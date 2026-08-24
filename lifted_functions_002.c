#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414920(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00014920;
    label_00005690: cpu->eip = LIFT_CODE_TOKEN_VA(0x405690u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000056D3;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000056B5;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000056A7;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000056A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4056A7u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000056B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4056B5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4056BAu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000056F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4056CBu); lift_push32(cpu, r); sfera_sub_00404180(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000056D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4056D3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4056D8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000056F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4056E9u); lift_push32(cpu, r); sfera_sub_00404140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000056F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4056F1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00005700: cpu->eip = LIFT_CODE_TOKEN_VA(0x405700u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005743;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005725;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005717;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005717: cpu->eip = LIFT_CODE_TOKEN_VA(0x405717u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005725: cpu->eip = LIFT_CODE_TOKEN_VA(0x405725u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40572Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005761;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40573Bu); lift_push32(cpu, r); sfera_sub_004041F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005743: cpu->eip = LIFT_CODE_TOKEN_VA(0x405743u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405748u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005761;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405759u); lift_push32(cpu, r); sfera_sub_004041C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005761: cpu->eip = LIFT_CODE_TOKEN_VA(0x405761u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00005890: cpu->eip = LIFT_CODE_TOKEN_VA(0x405890u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000058D3;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000058B5;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000058A7;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000058A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4058A7u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000058B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4058B5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4058BAu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000058F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4058CBu); lift_push32(cpu, r); sfera_sub_004042B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000058D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4058D3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4058D8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000058F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4058E9u); lift_push32(cpu, r); sfera_sub_00403480(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000058F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4058F1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00005900: cpu->eip = LIFT_CODE_TOKEN_VA(0x405900u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005943;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005925;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005917;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005917: cpu->eip = LIFT_CODE_TOKEN_VA(0x405917u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005925: cpu->eip = LIFT_CODE_TOKEN_VA(0x405925u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40592Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005982;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40593Bu); lift_push32(cpu, r); sfera_sub_004042F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005943: cpu->eip = LIFT_CODE_TOKEN_VA(0x405943u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405948u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005982;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x20u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_00005975;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    lift_store_f32(cpu->ecx + cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005975: cpu->eip = LIFT_CODE_TOKEN_VA(0x405975u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005982: cpu->eip = LIFT_CODE_TOKEN_VA(0x405982u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00005990: cpu->eip = LIFT_CODE_TOKEN_VA(0x405990u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000059D3;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000059B5;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000059A7;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000059A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4059A7u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000059B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4059B5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4059BAu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000059F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4059CBu); lift_push32(cpu, r); sfera_sub_00404330(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000059D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4059D3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4059D8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000059F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4059E9u); lift_push32(cpu, r); sfera_sub_004034C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000059F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4059F1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00007ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x407ED0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407ED9u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xBu)) goto label_00007FCD;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00007F4A;
        case 1u: goto label_00007F7D;
        case 2u: goto label_00007F9E;
        case 10u: goto label_00007EF0;
        case 11u: goto label_00007F1D;
        default: goto label_00007FCD;
    }
label_00007EF0: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407EF5u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007FDB;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F12u); lift_push32(cpu, r); sfera_sub_00406920(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x407F1Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F22u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007FDB;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F3Fu); lift_push32(cpu, r); sfera_sub_00406970(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x407F4Au);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F50u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F57u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007FDA;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F71u); lift_push32(cpu, r); sfera_sub_00405300(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x407F7Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F82u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00007FDB;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407F93u); lift_push32(cpu, r); sfera_sub_004069C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x407F9Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407FA3u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407FACu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00007FDB;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407FC2u); lift_push32(cpu, r); sfera_sub_00405340(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007FCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x407FCDu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005690;
    label_00007FDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x407FDAu);
    cpu->edi = lift_pop32(cpu);
    label_00007FDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x407FDBu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00008010: cpu->eip = LIFT_CODE_TOKEN_VA(0x408010u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408019u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xBu)) goto label_0000810D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000808A;
        case 1u: goto label_000080BD;
        case 2u: goto label_000080DE;
        case 10u: goto label_00008030;
        case 11u: goto label_0000805D;
        default: goto label_0000810D;
    }
label_00008030: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408035u); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408052u); lift_push32(cpu, r); sfera_sub_00406A30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000805D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40805Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408062u); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40807Fu); lift_push32(cpu, r); sfera_sub_00406A80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000808A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40808Au);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408090u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408097u); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811A;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4080B1u); lift_push32(cpu, r); sfera_sub_00405380(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000080BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4080BDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4080C2u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4080D3u); lift_push32(cpu, r); sfera_sub_004069C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000080DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4080DEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4080E3u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4080ECu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408102u); lift_push32(cpu, r); sfera_sub_004053C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000810D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40810Du);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005700;
    label_0000811A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40811Au);
    cpu->edi = lift_pop32(cpu);
    label_0000811B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40811Bu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000091B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4091B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4091DCu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xBu)) goto label_0000930C;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000926B;
        case 1u: goto label_000092A0;
        case 2u: goto label_000092CF;
        case 10u: goto label_000091F3;
        case 11u: goto label_00009243;
        default: goto label_0000930C;
    }
label_000091F3: ;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4091FCu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009220;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9219u); lift_push32(cpu, r); sfera_sub_00406AD0(cpu,r); if (cpu->eip != r) return; }
    label_00009219: cpu->eip = LIFT_CODE_TOKEN_VA(0x409219u);
    cpu->ecx = 0u;
    label_0000921B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40921Bu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9220u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00009220: cpu->eip = LIFT_CODE_TOKEN_VA(0x409220u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    label_00009224: cpu->eip = LIFT_CODE_TOKEN_VA(0x409224u);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409231u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_00009243: cpu->eip = LIFT_CODE_TOKEN_VA(0x409243u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40924Cu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009220;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409269u); lift_push32(cpu, r); sfera_sub_00406B20(cpu,r); if (cpu->eip != r) return; }
    goto label_00009219;
    label_0000926B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40926Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409270u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40927Bu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009224;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409299u); lift_push32(cpu, r); sfera_sub_00405440(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0000921B;
    label_000092A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4092A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4092A5u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009315;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4092B6u); lift_push32(cpu, r); sfera_sub_00408150(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4092BDu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000092CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4092CFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4092D4u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4092DDu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009315;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4092F3u); lift_push32(cpu, r); sfera_sub_004054B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4092FAu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0000930C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40930Cu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9315u); lift_push32(cpu, r); sfera_sub_00405800(cpu,r); if (cpu->eip != r) return; }
    label_00009315: cpu->eip = LIFT_CODE_TOKEN_VA(0x409315u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_00009350: cpu->eip = LIFT_CODE_TOKEN_VA(0x409350u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40935Au); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0000941D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000939F;
        case 1u: goto label_000093D1;
        case 2u: goto label_000093F3;
        case 10u: goto label_00009371;
        default: goto label_0000941D;
    }
label_00009371: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409376u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000942B;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409393u); lift_push32(cpu, r); sfera_sub_004081B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000939F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40939Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4093A4u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4093ABu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000942B;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4093C5u); lift_push32(cpu, r); sfera_sub_00402900(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000093D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4093D1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4093D6u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000942B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4093E7u); lift_push32(cpu, r); sfera_sub_004054F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000093F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4093F3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4093F8u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4093FFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000942B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409411u); lift_push32(cpu, r); sfera_sub_00402930(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000941D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40941Du);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005890;
    label_0000942B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40942Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00009450: cpu->eip = LIFT_CODE_TOKEN_VA(0x409450u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40945Au); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0000951D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000949F;
        case 1u: goto label_000094D1;
        case 2u: goto label_000094F3;
        case 10u: goto label_00009471;
        default: goto label_0000951D;
    }
label_00009471: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409476u); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409493u); lift_push32(cpu, r); sfera_sub_004081F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000949F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40949Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4094A4u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4094ABu); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4094C5u); lift_push32(cpu, r); sfera_sub_00402970(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000094D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4094D1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4094D6u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4094E7u); lift_push32(cpu, r); sfera_sub_004054F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000094F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4094F3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4094F8u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4094FFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409511u); lift_push32(cpu, r); sfera_sub_004029A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000951D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40951Du);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005900;
    label_0000952B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40952Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00009550: cpu->eip = LIFT_CODE_TOKEN_VA(0x409550u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40955Au); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0000961D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000959F;
        case 1u: goto label_000095D1;
        case 2u: goto label_000095F3;
        case 10u: goto label_00009571;
        default: goto label_0000961D;
    }
label_00009571: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409576u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0xBu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000962B;
    cpu->edx = (uint32_t)(cpu->esp + 0xBu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409593u); lift_push32(cpu, r); sfera_sub_00408230(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000959F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40959Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4095A4u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4095ABu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0xBu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000962B;
    cpu->eax = (uint32_t)(cpu->esp + 0xBu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4095C5u); lift_push32(cpu, r); sfera_sub_004029E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000095D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4095D1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4095D6u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000962B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4095E7u); lift_push32(cpu, r); sfera_sub_00405580(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000095F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4095F3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4095F8u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4095FFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000962B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409611u); lift_push32(cpu, r); sfera_sub_00402A10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000961D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40961Du);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005990;
    label_0000962B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40962Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00009650: cpu->eip = LIFT_CODE_TOKEN_VA(0x409650u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409659u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00009756;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000096C0;
        case 1u: goto label_000096ED;
        case 2u: goto label_00009716;
        case 3u: goto label_00009669;
        case 4u: goto label_0000968E;
        case 5u: goto label_000096B3;
        case 6u: case 7u: case 8u: goto label_00009756;
        case 9u: goto label_0000973F;
        default: lift_trap(cpu, 0x409662u, "resolved jump-table index out of range"); return;
    }
label_00009669: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40966Eu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009762;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409683u); lift_push32(cpu, r); sfera_sub_00403D50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000968E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40968Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409693u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009762;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4096A8u); lift_push32(cpu, r); sfera_sub_00403D90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000096B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4096B3u);
    cpu->ecx = lift_load8(cpu->esi + 8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000096C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4096C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4096C5u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009762;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4096E2u); lift_push32(cpu, r); sfera_sub_00406B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000096ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4096EDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4096F2u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009762;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40970Bu); lift_push32(cpu, r); sfera_sub_00408270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00009716: cpu->eip = LIFT_CODE_TOKEN_VA(0x409716u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40971Bu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009762;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409734u); lift_push32(cpu, r); sfera_sub_00405600(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000973F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40973Fu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    lift_store8(cpu->esi + 8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40974Bu); lift_push32(cpu, r); sfera_sub_004B24B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00009756: cpu->eip = LIFT_CODE_TOKEN_VA(0x409756u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00009762: cpu->eip = LIFT_CODE_TOKEN_VA(0x409762u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0000A870: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A870u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A87Au); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_0000A9A2;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000A8F8;
        case 1u: goto label_0000A930;
        case 2u: goto label_0000A95A;
        case 3u: goto label_0000A88A;
        case 4u: goto label_0000A8B8;
        case 5u: goto label_0000A8E6;
        case 6u: case 7u: case 8u: goto label_0000A9A2;
        case 9u: goto label_0000A98A;
        default: lift_trap(cpu, 0x40A883u, "resolved jump-table index out of range"); return;
    }
label_0000A88A: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A88Fu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A896u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000A9AF;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A8ACu); lift_push32(cpu, r); sfera_sub_00405B00(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A8B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A8B8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A8BDu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A8C4u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000A9AF;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A8DAu); lift_push32(cpu, r); sfera_sub_00405B50(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A8E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A8E6u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A8F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A8F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A8FDu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A906u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A9AF;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A922u); lift_push32(cpu, r); sfera_sub_004088E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A930: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A930u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A935u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A9AF;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A94Eu); lift_push32(cpu, r); sfera_sub_004084D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A95A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A95Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A95Fu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A968u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000A9AF;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A97Eu); lift_push32(cpu, r); sfera_sub_00406CE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A98A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A98Au);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A992u); lift_push32(cpu, r); sfera_sub_00429A30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A9A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A9A2u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A9AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A9AFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0000A9E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A9E0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A9ECu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_0000AB1A;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000AA6A;
        case 1u: goto label_0000AAA8;
        case 2u: goto label_0000AAD2;
        case 3u: goto label_0000A9FC;
        case 4u: goto label_0000AA2A;
        case 5u: goto label_0000AA58;
        case 6u: case 7u: case 8u: goto label_0000AB1A;
        case 9u: goto label_0000AB02;
        default: lift_trap(cpu, 0x40A9F5u, "resolved jump-table index out of range"); return;
    }
label_0000A9FC: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA01u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA08u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA1Eu); lift_push32(cpu, r); sfera_sub_00405C60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AA2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AA2Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA2Fu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA36u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA4Cu); lift_push32(cpu, r); sfera_sub_00405CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AA58: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AA58u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AA6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AA6Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA6Fu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA78u); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AA96u); lift_push32(cpu, r); sfera_sub_00408970(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AAA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AAA8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AAADu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000AB27;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AAC6u); lift_push32(cpu, r); sfera_sub_004084D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AAD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AAD2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AAD7u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AAE0u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AAF6u); lift_push32(cpu, r); sfera_sub_00406D20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AB02: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AB02u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AB0Au); lift_push32(cpu, r); sfera_sub_00429A30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AB1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AB1Au);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AB27: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AB27u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0000D0E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D0E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D10Cu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0000D20B;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000D173;
        case 1u: goto label_0000D1A5;
        case 2u: goto label_0000D1D4;
        case 10u: goto label_0000D123;
        default: goto label_0000D20B;
    }
label_0000D123: ;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D12Cu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D150;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D149u); lift_push32(cpu, r); sfera_sub_0040B760(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    label_0000D14B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D14Bu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD150u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0000D150: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D150u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D161u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0000D173: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D173u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D178u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D183u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D150;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1A1u); lift_push32(cpu, r); sfera_sub_00402A50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0000D14B;
    label_0000D1A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D1A5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1AAu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000D214;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1BBu); lift_push32(cpu, r); sfera_sub_0040A5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1C2u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0000D1D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D1D4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1D9u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1E0u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000D214;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1F2u); lift_push32(cpu, r); sfera_sub_00402AC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D1F9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0000D20B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D20Bu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD214u); lift_push32(cpu, r); sfera_sub_00405A80(cpu,r); if (cpu->eip != r) return; }
    label_0000D214: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D214u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_0000E6D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E6D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E6FCu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_0000E81E;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000E76B;
        case 1u: goto label_0000E7C9;
        case 2u: goto label_0000E7EB;
        case 3u: goto label_0000E70C;
        case 4u: goto label_0000E735;
        case 5u: goto label_0000E75E;
        case 6u: case 7u: case 8u: goto label_0000E81E;
        case 9u: goto label_0000E813;
        default: lift_trap(cpu, 0x40E705u, "resolved jump-table index out of range"); return;
    }
label_0000E70C: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E711u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E718u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000E826;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E72Eu); lift_push32(cpu, r); sfera_sub_00405F10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0000E821;
    label_0000E735: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E735u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E73Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E741u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000E826;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E757u); lift_push32(cpu, r); sfera_sub_00405F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0000E821;
    label_0000E75E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E75Eu);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000E821;
    label_0000E76B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E76Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E770u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E77Du); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E7A6;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E79Fu); lift_push32(cpu, r); sfera_sub_0040D3B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xE7A6u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0000E7A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E7A6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E7B7u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0000E7C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E7C9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E7CEu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E826;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E7E7u); lift_push32(cpu, r); sfera_sub_0040B810(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_0000E821;
    label_0000E7EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E7EBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E7F0u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E7F9u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000E826;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E80Fu); lift_push32(cpu, r); sfera_sub_00406DA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0000E821;
    label_0000E813: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E813u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E81Au); lift_push32(cpu, r); sfera_sub_0040AB60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_0000E821;
    label_0000E81E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E81Eu);
    cpu->ecx |= 0xFFFFFFFFu;
    label_0000E821: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E821u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xE826u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0000E826: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E826u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_000101D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4101D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410206u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00010344;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00010261;
        case 1u: goto label_0001029C;
        case 2u: goto label_000102D4;
        case 3u: goto label_00010216;
        case 4u: goto label_00010237;
        case 5u: goto label_00010258;
        case 6u: case 7u: case 8u: goto label_00010344;
        case 9u: goto label_00010339;
        default: lift_trap(cpu, 0x41020Fu, "resolved jump-table index out of range"); return;
    }
label_00010216: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41021Bu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001034C;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410230u); lift_push32(cpu, r); sfera_sub_00403DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00010347;
    label_00010237: cpu->eip = LIFT_CODE_TOKEN_VA(0x410237u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41023Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001034C;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410251u); lift_push32(cpu, r); sfera_sub_00403E10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00010347;
    label_00010258: cpu->eip = LIFT_CODE_TOKEN_VA(0x410258u);
    cpu->ecx = lift_load8(cpu->esi + 8u);
    goto label_00010347;
    label_00010261: cpu->eip = LIFT_CODE_TOKEN_VA(0x410261u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41026Au); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x68u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001028E;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410287u); lift_push32(cpu, r); sfera_sub_0040E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1028Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001028E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41028Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    label_00010292: cpu->eip = LIFT_CODE_TOKEN_VA(0x410292u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410297u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001034C;
    label_0001029C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41029Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4102A5u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x68u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010292;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4102C2u); lift_push32(cpu, r); sfera_sub_0040D330(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4102C9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4102D2u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001034C;
    label_000102D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4102D4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4102DDu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, 2u);
    lift_store32(cpu->esp + 0x3Cu, 0xFu);
    lift_store32(cpu->esp + 0x38u, 0u);
    lift_store8(cpu->esp + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410304u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x68u, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410312u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001032E;
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410327u); lift_push32(cpu, r); sfera_sub_004082E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1032Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001032E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41032Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410337u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001034C;
    label_00010339: cpu->eip = LIFT_CODE_TOKEN_VA(0x410339u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410340u); lift_push32(cpu, r); sfera_sub_0040B7A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_00010347;
    label_00010344: cpu->eip = LIFT_CODE_TOKEN_VA(0x410344u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00010347: cpu->eip = LIFT_CODE_TOKEN_VA(0x410347u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1034Cu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001034C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41034Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x64u;
    lift_return(cpu, 0u, stop_address); return;
    label_00010EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x410EC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410EF7u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xBu)) goto label_00011010;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00010F84;
        case 1u: goto label_00010FC4;
        case 2u: goto label_00010FE3;
        case 10u: goto label_00010F0E;
        case 11u: goto label_00010F49;
        default: goto label_00011010;
    }
label_00010F0E: ;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F17u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010F3B;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F34u); lift_push32(cpu, r); sfera_sub_00410390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x10F3Bu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00010F3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x410F3Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    label_00010F3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x410F3Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F44u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00011019;
    label_00010F49: cpu->eip = LIFT_CODE_TOKEN_VA(0x410F49u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F52u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010F3B;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F6Fu); lift_push32(cpu, r); sfera_sub_004103E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F76u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F7Fu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00011019;
    label_00010F84: cpu->eip = LIFT_CODE_TOKEN_VA(0x410F84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F89u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410F94u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010F3F;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FB2u); lift_push32(cpu, r); sfera_sub_0040A550(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FB9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FC2u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00011019;
    label_00010FC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x410FC4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FC9u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00011019;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FDAu); lift_push32(cpu, r); sfera_sub_0040B700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FE1u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00011019;
    label_00010FE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x410FE3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FE8u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410FF1u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00011019;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411007u); lift_push32(cpu, r); sfera_sub_00405400(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41100Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00011019;
    label_00011010: cpu->eip = LIFT_CODE_TOKEN_VA(0x411010u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x11019u); lift_push32(cpu, r); sfera_sub_00405770(cpu,r); if (cpu->eip != r) return; }
    label_00011019: cpu->eip = LIFT_CODE_TOKEN_VA(0x411019u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000116B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4116B0u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_000116D4;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000116C0;
        case 1u: goto label_000116C5;
        case 2u: goto label_000116D4;
        case 3u: goto label_000116CA;
        case 4u: goto label_000116CF;
        default: lift_trap(cpu, 0x4116B9u, "resolved jump-table index out of range"); return;
    }
