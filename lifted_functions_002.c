#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414920(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00014920;
    label_00005690:
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
    label_000056A7:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000056B5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4056BAu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4056BAu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000056F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4056CBu)); sfera_sub_00404180(cpu, LIFT_CODE_TOKEN_VA(0x4056CBu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000056D3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4056D8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4056D8u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000056F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4056E9u)); sfera_sub_00404140(cpu, LIFT_CODE_TOKEN_VA(0x4056E9u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000056F1:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00005700:
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
    label_00005717:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005725:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40572Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40572Au));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005761;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40573Bu)); sfera_sub_004041F0(cpu, LIFT_CODE_TOKEN_VA(0x40573Bu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005743:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405748u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x405748u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005761;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405759u)); sfera_sub_004041C0(cpu, LIFT_CODE_TOKEN_VA(0x405759u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005761:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00005890:
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
    label_000058A7:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000058B5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4058BAu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4058BAu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000058F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4058CBu)); sfera_sub_004042B0(cpu, LIFT_CODE_TOKEN_VA(0x4058CBu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000058D3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4058D8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4058D8u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000058F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4058E9u)); sfera_sub_00403480(cpu, LIFT_CODE_TOKEN_VA(0x4058E9u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000058F1:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00005900:
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
    label_00005917:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005925:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40592Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40592Au));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005982;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40593Bu)); sfera_sub_004042F0(cpu, LIFT_CODE_TOKEN_VA(0x40593Bu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005943:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405948u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x405948u));
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
    label_00005975:
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005982:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00005990:
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
    label_000059A7:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000059B5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4059BAu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4059BAu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000059F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4059CBu)); sfera_sub_00404330(cpu, LIFT_CODE_TOKEN_VA(0x4059CBu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000059D3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4059D8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4059D8u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000059F1;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4059E9u)); sfera_sub_004034C0(cpu, LIFT_CODE_TOKEN_VA(0x4059E9u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000059F1:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00007ED0:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407ED9u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x407ED9u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407EF5u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x407EF5u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007FDB;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F12u)); sfera_sub_00406920(cpu, LIFT_CODE_TOKEN_VA(0x407F12u));
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F1D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F22u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x407F22u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007FDB;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F3Fu)); sfera_sub_00406970(cpu, LIFT_CODE_TOKEN_VA(0x407F3Fu));
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F4A:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F50u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x407F50u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F57u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x407F57u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007FDA;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F71u)); sfera_sub_00405300(cpu, LIFT_CODE_TOKEN_VA(0x407F71u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F7D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F82u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x407F82u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00007FDB;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407F93u)); sfera_sub_004069C0(cpu, LIFT_CODE_TOKEN_VA(0x407F93u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007F9E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407FA3u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x407FA3u));
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407FACu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x407FACu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00007FDB;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407FC2u)); sfera_sub_00405340(cpu, LIFT_CODE_TOKEN_VA(0x407FC2u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00007FCD:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005690;
    label_00007FDA:
    cpu->edi = lift_pop32(cpu);
    label_00007FDB:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00008010:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408019u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x408019u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408035u)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x408035u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408052u)); sfera_sub_00406A30(cpu, LIFT_CODE_TOKEN_VA(0x408052u));
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000805D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408062u)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x408062u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40807Fu)); sfera_sub_00406A80(cpu, LIFT_CODE_TOKEN_VA(0x40807Fu));
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000808A:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408090u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x408090u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408097u)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x408097u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811A;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4080B1u)); sfera_sub_00405380(cpu, LIFT_CODE_TOKEN_VA(0x4080B1u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000080BD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4080C2u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4080C2u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4080D3u)); sfera_sub_004069C0(cpu, LIFT_CODE_TOKEN_VA(0x4080D3u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000080DE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4080E3u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4080E3u));
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4080ECu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4080ECu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000811B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408102u)); sfera_sub_004053C0(cpu, LIFT_CODE_TOKEN_VA(0x408102u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000810D:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005700;
    label_0000811A:
    cpu->edi = lift_pop32(cpu);
    label_0000811B:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000091B0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4091DCu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4091DCu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4091FCu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4091FCu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009220;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9219u)); sfera_sub_00406AD0(cpu, LIFT_CODE_TOKEN_RVA(0x9219u));
    label_00009219:
    cpu->ecx = 0u;
    label_0000921B:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9220u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x9220u));
    label_00009220:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    label_00009224:
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409231u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x409231u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00009243:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40924Cu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x40924Cu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009220;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409269u)); sfera_sub_00406B20(cpu, LIFT_CODE_TOKEN_VA(0x409269u));
    goto label_00009219;
    label_0000926B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409270u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x409270u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40927Bu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x40927Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009224;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409299u)); sfera_sub_00405440(cpu, LIFT_CODE_TOKEN_VA(0x409299u));
    cpu->ecx = cpu->eax;
    goto label_0000921B;
    label_000092A0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4092A5u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4092A5u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009315;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4092B6u)); sfera_sub_00408150(cpu, LIFT_CODE_TOKEN_VA(0x4092B6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4092BDu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4092BDu));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000092CF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4092D4u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4092D4u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4092DDu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4092DDu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009315;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4092F3u)); sfera_sub_004054B0(cpu, LIFT_CODE_TOKEN_VA(0x4092F3u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4092FAu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4092FAu));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000930C:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9315u)); sfera_sub_00405800(cpu, LIFT_CODE_TOKEN_RVA(0x9315u));
    label_00009315:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00009350:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40935Au)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40935Au));
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0000941D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000939F;
        case 1u: goto label_000093D1;
        case 2u: goto label_000093F3;
        case 10u: goto label_00009371;
        default: goto label_0000941D;
    }
label_00009371: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409376u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x409376u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000942B;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409393u)); sfera_sub_004081B0(cpu, LIFT_CODE_TOKEN_VA(0x409393u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000939F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4093A4u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4093A4u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4093ABu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4093ABu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000942B;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4093C5u)); sfera_sub_00402900(cpu, LIFT_CODE_TOKEN_VA(0x4093C5u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000093D1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4093D6u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4093D6u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000942B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4093E7u)); sfera_sub_004054F0(cpu, LIFT_CODE_TOKEN_VA(0x4093E7u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000093F3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4093F8u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4093F8u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4093FFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4093FFu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000942B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409411u)); sfera_sub_00402930(cpu, LIFT_CODE_TOKEN_VA(0x409411u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000941D:
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005890;
    label_0000942B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00009450:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40945Au)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40945Au));
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0000951D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000949F;
        case 1u: goto label_000094D1;
        case 2u: goto label_000094F3;
        case 10u: goto label_00009471;
        default: goto label_0000951D;
    }
label_00009471: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409476u)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x409476u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409493u)); sfera_sub_004081F0(cpu, LIFT_CODE_TOKEN_VA(0x409493u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000949F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4094A4u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4094A4u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4094ABu)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x4094ABu));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4094C5u)); sfera_sub_00402970(cpu, LIFT_CODE_TOKEN_VA(0x4094C5u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000094D1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4094D6u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4094D6u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4094E7u)); sfera_sub_004054F0(cpu, LIFT_CODE_TOKEN_VA(0x4094E7u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000094F3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4094F8u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4094F8u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4094FFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4094FFu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000952B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409511u)); sfera_sub_004029A0(cpu, LIFT_CODE_TOKEN_VA(0x409511u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000951D:
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005900;
    label_0000952B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00009550:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40955Au)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40955Au));
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0000961D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0000959F;
        case 1u: goto label_000095D1;
        case 2u: goto label_000095F3;
        case 10u: goto label_00009571;
        default: goto label_0000961D;
    }