label_000116C0: ;
    goto label_00007ED0;
    label_000116C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4116C5u);
    goto label_00008010;
    label_000116CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4116CAu);
    goto label_00010EC0;
    label_000116CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4116CFu);
    goto label_000091B0;
    label_000116D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4116D4u);
    lift_return(cpu, 0u, stop_address); return;
    label_00012160: cpu->eip = LIFT_CODE_TOKEN_VA(0x412160u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41216Cu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00012293;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000121EA;
        case 1u: goto label_00012226;
        case 2u: goto label_00012250;
        case 3u: goto label_0001217C;
        case 4u: goto label_000121AA;
        case 5u: goto label_000121D8;
        case 6u: case 7u: case 8u: goto label_00012293;
        case 9u: goto label_00012280;
        default: lift_trap(cpu, 0x412175u, "resolved jump-table index out of range"); return;
    }
label_0001217C: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412181u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412188u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000122A0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41219Eu); lift_push32(cpu, r); sfera_sub_00406DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000121AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4121AAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4121AFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4121B6u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000122A0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4121CCu); lift_push32(cpu, r); sfera_sub_00406E30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000121D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4121D8u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000121EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4121EAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4121EFu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4121F8u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000122A0;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41221Au); lift_push32(cpu, r); sfera_sub_004117C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012226: cpu->eip = LIFT_CODE_TOKEN_VA(0x412226u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41222Bu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000122A0;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412244u); lift_push32(cpu, r); sfera_sub_00411190(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012250: cpu->eip = LIFT_CODE_TOKEN_VA(0x412250u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412255u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41225Eu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000122A0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412274u); lift_push32(cpu, r); sfera_sub_00409C90(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012280: cpu->eip = LIFT_CODE_TOKEN_VA(0x412280u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412287u); lift_push32(cpu, r); sfera_sub_00410650(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012293: cpu->eip = LIFT_CODE_TOKEN_VA(0x412293u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000122A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4122A0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_000122D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4122D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4122FCu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_0001245D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0001236B;
        case 1u: goto label_000123C5;
        case 2u: goto label_0001240C;
        case 3u: goto label_0001230C;
        case 4u: goto label_00012335;
        case 5u: goto label_0001235E;
        case 6u: case 7u: case 8u: goto label_0001245D;
        case 9u: goto label_00012443;
        default: lift_trap(cpu, 0x412305u, "resolved jump-table index out of range"); return;
    }
label_0001230C: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412311u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412318u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41232Eu); lift_push32(cpu, r); sfera_sub_00406F30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00012460;
    label_00012335: cpu->eip = LIFT_CODE_TOKEN_VA(0x412335u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41233Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412341u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412357u); lift_push32(cpu, r); sfera_sub_00406F80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00012460;
    label_0001235E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41235Eu);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00012460;
    label_0001236B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41236Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412374u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412381u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000123A2;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412399u); lift_push32(cpu, r); sfera_sub_00411370(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->eax, cpu->edi);
    label_0001239B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41239Bu);
    cpu->ecx = 0u;
    label_0001239D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41239Du);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x123A2u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000123A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4123A2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4123B3u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000123C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4123C5u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4123CEu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00012402;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4123F0u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_00012402: cpu->eip = LIFT_CODE_TOKEN_VA(0x412402u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41240Au); lift_push32(cpu, r); sfera_sub_00411140(cpu,r); if (cpu->eip != r) return; }
    goto label_0001239B;
    label_0001240C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41240Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412415u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x1Cu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412422u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000123A2;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41243Cu); lift_push32(cpu, r); sfera_sub_00409D10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0001239D;
    label_00012443: cpu->eip = LIFT_CODE_TOKEN_VA(0x412443u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41244Bu); lift_push32(cpu, r); sfera_sub_0040A060(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412455u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00012460;
    label_0001245D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41245Du);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00012460: cpu->eip = LIFT_CODE_TOKEN_VA(0x412460u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x12465u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00012465: cpu->eip = LIFT_CODE_TOKEN_VA(0x412465u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000124A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4124A0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4124ACu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000125D3;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0001252A;
        case 1u: goto label_00012566;
        case 2u: goto label_00012590;
        case 3u: goto label_000124BC;
        case 4u: goto label_000124EA;
        case 5u: goto label_00012518;
        case 6u: case 7u: case 8u: goto label_000125D3;
        case 9u: goto label_000125C0;
        default: lift_trap(cpu, 0x4124B5u, "resolved jump-table index out of range"); return;
    }
label_000124BC: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4124C1u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4124C8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4124DEu); lift_push32(cpu, r); sfera_sub_00406FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000124EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4124EAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4124EFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4124F6u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41250Cu); lift_push32(cpu, r); sfera_sub_00407030(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012518: cpu->eip = LIFT_CODE_TOKEN_VA(0x412518u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0001252A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41252Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41252Fu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412538u); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41255Au); lift_push32(cpu, r); sfera_sub_00411820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012566: cpu->eip = LIFT_CODE_TOKEN_VA(0x412566u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41256Bu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000125E0;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412584u); lift_push32(cpu, r); sfera_sub_00411190(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012590: cpu->eip = LIFT_CODE_TOKEN_VA(0x412590u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412595u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41259Eu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4125B4u); lift_push32(cpu, r); sfera_sub_00409D50(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000125C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4125C0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4125C7u); lift_push32(cpu, r); sfera_sub_00410650(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000125D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4125D3u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000125E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4125E0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_00012610: cpu->eip = LIFT_CODE_TOKEN_VA(0x412610u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41263Cu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000127A3;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000126AB;
        case 1u: goto label_0001270B;
        case 2u: goto label_00012752;
        case 3u: goto label_0001264C;
        case 4u: goto label_00012675;
        case 5u: goto label_0001269E;
        case 6u: case 7u: case 8u: goto label_000127A3;
        case 9u: goto label_00012789;
        default: lift_trap(cpu, 0x412645u, "resolved jump-table index out of range"); return;
    }
label_0001264C: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412651u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412658u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000127AB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41266Eu); lift_push32(cpu, r); sfera_sub_00407130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000127A6;
    label_00012675: cpu->eip = LIFT_CODE_TOKEN_VA(0x412675u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41267Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412681u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000127AB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412697u); lift_push32(cpu, r); sfera_sub_00407180(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000127A6;
    label_0001269E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41269Eu);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000127A6;
    label_000126AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4126ABu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4126B4u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x20u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4126C1u); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000126E8;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4126DBu); lift_push32(cpu, r); sfera_sub_00411450(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000126E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4126E1u);
    cpu->ecx = 0u;
    label_000126E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4126E3u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x126E8u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000126E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4126E8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4126F9u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0001270B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41270Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412714u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00012748;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412736u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00012748: cpu->eip = LIFT_CODE_TOKEN_VA(0x412748u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412750u); lift_push32(cpu, r); sfera_sub_00411140(cpu,r); if (cpu->eip != r) return; }
    goto label_000126E1;
    label_00012752: cpu->eip = LIFT_CODE_TOKEN_VA(0x412752u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41275Bu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x20u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412768u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000126E8;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412782u); lift_push32(cpu, r); sfera_sub_00409DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000126E3;
    label_00012789: cpu->eip = LIFT_CODE_TOKEN_VA(0x412789u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412791u); lift_push32(cpu, r); sfera_sub_0040A060(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41279Bu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000127A6;
    label_000127A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4127A3u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_000127A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4127A6u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x127ABu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000127AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4127ABu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_000127F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4127F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41281Cu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_0001294D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0001288B;
        case 1u: goto label_000128E9;
        case 2u: goto label_0001290B;
        case 3u: goto label_0001282C;
        case 4u: goto label_00012855;
        case 5u: goto label_0001287E;
        case 6u: case 7u: case 8u: goto label_0001294D;
        case 9u: goto label_00012933;
        default: lift_trap(cpu, 0x412825u, "resolved jump-table index out of range"); return;
    }
label_0001282C: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412831u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412838u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012955;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41284Eu); lift_push32(cpu, r); sfera_sub_00407390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00012950;
    label_00012855: cpu->eip = LIFT_CODE_TOKEN_VA(0x412855u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41285Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412861u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012955;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412877u); lift_push32(cpu, r); sfera_sub_004073E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00012950;
    label_0001287E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41287Eu);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00012950;
    label_0001288B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41288Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412890u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41289Du); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000128C6;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4128BFu); lift_push32(cpu, r); sfera_sub_004118E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x128C6u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000128C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4128C6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4128D7u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_000128E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4128E9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4128EEu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00012955;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412907u); lift_push32(cpu, r); sfera_sub_00411280(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_00012950;
    label_0001290B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41290Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412910u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412919u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012955;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41292Fu); lift_push32(cpu, r); sfera_sub_00409ED0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00012950;
    label_00012933: cpu->eip = LIFT_CODE_TOKEN_VA(0x412933u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41293Bu); lift_push32(cpu, r); sfera_sub_00408A50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412945u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00012950;
    label_0001294D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41294Du);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00012950: cpu->eip = LIFT_CODE_TOKEN_VA(0x412950u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x12955u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00012955: cpu->eip = LIFT_CODE_TOKEN_VA(0x412955u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00012990: cpu->eip = LIFT_CODE_TOKEN_VA(0x412990u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4129C2u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00012B23;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00012A31;
        case 1u: goto label_00012AA2;
        case 2u: goto label_00012AD1;
        case 3u: goto label_000129D2;
        case 4u: goto label_000129FB;
        case 5u: goto label_00012A24;
        case 6u: case 7u: case 8u: goto label_00012B23;
        case 9u: goto label_00012B09;
        default: lift_trap(cpu, 0x4129CBu, "resolved jump-table index out of range"); return;
    }
label_000129D2: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4129D7u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4129DEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012B2B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4129F4u); lift_push32(cpu, r); sfera_sub_004074C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00012B26;
    label_000129FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4129FBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412A00u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412A07u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012B2B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412A1Du); lift_push32(cpu, r); sfera_sub_00407500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00012B26;
    label_00012A24: cpu->eip = LIFT_CODE_TOKEN_VA(0x412A24u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00012B26;
    label_00012A31: cpu->eip = LIFT_CODE_TOKEN_VA(0x412A31u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412A3Au); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412A4Bu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x28u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00012A71;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412A6Au); lift_push32(cpu, r); sfera_sub_00411930(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x12A71u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00012A71: cpu->eip = LIFT_CODE_TOKEN_VA(0x412A71u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store8(cpu->esp + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x12A7Fu); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    label_00012A7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x412A7Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412A90u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00012AA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x412AA2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412AABu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x28u, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00012A7F;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412AC8u); lift_push32(cpu, r); sfera_sub_00411320(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412ACFu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00012A7F;
    label_00012AD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x412AD1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412ADAu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x28u, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412AE7u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012A7F;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412AFDu); lift_push32(cpu, r); sfera_sub_00409F50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412B04u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00012A7F;
    label_00012B09: cpu->eip = LIFT_CODE_TOKEN_VA(0x412B09u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412B11u); lift_push32(cpu, r); sfera_sub_0040A0C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412B1Bu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00012B26;
    label_00012B23: cpu->eip = LIFT_CODE_TOKEN_VA(0x412B23u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00012B26: cpu->eip = LIFT_CODE_TOKEN_VA(0x412B26u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x12B2Bu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00012B2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x412B2Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00013100: cpu->eip = LIFT_CODE_TOKEN_VA(0x413100u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413137u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0001320F;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013189;
        case 1u: goto label_000131C9;
        case 2u: goto label_000131E8;
        case 10u: goto label_0001314E;
        default: goto label_0001320F;
    }
label_0001314E: ;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413157u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001317B;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413174u); lift_push32(cpu, r); sfera_sub_00412100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1317Bu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001317B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41317Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413184u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013218;
    label_00013189: cpu->eip = LIFT_CODE_TOKEN_VA(0x413189u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41318Eu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413199u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000131BE;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4131B7u); lift_push32(cpu, r); sfera_sub_0040A590(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x131BEu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000131BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4131BEu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4131C7u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013218;
    label_000131C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4131C9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4131CEu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013218;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4131DFu); lift_push32(cpu, r); sfera_sub_0040D250(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4131E6u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013218;
    label_000131E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4131E8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4131EDu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4131F4u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013218;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413206u); lift_push32(cpu, r); sfera_sub_004033A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41320Du); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013218;
    label_0001320F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41320Fu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13218u); lift_push32(cpu, r); sfera_sub_00405A00(cpu,r); if (cpu->eip != r) return; }
    label_00013218: cpu->eip = LIFT_CODE_TOKEN_VA(0x413218u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 0u, stop_address); return;
    label_00013260: cpu->eip = LIFT_CODE_TOKEN_VA(0x413260u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413297u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000133CC;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013306;
        case 1u: goto label_0001334B;
        case 2u: goto label_00013383;
        case 3u: goto label_000132A7;
        case 4u: goto label_000132D0;
        case 5u: goto label_000132F9;
        case 6u: case 7u: case 8u: goto label_000133CC;
        case 9u: goto label_000133C1;
        default: lift_trap(cpu, 0x4132A0u, "resolved jump-table index out of range"); return;
    }
label_000132A7: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4132ACu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4132B3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000133D4;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4132C9u); lift_push32(cpu, r); sfera_sub_00405BB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000133CF;
    label_000132D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4132D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4132D5u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4132DCu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000133D4;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4132F2u); lift_push32(cpu, r); sfera_sub_00405C00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000133CF;
    label_000132F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4132F9u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000133CF;
    label_00013306: cpu->eip = LIFT_CODE_TOKEN_VA(0x413306u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41330Fu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x50u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41331Cu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001333D;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413334u); lift_push32(cpu, r); sfera_sub_00411980(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1333Du); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001333D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41333Du);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    label_00013341: cpu->eip = LIFT_CODE_TOKEN_VA(0x413341u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413346u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000133D4;
    label_0001334B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41334Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413354u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013341;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413371u); lift_push32(cpu, r); sfera_sub_00410550(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413378u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413381u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000133D4;
    label_00013383: cpu->eip = LIFT_CODE_TOKEN_VA(0x413383u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41338Cu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x50u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413399u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000133B6;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4133AFu); lift_push32(cpu, r); sfera_sub_00408450(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x133B6u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000133B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4133B6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4133BFu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000133D4;
    label_000133C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4133C1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4133C8u); lift_push32(cpu, r); sfera_sub_0040E860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_000133CF;
    label_000133CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4133CCu);
    cpu->ecx |= 0xFFFFFFFFu;
    label_000133CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4133CFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x133D4u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000133D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4133D4u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 0u, stop_address); return;
    label_00013420: cpu->eip = LIFT_CODE_TOKEN_VA(0x413420u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413457u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00013592;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000134C6;
        case 1u: goto label_00013511;
        case 2u: goto label_00013549;
        case 3u: goto label_00013467;
        case 4u: goto label_00013490;
        case 5u: goto label_000134B9;
        case 6u: case 7u: case 8u: goto label_00013592;
        case 9u: goto label_00013587;
        default: lift_trap(cpu, 0x413460u, "resolved jump-table index out of range"); return;
    }
label_00013467: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41346Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413473u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001359A;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413489u); lift_push32(cpu, r); sfera_sub_00405D10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013595;
    label_00013490: cpu->eip = LIFT_CODE_TOKEN_VA(0x413490u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413495u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41349Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001359A;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4134B2u); lift_push32(cpu, r); sfera_sub_00405D60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013595;
    label_000134B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4134B9u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013595;
    label_000134C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4134C6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4134CFu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x54u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4134DCu); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013503;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4134F6u); lift_push32(cpu, r); sfera_sub_00411A70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->ecx = 0u;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13503u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013503: cpu->eip = LIFT_CODE_TOKEN_VA(0x413503u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    label_00013507: cpu->eip = LIFT_CODE_TOKEN_VA(0x413507u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41350Cu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001359A;
    label_00013511: cpu->eip = LIFT_CODE_TOKEN_VA(0x413511u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41351Au); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x54u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013507;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413537u); lift_push32(cpu, r); sfera_sub_00410550(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41353Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413547u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001359A;
    label_00013549: cpu->eip = LIFT_CODE_TOKEN_VA(0x413549u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413552u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x54u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41355Fu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001357C;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413575u); lift_push32(cpu, r); sfera_sub_00408510(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1357Cu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001357C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41357Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413585u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001359A;
    label_00013587: cpu->eip = LIFT_CODE_TOKEN_VA(0x413587u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41358Eu); lift_push32(cpu, r); sfera_sub_0040E860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_00013595;
    label_00013592: cpu->eip = LIFT_CODE_TOKEN_VA(0x413592u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013595: cpu->eip = LIFT_CODE_TOKEN_VA(0x413595u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1359Au); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001359A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41359Au);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000135E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4135E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413617u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00013729;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013686;
        case 1u: goto label_000136D4;
        case 2u: goto label_000136F6;
        case 3u: goto label_00013627;
        case 4u: goto label_00013650;
        case 5u: goto label_00013679;
        case 6u: case 7u: case 8u: goto label_00013729;
        case 9u: goto label_0001371E;
        default: lift_trap(cpu, 0x413620u, "resolved jump-table index out of range"); return;
    }
label_00013627: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41362Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413633u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013731;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413649u); lift_push32(cpu, r); sfera_sub_00405DC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0001372C;
    label_00013650: cpu->eip = LIFT_CODE_TOKEN_VA(0x413650u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413655u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41365Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013731;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413672u); lift_push32(cpu, r); sfera_sub_00405E10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0001372C;
    label_00013679: cpu->eip = LIFT_CODE_TOKEN_VA(0x413679u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0001372C;
    label_00013686: cpu->eip = LIFT_CODE_TOKEN_VA(0x413686u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41368Bu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413698u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000136C9;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4136B6u); lift_push32(cpu, r); sfera_sub_00411B60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4136C2u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x136C9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000136C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4136C9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4136D2u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013731;
    label_000136D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4136D4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4136D9u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013731;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4136F2u); lift_push32(cpu, r); sfera_sub_00410590(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_0001372C;
    label_000136F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4136F6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4136FBu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413704u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013731;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41371Au); lift_push32(cpu, r); sfera_sub_00406D60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0001372C;
    label_0001371E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41371Eu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413725u); lift_push32(cpu, r); sfera_sub_0040E890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_0001372C;
    label_00013729: cpu->eip = LIFT_CODE_TOKEN_VA(0x413729u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_0001372C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41372Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13731u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013731: cpu->eip = LIFT_CODE_TOKEN_VA(0x413731u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00013780: cpu->eip = LIFT_CODE_TOKEN_VA(0x413780u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4137B7u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00013906;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013826;
        case 1u: goto label_00013885;
        case 2u: goto label_000138BD;
        case 3u: goto label_000137C7;
        case 4u: goto label_000137F0;
        case 5u: goto label_00013819;
        case 6u: case 7u: case 8u: goto label_00013906;
        case 9u: goto label_000138FB;
        default: lift_trap(cpu, 0x4137C0u, "resolved jump-table index out of range"); return;
    }
label_000137C7: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4137CCu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4137D3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001390E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4137E9u); lift_push32(cpu, r); sfera_sub_00405E70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013909;
    label_000137F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4137F0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4137F5u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4137FCu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001390E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413812u); lift_push32(cpu, r); sfera_sub_00405EB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013909;
    label_00013819: cpu->eip = LIFT_CODE_TOKEN_VA(0x413819u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013909;
    label_00013826: cpu->eip = LIFT_CODE_TOKEN_VA(0x413826u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41382Fu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413840u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x6Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001386E;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41385Bu); lift_push32(cpu, r); sfera_sub_00411C90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413867u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1386Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001386E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41386Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13877u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_00013877: cpu->eip = LIFT_CODE_TOKEN_VA(0x413877u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413880u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001390E;
    label_00013885: cpu->eip = LIFT_CODE_TOKEN_VA(0x413885u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41388Eu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x6Cu, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013877;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4138ABu); lift_push32(cpu, r); sfera_sub_004105D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4138B2u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4138BBu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001390E;
    label_000138BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4138BDu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4138C6u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x6Cu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4138D3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000138F0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4138E9u); lift_push32(cpu, r); sfera_sub_00408590(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x138F0u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000138F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4138F0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4138F9u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001390E;
    label_000138FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4138FBu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413902u); lift_push32(cpu, r); sfera_sub_0040E8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_00013909;
    label_00013906: cpu->eip = LIFT_CODE_TOKEN_VA(0x413906u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013909: cpu->eip = LIFT_CODE_TOKEN_VA(0x413909u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1390Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001390E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41390Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x64u;
    lift_return(cpu, 0u, stop_address); return;
    label_00013960: cpu->eip = LIFT_CODE_TOKEN_VA(0x413960u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413997u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00013AE3;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013A06;
        case 1u: goto label_00013A62;
        case 2u: goto label_00013A9A;
        case 3u: goto label_000139A7;
        case 4u: goto label_000139D0;
        case 5u: goto label_000139F9;
        case 6u: case 7u: case 8u: goto label_00013AE3;
        case 9u: goto label_00013AD8;
        default: lift_trap(cpu, 0x4139A0u, "resolved jump-table index out of range"); return;
    }
label_000139A7: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4139ACu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4139B3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013AEB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4139C9u); lift_push32(cpu, r); sfera_sub_00405FC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013AE6;
    label_000139D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4139D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4139D5u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4139DCu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013AEB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4139F2u); lift_push32(cpu, r); sfera_sub_00406000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013AE6;
    label_000139F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4139F9u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013AE6;
    label_00013A06: cpu->eip = LIFT_CODE_TOKEN_VA(0x413A06u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A0Fu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x58u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A20u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x58u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013A46;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A3Fu); lift_push32(cpu, r); sfera_sub_00412B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13A46u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013A46: cpu->eip = LIFT_CODE_TOKEN_VA(0x413A46u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store8(cpu->esp + 0x58u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13A54u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    label_00013A54: cpu->eip = LIFT_CODE_TOKEN_VA(0x413A54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A5Du); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013AEB;
    label_00013A62: cpu->eip = LIFT_CODE_TOKEN_VA(0x413A62u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A6Bu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x58u, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013A54;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A88u); lift_push32(cpu, r); sfera_sub_00410610(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A8Fu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413A98u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013AEB;
    label_00013A9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x413A9Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413AA3u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x58u, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413AB0u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013ACD;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413AC6u); lift_push32(cpu, r); sfera_sub_00408610(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13ACDu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013ACD: cpu->eip = LIFT_CODE_TOKEN_VA(0x413ACDu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413AD6u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013AEB;
    label_00013AD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x413AD8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413ADFu); lift_push32(cpu, r); sfera_sub_0040E8F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_00013AE6;
    label_00013AE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x413AE3u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013AE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x413AE6u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13AEBu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013AEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x413AEBu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
    label_00013CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x413CC0u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00013CE9;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013CD0;
        case 1u: goto label_00013CD5;
        case 2u: goto label_00013CDA;
        case 3u: goto label_00013CDF;
        case 4u: goto label_00013CE4;
        default: lift_trap(cpu, 0x413CC9u, "resolved jump-table index out of range"); return;
    }
label_00013CD0: ;
    goto label_00009350;
    label_00013CD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x413CD5u);
    goto label_00009450;
    label_00013CDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x413CDAu);
    goto label_00009550;
    label_00013CDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x413CDFu);
    goto label_00013100;
    label_00013CE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x413CE4u);
    goto label_0000D0E0;
    label_00013CE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x413CE9u);
    lift_return(cpu, 0u, stop_address); return;
    label_00013D00: cpu->eip = LIFT_CODE_TOKEN_VA(0x413D00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413D37u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00013E7B;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013DA6;
        case 1u: goto label_00013DEB;
        case 2u: goto label_00013E23;
        case 3u: goto label_00013D47;
        case 4u: goto label_00013D70;
        case 5u: goto label_00013D99;
        case 6u: case 7u: case 8u: goto label_00013E7B;
        case 9u: goto label_00013E61;
        default: lift_trap(cpu, 0x413D40u, "resolved jump-table index out of range"); return;
    }
label_00013D47: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413D4Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413D53u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013E83;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413D69u); lift_push32(cpu, r); sfera_sub_00406E90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013E7E;
    label_00013D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x413D70u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413D75u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413D7Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013E83;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413D92u); lift_push32(cpu, r); sfera_sub_00406EE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00013E7E;
    label_00013D99: cpu->eip = LIFT_CODE_TOKEN_VA(0x413D99u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013E7E;
    label_00013DA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x413DA6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413DAFu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x50u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413DBCu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013DDD;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413DD4u); lift_push32(cpu, r); sfera_sub_00412BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13DDDu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013DDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x413DDDu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    label_00013DE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x413DE1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413DE6u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013E83;
    label_00013DEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x413DEBu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413DF4u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013DE1;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E11u); lift_push32(cpu, r); sfera_sub_004110F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E18u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E21u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013E83;
    label_00013E23: cpu->eip = LIFT_CODE_TOKEN_VA(0x413E23u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E2Cu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x50u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E39u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013E56;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E4Fu); lift_push32(cpu, r); sfera_sub_00409CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13E56u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013E56: cpu->eip = LIFT_CODE_TOKEN_VA(0x413E56u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E5Fu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00013E83;
    label_00013E61: cpu->eip = LIFT_CODE_TOKEN_VA(0x413E61u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E69u); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413E73u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00013E7E;
    label_00013E7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x413E7Bu);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013E7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x413E7Eu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13E83u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013E83: cpu->eip = LIFT_CODE_TOKEN_VA(0x413E83u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 0u, stop_address); return;
    label_00013ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x413ED0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F07u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00014051;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00013F76;
        case 1u: goto label_00013FC1;
        case 2u: goto label_00013FF9;
        case 3u: goto label_00013F17;
        case 4u: goto label_00013F40;
        case 5u: goto label_00013F69;
        case 6u: case 7u: case 8u: goto label_00014051;
        case 9u: goto label_00014037;
        default: lift_trap(cpu, 0x413F10u, "resolved jump-table index out of range"); return;
    }
label_00013F17: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F1Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F23u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014059;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F39u); lift_push32(cpu, r); sfera_sub_00407090(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00014054;
    label_00013F40: cpu->eip = LIFT_CODE_TOKEN_VA(0x413F40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F45u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F4Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014059;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F62u); lift_push32(cpu, r); sfera_sub_004070E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_00014054;
    label_00013F69: cpu->eip = LIFT_CODE_TOKEN_VA(0x413F69u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00014054;
    label_00013F76: cpu->eip = LIFT_CODE_TOKEN_VA(0x413F76u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F7Fu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x54u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413F8Cu); lift_push32(cpu, r); sfera_sub_0043B0C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013FB3;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413FA6u); lift_push32(cpu, r); sfera_sub_00412C80(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->ecx = 0u;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x13FB3u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00013FB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x413FB3u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    label_00013FB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x413FB7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413FBCu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00014059;
    label_00013FC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x413FC1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413FCAu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x54u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013FB7;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413FE7u); lift_push32(cpu, r); sfera_sub_004110F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413FEEu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413FF7u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00014059;
    label_00013FF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x413FF9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414002u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x54u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41400Fu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001402C;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414025u); lift_push32(cpu, r); sfera_sub_00409D90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1402Cu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001402C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41402Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414035u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00014059;
    label_00014037: cpu->eip = LIFT_CODE_TOKEN_VA(0x414037u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41403Fu); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414049u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00014054;
    label_00014051: cpu->eip = LIFT_CODE_TOKEN_VA(0x414051u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_00014054: cpu->eip = LIFT_CODE_TOKEN_VA(0x414054u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14059u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00014059: cpu->eip = LIFT_CODE_TOKEN_VA(0x414059u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000140A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4140A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4140D7u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000141F8;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00014146;
        case 1u: goto label_00014194;
        case 2u: goto label_000141B6;
        case 3u: goto label_000140E7;
        case 4u: goto label_00014110;
        case 5u: goto label_00014139;
        case 6u: case 7u: case 8u: goto label_000141F8;
        case 9u: goto label_000141DE;
        default: lift_trap(cpu, 0x4140E0u, "resolved jump-table index out of range"); return;
    }
label_000140E7: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4140ECu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4140F3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014200;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414109u); lift_push32(cpu, r); sfera_sub_004071D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000141FB;
    label_00014110: cpu->eip = LIFT_CODE_TOKEN_VA(0x414110u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414115u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41411Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014200;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414132u); lift_push32(cpu, r); sfera_sub_00407220(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000141FB;
    label_00014139: cpu->eip = LIFT_CODE_TOKEN_VA(0x414139u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000141FB;
    label_00014146: cpu->eip = LIFT_CODE_TOKEN_VA(0x414146u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41414Bu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414158u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014189;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414176u); lift_push32(cpu, r); sfera_sub_00412D50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414182u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14189u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00014189: cpu->eip = LIFT_CODE_TOKEN_VA(0x414189u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414192u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00014200;
    label_00014194: cpu->eip = LIFT_CODE_TOKEN_VA(0x414194u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414199u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014200;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4141B2u); lift_push32(cpu, r); sfera_sub_004111E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    goto label_000141FB;
    label_000141B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4141B6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4141BBu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4141C4u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014200;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4141DAu); lift_push32(cpu, r); sfera_sub_00409E10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000141FB;
    label_000141DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4141DEu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4141E6u); lift_push32(cpu, r); sfera_sub_0040BB40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4141F0u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000141FB;
    label_000141F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4141F8u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_000141FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4141FBu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14200u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00014200: cpu->eip = LIFT_CODE_TOKEN_VA(0x414200u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014250: cpu->eip = LIFT_CODE_TOKEN_VA(0x414250u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414287u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000143E5;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000142F6;
        case 1u: goto label_00014355;
        case 2u: goto label_0001438D;
        case 3u: goto label_00014297;
        case 4u: goto label_000142C0;
        case 5u: goto label_000142E9;
        case 6u: case 7u: case 8u: goto label_000143E5;
        case 9u: goto label_000143CB;
        default: lift_trap(cpu, 0x414290u, "resolved jump-table index out of range"); return;
    }
label_00014297: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41429Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4142A3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000143ED;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4142B9u); lift_push32(cpu, r); sfera_sub_00407270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000143E8;
    label_000142C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4142C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4142C5u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4142CCu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000143ED;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4142E2u); lift_push32(cpu, r); sfera_sub_004072B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000143E8;
    label_000142E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4142E9u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000143E8;
    label_000142F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4142F6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4142FFu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414310u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x6Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001433E;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41432Bu); lift_push32(cpu, r); sfera_sub_00412E60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414337u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1433Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001433E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41433Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14347u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_00014347: cpu->eip = LIFT_CODE_TOKEN_VA(0x414347u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414350u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000143ED;
    label_00014355: cpu->eip = LIFT_CODE_TOKEN_VA(0x414355u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41435Eu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x6Cu, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014347;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41437Bu); lift_push32(cpu, r); sfera_sub_00411230(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414382u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41438Bu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000143ED;
    label_0001438D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41438Du);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414396u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x6Cu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4143A3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000143C0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4143B9u); lift_push32(cpu, r); sfera_sub_00409E50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x143C0u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000143C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4143C0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4143C9u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000143ED;
    label_000143CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4143CBu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4143D3u); lift_push32(cpu, r); sfera_sub_0040BBA0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4143DDu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000143E8;
    label_000143E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4143E5u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_000143E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4143E8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x143EDu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000143ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4143EDu);
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x64u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014440: cpu->eip = LIFT_CODE_TOKEN_VA(0x414440u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414477u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000145D2;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000144E6;
        case 1u: goto label_00014542;
        case 2u: goto label_0001457A;
        case 3u: goto label_00014487;
        case 4u: goto label_000144B0;
        case 5u: goto label_000144D9;
        case 6u: case 7u: case 8u: goto label_000145D2;
        case 9u: goto label_000145B8;
        default: lift_trap(cpu, 0x414480u, "resolved jump-table index out of range"); return;
    }
label_00014487: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41448Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414493u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000145DA;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4144A9u); lift_push32(cpu, r); sfera_sub_00407430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000145D5;
    label_000144B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4144B0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4144B5u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4144BCu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000145DA;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4144D2u); lift_push32(cpu, r); sfera_sub_00407470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000145D5;
    label_000144D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4144D9u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000145D5;
    label_000144E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4144E6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4144EFu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x58u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414500u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x58u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014526;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41451Fu); lift_push32(cpu, r); sfera_sub_00413B30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14526u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00014526: cpu->eip = LIFT_CODE_TOKEN_VA(0x414526u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store8(cpu->esp + 0x58u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14534u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    label_00014534: cpu->eip = LIFT_CODE_TOKEN_VA(0x414534u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41453Du); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000145DA;
    label_00014542: cpu->eip = LIFT_CODE_TOKEN_VA(0x414542u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41454Bu); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x58u, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014534;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414568u); lift_push32(cpu, r); sfera_sub_004112D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41456Fu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414578u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000145DA;
    label_0001457A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41457Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414583u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x58u, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414590u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000145AD;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4145A6u); lift_push32(cpu, r); sfera_sub_00409F10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x145ADu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000145AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4145ADu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4145B6u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000145DA;
    label_000145B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4145B8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4145C0u); lift_push32(cpu, r); sfera_sub_0040BC20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4145CAu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000145D5;
    label_000145D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4145D2u);
    cpu->ecx |= 0xFFFFFFFFu;
    label_000145D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4145D5u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x145DAu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_000145DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4145DAu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014620: cpu->eip = LIFT_CODE_TOKEN_VA(0x414620u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00014684;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00014630;
        case 1u: goto label_00014645;
        case 2u: goto label_00014684;
        case 3u: goto label_0001465A;
        case 4u: goto label_0001466F;
        default: lift_trap(cpu, 0x414629u, "resolved jump-table index out of range"); return;
    }
label_00014630: ;
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00014640;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014684;
    goto label_00013260;
    label_00014640: cpu->eip = LIFT_CODE_TOKEN_VA(0x414640u);
    goto label_0000A870;
    label_00014645: cpu->eip = LIFT_CODE_TOKEN_VA(0x414645u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00014655;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014684;
    goto label_00013420;
    label_00014655: cpu->eip = LIFT_CODE_TOKEN_VA(0x414655u);
    goto label_0000A9E0;
    label_0001465A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41465Au);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001466A;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014684;
    goto label_00013780;
    label_0001466A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41466Au);
    goto label_000135E0;
    label_0001466F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41466Fu);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001467F;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014684;
    goto label_00013960;
    label_0001467F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41467Fu);
    goto label_0000E6D0;
    label_00014684: cpu->eip = LIFT_CODE_TOKEN_VA(0x414684u);
    lift_return(cpu, 0u, stop_address); return;
    label_000146A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4146A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4146D7u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_0001482B;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00014746;
        case 1u: goto label_000147AD;
        case 2u: goto label_000147DC;
        case 3u: goto label_000146E7;
        case 4u: goto label_00014710;
        case 5u: goto label_00014739;
        case 6u: case 7u: case 8u: goto label_0001482B;
        case 9u: goto label_00014811;
        default: lift_trap(cpu, 0x4146E0u, "resolved jump-table index out of range"); return;
    }
label_000146E7: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4146ECu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4146F3u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014833;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414709u); lift_push32(cpu, r); sfera_sub_00407300(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0001482E;
    label_00014710: cpu->eip = LIFT_CODE_TOKEN_VA(0x414710u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414715u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41471Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014833;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414732u); lift_push32(cpu, r); sfera_sub_00407340(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_0001482E;
    label_00014739: cpu->eip = LIFT_CODE_TOKEN_VA(0x414739u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0001482E;
    label_00014746: cpu->eip = LIFT_CODE_TOKEN_VA(0x414746u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41474Fu); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x3Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414760u); lift_push32(cpu, r); sfera_sub_0040A500(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x3Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001478E;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41477Bu); lift_push32(cpu, r); sfera_sub_00413B80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414787u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1478Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0001478E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41478Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14797u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_00014797: cpu->eip = LIFT_CODE_TOKEN_VA(0x414797u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x3Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4147A8u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    goto label_00014833;
    label_000147AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4147ADu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4147B6u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x3Cu, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014797;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4147D3u); lift_push32(cpu, r); sfera_sub_00411890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4147DAu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00014797;
    label_000147DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4147DCu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4147E5u); lift_push32(cpu, r); sfera_sub_00402720(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x3Cu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4147F2u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014797;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414808u); lift_push32(cpu, r); sfera_sub_00409E90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41480Fu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00014797;
    label_00014811: cpu->eip = LIFT_CODE_TOKEN_VA(0x414811u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414819u); lift_push32(cpu, r); sfera_sub_0040D740(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414823u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_0001482E;
    label_0001482B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41482Bu);
    cpu->ecx |= 0xFFFFFFFFu;
    label_0001482E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41482Eu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x14833u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00014833: cpu->eip = LIFT_CODE_TOKEN_VA(0x414833u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014880: cpu->eip = LIFT_CODE_TOKEN_VA(0x414880u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00014904;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00014890;
        case 1u: goto label_000148AD;
        case 2u: goto label_00014904;
        case 3u: goto label_000148CA;
        case 4u: goto label_000148E7;
        default: lift_trap(cpu, 0x414889u, "resolved jump-table index out of range"); return;
    }
label_00014890: ;
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148A8;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148A3;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014904;
    goto label_000122D0;
    label_000148A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148A3u);
    goto label_00013D00;
    label_000148A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148A8u);
    goto label_00012160;
    label_000148AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148ADu);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148C5;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148C0;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014904;
    goto label_00012610;
    label_000148C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148C0u);
    goto label_00013ED0;
    label_000148C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148C5u);
    goto label_000124A0;
    label_000148CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148CAu);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148E2;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148DD;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014904;
    goto label_000146A0;
    label_000148DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148DDu);
    goto label_00014250;
    label_000148E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148E2u);
    goto label_000140A0;
    label_000148E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148E7u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148FF;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148FA;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014904;
    goto label_00012990;
    label_000148FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148FAu);
    goto label_00014440;
    label_000148FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4148FFu);
    goto label_000127F0;
    label_00014904: cpu->eip = LIFT_CODE_TOKEN_VA(0x414904u);
    lift_return(cpu, 0u, stop_address); return;
    label_00014920: cpu->eip = LIFT_CODE_TOKEN_VA(0x414920u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414925u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00014938;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x19285u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00014940;
    label_00014938: cpu->eip = LIFT_CODE_TOKEN_VA(0x414938u);
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00014940: cpu->eip = LIFT_CODE_TOKEN_VA(0x414940u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00014979;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00014950;
        case 1u: goto label_00014955;
        case 2u: goto label_0001495A;
        case 3u: goto label_0001496F;
        case 4u: goto label_00014974;
        default: lift_trap(cpu, 0x414949u, "resolved jump-table index out of range"); return;
    }
label_00014950: ;
    goto label_000116B0;
    label_00014955: cpu->eip = LIFT_CODE_TOKEN_VA(0x414955u);
    goto label_00013CC0;
    label_0001495A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41495Au);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001496A;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014979;
    goto label_000101D0;
    label_0001496A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41496Au);
    goto label_00009650;
    label_0001496F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41496Fu);
    goto label_00014620;
    label_00014974: cpu->eip = LIFT_CODE_TOKEN_VA(0x414974u);
    goto label_00014880;
    label_00014979: cpu->eip = LIFT_CODE_TOKEN_VA(0x414979u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004149A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4149A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->edi + 4u, 0u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_000149DA;
    lift_push32(cpu, cpu->ebx);
    label_000149C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4149C0u);
    cpu->ebx = lift_load32(cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4149CAu); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4149D0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000149C0;
    cpu->ebx = lift_pop32(cpu);
    label_000149DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4149DAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004149E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4149E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00014A13;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00014A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x414A00u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414A08u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00014A00;
    cpu->edi = lift_pop32(cpu);
    label_00014A13: cpu->eip = LIFT_CODE_TOKEN_VA(0x414A13u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414A1Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00401E50(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x414A30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414A60u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0xCu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414A70u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014AAD;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414A8Fu); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014AAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x414AADu);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414AD7u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x414AD7u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x414AE0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414B10u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0xCu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414B20u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014B5D;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414B3Fu); lift_push32(cpu, r); sfera_sub_00401E00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014B5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x414B5Du);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414B87u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x414B87u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x414BF0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414C20u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x10u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414C30u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014C6D;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414C4Fu); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014C6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x414C6Du);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414C97u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x414C97u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x414CA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->edi = (uint32_t)(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414CE6u); lift_push32(cpu, r); sfera_sub_004149A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414CEEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D00u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00014D10;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D0Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00014D10: cpu->eip = LIFT_CODE_TOKEN_VA(0x414D10u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x414D50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D80u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x24u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D90u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014DCD;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414DAFu); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014DCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x414DCDu);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414DF7u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x414DF7u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x414E00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00014F3C;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00014E34;
        case 1u: goto label_00014E78;
        case 2u: goto label_00014F3C;
        case 3u: goto label_00014EBC;
        case 4u: goto label_00014EFC;
        default: lift_trap(cpu, 0x414E2Du, "resolved jump-table index out of range"); return;
    }