label_00009571: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409576u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x409576u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0xBu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000962B;
    cpu->edx = (uint32_t)(cpu->esp + 0xBu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409593u)); sfera_sub_00408230(cpu, LIFT_CODE_TOKEN_VA(0x409593u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000959F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4095A4u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4095A4u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4095ABu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4095ABu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0xBu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000962B;
    cpu->eax = (uint32_t)(cpu->esp + 0xBu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4095C5u)); sfera_sub_004029E0(cpu, LIFT_CODE_TOKEN_VA(0x4095C5u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000095D1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4095D6u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4095D6u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000962B;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4095E7u)); sfera_sub_00405580(cpu, LIFT_CODE_TOKEN_VA(0x4095E7u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000095F3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4095F8u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4095F8u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4095FFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4095FFu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000962B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409611u)); sfera_sub_00402A10(cpu, LIFT_CODE_TOKEN_VA(0x409611u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000961D:
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00005990;
    label_0000962B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00009650:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409659u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x409659u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40966Eu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40966Eu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009762;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409683u)); sfera_sub_00403D50(cpu, LIFT_CODE_TOKEN_VA(0x409683u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000968E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409693u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x409693u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00009762;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4096A8u)); sfera_sub_00403D90(cpu, LIFT_CODE_TOKEN_VA(0x4096A8u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000096B3:
    cpu->ecx = lift_load8(cpu->esi + 8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000096C0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4096C5u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4096C5u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009762;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4096E2u)); sfera_sub_00406B70(cpu, LIFT_CODE_TOKEN_VA(0x4096E2u));
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000096ED:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4096F2u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4096F2u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009762;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40970Bu)); sfera_sub_00408270(cpu, LIFT_CODE_TOKEN_VA(0x40970Bu));
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00009716:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40971Bu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40971Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009762;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409734u)); sfera_sub_00405600(cpu, LIFT_CODE_TOKEN_VA(0x409734u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000973F:
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    lift_store8(cpu->esi + 8u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40974Bu)); sfera_sub_004B24B0(cpu, LIFT_CODE_TOKEN_VA(0x40974Bu));
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00009756:
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00009762:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000A870:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A87Au)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40A87Au));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A88Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40A88Fu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A896u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40A896u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000A9AF;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A8ACu)); sfera_sub_00405B00(cpu, LIFT_CODE_TOKEN_VA(0x40A8ACu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A8B8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A8BDu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40A8BDu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A8C4u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40A8C4u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000A9AF;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A8DAu)); sfera_sub_00405B50(cpu, LIFT_CODE_TOKEN_VA(0x40A8DAu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A8E6:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A8F8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A8FDu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40A8FDu));
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A906u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40A906u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A9AF;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A922u)); sfera_sub_004088E0(cpu, LIFT_CODE_TOKEN_VA(0x40A922u));
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A930:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A935u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40A935u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A9AF;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A94Eu)); sfera_sub_004084D0(cpu, LIFT_CODE_TOKEN_VA(0x40A94Eu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A95A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A95Fu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40A95Fu));
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A968u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40A968u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000A9AF;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A97Eu)); sfera_sub_00406CE0(cpu, LIFT_CODE_TOKEN_VA(0x40A97Eu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A98A:
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A992u)); sfera_sub_00429A30(cpu, LIFT_CODE_TOKEN_VA(0x40A992u));
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A9A2:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000A9AF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000A9E0:
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A9ECu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40A9ECu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA01u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40AA01u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA08u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40AA08u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA1Eu)); sfera_sub_00405C60(cpu, LIFT_CODE_TOKEN_VA(0x40AA1Eu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AA2A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA2Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40AA2Fu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA36u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40AA36u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA4Cu)); sfera_sub_00405CB0(cpu, LIFT_CODE_TOKEN_VA(0x40AA4Cu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AA58:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AA6A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA6Fu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40AA6Fu));
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA78u)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x40AA78u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AA96u)); sfera_sub_00408970(cpu, LIFT_CODE_TOKEN_VA(0x40AA96u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AAA8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AAADu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40AAADu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000AB27;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AAC6u)); sfera_sub_004084D0(cpu, LIFT_CODE_TOKEN_VA(0x40AAC6u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AAD2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AAD7u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40AAD7u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AAE0u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40AAE0u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000AB27;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AAF6u)); sfera_sub_00406D20(cpu, LIFT_CODE_TOKEN_VA(0x40AAF6u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AB02:
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AB0Au)); sfera_sub_00429A30(cpu, LIFT_CODE_TOKEN_VA(0x40AB0Au));
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AB1A:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000AB27:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000D0E0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D10Cu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40D10Cu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D12Cu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x40D12Cu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D150;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D149u)); sfera_sub_0040B760(cpu, LIFT_CODE_TOKEN_VA(0x40D149u));
    cpu->ecx = 0u;
    label_0000D14B:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD150u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0xD150u));
    label_0000D150:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D161u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x40D161u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000D173:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D178u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40D178u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D183u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x40D183u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D150;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1A1u)); sfera_sub_00402A50(cpu, LIFT_CODE_TOKEN_VA(0x40D1A1u));
    cpu->ecx = cpu->eax;
    goto label_0000D14B;
    label_0000D1A5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1AAu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40D1AAu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000D214;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1BBu)); sfera_sub_0040A5E0(cpu, LIFT_CODE_TOKEN_VA(0x40D1BBu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1C2u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x40D1C2u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000D1D4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1D9u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40D1D9u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1E0u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40D1E0u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000D214;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1F2u)); sfera_sub_00402AC0(cpu, LIFT_CODE_TOKEN_VA(0x40D1F2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D1F9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x40D1F9u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000D20B:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD214u)); sfera_sub_00405A80(cpu, LIFT_CODE_TOKEN_RVA(0xD214u));
    label_0000D214:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000E6D0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E6FCu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40E6FCu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E711u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40E711u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E718u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40E718u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000E826;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E72Eu)); sfera_sub_00405F10(cpu, LIFT_CODE_TOKEN_VA(0x40E72Eu));
    cpu->ecx = cpu->eax;
    goto label_0000E821;
    label_0000E735:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E73Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40E73Au));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E741u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40E741u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000E826;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E757u)); sfera_sub_00405F60(cpu, LIFT_CODE_TOKEN_VA(0x40E757u));
    cpu->ecx = cpu->eax;
    goto label_0000E821;
    label_0000E75E:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000E821;
    label_0000E76B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E770u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40E770u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E77Du)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x40E77Du));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E7A6;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E79Fu)); sfera_sub_0040D3B0(cpu, LIFT_CODE_TOKEN_VA(0x40E79Fu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xE7A6u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0xE7A6u));
    label_0000E7A6:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E7B7u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x40E7B7u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000E7C9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E7CEu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40E7CEu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E826;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E7E7u)); sfera_sub_0040B810(cpu, LIFT_CODE_TOKEN_VA(0x40E7E7u));
    cpu->ecx = 0u;
    goto label_0000E821;
    label_0000E7EB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E7F0u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x40E7F0u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E7F9u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40E7F9u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0000E826;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E80Fu)); sfera_sub_00406DA0(cpu, LIFT_CODE_TOKEN_VA(0x40E80Fu));
    cpu->ecx = cpu->eax;
    goto label_0000E821;
    label_0000E813:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E81Au)); sfera_sub_0040AB60(cpu, LIFT_CODE_TOKEN_VA(0x40E81Au));
    cpu->ecx = 0u;
    goto label_0000E821;
    label_0000E81E:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0000E821:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xE826u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0xE826u));
    label_0000E826:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000101D0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410206u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x410206u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41021Bu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41021Bu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001034C;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410230u)); sfera_sub_00403DE0(cpu, LIFT_CODE_TOKEN_VA(0x410230u));
    cpu->ecx = cpu->eax;
    goto label_00010347;
    label_00010237:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41023Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41023Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001034C;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410251u)); sfera_sub_00403E10(cpu, LIFT_CODE_TOKEN_VA(0x410251u));
    cpu->ecx = cpu->eax;
    goto label_00010347;
    label_00010258:
    cpu->ecx = lift_load8(cpu->esi + 8u);
    goto label_00010347;
    label_00010261:
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41026Au)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41026Au));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x68u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001028E;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410287u)); sfera_sub_0040E6A0(cpu, LIFT_CODE_TOKEN_VA(0x410287u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1028Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1028Eu));
    label_0001028E:
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    label_00010292:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410297u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x410297u));
    goto label_0001034C;
    label_0001029C:
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4102A5u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4102A5u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x68u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010292;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4102C2u)); sfera_sub_0040D330(cpu, LIFT_CODE_TOKEN_VA(0x4102C2u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4102C9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4102C9u));
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4102D2u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4102D2u));
    goto label_0001034C;
    label_000102D4:
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4102DDu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4102DDu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, 2u);
    lift_store32(cpu->esp + 0x3Cu, 0xFu);
    lift_store32(cpu->esp + 0x38u, 0u);
    lift_store8(cpu->esp + 0x28u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410304u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x410304u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x68u, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410312u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x410312u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001032E;
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410327u)); sfera_sub_004082E0(cpu, LIFT_CODE_TOKEN_VA(0x410327u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1032Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1032Eu));
    label_0001032E:
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410337u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x410337u));
    goto label_0001034C;
    label_00010339:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410340u)); sfera_sub_0040B7A0(cpu, LIFT_CODE_TOKEN_VA(0x410340u));
    cpu->ecx = 0u;
    goto label_00010347;
    label_00010344:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00010347:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1034Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1034Cu));
    label_0001034C:
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00010EC0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410EF7u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x410EF7u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F17u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x410F17u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010F3B;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F34u)); sfera_sub_00410390(cpu, LIFT_CODE_TOKEN_VA(0x410F34u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x10F3Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x10F3Bu));
    label_00010F3B:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    label_00010F3F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F44u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x410F44u));
    goto label_00011019;
    label_00010F49:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F52u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x410F52u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010F3B;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F6Fu)); sfera_sub_004103E0(cpu, LIFT_CODE_TOKEN_VA(0x410F6Fu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F76u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x410F76u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F7Fu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x410F7Fu));
    goto label_00011019;
    label_00010F84:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F89u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x410F89u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410F94u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x410F94u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00010F3F;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FB2u)); sfera_sub_0040A550(cpu, LIFT_CODE_TOKEN_VA(0x410FB2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FB9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x410FB9u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FC2u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x410FC2u));
    goto label_00011019;
    label_00010FC4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FC9u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x410FC9u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00011019;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FDAu)); sfera_sub_0040B700(cpu, LIFT_CODE_TOKEN_VA(0x410FDAu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FE1u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x410FE1u));
    goto label_00011019;
    label_00010FE3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FE8u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x410FE8u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410FF1u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x410FF1u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00011019;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411007u)); sfera_sub_00405400(cpu, LIFT_CODE_TOKEN_VA(0x411007u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41100Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x41100Eu));
    goto label_00011019;
    label_00011010:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x11019u)); sfera_sub_00405770(cpu, LIFT_CODE_TOKEN_RVA(0x11019u));
    label_00011019:
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000116B0:
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
    label_000116C5:
    goto label_00008010;
    label_000116CA:
    goto label_00010EC0;
    label_000116CF:
    goto label_000091B0;
    label_000116D4:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00012160:
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41216Cu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41216Cu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412181u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412181u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412188u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412188u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000122A0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41219Eu)); sfera_sub_00406DE0(cpu, LIFT_CODE_TOKEN_VA(0x41219Eu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000121AA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4121AFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4121AFu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4121B6u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4121B6u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000122A0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4121CCu)); sfera_sub_00406E30(cpu, LIFT_CODE_TOKEN_VA(0x4121CCu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000121D8:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000121EA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4121EFu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4121EFu));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4121F8u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4121F8u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000122A0;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41221Au)); sfera_sub_004117C0(cpu, LIFT_CODE_TOKEN_VA(0x41221Au));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012226:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41222Bu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41222Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000122A0;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412244u)); sfera_sub_00411190(cpu, LIFT_CODE_TOKEN_VA(0x412244u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012250:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412255u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x412255u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41225Eu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41225Eu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000122A0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412274u)); sfera_sub_00409C90(cpu, LIFT_CODE_TOKEN_VA(0x412274u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012280:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412287u)); sfera_sub_00410650(cpu, LIFT_CODE_TOKEN_VA(0x412287u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012293:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000122A0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000122D0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4122FCu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4122FCu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412311u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412311u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412318u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412318u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41232Eu)); sfera_sub_00406F30(cpu, LIFT_CODE_TOKEN_VA(0x41232Eu));
    cpu->ecx = cpu->eax;
    goto label_00012460;
    label_00012335:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41233Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41233Au));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412341u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412341u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412357u)); sfera_sub_00406F80(cpu, LIFT_CODE_TOKEN_VA(0x412357u));
    cpu->ecx = cpu->eax;
    goto label_00012460;
    label_0001235E:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00012460;
    label_0001236B:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412374u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412374u));
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412381u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x412381u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000123A2;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412399u)); sfera_sub_00411370(cpu, LIFT_CODE_TOKEN_VA(0x412399u));
    lift_store32(cpu->eax, cpu->edi);
    label_0001239B:
    cpu->ecx = 0u;
    label_0001239D:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x123A2u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x123A2u));
    label_000123A2:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4123B3u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4123B3u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000123C5:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4123CEu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4123CEu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00012402;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4123F0u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4123F0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00012402:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41240Au)); sfera_sub_00411140(cpu, LIFT_CODE_TOKEN_VA(0x41240Au));
    goto label_0001239B;
    label_0001240C:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412415u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412415u));
    lift_store32(cpu->esp + 0x1Cu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412422u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412422u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000123A2;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41243Cu)); sfera_sub_00409D10(cpu, LIFT_CODE_TOKEN_VA(0x41243Cu));
    cpu->ecx = cpu->eax;
    goto label_0001239D;
    label_00012443:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41244Bu)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x41244Bu));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412455u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x412455u));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00012460;
    label_0001245D:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00012460:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x12465u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x12465u));
    label_00012465:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000124A0:
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4124ACu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4124ACu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4124C1u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4124C1u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4124C8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4124C8u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4124DEu)); sfera_sub_00406FE0(cpu, LIFT_CODE_TOKEN_VA(0x4124DEu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000124EA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4124EFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4124EFu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4124F6u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4124F6u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41250Cu)); sfera_sub_00407030(cpu, LIFT_CODE_TOKEN_VA(0x41250Cu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012518:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0001252A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41252Fu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41252Fu));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412538u)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x412538u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41255Au)); sfera_sub_00411820(cpu, LIFT_CODE_TOKEN_VA(0x41255Au));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012566:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41256Bu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41256Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000125E0;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412584u)); sfera_sub_00411190(cpu, LIFT_CODE_TOKEN_VA(0x412584u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00012590:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412595u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x412595u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41259Eu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41259Eu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000125E0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4125B4u)); sfera_sub_00409D50(cpu, LIFT_CODE_TOKEN_VA(0x4125B4u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000125C0:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4125C7u)); sfera_sub_00410650(cpu, LIFT_CODE_TOKEN_VA(0x4125C7u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000125D3:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000125E0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00012610:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41263Cu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41263Cu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412651u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412651u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412658u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412658u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000127AB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41266Eu)); sfera_sub_00407130(cpu, LIFT_CODE_TOKEN_VA(0x41266Eu));
    cpu->ecx = cpu->eax;
    goto label_000127A6;
    label_00012675:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41267Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41267Au));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412681u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412681u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000127AB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412697u)); sfera_sub_00407180(cpu, LIFT_CODE_TOKEN_VA(0x412697u));
    cpu->ecx = cpu->eax;
    goto label_000127A6;
    label_0001269E:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000127A6;
    label_000126AB:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4126B4u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4126B4u));
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4126C1u)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x4126C1u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000126E8;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4126DBu)); sfera_sub_00411450(cpu, LIFT_CODE_TOKEN_VA(0x4126DBu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000126E1:
    cpu->ecx = 0u;
    label_000126E3:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x126E8u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x126E8u));
    label_000126E8:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4126F9u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4126F9u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001270B:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412714u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412714u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00012748;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412736u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x412736u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00012748:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412750u)); sfera_sub_00411140(cpu, LIFT_CODE_TOKEN_VA(0x412750u));
    goto label_000126E1;
    label_00012752:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41275Bu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x41275Bu));
    lift_store32(cpu->esp + 0x20u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412768u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412768u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000126E8;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412782u)); sfera_sub_00409DD0(cpu, LIFT_CODE_TOKEN_VA(0x412782u));
    cpu->ecx = cpu->eax;
    goto label_000126E3;
    label_00012789:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412791u)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x412791u));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41279Bu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41279Bu));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000127A6;
    label_000127A3:
    cpu->ecx |= 0xFFFFFFFFu;
    label_000127A6:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x127ABu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x127ABu));
    label_000127AB:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000127F0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41281Cu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41281Cu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412831u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412831u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412838u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412838u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012955;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41284Eu)); sfera_sub_00407390(cpu, LIFT_CODE_TOKEN_VA(0x41284Eu));
    cpu->ecx = cpu->eax;
    goto label_00012950;
    label_00012855:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41285Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41285Au));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412861u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412861u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012955;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412877u)); sfera_sub_004073E0(cpu, LIFT_CODE_TOKEN_VA(0x412877u));
    cpu->ecx = cpu->eax;
    goto label_00012950;
    label_0001287E:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00012950;
    label_0001288B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412890u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x412890u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41289Du)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x41289Du));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000128C6;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4128BFu)); sfera_sub_004118E0(cpu, LIFT_CODE_TOKEN_VA(0x4128BFu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x128C6u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x128C6u));
    label_000128C6:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4128D7u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4128D7u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000128E9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4128EEu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4128EEu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00012955;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412907u)); sfera_sub_00411280(cpu, LIFT_CODE_TOKEN_VA(0x412907u));
    cpu->ecx = 0u;
    goto label_00012950;
    label_0001290B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412910u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x412910u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412919u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412919u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012955;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41292Fu)); sfera_sub_00409ED0(cpu, LIFT_CODE_TOKEN_VA(0x41292Fu));
    cpu->ecx = cpu->eax;
    goto label_00012950;
    label_00012933:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41293Bu)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x41293Bu));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412945u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x412945u));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00012950;
    label_0001294D:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00012950:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x12955u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x12955u));
    label_00012955:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00012990:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4129C2u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4129C2u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4129D7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4129D7u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4129DEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4129DEu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012B2B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4129F4u)); sfera_sub_004074C0(cpu, LIFT_CODE_TOKEN_VA(0x4129F4u));
    cpu->ecx = cpu->eax;
    goto label_00012B26;
    label_000129FB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A00u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412A00u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A07u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412A07u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012B2B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A1Du)); sfera_sub_00407500(cpu, LIFT_CODE_TOKEN_VA(0x412A1Du));
    cpu->ecx = cpu->eax;
    goto label_00012B26;
    label_00012A24:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00012B26;
    label_00012A31:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A3Au)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412A3Au));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x28u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A4Bu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412A4Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x28u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00012A71;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A6Au)); sfera_sub_00411930(cpu, LIFT_CODE_TOKEN_VA(0x412A6Au));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x12A71u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x12A71u));
    label_00012A71:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store8(cpu->esp + 0x28u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x12A7Fu)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_RVA(0x12A7Fu));
    label_00012A7F:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A90u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x412A90u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00012AA2:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412AABu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412AABu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x28u, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00012A7F;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412AC8u)); sfera_sub_00411320(cpu, LIFT_CODE_TOKEN_VA(0x412AC8u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412ACFu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x412ACFu));
    goto label_00012A7F;
    label_00012AD1:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412ADAu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412ADAu));
    lift_store32(cpu->esp + 0x28u, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412AE7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x412AE7u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00012A7F;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412AFDu)); sfera_sub_00409F50(cpu, LIFT_CODE_TOKEN_VA(0x412AFDu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412B04u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x412B04u));
    goto label_00012A7F;
    label_00012B09:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412B11u)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x412B11u));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412B1Bu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x412B1Bu));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00012B26;
    label_00012B23:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00012B26:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x12B2Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x12B2Bu));
    label_00012B2B:
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013100:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413137u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413137u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413157u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413157u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001317B;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413174u)); sfera_sub_00412100(cpu, LIFT_CODE_TOKEN_VA(0x413174u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1317Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1317Bu));
    label_0001317B:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413184u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413184u));
    goto label_00013218;
    label_00013189:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41318Eu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41318Eu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413199u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413199u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000131BE;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4131B7u)); sfera_sub_0040A590(cpu, LIFT_CODE_TOKEN_VA(0x4131B7u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x131BEu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x131BEu));
    label_000131BE:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4131C7u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4131C7u));
    goto label_00013218;
    label_000131C9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4131CEu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4131CEu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013218;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4131DFu)); sfera_sub_0040D250(cpu, LIFT_CODE_TOKEN_VA(0x4131DFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4131E6u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4131E6u));
    goto label_00013218;
    label_000131E8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4131EDu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4131EDu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4131F4u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4131F4u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013218;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413206u)); sfera_sub_004033A0(cpu, LIFT_CODE_TOKEN_VA(0x413206u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41320Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x41320Du));
    goto label_00013218;
    label_0001320F:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13218u)); sfera_sub_00405A00(cpu, LIFT_CODE_TOKEN_RVA(0x13218u));
    label_00013218:
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013260:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413297u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413297u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4132ACu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4132ACu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4132B3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4132B3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000133D4;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4132C9u)); sfera_sub_00405BB0(cpu, LIFT_CODE_TOKEN_VA(0x4132C9u));
    cpu->ecx = cpu->eax;
    goto label_000133CF;
    label_000132D0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4132D5u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4132D5u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4132DCu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4132DCu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000133D4;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4132F2u)); sfera_sub_00405C00(cpu, LIFT_CODE_TOKEN_VA(0x4132F2u));
    cpu->ecx = cpu->eax;
    goto label_000133CF;
    label_000132F9:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000133CF;
    label_00013306:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41330Fu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41330Fu));
    lift_store32(cpu->esp + 0x50u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41331Cu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41331Cu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001333D;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413334u)); sfera_sub_00411980(cpu, LIFT_CODE_TOKEN_VA(0x413334u));
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1333Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1333Du));
    label_0001333D:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    label_00013341:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413346u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413346u));
    goto label_000133D4;
    label_0001334B:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413354u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413354u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013341;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413371u)); sfera_sub_00410550(cpu, LIFT_CODE_TOKEN_VA(0x413371u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413378u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x413378u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413381u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413381u));
    goto label_000133D4;
    label_00013383:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41338Cu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41338Cu));
    lift_store32(cpu->esp + 0x50u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413399u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413399u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000133B6;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4133AFu)); sfera_sub_00408450(cpu, LIFT_CODE_TOKEN_VA(0x4133AFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x133B6u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x133B6u));
    label_000133B6:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4133BFu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4133BFu));
    goto label_000133D4;
    label_000133C1:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4133C8u)); sfera_sub_0040E860(cpu, LIFT_CODE_TOKEN_VA(0x4133C8u));
    cpu->ecx = 0u;
    goto label_000133CF;
    label_000133CC:
    cpu->ecx |= 0xFFFFFFFFu;
    label_000133CF:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x133D4u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x133D4u));
    label_000133D4:
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013420:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413457u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413457u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41346Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41346Cu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413473u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413473u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001359A;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413489u)); sfera_sub_00405D10(cpu, LIFT_CODE_TOKEN_VA(0x413489u));
    cpu->ecx = cpu->eax;
    goto label_00013595;
    label_00013490:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413495u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413495u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41349Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41349Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001359A;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4134B2u)); sfera_sub_00405D60(cpu, LIFT_CODE_TOKEN_VA(0x4134B2u));
    cpu->ecx = cpu->eax;
    goto label_00013595;
    label_000134B9:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013595;
    label_000134C6:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4134CFu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4134CFu));
    lift_store32(cpu->esp + 0x54u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4134DCu)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x4134DCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013503;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4134F6u)); sfera_sub_00411A70(cpu, LIFT_CODE_TOKEN_VA(0x4134F6u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->ecx = 0u;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13503u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13503u));
    label_00013503:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    label_00013507:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41350Cu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x41350Cu));
    goto label_0001359A;
    label_00013511:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41351Au)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41351Au));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x54u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013507;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413537u)); sfera_sub_00410550(cpu, LIFT_CODE_TOKEN_VA(0x413537u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41353Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x41353Eu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413547u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413547u));
    goto label_0001359A;
    label_00013549:
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413552u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413552u));
    lift_store32(cpu->esp + 0x54u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41355Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41355Fu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001357C;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413575u)); sfera_sub_00408510(cpu, LIFT_CODE_TOKEN_VA(0x413575u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1357Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1357Cu));
    label_0001357C:
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413585u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413585u));
    goto label_0001359A;
    label_00013587:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41358Eu)); sfera_sub_0040E860(cpu, LIFT_CODE_TOKEN_VA(0x41358Eu));
    cpu->ecx = 0u;
    goto label_00013595;
    label_00013592:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013595:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1359Au)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1359Au));
    label_0001359A:
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000135E0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413617u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413617u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41362Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41362Cu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413633u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413633u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013731;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413649u)); sfera_sub_00405DC0(cpu, LIFT_CODE_TOKEN_VA(0x413649u));
    cpu->ecx = cpu->eax;
    goto label_0001372C;
    label_00013650:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413655u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413655u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41365Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41365Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013731;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413672u)); sfera_sub_00405E10(cpu, LIFT_CODE_TOKEN_VA(0x413672u));
    cpu->ecx = cpu->eax;
    goto label_0001372C;
    label_00013679:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0001372C;
    label_00013686:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41368Bu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41368Bu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413698u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413698u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000136C9;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4136B6u)); sfera_sub_00411B60(cpu, LIFT_CODE_TOKEN_VA(0x4136B6u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4136C2u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4136C2u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x136C9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x136C9u));
    label_000136C9:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4136D2u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4136D2u));
    goto label_00013731;
    label_000136D4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4136D9u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4136D9u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013731;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4136F2u)); sfera_sub_00410590(cpu, LIFT_CODE_TOKEN_VA(0x4136F2u));
    cpu->ecx = 0u;
    goto label_0001372C;
    label_000136F6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4136FBu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4136FBu));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413704u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413704u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013731;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41371Au)); sfera_sub_00406D60(cpu, LIFT_CODE_TOKEN_VA(0x41371Au));
    cpu->ecx = cpu->eax;
    goto label_0001372C;
    label_0001371E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413725u)); sfera_sub_0040E890(cpu, LIFT_CODE_TOKEN_VA(0x413725u));
    cpu->ecx = 0u;
    goto label_0001372C;
    label_00013729:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0001372C:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13731u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13731u));
    label_00013731:
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013780:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4137B7u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4137B7u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4137CCu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4137CCu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4137D3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4137D3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001390E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4137E9u)); sfera_sub_00405E70(cpu, LIFT_CODE_TOKEN_VA(0x4137E9u));
    cpu->ecx = cpu->eax;
    goto label_00013909;
    label_000137F0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4137F5u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4137F5u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4137FCu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4137FCu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001390E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413812u)); sfera_sub_00405EB0(cpu, LIFT_CODE_TOKEN_VA(0x413812u));
    cpu->ecx = cpu->eax;
    goto label_00013909;
    label_00013819:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013909;
    label_00013826:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41382Fu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41382Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413840u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413840u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x6Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001386E;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41385Bu)); sfera_sub_00411C90(cpu, LIFT_CODE_TOKEN_VA(0x41385Bu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413867u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x413867u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1386Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1386Eu));
    label_0001386E:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13877u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0x13877u));
    label_00013877:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413880u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413880u));
    goto label_0001390E;
    label_00013885:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41388Eu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41388Eu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x6Cu, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013877;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4138ABu)); sfera_sub_004105D0(cpu, LIFT_CODE_TOKEN_VA(0x4138ABu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4138B2u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4138B2u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4138BBu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4138BBu));
    goto label_0001390E;
    label_000138BD:
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4138C6u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4138C6u));
    lift_store32(cpu->esp + 0x6Cu, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4138D3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4138D3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000138F0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4138E9u)); sfera_sub_00408590(cpu, LIFT_CODE_TOKEN_VA(0x4138E9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x138F0u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x138F0u));
    label_000138F0:
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4138F9u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4138F9u));
    goto label_0001390E;
    label_000138FB:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413902u)); sfera_sub_0040E8C0(cpu, LIFT_CODE_TOKEN_VA(0x413902u));
    cpu->ecx = 0u;
    goto label_00013909;
    label_00013906:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013909:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1390Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1390Eu));
    label_0001390E:
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013960:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413997u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413997u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4139ACu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4139ACu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4139B3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4139B3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013AEB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4139C9u)); sfera_sub_00405FC0(cpu, LIFT_CODE_TOKEN_VA(0x4139C9u));
    cpu->ecx = cpu->eax;
    goto label_00013AE6;
    label_000139D0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4139D5u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4139D5u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4139DCu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4139DCu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013AEB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4139F2u)); sfera_sub_00406000(cpu, LIFT_CODE_TOKEN_VA(0x4139F2u));
    cpu->ecx = cpu->eax;
    goto label_00013AE6;
    label_000139F9:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013AE6;
    label_00013A06:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A0Fu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413A0Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x58u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A20u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x413A20u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x58u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013A46;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A3Fu)); sfera_sub_00412B70(cpu, LIFT_CODE_TOKEN_VA(0x413A3Fu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13A46u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13A46u));
    label_00013A46:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store8(cpu->esp + 0x58u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13A54u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_RVA(0x13A54u));
    label_00013A54:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A5Du)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413A5Du));
    goto label_00013AEB;
    label_00013A62:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A6Bu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413A6Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x58u, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013A54;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A88u)); sfera_sub_00410610(cpu, LIFT_CODE_TOKEN_VA(0x413A88u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A8Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x413A8Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413A98u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413A98u));
    goto label_00013AEB;
    label_00013A9A:
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413AA3u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413AA3u));
    lift_store32(cpu->esp + 0x58u, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413AB0u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413AB0u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013ACD;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413AC6u)); sfera_sub_00408610(cpu, LIFT_CODE_TOKEN_VA(0x413AC6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13ACDu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13ACDu));
    label_00013ACD:
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413AD6u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413AD6u));
    goto label_00013AEB;
    label_00013AD8:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413ADFu)); sfera_sub_0040E8F0(cpu, LIFT_CODE_TOKEN_VA(0x413ADFu));
    cpu->ecx = 0u;
    goto label_00013AE6;
    label_00013AE3:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013AE6:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13AEBu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13AEBu));
    label_00013AEB:
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013CC0:
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
    label_00013CD5:
    goto label_00009450;
    label_00013CDA:
    goto label_00009550;
    label_00013CDF:
    goto label_00013100;
    label_00013CE4:
    goto label_0000D0E0;
    label_00013CE9:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013D00:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D37u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413D37u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D4Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413D4Cu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D53u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413D53u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013E83;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D69u)); sfera_sub_00406E90(cpu, LIFT_CODE_TOKEN_VA(0x413D69u));
    cpu->ecx = cpu->eax;
    goto label_00013E7E;
    label_00013D70:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D75u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413D75u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D7Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413D7Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013E83;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D92u)); sfera_sub_00406EE0(cpu, LIFT_CODE_TOKEN_VA(0x413D92u));
    cpu->ecx = cpu->eax;
    goto label_00013E7E;
    label_00013D99:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00013E7E;
    label_00013DA6:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DAFu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413DAFu));
    lift_store32(cpu->esp + 0x50u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DBCu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413DBCu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013DDD;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DD4u)); sfera_sub_00412BC0(cpu, LIFT_CODE_TOKEN_VA(0x413DD4u));
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13DDDu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13DDDu));
    label_00013DDD:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    label_00013DE1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DE6u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413DE6u));
    goto label_00013E83;
    label_00013DEB:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DF4u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413DF4u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x50u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013DE1;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E11u)); sfera_sub_004110F0(cpu, LIFT_CODE_TOKEN_VA(0x413E11u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E18u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x413E18u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E21u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413E21u));
    goto label_00013E83;
    label_00013E23:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E2Cu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413E2Cu));
    lift_store32(cpu->esp + 0x50u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E39u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413E39u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013E56;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E4Fu)); sfera_sub_00409CD0(cpu, LIFT_CODE_TOKEN_VA(0x413E4Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13E56u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13E56u));
    label_00013E56:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E5Fu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413E5Fu));
    goto label_00013E83;
    label_00013E61:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E69u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x413E69u));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E73u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x413E73u));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00013E7E;
    label_00013E7B:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00013E7E:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13E83u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13E83u));
    label_00013E83:
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00013ED0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F07u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x413F07u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F1Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413F1Cu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F23u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413F23u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014059;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F39u)); sfera_sub_00407090(cpu, LIFT_CODE_TOKEN_VA(0x413F39u));
    cpu->ecx = cpu->eax;
    goto label_00014054;
    label_00013F40:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F45u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413F45u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F4Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x413F4Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014059;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F62u)); sfera_sub_004070E0(cpu, LIFT_CODE_TOKEN_VA(0x413F62u));
    cpu->ecx = cpu->eax;
    goto label_00014054;
    label_00013F69:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00014054;
    label_00013F76:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F7Fu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413F7Fu));
    lift_store32(cpu->esp + 0x54u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F8Cu)); sfera_sub_0043B0C0(cpu, LIFT_CODE_TOKEN_VA(0x413F8Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00013FB3;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FA6u)); sfera_sub_00412C80(cpu, LIFT_CODE_TOKEN_VA(0x413FA6u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->ecx = 0u;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x13FB3u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x13FB3u));
    label_00013FB3:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    label_00013FB7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FBCu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413FBCu));
    goto label_00014059;
    label_00013FC1:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FCAu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413FCAu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x54u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00013FB7;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FE7u)); sfera_sub_004110F0(cpu, LIFT_CODE_TOKEN_VA(0x413FE7u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FEEu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x413FEEu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FF7u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413FF7u));
    goto label_00014059;
    label_00013FF9:
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414002u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414002u));
    lift_store32(cpu->esp + 0x54u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41400Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41400Fu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0001402C;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414025u)); sfera_sub_00409D90(cpu, LIFT_CODE_TOKEN_VA(0x414025u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1402Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1402Cu));
    label_0001402C:
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414035u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414035u));
    goto label_00014059;
    label_00014037:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41403Fu)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x41403Fu));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414049u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x414049u));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_00014054;
    label_00014051:
    cpu->ecx |= 0xFFFFFFFFu;
    label_00014054:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14059u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x14059u));
    label_00014059:
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000140A0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4140D7u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4140D7u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4140ECu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4140ECu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4140F3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4140F3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014200;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414109u)); sfera_sub_004071D0(cpu, LIFT_CODE_TOKEN_VA(0x414109u));
    cpu->ecx = cpu->eax;
    goto label_000141FB;
    label_00014110:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414115u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x414115u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41411Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41411Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014200;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414132u)); sfera_sub_00407220(cpu, LIFT_CODE_TOKEN_VA(0x414132u));
    cpu->ecx = cpu->eax;
    goto label_000141FB;
    label_00014139:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000141FB;
    label_00014146:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41414Bu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x41414Bu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414158u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414158u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014189;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414176u)); sfera_sub_00412D50(cpu, LIFT_CODE_TOKEN_VA(0x414176u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414182u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x414182u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14189u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x14189u));
    label_00014189:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414192u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414192u));
    goto label_00014200;
    label_00014194:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414199u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x414199u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014200;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141B2u)); sfera_sub_004111E0(cpu, LIFT_CODE_TOKEN_VA(0x4141B2u));
    cpu->ecx = 0u;
    goto label_000141FB;
    label_000141B6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141BBu)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4141BBu));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141C4u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4141C4u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014200;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141DAu)); sfera_sub_00409E10(cpu, LIFT_CODE_TOKEN_VA(0x4141DAu));
    cpu->ecx = cpu->eax;
    goto label_000141FB;
    label_000141DE:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141E6u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x4141E6u));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141F0u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4141F0u));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000141FB;
    label_000141F8:
    cpu->ecx |= 0xFFFFFFFFu;
    label_000141FB:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14200u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x14200u));
    label_00014200:
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014250:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414287u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x414287u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41429Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41429Cu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142A3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4142A3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000143ED;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142B9u)); sfera_sub_00407270(cpu, LIFT_CODE_TOKEN_VA(0x4142B9u));
    cpu->ecx = cpu->eax;
    goto label_000143E8;
    label_000142C0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142C5u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4142C5u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142CCu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4142CCu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000143ED;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142E2u)); sfera_sub_004072B0(cpu, LIFT_CODE_TOKEN_VA(0x4142E2u));
    cpu->ecx = cpu->eax;
    goto label_000143E8;
    label_000142E9:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000143E8;
    label_000142F6:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142FFu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4142FFu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414310u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414310u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x6Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001433E;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41432Bu)); sfera_sub_00412E60(cpu, LIFT_CODE_TOKEN_VA(0x41432Bu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414337u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x414337u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1433Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1433Eu));
    label_0001433E:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14347u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0x14347u));
    label_00014347:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414350u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414350u));
    goto label_000143ED;
    label_00014355:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41435Eu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41435Eu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x6Cu, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014347;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41437Bu)); sfera_sub_00411230(cpu, LIFT_CODE_TOKEN_VA(0x41437Bu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414382u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x414382u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41438Bu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x41438Bu));
    goto label_000143ED;
    label_0001438D:
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414396u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414396u));
    lift_store32(cpu->esp + 0x6Cu, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143A3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4143A3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000143C0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143B9u)); sfera_sub_00409E50(cpu, LIFT_CODE_TOKEN_VA(0x4143B9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x143C0u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x143C0u));
    label_000143C0:
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143C9u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4143C9u));
    goto label_000143ED;
    label_000143CB:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143D3u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x4143D3u));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143DDu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4143DDu));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000143E8;
    label_000143E5:
    cpu->ecx |= 0xFFFFFFFFu;
    label_000143E8:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x143EDu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x143EDu));
    label_000143ED:
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014440:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414477u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x414477u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41448Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41448Cu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414493u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x414493u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000145DA;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144A9u)); sfera_sub_00407430(cpu, LIFT_CODE_TOKEN_VA(0x4144A9u));
    cpu->ecx = cpu->eax;
    goto label_000145D5;
    label_000144B0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144B5u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4144B5u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144BCu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4144BCu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000145DA;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144D2u)); sfera_sub_00407470(cpu, LIFT_CODE_TOKEN_VA(0x4144D2u));
    cpu->ecx = cpu->eax;
    goto label_000145D5;
    label_000144D9:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000145D5;
    label_000144E6:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144EFu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4144EFu));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x58u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414500u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x414500u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x58u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014526;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41451Fu)); sfera_sub_00413B30(cpu, LIFT_CODE_TOKEN_VA(0x41451Fu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14526u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x14526u));
    label_00014526:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store8(cpu->esp + 0x58u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14534u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_RVA(0x14534u));
    label_00014534:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41453Du)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x41453Du));
    goto label_000145DA;
    label_00014542:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41454Bu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41454Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x58u, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014534;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414568u)); sfera_sub_004112D0(cpu, LIFT_CODE_TOKEN_VA(0x414568u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41456Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x41456Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414578u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414578u));
    goto label_000145DA;
    label_0001457A:
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414583u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414583u));
    lift_store32(cpu->esp + 0x58u, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414590u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x414590u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000145AD;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145A6u)); sfera_sub_00409F10(cpu, LIFT_CODE_TOKEN_VA(0x4145A6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x145ADu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x145ADu));
    label_000145AD:
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145B6u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4145B6u));
    goto label_000145DA;
    label_000145B8:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145C0u)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x4145C0u));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145CAu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4145CAu));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_000145D5;
    label_000145D2:
    cpu->ecx |= 0xFFFFFFFFu;
    label_000145D5:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x145DAu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x145DAu));
    label_000145DA:
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014620:
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
    label_00014640:
    goto label_0000A870;
    label_00014645:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00014655;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014684;
    goto label_00013420;
    label_00014655:
    goto label_0000A9E0;
    label_0001465A:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001466A;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014684;
    goto label_00013780;
    label_0001466A:
    goto label_000135E0;
    label_0001466F:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001467F;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014684;
    goto label_00013960;
    label_0001467F:
    goto label_0000E6D0;
    label_00014684:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000146A0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4146D7u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x4146D7u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4146ECu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4146ECu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4146F3u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4146F3u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014833;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414709u)); sfera_sub_00407300(cpu, LIFT_CODE_TOKEN_VA(0x414709u));
    cpu->ecx = cpu->eax;
    goto label_0001482E;
    label_00014710:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414715u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x414715u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41471Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x41471Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014833;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414732u)); sfera_sub_00407340(cpu, LIFT_CODE_TOKEN_VA(0x414732u));
    cpu->ecx = cpu->eax;
    goto label_0001482E;
    label_00014739:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0001482E;
    label_00014746:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41474Fu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x41474Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x3Cu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414760u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414760u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x3Cu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001478E;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41477Bu)); sfera_sub_00413B80(cpu, LIFT_CODE_TOKEN_VA(0x41477Bu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414787u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x414787u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1478Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x1478Eu));
    label_0001478E:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14797u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0x14797u));
    label_00014797:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x3Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147A8u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4147A8u));
    goto label_00014833;
    label_000147AD:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147B6u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4147B6u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x3Cu, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014797;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147D3u)); sfera_sub_00411890(cpu, LIFT_CODE_TOKEN_VA(0x4147D3u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147DAu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4147DAu));
    goto label_00014797;
    label_000147DC:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147E5u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4147E5u));
    lift_store32(cpu->esp + 0x3Cu, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147F2u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4147F2u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00014797;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414808u)); sfera_sub_00409E90(cpu, LIFT_CODE_TOKEN_VA(0x414808u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41480Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x41480Fu));
    goto label_00014797;
    label_00014811:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414819u)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x414819u));
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414823u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x414823u));
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx = 0u;
    goto label_0001482E;
    label_0001482B:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0001482E:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14833u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x14833u));
    label_00014833:
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014880:
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
    label_000148A3:
    goto label_00013D00;
    label_000148A8:
    goto label_00012160;
    label_000148AD:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148C5;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148C0;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014904;
    goto label_00012610;
    label_000148C0:
    goto label_00013ED0;
    label_000148C5:
    goto label_000124A0;
    label_000148CA:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148E2;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148DD;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014904;
    goto label_000146A0;
    label_000148DD:
    goto label_00014250;
    label_000148E2:
    goto label_000140A0;
    label_000148E7:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148FF;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000148FA;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014904;
    goto label_00012990;
    label_000148FA:
    goto label_00014440;
    label_000148FF:
    goto label_000127F0;
    label_00014904:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014920:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414925u)); sfera_sub_0043B0B0(cpu, LIFT_CODE_TOKEN_VA(0x414925u));
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00014938;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x19285u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00014940;
    label_00014938:
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00014940:
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
    label_00014955:
    goto label_00013CC0;
    label_0001495A:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001496A;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00014979;
    goto label_000101D0;
    label_0001496A:
    goto label_00009650;
    label_0001496F:
    goto label_00014620;
    label_00014974:
    goto label_00014880;
    label_00014979:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004149A0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000149C0:
    cpu->ebx = lift_load32(cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4149CAu)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4149CAu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4149D0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4149D0u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000149C0;
    cpu->ebx = lift_pop32(cpu);
    label_000149DA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004149E0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_00014A00:
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414A08u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414A08u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00014A00;
    cpu->edi = lift_pop32(cpu);
    label_00014A13:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414A1Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414A1Cu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00401E50(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414A30(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414A60u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x414A60u));
    cpu->edi = 0u;
    lift_push32(cpu, 0xCu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414A70u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414A70u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014AAD;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414A8Fu)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x414A8Fu));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014AAD:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414AD7u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x414AD7u));
    lift_trap(cpu, 0x414AD7u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414AE0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414B10u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x414B10u));
    cpu->edi = 0u;
    lift_push32(cpu, 0xCu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414B20u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414B20u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014B5D;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414B3Fu)); sfera_sub_00401E00(cpu, LIFT_CODE_TOKEN_VA(0x414B3Fu));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014B5D:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414B87u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x414B87u));
    lift_trap(cpu, 0x414B87u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414BF0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414C20u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x414C20u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x10u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414C30u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414C30u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014C6D;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414C4Fu)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x414C4Fu));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014C6D:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414C97u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x414C97u));
    lift_trap(cpu, 0x414C97u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414CA0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414CE6u)); sfera_sub_004149A0(cpu, LIFT_CODE_TOKEN_VA(0x414CE6u));
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414CEEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414CEEu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D00u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x414D00u));
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00014D10;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D0Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414D0Du));
    cpu->esp += 4u;
    label_00014D10:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414D50(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D80u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x414D80u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x24u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D90u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414D90u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00014DCD;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414DAFu)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x414DAFu));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014DCD:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414DF7u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x414DF7u));
    lift_trap(cpu, 0x414DF7u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00414E00(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414E43u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x414E43u));
    lift_push32(cpu, 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414E4Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414E4Au));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414E68u)); sfera_sub_00414A30(cpu, LIFT_CODE_TOKEN_VA(0x414E68u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014E78:
    cpu->edx = 0xDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414E87u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x414E87u));
    lift_push32(cpu, 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414E8Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414E8Eu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414EACu)); sfera_sub_00414AE0(cpu, LIFT_CODE_TOKEN_VA(0x414EACu));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014EBC:
    cpu->edx = 0xDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414ECBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x414ECBu));
    lift_push32(cpu, 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414ED2u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414ED2u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414EECu)); sfera_sub_00414D50(cpu, LIFT_CODE_TOKEN_VA(0x414EECu));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014EFC:
    cpu->edx = 0xDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414F0Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x414F0Bu));
    lift_push32(cpu, 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414F12u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x414F12u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00014F3C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414F2Cu)); sfera_sub_00414BF0(cpu, LIFT_CODE_TOKEN_VA(0x414F2Cu));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00014F3C:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004150C0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4150F0u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4150F0u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415100u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415100u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415132u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x415132u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41513Au)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x41513Au));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015158:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415182u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x415182u));
    lift_trap(cpu, 0x415182u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415190(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4151C0u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4151C0u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4151D0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4151D0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415202u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x415202u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41520Au)); sfera_sub_00401E00(cpu, LIFT_CODE_TOKEN_VA(0x41520Au));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015228:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415252u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x415252u));
    lift_trap(cpu, 0x415252u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415260(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4152B2u)); sfera_sub_00406340(cpu, LIFT_CODE_TOKEN_VA(0x4152B2u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4152BBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4152BBu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4152CDu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x4152CDu));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_000152DD;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4152DAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4152DAu));
    cpu->esp += 4u;
    label_000152DD:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415370(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4153A0u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4153A0u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x1Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4153B0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4153B0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4153E2u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x4153E2u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4153EAu)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x4153EAu));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015408:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415432u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x415432u));
    lift_trap(cpu, 0x415432u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415440(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415492u)); sfera_sub_00409F90(cpu, LIFT_CODE_TOKEN_VA(0x415492u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41549Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41549Bu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4154ADu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x4154ADu));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_000154BD;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4154BAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4154BAu));
    cpu->esp += 4u;
    label_000154BD:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004156A0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4156D0u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4156D0u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x30u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4156E0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4156E0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415712u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x415712u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41571Au)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x41571Au));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015738:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415762u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x415762u));
    lift_trap(cpu, 0x415762u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415770(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4157A0u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4157A0u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x30u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4157B0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4157B0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4157E2u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x4157E2u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4157EAu)); sfera_sub_00401E00(cpu, LIFT_CODE_TOKEN_VA(0x4157EAu));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015808:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415832u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x415832u));
    lift_trap(cpu, 0x415832u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415840(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415870u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x415870u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x30u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415880u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415880u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4158B2u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x4158B2u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4158BAu)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x4158BAu));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000158D8:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415902u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x415902u));
    lift_trap(cpu, 0x415902u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415910(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415940u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x415940u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x48u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415950u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415950u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415982u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x415982u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41598Au)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x41598Au));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000159A8:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4159D2u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4159D2u));
    lift_trap(cpu, 0x4159D2u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004159E0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415A10u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x415A10u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415A20u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415A20u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415A52u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x415A52u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415A5Au)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x415A5Au));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015A78:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415AA2u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x415AA2u));
    lift_trap(cpu, 0x415AA2u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415DB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00015DB0;
    label_00015AB0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415AE6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415AE6u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415AEDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415AEDu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015B57;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415B07u)); sfera_sub_004156A0(cpu, LIFT_CODE_TOKEN_VA(0x415B07u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015B17:
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415B26u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415B26u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415B2Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415B2Du));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015B57;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415B47u)); sfera_sub_004150C0(cpu, LIFT_CODE_TOKEN_VA(0x415B47u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015B57:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015B70:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415BA6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415BA6u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415BADu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415BADu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015C17;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415BC7u)); sfera_sub_00415770(cpu, LIFT_CODE_TOKEN_VA(0x415BC7u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015BD7:
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415BE6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415BE6u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415BEDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415BEDu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015C17;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415C07u)); sfera_sub_00415190(cpu, LIFT_CODE_TOKEN_VA(0x415C07u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015C17:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015C30:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415C66u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415C66u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415C6Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415C6Du));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015CD7;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415C87u)); sfera_sub_00415910(cpu, LIFT_CODE_TOKEN_VA(0x415C87u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015C97:
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415CA6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415CA6u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415CADu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415CADu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015CD7;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415CC7u)); sfera_sub_00415840(cpu, LIFT_CODE_TOKEN_VA(0x415CC7u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015CD7:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015CF0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415D26u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415D26u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415D2Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415D2Du));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015D97;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415D47u)); sfera_sub_004159E0(cpu, LIFT_CODE_TOKEN_VA(0x415D47u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015D57:
    cpu->edx = 0x7Au;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415D66u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x415D66u));
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415D6Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x415D6Du));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00015D97;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415D87u)); sfera_sub_00415370(cpu, LIFT_CODE_TOKEN_VA(0x415D87u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015D97:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00015DB0:
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
    label_00015DC6:
    cpu->ecx = cpu->edx;
    goto label_00015B70;
    label_00015DCD:
    cpu->ecx = cpu->edx;
    goto label_00015C30;
    label_00015DD4:
    cpu->ecx = cpu->edx;
    goto label_00015CF0;
    label_00015DDB:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415E00(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415E52u)); sfera_sub_0040D400(cpu, LIFT_CODE_TOKEN_VA(0x415E52u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415E5Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x415E5Bu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415E6Du)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x415E6Du));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_00015E7D;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415E7Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x415E7Au));
    cpu->esp += 4u;
    label_00015E7D:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415EA0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415EF2u)); sfera_sub_0040D4D0(cpu, LIFT_CODE_TOKEN_VA(0x415EF2u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415EFBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x415EFBu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415F0Du)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x415F0Du));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_00015F1D;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415F1Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x415F1Au));
    cpu->esp += 4u;
    label_00015F1D:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415F40(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415F92u)); sfera_sub_0040D5A0(cpu, LIFT_CODE_TOKEN_VA(0x415F92u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415F9Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x415F9Bu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415FADu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x415FADu));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_00015FBD;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415FBAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x415FBAu));
    cpu->esp += 4u;
    label_00015FBD:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00415FE0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416032u)); sfera_sub_0040D670(cpu, LIFT_CODE_TOKEN_VA(0x416032u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41603Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41603Bu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41604Du)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x41604Du));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_0001605D;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41605Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41605Au));
    cpu->esp += 4u;
    label_0001605D:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000160AF;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00016093;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016093:
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4160A2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4160A2u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4160ABu)); sfera_sub_00415E00(cpu, LIFT_CODE_TOKEN_VA(0x4160ABu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000160AF:
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4160BEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4160BEu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4160C7u)); sfera_sub_00415260(cpu, LIFT_CODE_TOKEN_VA(0x4160C7u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004160D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000160FF;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000160E3;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000160E3:
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4160F2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4160F2u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4160FBu)); sfera_sub_00415F40(cpu, LIFT_CODE_TOKEN_VA(0x4160FBu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000160FF:
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41610Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41610Eu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416117u)); sfera_sub_00415EA0(cpu, LIFT_CODE_TOKEN_VA(0x416117u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416120(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001614F;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00016133;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016133:
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416142u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x416142u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41614Bu)); sfera_sub_00415FE0(cpu, LIFT_CODE_TOKEN_VA(0x41614Bu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001614F:
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41615Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41615Eu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416167u)); sfera_sub_00415440(cpu, LIFT_CODE_TOKEN_VA(0x416167u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004161D0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416200u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x416200u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416210u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x416210u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416242u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x416242u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 3u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016260:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41628Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41628Au));
    lift_trap(cpu, 0x41628Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416290(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4162E2u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4162E2u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4162EBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4162EBu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4162FDu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x4162FDu));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_0001630D;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41630Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41630Au));
    cpu->esp += 4u;
    label_0001630D:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004163A0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4163D0u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4163D0u));
    cpu->edi = 0u;
    lift_push32(cpu, 0x2Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4163E0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4163E0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416412u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x416412u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 3u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016430:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41645Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41645Au));
    lift_trap(cpu, 0x41645Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416460(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416496u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x416496u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41649Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x41649Du));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00016507;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4164B7u)); sfera_sub_004163A0(cpu, LIFT_CODE_TOKEN_VA(0x4164B7u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000164C7:
    cpu->edx = 0xEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4164D6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4164D6u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4164DDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4164DDu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00016507;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4164F7u)); sfera_sub_004161D0(cpu, LIFT_CODE_TOKEN_VA(0x4164F7u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016507:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416520(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416572u)); sfera_sub_0040A7A0(cpu, LIFT_CODE_TOKEN_VA(0x416572u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41657Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41657Bu));
    cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41658Du)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x41658Du));
    if ((uint8_t)((lift_load8(cpu->esp + 0x28u)) & (1u)) == 0u) goto label_0001659D;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41659Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41659Au));
    cpu->esp += 4u;
    label_0001659D:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416610(LiftCpu* cpu, uint32_t stop_address) {
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
    label_00016630:
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416638u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416638u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi))) goto label_00016630;
    cpu->edi = lift_pop32(cpu);
    label_00016642:
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41664Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41664Au));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416650(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016666;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416663u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416663u));
    cpu->esp += 4u;
    label_00016666:
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
    label_00016684:
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41668Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41668Cu));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00016684;
    label_00016696:
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41669Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41669Fu));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416A30(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416A6Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416A6Eu));
    cpu->esp += 4u;
    label_00016A71:
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416A8Du)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x416A8Du));
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416A95u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416A95u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416AA7u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x416AA7u));
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016AB7;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416AB4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416AB4u));
    cpu->esp += 4u;
    label_00016AB7:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416AD0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416B0Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416B0Eu));
    cpu->esp += 4u;
    label_00016B11:
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416B2Du)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x416B2Du));
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416B35u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416B35u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416B47u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x416B47u));
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016B57;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416B54u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416B54u));
    cpu->esp += 4u;
    label_00016B57:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416B70(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416BAEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416BAEu));
    cpu->esp += 4u;
    label_00016BB1:
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416BCDu)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x416BCDu));
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416BD5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416BD5u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416BE7u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x416BE7u));
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016BF7;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416BF4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416BF4u));
    cpu->esp += 4u;
    label_00016BF7:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416C10(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416C41u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x416C41u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x10u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416C60u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x416C60u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416C8Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416C8Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416C9Bu)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x416C9Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416CA3u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x416CA3u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016CC2:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416CECu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416CECu));
    lift_trap(cpu, 0x416CECu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416CF0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416D21u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x416D21u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416D40u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x416D40u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416D6Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416D6Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416D7Bu)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x416D7Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416D83u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x416D83u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016DA2:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416DCCu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416DCCu));
    lift_trap(cpu, 0x416DCCu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416DD0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416E01u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x416E01u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x10u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416E20u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x416E20u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416E4Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416E4Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416E5Bu)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x416E5Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416E63u)); sfera_sub_00401E00(cpu, LIFT_CODE_TOKEN_VA(0x416E63u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016E82:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416EACu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416EACu));
    lift_trap(cpu, 0x416EACu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416EB0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416EE1u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x416EE1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416F00u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x416F00u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416F2Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416F2Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416F3Bu)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x416F3Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416F43u)); sfera_sub_00401E00(cpu, LIFT_CODE_TOKEN_VA(0x416F43u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016F62:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416F8Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416F8Cu));
    lift_trap(cpu, 0x416F8Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00416F90(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416FC1u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x416FC1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416FE0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x416FE0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41700Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41700Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41701Bu)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x41701Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417023u)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x417023u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017042:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41706Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41706Cu));
    lift_trap(cpu, 0x41706Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417070(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4170A1u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4170A1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4170C0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4170C0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4170EEu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4170EEu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4170FBu)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x4170FBu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417103u)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x417103u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017122:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41714Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41714Cu));
    lift_trap(cpu, 0x41714Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004172F0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417321u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x417321u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x28u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417340u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417340u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41736Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41736Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41737Bu)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x41737Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417383u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x417383u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000173A2:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4173CCu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4173CCu));
    lift_trap(cpu, 0x4173CCu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004173D0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417401u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x417401u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x28u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417420u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417420u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41744Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41744Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41745Bu)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x41745Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417463u)); sfera_sub_00401E00(cpu, LIFT_CODE_TOKEN_VA(0x417463u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017482:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4174ACu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4174ACu));
    lift_trap(cpu, 0x4174ACu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004174B0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4174E1u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4174E1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x28u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417500u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417500u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41752Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41752Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41753Bu)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x41753Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417543u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x417543u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017562:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41758Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41758Cu));
    lift_trap(cpu, 0x41758Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417590(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4175C1u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4175C1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x40u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4175E0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4175E0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41760Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41760Eu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41761Bu)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x41761Bu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417623u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x417623u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017642:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41766Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41766Cu));
    lift_trap(cpu, 0x41766Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417670(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4176A1u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4176A1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x2Cu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4176C0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4176C0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4176EEu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4176EEu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4176FBu)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x4176FBu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417703u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x417703u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017722:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41774Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41774Cu));
    lift_trap(cpu, 0x41774Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417750(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417781u)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x417781u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x10u)) & 0xFFFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    cpu->ebx = 0u;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 0x2Cu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4177A0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4177A0u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4177CEu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4177CEu));
    lift_store8(cpu->esp + 0x30u, 3u);
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4177DBu)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x4177DBu));
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4177E3u)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x4177E3u));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 4u, 5u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017802:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41782Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41782Cu));
    lift_trap(cpu, 0x41782Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417C70(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00017C70;
    label_00017830:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417873u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417873u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41787Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x41787Au));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417898u)); sfera_sub_00416CF0(cpu, LIFT_CODE_TOKEN_VA(0x417898u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000178A8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4178B7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4178B7u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4178BEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4178BEu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4178D8u)); sfera_sub_004172F0(cpu, LIFT_CODE_TOKEN_VA(0x4178D8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000178E8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4178F7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4178F7u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4178FEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4178FEu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417918u)); sfera_sub_00416C10(cpu, LIFT_CODE_TOKEN_VA(0x417918u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017928:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017940:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417983u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417983u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41798Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x41798Au));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4179A8u)); sfera_sub_00416EB0(cpu, LIFT_CODE_TOKEN_VA(0x4179A8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000179B8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4179C7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4179C7u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4179CEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4179CEu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4179E8u)); sfera_sub_004173D0(cpu, LIFT_CODE_TOKEN_VA(0x4179E8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000179F8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417A07u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417A07u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417A0Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417A0Eu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417A28u)); sfera_sub_00416DD0(cpu, LIFT_CODE_TOKEN_VA(0x417A28u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017A38:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017A50:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417A93u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417A93u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417A9Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417A9Au));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417AB8u)); sfera_sub_00417670(cpu, LIFT_CODE_TOKEN_VA(0x417AB8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017AC8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417AD7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417AD7u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417ADEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417ADEu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417AF8u)); sfera_sub_00417590(cpu, LIFT_CODE_TOKEN_VA(0x417AF8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017B08:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417B17u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417B17u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417B1Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417B1Eu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417B38u)); sfera_sub_004174B0(cpu, LIFT_CODE_TOKEN_VA(0x417B38u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017B48:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017B60:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417BA3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417BA3u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417BAAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417BAAu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417BC8u)); sfera_sub_00417070(cpu, LIFT_CODE_TOKEN_VA(0x417BC8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017BD8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417BE7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417BE7u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417BEEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417BEEu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417C08u)); sfera_sub_00417750(cpu, LIFT_CODE_TOKEN_VA(0x417C08u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017C18:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417C27u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417C27u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417C2Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x417C2Eu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417C48u)); sfera_sub_00416F90(cpu, LIFT_CODE_TOKEN_VA(0x417C48u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017C58:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017C70:
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
    label_00017C86:
    cpu->ecx = cpu->edx;
    goto label_00017940;
    label_00017C8D:
    cpu->ecx = cpu->edx;
    goto label_00017A50;
    label_00017C94:
    cpu->ecx = cpu->edx;
    goto label_00017B60;
    label_00017C9B:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417CC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017CD6;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417CD3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417CD3u));
    cpu->esp += 4u;
    label_00017CD6:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417CE7u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x417CE7u));
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417CF0u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417CFAu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x417CFAu));
    if ((uint8_t)((lift_load8(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017D0A;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D07u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417D07u));
    cpu->esp += 4u;
    label_00017D0A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017D36;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D33u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417D33u));
    cpu->esp += 4u;
    label_00017D36:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D47u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x417D47u));
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D50u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417D50u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D5Au)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x417D5Au));
    if ((uint8_t)((lift_load8(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017D6A;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D67u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417D67u));
    cpu->esp += 4u;
    label_00017D6A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417D80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017D96;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D93u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417D93u));
    cpu->esp += 4u;
    label_00017D96:
    cpu->ecx = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417DA7u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x417DA7u));
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417DB0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417DB0u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417DBAu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x417DBAu));
    if ((uint8_t)((lift_load8(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017DCA;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417DC7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417DC7u));
    cpu->esp += 4u;
    label_00017DCA:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417DE0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417E1Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417E1Eu));
    cpu->esp += 4u;
    label_00017E21:
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417E3Du)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x417E3Du));
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417E45u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417E45u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417E57u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x417E57u));
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00017E67;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417E64u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417E64u));
    cpu->esp += 4u;
    label_00017E67:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417E80(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417EBEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417EBEu));
    cpu->esp += 4u;
    label_00017EC1:
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417EDDu)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x417EDDu));
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417EE5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417EE5u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417EF7u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x417EF7u));
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00017F07;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F04u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417F04u));
    cpu->esp += 4u;
    label_00017F07:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417F20(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017F36:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F45u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417F45u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F4Eu)); sfera_sub_00416A30(cpu, LIFT_CODE_TOKEN_VA(0x417F4Eu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017F52:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F61u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417F61u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F6Au)); sfera_sub_00417CC0(cpu, LIFT_CODE_TOKEN_VA(0x417F6Au));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017F6E:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F7Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417F7Du));
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F85u)); sfera_sub_00416650(cpu, LIFT_CODE_TOKEN_VA(0x417F85u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F8Cu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x417F8Cu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F92u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417F92u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00417FA0(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017FB6:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417FC5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417FC5u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417FCEu)); sfera_sub_00417DE0(cpu, LIFT_CODE_TOKEN_VA(0x417FCEu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017FD2:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417FE1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417FE1u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417FEAu)); sfera_sub_00417D80(cpu, LIFT_CODE_TOKEN_VA(0x417FEAu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017FEE:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417FFDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x417FFDu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418006u)); sfera_sub_00417D20(cpu, LIFT_CODE_TOKEN_VA(0x418006u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418010(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018026:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418035u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x418035u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41803Eu)); sfera_sub_00416B70(cpu, LIFT_CODE_TOKEN_VA(0x41803Eu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018042:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418051u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x418051u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41805Au)); sfera_sub_00417E80(cpu, LIFT_CODE_TOKEN_VA(0x41805Au));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001805E:
    cpu->edx = 0x9Du;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41806Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41806Du));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418076u)); sfera_sub_00416AD0(cpu, LIFT_CODE_TOKEN_VA(0x418076u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004180D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4180FDu)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4180FDu));
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418119u)); sfera_sub_00401DF0(cpu, LIFT_CODE_TOKEN_VA(0x418119u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41816Du)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x41816Du));
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418189u)); sfera_sub_00401E00(cpu, LIFT_CODE_TOKEN_VA(0x418189u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004181B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4181DDu)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x4181DDu));
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4181F9u)); sfera_sub_00401E10(cpu, LIFT_CODE_TOKEN_VA(0x4181F9u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018233;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418230u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x418230u));
    cpu->esp += 4u;
    label_00018233:
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41824Fu)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x41824Fu));
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_0001825F;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41825Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41825Cu));
    cpu->esp += 4u;
    label_0001825F:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004182C0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_00018300:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418307u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x418307u));
    cpu->esi += 8u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_00018300;
    label_0001830E:
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418317u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x418317u));
    cpu->esp += 4u;
    label_0001831A:
    cpu->ecx = cpu->edi;
    lift_store32(cpu->edi + 0x10u, cpu->ebp);
    lift_store32(cpu->edi + 0x14u, cpu->ebp);
    lift_store32(cpu->edi + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418332u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x418332u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418350(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41837Du)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x41837Du));
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418399u)); sfera_sub_00401E30(cpu, LIFT_CODE_TOKEN_VA(0x418399u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41842Du)); sfera_sub_00401E40(cpu, LIFT_CODE_TOKEN_VA(0x41842Du));
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418449u)); sfera_sub_00401E20(cpu, LIFT_CODE_TOKEN_VA(0x418449u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418470(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4184B3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4184B3u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4184BAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4184BAu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4184D8u)); sfera_sub_004180D0(cpu, LIFT_CODE_TOKEN_VA(0x4184D8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000184E8:
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4184F7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4184F7u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4184FEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4184FEu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41851Cu)); sfera_sub_00418140(cpu, LIFT_CODE_TOKEN_VA(0x41851Cu));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001852C:
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41853Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41853Bu));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418542u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x418542u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418560u)); sfera_sub_004181B0(cpu, LIFT_CODE_TOKEN_VA(0x418560u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018570:
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41857Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41857Fu));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418586u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x418586u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4185A0u)); sfera_sub_00418400(cpu, LIFT_CODE_TOKEN_VA(0x4185A0u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000185B0:
    cpu->edx = 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4185BFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4185BFu));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4185C6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4185C6u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000185F0;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4185E0u)); sfera_sub_00418350(cpu, LIFT_CODE_TOKEN_VA(0x4185E0u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000185F0:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00018647;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41863Bu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x41863Bu));
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418644u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x418644u));
    cpu->esp += 4u;
    label_00018647:
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418663u)); sfera_sub_00401E50(cpu, LIFT_CODE_TOKEN_VA(0x418663u));
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_00018673;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418670u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x418670u));
    cpu->esp += 4u;
    label_00018673:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x414u;
    cpu->eax = lift_load32(cpu->esp + 0x418u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\%d%s");
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, 0x400u); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x418787u));
    cpu->ebp = native_function_address32(&::fopen);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->edx);
    cpu->edi = 0u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x187A1u), LIFT_CODE_TOKEN_RVA(0x1879Fu))) { return; }
    cpu->esi = cpu->eax;
    cpu->esp += 0x1Cu;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00018875;
    cpu->edi = native_function_address32(&::fclose);
    label_000187B4:
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_00018815;
    lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x4187BEu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4187C5u));
    cpu->esp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x989680u)) goto label_00018815;
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x187D8u), LIFT_CODE_TOKEN_RVA(0x187D6u))) { return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x187E4u), LIFT_CODE_TOKEN_RVA(0x187E2u))) { return; }
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00018815;
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4187F3u));
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x187FCu), LIFT_CODE_TOKEN_RVA(0x187FAu))) { return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x1880Au), LIFT_CODE_TOKEN_RVA(0x18808u))) { return; }
    cpu->esi = cpu->eax;
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000187B4;
    goto label_00018877;
    label_00018815:
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x41881Au));
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
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x41884Au));
    cpu->ecx = lift_load32(cpu->esp + 0x44Cu);
    cpu->ebx = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x450u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::vfprintf), LIFT_CODE_TOKEN_VA(0x418863u));
    lift_push32(cpu, cpu->esi);
    cpu->ebx += cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1886Eu), LIFT_CODE_TOKEN_RVA(0x1886Cu))) { return; }
    cpu->esp += 0x30u;
    cpu->eax = cpu->ebx;
    goto label_00018877;
    label_00018875:
    cpu->eax = cpu->edi;
    label_00018877:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004188A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4188CEu)); sfera_sub_00419810(cpu, LIFT_CODE_TOKEN_VA(0x4188CEu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418933u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x418933u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0xEA9Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x418940u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418986u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418986u));
    lift_push32(cpu, (uintptr_t)"Create connect manager\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418995u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418995u));
    cpu->esp += 0x1Cu;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004189B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) == (uint8_t)(1u)) goto label_000189FD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::Sleep);
    label_000189C5:
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) == (uint8_t)(0u)) goto label_000189EF;
    cpu->eax = lift_load32(cpu->esi + 0xEA6Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000189EF;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0xEA60u)) <= (int32_t)(uint32_t)(0u)) goto label_000189EB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x189EBu)); sfera_sub_00419730(cpu, LIFT_CODE_TOKEN_RVA(0x189EBu));
    label_000189EB:
    lift_push32(cpu, 6u);
    goto label_000189F1;
    label_000189EF:
    lift_push32(cpu, 0xAu);
    label_000189F1:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x189F3u), LIFT_CODE_TOKEN_RVA(0x189F1u))) { return; }
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) != (uint8_t)(1u)) goto label_000189C5;
    cpu->edi = lift_pop32(cpu);
    label_000189FD:
    lift_push32(cpu, (uintptr_t)"Rnd Thread exit\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418A0Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418A0Cu));
    cpu->esp += 8u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA4u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00018B10;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(1)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418A43u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418A43u));
    cpu->eax = lift_load32(cpu->esi + 0xEA70u);
    cpu->edi = native_function_address32(&::WaitForSingleObject);
    cpu->esp += 8u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esi + 0xEA88u, cpu->ebx & 0xFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x18A5Du), LIFT_CODE_TOKEN_RVA(0x18A5Bu))) { return; }
    cpu->ebx = native_function_address32(&::TerminateThread);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018A72;
    cpu->ecx = lift_load32(cpu->esi + 0xEA70u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x18A72u), LIFT_CODE_TOKEN_RVA(0x18A70u))) { return; }
    label_00018A72:
    cpu->edx = lift_load32(cpu->esi + 0xEA70u);
    cpu->ebp = native_function_address32(&::CloseHandle);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x18A81u), LIFT_CODE_TOKEN_RVA(0x18A7Fu))) { return; }
    cpu->eax = lift_load32(cpu->esi + 0xEA78u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x18A8Cu), LIFT_CODE_TOKEN_RVA(0x18A8Au))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018A9B;
    cpu->ecx = lift_load32(cpu->esi + 0xEA78u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x18A9Bu), LIFT_CODE_TOKEN_RVA(0x18A99u))) { return; }
    label_00018A9B:
    cpu->edx = lift_load32(cpu->esi + 0xEA78u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x18AA4u), LIFT_CODE_TOKEN_RVA(0x18AA2u))) { return; }
    cpu->eax = lift_load32(cpu->esi + 0xEA80u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x18AAFu), LIFT_CODE_TOKEN_RVA(0x18AADu))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018ABE;
    cpu->ecx = lift_load32(cpu->esi + 0xEA80u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x18ABEu), LIFT_CODE_TOKEN_RVA(0x18ABCu))) { return; }
    label_00018ABE:
    cpu->edx = lift_load32(cpu->esi + 0xEA80u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x18AC7u), LIFT_CODE_TOKEN_RVA(0x18AC5u))) { return; }
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(2)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418AD6u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418AD6u));
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018AF0;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00018AF0;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418AEBu));
    label_00018AF0:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418AF0u));
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(3)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store16(cpu->esi + 0xEAA4u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418B0Du)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418B0Du));
    cpu->esp += 8u;
    label_00018B10:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418B20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) == (uint8_t)(0u)) goto label_00018B9F;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418B32u));
    cpu->eax = lift_load32(cpu->esi + 0xEAA0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00018B93;
    cpu->ecx = lift_load32(cpu->esi + 0xEA68u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x418B53u));
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x418B5Au));
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00018B93;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xEAA0u))) goto label_00018B87;
    cpu->eax = lift_load32(cpu->esi + 0xEA9Cu);
    cpu->edx = 0x13880u;
    cpu->edx -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x418B7Eu));
    cpu->esp += 0xCu;
    label_00018B87:
    lift_store32(cpu->esi + 0xEAA0u, (uint64_t)(lift_load32(cpu->esi + 0xEAA0u)) - (uint64_t)(cpu->edi) - (uint64_t)(0u));
    lift_store32(cpu->esi + 0xEA90u, (uint64_t)(lift_load32(cpu->esi + 0xEA90u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    label_00018B93:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418B98u));
    cpu->edi = lift_pop32(cpu);
    label_00018B9F:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418BE4u));
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    cpu->ebp = cpu->eax & 0xFFFFu;
    cpu->ecx = 0x13880u;
    cpu->ecx -= lift_load32(cpu->esi + 0xEAA0u);
    cpu->edi = cpu->ebp;
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edi)) goto label_00018C4F;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: send buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418C1Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418C1Cu));
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018C3E;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00018C3E;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418C39u));
    label_00018C3E:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418C3Eu));
    lift_store8(cpu->esi + 0xEAA5u, 0u);
    goto label_00018D2B;
    label_00018C4F:
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x418C4Fu));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00018C61;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFCu;
    ++cpu->eax;
    label_00018C61:
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
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x418CBEu));
    cpu->eax = 4u;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00018CFF;
    cpu->ecx = lift_load32(cpu->esi + 0xEA9Cu);
    cpu->edx = lift_load32(cpu->esi + 0xEAA0u);
    cpu->edx += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x28u)) & 0xFFFFu);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00018CF0:
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(((int8_t)(lift_load8(cpu->edx + cpu->eax)))) & 0xFFFFu);
    ++cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00018CF0;
    goto label_00018D04;
    label_00018CFF:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x28u)) & 0xFFFFu);
    label_00018D04:
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0xEAB4u)) & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0xEAA0u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) ^ (uint64_t)((cpu->ecx & 0xFFFFu)))) & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 0xEA9Cu);
    lift_store16(cpu->eax + cpu->ecx + 2u, cpu->edx & 0xFFFFu);
    lift_store32(cpu->esi + 0xEAA0u, (uint64_t)(lift_load32(cpu->esi + 0xEAA0u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0xEAB8u, (uint64_t)(lift_load32(cpu->esi + 0xEAB8u)) + 1u);
    label_00018D2B:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418D30u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418D85u)); sfera_sub_00418A20(cpu, LIFT_CODE_TOKEN_VA(0x418D85u));
    cpu->ecx = lift_load32(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, 0x3Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418D97u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x418D97u));
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418DA6u)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x418DA6u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00418DD0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x418E20u));
    lift_push32(cpu, 0x54u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    cpu->ecx = 0xEA60u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418E3Bu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x418E3Bu));
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xEA88u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x16u, 1u);
    lift_store8(cpu->esp + 0x17u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001918D;
    label_00018E58:
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) != (uint8_t)(0u)) goto label_00018E68;
    lift_push32(cpu, 0xAu);
    goto label_0001910A;
    label_00018E68:
    cpu->edi = 0xEA60u;
    cpu->edi -= cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(1u)) goto label_00018E9B;
    if ((uint8_t)(lift_load8(cpu->esp + 0x16u)) != (uint8_t)(1u)) goto label_00018F30;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: local rcv buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418E8Eu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418E8Eu));
    cpu->esp += 8u;
    lift_store8(cpu->esp + 0x16u, 0u);
    goto label_00018F30;
    label_00018E9B:
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    lift_store8(cpu->esp + 0x2Au, 1u);
    lift_store32(cpu->esp + 0x144u, cpu->eax);
    lift_store32(cpu->esp + 0x140u, 1u);
    lift_native_call(cpu, native_function_address32(&::select), LIFT_CODE_TOKEN_VA(0x418ECBu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0001911F;
    cpu->ecx = lift_load32(cpu->esi + 0xEA68u);
    cpu->eax = (uint32_t)(cpu->esp + 0x12Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x418EE8u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00018F30;
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ebx + cpu->ebp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::recv), LIFT_CODE_TOKEN_VA(0x418EFFu));
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x418F06u));
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00019139;
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00019155;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00018F30;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esi + 0xEA8Cu, (uint64_t)(lift_load32(cpu->esi + 0xEA8Cu)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    label_00018F26:
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00018F30:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418F8Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418F8Cu));
    cpu->ecx = g_sfera_directplay_runtime.transport.mode;
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x190u);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418FACu)); sfera_sub_00418BB0(cpu, LIFT_CODE_TOKEN_VA(0x418FACu));
    g_sfera_network_runtime.initialization_result = (uint32_t)(1u);
    lift_store32(cpu->esi + 0xEA6Cu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x418FBCu));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0x3E8u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->edx;
    lift_store16(cpu->esi + 0xEAB2u, cpu->edx & 0xFFFFu);
    goto label_00019088;
    label_00018FDB:
    cpu->edx = 0x1F4u;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != (uint16_t)((cpu->edx & 0xFFFFu))) goto label_0001902B;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418FEAu));
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x418FF0u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0xEAACu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0001900C;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0001900C:
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (3.0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419017u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x419017u));
    lift_store32(cpu->esi + 0xEAA8u, cpu->eax);
    lift_store8(cpu->esi + 0xEAB0u, 1u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    goto label_00019082;
    label_0001902B:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x419038u));
    cpu->ecx = lift_load32(cpu->esi + 0xEA60u);
    cpu->eax = 0xEA60u;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x23Cu, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_000190A5;
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0x23u, 1u);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x419064u));
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0xEA60u, (uint64_t)(lift_load32(cpu->esi + 0xEA60u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x23Cu, 0xFFFFFFFFu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    label_00019082:
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0x19082u));
    label_00019088:
    cpu->eax = 0xEA60u;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->ebp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x419095u));
    cpu->esp += 0xCu;
    cpu->ebx -= cpu->edi;
    goto label_00018F26;
    label_000190A5:
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) != (uint8_t)(1u)) goto label_000190C3;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: rcv buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4190BBu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4190BBu));
    cpu->esp += 8u;
    lift_store8(cpu->esp + 0x17u, 0u);
    label_000190C3:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_store32(cpu->esp + 0x240u, 0xFFFFFFFFu);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0x190D3u));
    label_000190D9:
    cpu->edi = native_function_address32(&::GetTickCount);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x190E1u), LIFT_CODE_TOKEN_RVA(0x190DFu))) { return; }
    cpu->eax -= lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3E8u)) goto label_00019108;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x190EEu), LIFT_CODE_TOKEN_RVA(0x190ECu))) { return; }
    cpu->edx = lift_load32(cpu->esi + 0xEA8Cu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0xEA98u, cpu->edx);
    lift_store32(cpu->esi + 0xEA8Cu, 0u);
    label_00019108:
    lift_push32(cpu, 0xFu);
    label_0001910A:
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x41910Au));
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) != (uint8_t)(1u)) goto label_00018E58;
    goto label_0001918D;
    label_0001911F:
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41911Fu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------ERROR: select, err=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419134u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419134u));
    cpu->esp += 0xCu;
    goto label_00019183;
    label_00019139:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------LOST CONNECTION, err=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store8(cpu->esi + 0xEAA5u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419150u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419150u));
    cpu->esp += 0xCu;
    goto label_00019183;
    label_00019155:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------CLOSE CONNECTION, err=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_store8(cpu->esi + 0xEAA5u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41916Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41916Cu));
    cpu->esp += 0xCu;
    goto label_00019183;
    label_00019171:
    lift_push32(cpu, (uintptr_t)"-------------------------IN(ERROR): (limit connections)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419180u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419180u));
    cpu->esp += 8u;
    label_00019183:
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    label_0001918D:
    lift_push32(cpu, (uintptr_t)"Rcv Thread exit\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41919Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41919Cu));
    cpu->esp += 8u;
    cpu->edi = 0u;
    lift_push32(cpu, 0x120u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0xEA94u, cpu->edi);
    lift_store32(cpu->esi + 0xEA98u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4191BEu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4191BEu));
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0xEA68u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000191DD;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000191DD;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x4191D8u));
    label_000191DD:
    lift_store32(cpu->esi + 0xEA68u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4191E3u));
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x234u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x22Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x110u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetTickCount);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19231u), LIFT_CODE_TOKEN_RVA(0x1922Fu))) { return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19237u), LIFT_CODE_TOKEN_RVA(0x19235u))) { return; }
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1923Du), LIFT_CODE_TOKEN_RVA(0x1923Bu))) { return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19243u), LIFT_CODE_TOKEN_RVA(0x19241u))) { return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x419247u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0x1388u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->esi = lift_load32(cpu->esp + 0x120u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xEA88u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = (uint32_t)(cpu->edx + 0x7D0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000193BE;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::EnterCriticalSection);
    label_00019276:
    if ((uint8_t)(lift_load8(cpu->esi + 0xEAA5u)) != (uint8_t)(0u)) goto label_00019286;
    lift_push32(cpu, 0xAu);
    goto label_000193AA;
    label_00019286:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19288u), LIFT_CODE_TOKEN_RVA(0x19286u))) { return; }
    cpu->eax -= lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3E8u)) goto label_000192C1;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19295u), LIFT_CODE_TOKEN_RVA(0x19293u))) { return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x192A0u), LIFT_CODE_TOKEN_RVA(0x1929Eu))) { return; }
    cpu->edx = lift_load32(cpu->esi + 0xEA90u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    lift_store32(cpu->esi + 0xEA94u, cpu->edx);
    lift_store32(cpu->esi + 0xEA90u, 0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0x192BBu));
    label_000192C1:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x192C3u), LIFT_CODE_TOKEN_RVA(0x192C1u))) { return; }
    cpu->eax -= lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0xFu)) goto label_00019306;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x192CEu), LIFT_CODE_TOKEN_RVA(0x192CCu))) { return; }
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4192D9u)); sfera_sub_00418B20(cpu, LIFT_CODE_TOKEN_VA(0x4192D9u));
    cpu->eax = 0xC350u;
    if ((uint16_t)(lift_load16(cpu->esi + 0xEAB2u)) <= (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00019306;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = 1u;
    lift_push32(cpu, 0x258u);
    lift_store16(cpu->esi + 0xEAB2u, cpu->ecx & 0xFFFFu);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x19306u)); sfera_sub_00418BB0(cpu, LIFT_CODE_TOKEN_RVA(0x19306u));
    label_00019306:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19308u), LIFT_CODE_TOKEN_RVA(0x19306u))) { return; }
    cpu->eax -= lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0xBB8u)) goto label_00019367;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19315u), LIFT_CODE_TOKEN_RVA(0x19313u))) { return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x19320u), LIFT_CODE_TOKEN_RVA(0x1931Eu))) { return; }
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19322u), LIFT_CODE_TOKEN_RVA(0x19320u))) { return; }
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xEAB0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esi + 0xEAACu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001933B;
    lift_store32(cpu->esi + 0xEAA8u, (uint64_t)(lift_load32(cpu->esi + 0xEAA8u)) + (uint64_t)(0xBB8u) + (uint64_t)(0u));
    label_0001933B:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x419340u));
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x1F4u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi + 0xEAB0u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419360u)); sfera_sub_00418BB0(cpu, LIFT_CODE_TOKEN_VA(0x419360u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x19367u)); sfera_sub_00418B20(cpu, LIFT_CODE_TOKEN_RVA(0x19367u));
    label_00019367:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19369u), LIFT_CODE_TOKEN_RVA(0x19367u))) { return; }
    cpu->eax -= lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_000193A8;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x419371u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0x2710u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ebp = (uint32_t)(cpu->edx + 0xBB8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x19387u), LIFT_CODE_TOKEN_RVA(0x19385u))) { return; }
    cpu->edx = lift_load32(cpu->esi + 0xEAB8u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x2BCu); lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x193A8u)); sfera_sub_00418BB0(cpu, LIFT_CODE_TOKEN_RVA(0x193A8u));
    label_000193A8:
    lift_push32(cpu, 4u);
    label_000193AA:
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x4193AAu));
    if ((uint8_t)(lift_load8(cpu->esi + 0xEA88u)) != (uint8_t)(1u)) goto label_00019276;
    cpu->ebx = lift_pop32(cpu);
    label_000193BE:
    lift_push32(cpu, (uintptr_t)"Snd Thread exit\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4193CDu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4193CDu));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x110u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004193E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1A8u;
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00019410;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019716;
    label_00019410:
    if ((uint8_t)(lift_load8(cpu->edi + 0xEAA4u)) != (uint8_t)(1u)) goto label_0001943B;
    cpu->eax = lift_load32(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------ERROR: ALREADY Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419431u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419431u));
    cpu->esp += 0x10u;
    cpu->eax = 0u;
    goto label_00019716;
    label_0001943B:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1B8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419454u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419454u));
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x102u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x419461u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019479;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41946Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(1)--init connect manager (%d '%s'), error=%d\n");
    goto label_000194A3;
    label_00019479:
    lift_push32(cpu, 6u); lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x41947Fu));
    lift_store32(cpu->edi + 0xEA68u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000194B8;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41948Fu));
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x419496u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2)--init connect manager (%d '%s'), error=%d\n");
    label_000194A3:
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4194ADu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4194ADu));
    cpu->esp += 0x14u;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019715;
    label_000194B8:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s'), skt=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4194CCu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4194CCu));
    cpu->eax = lift_load32(cpu->edi + 0xEA68u);
    cpu->esp += 0x14u;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, 6u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, 1u);
    lift_native_call(cpu, native_function_address32(&::setsockopt), LIFT_CODE_TOKEN_VA(0x4194E9u));
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0001950D;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4194F4u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2_1)--init connect manager (%d), error=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41950Au)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41950Au));
    cpu->esp += 0x10u;
    label_0001950D:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') - no delay res = %d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41951Fu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41951Fu));
    cpu->esp += 0x14u;
    cpu->ecx = 2u;
    lift_push32(cpu, cpu->ebp);
    lift_store16(cpu->esp + 0x18u, cpu->ecx & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x41952Du));
    lift_push32(cpu, cpu->esi);
    lift_store16(cpu->esp + 0x1Au, cpu->eax & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419538u));
    lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0001955E;
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419543u));
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x41954Du));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(1) (%d '%s'), skt=%d, adr='%s'\n");
    goto label_00019586;
    label_0001955E:
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x41955Eu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000196E4;
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x419577u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(2) (%d '%s'), skt=%d, adr='%s'\n");
    label_00019586:
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419590u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419590u));
    cpu->edx = lift_load32(cpu->edi + 0xEA68u);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::connect), LIFT_CODE_TOKEN_VA(0x4195A1u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000195FB;
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x4195AAu));
    cpu->edi = lift_load32(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4195B2u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_1)--init connect manager (%d '%s') \n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195CAu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195CAu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_2)--init connect manager (%d '%s'), errno=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195DCu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195DCu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_3)--init connect manager (%d '%s'), lastError=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195EEu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195EEu));
    cpu->esp += 0x38u;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4195F1u));
    goto label_00019711;
    label_000195FB:
    cpu->eax = (uint32_t)(cpu->edi + 0xEA74u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00418DD0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_store8(cpu->edi + 0xEA88u, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x419615u));
    lift_store32(cpu->edi + 0xEA70u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00019638;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419625u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(5)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019638:
    cpu->ebx = native_function_address32(&::SetThreadPriority);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x19643u), LIFT_CODE_TOKEN_RVA(0x19641u))) { return; }
    cpu->ecx = (uint32_t)(cpu->edi + 0xEA7Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00419220)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x419656u));
    lift_store32(cpu->edi + 0xEA78u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00019679;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419666u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(6)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019679:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x1967Eu), LIFT_CODE_TOKEN_RVA(0x1967Cu))) { return; }
    cpu->edx = (uint32_t)(cpu->edi + 0xEA84u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004189B0)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x419691u));
    lift_store32(cpu->edi + 0xEA80u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000196B1;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4196A1u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(7)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_000196B1:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x196B6u), LIFT_CODE_TOKEN_RVA(0x196B4u))) { return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x4196BBu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(3) (%d '%s'), skt=%d, adr='%s'\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4196D4u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4196D4u));
    cpu->esp += 0x18u;
    lift_store16(cpu->edi + 0xEAA4u, 0x101u);
    cpu->eax = 0u;
    goto label_00019714;
    label_000196E4:
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4196E4u));
    cpu->ecx = lift_load32(cpu->edi + 0xEA68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x4196F2u));
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4196F7u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(3)--init connect manager (%d '%s'), error=%d\n");
    label_00019704:
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41970Eu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41970Eu));
    cpu->esp += 0x14u;
    label_00019711:
    cpu->eax |= 0xFFFFFFFFu;
    label_00019714:
    cpu->ebx = lift_pop32(cpu);
    label_00019715:
    cpu->ebp = lift_pop32(cpu);
    label_00019716:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1A8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    (void)cpu;
    label_00019740:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    cpu->edi = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x1974Bu), LIFT_CODE_TOKEN_RVA(0x19749u))) { return; }
    cpu->eax = lift_load32(cpu->esi + 0xEA60u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(2u)) goto label_0001975F;
    cpu->edi = lift_load16(cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edi)) goto label_0001975F;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_0001975F:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x419764u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x197C6u)); sfera_sub_00433400(cpu, LIFT_CODE_TOKEN_RVA(0x197C6u));
    label_000197C6:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x197CDu), LIFT_CODE_TOKEN_RVA(0x197CBu))) { return; }
    cpu->edx = 0xEA60u;
    cpu->edx -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4197DAu));
    lift_store32(cpu->esi + 0xEA60u, (uint64_t)(lift_load32(cpu->esi + 0xEA60u)) - (uint64_t)(cpu->edi) - (uint64_t)(0u));
    cpu->esp += 0xCu;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4197EEu));
    goto label_00019740;
    label_000197F9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xEA60u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41981Bu));
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0xEA60u, 0u);
    lift_store32(cpu->esi + 0xEA64u, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419840(LiftCpu* cpu, uint32_t stop_address) {
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
    label_00019885:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_0001988F;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_000198DE;
    label_0001988F:
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_00019897;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_000198DE;
    label_00019897:
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_0001989F;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_000198DE;
    label_0001989F:
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
    label_000198DE:
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    label_000198E1:
    ++cpu->edx;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->esi)) goto label_00019885;
    label_000198E6:
    lift_store8(cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000198FC:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    label_00019901:
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000198E6;
    lift_store8(cpu->ecx, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419920(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419952u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x419952u));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0001997D;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00019960:
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    ++cpu->eax;
    lift_store32(cpu->ecx + cpu->edx, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00019960;
    label_0001997D:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419990(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000199C4:
    if ((uint32_t)(lift_load32(cpu->edx)) == (uint32_t)(0u)) goto label_00019A23;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = cpu->ebp;
    if ((uint32_t)(cpu->eax) < (uint32_t)(4u)) goto label_000199EB;
    label_000199D7:
    cpu->ebx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00019A1F;
    cpu->eax -= 4u;
    cpu->ecx += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000199D7;
    label_000199EB:
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019AB8;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi))) goto label_00019A1F;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_00019AB8;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi + 1u))) goto label_00019A1F;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(2u)) goto label_00019AB8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 2u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(lift_load8(cpu->edi + 2u))) goto label_00019AB8;
    label_00019A1F:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_00019A23:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->edx += cpu->ecx;
    cpu->ebp += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000199C4;
    label_00019A35:
    cpu->edi = 0u;
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00019A6A;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->ebx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 4u);
    cpu->eax = cpu->edx;
    label_00019A54:
    cpu->ebp = lift_load32(cpu->eax + cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + cpu->ebx))) goto label_00019A62;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->edi = cpu->eax;
    label_00019A62:
    ++cpu->ecx;
    cpu->eax += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00019A54;
    label_00019A6A:
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
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x419A8Eu));
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->edx);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->edi + cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x19AA7u), LIFT_CODE_TOKEN_RVA(0x19AA5u))) { return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00019AB8:
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 4u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->ecx);
    lift_store32(cpu->esp, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00019BA3;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::rand);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_00019AF5:
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00019B8D;
    (void)cpu;
    label_00019B00:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x19B02u), LIFT_CODE_TOKEN_RVA(0x19B00u))) { return; }
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
    lift_native_call(cpu, native_function_address32(&::SetPixel), LIFT_CODE_TOKEN_VA(0x419B79u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->eax)) goto label_00019B00;
    cpu->ecx = cpu->esi;
    label_00019B8D:
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00019AF5;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00019BA3:
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x419BBBu));
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_VA(0x419BC5u));
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_VA(0x419BCFu));
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx + 4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x19BDEu), LIFT_CODE_TOKEN_RVA(0x19BDCu))) { return; }
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00499F50(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419BF0(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x19CA5u), LIFT_CODE_TOKEN_RVA(0x19CA3u))) { return; }
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
    label_00019CD0:
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x19CE5u), LIFT_CODE_TOKEN_RVA(0x19CE3u))) { return; }
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00019CD0;
    cpu->ebp = lift_pop32(cpu);
    label_00019CED:
    cpu->ebx = lift_pop32(cpu);
    label_00019CEE:
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x50u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x19CFDu), LIFT_CODE_TOKEN_RVA(0x19CFBu))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419D10(LiftCpu* cpu, uint32_t stop_address) {
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
    label_00019D52:
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x400u)) goto label_00019D66;
    cpu->edx = 0x400u;
    label_00019D66:
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi, cpu->ebx);
    lift_store8(cpu->ebp + 0xBu, cpu->ebx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->eax)) goto label_00019D7C;
    cpu->ecx = cpu->eax;
    label_00019D7C:
    cpu->eax = 0x20u;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00019D93;
    label_00019D88:
    cpu->eax += cpu->eax;
    cpu->edx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00019D88;
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    label_00019D93:
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetDC), LIFT_CODE_TOKEN_VA(0x419D97u));
    cpu->edi = cpu->eax;
    lift_store32(cpu->ebp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_00019DB9;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFFEFu, cpu->eax & 0xFFu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFEFu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x19DB9u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x19DB9u));
    label_00019DB9:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleDC), LIFT_CODE_TOKEN_VA(0x419DBAu));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00019DDA;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFEEu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->ebp + 0xFFFFFFEEu, cpu->eax & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x19DDAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x19DDAu));
    label_00019DDA:
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleBitmap), LIFT_CODE_TOKEN_VA(0x419DE3u));
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00019E03;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFEDu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->ebp + 0xFFFFFFEDu, cpu->eax & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x19E03u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x19E03u));
    label_00019E03:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_VA(0x419E05u));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->ebp + 0xCu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419E1Du)); sfera_sub_00499EF0(cpu, LIFT_CODE_TOKEN_VA(0x419E1Du));
    cpu->ebx = 1u;
    cpu->edx = (uint32_t)(cpu->ebx + 0x4Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"Bitmap.cpp";
    lift_store8(cpu->ebp + 0xBu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419E32u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x419E32u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419E39u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x419E39u));
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019E5E;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x16u); lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419E5Cu)); sfera_sub_004DA880(cpu, LIFT_CODE_TOKEN_VA(0x419E5Cu));
    goto label_00019E60;
    label_00019E5E:
    cpu->eax = 0u;
    label_00019E60:
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 0u);
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00019E7D;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ebp + 0xFFFFFFECu, cpu->eax & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x19E7Du)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x19E7Du));
    label_00019E7D:
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x419E85u));
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419E95u)); sfera_sub_00419AD0(cpu, LIFT_CODE_TOKEN_VA(0x419E95u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419E9Cu)); sfera_sub_00419BF0(cpu, LIFT_CODE_TOKEN_VA(0x419E9Cu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419EB0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019EC0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_RVA(0x19EBAu));
    label_00019EC0:
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019ED1;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_RVA(0x19ECBu));
    label_00019ED1:
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00019EDF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_RVA(0x19ED9u));
    label_00019EDF:
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_00019F09;
    cpu->edx = 0x62u;
    cpu->ecx = (uint32_t)(uintptr_t)"Bitmap.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419EF3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x419EF3u));
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00019F09;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419F00u)); sfera_sub_004DA4D0(cpu, LIFT_CODE_TOKEN_VA(0x419F00u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419F06u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x419F06u));
    cpu->esp += 4u;
    label_00019F09:
    if ((uint8_t)(lift_load8(cpu->ebp + 0xBu)) == (uint8_t)(0u)) goto label_00019F1E;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x19F1Eu)); sfera_sub_00499F50(cpu, LIFT_CODE_TOKEN_RVA(0x19F1Eu));
    label_00019F1E:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419F27u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x419F27u));
    lift_trap(cpu, 0x419F27u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419F44u)); sfera_sub_00419D10(cpu, LIFT_CODE_TOKEN_VA(0x419F44u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419F66u)); sfera_sub_00419D10(cpu, LIFT_CODE_TOKEN_VA(0x419F66u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00419F70(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A010(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A090(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001A0A6;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0001A0A6:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_blood_effect_instance;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A0C0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_0001A0E1:
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
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0001A104:
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
    label_0001A130:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x40u);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41A139u));
    cpu->edi = native_function_address32(&::rand);
    cpu->esp += 0xCu;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1A149u), LIFT_CODE_TOKEN_RVA(0x1A147u))) { return; }
    lift_store32(cpu->esp + 0x78u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x78u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A16Eu)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x41A16Eu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x20u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A17Bu)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x41A17Bu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x1A18Bu), LIFT_CODE_TOKEN_RVA(0x1A189u))) { return; }
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
    label_0001A274:
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
    label_0001A48A:
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0001A531;
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = cpu->edi;
    cpu->eax += 8u;
    cpu->edx -= cpu->esi;
    label_0001A4A3:
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
    label_0001A531:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp + 4u, cpu->edi);
    lift_store32(cpu->eax + 0x12848u, (uint64_t)(lift_load32(cpu->eax + 0x12848u)) + 1u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001A549:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0001A54B:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x5Cu;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x12848u)) != (uint32_t)(cpu->ebp)) goto label_0001A595;
    lift_store_f32(cpu->esi + 0x1284Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001A595:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x9ECu);
    cpu->edi = 5u;
    cpu->edx |= 0xFFFFFFFFu;
    label_0001A5A4:
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
    label_0001A5EA:
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
    label_0001A620:
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
    label_0001A666:
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
    label_0001A6AC:
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
    label_0001A6F2:
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
    label_0001A738:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A779u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x41A779u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A7D5u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x41A7D5u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A82Eu)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x41A82Eu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A83Cu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x41A83Cu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A84Au)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x41A84Au));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A859u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x41A859u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A869u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x41A869u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A879u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x41A879u));
    cpu->ecx = 0xBB8u;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A887u)); sfera_sub_0044F240(cpu, LIFT_CODE_TOKEN_VA(0x41A887u));
    lift_x87_push(cpu, 255.0);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    cpu->esi += 0xCu;
    label_0001A898:
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
    label_0001A90B:
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
    label_0001A93D:
    cpu->ebp = 0u;
    label_0001A93F:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->esi += 0x9E0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x1Eu)) goto label_0001A898;
    goto label_0001A963;
    label_0001A959:
    lift_store32(cpu->esp + 0x18u, 0xBB8u);
    cpu->ebp = 0u;
    label_0001A963:
    cpu->ecx = g_sfera_window_runtime.render_vertex_buffer;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A97Cu)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x41A97Cu));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A9A5u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x41A9A5u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_04, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04)) + (uint64_t)(0xBB8u) + (uint64_t)(0u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A9BEu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x41A9BEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41A9CDu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x41A9CDu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1A9DDu)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_RVA(0x1A9DDu));
    label_0001A9DD:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041A9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xE0u;
    cpu->eax = g_sfera_blood_effect_instance;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x12848u)), r=(uint64_t)(0x1Eu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xF8u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0001ACD0;
    if ((uint32_t)(lift_load32(cpu->edi + 0x28u)) == (uint32_t)(1u)) goto label_0001AA3A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown classID for blood spot effect.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AA31u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x41AA31u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AA37u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x41AA37u));
    cpu->esp += 8u;
    label_0001AA3A:
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x41AA3Au));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AA6Eu)); sfera_sub_00426160(cpu, LIFT_CODE_TOKEN_VA(0x41AA6Eu));
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
    label_0001AA98:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0001AA9E:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AB16u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x41AB16u));
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
    label_0001AB3D:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    goto label_0001AB49;
    label_0001AB45:
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001AB49:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    ++cpu->ebx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ebp += 0x50u;
    cpu->edi += 0xCu;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->esi)) goto label_0001AB76;
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    goto label_0001AA98;
    label_0001AB65:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0001ACD0;
    label_0001AB70:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0001AB76:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41ACA0u)); sfera_sub_0046F280(cpu, LIFT_CODE_TOKEN_VA(0x41ACA0u));
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle)) == (uint32_t)(0u)) goto label_0001ACD0;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0001ACD0;
    cpu->edi = (uint32_t)(cpu->esp + 0x74u);
    label_0001ACB1:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    cpu->ecx = g_sfera_blood_effect_instance;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41ACCAu)); sfera_sub_0041A0C0(cpu, LIFT_CODE_TOKEN_VA(0x41ACCAu));
    cpu->edi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001ACB1;
    label_0001ACD0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esp += 0xE0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041ACF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store_f32(cpu->esi + 0x1284Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = 0x136u;
    std::construct_at(reinterpret_cast<BloodEffListener*>(cpu->esi));
    lift_store32(cpu->esi + 4u, 0x40u);
    lift_store32(cpu->esi + 0x12848u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AD1Eu)); sfera_sub_0042AA90(cpu, LIFT_CODE_TOKEN_VA(0x41AD1Eu));
    cpu->ecx = (uint32_t)(uintptr_t)"fx_bspot";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AD28u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x41AD28u));
    lift_push32(cpu, 0x12840u);
    lift_store32(cpu->esi + 0x12850u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41AD39u));
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AD50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    if ((uint32_t)(g_sfera_blood_effect_instance) == (uint32_t)(0u)) goto label_0001AD97;
    lift_push32(cpu, 0x9Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AD8Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x41AD8Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AD94u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x41AD94u));
    cpu->esp += 0x10u;
    label_0001AD97:
    cpu->edx = 0x9Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41ADA6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41ADA6u));
    lift_push32(cpu, 0x12854u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41ADB0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x41ADB0u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001ADDF;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41ADCAu)); sfera_sub_0041ACF0(cpu, LIFT_CODE_TOKEN_VA(0x41ADCAu));
    g_sfera_blood_effect_instance = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001ADDF:
    cpu->eax = 0u;
    g_sfera_blood_effect_instance = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AE00(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(g_sfera_blood_effect_instance) != (uint32_t)(0u)) goto label_0001AE26;
    lift_push32(cpu, 0xA7u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AE1Du)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x41AE1Du));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AE23u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x41AE23u));
    cpu->esp += 0x10u;
    label_0001AE26:
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0xA8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\BloodEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AE36u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41AE36u));
    cpu->ecx = g_sfera_blood_effect_instance;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001AE50;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AE47u)); sfera_sub_00429990(cpu, LIFT_CODE_TOKEN_VA(0x41AE47u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AE4Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41AE4Du));
    cpu->esp += 4u;
    label_0001AE50:
    g_sfera_blood_effect_instance = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AE60(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041AEE0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_0001AF1F:
    cpu->edx = 0x73u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1AF2Eu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1AF2Eu));
    label_0001AF2E:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AF64u)); sfera_sub_0047EC40(cpu, LIFT_CODE_TOKEN_VA(0x41AF64u));
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AF72u)); sfera_sub_0047ED30(cpu, LIFT_CODE_TOKEN_VA(0x41AF72u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AF79u)); sfera_sub_0045A9C0(cpu, LIFT_CODE_TOKEN_VA(0x41AF79u));
    cpu->esi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AF8Du)); sfera_sub_0047ED10(cpu, LIFT_CODE_TOKEN_VA(0x41AF8Du));
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0x30686373u)) goto label_0001AF9F;
    cpu->ecx = (uint32_t)(uintptr_t)"preload_model: wrong file format";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1AF9Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x1AF9Fu));
    label_0001AF9F:
    cpu->edi = lift_load32(cpu->esi + 8u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    cpu->eax += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->eax);
    cpu->ecx = 0x20u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0001AFCA;
    cpu->esi = cpu->edi;
    label_0001AFB6:
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0001AFC4;
    if ((uint32_t)(cpu->edx) == (uint32_t)(7u)) goto label_0001AFC4;
    cpu->ecx += lift_load32(cpu->eax + 8u);
    label_0001AFC4:
    cpu->eax += 0xCu;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001AFB6;
    label_0001AFCA:
    lift_push32(cpu, 0x83u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41AFD9u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x41AFD9u));
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
    label_0001B011:
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0001B035;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(7u)) goto label_0001B035;
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax += lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41B02Au));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp += 0xCu;
    label_0001B035:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1B069u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1B069u));
    label_0001B069:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    label_0001B06C:
    cpu->eax += 0xCu;
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE8u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xFFFFFFE8u, v); }
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001B011;
    label_0001B079:
    cpu->ebx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->edi = lift_load32(cpu->ebx);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->edi);
    cpu->ebx += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B08Cu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x41B08Cu));
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0001B132;
    label_0001B09E:
    cpu->edx = (int8_t)(lift_load8(cpu->ebx));
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edi = 0u;
    ++cpu->ebx;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->edx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0001B10E;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    label_0001B0B1:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->edx += lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x41B0BCu));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0001B104;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE8u)) + (uint64_t)(0x1Eu) + (uint64_t)(0u));
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->eax))) goto label_0001B0B1;
    goto label_0001B10E;
    label_0001B0D7:
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    goto label_0001B06C;
    label_0001B0DF:
    lift_store32(cpu->esi, cpu->ebx);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    cpu->edx += cpu->ebx;
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    goto label_0001B06C;
    label_0001B0F6:
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx += lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ecx);
    goto label_0001B06C;
    label_0001B104:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u), cpu->edi & 0xFFFFu);
    label_0001B10E:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0001B11F;
    cpu->ecx = (uint32_t)(uintptr_t)"Match for bone name not found";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1B11Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x1B11Fu));
    label_0001B11F:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ebx += lift_load32(cpu->ebp + 0xFFFFFFDCu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE0u))) goto label_0001B09E;
    label_0001B132:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001B18D;
    cpu->ebx += 0x20u;
    label_0001B145:
    cpu->edi = lift_load32(cpu->ebx);
    cpu->eax = lift_load8(cpu->ebx + 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->edi &= 0xFFu;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0001B15F;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0001B16C;
    label_0001B15F:
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 759476206789";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B169u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x41B169u));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    label_0001B16C:
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
    label_0001B18D:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_RVA(0x1B191u));
    label_0001B197:
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B1E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0001B24F;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    label_0001B1F4:
    cpu->eax = lift_load32(cpu->esi + 0x4F44u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax + 0x24u)) == (uint32_t)(cpu->ebp)) goto label_0001B242;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0001B20C;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u))) goto label_0001B21B;
    label_0001B20C:
    cpu->edx = 0xFFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1B21Bu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1B21Bu));
    label_0001B21B:
    cpu->ecx = lift_load32(cpu->esi + 0x4F44u);
    cpu->ecx = lift_load32(cpu->edi + cpu->ecx + 0x24u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B242;
    lift_push32(cpu, 0x100u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B238u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41B238u));
    cpu->edx = lift_load32(cpu->esi + 0x4F44u);
    lift_store32(cpu->edi + cpu->edx + 0x24u, cpu->ebp);
    label_0001B242:
    ++cpu->ebx;
    cpu->edi += 0x2Cu;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x4F48u))) goto label_0001B1F4;
    cpu->edi = lift_pop32(cpu);
    label_0001B24F:
    cpu->ecx = lift_load32(cpu->esi + 0x4F44u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B26E;
    lift_push32(cpu, 0x189u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B268u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41B268u));
    lift_store32(cpu->esi + 0x4F44u, cpu->ebp);
    label_0001B26E:
    cpu->ecx = lift_load32(cpu->esi + 0xB0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B28D;
    lift_push32(cpu, 0x18Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B287u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41B287u));
    lift_store32(cpu->esi + 0xB0u, cpu->ebp);
    label_0001B28D:
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B2AC;
    lift_push32(cpu, 0x18Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B2A6u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41B2A6u));
    lift_store32(cpu->esi + 0xECu, cpu->ebp);
    label_0001B2AC:
    cpu->ecx = lift_load32(cpu->esi + 0x4F4Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B2CB;
    lift_push32(cpu, 0x18Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B2C5u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41B2C5u));
    lift_store32(cpu->esi + 0x4F4Cu, cpu->ebp);
    label_0001B2CB:
    cpu->ecx = lift_load32(cpu->esi + 0x4F50u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0001B2EA;
    lift_push32(cpu, 0x18Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B2E4u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x41B2E4u));
    lift_store32(cpu->esi + 0x4F50u, cpu->ebp);
    label_0001B2EA:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B2F0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixRotationQuaternion), LIFT_CODE_TOKEN_VA(0x41B33Eu));
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
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41B372u));
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0001B3A3;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0001B380:
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(cpu->ebx)) goto label_0001B39E;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1B39Eu)); sfera_sub_0041B2F0(cpu, LIFT_CODE_TOKEN_RVA(0x1B39Eu));
    label_0001B39E:
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0001B380;
    label_0001B3A3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B3C0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_0001B446:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x64u)) goto label_0001B455;
    lift_store32(cpu->esp + 0x84u, 2u);
    label_0001B455:
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixRotationQuaternion), LIFT_CODE_TOKEN_VA(0x41B45Fu));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    label_0001B479:
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    cpu->eax += lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixMultiply), LIFT_CODE_TOKEN_VA(0x41B495u));
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0001B4D8;
    label_0001B4A0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1B4D3u)); sfera_sub_0041B3C0(cpu, LIFT_CODE_TOKEN_RVA(0x1B4D3u));
    label_0001B4D3:
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0001B4A0;
    label_0001B4D8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 0x24u; cpu->eip = stop_address; return;
    label_0001B4ED:
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_0001B455;
    label_0001B4F6:
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x14u));
    cpu->ecx += cpu->ebx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixRotationQuaternion), LIFT_CODE_TOKEN_VA(0x41B50Fu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    goto label_0001B479;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 0x144u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->ecx + 0x4F3Cu, 0u);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B560(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001B5A5:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B5B0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41B96Au)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x41B96Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x6Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041B980(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BA00(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BA49u)); sfera_sub_0041AEE0(cpu, LIFT_CODE_TOKEN_VA(0x41BA49u));
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001BA59;
    lift_store32(cpu->ebp + 0x20u, 0x30u);
    goto label_0001BA7C;
    label_0001BA59:
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x30u)) goto label_0001BA63;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x39u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001BA7C;
    label_0001BA63:
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x61u)) goto label_0001BA6D;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x7Au), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0001BA7C;
    label_0001BA6D:
    cpu->edx = 0x2F6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1BA7Cu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1BA7Cu));
    label_0001BA7C:
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->esi + 0x4F44u);
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x2Cu); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edi = lift_load32(cpu->edx + cpu->ecx + 0x24u);
    cpu->ebx = lift_load32(cpu->edi + 0x1Cu);
    cpu->esi = lift_load32(cpu->edi + 0xCu);
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BA9Bu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x41BA9Bu));
    cpu->ecx = cpu->esp;
    cpu->edx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0001BCA7;
    cpu->ebx = lift_load32(cpu->ebp + 0x14u);
    lift_x87_push(cpu, 0.9900000095367432);
    cpu->ecx += 4u;
    label_0001BAB6:
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
    label_0001BC92:
    ++cpu->edx;
    cpu->esi += 0x28u;
    cpu->ecx += 0x20u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x1Cu))) goto label_0001BAB6;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001BCA7:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1BCCDu)); sfera_sub_0048D390(cpu, LIFT_CODE_TOKEN_RVA(0x1BCCDu));
    label_0001BCCD:
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_0001BE0A;
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x39u)) goto label_0001BCE3;
    cpu->eax += 0xFFFFFFD0u;
    goto label_0001BCE6;
    label_0001BCE3:
    cpu->eax += 0xFFFFFFA9u;
    label_0001BCE6:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 4u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0001BD09;
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0001BD09;
    cpu->edx = 0x335u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1BD09u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1BD09u));
    label_0001BD09:
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BD13u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x41BD13u));
    cpu->ecx = lift_load32(cpu->edi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BD1Bu)); sfera_sub_0044EFE0(cpu, LIFT_CODE_TOKEN_VA(0x41BD1Bu));
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001BE0A;
    cpu->ecx = lift_load32(cpu->edi + 0x1Cu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41BD2Fu));
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BD4Bu)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x41BD4Bu));
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001BD61;
    cpu->esi = 0u;
    label_0001BD61:
    if ((uint32_t)(lift_load32(cpu->ebp + 0x18u)) != (uint32_t)(0u)) goto label_0001BD6A;
    cpu->esi |= 4u;
    label_0001BD6A:
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->eax + 6u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BD78u)); sfera_sub_0044F0F0(cpu, LIFT_CODE_TOKEN_VA(0x41BD78u));
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 6u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x41BD89u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BDA6u)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x41BDA6u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BDE9u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x41BDE9u));
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 6u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edx);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1Cu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.timing_accumulator, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_0001BE0A:
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x24u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x4Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_push32(cpu, 0x44u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.699999988079071));
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.30000001192092896));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41BE4Bu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BEC9u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x41BEC9u));
    cpu->esp += 0x4Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BEE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x4Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_push32(cpu, 0x44u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.699999988079071));
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.30000001192092896));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41BF0Bu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BF59u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x41BF59u));
    cpu->esp += 0x4Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BF85u)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x41BF85u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"models\\textures\\wf00.dds";
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001BFA4;
    lift_store8(cpu->esp + 0x10u, 0x6Du);
    label_0001BFA4:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_0001BFA7:
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(9u)) goto label_0001BFB5;
    cpu->eax = (uint32_t)(cpu->ebx + 0x30u);
    lift_store8(cpu->esp + 0x16u, cpu->eax & 0xFFu);
    goto label_0001BFBC;
    label_0001BFB5:
    cpu->ecx = (uint32_t)(cpu->ebx + 0x57u);
    lift_store8(cpu->esp + 0x16u, cpu->ecx & 0xFFu);
    label_0001BFBC:
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BFC6u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x41BFC6u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0001BFA7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41BFD0u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x41BFD0u));
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041BFF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C005u)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x41C005u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"models\\textures\\wr00.dds";
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C024;
    lift_store8(cpu->esp + 0x10u, 0x6Du);
    label_0001C024:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_0001C027:
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(9u)) goto label_0001C035;
    cpu->eax = (uint32_t)(cpu->ebx + 0x30u);
    lift_store8(cpu->esp + 0x16u, cpu->eax & 0xFFu);
    goto label_0001C03C;
    label_0001C035:
    cpu->ecx = (uint32_t)(cpu->ebx + 0x57u);
    lift_store8(cpu->esp + 0x16u, cpu->ecx & 0xFFu);
    label_0001C03C:
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C046u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x41C046u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0001C027;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C050u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x41C050u));
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C070(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(lift_load32(cpu->esp + 4u)) != (uint32_t)(0u)) goto label_0001C07C;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001C07C:
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x39u)) goto label_0001C092;
    cpu->eax -= 0x30u;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x74D4u);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001C092:
    cpu->eax -= 0x57u;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x74D4u);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C1B0(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C1F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0001C204;
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C204u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x1C204u));
    label_0001C204:
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0001C213;
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C213u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1C213u));
    label_0001C213:
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C220(LiftCpu* cpu, uint32_t stop_address) {
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
    label_0001C24B:
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    label_0001C253:
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
    label_0001C271:
    cpu->edx += lift_load32(cpu->eax);
    cpu->esi += lift_load32(cpu->eax + 4u);
    cpu->eax += 8u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C271;
    label_0001C27C:
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0001C28C;
    cpu->eax = lift_load32(cpu->ebx + 0x18u);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    cpu->edi += lift_load32(cpu->esp + 0x20u);
    label_0001C28C:
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
    label_0001C2B0:
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0xFFFFFFFFu)) goto label_0001C2CE;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C2CEu)); sfera_sub_0041B2F0(cpu, LIFT_CODE_TOKEN_RVA(0x1C2CEu));
    label_0001C2CE:
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx))) goto label_0001C2B0;
    goto label_0001C37E;
    label_0001C2D8:
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_0001C2F5;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x14u))) goto label_0001C2F5;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0001C2F5;
    cpu->edx = lift_load32(cpu->ebx + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u)))) goto label_0001C301;
    label_0001C2F5:
    cpu->eax = 0u;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    label_0001C301:
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
    label_0001C320:
    cpu->edx += lift_load32(cpu->eax);
    cpu->esi += lift_load32(cpu->eax + 4u);
    cpu->eax += 8u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C320;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    label_0001C333:
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0001C33F;
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->edi += cpu->eax;
    label_0001C33F:
    cpu->esi += cpu->edx;
    cpu->edi += cpu->esi;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0001C37E;
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0001C350:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C379u)); sfera_sub_0041B3C0(cpu, LIFT_CODE_TOKEN_RVA(0x1C379u));
    label_0001C379:
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx))) goto label_0001C350;
    label_0001C37E:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0001C3CC;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(0u)) goto label_0001C3CC;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(0u)) goto label_0001C3CC;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0001C3CC;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edi = cpu->edi;
    label_0001C3A0:
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x1Cu))) goto label_0001C3C4;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x20u))) goto label_0001C3C4;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x24u))) goto label_0001C3C4;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x28u))) goto label_0001C3C4;
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->esi += 8u;
    cpu->ecx = 0x10u;
    cpu->edi = cpu->edx;
    lift_movs32(cpu, 1u);
    label_0001C3C4:
    ++cpu->eax;
    cpu->edx += 0x40u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebx))) goto label_0001C3A0;
    label_0001C3CC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x24u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C3E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0001C3FB;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong handle: set_char_param\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C3F6u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x41C3F6u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001C3FB:
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0001C40F;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C40Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1C40Fu));
    label_0001C40F:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x236u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C428u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x41C428u));
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x144u)) <= (int32_t)(uint32_t)(0u)) goto label_0001C442;
    cpu->edx = 0x237u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C442u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1C442u));
    label_0001C442:
    cpu->eax = lift_load32(cpu->edi + 0x144u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0001C453;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->eax;
    goto label_0001C4A3;
    label_0001C453:
    cpu->esi = 0u;
    cpu->eax = (uint32_t)(cpu->ebx + 0x4F54u);
    label_0001C460:
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0u)) goto label_0001C477;
    ++cpu->esi;
    cpu->eax += 0x18u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x190u)) goto label_0001C460;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    goto label_0001C47F;
    label_0001C477:
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x190u)) goto label_0001C48E;
    label_0001C47F:
    cpu->edx = 0x245u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C48Eu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x1C48Eu));
    label_0001C48E:
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    lift_store32(cpu->edi + 0x144u, cpu->ecx);
    lift_store32(cpu->ebx + ((uint32_t)(cpu->edx) * 8u) + 0x4F54u, cpu->edi);
    label_0001C4A3:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C4D4u)); sfera_sub_00479FD0(cpu, LIFT_CODE_TOKEN_VA(0x41C4D4u));
    goto label_0001C4F3;
    label_0001C4D6:
    cpu->ecx = cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0001C4E9;
    lift_push32(cpu, 3u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C4E7u)); sfera_sub_00479FD0(cpu, LIFT_CODE_TOKEN_VA(0x41C4E7u));
    goto label_0001C4F3;
    label_0001C4E9:
    cpu->edx = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C4F3u)); sfera_sub_004593C0(cpu, LIFT_CODE_TOKEN_RVA(0x1C4F3u));
    label_0001C4F3:
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
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041C520(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0001C53D;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong handle: get_char_param\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C536u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_RVA(0x1C536u));
    label_0001C536:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0001C53D:
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0001C551;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1C551u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x1C551u));
    label_0001C551:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, 0x26Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\CharMdl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41C568u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x41C568u));
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
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