label_00014E34: ;
    cpu->edx = 0xDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414E43u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414E4Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414E68u); lift_push32(cpu, r); sfera_sub_00414A30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014E78: cpu->eip = LIFT_CODE_TOKEN_VA(0x414E78u);
    cpu->edx = 0xDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414E87u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414E8Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414EACu); lift_push32(cpu, r); sfera_sub_00414AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014EBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x414EBCu);
    cpu->edx = 0xDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414ECBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414ED2u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414EECu); lift_push32(cpu, r); sfera_sub_00414D50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014EFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x414EFCu);
    cpu->edx = 0xDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414F0Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414F12u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414F2Cu); lift_push32(cpu, r); sfera_sub_00414BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00014F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x414F3Cu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004150C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4150C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4150F0u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415100u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00015158;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x14u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x15u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415132u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41513Au); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015158: cpu->eip = LIFT_CODE_TOKEN_VA(0x415158u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415182u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x415182u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415190u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4151C0u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4151D0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00015228;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x14u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x15u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415202u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41520Au); lift_push32(cpu, r); sfera_sub_00401E00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015228: cpu->eip = LIFT_CODE_TOKEN_VA(0x415228u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415252u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x415252u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415260u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4152B2u); lift_push32(cpu, r); sfera_sub_00406340(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4152BBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4152CDu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_000152DD;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4152DAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000152DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4152DDu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415370u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4153A0u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x1Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4153B0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00015408;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x18u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x19u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4153E2u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4153EAu); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015408: cpu->eip = LIFT_CODE_TOKEN_VA(0x415408u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415432u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x415432u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415440u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415492u); lift_push32(cpu, r); sfera_sub_00409F90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41549Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4154ADu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_000154BD;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4154BAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000154BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4154BDu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004156A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4156A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4156D0u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x30u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4156E0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00015738;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x2Cu, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x2Du, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415712u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41571Au); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015738: cpu->eip = LIFT_CODE_TOKEN_VA(0x415738u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415762u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x415762u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415770u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4157A0u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x30u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4157B0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00015808;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x2Cu, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x2Du, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4157E2u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4157EAu); lift_push32(cpu, r); sfera_sub_00401E00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015808: cpu->eip = LIFT_CODE_TOKEN_VA(0x415808u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415832u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x415832u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415840u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415870u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x30u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415880u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000158D8;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x2Cu, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x2Du, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4158B2u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4158BAu); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_000158D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4158D8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415902u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x415902u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415910u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415940u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x48u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415950u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000159A8;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x44u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x45u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415982u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41598Au); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_000159A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4159A8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4159D2u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4159D2u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004159E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4159E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415A10u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415A20u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00015A78;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x30u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store8(cpu->edx + 0x31u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415A52u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415A5Au); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015A78: cpu->eip = LIFT_CODE_TOKEN_VA(0x415A78u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415AA2u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x415AA2u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415DB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00015DB0;
    label_00015AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x415AB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00015B17;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00015B57;
    cpu->edx = (uint32_t)(cpu->ecx + 0x7Au);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415AE6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415AEDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015B57;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415B07u); lift_push32(cpu, r); sfera_sub_004156A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015B17: cpu->eip = LIFT_CODE_TOKEN_VA(0x415B17u);
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415B26u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415B2Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015B57;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415B47u); lift_push32(cpu, r); sfera_sub_004150C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015B57: cpu->eip = LIFT_CODE_TOKEN_VA(0x415B57u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015B70: cpu->eip = LIFT_CODE_TOKEN_VA(0x415B70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00015BD7;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00015C17;
    cpu->edx = (uint32_t)(cpu->ecx + 0x7Au);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415BA6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415BADu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015C17;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415BC7u); lift_push32(cpu, r); sfera_sub_00415770(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015BD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x415BD7u);
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415BE6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415BEDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015C17;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415C07u); lift_push32(cpu, r); sfera_sub_00415190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015C17: cpu->eip = LIFT_CODE_TOKEN_VA(0x415C17u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015C30: cpu->eip = LIFT_CODE_TOKEN_VA(0x415C30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00015C97;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00015CD7;
    cpu->edx = (uint32_t)(cpu->ecx + 0x7Au);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415C66u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415C6Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015CD7;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415C87u); lift_push32(cpu, r); sfera_sub_00415910(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015C97: cpu->eip = LIFT_CODE_TOKEN_VA(0x415C97u);
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415CA6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415CADu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015CD7;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415CC7u); lift_push32(cpu, r); sfera_sub_00415840(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015CD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x415CD7u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015CF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x415CF0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00015D57;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00015D97;
    cpu->edx = (uint32_t)(cpu->ecx + 0x7Au);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415D26u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415D2Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015D97;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415D47u); lift_push32(cpu, r); sfera_sub_004159E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015D57: cpu->eip = LIFT_CODE_TOKEN_VA(0x415D57u);
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415D66u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415D6Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015D97;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415D87u); lift_push32(cpu, r); sfera_sub_00415370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015D97: cpu->eip = LIFT_CODE_TOKEN_VA(0x415D97u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00015DB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x415DB0u);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00015DDB;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00015DBF;
        case 1u: goto label_00015DC6;
        case 2u: goto label_00015DDB;
        case 3u: goto label_00015DCD;
        case 4u: goto label_00015DD4;
        default: lift_trap(cpu, 0x415DB8u, "resolved jump-table index out of range"); return;
    }
label_00015DBF: ;
    cpu->ecx = cpu->edx;
    goto label_00015AB0;
    label_00015DC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x415DC6u);
    cpu->ecx = cpu->edx;
    goto label_00015B70;
    label_00015DCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x415DCDu);
    cpu->ecx = cpu->edx;
    goto label_00015C30;
    label_00015DD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x415DD4u);
    cpu->ecx = cpu->edx;
    goto label_00015CF0;
    label_00015DDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x415DDBu);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415E00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415E52u); lift_push32(cpu, r); sfera_sub_0040D400(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415E5Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415E6Du); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_00015E7D;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415E7Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00015E7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x415E7Du);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415EA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415EA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415EF2u); lift_push32(cpu, r); sfera_sub_0040D4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415EFBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415F0Du); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_00015F1D;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415F1Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00015F1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x415F1Du);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415F40u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415F92u); lift_push32(cpu, r); sfera_sub_0040D5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415F9Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415FADu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_00015FBD;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415FBAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00015FBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x415FBDu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x415FE0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416032u); lift_push32(cpu, r); sfera_sub_0040D670(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41603Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41604Du); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_0001605D;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41605Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0001605D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41605Du);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416080u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000160AF;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00016093;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00016093: cpu->eip = LIFT_CODE_TOKEN_VA(0x416093u);
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4160A2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4160ABu); lift_push32(cpu, r); sfera_sub_00415E00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000160AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4160AFu);
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4160BEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4160C7u); lift_push32(cpu, r); sfera_sub_00415260(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004160D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4160D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000160FF;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000160E3;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000160E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4160E3u);
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4160F2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4160FBu); lift_push32(cpu, r); sfera_sub_00415F40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000160FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4160FFu);
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41610Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416117u); lift_push32(cpu, r); sfera_sub_00415EA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416120u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001614F;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00016133;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00016133: cpu->eip = LIFT_CODE_TOKEN_VA(0x416133u);
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416142u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41614Bu); lift_push32(cpu, r); sfera_sub_00415FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0001614F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41614Fu);
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41615Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416167u); lift_push32(cpu, r); sfera_sub_00415440(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004161D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4161D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416200u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416210u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016260;
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x10u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_store8(cpu->edx + 0x11u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416242u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 3u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016260: cpu->eip = LIFT_CODE_TOKEN_VA(0x416260u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41628Au); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41628Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416290u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4162E2u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4162EBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4162FDu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_0001630D;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41630Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0001630D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41630Du);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004163A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4163A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4163D0u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, 0x2Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4163E0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016430;
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x28u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_store8(cpu->edx + 0x29u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x28u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416412u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 3u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016430: cpu->eip = LIFT_CODE_TOKEN_VA(0x416430u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41645Au); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41645Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416460u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000164C7;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00016507;
    cpu->edx = (uint32_t)(cpu->ecx + 0xEu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416496u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41649Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00016507;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4164B7u); lift_push32(cpu, r); sfera_sub_004163A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000164C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4164C7u);
    cpu->edx = 0xEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4164D6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4164DDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00016507;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4164F7u); lift_push32(cpu, r); sfera_sub_004161D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016507: cpu->eip = LIFT_CODE_TOKEN_VA(0x416507u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416520u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x2Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416572u); lift_push32(cpu, r); sfera_sub_0040A7A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41657Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41658Du); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_0001659D;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41659Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0001659D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41659Du);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416610u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi))) goto label_00016642;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00016630: cpu->eip = LIFT_CODE_TOKEN_VA(0x416630u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416638u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi))) goto label_00016630;
    cpu->edi = lift_pop32(cpu);
    label_00016642: cpu->eip = LIFT_CODE_TOKEN_VA(0x416642u);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41664Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416650u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016666;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416663u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016666: cpu->eip = LIFT_CODE_TOKEN_VA(0x416666u);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 8u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00016696;
    label_00016684: cpu->eip = LIFT_CODE_TOKEN_VA(0x416684u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41668Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00016684;
    label_00016696: cpu->eip = LIFT_CODE_TOKEN_VA(0x416696u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41669Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416A30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016A71;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416A6Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016A71: cpu->eip = LIFT_CODE_TOKEN_VA(0x416A71u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416A8Du); lift_push32(cpu, r); sfera_sub_0040A060(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416A95u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416AA7u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016AB7;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416AB4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016AB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x416AB7u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416AD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016B11;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416B0Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016B11: cpu->eip = LIFT_CODE_TOKEN_VA(0x416B11u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416B2Du); lift_push32(cpu, r); sfera_sub_00408A50(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416B35u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416B47u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016B57;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416B54u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016B57: cpu->eip = LIFT_CODE_TOKEN_VA(0x416B57u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416B70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016BB1;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416BAEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016BB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x416BB1u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416BCDu); lift_push32(cpu, r); sfera_sub_0040A0C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416BD5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416BE7u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016BF7;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416BF4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016BF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x416BF7u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416C10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416C41u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x10u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416C60u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00016CC2;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416C8Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416C9Bu); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416CA3u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016CC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x416CC2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416CECu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x416CECu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416CF0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416D21u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416D40u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00016DA2;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416D6Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416D7Bu); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416D83u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016DA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x416DA2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416DCCu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x416DCCu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416DD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416E01u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x10u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416E20u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00016E82;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416E4Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416E5Bu); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416E63u); lift_push32(cpu, r); sfera_sub_00401E00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016E82: cpu->eip = LIFT_CODE_TOKEN_VA(0x416E82u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416EACu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x416EACu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416EB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416EE1u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416F00u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00016F62;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416F2Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416F3Bu); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416F43u); lift_push32(cpu, r); sfera_sub_00401E00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016F62: cpu->eip = LIFT_CODE_TOKEN_VA(0x416F62u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416F8Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x416F8Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x416F90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416FC1u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416FE0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00017042;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41700Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41701Bu); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417023u); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017042: cpu->eip = LIFT_CODE_TOKEN_VA(0x417042u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41706Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41706Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417070u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4170A1u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4170C0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00017122;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4170EEu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4170FBu); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417103u); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017122: cpu->eip = LIFT_CODE_TOKEN_VA(0x417122u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41714Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41714Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004172F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4172F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417321u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x28u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417340u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000173A2;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41736Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41737Bu); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417383u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_000173A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4173A2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4173CCu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4173CCu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004173D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4173D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417401u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x28u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417420u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00017482;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41744Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41745Bu); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417463u); lift_push32(cpu, r); sfera_sub_00401E00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017482: cpu->eip = LIFT_CODE_TOKEN_VA(0x417482u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4174ACu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4174ACu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004174B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4174B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4174E1u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x28u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417500u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00017562;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41752Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41753Bu); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417543u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017562: cpu->eip = LIFT_CODE_TOKEN_VA(0x417562u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41758Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41758Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417590u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4175C1u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x40u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4175E0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00017642;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41760Eu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41761Bu); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417623u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017642: cpu->eip = LIFT_CODE_TOKEN_VA(0x417642u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41766Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41766Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417670u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4176A1u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x2Cu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4176C0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00017722;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4176EEu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4176FBu); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417703u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017722: cpu->eip = LIFT_CODE_TOKEN_VA(0x417722u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41774Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41774Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417750u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417781u); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x2Cu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4177A0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00017802;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4177CEu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4177DBu); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4177E3u); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017802: cpu->eip = LIFT_CODE_TOKEN_VA(0x417802u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41782Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x41782Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417C70(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00017C70;
    label_00017830: cpu->eip = LIFT_CODE_TOKEN_VA(0x417830u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000178E8;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000178A8;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00017928;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417873u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41787Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417898u); lift_push32(cpu, r); sfera_sub_00416CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000178A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4178A8u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4178B7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4178BEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4178D8u); lift_push32(cpu, r); sfera_sub_004172F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000178E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4178E8u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4178F7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4178FEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417918u); lift_push32(cpu, r); sfera_sub_00416C10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017928: cpu->eip = LIFT_CODE_TOKEN_VA(0x417928u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017940: cpu->eip = LIFT_CODE_TOKEN_VA(0x417940u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000179F8;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000179B8;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00017A38;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417983u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41798Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4179A8u); lift_push32(cpu, r); sfera_sub_00416EB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000179B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4179B8u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4179C7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4179CEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4179E8u); lift_push32(cpu, r); sfera_sub_004173D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000179F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4179F8u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417A07u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417A0Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417A28u); lift_push32(cpu, r); sfera_sub_00416DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017A38: cpu->eip = LIFT_CODE_TOKEN_VA(0x417A38u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017A50: cpu->eip = LIFT_CODE_TOKEN_VA(0x417A50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017B08;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017AC8;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00017B48;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417A93u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417A9Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417AB8u); lift_push32(cpu, r); sfera_sub_00417670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017AC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x417AC8u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417AD7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417ADEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417AF8u); lift_push32(cpu, r); sfera_sub_00417590(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017B08: cpu->eip = LIFT_CODE_TOKEN_VA(0x417B08u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417B17u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417B1Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417B38u); lift_push32(cpu, r); sfera_sub_004174B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017B48: cpu->eip = LIFT_CODE_TOKEN_VA(0x417B48u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017B60: cpu->eip = LIFT_CODE_TOKEN_VA(0x417B60u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017C18;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017BD8;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00017C58;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417BA3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417BAAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417BC8u); lift_push32(cpu, r); sfera_sub_00417070(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017BD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x417BD8u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417BE7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417BEEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417C08u); lift_push32(cpu, r); sfera_sub_00417750(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017C18: cpu->eip = LIFT_CODE_TOKEN_VA(0x417C18u);
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417C27u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417C2Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417C48u); lift_push32(cpu, r); sfera_sub_00416F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017C58: cpu->eip = LIFT_CODE_TOKEN_VA(0x417C58u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00017C70: cpu->eip = LIFT_CODE_TOKEN_VA(0x417C70u);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00017C9B;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00017C7F;
        case 1u: goto label_00017C86;
        case 2u: goto label_00017C9B;
        case 3u: goto label_00017C8D;
        case 4u: goto label_00017C94;
        default: lift_trap(cpu, 0x417C78u, "resolved jump-table index out of range"); return;
    }
label_00017C7F: ;
    cpu->ecx = cpu->edx;
    goto label_00017830;
    label_00017C86: cpu->eip = LIFT_CODE_TOKEN_VA(0x417C86u);
    cpu->ecx = cpu->edx;
    goto label_00017940;
    label_00017C8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x417C8Du);
    cpu->ecx = cpu->edx;
    goto label_00017A50;
    label_00017C94: cpu->eip = LIFT_CODE_TOKEN_VA(0x417C94u);
    cpu->ecx = cpu->edx;
    goto label_00017B60;
    label_00017C9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x417C9Bu);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417CC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017CD6;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417CD3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017CD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x417CD6u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417CE7u); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417CFAu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017D0A;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417D07u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017D0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x417D0Au);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417D20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017D36;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417D33u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017D36: cpu->eip = LIFT_CODE_TOKEN_VA(0x417D36u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417D47u); lift_push32(cpu, r); sfera_sub_0040BB40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417D50u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417D5Au); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017D6A;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417D67u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017D6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x417D6Au);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417D80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017D96;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417D93u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017D96: cpu->eip = LIFT_CODE_TOKEN_VA(0x417D96u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417DA7u); lift_push32(cpu, r); sfera_sub_0040BBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417DB0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417DBAu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017DCA;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417DC7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017DCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x417DCAu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417DE0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017E21;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417E1Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017E21: cpu->eip = LIFT_CODE_TOKEN_VA(0x417E21u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417E3Du); lift_push32(cpu, r); sfera_sub_0040D740(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417E45u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417E57u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00017E67;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417E64u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017E67: cpu->eip = LIFT_CODE_TOKEN_VA(0x417E67u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417E80u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017EC1;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417EBEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017EC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x417EC1u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417EDDu); lift_push32(cpu, r); sfera_sub_0040BC20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417EE5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417EF7u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00017F07;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F04u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017F07: cpu->eip = LIFT_CODE_TOKEN_VA(0x417F07u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417F20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017F6E;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017F52;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017F36;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00017F36: cpu->eip = LIFT_CODE_TOKEN_VA(0x417F36u);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F45u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F4Eu); lift_push32(cpu, r); sfera_sub_00416A30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00017F52: cpu->eip = LIFT_CODE_TOKEN_VA(0x417F52u);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F61u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F6Au); lift_push32(cpu, r); sfera_sub_00417CC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00017F6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x417F6Eu);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F7Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F85u); lift_push32(cpu, r); sfera_sub_00416650(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F8Cu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417F92u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x417FA0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017FEE;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017FD2;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00017FB6;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00017FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x417FB6u);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417FC5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417FCEu); lift_push32(cpu, r); sfera_sub_00417DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00017FD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x417FD2u);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417FE1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417FEAu); lift_push32(cpu, r); sfera_sub_00417D80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00017FEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x417FEEu);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417FFDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418006u); lift_push32(cpu, r); sfera_sub_00417D20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418010u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001805E;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00018042;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00018026;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00018026: cpu->eip = LIFT_CODE_TOKEN_VA(0x418026u);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418035u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41803Eu); lift_push32(cpu, r); sfera_sub_00416B70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00018042: cpu->eip = LIFT_CODE_TOKEN_VA(0x418042u);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418051u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41805Au); lift_push32(cpu, r); sfera_sub_00417E80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0001805E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41805Eu);
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41806Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418076u); lift_push32(cpu, r); sfera_sub_00416AD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004180D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4180D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4180FDu); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418119u); lift_push32(cpu, r); sfera_sub_00401DF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418140u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41816Du); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418189u); lift_push32(cpu, r); sfera_sub_00401E00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004181B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4181B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4181DDu); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4181F9u); lift_push32(cpu, r); sfera_sub_00401E10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418220u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018233;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418230u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00018233: cpu->eip = LIFT_CODE_TOKEN_VA(0x418233u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41824Fu); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_0001825F;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41825Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0001825F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41825Fu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004182C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4182C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebp)) goto label_0001831A;
    cpu->ebx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_0001830E;
    (void)cpu;
    label_00018300: cpu->eip = LIFT_CODE_TOKEN_VA(0x418300u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418307u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 8u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_00018300;
    label_0001830E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41830Eu);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418317u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0001831A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41831Au);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->edi + 0x10u, cpu->ebp);
    lift_store32(cpu->edi + 0x14u, cpu->ebp);
    lift_store32(cpu->edi + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418332u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418350u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41837Du); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418399u); lift_push32(cpu, r); sfera_sub_00401E30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418400u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41842Du); lift_push32(cpu, r); sfera_sub_00401E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418449u); lift_push32(cpu, r); sfera_sub_00401E20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418470u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_000185F0;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000184A4;
        case 1u: goto label_000184E8;
        case 2u: goto label_0001852C;
        case 3u: goto label_00018570;
        case 4u: goto label_000185B0;
        default: lift_trap(cpu, 0x41849Du, "resolved jump-table index out of range"); return;
    }
label_000184A4: ;
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4184B3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4184BAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4184D8u); lift_push32(cpu, r); sfera_sub_004180D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000184E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4184E8u);
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4184F7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4184FEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41851Cu); lift_push32(cpu, r); sfera_sub_00418140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_0001852C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41852Cu);
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41853Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418542u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418560u); lift_push32(cpu, r); sfera_sub_004181B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00018570: cpu->eip = LIFT_CODE_TOKEN_VA(0x418570u);
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41857Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418586u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4185A0u); lift_push32(cpu, r); sfera_sub_00418400(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000185B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4185B0u);
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4185BFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4185C6u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4185E0u); lift_push32(cpu, r); sfera_sub_00418350(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000185F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4185F0u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418620u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00018647;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41863Bu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418644u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00018647: cpu->eip = LIFT_CODE_TOKEN_VA(0x418647u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418663u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_00018673;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418670u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00018673: cpu->eip = LIFT_CODE_TOKEN_VA(0x418673u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418750u);
    cpu->esp -= 0x414u;
    cpu->eax = lift_load32(cpu->esp + 0x418u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\%d%s");
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, 0x400u); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x418787u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41878Du);
    cpu->ebp = native_function_address32(&::fopen);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->edx);
    cpu->edi = 0u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x187A1u), LIFT_CODE_TOKEN_RVA(0x1879Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4187A1u);
    cpu->esi = cpu->eax;
    cpu->esp += 0x1Cu;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00018875;
    cpu->edi = native_function_address32(&::fclose);
    label_000187B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4187B4u);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_00018815;
    lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x4187BEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4187C4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4187C5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4187CBu);
    cpu->esp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x989680u)) goto label_00018815;
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x187D8u), LIFT_CODE_TOKEN_RVA(0x187D6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4187D8u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x187E4u), LIFT_CODE_TOKEN_RVA(0x187E2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4187E4u);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00018815;
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4187F3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4187F9u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x187FCu), LIFT_CODE_TOKEN_RVA(0x187FAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4187FCu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x1880Au), LIFT_CODE_TOKEN_RVA(0x18808u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41880Au);
    cpu->esi = cpu->eax;
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000187B4;
    goto label_00018877;
    label_00018815: cpu->eip = LIFT_CODE_TOKEN_VA(0x418815u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x41881Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418820u);
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load16(cpu->esp + 0x1Au);
    cpu->edx = lift_load16(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load16(cpu->esp + 0x1Au);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load16(cpu->esp + 0x22u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%02u.%02u.%04u %02u:%02u:%02u "); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x41884Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418850u);
    cpu->ecx = lift_load32(cpu->esp + 0x44Cu);
    cpu->ebx = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x450u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::vfprintf), LIFT_CODE_TOKEN_VA(0x418863u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418869u);
    lift_push32(cpu, cpu->esi);
    cpu->ebx += cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1886Eu), LIFT_CODE_TOKEN_RVA(0x1886Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41886Eu);
    cpu->esp += 0x30u;
    cpu->eax = cpu->ebx;
    goto label_00018877;
    label_00018875: cpu->eip = LIFT_CODE_TOKEN_VA(0x418875u);
    cpu->eax = cpu->edi;
    label_00018877: cpu->eip = LIFT_CODE_TOKEN_VA(0x418877u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004188A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4188A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4188CEu); lift_push32(cpu, r); sfera_sub_00419810(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_push32(cpu, 0x23u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    cpu->ecx = 0x13880u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esi + 0xEA68u, cpu->ebx);
    lift_store32(cpu->esi + 0xEA6Cu, cpu->ebx);
    lift_store32(cpu->esi + 0xEA70u, cpu->ebx);
    lift_store32(cpu->esi + 0xEA74u, cpu->ebx);
    lift_store32(cpu->esi + 0xEA78u, cpu->ebx);
    lift_store32(cpu->esi + 0xEA7Cu, cpu->ebx);
    lift_store32(cpu->esi + 0xEA80u, cpu->ebx);
    lift_store32(cpu->esi + 0xEA84u, cpu->ebx);
    lift_store8(cpu->esi + 0xEA88u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0xEA8Cu, cpu->ebx);
    lift_store32(cpu->esi + 0xEA90u, cpu->ebx);
    lift_store32(cpu->esi + 0xEA94u, cpu->ebx);
    lift_store32(cpu->esi + 0xEA98u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418933u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0xEA9Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x418940u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418945u);
    cpu->eax = 0u;
    lift_push32(cpu, (uintptr_t)"============================================================================\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store32(cpu->esi + 0xEAA0u, cpu->ebx);
    lift_store8(cpu->esi + 0xEAA4u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esi + 0xEAA6u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0xEAA8u, cpu->ebx);
    lift_store32(cpu->esi + 0xEAACu, cpu->ebx);
    lift_store8(cpu->esi + 0xEAB0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0xEAB2u, cpu->eax);
    lift_store32(cpu->esi + 0xEAB8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418986u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)"Create connect manager\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418995u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004189B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4189B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) == (uint8_t)(1u)) goto label_000189FD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::Sleep);
    label_000189C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4189C5u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) == (uint8_t)(0u)) goto label_000189EF;
    cpu->eax = lift_load32(cpu->esi + 0xEA6Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000189EF;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0xEA60u)) <= (int32_t)(uint32_t)(0u)) goto label_000189EB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x189EBu); lift_push32(cpu, r); sfera_sub_00419730(cpu,r); if (cpu->eip != r) return; }
    label_000189EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4189EBu);
    lift_push32(cpu, 6u);
    goto label_000189F1;
    label_000189EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4189EFu);
    lift_push32(cpu, 0xAu);
    label_000189F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4189F1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x189F3u), LIFT_CODE_TOKEN_RVA(0x189F1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4189F3u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) != (uint8_t)(1u)) goto label_000189C5;
    cpu->edi = lift_pop32(cpu);
    label_000189FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4189FDu);
    lift_push32(cpu, (uintptr_t)"Rnd Thread exit\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418A0Cu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418A20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA4u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00018B10;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(1)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418A43u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xEA70u);
    cpu->edi = native_function_address32(&::WaitForSingleObject);
    cpu->esp += 8u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esi + 0xEA88u, cpu->ebx & 0xFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x18A5Du), LIFT_CODE_TOKEN_RVA(0x18A5Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418A5Du);
    cpu->ebx = native_function_address32(&::TerminateThread);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018A72;
    cpu->ecx = lift_load32(cpu->esi + 0xEA70u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x18A72u), LIFT_CODE_TOKEN_RVA(0x18A70u))) { return; }
    label_00018A72: cpu->eip = LIFT_CODE_TOKEN_VA(0x418A72u);
    cpu->edx = lift_load32(cpu->esi + 0xEA70u);
    cpu->ebp = native_function_address32(&::CloseHandle);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x18A81u), LIFT_CODE_TOKEN_RVA(0x18A7Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418A81u);
    cpu->eax = lift_load32(cpu->esi + 0xEA78u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x18A8Cu), LIFT_CODE_TOKEN_RVA(0x18A8Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418A8Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018A9B;
    cpu->ecx = lift_load32(cpu->esi + 0xEA78u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x18A9Bu), LIFT_CODE_TOKEN_RVA(0x18A99u))) { return; }
    label_00018A9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x418A9Bu);
    cpu->edx = lift_load32(cpu->esi + 0xEA78u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x18AA4u), LIFT_CODE_TOKEN_RVA(0x18AA2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418AA4u);
    cpu->eax = lift_load32(cpu->esi + 0xEA80u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x18AAFu), LIFT_CODE_TOKEN_RVA(0x18AADu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418AAFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018ABE;
    cpu->ecx = lift_load32(cpu->esi + 0xEA80u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x18ABEu), LIFT_CODE_TOKEN_RVA(0x18ABCu))) { return; }
    label_00018ABE: cpu->eip = LIFT_CODE_TOKEN_VA(0x418ABEu);
    cpu->edx = lift_load32(cpu->esi + 0xEA80u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x18AC7u), LIFT_CODE_TOKEN_RVA(0x18AC5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418AC7u);
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(2)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418AD6u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018AF0;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00018AF0;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418AEBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418AF0u);
    label_00018AF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x418AF0u);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418AF0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418AF5u);
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(3)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store16(cpu->esi + 0xEAA4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418B0Du); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00018B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x418B10u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418B20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) == (uint8_t)(0u)) goto label_00018B9F;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418B32u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418B38u);
    cpu->eax = lift_load32(cpu->esi + 0xEAA0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00018B93;
    cpu->ecx = lift_load32(cpu->esi + 0xEA68u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x418B53u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418B58u);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x418B5Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418B5Fu);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00018B93;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xEAA0u))) goto label_00018B87;
    cpu->eax = lift_load32(cpu->esi + 0xEA9Cu);
    cpu->edx = 0x13880u;
    cpu->edx -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x418B7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418B84u);
    cpu->esp += 0xCu;
    label_00018B87: cpu->eip = LIFT_CODE_TOKEN_VA(0x418B87u);
    lift_store32(cpu->esi + 0xEAA0u, (uint64_t)(lift_load32(cpu->esi + 0xEAA0u)) - (uint64_t)(cpu->edi) - (uint64_t)(0u));
    lift_store32(cpu->esi + 0xEA90u, (uint64_t)(lift_load32(cpu->esi + 0xEA90u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    label_00018B93: cpu->eip = LIFT_CODE_TOKEN_VA(0x418B93u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418B98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418B9Eu);
    cpu->edi = lift_pop32(cpu);
    label_00018B9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x418B9Fu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418BB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418BE4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418BEAu);
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    cpu->ebp = cpu->eax & 0xFFFFu;
    cpu->ecx = 0x13880u;
    cpu->ecx -= lift_load32(cpu->esi + 0xEAA0u);
    cpu->edi = cpu->ebp;
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edi)) goto label_00018C4F;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: send buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418C1Cu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018C3E;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00018C3E;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418C39u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418C3Eu);
    label_00018C3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x418C3Eu);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418C3Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418C43u);
    lift_store8(cpu->esi + 0xEAA5u, 0u);
    goto label_00018D2B;
    label_00018C4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x418C4Fu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x418C4Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418C55u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00018C61;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFCu;
    ++cpu->eax;
    label_00018C61: cpu->eip = LIFT_CODE_TOKEN_VA(0x418C61u);
    cpu->edx = lift_load32(cpu->esi + 0xEAA0u);
    ++cpu->eax;
    lift_store16(cpu->esi + 0xEAB2u, (uint64_t)(lift_load16(cpu->esi + 0xEAB2u)) + (uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 0xEA9Cu);
    lift_store16(cpu->edx + cpu->eax, cpu->ebp & 0xFFFFu);
    cpu->eax = lift_load16(cpu->esi + 0xEAB2u);
    cpu->ecx = lift_load32(cpu->esi + 0xEAA0u);
    cpu->edx = lift_load32(cpu->esi + 0xEA9Cu);
    lift_store16(cpu->ecx + cpu->edx + 4u, cpu->eax & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 0xEAA0u);
    cpu->edx = lift_load32(cpu->esi + 0xEA9Cu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x2Cu)) & 0xFFFFu);
    lift_store16(cpu->ecx + cpu->edx + 6u, cpu->eax & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->edx = lift_load32(cpu->esi + 0xEAA0u);
    cpu->eax = lift_load32(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x418CBEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418CC3u);
    cpu->eax = 4u;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00018CFF;
    cpu->ecx = lift_load32(cpu->esi + 0xEA9Cu);
    cpu->edx = lift_load32(cpu->esi + 0xEAA0u);
    cpu->edx += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x28u)) & 0xFFFFu);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00018CF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x418CF0u);
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(((int8_t)(lift_load8(cpu->edx + cpu->eax)))) & 0xFFFFu);
    ++cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00018CF0;
    goto label_00018D04;
    label_00018CFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x418CFFu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x28u)) & 0xFFFFu);
    label_00018D04: cpu->eip = LIFT_CODE_TOKEN_VA(0x418D04u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0xEAB4u)) & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0xEAA0u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) ^ (uint64_t)((cpu->ecx & 0xFFFFu)))) & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 0xEA9Cu);
    lift_store16(cpu->eax + cpu->ecx + 2u, cpu->edx & 0xFFFFu);
    lift_store32(cpu->esi + 0xEAA0u, (uint64_t)(lift_load32(cpu->esi + 0xEAA0u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0xEAB8u, (uint64_t)(lift_load32(cpu->esi + 0xEAB8u)) + 1u);
    label_00018D2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x418D2Bu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418D30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418D36u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418D50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418D85u); lift_push32(cpu, r); sfera_sub_00418A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, 0x3Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418D97u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418DA6u); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x418DD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x220u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x234u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x244u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, 0x2710u);
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x418E20u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418E26u);
    lift_push32(cpu, 0x54u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    cpu->ecx = 0xEA60u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418E3Bu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xEA88u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x16u, 1u);
    lift_store8(cpu->esp + 0x17u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001918D;
    label_00018E58: cpu->eip = LIFT_CODE_TOKEN_VA(0x418E58u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) != (uint8_t)(0u)) goto label_00018E68;
    lift_push32(cpu, 0xAu);
    goto label_0001910A;
    label_00018E68: cpu->eip = LIFT_CODE_TOKEN_VA(0x418E68u);
    cpu->edi = 0xEA60u;
    cpu->edi -= cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(1u)) goto label_00018E9B;
    if ((uint8_t)(lift_load8(cpu->esp + 0x16u)) != (uint8_t)(1u)) goto label_00018F30;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: local rcv buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418E8Eu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_store8(cpu->esp + 0x16u, 0u);
    goto label_00018F30;
    label_00018E9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x418E9Bu);
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    lift_store8(cpu->esp + 0x2Au, 1u);
    lift_store32(cpu->esp + 0x144u, cpu->eax);
    lift_store32(cpu->esp + 0x140u, 1u);
    lift_native_call(cpu, native_function_address32(&::select), LIFT_CODE_TOKEN_VA(0x418ECBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418ED0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0001911F;
    cpu->ecx = lift_load32(cpu->esi + 0xEA68u);
    cpu->eax = (uint32_t)(cpu->esp + 0x12Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x418EE8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418EEDu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018F30;
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ebx + cpu->ebp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::recv), LIFT_CODE_TOKEN_VA(0x418EFFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418F04u);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x418F06u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418F0Bu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00019139;
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00019155;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00018F30;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esi + 0xEA8Cu, (uint64_t)(lift_load32(cpu->esi + 0xEA8Cu)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    label_00018F26: cpu->eip = LIFT_CODE_TOKEN_VA(0x418F26u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00018F30: cpu->eip = LIFT_CODE_TOKEN_VA(0x418F30u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(2u)) goto label_000190D9;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp)) & 0xFFFFu);
    lift_store32(cpu->esp + 0x18u, 0u);
    lift_store16(cpu->esp + 0x18u, cpu->ecx & 0xFFFFu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->edi)) goto label_000190D9;
    cpu->eax = lift_load16(cpu->ebp + 2u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x64u)) goto label_00019171;
    cpu->edx = 0xC8u;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00018FDB;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp + 8u)) & 0xFFFFu);
    cpu->ebx = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"Create connection: socket=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store16(cpu->esi + 0xEAB4u, cpu->eax & 0xFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418F8Cu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_directplay_runtime.transport.mode;
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x190u);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418FACu); lift_push32(cpu, r); sfera_sub_00418BB0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_network_runtime.initialization_result = (uint32_t)(1u);
    lift_store32(cpu->esi + 0xEA6Cu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x418FBCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418FC2u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0x3E8u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->edx;
    lift_store16(cpu->esi + 0xEAB2u, cpu->edx & 0xFFFFu);
    goto label_00019088;
    label_00018FDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x418FDBu);
    cpu->edx = 0x1F4u;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != (uint16_t)((cpu->edx & 0xFFFFu))) goto label_0001902B;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418FEAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418FF0u);
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x418FF0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418FF6u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0xEAACu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0001900C;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0001900C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41900Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (3.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419017u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xEAA8u, cpu->eax);
    lift_store8(cpu->esi + 0xEAB0u, 1u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    goto label_00019082;
    label_0001902B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41902Bu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x419038u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41903Eu);
    cpu->ecx = lift_load32(cpu->esi + 0xEA60u);
    cpu->eax = 0xEA60u;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x23Cu, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_000190A5;
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0x23u, 1u);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x419064u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419069u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0xEA60u, (uint64_t)(lift_load32(cpu->esi + 0xEA60u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x23Cu, 0xFFFFFFFFu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    label_00019082: cpu->eip = LIFT_CODE_TOKEN_VA(0x419082u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0x19082u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x19088u);
    label_00019088: cpu->eip = LIFT_CODE_TOKEN_VA(0x419088u);
    cpu->eax = 0xEA60u;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->ebp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x419095u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41909Bu);
    cpu->esp += 0xCu;
    cpu->ebx -= cpu->edi;
    goto label_00018F26;
    label_000190A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4190A5u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) != (uint8_t)(1u)) goto label_000190C3;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: rcv buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4190BBu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_store8(cpu->esp + 0x17u, 0u);
    label_000190C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4190C3u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_store32(cpu->esp + 0x240u, 0xFFFFFFFFu);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0x190D3u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x190D9u);
    label_000190D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4190D9u);
    cpu->edi = native_function_address32(&::GetTickCount);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x190E1u), LIFT_CODE_TOKEN_RVA(0x190DFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4190E1u);
    cpu->eax -= lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3E8u)) goto label_00019108;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x190EEu), LIFT_CODE_TOKEN_RVA(0x190ECu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4190EEu);
    cpu->edx = lift_load32(cpu->esi + 0xEA8Cu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0xEA98u, cpu->edx);
    lift_store32(cpu->esi + 0xEA8Cu, 0u);
    label_00019108: cpu->eip = LIFT_CODE_TOKEN_VA(0x419108u);
    lift_push32(cpu, 0xFu);
    label_0001910A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41910Au);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x41910Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419110u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) != (uint8_t)(1u)) goto label_00018E58;
    goto label_0001918D;
    label_0001911F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41911Fu);
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41911Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419124u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------ERROR: select, err=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419134u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    goto label_00019183;
    label_00019139: cpu->eip = LIFT_CODE_TOKEN_VA(0x419139u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------LOST CONNECTION, err=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store8(cpu->esi + 0xEAA5u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419150u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    goto label_00019183;
    label_00019155: cpu->eip = LIFT_CODE_TOKEN_VA(0x419155u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------CLOSE CONNECTION, err=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store8(cpu->esi + 0xEAA5u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41916Cu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    goto label_00019183;
    label_00019171: cpu->eip = LIFT_CODE_TOKEN_VA(0x419171u);
    lift_push32(cpu, (uintptr_t)"-------------------------IN(ERROR): (limit connections)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419180u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00019183: cpu->eip = LIFT_CODE_TOKEN_VA(0x419183u);
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    label_0001918D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41918Du);
    lift_push32(cpu, (uintptr_t)"Rcv Thread exit\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41919Cu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = 0u;
    lift_push32(cpu, 0x120u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0xEA94u, cpu->edi);
    lift_store32(cpu->esi + 0xEA98u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4191BEu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000191DD;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000191DD;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x4191D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4191DDu);
    label_000191DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4191DDu);
    lift_store32(cpu->esi + 0xEA68u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4191E3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4191E8u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x234u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x22Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419220u);
    cpu->esp -= 0x110u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetTickCount);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19231u), LIFT_CODE_TOKEN_RVA(0x1922Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419231u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19237u), LIFT_CODE_TOKEN_RVA(0x19235u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419237u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1923Du), LIFT_CODE_TOKEN_RVA(0x1923Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41923Du);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19243u), LIFT_CODE_TOKEN_RVA(0x19241u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419243u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x419247u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41924Du);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0x1388u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->esi = lift_load32(cpu->esp + 0x120u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xEA88u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = (uint32_t)(cpu->edx + 0x7D0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000193BE;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::EnterCriticalSection);
    label_00019276: cpu->eip = LIFT_CODE_TOKEN_VA(0x419276u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) != (uint8_t)(0u)) goto label_00019286;
    lift_push32(cpu, 0xAu);
    goto label_000193AA;
    label_00019286: cpu->eip = LIFT_CODE_TOKEN_VA(0x419286u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19288u), LIFT_CODE_TOKEN_RVA(0x19286u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419288u);
    cpu->eax -= lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3E8u)) goto label_000192C1;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19295u), LIFT_CODE_TOKEN_RVA(0x19293u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419295u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x192A0u), LIFT_CODE_TOKEN_RVA(0x1929Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4192A0u);
    cpu->edx = lift_load32(cpu->esi + 0xEA90u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_store32(cpu->esi + 0xEA94u, cpu->edx);
    lift_store32(cpu->esi + 0xEA90u, 0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0x192BBu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x192C1u);
    label_000192C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4192C1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x192C3u), LIFT_CODE_TOKEN_RVA(0x192C1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4192C3u);
    cpu->eax -= lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0xFu)) goto label_00019306;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x192CEu), LIFT_CODE_TOKEN_RVA(0x192CCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4192CEu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4192D9u); lift_push32(cpu, r); sfera_sub_00418B20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0xC350u;
    if ((uint16_t)(lift_load16(cpu->esi + 0xEAB2u)) <= (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00019306;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = 1u;
    lift_push32(cpu, 0x258u);
    lift_store16(cpu->esi + 0xEAB2u, cpu->ecx & 0xFFFFu);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x19306u); lift_push32(cpu, r); sfera_sub_00418BB0(cpu,r); if (cpu->eip != r) return; }
    label_00019306: cpu->eip = LIFT_CODE_TOKEN_VA(0x419306u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19308u), LIFT_CODE_TOKEN_RVA(0x19306u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419308u);
    cpu->eax -= lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0xBB8u)) goto label_00019367;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19315u), LIFT_CODE_TOKEN_RVA(0x19313u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419315u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x19320u), LIFT_CODE_TOKEN_RVA(0x1931Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419320u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19322u), LIFT_CODE_TOKEN_RVA(0x19320u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419322u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xEAB0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esi + 0xEAACu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001933B;
    lift_store32(cpu->esi + 0xEAA8u, (uint64_t)(lift_load32(cpu->esi + 0xEAA8u)) + (uint64_t)(0xBB8u) + (uint64_t)(0u));
    label_0001933B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41933Bu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x419340u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419346u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x1F4u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi + 0xEAB0u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419360u); lift_push32(cpu, r); sfera_sub_00418BB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x19367u); lift_push32(cpu, r); sfera_sub_00418B20(cpu,r); if (cpu->eip != r) return; }
    label_00019367: cpu->eip = LIFT_CODE_TOKEN_VA(0x419367u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19369u), LIFT_CODE_TOKEN_RVA(0x19367u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419369u);
    cpu->eax -= lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_000193A8;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x419371u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419377u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0x2710u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ebp = (uint32_t)(cpu->edx + 0xBB8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19387u), LIFT_CODE_TOKEN_RVA(0x19385u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419387u);
    cpu->edx = lift_load32(cpu->esi + 0xEAB8u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x2BCu); lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x193A8u); lift_push32(cpu, r); sfera_sub_00418BB0(cpu,r); if (cpu->eip != r) return; }
    label_000193A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4193A8u);
    lift_push32(cpu, 4u);
    label_000193AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4193AAu);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x4193AAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4193B0u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) != (uint8_t)(1u)) goto label_00019276;
    cpu->ebx = lift_pop32(cpu);
    label_000193BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4193BEu);
    lift_push32(cpu, (uintptr_t)"Snd Thread exit\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4193CDu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x110u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004193E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4193E0u);
    cpu->esp -= 0x1A8u;
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00019410;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019716;
    label_00019410: cpu->eip = LIFT_CODE_TOKEN_VA(0x419410u);
    if ((uint8_t)(lift_load8(cpu->edi + 0xEAA4u)) != (uint8_t)(1u)) goto label_0001943B;
    cpu->eax = lift_load32(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------ERROR: ALREADY Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419431u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->eax = 0u;
    goto label_00019716;
    label_0001943B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41943Bu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1B8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419454u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x102u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x419461u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419466u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019479;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41946Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41946Fu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(1)--init connect manager (%d '%s'), error=%d\n");
    goto label_000194A3;
    label_00019479: cpu->eip = LIFT_CODE_TOKEN_VA(0x419479u);
    lift_push32(cpu, 6u); lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x41947Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419484u);
    lift_store32(cpu->edi + 0xEA68u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000194B8;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41948Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419494u);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x419496u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41949Bu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2)--init connect manager (%d '%s'), error=%d\n");
    label_000194A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4194A3u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4194ADu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019715;
    label_000194B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4194B8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s'), skt=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4194CCu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0xEA68u);
    cpu->esp += 0x14u;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, 6u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, 1u);
    lift_native_call(cpu, native_function_address32(&::setsockopt), LIFT_CODE_TOKEN_VA(0x4194E9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4194EEu);
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0001950D;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4194F4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4194F9u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2_1)--init connect manager (%d), error=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41950Au); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0001950D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41950Du);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') - no delay res = %d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41951Fu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    cpu->ecx = 2u;
    lift_push32(cpu, cpu->ebp);
    lift_store16(cpu->esp + 0x18u, cpu->ecx & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x41952Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419532u);
    lift_push32(cpu, cpu->esi);
    lift_store16(cpu->esp + 0x1Au, cpu->eax & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419538u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41953Du);
    lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0001955E;
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419543u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419548u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x41954Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419552u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(1) (%d '%s'), skt=%d, adr='%s'\n");
    goto label_00019586;
    label_0001955E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41955Eu);
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x41955Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419563u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000196E4;
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x419577u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41957Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(2) (%d '%s'), skt=%d, adr='%s'\n");
    label_00019586: cpu->eip = LIFT_CODE_TOKEN_VA(0x419586u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419590u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0xEA68u);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::connect), LIFT_CODE_TOKEN_VA(0x4195A1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4195A6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000195FB;
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x4195AAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4195B0u);
    cpu->edi = lift_load32(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4195B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4195B7u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_1)--init connect manager (%d '%s') \n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4195CAu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_2)--init connect manager (%d '%s'), errno=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4195DCu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_3)--init connect manager (%d '%s'), lastError=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4195EEu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x38u;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4195F1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4195F6u);
    goto label_00019711;
    label_000195FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4195FBu);
    cpu->eax = (uint32_t)(cpu->edi + 0xEA74u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00418DD0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_store8(cpu->edi + 0xEA88u, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x419615u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41961Bu);
    lift_store32(cpu->edi + 0xEA70u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00019638;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419625u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41962Bu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(5)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019638: cpu->eip = LIFT_CODE_TOKEN_VA(0x419638u);
    cpu->ebx = native_function_address32(&::SetThreadPriority);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x19643u), LIFT_CODE_TOKEN_RVA(0x19641u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419643u);
    cpu->ecx = (uint32_t)(cpu->edi + 0xEA7Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00419220)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x419656u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41965Cu);
    lift_store32(cpu->edi + 0xEA78u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00019679;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419666u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41966Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(6)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019679: cpu->eip = LIFT_CODE_TOKEN_VA(0x419679u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x1967Eu), LIFT_CODE_TOKEN_RVA(0x1967Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41967Eu);
    cpu->edx = (uint32_t)(cpu->edi + 0xEA84u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004189B0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x419691u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419697u);
    lift_store32(cpu->edi + 0xEA80u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000196B1;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4196A1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4196A7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(7)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_000196B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4196B1u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x196B6u), LIFT_CODE_TOKEN_RVA(0x196B4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4196B6u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x4196BBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4196C0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(3) (%d '%s'), skt=%d, adr='%s'\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4196D4u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_store16(cpu->edi + 0xEAA4u, 0x101u);
    cpu->eax = 0u;
    goto label_00019714;
    label_000196E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4196E4u);
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4196E4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4196E9u);
    cpu->ecx = lift_load32(cpu->edi + 0xEA68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x4196F2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4196F7u);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4196F7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4196FCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(3)--init connect manager (%d '%s'), error=%d\n");
    label_00019704: cpu->eip = LIFT_CODE_TOKEN_VA(0x419704u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41970Eu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_00019711: cpu->eip = LIFT_CODE_TOKEN_VA(0x419711u);
    cpu->eax |= 0xFFFFFFFFu;
    label_00019714: cpu->eip = LIFT_CODE_TOKEN_VA(0x419714u);
    cpu->ebx = lift_pop32(cpu);
    label_00019715: cpu->eip = LIFT_CODE_TOKEN_VA(0x419715u);
    cpu->ebp = lift_pop32(cpu);
    label_00019716: cpu->eip = LIFT_CODE_TOKEN_VA(0x419716u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1A8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419730u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    (void)cpu;
    label_00019740: cpu->eip = LIFT_CODE_TOKEN_VA(0x419740u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    cpu->edi = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x1974Bu), LIFT_CODE_TOKEN_RVA(0x19749u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41974Bu);
    cpu->eax = lift_load32(cpu->esi + 0xEA60u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(2u)) goto label_0001975F;
    cpu->edi = lift_load16(cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edi)) goto label_0001975F;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_0001975F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41975Fu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x419764u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41976Au);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_000197F9;
    cpu->eax = 0x12Cu;
    if ((uint16_t)(lift_load16(cpu->esi + 2u)) != (uint16_t)((cpu->eax & 0xFFFFu))) goto label_000197C6;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = lift_load16(cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->eax -= 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0xFFFF0011u;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x197C6u); lift_push32(cpu, r); sfera_sub_00433400(cpu,r); if (cpu->eip != r) return; }
    label_000197C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4197C6u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x197CDu), LIFT_CODE_TOKEN_RVA(0x197CBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4197CDu);
    cpu->edx = 0xEA60u;
    cpu->edx -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4197DAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4197E0u);
    lift_store32(cpu->esi + 0xEA60u, (uint64_t)(lift_load32(cpu->esi + 0xEA60u)) - (uint64_t)(cpu->edi) - (uint64_t)(0u));
    cpu->esp += 0xCu;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4197EEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4197F4u);
    goto label_00019740;
    label_000197F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4197F9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419810u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xEA60u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41981Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419820u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0xEA60u, 0u);
    lift_store32(cpu->esi + 0xEA64u, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419840u);
    cpu->esp -= 0x18u;
    cpu->eax = lift_load32((uintptr_t)"0123456789ABCDEF");
    lift_store32(cpu->esp, cpu->eax);
    cpu->eax = lift_load32(((uint32_t)(uintptr_t)"0123456789ABCDEF") + 4u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = lift_load32(((uint32_t)(uintptr_t)"0123456789ABCDEF") + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = lift_load32(((uint32_t)(uintptr_t)"0123456789ABCDEF") + 0xCu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"0123456789ABCDEF") + 0x10u)) & 0xFFu);
    cpu->esi += cpu->ecx;
    lift_store8(cpu->esp + 0x14u, cpu->eax & 0xFFu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000198E6;
    label_00019885: cpu->eip = LIFT_CODE_TOKEN_VA(0x419885u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_0001988F;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_000198DE;
    label_0001988F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41988Fu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_00019897;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_000198DE;
    label_00019897: cpu->eip = LIFT_CODE_TOKEN_VA(0x419897u);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_0001989F;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_000198DE;
    label_0001989F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41989Fu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_000198DE;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x5Fu)) goto label_000198DE;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_000198DE;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x7Eu)) goto label_000198DE;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000198FC;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00019901;
    lift_store8(cpu->ecx, 0x25u);
    cpu->eax = lift_load8(cpu->edx);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax = lift_load8(cpu->esp + cpu->eax + 4u);
    lift_store8(cpu->ecx + 1u, cpu->eax & 0xFFu);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    cpu->eax &= 0xFu;
    cpu->eax = lift_load8(cpu->esp + cpu->eax + 4u);
    lift_store8(cpu->ecx + 2u, cpu->eax & 0xFFu);
    cpu->ecx += 3u;
    goto label_000198E1;
    label_000198DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4198DEu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    label_000198E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4198E1u);
    ++cpu->edx;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->esi)) goto label_00019885;
    label_000198E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4198E6u);
    lift_store8(cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
    label_000198FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4198FCu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    label_00019901: cpu->eip = LIFT_CODE_TOKEN_VA(0x419901u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000198E6;
    lift_store8(cpu->ecx, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419920u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edx + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_push32(cpu, 0x1Fu);
    cpu->edx = (uint32_t)(uintptr_t)"BaseCache.cpp";
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419952u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0001997D;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00019960: cpu->eip = LIFT_CODE_TOKEN_VA(0x419960u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    ++cpu->eax;
    lift_store32(cpu->ecx + cpu->edx, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00019960;
    label_0001997D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41997Du);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419990u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + 1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00019A35;
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ebp = (uint32_t)(cpu->eax + 4u);
    label_000199C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4199C4u);
    if ((uint32_t)(lift_load32(cpu->edx)) == (uint32_t)(0u)) goto label_00019A23;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = cpu->ebp;
    if ((uint32_t)(cpu->eax) < (uint32_t)(4u)) goto label_000199EB;
    label_000199D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4199D7u);
    cpu->ebx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00019A1F;
    cpu->eax -= 4u;
    cpu->ecx += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000199D7;
    label_000199EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4199EBu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019AB8;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi))) goto label_00019A1F;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_00019AB8;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi + 1u))) goto label_00019A1F;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(2u)) goto label_00019AB8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 2u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(lift_load8(cpu->edi + 2u))) goto label_00019AB8;
    label_00019A1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x419A1Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_00019A23: cpu->eip = LIFT_CODE_TOKEN_VA(0x419A23u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->edx += cpu->ecx;
    cpu->ebp += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000199C4;
    label_00019A35: cpu->eip = LIFT_CODE_TOKEN_VA(0x419A35u);
    cpu->edi = 0u;
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00019A6A;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->ebx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 4u);
    cpu->eax = cpu->edx;
    label_00019A54: cpu->eip = LIFT_CODE_TOKEN_VA(0x419A54u);
    cpu->ebp = lift_load32(cpu->eax + cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + cpu->ebx))) goto label_00019A62;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->edi = cpu->eax;
    label_00019A62: cpu->eip = LIFT_CODE_TOKEN_VA(0x419A62u);
    ++cpu->ecx;
    cpu->eax += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00019A54;
    label_00019A6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x419A6Au);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->edx + 4u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x10u));
    cpu->edi += lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->edi, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x419A8Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419A93u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->edx);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->edi + cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x19AA7u), LIFT_CODE_TOKEN_RVA(0x19AA5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419AA7u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_00019AB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x419AB8u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 4u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419AD0u);
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->ecx);
    lift_store32(cpu->esp, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00019BA3;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_00019AF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x419AF5u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00019B8D;
    (void)cpu;
    label_00019B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x419B00u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x19B02u), LIFT_CODE_TOKEN_RVA(0x19B00u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419B02u);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xFFu);
    cpu->eax = 0x80010003u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(0xEu), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebx = cpu->eax & 0xFFu;
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(8u), 32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x19B25u), LIFT_CODE_TOKEN_RVA(0x19B23u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419B25u);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xFFu);
    cpu->eax = 0x80010003u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(0xEu), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    cpu->esi = cpu->ecx & 0xFFu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x19B4Au), LIFT_CODE_TOKEN_RVA(0x19B48u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419B4Au);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xFFu);
    cpu->eax = 0x80010003u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(0xEu), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax & 0xFFu;
    cpu->ecx |= cpu->esi;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetPixel), LIFT_CODE_TOKEN_VA(0x419B79u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419B7Fu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->eax)) goto label_00019B00;
    cpu->ecx = cpu->esi;
    label_00019B8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x419B8Du);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00019AF5;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00019BA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x419BA3u);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419BB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x419BBBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419BC1u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_VA(0x419BC5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419BCBu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_VA(0x419BCFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419BD5u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx + 4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x19BDEu), LIFT_CODE_TOKEN_RVA(0x19BDCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419BDEu);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00499F50(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419BF0u);
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x1Fu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = cpu->edx;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->eax = 1u;
    lift_store16(cpu->esp + 0x1Cu, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, 0x800u);
    cpu->eax = 0x20u;
    lift_store32(cpu->esp + 0x14u, 0x28u);
    lift_store16(cpu->esp + 0x22u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esp + 0x24u, 0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x19C91u), LIFT_CODE_TOKEN_RVA(0x19C8Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419C91u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x19CA5u), LIFT_CODE_TOKEN_RVA(0x19CA3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419CA5u);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00019CEE;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) != (uint32_t)(cpu->eax)) goto label_00019CEE;
    if ((uint32_t)(lift_load32(cpu->esp + 0x54u)) != (uint32_t)(cpu->eax)) goto label_00019CEE;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00019CED;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::GetDIBits);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00019CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x419CD0u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x19CE5u), LIFT_CODE_TOKEN_RVA(0x19CE3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419CE5u);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00019CD0;
    cpu->ebp = lift_pop32(cpu);
    label_00019CED: cpu->eip = LIFT_CODE_TOKEN_VA(0x419CEDu);
    cpu->ebx = lift_pop32(cpu);
    label_00019CEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x419CEEu);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x50u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x19CFDu), LIFT_CODE_TOKEN_RVA(0x19CFBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419CFDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419D10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->eax = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x400u)) goto label_00019D52;
    cpu->eax = 0x400u;
    label_00019D52: cpu->eip = LIFT_CODE_TOKEN_VA(0x419D52u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x400u)) goto label_00019D66;
    cpu->edx = 0x400u;
    label_00019D66: cpu->eip = LIFT_CODE_TOKEN_VA(0x419D66u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi, cpu->ebx);
    lift_store8(cpu->ebp + 0xBu, cpu->ebx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->eax)) goto label_00019D7C;
    cpu->ecx = cpu->eax;
    label_00019D7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x419D7Cu);
    cpu->eax = 0x20u;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00019D93;
    label_00019D88: cpu->eip = LIFT_CODE_TOKEN_VA(0x419D88u);
    cpu->eax += cpu->eax;
    cpu->edx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00019D88;
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    label_00019D93: cpu->eip = LIFT_CODE_TOKEN_VA(0x419D93u);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetDC), LIFT_CODE_TOKEN_VA(0x419D97u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419D9Du);
    cpu->edi = cpu->eax;
    lift_store32(cpu->ebp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_00019DB9;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFFEFu, cpu->eax & 0xFFu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFEFu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x19DB9u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_00019DB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x419DB9u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleDC), LIFT_CODE_TOKEN_VA(0x419DBAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419DC0u);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00019DDA;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFEEu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->ebp + 0xFFFFFFEEu, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x19DDAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_00019DDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x419DDAu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleBitmap), LIFT_CODE_TOKEN_VA(0x419DE3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419DE9u);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00019E03;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFEDu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->ebp + 0xFFFFFFEDu, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x19E03u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_00019E03: cpu->eip = LIFT_CODE_TOKEN_VA(0x419E03u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_VA(0x419E05u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419E0Bu);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->ebp + 0xCu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419E1Du); lift_push32(cpu, r); sfera_sub_00499EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 1u;
    cpu->edx = (uint32_t)(cpu->ebx + 0x4Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"Bitmap.cpp";
    lift_store8(cpu->ebp + 0xBu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419E32u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419E39u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019E5E;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x16u); lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419E5Cu); lift_push32(cpu, r); sfera_sub_004DA880(cpu,r); if (cpu->eip != r) return; }
    goto label_00019E60;
    label_00019E5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x419E5Eu);
    cpu->eax = 0u;
    label_00019E60: cpu->eip = LIFT_CODE_TOKEN_VA(0x419E60u);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 0u);
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00019E7D;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ebp + 0xFFFFFFECu, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x19E7Du); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_00019E7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x419E7Du);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x419E85u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x419E8Bu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419E95u); lift_push32(cpu, r); sfera_sub_00419AD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419E9Cu); lift_push32(cpu, r); sfera_sub_00419BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419EB0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419EB0u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019EC0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_RVA(0x19EBAu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x19EC0u);
    label_00019EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x419EC0u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019ED1;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_RVA(0x19ECBu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x19ED1u);
    label_00019ED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x419ED1u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019EDF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_RVA(0x19ED9u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x19EDFu);
    label_00019EDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x419EDFu);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_00019F09;
    cpu->edx = 0x62u;
    cpu->ecx = (uint32_t)(uintptr_t)"Bitmap.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419EF3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00019F09;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419F00u); lift_push32(cpu, r); sfera_sub_004DA4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419F06u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00019F09: cpu->eip = LIFT_CODE_TOKEN_VA(0x419F09u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xBu)) == (uint8_t)(0u)) goto label_00019F1E;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x19F1Eu); lift_push32(cpu, r); sfera_sub_00499F50(cpu,r); if (cpu->eip != r) return; }
    label_00019F1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x419F1Eu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419F27u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x419F27u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419F30u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419F44u); lift_push32(cpu, r); sfera_sub_00419D10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419F50u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x419F66u); lift_push32(cpu, r); sfera_sub_00419D10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x419F70u);
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
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x1Cu))));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x20u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x2Cu))));
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A010u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0x24u))));
    lift_store_f32(cpu->ecx + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0x18u))));
    lift_store_f32(cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0x28u))));
    lift_store_f32(cpu->ecx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A070u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A080u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A090u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001A0A6;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 12u, stop_address); return;
    label_0001A0A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A0A6u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A0B0u);
    cpu->eax = g_sfera_blood_effect_instance;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A0C0u);
    cpu->esp -= 0x5Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x12848u)), r=(uint64_t)(0x1Eu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0001A54B;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    cpu->ecx = 0u;
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    label_0001A0E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A0E1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A104;
    ++cpu->ecx;
    cpu->edx += 0x9E0u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x1Eu)) goto label_0001A0E1;
    cpu->ebx = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    lift_return(cpu, 12u, stop_address); return;
    label_0001A104: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A104u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9E0u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->esi + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->ebp);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0001A549;
    lift_x87_push(cpu, 1.0);
    cpu->esi = lift_load32(cpu->esp + 0x74u);
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(0x1Eu)) goto label_0001A130;
    cpu->esi = 0x1Eu;
    label_0001A130: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A130u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x40u);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41A139u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41A13Eu);
    cpu->edi = native_function_address32(&::rand);
    cpu->esp += 0xCu;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1A149u), LIFT_CODE_TOKEN_RVA(0x1A147u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A149u);
    lift_store32(cpu->esp + 0x78u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x78u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A16Eu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x20u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A17Bu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1A18Bu), LIFT_CODE_TOKEN_RVA(0x1A189u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A18Bu);
    lift_store32(cpu->esp + 0x78u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x78u)))));
    cpu->eax = lift_load32(cpu->esp + 0x70u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_push(cpu, 2.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.0));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->esi = 0u;
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.5);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001A48A;
    cpu->ecx = lift_load32(cpu->esp + 0x74u);
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFCu);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->ecx += 0xCu;
    ++cpu->edx;
    cpu->esi = (uint32_t)(((uint32_t)(cpu->edx) * 4u));
    label_0001A274: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A274u);
    cpu->ebp = lift_load32(cpu->ecx + 0xFFFFFFF4u);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->ecx + 0xFFFFFFF8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    cpu->ebp = lift_load32(cpu->ecx + 0xFFFFFFFCu);
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_store32(cpu->eax + 0x10u, cpu->ebx);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ebp = lift_load32(cpu->ecx + 4u);
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    cpu->ebp = lift_load32(cpu->ecx + 8u);
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->eax + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store32(cpu->eax + 0x2Cu, cpu->ebx);
    lift_store_f32(cpu->eax + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->ecx + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    cpu->ebp = lift_load32(cpu->ecx + 0x14u);
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->eax + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_store_f32(cpu->eax + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store32(cpu->eax + 0x48u, cpu->ebx);
    lift_store_f32(cpu->eax + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->ecx + 0x18u);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ebp = lift_load32(cpu->ecx + 0x1Cu);
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    cpu->ebp = lift_load32(cpu->ecx + 0x20u);
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_store_f32(cpu->eax + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1Cu));
    lift_store_f32(cpu->eax + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x20u));
    lift_store32(cpu->eax + 0x64u, cpu->ebx);
    lift_store_f32(cpu->eax + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    cpu->eax += 0x70u;
    cpu->ecx += 0x30u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_store_f32(cpu->eax + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001A274;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    label_0001A48A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A48Au);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0001A531;
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = cpu->edi;
    cpu->eax += 8u;
    cpu->edx -= cpu->esi;
    label_0001A4A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A4A3u);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += 0x1Cu;
    cpu->ecx += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_store_f32(cpu->eax + 0xFFFFFFDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    lift_store_f32(cpu->eax + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_store32(cpu->eax + 0xFFFFFFECu, cpu->ebx);
    lift_store_f32(cpu->eax + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001A4A3;
    label_0001A531: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A531u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp + 4u, cpu->edi);
    lift_store32(cpu->eax + 0x12848u, (uint64_t)(lift_load32(cpu->eax + 0x12848u)) + 1u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001A549: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A549u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001A54B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A54Bu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A560u);
    cpu->esp -= 0x5Cu;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x12848u)) != (uint32_t)(cpu->ebp)) goto label_0001A595;
    lift_store_f32(cpu->esi + 0x1284Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0001A595: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A595u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x9ECu);
    cpu->edi = 5u;
    cpu->edx |= 0xFFFFFFFFu;
    label_0001A5A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A5A4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFF61Cu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A5EA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFF61Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x1284Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0xFFFFF61Cu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001A5EA;
    lift_store_f32(cpu->ecx + 0xFFFFF61Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ecx + 0xFFFFF620u, cpu->ebp);
    lift_store32(cpu->esi + 0x12848u, (uint64_t)(lift_load32(cpu->esi + 0x12848u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_0001A5EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A5EAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A620;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x1284Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001A620;
    lift_store_f32(cpu->ecx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ecx, cpu->ebp);
    lift_store32(cpu->esi + 0x12848u, (uint64_t)(lift_load32(cpu->esi + 0x12848u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_0001A620: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A620u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x9DCu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A666;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x9DCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x1284Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0x9DCu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001A666;
    lift_store_f32(cpu->ecx + 0x9DCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ecx + 0x9E0u, cpu->ebp);
    lift_store32(cpu->esi + 0x12848u, (uint64_t)(lift_load32(cpu->esi + 0x12848u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_0001A666: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A666u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x13BCu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A6AC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x13BCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x1284Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0x13BCu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001A6AC;
    lift_store_f32(cpu->ecx + 0x13BCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ecx + 0x13C0u, cpu->ebp);
    lift_store32(cpu->esi + 0x12848u, (uint64_t)(lift_load32(cpu->esi + 0x12848u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_0001A6AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A6ACu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1D9Cu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A6F2;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1D9Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x1284Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0x1D9Cu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001A6F2;
    lift_store_f32(cpu->ecx + 0x1D9Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ecx + 0x1DA0u, cpu->ebp);
    lift_store32(cpu->esi + 0x12848u, (uint64_t)(lift_load32(cpu->esi + 0x12848u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_0001A6F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A6F2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x277Cu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A738;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x277Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x1284Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0x277Cu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001A738;
    lift_store_f32(cpu->ecx + 0x277Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ecx + 0x2780u, cpu->ebp);
    lift_store32(cpu->esi + 0x12848u, (uint64_t)(lift_load32(cpu->esi + 0x12848u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_0001A738: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A738u);
    cpu->ecx += 0x3B40u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001A5A4;
    lift_store_f32(cpu->esi + 0x1284Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.44999998807907104));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.3100000023841858));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[2].z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.23999999463558197));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A779u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->edi = (uint32_t)(cpu->ecx + 0x64u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Bu);
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u) + 0x1F4u);
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->ecx += cpu->ecx;
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ebx = cpu->edx;
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(0x1Fu), 32u);
    cpu->ebx += cpu->edx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x12848u)) == (uint32_t)(cpu->ebp)) goto label_0001A9DD;
    cpu->ecx = lift_load32(cpu->esi + 0x12850u);
    cpu->edx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A7D5u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x100u);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A82Eu); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A83Cu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A84Au); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A859u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A869u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A879u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0xBB8u;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A887u); lift_push32(cpu, r); sfera_sub_0044F240(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 255.0);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    cpu->esi += 0xCu;
    label_0001A898: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A898u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFFCu));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0001A93F;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ebp = lift_load32(cpu->esi);
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xBB8u)) goto label_0001A959;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFFCu));
    cpu->edi = 0u;
    lift_store16(cpu->esp + 0x16u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x16u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xC00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = lift_load8(cpu->esp + 0x24u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store64(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x16u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->ebx & 0xFFu;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->eax = cpu->ebx & 0xFFu;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->eax;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0001A93D;
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    label_0001A90B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A90Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF8u));
    ++cpu->edi;
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    cpu->eax += 0x1Cu;
    lift_store_f32(cpu->ecx + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFE4u));
    lift_store32(cpu->ecx + 0xFFFFFFF0u, cpu->edx);
    lift_store_f32(cpu->ecx + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0xFFFFFFF4u, 0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF0u));
    lift_store_f32(cpu->ecx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF4u));
    lift_store_f32(cpu->ecx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi))) goto label_0001A90B;
    label_0001A93D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A93Du);
    cpu->ebp = 0u;
    label_0001A93F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A93Fu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->esi += 0x9E0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x1Eu)) goto label_0001A898;
    goto label_0001A963;
    label_0001A959: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A959u);
    lift_store32(cpu->esp + 0x18u, 0xBB8u);
    cpu->ebp = 0u;
    label_0001A963: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A963u);
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A97Cu); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A9A5u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_04, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04)) + (uint64_t)(0xBB8u) + (uint64_t)(0u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A9BEu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41A9CDu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1A9DDu); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    label_0001A9DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41A9DDu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41A9F0u);
    cpu->esp -= 0xE0u;
    cpu->eax = g_sfera_blood_effect_instance;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x12848u)), r=(uint64_t)(0x1Eu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xF8u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0001ACD0;
    if ((uint32_t)(lift_load32(cpu->edi + 0x28u)) == (uint32_t)(1u)) goto label_0001AA3A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown classID for blood spot effect.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AA31u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AA37u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0001AA3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AA3Au);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x41AA3Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41AA40u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 3u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->esi = cpu->edx;
    cpu->edx = lift_load32(cpu->edi + 0x2Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AA6Eu); lift_push32(cpu, r); sfera_sub_00426160(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001AB70;
    cpu->edx = lift_load32(cpu->eax + 0x5Cu);
    lift_store32(cpu->esp + 0x54u, cpu->edx);
    cpu->ebp = 0u;
    cpu->edi = (uint32_t)(cpu->esp + 0x7Cu);
    goto label_0001AA9E;
    label_0001AA98: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AA98u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0001AA9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AA9Eu);
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(lift_load32(cpu->esp + 0x54u))) goto label_0001AB65;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001AB65;
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ecx + 0x28u)));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0001AB45;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_store_f32(cpu->edi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x20u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.5));
    lift_store_f32(cpu->edi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->edi + 0xFFFFFFF8u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->edi + 0xFFFFFFFCu))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->edi))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AB16u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001AB3D;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    goto label_0001AB49;
    label_0001AB3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AB3Du);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    goto label_0001AB49;
    label_0001AB45: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AB45u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001AB49: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AB49u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    ++cpu->ebx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ebp += 0x50u;
    cpu->edi += 0xCu;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->esi)) goto label_0001AB76;
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    goto label_0001AA98;
    label_0001AB65: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AB65u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0001ACD0;
    label_0001AB70: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AB70u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0001AB76: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AB76u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)-1.0f);
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_store32(cpu->esp + 0x68u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_store32(cpu->esp + 0x6Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x70u, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x84u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store32(cpu->esp + 0x88u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.5));
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.7999999523162842));
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41ACA0u); lift_push32(cpu, r); sfera_sub_0046F280(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle)) == (uint32_t)(0u)) goto label_0001ACD0;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0001ACD0;
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    label_0001ACB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ACB1u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    cpu->ecx = g_sfera_blood_effect_instance;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41ACCAu); lift_push32(cpu, r); sfera_sub_0041A0C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001ACB1;
    label_0001ACD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ACD0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041ACF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41ACF0u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store_f32(cpu->esi + 0x1284Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = 0x136u;
    std::construct_at(reinterpret_cast<BloodEffListener*>(cpu->esi));
    lift_store32(cpu->esi + 4u, 0x40u);
    lift_store32(cpu->esi + 0x12848u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AD1Eu); lift_push32(cpu, r); sfera_sub_0042AA90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"fx_bspot";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AD28u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x12840u);
    lift_store32(cpu->esi + 0x12850u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41AD39u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41AD3Eu);
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41AD50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    if ((uint32_t)(g_sfera_blood_effect_instance) == (uint32_t)(0u)) goto label_0001AD97;
    lift_push32(cpu, 0x9Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AD8Eu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AD94u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0001AD97: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AD97u);
    cpu->edx = 0x9Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41ADA6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x12854u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41ADB0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001ADDF;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41ADCAu); lift_push32(cpu, r); sfera_sub_0041ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_blood_effect_instance = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_0001ADDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41ADDFu);
    cpu->eax = 0u;
    g_sfera_blood_effect_instance = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41AE00u);
    if ((uint32_t)(g_sfera_blood_effect_instance) != (uint32_t)(0u)) goto label_0001AE26;
    lift_push32(cpu, 0xA7u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AE1Du); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AE23u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0001AE26: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AE26u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0xA8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AE36u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_blood_effect_instance;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001AE50;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AE47u); lift_push32(cpu, r); sfera_sub_00429990(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AE4Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0001AE50: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AE50u);
    g_sfera_blood_effect_instance = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41AE60u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x1Cu))));
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x20u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x2Cu))));
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AEE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41AEE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_0001AF1F;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u))) goto label_0001AF2E;
    label_0001AF1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AF1Fu);
    cpu->edx = 0x73u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1AF2Eu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001AF2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AF2Eu);
    cpu->eax = lift_load32(cpu->esi + 0x4F44u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x2Cu);
    if ((uint32_t)(lift_load32(cpu->ebx + cpu->eax + 0x24u)) != (uint32_t)(0u)) goto label_0001B197;
    cpu->edx = lift_load32(cpu->eax + cpu->ebx + 0x20u);
    cpu->eax += cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xC8u);
    lift_push32(cpu, (uintptr_t)".chr"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x120u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AF64u); lift_push32(cpu, r); sfera_sub_0047EC40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AF72u); lift_push32(cpu, r); sfera_sub_0047ED30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AF79u); lift_push32(cpu, r); sfera_sub_0045A9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AF8Du); lift_push32(cpu, r); sfera_sub_0047ED10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0x30686373u)) goto label_0001AF9F;
    cpu->ecx = (uint32_t)(uintptr_t)"preload_model: wrong file format";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1AF9Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0001AF9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AF9Fu);
    cpu->edi = lift_load32(cpu->esi + 8u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    cpu->eax += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->eax);
    cpu->ecx = 0x20u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0001AFCA;
    cpu->esi = cpu->edi;
    label_0001AFB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AFB6u);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0001AFC4;
    if ((uint32_t)(cpu->edx) == (uint32_t)(7u)) goto label_0001AFC4;
    cpu->ecx += lift_load32(cpu->eax + 8u);
    label_0001AFC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AFC4u);
    cpu->eax += 0xCu;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001AFB6;
    label_0001AFCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41AFCAu);
    lift_push32(cpu, 0x83u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41AFD9u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = lift_load32(cpu->ecx + 0x4F44u);
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    lift_store32(cpu->ebx + cpu->edx + 0x24u, cpu->esi);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    cpu->ebx = (uint32_t)(cpu->esi + 0x20u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0001B079;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    label_0001B011: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B011u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001B035;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(7u)) goto label_0001B035;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax += lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41B02Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41B02Fu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp += 0xCu;
    label_0001B035: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B035u);
    cpu->ecx = lift_load32(cpu->eax);
    --cpu->ecx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(6u)) goto label_0001B06C;
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: goto label_0001B044;
        case 1u: goto label_0001B0D7;
        case 2u: case 3u: case 4u: goto label_0001B06C;
        case 5u: goto label_0001B0DF;
        case 6u: goto label_0001B0F6;
        default: lift_trap(cpu, 0x41B03Du, "resolved jump-table index out of range"); return;
    }
label_0001B044: ;
    cpu->edx = 0u;
    cpu->eax = cpu->edi;
    cpu->ecx = 0x28u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0001B069;
    cpu->edx = (uint32_t)(cpu->ecx + 0x6Fu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1B069u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001B069: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B069u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    label_0001B06C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B06Cu);
    cpu->eax += 0xCu;
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE8u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xFFFFFFE8u, v); }
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001B011;
    label_0001B079: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B079u);
    cpu->ebx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->edi = lift_load32(cpu->ebx);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->edi);
    cpu->ebx += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B08Cu); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0001B132;
    label_0001B09E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B09Eu);
    cpu->edx = (int8_t)(lift_load8(cpu->ebx));
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edi = 0u;
    ++cpu->ebx;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->edx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0001B10E;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    label_0001B0B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B0B1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->edx += lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41B0BCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41B0C2u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001B104;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE8u)) + (uint64_t)(0x1Eu) + (uint64_t)(0u));
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->eax))) goto label_0001B0B1;
    goto label_0001B10E;
    label_0001B0D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B0D7u);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    goto label_0001B06C;
    label_0001B0DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B0DFu);
    lift_store32(cpu->esi, cpu->ebx);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    cpu->edx += cpu->ebx;
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    goto label_0001B06C;
    label_0001B0F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B0F6u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx += lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ecx);
    goto label_0001B06C;
    label_0001B104: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B104u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u), cpu->edi & 0xFFFFu);
    label_0001B10E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B10Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0001B11F;
    cpu->ecx = (uint32_t)(uintptr_t)"Match for bone name not found";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1B11Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0001B11F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B11Fu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ebx += lift_load32(cpu->ebp + 0xFFFFFFDCu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE0u))) goto label_0001B09E;
    label_0001B132: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B132u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001B18D;
    cpu->ebx += 0x20u;
    label_0001B145: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B145u);
    cpu->edi = lift_load32(cpu->ebx);
    cpu->eax = lift_load8(cpu->ebx + 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->edi &= 0xFFu;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0001B15F;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001B16C;
    label_0001B15F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B15Fu);
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 759476206789";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B169u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    label_0001B16C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B16Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store32(cpu->ebx, cpu->edx);
    ++cpu->eax;
    cpu->ebx += 0x28u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1Cu))) goto label_0001B145;
    label_0001B18D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B18Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_RVA(0x1B191u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x1B197u);
    label_0001B197: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B197u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B1E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41B1E0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001B24F;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    label_0001B1F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B1F4u);
    cpu->eax = lift_load32(cpu->esi + 0x4F44u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax + 0x24u)) == (uint32_t)(cpu->ebp)) goto label_0001B242;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0001B20C;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u))) goto label_0001B21B;
    label_0001B20C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B20Cu);
    cpu->edx = 0xFFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1B21Bu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001B21B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B21Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x4F44u);
    cpu->ecx = lift_load32(cpu->edi + cpu->ecx + 0x24u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B242;
    lift_push32(cpu, 0x100u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B238u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x4F44u);
    lift_store32(cpu->edi + cpu->edx + 0x24u, cpu->ebp);
    label_0001B242: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B242u);
    ++cpu->ebx;
    cpu->edi += 0x2Cu;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u))) goto label_0001B1F4;
    cpu->edi = lift_pop32(cpu);
    label_0001B24F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B24Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x4F44u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B26E;
    lift_push32(cpu, 0x189u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B268u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x4F44u, cpu->ebp);
    label_0001B26E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B26Eu);
    cpu->ecx = lift_load32(cpu->esi + 0xB0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B28D;
    lift_push32(cpu, 0x18Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B287u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xB0u, cpu->ebp);
    label_0001B28D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B28Du);
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B2AC;
    lift_push32(cpu, 0x18Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B2A6u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xECu, cpu->ebp);
    label_0001B2AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B2ACu);
    cpu->ecx = lift_load32(cpu->esi + 0x4F4Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B2CB;
    lift_push32(cpu, 0x18Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B2C5u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x4F4Cu, cpu->ebp);
    label_0001B2CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B2CBu);
    cpu->ecx = lift_load32(cpu->esi + 0x4F50u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B2EA;
    lift_push32(cpu, 0x18Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B2E4u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x4F50u, cpu->ebp);
    label_0001B2EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B2EAu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B2F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41B2F0u);
    cpu->esp -= 0x54u;
    cpu->eax = lift_load32(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebp);
    cpu->eax += cpu->ebx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixRotationQuaternion), LIFT_CODE_TOKEN_VA(0x41B33Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41B343u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = cpu->ebx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(6u), 32u);
    cpu->eax += cpu->edx;
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41B372u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41B377u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0001B3A3;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0001B380: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B380u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(cpu->ebx)) goto label_0001B39E;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1B39Eu); lift_push32(cpu, r); sfera_sub_0041B2F0(cpu,r); if (cpu->eip != r) return; }
    label_0001B39E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B39Eu);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0001B380;
    label_0001B3A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B3A3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41B3C0u);
    cpu->esp -= 0x58u;
    cpu->eax = lift_load32(cpu->esp + 0x64u);
    cpu->edx = lift_load32(cpu->esp + 0x78u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebp);
    cpu->eax += cpu->ebx;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001B4ED;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->edx = cpu->ebx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx -= cpu->ebx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(cpu->edx) * 2u))) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x75u)) goto label_0001B446;
    lift_store32(cpu->esp + 0x84u, 1u);
    goto label_0001B4F6;
    label_0001B446: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B446u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x64u)) goto label_0001B455;
    lift_store32(cpu->esp + 0x84u, 2u);
    label_0001B455: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B455u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixRotationQuaternion), LIFT_CODE_TOKEN_VA(0x41B45Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41B464u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    label_0001B479: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B479u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->eax += lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41B495u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41B49Au);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0001B4D8;
    label_0001B4A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B4A0u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(cpu->ebx)) goto label_0001B4D3;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1B4D3u); lift_push32(cpu, r); sfera_sub_0041B3C0(cpu,r); if (cpu->eip != r) return; }
    label_0001B4D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B4D3u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0001B4A0;
    label_0001B4D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B4D8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 32u, stop_address); return;
    label_0001B4ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B4EDu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_0001B455;
    label_0001B4F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B4F6u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x14u));
    cpu->ecx += cpu->ebx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixRotationQuaternion), LIFT_CODE_TOKEN_VA(0x41B50Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41B514u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    goto label_0001B479;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41B530u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 0x144u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->ecx + 0x4F3Cu, 0u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41B560u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 0x144u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->eax + 0x4F40u);
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0001B5A5;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(4u), 32u);
    cpu->esi -= cpu->eax;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xBCu))) goto label_0001B5A5;
    cpu->ecx = lift_load32(cpu->eax + 0xC0u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    lift_return(cpu, 8u, stop_address); return;
    label_0001B5A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41B5A5u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B5B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41B5B0u);
    cpu->esp -= 0x6Cu;
    cpu->eax = lift_load32(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x48u);
    cpu->ecx = 0x18u;
    cpu->edi = (uint32_t)(cpu->esp + 0x10u);
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_push32(cpu, 8u);
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41B96Au); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x6Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41B980u);
    lift_x87_push(cpu, (double)-1.0f);
    lift_store_f32(cpu->ecx + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ecx + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x58u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x50u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x54u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->ecx + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x60u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x74u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->ecx + 0x64u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x68u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x78u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)-2.5f);
    lift_store_f32(cpu->ecx + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x88u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x94u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x80u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x84u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x8Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x90u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41BA00u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x4F50u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFu)) goto label_0001BE0A;
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x54u);
    cpu->eax += lift_load32(cpu->esi + 0x4F4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BA49u); lift_push32(cpu, r); sfera_sub_0041AEE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001BA59;
    lift_store32(cpu->ebp + 0x20u, 0x30u);
    goto label_0001BA7C;
    label_0001BA59: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BA59u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x30u)) goto label_0001BA63;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x39u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001BA7C;
    label_0001BA63: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BA63u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x61u)) goto label_0001BA6D;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x7Au), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001BA7C;
    label_0001BA6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BA6Du);
    cpu->edx = 0x2F6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1BA7Cu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001BA7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BA7Cu);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->esi + 0x4F44u);
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x2Cu); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edi = lift_load32(cpu->edx + cpu->ecx + 0x24u);
    cpu->ebx = lift_load32(cpu->edi + 0x1Cu);
    cpu->esi = lift_load32(cpu->edi + 0xCu);
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BA9Bu); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esp;
    cpu->edx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0001BCA7;
    cpu->ebx = lift_load32(cpu->ebp + 0x14u);
    lift_x87_push(cpu, 0.9900000095367432);
    cpu->ecx += 4u;
    label_0001BAB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BAB6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_store_f32(cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ebx + 0x10u));
    cpu->eax += cpu->ebx;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x30u))));
    lift_store_f32(cpu->ecx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x34u))));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x38u))));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001BC92;
    cpu->eax = lift_load8(cpu->esi + 0x21u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->eax += cpu->ebx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x30u))));
    lift_store_f32(cpu->ebp + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x34u))));
    lift_store_f32(cpu->ebp + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x38u))));
    lift_store_f32(cpu->ebp + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFF0u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFF4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFF8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFF0u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFF4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFF8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001BC92: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BC92u);
    ++cpu->edx;
    cpu->esi += 0x28u;
    cpu->ecx += 0x20u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x1Cu))) goto label_0001BAB6;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001BCA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BCA7u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x24u)) & 0xFFu);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_0001BCCD;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->eax + 6u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->edi + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->edi + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_shadow_runtime.manager;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1BCCDu); lift_push32(cpu, r); sfera_sub_0048D390(cpu,r); if (cpu->eip != r) return; }
    label_0001BCCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BCCDu);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_0001BE0A;
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x39u)) goto label_0001BCE3;
    cpu->eax += 0xFFFFFFD0u;
    goto label_0001BCE6;
    label_0001BCE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BCE3u);
    cpu->eax += 0xFFFFFFA9u;
    label_0001BCE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BCE6u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 4u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0001BD09;
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0001BD09;
    cpu->edx = 0x335u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1BD09u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001BD09: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BD09u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BD13u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BD1Bu); lift_push32(cpu, r); sfera_sub_0044EFE0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001BE0A;
    cpu->ecx = lift_load32(cpu->edi + 0x1Cu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41BD2Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41BD34u);
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BD4Bu); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001BD61;
    cpu->esi = 0u;
    label_0001BD61: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BD61u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x18u)) != (uint32_t)(0u)) goto label_0001BD6A;
    cpu->esi |= 4u;
    label_0001BD6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BD6Au);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->eax + 6u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BD78u); lift_push32(cpu, r); sfera_sub_0044F0F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 6u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41BD89u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41BD8Eu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BDA6u); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07;
    cpu->eax = lift_load32(cpu->edx + 6u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_sky_runtime.draw_resource;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi |= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BDE9u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 6u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edx);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1Cu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.timing_accumulator, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_0001BE0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BE0Au);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 32u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41BE20u);
    cpu->esp -= 0x4Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_push32(cpu, 0x44u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.699999988079071));
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.30000001192092896));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41BE4Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41BE50u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->esp += 0xCu;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BEC9u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x4Cu;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BEE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41BEE0u);
    cpu->esp -= 0x4Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_push32(cpu, 0x44u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.699999988079071));
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.30000001192092896));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41BF0Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x41BF10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BF59u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x4Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41BF70u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BF85u); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"models\\textures\\wf00.dds";
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001BFA4;
    lift_store8(cpu->esp + 0x10u, 0x6Du);
    label_0001BFA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BFA4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_0001BFA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BFA7u);
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(9u)) goto label_0001BFB5;
    cpu->eax = (uint32_t)(cpu->ebx + 0x30u);
    lift_store8(cpu->esp + 0x16u, cpu->eax & 0xFFu);
    goto label_0001BFBC;
    label_0001BFB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BFB5u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x57u);
    lift_store8(cpu->esp + 0x16u, cpu->ecx & 0xFFu);
    label_0001BFBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41BFBCu);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BFC6u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0001BFA7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41BFD0u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BFF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41BFF0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C005u); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"models\\textures\\wr00.dds";
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C024;
    lift_store8(cpu->esp + 0x10u, 0x6Du);
    label_0001C024: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C024u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_0001C027: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C027u);
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(9u)) goto label_0001C035;
    cpu->eax = (uint32_t)(cpu->ebx + 0x30u);
    lift_store8(cpu->esp + 0x16u, cpu->eax & 0xFFu);
    goto label_0001C03C;
    label_0001C035: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C035u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x57u);
    lift_store8(cpu->esp + 0x16u, cpu->ecx & 0xFFu);
    label_0001C03C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C03Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C046u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0001C027;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C050u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C070u);
    if ((uint32_t)(lift_load32(cpu->esp + 4u)) != (uint32_t)(0u)) goto label_0001C07C;
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_0001C07C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C07Cu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x39u)) goto label_0001C092;
    cpu->eax -= 0x30u;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x74D4u);
    lift_return(cpu, 8u, stop_address); return;
    label_0001C092: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C092u);
    cpu->eax -= 0x57u;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x74D4u);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C1B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C1B0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->ecx + 0x7538u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.699999988079071));
    lift_store_f32(cpu->ecx + 0x7534u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C1F0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0001C204;
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C204u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0001C204: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C204u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0001C213;
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C213u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001C213: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C213u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C220u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0001C24B;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x14u))) goto label_0001C24B;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->edx)) goto label_0001C24B;
    cpu->esi = lift_load32(cpu->ebx + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u)))) goto label_0001C253;
    label_0001C24B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C24Bu);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    label_0001C253: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C253u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->esi = 0u;
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(2u)) goto label_0001C27C;
    cpu->eax = lift_load32(cpu->ebx + 0x18u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFFFEu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    ++cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->ecx);
    label_0001C271: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C271u);
    cpu->edx += lift_load32(cpu->eax);
    cpu->esi += lift_load32(cpu->eax + 4u);
    cpu->eax += 8u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C271;
    label_0001C27C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C27Cu);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0001C28C;
    cpu->eax = lift_load32(cpu->ebx + 0x18u);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    cpu->edi += lift_load32(cpu->esp + 0x20u);
    label_0001C28C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C28Cu);
    lift_x87_push(cpu, (double)0.009999999776482582f);
    cpu->esi += cpu->edx;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x2Cu)));
    lift_x87_pop(cpu);
    cpu->edi += cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001C2D8;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0001C37E;
    (void)cpu;
    label_0001C2B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C2B0u);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0xFFFFFFFFu)) goto label_0001C2CE;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C2CEu); lift_push32(cpu, r); sfera_sub_0041B2F0(cpu,r); if (cpu->eip != r) return; }
    label_0001C2CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C2CEu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx))) goto label_0001C2B0;
    goto label_0001C37E;
    label_0001C2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C2D8u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_0001C2F5;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x14u))) goto label_0001C2F5;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0001C2F5;
    cpu->edx = lift_load32(cpu->ebx + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u)))) goto label_0001C301;
    label_0001C2F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C2F5u);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    label_0001C301: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C301u);
    cpu->edx = 0u;
    cpu->esi = 0u;
    cpu->ebp = 0u;
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(2u)) goto label_0001C333;
    cpu->eax = lift_load32(cpu->ebx + 0x18u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFFFEu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    ++cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->ecx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0001C320: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C320u);
    cpu->edx += lift_load32(cpu->eax);
    cpu->esi += lift_load32(cpu->eax + 4u);
    cpu->eax += 8u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C320;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    label_0001C333: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C333u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0001C33F;
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->edi += cpu->eax;
    label_0001C33F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C33Fu);
    cpu->esi += cpu->edx;
    cpu->edi += cpu->esi;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0001C37E;
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0001C350: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C350u);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0xFFFFFFFFu)) goto label_0001C379;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C379u); lift_push32(cpu, r); sfera_sub_0041B3C0(cpu,r); if (cpu->eip != r) return; }
    label_0001C379: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C379u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx))) goto label_0001C350;
    label_0001C37E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C37Eu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C3CC;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(0u)) goto label_0001C3CC;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(0u)) goto label_0001C3CC;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0001C3CC;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edi = cpu->edi;
    label_0001C3A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C3A0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x1Cu))) goto label_0001C3C4;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x20u))) goto label_0001C3C4;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x24u))) goto label_0001C3C4;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x28u))) goto label_0001C3C4;
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->esi += 8u;
    cpu->ecx = 0x10u;
    cpu->edi = cpu->edx;
    lift_movs32(cpu, 1u);
    label_0001C3C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C3C4u);
    ++cpu->eax;
    cpu->edx += 0x40u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx))) goto label_0001C3A0;
    label_0001C3CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C3CCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 32u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C3E0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0001C3FB;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong handle: set_char_param\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C3F6u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0001C3FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C3FBu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0001C40F;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C40Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001C40F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C40Fu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x236u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C428u); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x144u)) <= (int32_t)(uint32_t)(0u)) goto label_0001C442;
    cpu->edx = 0x237u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C442u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001C442: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C442u);
    cpu->eax = lift_load32(cpu->edi + 0x144u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001C453;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->eax;
    goto label_0001C4A3;
    label_0001C453: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C453u);
    cpu->esi = 0u;
    cpu->eax = (uint32_t)(cpu->ebx + 0x4F54u);
    label_0001C460: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C460u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0u)) goto label_0001C477;
    ++cpu->esi;
    cpu->eax += 0x18u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x190u)) goto label_0001C460;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    goto label_0001C47F;
    label_0001C477: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C477u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x190u)) goto label_0001C48E;
    label_0001C47F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C47Fu);
    cpu->edx = 0x245u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C48Eu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0001C48E: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C48Eu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    lift_store32(cpu->edi + 0x144u, cpu->ecx);
    lift_store32(cpu->ebx + ((uint32_t)(cpu->edx) * 8u) + 0x4F54u, cpu->edi);
    label_0001C4A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C4A3u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x10u)) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u) + 0x9EDu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x14u, 0x30736Du);
    lift_store8(cpu->esp + 0x16u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C4D6;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0001C4F3;
    lift_push32(cpu, 3u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C4D4u); lift_push32(cpu, r); sfera_sub_00479FD0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001C4F3;
    label_0001C4D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C4D6u);
    cpu->ecx = cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0001C4E9;
    lift_push32(cpu, 3u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C4E7u); lift_push32(cpu, r); sfera_sub_00479FD0(cpu,r); if (cpu->eip != r) return; }
    goto label_0001C4F3;
    label_0001C4E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C4E9u);
    cpu->edx = 3u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C4F3u); lift_push32(cpu, r); sfera_sub_004593C0(cpu,r); if (cpu->eip != r) return; }
    label_0001C4F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C4F3u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 8u) + 0x4F58u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41C520u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0001C53D;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong handle: get_char_param\n";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C536u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    label_0001C536: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C536u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0001C53D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C53Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0001C551;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1C551u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0001C551: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C551u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, 0x26Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C568u); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 0x144u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0001C536;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx = lift_load32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0x4F58u);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0x4F58u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}
