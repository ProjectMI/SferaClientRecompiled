#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6C70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->edi)) goto label_000A76EF;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(cpu->edi)) goto label_000A76EF;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6C99u)); sfera_sub_004A6C00(cpu, LIFT_CODE_TOKEN_VA(0x4A6C99u));
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4A6CA5u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6CB4u)); sfera_sub_004A6480(cpu, LIFT_CODE_TOKEN_VA(0x4A6CB4u));
    cpu->ebx = lift_load32(cpu->esp + 0xE8u);
    cpu->ebp = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)" ";
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6CD8u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A6CD8u));
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(2u)) goto label_000A6CE2;
    lift_store32(cpu->esp + 0x38u, (uint64_t)(lift_load32(cpu->esp + 0x38u)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000A6CE2:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000A6FF8;
    cpu->ebx = cpu->edi;
    label_000A6CF5:
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 8u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = (uint32_t)(cpu->edi + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A6D46;
    cpu->eax = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000A6D15;
    lift_store32(cpu->ecx + 0x94u, 0xFFFFFFFFu);
    label_000A6D15:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6D1Eu)); sfera_sub_004A6480(cpu, LIFT_CODE_TOKEN_VA(0x4A6D1Eu));
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->edi + 0x90u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A6FD6;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A6D33:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A6D33;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A6FD6;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_000A6D46:
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(8u)) goto label_000A6D5A;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    cpu->ebx += cpu->eax;
    label_000A6D5A:
    if ((uint32_t)(cpu->ecx) != (uint32_t)(9u)) goto label_000A6D68;
    cpu->ecx = lift_load16(cpu->edi + 0x98u);
    cpu->ebx += cpu->ecx;
    label_000A6D68:
    cpu->eax = lift_load32(cpu->edi + 0x90u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A6F99;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A6D80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A6D80;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A6F99;
    cpu->ecx = 0x27u;
    cpu->edi = (uint32_t)(cpu->esp + 0x40u);
    lift_movs32(cpu, 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A6DA0:
    cpu->edi = lift_load32(cpu->esp + 0xE8u);
    cpu->esi = lift_load32(cpu->esp + 0xC8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6DC3u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A6DC3u));
    if ((uint32_t)(cpu->edi) >= (uint32_t)(2u)) goto label_000A6DCD;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000A6DCD:
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx += cpu->ebx;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0xE0u))) goto label_000A6F87;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    label_000A6DE4:
    cpu->eax = 0u;
    g_sfera_hypertext_scratch_runtime.token_text[0] = (uint8_t)((cpu->eax & 0xFFu));
    cpu->edi = cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000A6E24;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.token_text[0];
    cpu->ecx -= cpu->esi;
    label_000A6DF8:
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x20u)) goto label_000A6E08;
    lift_store8(cpu->ecx + cpu->esi, 0x20u);
    ++cpu->esi;
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0u)) goto label_000A6DF8;
    label_000A6E08:
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_000A6E24;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A6E10:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_000A6E24;
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.token_text[0]), cpu->ecx & 0xFFu);
    ++cpu->esi;
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0u)) goto label_000A6E10;
    label_000A6E24:
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xECu);
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.token_text[0]), 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.token_text[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6E48u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A6E48u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xE8u)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A6E5D;
    cpu->ecx -= 2u;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    label_000A6E5D:
    cpu->eax = lift_load32(cpu->esp + 0xE0u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_000A6E75;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esp + 0xC8u))) goto label_000A6E75;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000A6EC6;
    label_000A6E75:
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebx);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000A6F19;
    cpu->eax = lift_load32(cpu->esp + 0xE8u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(2u)) goto label_000A6E95;
    cpu->eax = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    goto label_000A6E97;
    label_000A6E95:
    cpu->eax = 0u;
    label_000A6E97:
    cpu->eax += cpu->ecx;
    cpu->ebx += cpu->eax;
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0u)) goto label_000A6DE4;
    lift_push32(cpu, 0x2E6u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6EB8u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A6EB8u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6EBEu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A6EBEu));
    cpu->esp += 0x10u;
    goto label_000A6DE4;
    label_000A6EC6:
    lift_store8(cpu->esi, 0u);
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    ++cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6EDEu)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A6EDEu));
    cpu->edx = 0x1A41A40u;
    cpu->edx -= lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A7154;
    lift_store32(cpu->ebp + 4u, (uint64_t)(lift_load32(cpu->ebp + 4u)) + 1u);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6F03u)); sfera_sub_004A6480(cpu, LIFT_CODE_TOKEN_VA(0x4A6F03u));
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0xC8u, cpu->esi);
    lift_store32(cpu->esp + 0x40u, 0u);
    goto label_000A6DA0;
    label_000A6F19:
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esp + 0xC8u))) goto label_000A6F2D;
    lift_store32(cpu->esp + 0xC8u, 0u);
    label_000A6F2D:
    cpu->esi = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6F41u)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A6F41u));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A7154;
    ++cpu->ecx;
    lift_store32(cpu->ebp + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000A6F6A;
    lift_store8(cpu->edi, 0u);
    ++cpu->edi;
    label_000A6F6A:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6F73u)); sfera_sub_004A6480(cpu, LIFT_CODE_TOKEN_VA(0x4A6F73u));
    cpu->ebx = 0u;
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0xC8u, cpu->edi);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    goto label_000A6DA0;
    label_000A6F87:
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6F93u)); sfera_sub_004A6B90(cpu, LIFT_CODE_TOKEN_VA(0x4A6F93u));
    cpu->ebx += lift_load32(cpu->esp + 0x10u);
    goto label_000A6FD6;
    label_000A6F99:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 0x90u, 0u);
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6FB7u)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A6FB7u));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A7154;
    ++cpu->ecx;
    lift_store32(cpu->ebp + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    label_000A6FD6:
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx + 0x10u))) goto label_000A6CF5;
    cpu->ebx = lift_load32(cpu->esp + 0xE8u);
    cpu->edi = 0u;
    cpu->esi = cpu->ecx;
    label_000A6FF8:
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) <= (uint32_t)(cpu->edi)) goto label_000A73BD;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    label_000A7011:
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->ebx + 0x1Cu);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A7069;
    label_000A7027:
    if ((uint32_t)(lift_load32(cpu->eax + 0x90u)) != (uint32_t)(0u)) goto label_000A703C;
    cpu->edx = lift_load32(cpu->ebx + 0x1Cu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->esi + cpu->edx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_000A7027;
    label_000A703C:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A7069;
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(5u)) goto label_000A7069;
    cpu->ecx = lift_load32(cpu->eax + 0x90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000A7069;
    label_000A7052:
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A7069;
    lift_store32(cpu->eax + 0x90u, (uint64_t)(lift_load32(cpu->eax + 0x90u)) + 1u);
    cpu->edx = lift_load32(cpu->eax + 0x90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A7052;
    label_000A7069:
    cpu->eax = lift_load32(cpu->ebx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000A70D7;
    label_000A7080:
    cpu->ecx = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x90u)) != (uint32_t)(0u)) goto label_000A709A;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + cpu->ecx);
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000A7080;
    label_000A709A:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000A70D7;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 0x90u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A70B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A70B0;
    cpu->eax -= cpu->esi;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx + cpu->eax + 0xFFFFFFFFu)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A70CD;
    label_000A70C4:
    --cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A70CD;
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x20u)) goto label_000A70C4;
    label_000A70CD:
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) != (uint8_t)(0x20u)) goto label_000A70D7;
    lift_store8(cpu->ecx + 1u, 0u);
    label_000A70D7:
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->ebx + 0x28u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ebp = 0u;
    cpu->edi = 0u;
    lift_store8(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->eax)) goto label_000A710C;
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x94u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x1Cu, (((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u);
    label_000A710C:
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000A71D6;
    label_000A7118:
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_000A7127;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    label_000A7127:
    if ((uint32_t)(cpu->eax) != (uint32_t)(8u)) goto label_000A712F;
    cpu->ebp += lift_load32(cpu->esi + 0xCu);
    label_000A712F:
    if ((uint32_t)(cpu->eax) != (uint32_t)(9u)) goto label_000A7180;
    cpu->eax = lift_load16(cpu->esi + 0x98u);
    cpu->ebp += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A715F;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A716F;
    cpu->eax = lift_load16(cpu->esi + 0x9Au);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 0x28u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    goto label_000A7169;
    label_000A7154:
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A7154u), "std::length_error");
    label_000A715F:
    cpu->eax = lift_load16(cpu->esi + 0x9Au);
    cpu->eax -= lift_load32(cpu->ebx + 0x28u);
    label_000A7169:
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edi)) goto label_000A716F;
    cpu->edi = cpu->eax;
    label_000A716F:
    cpu->eax = lift_load16(cpu->esi + 0x9Au);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000A7180;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000A7180:
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A71C2;
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0u)) goto label_000A71C2;
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xECu);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A71A7u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A71A7u));
    if ((uint32_t)(lift_load32(cpu->esp + 0xE8u)) >= (uint32_t)(2u)) goto label_000A71B6;
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000A71B6:
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ebp += cpu->eax;
    lift_store32(cpu->esi + 0x94u, cpu->eax);
    label_000A71C2:
    cpu->ecx = lift_load32(cpu->ebx + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->edx + cpu->ecx);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000A7118;
    label_000A71D6:
    cpu->eax = lift_load32(cpu->ebx + 0x5Cu);
    cpu->ebx += 0x58u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A724C;
    cpu->edx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_000A724C;
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000A723C;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3FFFFFFEu)) goto label_000A742A;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000A723C;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->edx;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->ecx)) goto label_000A7225;
    cpu->ecx = 0u;
    goto label_000A7227;
    label_000A7225:
    cpu->ecx += cpu->edx;
    label_000A7227:
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A722D;
    cpu->ecx = cpu->eax;
    label_000A722D:
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    cpu->ebx += 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA723Cu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_RVA(0xA723Cu));
    label_000A723C:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A729F;
    cpu->edx = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->eax, cpu->ecx);
    goto label_000A729F;
    label_000A724C:
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000A7292;
    cpu->edx = lift_load32(cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3FFFFFFEu)) goto label_000A742A;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000A7292;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi = 0x3FFFFFFFu;
    cpu->esi -= cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000A7282;
    cpu->ecx = 0u;
    goto label_000A7284;
    label_000A7282:
    cpu->ecx += cpu->edx;
    label_000A7284:
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A728A;
    cpu->ecx = cpu->eax;
    label_000A728A:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA7292u)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_RVA(0xA7292u));
    label_000A7292:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A729F;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    label_000A729F:
    lift_store32(cpu->ebx + 4u, (uint64_t)(lift_load32(cpu->ebx + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000A7395;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0xD4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->esi = lift_load32(cpu->ebx + cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esp + 0x48u, cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0xD0u, cpu->edi);
    cpu->edi = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x4Cu, 6u);
    lift_store32(cpu->esp + 0xD8u, cpu->ebp);
    lift_store32(cpu->esp + 0xD4u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A730Eu)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A730Eu));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A7154;
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xE0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A7395;
    cpu->ecx = lift_load32(cpu->esp + 0xE4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(1u)) goto label_000A734B;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A7395;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000A734B:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->esi = lift_load32(cpu->ebx + cpu->eax);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x4Cu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7376u)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A7376u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A7154;
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    label_000A7395:
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edx + 0x20u))) goto label_000A7011;
    cpu->ebx = lift_load32(cpu->esp + 0xE8u);
    cpu->edi = 0u;
    cpu->esi = cpu->edx;
    label_000A73BD:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xE4u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A76DD;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) <= (uint32_t)(cpu->edi)) goto label_000A76DD;
    label_000A73E0:
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->esi = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->esi);
    cpu->ebp = 0u;
    cpu->edx = cpu->edi;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_store8(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000A76C7;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    label_000A7411:
    if ((uint32_t)(lift_load32(cpu->edx + 8u)) != (uint32_t)(6u)) goto label_000A7435;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx + 0x10u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = lift_load32(cpu->edx + 0x94u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A7435;
    lift_store8(cpu->esp + 0x1Cu, 1u);
    goto label_000A748D;
    label_000A742A:
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A742Au), "std::length_error");
    label_000A7435:
    cpu->ecx = lift_load32(cpu->edx + 0x90u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A748D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A748D;
    label_000A7445:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A7453;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A7445;
    goto label_000A748D;
    label_000A7453:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A748D;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A7460:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A747D;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + 1u);
    label_000A7468:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A7486;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000A7468;
    cpu->ebx = lift_load32(cpu->esp + 0xE8u);
    goto label_000A747E;
    label_000A747D:
    ++cpu->ecx;
    label_000A747E:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A7460;
    goto label_000A748D;
    label_000A7486:
    cpu->ebx = lift_load32(cpu->esp + 0xE8u);
    label_000A748D:
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000A7411;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000A76C7;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(0u)) goto label_000A76C7;
    if ((uint8_t)(lift_load8(cpu->esp + 0x1Cu)) != (uint8_t)(0u)) goto label_000A76C7;
    cpu->eax = lift_load32(cpu->esp + 0xE0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A74D4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A74D4:
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A74E6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A74E6:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A74FBu)); sfera_sub_004EED66(cpu, LIFT_CODE_TOKEN_VA(0x4A74FBu));
    lift_store16(cpu->esp + 0x24u, cpu->fpu_control);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x2Cu));
    lift_store64(cpu->esp + 0x2Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000A76C7;
    cpu->edi = cpu->edi;
    label_000A7540:
    cpu->esi = lift_load32(cpu->edi + 0x90u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000A76B9;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_000A76B9;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A76B9;
    label_000A7561:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A7572;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A7561;
    goto label_000A76B9;
    label_000A7572:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A76B9;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    label_000A7580:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A76A4;
    label_000A7588:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A7594;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000A7588;
    label_000A7594:
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->ecx = lift_load32(cpu->edi + 0x90u);
    lift_push32(cpu, 1u);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A75B1u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A75B1u));
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(2u)) goto label_000A75BB;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000A75BB:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    --cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) != (uint32_t)(cpu->eax)) goto label_000A75D4;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->edx -= lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    goto label_000A75D8;
    label_000A75D4:
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    label_000A75D8:
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_000A75ED;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(2u)) goto label_000A75FB;
    cpu->eax = lift_load32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    cpu->eax += cpu->eax;
    goto label_000A75FD;
    label_000A75ED:
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(2u)) goto label_000A75FB;
    cpu->eax = lift_load32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    goto label_000A75FD;
    label_000A75FB:
    cpu->eax = 0u;
    label_000A75FD:
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax += lift_load32(cpu->esp + 0x38u);
    cpu->ecx += cpu->edx;
    lift_store32(cpu->edi + 0x94u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A761D;
    cpu->eax = cpu->edx;
    goto label_000A7621;
    label_000A761D:
    cpu->eax -= lift_load32(cpu->esp + 0x1Cu);
    label_000A7621:
    lift_store32(cpu->edi + 0x94u, (uint64_t)(lift_load32(cpu->edi + 0x94u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + 1u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7644u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A7644u));
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(2u)) goto label_000A764E;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000A764E:
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_000A76AF;
    cpu->edi = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x4Cu, 0u);
    lift_store32(cpu->esp + 0xD4u, cpu->esi);
    lift_store32(cpu->esp + 0xD8u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7680u)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A7680u));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A7154;
    ++cpu->ecx;
    lift_store32(cpu->ebp + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edi = lift_load32(cpu->edi + 4u);
    goto label_000A76A5;
    label_000A76A4:
    ++cpu->esi;
    label_000A76A5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A7580;
    label_000A76AF:
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) == (uint32_t)(cpu->edx)) goto label_000A76C7;
    label_000A76B9:
    cpu->edi = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000A7540;
    label_000A76C7:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 0x20u))) goto label_000A73E0;
    label_000A76DD:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A76EF:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A7700(LiftCpu* cpu, uint32_t stop_address) {
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
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0xDD67C8u)) goto label_000A7743;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A7700u), "std::length_error");
    label_000A7743:
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx -= lift_load32(cpu->esi);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_000A77CB;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A776Au)); sfera_sub_004A6270(cpu, LIFT_CODE_TOKEN_VA(0x4A776Au));
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7786u)); sfera_sub_004A6440(cpu, LIFT_CODE_TOKEN_VA(0x4A7786u));
    cpu->ebx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ecx -= cpu->ebx;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000A77AD;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A77AAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A77AAu));
    cpu->esp += 4u;
    label_000A77AD:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x128u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x128u);
    cpu->eax += cpu->ecx;
    cpu->edi += cpu->ecx;
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_store32(cpu->esi, cpu->ecx);
    label_000A77CB:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A77DF(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A77E8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A77E8u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A77F4u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A77F4u));
    lift_trap(cpu, 0x4A77F4u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A7800(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    cpu->esi -= cpu->ebx;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    cpu->edx = 0xDD67C8u;
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->esi)) goto label_000A7836;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A7800u), "std::length_error");
    label_000A7836:
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000A787C;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0xDD67C8u;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000A7868;
    cpu->eax = 0u;
    goto label_000A786A;
    label_000A7868:
    cpu->eax += cpu->edx;
    label_000A786A:
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_000A7870;
    cpu->eax = cpu->esi;
    label_000A7870:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    sfera_sub_004A7700(cpu, stop_address); return;
    label_000A787C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A7890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi))) goto label_000A78C2;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A78B0:
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A78B8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A78B8u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi))) goto label_000A78B0;
    cpu->edi = lift_pop32(cpu);
    label_000A78C2:
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A78DDu)); sfera_sub_004A6AC0(cpu, LIFT_CODE_TOKEN_VA(0x4A78DDu));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A78F0(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->edi = 0u;
    lift_store32(cpu->esi, cpu->edi);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    lift_push32(cpu, 0xA4u);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7935u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A7935u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000A79CC;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    lift_store32(cpu->esi + 0x44u, cpu->edi);
    lift_store32(cpu->esi + 0x48u, cpu->edi);
    lift_store32(cpu->esi + 0x50u, 0xFF50A0A0u);
    lift_store32(cpu->esi + 0x54u, 0xFFFFFF00u);
    lift_store32(cpu->esi + 0x58u, cpu->edi);
    lift_store32(cpu->esi + 0x5Cu, cpu->edi);
    lift_store32(cpu->esi + 0x60u, cpu->edi);
    cpu->edx = 0xC4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_store8(cpu->esp + 0x28u, 3u);
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    lift_store32(cpu->esi + 0x24u, 0x64u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A799Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A799Cu));
    lift_push32(cpu, 0x190u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A79A6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A79A6u));
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A79B0u));
    cpu->esp += 0x10u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A79CC:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A79F6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A79F6u));
    lift_trap(cpu, 0x4A79F6u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A7A00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x20u, 3u);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->ebx)) goto label_000A7A53;
    cpu->edx = 0xD0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A48u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7A48u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A50u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7A50u));
    cpu->esp += 4u;
    label_000A7A53:
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->ebx)) goto label_000A7A73;
    cpu->edx = 0xD1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A67u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7A67u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A70u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7A70u));
    cpu->esp += 4u;
    label_000A7A73:
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->ebx)) goto label_000A7A93;
    cpu->edx = 0xD2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A87u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7A87u));
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A90u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7A90u));
    cpu->esp += 4u;
    label_000A7A93:
    cpu->ebp = lift_load32(cpu->esi + 0x10u);
    cpu->edi = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_000A7ABB;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A7AA0:
    if ((uint32_t)(lift_load32(cpu->edi + 8u)) != (uint32_t)(9u)) goto label_000A7AB5;
    cpu->ecx = lift_load32(cpu->edi + 0xA0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A7AB5;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA7AB5u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_RVA(0xA7AB5u));
    label_000A7AB5:
    cpu->edi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebp)) goto label_000A7AA0;
    label_000A7ABB:
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) == (uint32_t)(cpu->ebx)) goto label_000A7B48;
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x24u)) <= (uint32_t)(cpu->ebx)) goto label_000A7B2D;
    label_000A7AD0:
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u))) == (uint32_t)(cpu->ebx)) goto label_000A7B27;
    cpu->edx = 0xE2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7AE7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7AE7u));
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000A7B27;
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->edi))) goto label_000A7B16;
    label_000A7B03:
    cpu->ebx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B0Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7B0Bu));
    cpu->esp += 4u;
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000A7B03;
    cpu->ebx = 0u;
    label_000A7B16:
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B1Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7B1Eu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B24u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7B24u));
    cpu->esp += 8u;
    label_000A7B27:
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0x24u))) goto label_000A7AD0;
    label_000A7B2D:
    cpu->edx = 0xE4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B3Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7B3Cu));
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B45u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7B45u));
    cpu->esp += 4u;
    label_000A7B48:
    cpu->eax = lift_load32(cpu->esi + 0x58u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000A7B58;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B55u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7B55u));
    cpu->esp += 4u;
    label_000A7B58:
    lift_store32(cpu->esi + 0x58u, cpu->ebx);
    lift_store32(cpu->esi + 0x5Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x60u, cpu->ebx);
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000A7B71;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B6Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7B6Eu));
    cpu->esp += 4u;
    label_000A7B71:
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    lift_store32(cpu->esi + 0x48u, cpu->ebx);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000A7B8A;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B87u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7B87u));
    cpu->esp += 4u;
    label_000A7B8A:
    lift_store32(cpu->esi + 0x30u, cpu->ebx);
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000A7BBA;
    label_000A7BA8:
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7BB0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7BB0u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000A7BA8;
    label_000A7BBA:
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7BC3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7BC3u));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A7BE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ebx = lift_load32(cpu->ebp);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edx)) goto label_000A7C15;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_000A7C12;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000A7BF6:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebx;
    cpu->eax += 0x128u;
    cpu->ecx = 0x4Au;
    cpu->ebx += 0x128u;
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000A7BF6;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000A7C12:
    lift_store32(cpu->ebp + 4u, cpu->ebx);
    label_000A7C15:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A7C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2F8u;
    cpu->eax = lift_load32(cpu->esp + 0x300u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x300u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A80B2;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x188u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    cpu->esi = (uint32_t)(cpu->eax + cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7C65u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7C65u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7C6Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A7C6Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A7C72u));
    cpu->esp += 0x10u;
    cpu->edx = 0x18Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7C89u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7C89u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7C8Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A7C8Fu));
    lift_store32(cpu->edi + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->edi + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 0x14u, 0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_000A7CCA;
    label_000A7CB8:
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7CC0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A7CC0u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_000A7CB8;
    label_000A7CCA:
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x30u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edx)) goto label_000A7D04;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_000A7CFE;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A7CE0:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebp;
    cpu->eax += 0x128u;
    cpu->ecx = 0x4Au;
    cpu->ebp += 0x128u;
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000A7CE0;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_000A7CFE:
    cpu->ecx = (uint32_t)(cpu->edi + 0x30u);
    lift_store32(cpu->ecx + 4u, cpu->ebp);
    label_000A7D04:
    lift_push32(cpu, 0x1Eu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7D0Bu)); sfera_sub_004A7700(cpu, LIFT_CODE_TOKEN_VA(0x4A7D0Bu));
    cpu->ecx = lift_load32(cpu->edi + 0x5Cu);
    cpu->esi = (uint32_t)(cpu->edi + 0x58u);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000A7D36;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A7D28u));
    cpu->esp += 0xCu;
    cpu->ebp += cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->ebp);
    label_000A7D36:
    lift_push32(cpu, 0x64u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7D3Fu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4A7D3Fu));
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebp = lift_load32(cpu->edi + 0x40u);
    cpu->edx = lift_load32(cpu->edi + 0x44u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edx)) goto label_000A7D7A;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_000A7D74;
    label_000A7D56:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebp;
    cpu->eax += 0x128u;
    cpu->ecx = 0x4Au;
    cpu->ebp += 0x128u;
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000A7D56;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_000A7D74:
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_store32(cpu->ecx + 4u, cpu->ebp);
    label_000A7D7A:
    lift_push32(cpu, 0xAu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7D81u)); sfera_sub_004A7700(cpu, LIFT_CODE_TOKEN_VA(0x4A7D81u));
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0xA0u, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0xA4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7DADu)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A7DADu));
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000A7DC7;
    label_000A7DBC:
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A7DBCu), "std::length_error");
    label_000A7DC7:
    ++cpu->ecx;
    lift_store32(cpu->edi + 0x14u, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A809C;
    cpu->edi = cpu->edi;
    label_000A7DE0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A7DF3;
    label_000A7DE7:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A7DF3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000A7DE7;
    label_000A7DF3:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_000A7E00;
    ++cpu->ebp;
    goto label_000A8092;
    label_000A7E00:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A8086;
    label_000A7E08:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Cu)) goto label_000A806B;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7E1Du)); sfera_sub_004A5F10(cpu, LIFT_CODE_TOKEN_VA(0x4A7E1Du));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A805B;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = (uint32_t)(cpu->eax + cpu->ebp + 2u);
    lift_store32(cpu->esp + 0xA4u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A7F10;
    lift_push32(cpu, 0x128u);
    cpu->eax = (uint32_t)(cpu->esp + 0xB8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A7E4Eu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_000A7E60:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x20u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0xB4u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A7E60;
    cpu->ebx = (uint32_t)(cpu->edi + 0x30u);
    cpu->edi = lift_load32(cpu->ebx + 4u);
    lift_store8(cpu->esp + 0x1D8u, cpu->ecx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xB4u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_000A7EC4;
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edx)) goto label_000A7EC4;
    cpu->ecx -= cpu->eax;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000A7EB3;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA7EB3u)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA7EB3u));
    label_000A7EB3:
    cpu->edi = lift_load32(cpu->ebx + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x128u);
    cpu->esi += lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A7EE7;
    goto label_000A7EE0;
    label_000A7EC4:
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000A7ED2;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA7ED2u)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA7ED2u));
    label_000A7ED2:
    cpu->edi = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A7EE7;
    cpu->esi = (uint32_t)(cpu->esp + 0xB4u);
    label_000A7EE0:
    cpu->ecx = 0x4Au;
    lift_movs32(cpu, 1u);
    label_000A7EE7:
    lift_store32(cpu->ebx + 4u, (uint64_t)(lift_load32(cpu->ebx + 4u)) + (uint64_t)(0x128u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    label_000A7F10:
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(0xAu)) goto label_000A8012;
    if ((uint8_t)(lift_load8(cpu->esp + 0x20u)) != (uint8_t)(0x23u)) goto label_000A7F44;
    lift_push32(cpu, 0x80u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x25u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7F30u)); sfera_sub_004B9140(cpu, LIFT_CODE_TOKEN_VA(0x4A7F30u));
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1E4u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4A7F39u));
    cpu->esp += 0xCu;
    goto label_000A7F60;
    label_000A7F44:
    cpu->eax = 0u;
    label_000A7F50:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x20u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x1DCu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A7F50;
    label_000A7F60:
    cpu->edi = lift_load32(cpu->edi + 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1DCu);
    lift_store8(cpu->esp + 0x300u, 0u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000A7FBF;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ebx + 0x40u);
    cpu->ebx += 0x40u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1DCu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->ecx)) goto label_000A7FBF;
    cpu->ecx -= cpu->eax;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000A7FAE;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA7FAEu)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA7FAEu));
    label_000A7FAE:
    cpu->edi = lift_load32(cpu->ebx + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x128u);
    cpu->esi += lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A7FE9;
    goto label_000A7FE2;
    label_000A7FBF:
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx += 0x40u;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000A7FD4;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA7FD4u)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA7FD4u));
    label_000A7FD4:
    cpu->edi = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A7FE9;
    cpu->esi = (uint32_t)(cpu->esp + 0x1DCu);
    label_000A7FE2:
    cpu->ecx = 0x4Au;
    lift_movs32(cpu, 1u);
    label_000A7FE9:
    lift_store32(cpu->ebx + 4u, (uint64_t)(lift_load32(cpu->ebx + 4u)) + (uint64_t)(0x128u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    label_000A8012:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->eax, 0u);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    ++cpu->eax;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xA0u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A803Au)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A803Au));
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A7DBC;
    ++cpu->ecx;
    lift_store32(cpu->edi + 0x14u, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000A807B;
    label_000A805B:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_000A807A;
    label_000A806B:
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xAu)) goto label_000A807A;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_000A807A:
    ++cpu->ebp;
    label_000A807B:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A7E08;
    label_000A8086:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->eax, 0x20u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000A8092:
    if ((uint8_t)(lift_load8(cpu->ebp)) != (uint8_t)(0u)) goto label_000A7DE0;
    label_000A809C:
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4A80A8u));
    cpu->esp += 0xCu;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000A80B2:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2F8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A80D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x310u;
    cpu->eax = lift_load32(cpu->esp + 0x318u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x318u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->edi);
    --cpu->esi;
    cpu->edi = cpu->ecx;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000A815A;
    cpu->ecx = lift_load32(cpu->ebx + 0xCu);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A8120:
    cpu->eax = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A8128;
    cpu->eax = 0u;
    label_000A8128:
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000A812F;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    label_000A812F:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000A8155;
    cpu->eax = lift_load32(cpu->ebx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8155;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A8140:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A8140;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax -= cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebp = (uint32_t)(cpu->eax + cpu->ebp + 1u);
    label_000A8155:
    ++cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->esi)) goto label_000A8120;
    label_000A815A:
    cpu->edx = 0x1F9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    cpu->esi = (uint32_t)(cpu->ebp + cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A816Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A816Du));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8173u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A8173u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A817Au));
    cpu->esp += 0x10u;
    cpu->edx = 0x1FCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8191u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A8191u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8197u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A8197u));
    lift_store32(cpu->edi + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->edi + 0xCu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->edi + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->ebx + 4u, 0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->ebx))) goto label_000A81D5;
    label_000A81C4:
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A81CCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A81CCu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->ebx))) goto label_000A81C4;
    label_000A81D5:
    cpu->ebp = lift_load32(cpu->edi + 0x30u);
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    cpu->ebx = (uint32_t)(cpu->edi + 0x30u);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edx)) goto label_000A820D;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_000A820A;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A81F0:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebp;
    cpu->eax += 0x128u;
    cpu->ecx = 0x4Au;
    cpu->ebp += 0x128u;
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000A81F0;
    label_000A820A:
    lift_store32(cpu->ebx + 4u, cpu->ebp);
    label_000A820D:
    lift_push32(cpu, 0x1Eu);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8216u)); sfera_sub_004A7700(cpu, LIFT_CODE_TOKEN_VA(0x4A8216u));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->esi + 0x58u);
    cpu->ecx = lift_load32(cpu->esi + 0x5Cu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000A8243;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A8235u));
    cpu->esp += 0xCu;
    cpu->ebp += cpu->edi;
    lift_store32(cpu->esi + 0x5Cu, cpu->ebp);
    label_000A8243:
    lift_push32(cpu, 0x64u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x58u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A824Du)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4A824Du));
    cpu->edi = cpu->esi;
    cpu->ebp = lift_load32(cpu->edi + 0x40u);
    cpu->edx = lift_load32(cpu->edi + 0x44u);
    cpu->ebx = (uint32_t)(cpu->edi + 0x40u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edx)) goto label_000A8283;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_000A827C;
    label_000A8262:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebp;
    cpu->eax += 0x128u;
    cpu->ecx = 0x4Au;
    cpu->ebp += 0x128u;
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000A8262;
    label_000A827C:
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebx + 4u, cpu->ebp);
    label_000A8283:
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A828Cu)); sfera_sub_004A7700(cpu, LIFT_CODE_TOKEN_VA(0x4A828Cu));
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->ebp);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0xB8u, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0xBCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A82BBu)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A82BBu));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000A82D5;
    label_000A82CA:
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A82CAu), "std::length_error");
    label_000A82D5:
    ++cpu->ecx;
    lift_store32(cpu->ebp + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->ecx);
    --cpu->edx;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000A85DF;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A8300:
    cpu->eax = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A8308;
    cpu->eax = 0u;
    label_000A8308:
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000A8316;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    label_000A8316:
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A85C6;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_000A85C6;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A8342;
    label_000A8332:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A85BE;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000A8332;
    label_000A8342:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A85BE;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A8350:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Cu)) goto label_000A85A8;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8367u)); sfera_sub_004A5F10(cpu, LIFT_CODE_TOKEN_VA(0x4A8367u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A85A2;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esi + cpu->eax + 2u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0xBCu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A846D;
    lift_push32(cpu, 0x128u);
    cpu->edx = (uint32_t)(cpu->esp + 0xD0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A839Cu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_000A83B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x38u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0xCCu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A83B0;
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    cpu->edi = lift_load32(cpu->ebp + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCCu);
    lift_store8(cpu->esp + 0x1F0u, cpu->ecx & 0xFFu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000A841C;
    cpu->eax = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCCu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->ecx)) goto label_000A841C;
    cpu->ecx -= cpu->eax;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_000A840A;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA840Au)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA840Au));
    label_000A840A:
    cpu->edi = lift_load32(cpu->ebp + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x128u);
    cpu->esi += lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A843F;
    goto label_000A8438;
    label_000A841C:
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_000A842A;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA842Au)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA842Au));
    label_000A842A:
    cpu->edi = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A843F;
    cpu->esi = (uint32_t)(cpu->esp + 0xCCu);
    label_000A8438:
    cpu->ecx = 0x4Au;
    lift_movs32(cpu, 1u);
    label_000A843F:
    lift_store32(cpu->ebp + 4u, (uint64_t)(lift_load32(cpu->ebp + 4u)) + (uint64_t)(0x128u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->ecx -= lift_load32(cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    label_000A846D:
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) != (uint32_t)(0xAu)) goto label_000A855A;
    if ((uint8_t)(lift_load8(cpu->esp + 0x38u)) != (uint8_t)(0x23u)) goto label_000A84A1;
    lift_push32(cpu, 0x80u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Du);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A848Du)); sfera_sub_004B9140(cpu, LIFT_CODE_TOKEN_VA(0x4A848Du));
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1FCu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4A8496u));
    cpu->esp += 0xCu;
    goto label_000A84B3;
    label_000A84A1:
    cpu->eax = 0u;
    label_000A84A3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x38u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x1F4u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A84A3;
    label_000A84B3:
    cpu->edi = lift_load32(cpu->ebx + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1F4u);
    lift_store8(cpu->esp + 0x318u, 0u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000A850A;
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1F4u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->ecx)) goto label_000A850A;
    cpu->ecx -= cpu->eax;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000A84F9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA84F9u)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA84F9u));
    label_000A84F9:
    cpu->edi = lift_load32(cpu->ebx + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x128u);
    cpu->esi += lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A852D;
    goto label_000A8526;
    label_000A850A:
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000A8518;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA8518u)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA8518u));
    label_000A8518:
    cpu->edi = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A852D;
    cpu->esi = (uint32_t)(cpu->esp + 0x1F4u);
    label_000A8526:
    cpu->ecx = 0x4Au;
    lift_movs32(cpu, 1u);
    label_000A852D:
    lift_store32(cpu->ebx + 4u, (uint64_t)(lift_load32(cpu->ebx + 4u)) + (uint64_t)(0x128u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    label_000A855A:
    lift_store8(cpu->edi, 0u);
    cpu->esi = lift_load32(cpu->ebp);
    ++cpu->edi;
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0xB8u, cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A857Du)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A857Du));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000A82CA;
    ++cpu->ecx;
    lift_store32(cpu->ebp + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000A85B0;
    label_000A85A2:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    lift_store8(cpu->edi, cpu->edx & 0xFFu);
    goto label_000A85AA;
    label_000A85A8:
    lift_store8(cpu->edi, cpu->eax & 0xFFu);
    label_000A85AA:
    ++cpu->edi;
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    label_000A85B0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A8350;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    label_000A85BE:
    lift_store8(cpu->edi, 0x20u);
    ++cpu->edi;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    label_000A85C6:
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    ++cpu->edx;
    --cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000A8300;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_000A85DF:
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4A85EBu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x310u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8610(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x410u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8646u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A8646u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8650u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A8650u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A866E;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A866Au)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x4A866Au));
    cpu->esi = cpu->eax;
    goto label_000A8670;
    label_000A866E:
    cpu->esi = 0u;
    label_000A8670:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8684u)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x4A8684u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"hypertext");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8699u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4A8699u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A86D6;
    cpu->edx = 0x417u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86ACu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A86ACu));
    if ((uint32_t)(cpu->esi) == 0u) goto label_000A86C0;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86B7u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4A86B7u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86BDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A86BDu));
    cpu->esp += 4u;
    label_000A86C0:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A86D6:
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86E3u)); sfera_sub_004A80D0(cpu, LIFT_CODE_TOKEN_VA(0x4A86E3u));
    cpu->edx = 0x41Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86F2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A86F2u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_000A8706;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86FDu)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4A86FDu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8703u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A8703u));
    cpu->esp += 4u;
    label_000A8706:
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A8752;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8752;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A873Cu)); sfera_sub_004A7C20(cpu, LIFT_CODE_TOKEN_VA(0x4A873Cu));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA8752u)); sfera_sub_004A6C70(cpu, LIFT_CODE_TOKEN_RVA(0xA8752u));
    label_000A8752:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8760(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A8892;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->ebp);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->ebp = cpu->edx;
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A879A;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8792u)); sfera_sub_004A7BE0(cpu, LIFT_CODE_TOKEN_VA(0x4A8792u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A879A:
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->edi -= cpu->ecx;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ebp) > (uint32_t)(cpu->edi)) goto label_000A87F0;
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A87C4u)); sfera_sub_004A62D0(cpu, LIFT_CODE_TOKEN_VA(0x4A87C4u));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x128u);
    cpu->eax += lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A87F0:
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ebp) > (uint32_t)(cpu->eax)) goto label_000A884B;
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x128u);
    cpu->edi += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8826u)); sfera_sub_004A62D0(cpu, LIFT_CODE_TOKEN_VA(0x4A8826u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A883Fu)); sfera_sub_004A6400(cpu, LIFT_CODE_TOKEN_VA(0x4A883Fu));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A884B:
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A8858;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8855u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A8855u));
    cpu->esp += 4u;
    label_000A8858:
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8878u)); sfera_sub_004A6300(cpu, LIFT_CODE_TOKEN_VA(0x4A8878u));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A8890;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A888Du)); sfera_sub_004A6BE0(cpu, LIFT_CODE_TOKEN_VA(0x4A888Du));
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000A8890:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000A8892:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A88A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 4u)) == (uint32_t)(cpu->esi)) goto label_000A8A0D;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) == (uint32_t)(cpu->esi)) goto label_000A8A0D;
    if ((uint32_t)(lift_load32(cpu->edi + 0xCu)) == (uint32_t)(cpu->esi)) goto label_000A8A0D;
    cpu->edx = 0x4EFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A88F3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A88F3u));
    lift_push32(cpu, 0x68u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A88FAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A88FAu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000A8912;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8910u)); sfera_sub_004A78F0(cpu, LIFT_CODE_TOKEN_VA(0x4A8910u));
    cpu->esi = cpu->eax;
    label_000A8912:
    cpu->edx = 0x4F1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8929u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A8929u));
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8932u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A8932u));
    cpu->esp += 4u;
    cpu->edx = 0x4F2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8947u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A8947u));
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8950u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A8950u));
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->ebx = (uint32_t)(cpu->edi + 0x10u);
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_000A8978;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA8978u)); sfera_sub_004A7890(cpu, LIFT_CODE_TOKEN_RVA(0xA8978u));
    label_000A8978:
    cpu->eax = (uint32_t)(cpu->edi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8984u)); sfera_sub_004A8760(cpu, LIFT_CODE_TOKEN_VA(0x4A8984u));
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8990u)); sfera_sub_004A8760(cpu, LIFT_CODE_TOKEN_VA(0x4A8990u));
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A899Au)); sfera_sub_004A5E90(cpu, LIFT_CODE_TOKEN_VA(0x4A899Au));
    cpu->ebx = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A89DF;
    cpu->ebp = 9u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A89B0:
    cpu->edx = lift_load32(cpu->ecx + 0x90u);
    cpu->edx -= lift_load32(cpu->edi + 4u);
    cpu->edx += lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 0x90u, cpu->edx);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) != (uint32_t)(cpu->ebp)) goto label_000A89D7;
    cpu->edx = lift_load32(cpu->eax + 0xA0u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A89D7;
    lift_store32(cpu->edx + 0x8Cu, (uint64_t)(lift_load32(cpu->edx + 0x8Cu)) + 1u);
    label_000A89D7:
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_000A89B0;
    label_000A89DF:
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4A89EBu));
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8A09u)); sfera_sub_004A6C70(cpu, LIFT_CODE_TOKEN_VA(0x4A8A09u));
    cpu->eax = cpu->esi;
    goto label_000A8A0F;
    label_000A8A0D:
    cpu->eax = 0u;
    label_000A8A0F:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A8A66;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8A5Cu)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4A8A5Cu));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esi, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000A8A66:
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A8AAA;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8AA5u)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4A8AA5u));
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    label_000A8AAA:
    cpu->edx += lift_load32(cpu->edi + 0x30u);
    cpu->eax += lift_load32(cpu->edi + 0x34u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x258u, cpu->edx);
    lift_store32(cpu->esi + 0x25Cu, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 0x260u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A8AE3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_000A8AE3:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A8AEF;
    cpu->ecx = lift_load32(cpu->ecx + 0x264u);
    cpu->eax = 0u;
    goto label_000A8B11;
    label_000A8AEF:
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->ecx + 0x254u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A8B0A;
    cpu->eax = 0u;
    goto label_000A8B0E;
    label_000A8B0A:
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_000A8B0E:
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    label_000A8B11:
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A8B1B;
    lift_store32(cpu->edx, cpu->eax);
    label_000A8B1B:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8B25;
    lift_store32(cpu->eax, cpu->ecx);
    label_000A8B25:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esi + 0x270u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8B54u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4A8B54u));
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A8B77;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8B72u)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4A8B72u));
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    label_000A8B77:
    cpu->eax += lift_load32(cpu->edi + 0x34u);
    lift_x87_push(cpu, 0.0);
    cpu->edx += lift_load32(cpu->edi + 0x30u);
    lift_store32(cpu->esi + 0x25Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x25Cu);
    cpu->ecx += lift_load32(cpu->esi + 0x34u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esi + 0x258u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8BE3u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4A8BE3u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8C00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000A8C1D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A8C1D:
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0x1FFFFFFFu)) goto label_000A8C30;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A8C1Du), "std::length_error");
    label_000A8C30:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8C39u)); sfera_sub_00402BB0(cpu, LIFT_CODE_TOKEN_VA(0x4A8C39u));
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8C60;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8C60;
    cpu->edx = lift_load32(cpu->eax);
    label_000A8C60:
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->ecx += lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A8C89;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A8C89;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000A8C89:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A8CB7;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->esi -= cpu->eax;
    cpu->edi = cpu->edi;
    label_000A8CA0:
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000A8CA0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000A8CB7:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->esi);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A8CDCu));
    cpu->esp += 0xCu;
    cpu->eax += cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A8D6B;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A8D10:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(2u), 32u);
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000A8D25;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    label_000A8D25:
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->ebx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->ebx &= 3u;
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->esi)) goto label_000A8D3A;
    cpu->esi -= cpu->eax;
    label_000A8D3A:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u), cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    ++cpu->edx;
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x24u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A8D10;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000A8D6B:
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x20u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8D80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->ebx = cpu->edx;
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->edi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000A8DAB;
    label_000A8DA0:
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    cpu->eax = cpu->edi;
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_000A8DA0;
    label_000A8DAB:
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000A8E0A;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000A8E0A;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    label_000A8DC0:
    cpu->edx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u));
    cpu->edi = cpu->ebp;
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000A8DD0;
    cpu->edx = cpu->ecx;
    cpu->edi = cpu->edi;
    label_000A8DD0:
    cpu->esi = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000A8DF6;
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ebx) * 4u));
    cpu->edx += cpu->esi;
    goto label_000A8DFD;
    label_000A8DF6:
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->esi;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    label_000A8DFD:
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ebp)) goto label_000A8DD0;
    --cpu->eax;
    cpu->ebp -= 4u;
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000A8DC0;
    cpu->ebp = lift_pop32(cpu);
    label_000A8E0A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    cpu->ecx = 0x2762762u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->ecx -= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A8E64;
    lift_push32(cpu, (uint32_t)(uintptr_t)"deque<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A8E40u), "std::length_error");
    label_000A8E64:
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(8u)) goto label_000A8E72;
    cpu->ecx = 8u;
    label_000A8E72:
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ecx)) goto label_000A8E83;
    cpu->edx = 0x2762762u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edx)) goto label_000A8E83;
    cpu->ebp = cpu->ecx;
    label_000A8E83:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx + 0xCu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x15u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8E97u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A8E97u));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = cpu->eax;
    cpu->esi = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    cpu->eax = (uint32_t)(cpu->esi + cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax -= lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A8ECFu));
    cpu->eax += lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000A8F20;
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->edx = cpu->esi;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ebp;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A8EF5u));
    cpu->edx = cpu->eax;
    cpu->edx += lift_load32(cpu->esp + 0x20u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A8F14;
    cpu->ecx = cpu->esi;
    cpu->eax = 0u;
    cpu->edi = cpu->edx;
    lift_stos32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_000A8F14:
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A8F67;
    cpu->ecx = cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    goto label_000A8F63;
    label_000A8F20:
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp) * 4u));
    cpu->edx = cpu->edi;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A8F33u));
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->eax);
    cpu->esi -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A8F51u));
    cpu->esp += 0x18u;
    cpu->edi = (uint32_t)(cpu->esi + cpu->eax);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000A8F67;
    cpu->ecx = cpu->ebp;
    label_000A8F63:
    cpu->eax = 0u;
    lift_stos32(cpu, 1u);
    label_000A8F67:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8F79;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8F76u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A8F76u));
    cpu->esp += 4u;
    label_000A8F79:
    lift_store32(cpu->ebx + 8u, (uint64_t)(lift_load32(cpu->ebx + 8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A8FD9;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A8FC0:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8FCE;
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    label_000A8FCE:
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000A8FC0;
    cpu->esi = lift_pop32(cpu);
    label_000A8FD9:
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A8FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A9007;
    lift_push32(cpu, cpu->esi);
    (void)cpu;
    label_000A8FF0:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A8FF8;
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->esi);
    label_000A8FF8:
    cpu->ecx += 4u;
    cpu->eax += 4u;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000A8FF0;
    cpu->esi = lift_pop32(cpu);
    label_000A9007:
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x5Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x58u);
    cpu->ebp = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 0x248u);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A905Du)); sfera_sub_00431210(cpu, LIFT_CODE_TOKEN_VA(0x4A905Du));
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A9137;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A913D;
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    cpu->eax &= 0xFFu;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_x87_push(cpu, 0.75);
    cpu->edx = cpu->ecx;
    lift_store16(cpu->esp + 0x1Cu, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xC00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx &= 0xFFu;
    lift_store64(cpu->esp + 0x14u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    cpu->edx = cpu->ecx & 0xFFu;
    cpu->ecx &= 0xFF000000u;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store16(cpu->esp + 0x1Cu, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_store64(cpu->esp + 0x14u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store16(cpu->esp + 0x1Cu, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_store64(cpu->esp + 0x14u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax &= 0xFFu;
    cpu->esi |= cpu->eax;
    cpu->esi |= cpu->ecx;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    goto label_000A913D;
    label_000A9137:
    cpu->esi = lift_load32(cpu->ebp + 0x244u);
    label_000A913D:
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9149u)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4A9149u));
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    cpu->ebp = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A915Fu)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4A915Fu));
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0xFFFFFFFFu);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->edx);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A918Du)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4A918Du));
    cpu->edi = 0x10u;
    lift_store32(cpu->esp + 0x50u, 0u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->edi)) goto label_000A91A1;
    cpu->eax = lift_load32(cpu->eax);
    label_000A91A1:
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 4u)))));
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->eax + 0xDCu);
    cpu->ecx = lift_load8(cpu->eax + 0x8Cu);
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x18u), 32u);
    cpu->esi &= 0xFFFFFFu;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx |= cpu->esi;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx)))));
    cpu->ecx -= 2u;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A91D7u)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_VA(0x4A91D7u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x3Cu)) < (uint32_t)(cpu->edi)) goto label_000A91EA;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A91E7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A91E7u));
    cpu->esp += 4u;
    label_000A91EA:
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9210(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x58u);
    cpu->edi = lift_load32(cpu->esp + 0x54u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9258u)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4A9258u));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->edx + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A926Eu)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4A926Eu));
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 0xFFFFFFFFu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->edx);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A929Cu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4A929Cu));
    cpu->esi = 0x10u;
    lift_store32(cpu->esp + 0x4Cu, 0u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_000A92B0;
    cpu->eax = lift_load32(cpu->eax);
    label_000A92B0:
    cpu->edx = lift_load32(cpu->ebp + 0xDCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 4u)))));
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    lift_push32(cpu, 0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x18u), 32u);
    cpu->esp -= 8u;
    cpu->edx |= cpu->ecx;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load8(cpu->ebp + 0x8Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi)))));
    cpu->ecx -= 2u;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A92E6u)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_VA(0x4A92E6u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x38u)) < (uint32_t)(cpu->esi)) goto label_000A92F9;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A92F6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A92F6u));
    cpu->esp += 4u;
    label_000A92F9:
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9320(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(0u)) goto label_000A9355;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9337u)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4A9337u));
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000A9349;
    lift_store32(cpu->esi + 0xCu, 0u);
    label_000A9349:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A9355;
    lift_store32(cpu->esi + 0xCu, 0u);
    label_000A9355:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9360(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9391;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000A937A;
    cpu->eax -= cpu->ecx;
    label_000A937A:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9385u)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4A9385u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A9391;
    lift_store32(cpu->esi + 0xCu, 0u);
    label_000A9391:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A93A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A93C9;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A93B0:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A93BE;
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    label_000A93BE:
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000A93B0;
    cpu->esi = lift_pop32(cpu);
    label_000A93C9:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A93D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A93EF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A93EF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000A93F5;
    label_000A93EF:
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000A93FB;
    label_000A93F5:
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000A93FB:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A9413;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A9413;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000A9417;
    label_000A9413:
    cpu->edi = 0u;
    goto label_000A9419;
    label_000A9417:
    cpu->edi = lift_load32(cpu->eax);
    label_000A9419:
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A9433;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A9433;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A9433;
    cpu->ecx = lift_load32(cpu->eax);
    label_000A9433:
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A944Fu)); sfera_sub_004A8CF0(cpu, LIFT_CODE_TOKEN_VA(0x4A944Fu));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A947B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A947B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->esi, cpu->ecx);
    label_000A947B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9490(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edi)) goto label_000A94BB;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000A94C2;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A94ADu)); sfera_sub_004A8D80(cpu, LIFT_CODE_TOKEN_VA(0x4A94ADu));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A94BB:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A94C2:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A94D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 0x1B0u);
    cpu->eax = lift_load32(cpu->ebx + 0x1B4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 8u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000A9587;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000A957C;
    lift_push32(cpu, cpu->esi);
    label_000A9506:
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->edx)) goto label_000A9514;
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->ebp + 1u);
    goto label_000A956B;
    label_000A9514:
    cpu->esi = 0u;
    label_000A9516:
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A952Cu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A952Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9533u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A9533u));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A953B;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000A953B:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000A9547;
    cpu->eax -= cpu->edx;
    label_000A9547:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    --cpu->edx;
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->edx)) goto label_000A955F;
    ++cpu->esi;
    ++cpu->ebp;
    goto label_000A9516;
    label_000A955F:
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_000A956B:
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_000A9506;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A957C:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A9587:
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A95A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(0u)) goto label_000A96C9;
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1B4u))) goto label_000A96C9;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x268u)) <= (uint32_t)(cpu->ebp)) goto label_000A96C8;
    lift_push32(cpu, cpu->edi);
    label_000A95D5:
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(lift_load32(cpu->esp + 0x40u))) goto label_000A96C7;
    cpu->edi = lift_load32(cpu->esi + 0x260u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000A9645;
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9607u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A9607u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A960Eu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A960Eu));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A9616;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000A9616:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000A9622;
    cpu->eax -= cpu->edx;
    label_000A9622:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = lift_load32(cpu->esi + 0x264u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    --cpu->edx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_000A96B3;
    ++cpu->ecx;
    lift_store32(cpu->esi + 0x264u, cpu->ecx);
    goto label_000A96B3;
    label_000A9645:
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9664u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A9664u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A966Bu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A966Bu));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A9673;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000A9673:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000A967F;
    cpu->eax -= cpu->edx;
    label_000A967F:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = lift_load32(cpu->esi + 0x264u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    --cpu->edx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_000A96A2;
    ++cpu->ecx;
    lift_store32(cpu->esi + 0x264u, cpu->ecx);
    goto label_000A96B3;
    label_000A96A2:
    --cpu->edi;
    lift_store32(cpu->esi + 0x260u, cpu->edi);
    lift_store32(cpu->esi + 0x264u, 0u);
    label_000A96B3:
    lift_store32(cpu->esi + 0x268u, (uint64_t)(lift_load32(cpu->esi + 0x268u)) - 1u);
    ++cpu->ebp;
    if ((uint32_t)(lift_load32(cpu->esi + 0x268u)) > (uint32_t)(0u)) goto label_000A95D5;
    label_000A96C7:
    cpu->edi = lift_pop32(cpu);
    label_000A96C8:
    cpu->ebp = lift_pop32(cpu);
    label_000A96C9:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A96D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(0u)) goto label_000A97B6;
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1B4u))) goto label_000A97B6;
    cpu->ecx = lift_load32(cpu->esi + 0x260u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x264u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A970Bu)); sfera_sub_004A94D0(cpu, LIFT_CODE_TOKEN_VA(0x4A970Bu));
    cpu->ecx = lift_load32(cpu->esi + 0x254u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000A977E;
    cpu->eax -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000A9721;
    cpu->eax = cpu->ecx;
    label_000A9721:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A97B5;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x268u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    cpu->ebp = cpu->eax;
    cpu->edi = 1u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A9740:
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000A979F;
    lift_store32(cpu->esi + 0x260u, (uint64_t)(lift_load32(cpu->esi + 0x260u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esi + 0x1B0u);
    cpu->eax = lift_load32(cpu->esi + 0x260u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A976Fu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A976Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9776u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A9776u));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000A9782;
    goto label_000A9784;
    label_000A977E:
    cpu->eax = 0u;
    goto label_000A9721;
    label_000A9782:
    cpu->ecx = lift_load32(cpu->ecx);
    label_000A9784:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000A9790;
    cpu->eax -= cpu->edx;
    label_000A9790:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    label_000A979F:
    cpu->ecx -= cpu->edi;
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esi + 0x264u, cpu->ecx);
    lift_store32(cpu->esi + 0x268u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A9740;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A97B5:
    cpu->edi = lift_pop32(cpu);
    label_000A97B6:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A97C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esp + 0x28u)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_000A982D;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(cpu->eax)) goto label_000A982D;
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esi + 0x1B4u))) goto label_000A982D;
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9819u)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4A9819u));
    cpu->ecx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    --cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA982Du)); sfera_sub_004A94D0(cpu, LIFT_CODE_TOKEN_RVA(0xA982Du));
    label_000A982D:
    cpu->ecx = lift_load32(cpu->esi + 0x254u);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_store32(cpu->esp + 0x14u, 1u);
    lift_store32(cpu->esp + 8u, 0x17u);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000A9870;
    if ((uint8_t)(lift_load8(cpu->esp + 0x28u)) != (uint8_t)(0u)) goto label_000A9870;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax -= lift_load32(cpu->esi + 0x268u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    goto label_000A9880;
    label_000A9870:
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_store32(cpu->esp + 0x18u, 0u);
    label_000A9880:
    cpu->ecx = lift_load32(cpu->esi + 0x26Cu);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9890u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_VA(0x4A9890u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A98B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(cpu->eax)) goto label_000A98FB;
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esi + 0x1B4u))) goto label_000A98FB;
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A98E7u)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4A98E7u));
    cpu->ecx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    --cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA98FBu)); sfera_sub_004A94D0(cpu, LIFT_CODE_TOKEN_RVA(0xA98FBu));
    label_000A98FB:
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 0x254u))) goto label_000A995B;
    cpu->ecx = lift_load32(cpu->esi + 0x26Cu);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9913u)); sfera_sub_004C7A70(cpu, LIFT_CODE_TOKEN_VA(0x4A9913u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax -= lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esi + 0x268u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000A993F;
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A992Fu)); sfera_sub_004A96D0(cpu, LIFT_CODE_TOKEN_VA(0x4A992Fu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A993F:
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A9964;
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A994Bu)); sfera_sub_004A95A0(cpu, LIFT_CODE_TOKEN_VA(0x4A994Bu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A995B:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA9964u)); sfera_sub_004A97C0(cpu, LIFT_CODE_TOKEN_RVA(0xA9964u));
    label_000A9964:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A9A96;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000A99D5;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000A9A95;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A99BFu));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A99D5:
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->edi)) goto label_000A9A12;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A99F0u));
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->eax -= lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi);
    { uint64_t l=cpu->esp, r=(uint64_t)(0xCu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebp = lift_pop32(cpu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A9A12:
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_000A9A5F;
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx = cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::memmove);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xA9A37u), LIFT_CODE_TOKEN_RVA(0xA9A35u))) { return; }
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xA9A4Eu), LIFT_CODE_TOKEN_RVA(0xA9A4Cu))) { return; }
    cpu->esp += 0x18u;
    cpu->eax += cpu->ebx;
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A9A5F:
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000A9A6C;
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9A69u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A9A69u));
    cpu->esp += 4u;
    label_000A9A6C:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->esi;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9A7Cu)); sfera_sub_004BDC80(cpu, LIFT_CODE_TOKEN_VA(0x4A9A7Cu));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A9A94;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9A91u)); sfera_sub_004A8CC0(cpu, LIFT_CODE_TOKEN_VA(0x4A9A91u));
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000A9A94:
    cpu->ebp = lift_pop32(cpu);
    label_000A9A95:
    cpu->edi = lift_pop32(cpu);
    label_000A9A96:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9AA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000A9ADF;
    cpu->edi |= 0xFFFFFFFFu;
    (void)cpu;
    label_000A9AB0:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000A9ADA;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000A9AC7;
    cpu->eax -= cpu->ecx;
    label_000A9AC7:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9AD2u)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4A9AD2u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A9ADA;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000A9ADA:
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) != (uint32_t)(cpu->ebx)) goto label_000A9AB0;
    label_000A9ADF:
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebx)) goto label_000A9B01;
    label_000A9AE6:
    cpu->eax = lift_load32(cpu->esi + 4u);
    --cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A9AFD;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9AFAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A9AFAu));
    cpu->esp += 4u;
    label_000A9AFD:
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->ebx)) goto label_000A9AE6;
    label_000A9B01:
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000A9B11;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9B0Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A9B0Eu));
    cpu->esp += 4u;
    label_000A9B11:
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9B3Bu)); sfera_sub_004A8FB0(cpu, LIFT_CODE_TOKEN_VA(0x4A9B3Bu));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A9C80;
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->eax = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->edi);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->edi = 0x3FFFFFFFu;
    cpu->edi -= cpu->eax;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->ecx)) goto label_000A9B88;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A9B40u), "std::length_error");
    label_000A9B88:
    cpu->edi = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A9C58;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx = 0x3FFFFFFFu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000A9BB8;
    lift_store32(cpu->esp + 0x24u, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    goto label_000A9BBE;
    label_000A9BB8:
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    label_000A9BBE:
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000A9BC8;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    cpu->eax = cpu->edi;
    label_000A9BC8:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9BD1u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A9BD1u));
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebx = native_function_address32(&::memmove);
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA9BF0u), LIFT_CODE_TOKEN_RVA(0xA9BEEu))) { return; }
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax += cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA9C03u), LIFT_CODE_TOKEN_RVA(0xA9C01u))) { return; }
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA9C1Au), LIFT_CODE_TOKEN_RVA(0xA9C18u))) { return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esp + 0x38u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esp += 0x24u;
    cpu->edi += cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9C3A;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9C37u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A9C37u));
    cpu->esp += 4u;
    label_000A9C3A:
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->edx) * 4u));
    cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esi, cpu->ebp);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000A9C58:
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A9C62u));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->esp += 0xCu;
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9C7Bu)); sfera_sub_004A9490(cpu, LIFT_CODE_TOKEN_VA(0x4A9C7Bu));
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A9C80:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A9CBD;
    lift_push32(cpu, cpu->esi);
    (void)cpu;
    label_000A9CA0:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9CAE;
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    label_000A9CAE:
    cpu->ecx += 8u;
    cpu->eax += 8u;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000A9CA0;
    cpu->esi = lift_pop32(cpu);
    label_000A9CBD:
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x50u);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x9Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x58u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A9D03;
    lift_push32(cpu, 0x13u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListControl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9CFAu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A9CFAu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9D00u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A9D00u));
    cpu->esp += 0x10u;
    label_000A9D03:
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9D0Fu)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4A9D0Fu));
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"scrollbar");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9D23u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4A9D23u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9D96;
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9D39u)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4A9D39u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebx + 0x26Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9D47u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4A9D47u));
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x26Cu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x34u, 0x17u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA9D96u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_RVA(0xA9D96u));
    label_000A9D96:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"linkColor");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9DA3u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4A9DA3u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9E1A;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4A9DBFu));
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000A9DF4;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"linkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextChatListControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9DEBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A9DEBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9DF1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A9DF1u));
    cpu->esp += 0x1Cu;
    label_000A9DF4:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load8(cpu->esp + 0x14u);
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    lift_store32(cpu->ebx + 0x248u, cpu->edx);
    goto label_000A9E41;
    label_000A9E1A:
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = (uintptr_t)"%s(): HyperTextChatList control must have '%s' parameter in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"linkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextChatListControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9E38u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A9E38u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9E3Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A9E3Eu));
    cpu->esp += 0x1Cu;
    label_000A9E41:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"playerLinkColor");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9E4Eu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4A9E4Eu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9EBE;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4A9E6Au));
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000A9E9F;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"playerLinkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextChatListControl::LoadUI"); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9E96u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A9E96u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9E9Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A9E9Cu));
    cpu->esp += 0x1Cu;
    label_000A9E9F:
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load8(cpu->esp + 0x14u);
    cpu->edx = lift_load8(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->edx;
    goto label_000A9EC4;
    label_000A9EBE:
    cpu->eax = lift_load32(cpu->ebx + 0x248u);
    label_000A9EC4:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"itemLinkColor");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebx + 0x240u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9ED7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4A9ED7u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9F48;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4A9EF3u));
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000A9F28;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"itemLinkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextChatListControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9F1Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A9F1Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9F25u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A9F25u));
    cpu->esp += 0x1Cu;
    label_000A9F28:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load8(cpu->esp + 0x14u);
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    goto label_000A9F4E;
    label_000A9F48:
    cpu->edx = lift_load32(cpu->ebx + 0x248u);
    label_000A9F4E:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"maxItems");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebx + 0x244u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9F61u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4A9F61u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9F76;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9F6Eu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4A9F6Eu));
    lift_store32(cpu->ebx + 0x24Cu, cpu->eax);
    goto label_000A9F80;
    label_000A9F76:
    lift_store32(cpu->ebx + 0x24Cu, 0x100u);
    label_000A9F80:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"rowHeight");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9F8Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4A9F8Du));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A9FA2;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9F9Au)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4A9F9Au));
    lift_store32(cpu->ebx + 0x250u, cpu->eax);
    goto label_000A9FAC;
    label_000A9FA2:
    lift_store32(cpu->ebx + 0x250u, 0xFu);
    label_000A9FAC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x8Cu)) >= (uint8_t)((cpu->eax & 0xFFu))) goto label_000A9FBC;
    lift_store8(cpu->ebx + 0x8Cu, cpu->eax & 0xFFu);
    label_000A9FBC:
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A9FC8u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4A9FC8u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x3Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A9FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    cpu->esi = lift_load32(cpu->edi + 0x1B0u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_000AA02B;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4AA01Au));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->esi;
    lift_store32(cpu->edi + 0x1B4u, cpu->ebx);
    label_000AA02B:
    cpu->eax = lift_load32(cpu->edi + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->edi + 0x1C4u))) goto label_000AA0C8;
    cpu->ebx = lift_load32(cpu->edi + 0x1A8u);
    label_000AA043:
    --cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(lift_load32(cpu->edi + 0x1A8u))) goto label_000AA0C8;
    cpu->esi = lift_load32(cpu->edi + 0x1C4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA06Cu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AA06Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA073u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AA073u));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AA07B;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000AA07B:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AA087;
    cpu->eax -= cpu->edx;
    label_000AA087:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edi + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000AA043;
    cpu->ecx = lift_load32(cpu->ecx + 0x38u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000AA0A0:
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->ecx)) goto label_000AA0AB;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000AA0A0;
    label_000AA0AB:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000AA043;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1B0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA0BFu)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4AA0BFu));
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    goto label_000AA043;
    label_000AA0C8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load8(cpu->edi + 0x8Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AA200;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA0F1u)); sfera_sub_004D1AC0(cpu, LIFT_CODE_TOKEN_VA(0x4AA0F1u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x1A8u)) == (uint32_t)(0u)) goto label_000AA200;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA110u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AA110u));
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA120u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AA120u));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000AA195;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->edi;
    label_000AA130:
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000AA138;
    cpu->edx = 0u;
    goto label_000AA13B;
    label_000AA138:
    cpu->edx = lift_load32(cpu->ebp);
    label_000AA13B:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->esi)) goto label_000AA146;
    cpu->eax -= cpu->ecx;
    label_000AA146:
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA151u)); sfera_sub_004AE280(cpu, LIFT_CODE_TOKEN_VA(0x4AA151u));
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000AA159;
    cpu->ecx = 0u;
    goto label_000AA15C;
    label_000AA159:
    cpu->ecx = lift_load32(cpu->ebp);
    label_000AA15C:
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->esi)) goto label_000AA167;
    cpu->eax -= cpu->edx;
    label_000AA167:
    cpu->edx = lift_load8(cpu->edi + 0x8Cu);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->edi + 0x28u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA17Eu)); sfera_sub_004AE9B0(cpu, LIFT_CODE_TOKEN_VA(0x4AA17Eu));
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    ++cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA18Fu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AA18Fu));
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000AA130;
    cpu->ebp = lift_pop32(cpu);
    label_000AA195:
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = 0u;
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_store32(cpu->edi + 0x260u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA1B4u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AA1B4u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA1BBu)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x4AA1BBu));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_000AA1C5;
    cpu->ecx = 0u;
    goto label_000AA1C7;
    label_000AA1C5:
    cpu->ecx = lift_load32(cpu->ecx);
    label_000AA1C7:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AA1D3;
    cpu->eax -= cpu->edx;
    label_000AA1D3:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->edi + 0x268u, cpu->esi);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    --cpu->ecx;
    lift_store32(cpu->edi + 0x264u, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA1F6u)); sfera_sub_004A9FF0(cpu, LIFT_CODE_TOKEN_VA(0x4AA1F6u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA1FEu)); sfera_sub_004A97C0(cpu, LIFT_CODE_TOKEN_VA(0x4AA1FEu));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000AA200:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AA3F1;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->eax;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->edi)) goto label_000AA2D0;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4AA270u), "std::length_error");
    label_000AA2D0:
    cpu->ebx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000AA3C7;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx = 0x3FFFFFFFu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000AA2FE;
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000AA303;
    label_000AA2FE:
    cpu->eax += cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    label_000AA303:
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_000AA30C;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    cpu->eax = cpu->ebx;
    label_000AA30C:
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA315u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x4AA315u));
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4AA335u));
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA356u)); sfera_sub_004A8FE0(cpu, LIFT_CODE_TOKEN_VA(0x4AA356u));
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4AA368u));
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esp += 0xCu;
    cpu->edi += cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AA38A;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA387u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA387u));
    cpu->esp += 4u;
    label_000AA38A:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000AA3C7:
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA3DBu)); sfera_sub_004A8FE0(cpu, LIFT_CODE_TOKEN_VA(0x4AA3DBu));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA3EEu)); sfera_sub_004A9490(cpu, LIFT_CODE_TOKEN_VA(0x4AA3EEu));
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    label_000AA3F1:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA3B2(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA3BBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA3BBu));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA3C7u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AA3C7u));
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA3DBu)); sfera_sub_004A8FE0(cpu, LIFT_CODE_TOKEN_VA(0x4AA3DBu));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA3EEu)); sfera_sub_004A9490(cpu, LIFT_CODE_TOKEN_VA(0x4AA3EEu));
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA410(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA441u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4AA441u));
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(cpu->esi + 0x198u);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextChatListControl*>(cpu->esi));
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x34u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA465u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AA465u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AA542;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B8u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    lift_store32(cpu->esi + 0x1E0u, cpu->ebx);
    cpu->eax = 0xFu;
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    lift_store8(cpu->esi + 0x1D0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x200u, cpu->eax);
    lift_store32(cpu->esi + 0x1FCu, cpu->ebx);
    lift_store8(cpu->esi + 0x1ECu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x21Cu, cpu->eax);
    lift_store32(cpu->esi + 0x218u, cpu->ebx);
    lift_store8(cpu->esi + 0x208u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x238u, cpu->eax);
    lift_store32(cpu->esi + 0x234u, cpu->ebx);
    lift_store8(cpu->esi + 0x224u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x260u, cpu->ebx);
    lift_store32(cpu->esi + 0x264u, cpu->ebx);
    lift_store32(cpu->esi + 0x268u, cpu->ebx);
    lift_store32(cpu->esi + 0x26Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x288u, cpu->ebx);
    lift_store32(cpu->esi + 0x28Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x290u, cpu->ebx);
    lift_store32(cpu->esi + 0x50u, 0x16u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AA542:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA56Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AA56Cu));
    lift_trap(cpu, 0x4AA56Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA570(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextChatListControl*>(cpu->esi));
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x3Cu, 7u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x26Cu)) == (uint32_t)(cpu->ebx)) goto label_000AA5DB;
    cpu->edx = (uint32_t)(cpu->ebx + 0x60u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA5C2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AA5C2u));
    cpu->ecx = lift_load32(cpu->esi + 0x26Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AA5D5;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000AA5D5:
    lift_store32(cpu->esi + 0x26Cu, cpu->ebx);
    label_000AA5DB:
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) <= (uint32_t)(cpu->ebx)) goto label_000AA62E;
    label_000AA5E5:
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA5FBu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AA5FBu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA602u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AA602u));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_000AA60C;
    cpu->ecx = 0u;
    goto label_000AA60E;
    label_000AA60C:
    cpu->ecx = lift_load32(cpu->ecx);
    label_000AA60E:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AA61A;
    cpu->eax -= cpu->edx;
    label_000AA61A:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA625u)); sfera_sub_004AD610(cpu, LIFT_CODE_TOKEN_VA(0x4AA625u));
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x1A8u))) goto label_000AA5E5;
    label_000AA62E:
    cpu->eax = lift_load32(cpu->esi + 0x288u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AA641;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA63Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA63Eu));
    cpu->esp += 4u;
    label_000AA641:
    cpu->ebp = 0x10u;
    lift_store32(cpu->esi + 0x288u, cpu->ebx);
    lift_store32(cpu->esi + 0x28Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x290u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x238u)) < (uint32_t)(cpu->ebp)) goto label_000AA66F;
    cpu->eax = lift_load32(cpu->esi + 0x224u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA66Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA66Cu));
    cpu->esp += 4u;
    label_000AA66F:
    cpu->edi = 0xFu;
    lift_store32(cpu->esi + 0x238u, cpu->edi);
    lift_store32(cpu->esi + 0x234u, cpu->ebx);
    lift_store8(cpu->esi + 0x224u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x21Cu)) < (uint32_t)(cpu->ebp)) goto label_000AA69D;
    cpu->eax = lift_load32(cpu->esi + 0x208u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA69Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA69Au));
    cpu->esp += 4u;
    label_000AA69D:
    lift_store32(cpu->esi + 0x21Cu, cpu->edi);
    lift_store32(cpu->esi + 0x218u, cpu->ebx);
    lift_store8(cpu->esi + 0x208u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x200u)) < (uint32_t)(cpu->ebp)) goto label_000AA6C6;
    cpu->eax = lift_load32(cpu->esi + 0x1ECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA6C3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA6C3u));
    cpu->esp += 4u;
    label_000AA6C6:
    lift_store32(cpu->esi + 0x200u, cpu->edi);
    lift_store32(cpu->esi + 0x1FCu, cpu->ebx);
    lift_store8(cpu->esi + 0x1ECu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1E4u)) < (uint32_t)(cpu->ebp)) goto label_000AA6EF;
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA6ECu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA6ECu));
    cpu->esp += 4u;
    label_000AA6EF:
    lift_store32(cpu->esi + 0x1E4u, cpu->edi);
    lift_store32(cpu->esi + 0x1E0u, cpu->ebx);
    lift_store8(cpu->esi + 0x1D0u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AA714;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA711u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA711u));
    cpu->esp += 4u;
    label_000AA714:
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AA739;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA736u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA736u));
    cpu->esp += 4u;
    label_000AA739:
    cpu->edi = (uint32_t)(cpu->esi + 0x198u);
    lift_store32(cpu->esi + 0x1B0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B8u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x3Cu, 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA761u)); sfera_sub_004A9AA0(cpu, LIFT_CODE_TOKEN_VA(0x4AA761u));
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA769u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA769u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->edi, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA77Du)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4AA77Du));
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA7A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C0u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000AA7D2;
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000AA820;
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    label_000AA7C3:
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->edi)) goto label_000AA7CE;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000AA7C3;
    label_000AA7CE:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000AA820;
    label_000AA7D2:
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA7DCu)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4AA7DCu));
    cpu->edi = 0u;
    lift_store32(cpu->esi + 0x260u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) != (uint32_t)(cpu->edi)) goto label_000AA7F0;
    cpu->ecx = 0u;
    goto label_000AA805;
    label_000AA7F0:
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA7FBu)); sfera_sub_004AF350(cpu, LIFT_CODE_TOKEN_VA(0x4AA7FBu));
    cpu->ecx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    --cpu->ecx;
    label_000AA805:
    lift_store32(cpu->esi + 0x264u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA812u)); sfera_sub_004A9FF0(cpu, LIFT_CODE_TOKEN_VA(0x4AA812u));
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x268u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAA820u)); sfera_sub_004A97C0(cpu, LIFT_CODE_TOKEN_RVA(0xAA820u));
    label_000AA820:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x1C0u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000AA876;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->ebx);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4AA864u));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esi + 0x1C4u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    label_000AA876:
    cpu->edi = 0u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x260u, cpu->edi);
    lift_store32(cpu->esi + 0x264u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA88Bu)); sfera_sub_004A9FF0(cpu, LIFT_CODE_TOKEN_VA(0x4AA88Bu));
    cpu->ecx = lift_load32(cpu->esi + 0x26Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->eax = 1u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x268u, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x10u, 0x17u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA8E0u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_VA(0x4AA8E0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA900(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 0x1B4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x1B0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 4u, 0u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_000AA961;
    cpu->edx = lift_load32(cpu->ecx + 0x1B0u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA936u)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4AA936u));
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->eax += 0x1Cu;
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA95Au)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AA95Au));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000AA961:
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA984u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4AA984u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AA990(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 0x1B4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x1B0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 4u, 0u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_000AA9EE;
    cpu->edx = lift_load32(cpu->ecx + 0x1B0u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA9C6u)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4AA9C6u));
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA9E7u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AA9E7u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000AA9EE:
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAA11u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4AAA11u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000AAA50;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->esi)) goto label_000AAA4D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi;
    cpu->edi -= cpu->eax;
    label_000AAA36:
    cpu->ebx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->ebx);
    cpu->ebx = lift_load32(cpu->edi + cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->edx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_000AAA36;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000AAA4D:
    lift_store32(cpu->ecx + 4u, cpu->eax);
    label_000AAA50:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAB13(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAB1Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AAB1Cu));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAB28u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AAB28u));
    lift_trap(cpu, 0x4AAB28u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAB30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAB38u)); sfera_sub_004AA570(cpu, LIFT_CODE_TOKEN_VA(0x4AAB38u));
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000AAB48;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAB45u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AAB45u));
    cpu->esp += 4u;
    label_000AAB48:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAB50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000AAC1E;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AAB7E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAB77u)); sfera_sub_004AAA20(cpu, LIFT_CODE_TOKEN_VA(0x4AAB77u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AAB7E:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_arithmetic(cpu, cpu->ebp, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->ebp)) goto label_000AABAD;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAB94u)); sfera_sub_004A8C90(cpu, LIFT_CODE_TOKEN_VA(0x4AAB94u));
    cpu->eax = lift_load32(cpu->edi + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->ebx = lift_pop32(cpu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AABAD:
    cpu->edx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edx)) goto label_000AABE7;
    cpu->ebp = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ebp) * 8u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AABC4u)); sfera_sub_004A8C90(cpu, LIFT_CODE_TOKEN_VA(0x4AABC4u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AABDBu)); sfera_sub_004A8FB0(cpu, LIFT_CODE_TOKEN_VA(0x4AABDBu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AABE7:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000AABF4;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AABF1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AABF1u));
    cpu->esp += 4u;
    label_000AABF4:
    cpu->eax = lift_load32(cpu->edi + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->esi;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAC04u)); sfera_sub_004A8C00(cpu, LIFT_CODE_TOKEN_VA(0x4AAC04u));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000AAC1C;
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAC19u)); sfera_sub_004A9B20(cpu, LIFT_CODE_TOKEN_VA(0x4AAC19u));
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000AAC1C:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000AAC1E:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAC30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAC3Eu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4AAC3Eu));
    cpu->edi += 0x1Cu;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAC4Au)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4AAC4Au));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAC60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000AAC60;
    label_000AAA60:
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
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x1FFFFFFFu)) goto label_000AAAA2;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4AAA60u), "std::length_error");
    label_000AAAA2:
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000AAAFF;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAAB9u)); sfera_sub_00402BB0(cpu, LIFT_CODE_TOKEN_VA(0x4AAAB9u));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAAD7u)); sfera_sub_004A93A0(cpu, LIFT_CODE_TOKEN_VA(0x4AAAD7u));
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AAAEE;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAAEBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AAAEBu));
    cpu->esp += 4u;
    label_000AAAEE:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edi) * 8u));
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi, cpu->ebx);
    label_000AAAFF:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AAC60:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = 0x1FFFFFFFu;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000AAC86;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4AAC60u), "std::length_error");
    label_000AAC86:
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000AACBA;
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->edi = 0x1FFFFFFFu;
    cpu->edi -= cpu->esi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_000AACA7;
    cpu->edx = 0u;
    goto label_000AACA9;
    label_000AACA7:
    cpu->edx += cpu->esi;
    label_000AACA9:
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000AACAF;
    cpu->edx = cpu->eax;
    label_000AACAF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    goto label_000AAA60;
    label_000AACBA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AACC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    cpu->edi = 0u;
    lift_store32(cpu->esi, cpu->edi);
    lift_push32(cpu, 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AACFEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AACFEu));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000AADAE;
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    cpu->ecx = cpu->ebx;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAD42u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AAD42u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 8u, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAD52u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AAD52u));
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAD5Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AAD5Du));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ebp + 8u, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_000AAD7A;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_000AAD7A;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000AAD7A:
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAD87u)); sfera_sub_0048F7E0(cpu, LIFT_CODE_TOKEN_VA(0x4AAD87u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AADAE:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AADD3u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AADD3u));
    lift_trap(cpu, 0x4AADD3u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAD9D(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AADA5u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4AADA5u));
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AADAEu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AADAEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AADD3u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AADD3u));
    lift_trap(cpu, 0x4AADD3u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AADE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000AAF9B;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_000AAE11;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAE05u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4AAE05u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AAE11:
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AAEC7;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAE2Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AAE2Du));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAE3Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AAE3Eu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAE4Fu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AAE4Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAE58u)); sfera_sub_004A93D0(cpu, LIFT_CODE_TOKEN_VA(0x4AAE58u));
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAE64u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AAE64u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->ebp);
    lift_store32(cpu->ecx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000AAE82;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000AAE82;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000AAE82:
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000AAEA8;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000AAEA8;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AAEA8:
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAEBBu)); sfera_sub_0048EBC0(cpu, LIFT_CODE_TOKEN_VA(0x4AAEBBu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AAEC7:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAED9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AAED9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAEE0u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AAEE0u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAEF1u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AAEF1u));
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000AAF11;
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000AAF11;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AAF11:
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAF29u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AAF29u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAF32u)); sfera_sub_004A93D0(cpu, LIFT_CODE_TOKEN_VA(0x4AAF32u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAF43u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AAF43u));
    cpu->esp -= 0xCu;
    cpu->esi = 0u;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->esi);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000AAF61;
    cpu->ebx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000AAF61;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AAF61:
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AAF70u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AAF70u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000AAF8E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000AAF8E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000AAF8E:
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAAF9Bu)); sfera_sub_0048F7E0(cpu, LIFT_CODE_TOKEN_RVA(0xAAF9Bu));
    label_000AAF9B:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AAFB0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->eax = 0u;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->edi = lift_load32(cpu->ebx + 4u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->ebx)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    lift_store32(cpu->esi, cpu->eax);
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000AB047;
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0x1FFFFFFFu)) goto label_000AB014;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4AAFB0u), "std::length_error");
    label_000AB014:
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB01Du)); sfera_sub_00402BB0(cpu, LIFT_CODE_TOKEN_VA(0x4AB01Du));
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ebx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB044u)); sfera_sub_004A9C90(cpu, LIFT_CODE_TOKEN_VA(0x4AB044u));
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000AB047:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB05D(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB065u)); sfera_sub_00429AF0(cpu, LIFT_CODE_TOKEN_VA(0x4AB065u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB06Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AB06Eu));
    lift_trap(cpu, 0x4AB06Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB070(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000AB0B7;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_000AB0B7;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000AB098;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAB098u)); sfera_sub_004AAC60(cpu, LIFT_CODE_TOKEN_RVA(0xAB098u));
    label_000AB098:
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AB0D6;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AB0B7:
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000AB0C5;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAB0C5u)); sfera_sub_004AAC60(cpu, LIFT_CODE_TOKEN_RVA(0xAB0C5u));
    label_000AB0C5:
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AB0D6;
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    label_000AB0D6:
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB0E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB123u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4AB123u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB140u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4AB140u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000AB193;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->ebx);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4AB184u));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    label_000AB193:
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB1A8u)); sfera_sub_004AA270(cpu, LIFT_CODE_TOKEN_VA(0x4AB1A8u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB1B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esi, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB1F8u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB1F8u));
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edi + 0x1Cu);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, 0u);
    lift_store8(cpu->ecx, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB221u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB221u));
    cpu->ecx = lift_load32(cpu->edi + 0x38u);
    lift_store32(cpu->esi + 0x38u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x3Cu);
    cpu->eax = (uint32_t)(cpu->edi + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x40u);
    lift_store8(cpu->esp + 0x1Cu, 1u);
    lift_store32(cpu->esi + 0x3Cu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB23Eu)); sfera_sub_004AACC0(cpu, LIFT_CODE_TOKEN_VA(0x4AB23Eu));
    cpu->edi += 0x58u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x58u);
    lift_store8(cpu->esp + 0x1Cu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB24Fu)); sfera_sub_004AAFB0(cpu, LIFT_CODE_TOKEN_VA(0x4AB24Fu));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000AB307;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000AB287:
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AB294;
    cpu->eax -= cpu->edx;
    label_000AB294:
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ecx)) goto label_000AB2A1;
    cpu->ecx -= cpu->esi;
    label_000AB2A1:
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB2B9u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB2B9u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB2C9u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB2C9u));
    cpu->edx = lift_load32(cpu->esi + 0x38u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x40u);
    lift_store32(cpu->edi + 0x38u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_store32(cpu->edi + 0x3Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB2E1u)); sfera_sub_004AADE0(cpu, LIFT_CODE_TOKEN_VA(0x4AB2E1u));
    cpu->esi += 0x58u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edi + 0x58u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB2EDu)); sfera_sub_004AAB50(cpu, LIFT_CODE_TOKEN_VA(0x4AB2EDu));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    ++cpu->eax;
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000AB287;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AB307:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ebx, cpu->edx);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x20u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB320(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x70u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x84u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->esi = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB363u)); sfera_sub_004AB1B0(cpu, LIFT_CODE_TOKEN_VA(0x4AB363u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x98u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB37Au)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB37Au));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ebx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB38Au)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB38Au));
    cpu->eax = lift_load32(cpu->esi + 0x38u);
    lift_store32(cpu->edi + 0x38u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x3Cu);
    lift_store32(cpu->edi + 0x3Cu, cpu->ecx);
    cpu->ebp = (uint32_t)(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB3A2u)); sfera_sub_004AADE0(cpu, LIFT_CODE_TOKEN_VA(0x4AB3A2u));
    cpu->eax = (uint32_t)(cpu->esi + 0x58u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x58u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB3B2u)); sfera_sub_004AAB50(cpu, LIFT_CODE_TOKEN_VA(0x4AB3B2u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB3C2u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB3C2u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB3D2u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AB3D2u));
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_store32(cpu->esi + 0x38u, cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x3Cu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB3ECu)); sfera_sub_004AADE0(cpu, LIFT_CODE_TOKEN_VA(0x4AB3ECu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB3FAu)); sfera_sub_004AAB50(cpu, LIFT_CODE_TOKEN_VA(0x4AB3FAu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x8Cu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB40Eu)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4AB40Eu));
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x7Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB430(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x88u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AB54D;
    if ((uint8_t)((lift_load8(cpu->ebx + 0x24u)) & (2u)) != 0u) goto label_000AB54D;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1A8u)) == (uint32_t)(0u)) goto label_000AB54D;
    cpu->eax = lift_load32(cpu->ebx + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x1C4u))) goto label_000AB54D;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB47Eu)); sfera_sub_004A8A80(cpu, LIFT_CODE_TOKEN_VA(0x4AB47Eu));
    cpu->ecx = (uint32_t)(cpu->ebx + 0x288u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB489u)); sfera_sub_004AAA20(cpu, LIFT_CODE_TOKEN_VA(0x4AB489u));
    cpu->eax = lift_load32(cpu->ebx + 0x258u);
    cpu->eax += lift_load32(cpu->ebx + 0x30u);
    cpu->ecx = lift_load32(cpu->ebx + 0x25Cu);
    cpu->ecx += lift_load32(cpu->ebx + 0x34u);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    lift_divide_accumulator(cpu, lift_load32(cpu->ebx + 0x250u), 32u, 0u);
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_store32(cpu->ebx + 0x254u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(1u)) goto label_000AB54D;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB4CCu)); sfera_sub_004A8B30(cpu, LIFT_CODE_TOKEN_VA(0x4AB4CCu));
    cpu->edx = lift_load32(cpu->ebx + 0x1B4u);
    cpu->edx -= lift_load32(cpu->ebx + 0x1B0u);
    cpu->ebp = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000AB564;
    label_000AB4EB:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->ebx + 0x270u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB4FDu)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4AB4FDu));
    cpu->ecx = lift_load32(cpu->ebx + 0x26Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AB54D;
    cpu->eax = lift_load32(cpu->ebx + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000AB540;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000AB529;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000AB529:
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000AB540:
    cpu->ecx = lift_load32(cpu->ebx + 0x26Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000AB54D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AB560:
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_000AB564:
    if ((uint32_t)(cpu->esi) >= (uint32_t)(lift_load32(cpu->ebx + 0x254u))) goto label_000AB4EB;
    cpu->eax = lift_load32(cpu->ebx + 0x1B0u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB585u)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4AB585u));
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB5A6u)); sfera_sub_004A8AD0(cpu, LIFT_CODE_TOKEN_VA(0x4AB5A6u));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000AB791;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x44u);
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->edi;
    ++cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->ebx + 0x250u));
    lift_store32(cpu->esp + 0x40u, (uint64_t)(lift_load32(cpu->esp + 0x40u)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edi)) goto label_000AB5F5;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000AB5D0:
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->eax)) goto label_000AB5F5;
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x288u);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x50u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB5ECu)); sfera_sub_004AB070(cpu, LIFT_CODE_TOKEN_VA(0x4AB5ECu));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    --cpu->esi;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_000AB5D0;
    label_000AB5F5:
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_000AB791;
    lift_store32(cpu->esp + 0x30u, 0u);
    label_000AB60B:
    cpu->edi = lift_load32(cpu->ebx + 0x250u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x30u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->eax + 0x58u);
    cpu->edi += lift_load32(cpu->esp + 0x40u);
    cpu->ebp = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->esi = lift_load32(cpu->esp + 0x50u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    if ((uint32_t)(cpu->ebp) > (uint32_t)(cpu->edx)) goto label_000AB770;
    label_000AB642:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += 0x40u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x10u)) <= (uint32_t)(cpu->ebp)) goto label_000AB7B2;
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB665u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AB665u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB66Cu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AB66Cu));
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AB676;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_000AB678;
    label_000AB676:
    cpu->esi = lift_load32(cpu->ecx);
    label_000AB678:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AB68C;
    cpu->eax -= cpu->edx;
    label_000AB68C:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ebx = cpu->eax;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB6A4u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x4AB6A4u));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000AB75D;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += 0x40u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x10u)) <= (uint32_t)(cpu->ebp)) goto label_000AB7B2;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB6CFu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AB6CFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB6D6u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AB6D6u));
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AB6E0;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000AB6E2;
    label_000AB6E0:
    cpu->edx = lift_load32(cpu->ecx);
    label_000AB6E2:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->eax)) goto label_000AB6F6;
    cpu->eax -= cpu->esi;
    label_000AB6F6:
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = cpu->edi;
    cpu->ecx -= lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB70Du)); sfera_sub_004312B0(cpu, LIFT_CODE_TOKEN_VA(0x4AB70Du));
    cpu->eax = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AB730;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AB74B;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edx + 0x3Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB72Eu)); sfera_sub_004A9010(cpu, LIFT_CODE_TOKEN_VA(0x4AB72Eu));
    goto label_000AB747;
    label_000AB730:
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edx + 0x3Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAB747u)); sfera_sub_004A9210(cpu, LIFT_CODE_TOKEN_RVA(0xAB747u));
    label_000AB747:
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    label_000AB74B:
    cpu->edx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB757u)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4AB757u));
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000AB75D:
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000AB642;
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    label_000AB770:
    cpu->eax = 1u;
    lift_store32(cpu->esp + 0x30u, (uint64_t)(lift_load32(cpu->esp + 0x30u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000AB60B;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    label_000AB791:
    cpu->ecx = lift_load32(cpu->ebx + 0x1B4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->ebx + 0x1B0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->ebp), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->ecx)) goto label_000AB560;
    goto label_000AB4EB;
    label_000AB7B2:
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid deque<T> subscript");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4AB7B2u), "std::out_of_range");
    lift_trap(cpu, 0x4AB7BDu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AB7C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1ACu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1C0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x1D0u);
    cpu->esi = cpu->ecx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x48u)) & 0xFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000ABC8A;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(0u)) goto label_000ABC8A;
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1B4u))) goto label_000ABC8A;
    if ((uint32_t)(lift_load32(cpu->esi + 0x26Cu)) == (uint32_t)(0u)) goto label_000AB849;
    cpu->ecx = lift_load32(cpu->esi + 0x26Cu);
    lift_push32(cpu, cpu->ebx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000AB849:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB84Eu)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4AB84Eu));

    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB870u)); sfera_sub_004A8A80(cpu, LIFT_CODE_TOKEN_VA(0x4AB870u));
    cpu->ebp = lift_load32(cpu->esi + 0x258u);
    cpu->ebp += lift_load32(cpu->esi + 0x30u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->edx = lift_load32(cpu->esi + 0x25Cu);
    cpu->edx += lift_load32(cpu->esi + 0x34u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp + 0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000ABC8A;
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(cpu->ecx)) goto label_000ABC8A;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->edx)) goto label_000ABC8A;
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(cpu->eax)) goto label_000ABC8A;
    cpu->eax -= cpu->edi;
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x250u), 32u, 0u);
    cpu->ecx = lift_load32(cpu->esi + 0x28Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x288u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000ABC8A;
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (0xCu)) == 0u) goto label_000ABC8A;
    cpu->edx = lift_load32(cpu->esi + 0x288u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB90Eu)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4AB90Eu));
    cpu->ebx = cpu->eax;
    cpu->edx = lift_load32(cpu->ebx + 0x58u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000ABC8A;
    label_000AB92E:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB937u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4AB937u));
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_000ABC77;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB951u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4AB951u));
    cpu->edi = lift_load32(cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB95Fu)); sfera_sub_00431280(cpu, LIFT_CODE_TOKEN_VA(0x4AB95Fu));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000ABC77;
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB97Bu)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4AB97Bu));
    cpu->ebp = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB989u)); sfera_sub_00431280(cpu, LIFT_CODE_TOKEN_VA(0x4AB989u));
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->ecx += lift_load32(cpu->eax);
    cpu->ecx += lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000ABC77;
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB9A8u)); sfera_sub_00431280(cpu, LIFT_CODE_TOKEN_VA(0x4AB9A8u));
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax += lift_load32(cpu->esp + 0x28u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_000ABC77;
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB9C5u)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4AB9C5u));
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    cpu->ebp = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB9D4u)); sfera_sub_00431280(cpu, LIFT_CODE_TOKEN_VA(0x4AB9D4u));
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax += lift_load32(cpu->ebp);
    cpu->eax += lift_load32(cpu->esp + 0x28u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000ABC77;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AB9EFu)); sfera_sub_00431210(cpu, LIFT_CODE_TOKEN_VA(0x4AB9EFu));
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ABBD1;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ABC77;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000ABAF6;
    if ((uint8_t)((lift_load8(cpu->ecx + 0x18u)) & (1u)) == 0u) goto label_000ABA56;
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABA21u)); sfera_sub_00431680(cpu, LIFT_CODE_TOKEN_VA(0x4ABA21u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1C8u, 2u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ABA34;
    cpu->eax = lift_load32(cpu->eax);
    label_000ABA34:
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABA43u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4ABA43u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABA4Au)); sfera_sub_004A2670(cpu, LIFT_CODE_TOKEN_VA(0x4ABA4Au));
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    goto label_000ABC67;
    label_000ABA56:
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x70u, cpu->esi);
    lift_store32(cpu->esp + 0x74u, cpu->edx);
    lift_store32(cpu->esp + 0x78u, 0x1D50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABA7Cu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4ABA7Cu));
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABA8Bu)); sfera_sub_00431680(cpu, LIFT_CODE_TOKEN_VA(0x4ABA8Bu));
    cpu->ebp = cpu->eax;
    cpu->edx = (uint32_t)(cpu->esp + 0x114u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x1CCu, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABAA7u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4ABAA7u));
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x150u);
    lift_store8(cpu->esp + 0x1CCu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABABEu)); sfera_sub_004AB0E0(cpu, LIFT_CODE_TOKEN_VA(0x4ABABEu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1D0u);
    lift_store8(cpu->esp + 0x1CCu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABAD2u)); sfera_sub_004AAC30(cpu, LIFT_CODE_TOKEN_VA(0x4ABAD2u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABADEu)); sfera_sub_00406210(cpu, LIFT_CODE_TOKEN_VA(0x4ABADEu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x114u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABAEAu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ABAEAu));
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    goto label_000ABC67;
    label_000ABAF6:
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_000ABC77;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x70u, cpu->esi);
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    lift_store32(cpu->esp + 0x78u, 0x1D51u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABB24u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4ABB24u));
    cpu->edx = (uint32_t)(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABB33u)); sfera_sub_00431680(cpu, LIFT_CODE_TOKEN_VA(0x4ABB33u));
    cpu->ebp = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x1CCu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABB4Fu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4ABB4Fu));
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x188u);
    lift_store8(cpu->esp + 0x1CCu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABB66u)); sfera_sub_004AB0E0(cpu, LIFT_CODE_TOKEN_VA(0x4ABB66u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1D0u);
    lift_store8(cpu->esp + 0x1CCu, 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABB7Au)); sfera_sub_004AAC30(cpu, LIFT_CODE_TOKEN_VA(0x4ABB7Au));
    cpu->ecx = (uint32_t)(cpu->esp + 0x184u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABB86u)); sfera_sub_00406210(cpu, LIFT_CODE_TOKEN_VA(0x4ABB86u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x130u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABB92u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ABB92u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xA4u);
    lift_store32(cpu->esp + 0x1C8u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABBA9u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ABBA9u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x224u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABBB9u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4ABBB9u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x208u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABBCCu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4ABBCCu));
    goto label_000ABC77;
    label_000ABBD1:
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint8_t)((lift_load8(cpu->edx + 0xCu)) & (4u)) == 0u) goto label_000ABC77;
    cpu->eax = cpu->edx;
    if ((uint8_t)((lift_load8(cpu->eax + 0x18u)) & (1u)) == 0u) goto label_000ABC28;
    cpu->ecx = (uint32_t)(cpu->esp + 0xC0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABBF6u)); sfera_sub_00431680(cpu, LIFT_CODE_TOKEN_VA(0x4ABBF6u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1C8u, 0u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ABC09;
    cpu->eax = lift_load32(cpu->eax);
    label_000ABC09:
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABC18u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4ABC18u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABC1Fu)); sfera_sub_004A2670(cpu, LIFT_CODE_TOKEN_VA(0x4ABC1Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0xC0u);
    goto label_000ABC67;
    label_000ABC28:
    cpu->edx = (uint32_t)(cpu->esp + 0xF8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABC37u)); sfera_sub_00431680(cpu, LIFT_CODE_TOKEN_VA(0x4ABC37u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1C8u, 1u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ABC4A;
    cpu->eax = lift_load32(cpu->eax);
    label_000ABC4A:
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1388u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABC59u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4ABC59u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABC60u)); sfera_sub_004A2670(cpu, LIFT_CODE_TOKEN_VA(0x4ABC60u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xF8u);
    label_000ABC67:
    lift_store32(cpu->esp + 0x1C8u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xABC77u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0xABC77u));
    label_000ABC77:
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(lift_load32(cpu->esp + 0x34u))) goto label_000AB92E;
    label_000ABC8A:
    cpu->ecx = lift_load32(cpu->esp + 0x1C0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1B8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ABCC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    cpu->ebx = 0u;
    cpu->esi = 0u;
    cpu->ebp = 0u;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->edi + 0x1C0u);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store8(cpu->esp + 0x17u, 0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->edi + 0x1C4u))) goto label_000ABECF;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esp + 0x58u)) <= (uint32_t)(cpu->eax)) goto label_000ABF66;
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x5Cu, cpu->edx);
    label_000ABD32:
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->esi)) goto label_000ABDA7;
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->edx)) goto label_000ABDA7;
    cpu->edi = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebp)) goto label_000ABD98;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3FFFFFFEu)) goto label_000ABEC4;
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000ABD98;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi = 0x3FFFFFFFu;
    cpu->esi -= cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000ABD76;
    cpu->ecx = 0u;
    goto label_000ABD78;
    label_000ABD76:
    cpu->ecx += cpu->edx;
    label_000ABD78:
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000ABD7E;
    cpu->ecx = cpu->eax;
    label_000ABD7E:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABD88u)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4ABD88u));
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    label_000ABD98:
    if ((uint32_t)(cpu->esi) == 0u) goto label_000ABDA1;
    cpu->eax = lift_load32(cpu->ebx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esi, cpu->eax);
    label_000ABDA1:
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    goto label_000ABE06;
    label_000ABDA7:
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebp)) goto label_000ABDFE;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3FFFFFFEu)) goto label_000ABEC4;
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000ABDFE;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi = 0x3FFFFFFFu;
    cpu->esi -= cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000ABDDC;
    cpu->ecx = 0u;
    goto label_000ABDDE;
    label_000ABDDC:
    cpu->ecx += cpu->edx;
    label_000ABDDE:
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000ABDE4;
    cpu->ecx = cpu->eax;
    label_000ABDE4:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABDEEu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4ABDEEu));
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    label_000ABDFE:
    if ((uint32_t)(cpu->esi) == 0u) goto label_000ABE06;
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->esi, cpu->ecx);
    label_000ABE06:
    cpu->ecx = lift_load32(cpu->edi + 0x1C4u);
    cpu->eax = lift_load32(cpu->edi + 0x1C0u);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000ABE38;
    cpu->edx = lift_load32(cpu->edx);
    (void)cpu;
    label_000ABE20:
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->edx)) goto label_000ABE2B;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000ABE20;
    label_000ABE2B:
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000ABE38;
    lift_store8(cpu->esp + 0x17u, 1u);
    label_000ABE38:
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->eax;
    cpu->edx += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->edx);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esp + 0x58u))) goto label_000ABD32;
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) != (uint8_t)(1u)) goto label_000ABF59;
    label_000ABE5D:
    cpu->ecx = lift_load32(cpu->edi + 0x1C4u);
    cpu->edi = lift_load32(cpu->edi + 0x1C0u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000ABE93;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4ABE7Eu));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    cpu->edi += cpu->ebp;
    lift_store32(cpu->eax + 0x1C4u, cpu->edi);
    label_000ABE93:
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->edi + 0x1C0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1C0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABEB0u)); sfera_sub_004AA270(cpu, LIFT_CODE_TOKEN_VA(0x4ABEB0u));
    cpu->esi = 0u;
    lift_store32(cpu->edi + 0x260u, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1A8u)) != (uint32_t)(cpu->esi)) goto label_000ABEF8;
    cpu->eax = 0u;
    goto label_000ABF3E;
    label_000ABEC4:
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4ABEC4u), "std::length_error");
    label_000ABECF:
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABEEBu)); sfera_sub_004A9B40(cpu, LIFT_CODE_TOKEN_VA(0x4ABEEBu));
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    goto label_000ABE5D;
    label_000ABEF8:
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABF0Fu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4ABF0Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABF16u)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x4ABF16u));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_000ABF20;
    cpu->ecx = 0u;
    goto label_000ABF22;
    label_000ABF20:
    cpu->ecx = lift_load32(cpu->ecx);
    label_000ABF22:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000ABF2E;
    cpu->eax -= cpu->edx;
    label_000ABF2E:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ecx + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ecx + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    --cpu->eax;
    label_000ABF3E:
    cpu->ecx = cpu->edi;
    lift_store32(cpu->edi + 0x264u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABF4Bu)); sfera_sub_004A9FF0(cpu, LIFT_CODE_TOKEN_VA(0x4ABF4Bu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->edi + 0x268u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xABF59u)); sfera_sub_004A97C0(cpu, LIFT_CODE_TOKEN_RVA(0xABF59u));
    label_000ABF59:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000ABF66;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABF63u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ABF63u));
    cpu->esp += 4u;
    label_000ABF66:
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ABF80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) == (uint32_t)(cpu->eax)) goto label_000AC023;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000ABF93:
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    --cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000ABFA2;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000ABFA2:
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000ABFAB;
    cpu->eax -= cpu->edx;
    label_000ABFAB:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    --cpu->eax;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000ABFC4;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000ABFC4:
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000ABFCD;
    cpu->eax -= cpu->edx;
    label_000ABFCD:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABFDFu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4ABFDFu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ABFEFu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4ABFEFu));
    cpu->ecx = lift_load32(cpu->edi + 0x38u);
    lift_store32(cpu->esi + 0x38u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x3Cu);
    cpu->eax = (uint32_t)(cpu->edi + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x40u);
    lift_store32(cpu->esi + 0x3Cu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC007u)); sfera_sub_004AADE0(cpu, LIFT_CODE_TOKEN_VA(0x4AC007u));
    cpu->edi += 0x58u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x58u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC013u)); sfera_sub_004AAB50(cpu, LIFT_CODE_TOKEN_VA(0x4AC013u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->eax)) goto label_000ABF93;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AC023:
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->ebx, 0u);
    lift_store32(cpu->ebx + 4u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC05C;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC04F;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ebx, cpu->ecx);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
    label_000AC04F:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ebx + 8u, cpu->eax);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
    label_000AC05C:
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000AC11B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000AC087:
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000AC093;
    cpu->edi = 0u;
    goto label_000AC095;
    label_000AC093:
    cpu->edi = lift_load32(cpu->edx);
    label_000AC095:
    cpu->edx = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AC09E;
    cpu->eax -= cpu->edx;
    label_000AC09E:
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000AC0A8;
    cpu->edx = lift_load32(cpu->edx);
    label_000AC0A8:
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ecx)) goto label_000AC0B1;
    cpu->ecx -= cpu->esi;
    label_000AC0B1:
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC0C9u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AC0C9u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC0D9u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AC0D9u));
    cpu->edx = lift_load32(cpu->esi + 0x38u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x40u);
    lift_store32(cpu->edi + 0x38u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_store32(cpu->edi + 0x3Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC0F1u)); sfera_sub_004AADE0(cpu, LIFT_CODE_TOKEN_VA(0x4AC0F1u));
    cpu->esi += 0x58u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edi + 0x58u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC0FDu)); sfera_sub_004AAB50(cpu, LIFT_CODE_TOKEN_VA(0x4AC0FDu));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    ++cpu->eax;
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000AC087;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AC11B:
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->ebx, 0u);
    lift_store32(cpu->ebx + 4u, 0u);
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC13D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC13D;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ebx, cpu->edx);
    label_000AC13D:
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x3Cu;
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    cpu->eax -= cpu->edi;
    cpu->ebx = cpu->esi;
    cpu->ebx -= cpu->edi;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AC18A;
    label_000AC179:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_000AC179;
    label_000AC18A:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000AC279;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000AC279;
    goto label_000AC1A3;
    label_000AC1A0:
    cpu->esi = lift_load32(cpu->ebp + 0x1Cu);
    label_000AC1A3:
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->edx += cpu->edi;
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    cpu->ecx = cpu->edi;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_000AC1CC;
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    cpu->ebx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 4u);
    goto label_000AC1E7;
    label_000AC1CC:
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->ebx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    goto label_000AC1E7;
    label_000AC1E3:
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_000AC1E7:
    cpu->edx = lift_load32(cpu->ebx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->esi)) goto label_000AC1F2;
    cpu->eax -= cpu->edx;
    label_000AC1F2:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_000AC1FF;
    cpu->ecx -= cpu->edx;
    label_000AC1FF:
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->edi = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC214u)); sfera_sub_004AB320(cpu, LIFT_CODE_TOKEN_VA(0x4AC214u));
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx -= cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000AC240;
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    cpu->esi += cpu->edx;
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    goto label_000AC259;
    label_000AC240:
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->eax = cpu->edi;
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    label_000AC259:
    cpu->esi = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x3Cu))) goto label_000AC1E3;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    --cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000AC1A0;
    label_000AC279:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC2AF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC2AF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000AC2B5;
    label_000AC2AF:
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000AC2BB;
    label_000AC2B5:
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000AC2BB:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC2D3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC2D3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000AC2D7;
    label_000AC2D3:
    cpu->edi = 0u;
    goto label_000AC2D9;
    label_000AC2D7:
    cpu->edi = lift_load32(cpu->eax);
    label_000AC2D9:
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC2F3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC2F3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC2F3;
    cpu->ecx = lift_load32(cpu->eax);
    label_000AC2F3:
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC30Fu)); sfera_sub_004AB270(cpu, LIFT_CODE_TOKEN_VA(0x4AC30Fu));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AC33B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AC33B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->esi, cpu->ecx);
    label_000AC33B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC350(LiftCpu* cpu, uint32_t stop_address) {
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
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC37B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC37B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC37B:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC3A2;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC3A2;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC3A2:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC3C9;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC3C9;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_000AC3C9:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC3D7u)); sfera_sub_004ABF80(cpu, LIFT_CODE_TOKEN_VA(0x4AC3D7u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC3E0(LiftCpu* cpu, uint32_t stop_address) {
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
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC40B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC40B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC40B:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC432;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC432;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC432:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC459;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AC459;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_000AC459:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC467u)); sfera_sub_004AC070(cpu, LIFT_CODE_TOKEN_VA(0x4AC467u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC4C7;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_000AC480:
    --cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AC4C5;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_000AC496;
    cpu->ecx -= cpu->edx;
    label_000AC496:
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AC4A3;
    cpu->eax -= cpu->edx;
    label_000AC4A3:
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC4B4u)); sfera_sub_004AB320(cpu, LIFT_CODE_TOKEN_VA(0x4AC4B4u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000AC480;
    label_000AC4C5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AC4C7:
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->ebx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC4FB;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC4FB;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC4FB:
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC50Eu)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x4AC50Eu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC52E;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC52E;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC52E:
    cpu->edx = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC541u)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x4AC541u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC54Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AC54Du));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ebp = cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC570u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AC570u));
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->eax -= cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esp -= 0xCu;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AC628;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC5A4;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC5A4;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC5A4:
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC5CB;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC5CB;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC5CB:
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x38u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC5E3u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AC5E3u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC5ECu)); sfera_sub_004AC350(cpu, LIFT_CODE_TOKEN_VA(0x4AC5ECu));
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_000AC6BD;
    cpu->edi |= 0xFFFFFFFFu;
    label_000AC5F7:
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000AC620;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC60Au)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4AC60Au));
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000AC618;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000AC618:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AC620;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000AC620:
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AC5F7;
    goto label_000AC6BD;
    label_000AC628:
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC63A;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC63A;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC63A:
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC652u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AC652u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x38u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC672;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AC672;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AC672:
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC682u)); sfera_sub_004AC3E0(cpu, LIFT_CODE_TOKEN_VA(0x4AC682u));
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_000AC6BD;
    cpu->edi |= 0xFFFFFFFFu;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000AC690:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AC6BA;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AC6A7;
    cpu->eax -= cpu->ecx;
    label_000AC6A7:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC6B2u)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4AC6B2u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AC6BA;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000AC6BA:
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AC690;
    label_000AC6BD:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC6D3u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AC6D3u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC6DAu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AC6DAu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC6F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000AC727;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAC727u)); sfera_sub_004A8E40(cpu, LIFT_CODE_TOKEN_RVA(0xAC727u));
    label_000AC727:
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000AC731;
    cpu->edi = lift_load32(cpu->esi + 8u);
    label_000AC731:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    --cpu->edi;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_000AC74F;
    lift_push32(cpu, 0x68u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC742u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AC742u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC78D;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    label_000AC74F:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AC773;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAC773u)); sfera_sub_004AB1B0(cpu, LIFT_CODE_TOKEN_RVA(0xAC773u));
    label_000AC773:
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AC78D:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC7BBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AC7BBu));
    lift_trap(cpu, 0x4AC7BBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC7C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000AC84B;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000AC84B;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC7EE;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC7EE;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AC7F2;
    label_000AC7EE:
    cpu->edx = 0u;
    goto label_000AC7F4;
    label_000AC7F2:
    cpu->edx = lift_load32(cpu->eax);
    label_000AC7F4:
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC808;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC808;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AC80C;
    label_000AC808:
    cpu->ecx = 0u;
    goto label_000AC80E;
    label_000AC80C:
    cpu->ecx = lift_load32(cpu->eax);
    label_000AC80E:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC822;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC822;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AC826;
    label_000AC822:
    cpu->eax = 0u;
    goto label_000AC828;
    label_000AC826:
    cpu->eax = lift_load32(cpu->eax);
    label_000AC828:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC837u)); sfera_sub_004AC150(cpu, LIFT_CODE_TOKEN_VA(0x4AC837u));
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    label_000AC84B:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edi, 0u);
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC86D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC86D;
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->eax);
    label_000AC86D:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC880(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000AC8B7;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAC8B7u)); sfera_sub_004A8E40(cpu, LIFT_CODE_TOKEN_RVA(0xAC8B7u));
    label_000AC8B7:
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    cpu->edi += lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edi)) goto label_000AC8C6;
    cpu->edi -= cpu->eax;
    label_000AC8C6:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_000AC8E3;
    lift_push32(cpu, 0x68u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC8D6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AC8D6u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AC91E;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    label_000AC8E3:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AC907;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAC907u)); sfera_sub_004AB1B0(cpu, LIFT_CODE_TOKEN_RVA(0xAC907u));
    label_000AC907:
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AC91E:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC94Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AC94Cu));
    lift_trap(cpu, 0x4AC94Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC950(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x70u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC989u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AC989u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AC99C;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    goto label_000AC9A3;
    label_000AC99C:
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    cpu->esi = cpu->eax;
    label_000AC9A3:
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebp + 0x28u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ACB9C;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ecx)) goto label_000ACAEC;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    label_000AC9C8:
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000ACA1A;
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000AC9D8;
    cpu->edx = 0u;
    goto label_000AC9DA;
    label_000AC9D8:
    cpu->edx = lift_load32(cpu->ecx);
    label_000AC9DA:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AC9E3;
    cpu->eax -= cpu->ecx;
    label_000AC9E3:
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AC9F1u)); sfera_sub_004AC6F0(cpu, LIFT_CODE_TOKEN_VA(0x4AC9F1u));
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0x1Cu, cpu->eax);
    goto label_000AC9C8;
    label_000ACA1A:
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA36u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACA36u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA3Du)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACA3Du));
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA48u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACA48u));
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA5F;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA5F;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ACA63;
    label_000ACA5F:
    cpu->ecx = 0u;
    goto label_000ACA65;
    label_000ACA63:
    cpu->ecx = lift_load32(cpu->eax);
    label_000ACA65:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA7D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA7D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ACA81;
    label_000ACA7D:
    cpu->ecx = 0u;
    goto label_000ACA83;
    label_000ACA81:
    cpu->ecx = lift_load32(cpu->eax);
    label_000ACA83:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA8Du)); sfera_sub_004AC470(cpu, LIFT_CODE_TOKEN_VA(0x4ACA8Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAAAu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACAAAu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB1u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB8u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB8u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACACDu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACACDu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAD4u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACAD4u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAE4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACAE4u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    goto label_000ACB97;
    label_000ACAEC:
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    label_000ACAF3:
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000ACB45;
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000ACB03;
    cpu->edx = 0u;
    goto label_000ACB05;
    label_000ACB03:
    cpu->edx = lift_load32(cpu->ecx);
    label_000ACB05:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000ACB0E;
    cpu->eax -= cpu->ecx;
    label_000ACB0E:
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB1Cu)); sfera_sub_004AC880(cpu, LIFT_CODE_TOKEN_VA(0x4ACB1Cu));
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0x1Cu, cpu->eax);
    goto label_000ACAF3;
    label_000ACB45:
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB5Cu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4ACB5Cu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB71u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACB71u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB78u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACB78u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF90u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB8Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACB8Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB94u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACB94u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF84u);
    label_000ACB97:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xACB9Cu)); sfera_sub_004AC7C0(cpu, LIFT_CODE_TOKEN_RVA(0xACB9Cu));
    label_000ACB9C:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AC9FA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000ACA11;
    label_000ACA05:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA0Cu)); sfera_sub_004A9320(cpu, LIFT_CODE_TOKEN_VA(0x4ACA0Cu));
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000ACA05;
    label_000ACA11:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA1Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4ACA1Au));
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA36u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACA36u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA3Du)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACA3Du));
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA48u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACA48u));
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA5F;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA5F;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ACA63;
    label_000ACA5F:
    cpu->ecx = 0u;
    goto label_000ACA65;
    label_000ACA63:
    cpu->ecx = lift_load32(cpu->eax);
    label_000ACA65:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA7D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ACA7D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ACA81;
    label_000ACA7D:
    cpu->ecx = 0u;
    goto label_000ACA83;
    label_000ACA81:
    cpu->ecx = lift_load32(cpu->eax);
    label_000ACA83:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACA8Du)); sfera_sub_004AC470(cpu, LIFT_CODE_TOKEN_VA(0x4ACA8Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAAAu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACAAAu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB1u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB8u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACAB8u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACACDu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACACDu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAD4u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACAD4u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACAE4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACAE4u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB9Cu)); sfera_sub_004AC7C0(cpu, LIFT_CODE_TOKEN_VA(0x4ACB9Cu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ACB25(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000ACB3C;
    label_000ACB30:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB37u)); sfera_sub_004A9360(cpu, LIFT_CODE_TOKEN_VA(0x4ACB37u));
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000ACB30;
    label_000ACB3C:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB45u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4ACB45u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB5Cu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4ACB5Cu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB71u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACB71u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB78u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACB78u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF90u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB8Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACB8Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB94u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4ACB94u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF84u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACB9Cu)); sfera_sub_004AC7C0(cpu, LIFT_CODE_TOKEN_VA(0x4ACB9Cu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ACBB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x78u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x8Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0xA0u);
    cpu->eax = lift_load32(cpu->esp + 0x9Cu);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACC08u)); sfera_sub_004AE100(cpu, LIFT_CODE_TOKEN_VA(0x4ACC08u));
    cpu->eax = lift_load8(cpu->edi + 0x8Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ebp = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x9Cu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACC26u)); sfera_sub_004AE9B0(cpu, LIFT_CODE_TOKEN_VA(0x4ACC26u));
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x78u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_000ACC43;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACC3Eu)); sfera_sub_004AD610(cpu, LIFT_CODE_TOKEN_VA(0x4ACC3Eu));
    goto label_000ACD2D;
    label_000ACC43:
    cpu->eax = lift_load32(cpu->edi + 0x1A8u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edi + 0x24Cu))) goto label_000ACCC8;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACC61u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4ACC61u));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_000ACC6B;
    cpu->ecx = 0u;
    goto label_000ACC6D;
    label_000ACC6B:
    cpu->ecx = lift_load32(cpu->ecx);
    label_000ACC6D:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000ACC79;
    cpu->eax -= cpu->edx;
    label_000ACC79:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACC84u)); sfera_sub_004AD610(cpu, LIFT_CODE_TOKEN_VA(0x4ACC84u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x1A8u)) == (uint32_t)(cpu->ebp)) goto label_000ACCC8;
    cpu->eax = lift_load32(cpu->edi + 0x1A4u);
    cpu->edx = lift_load32(cpu->edi + 0x19Cu);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACCA0u)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4ACCA0u));
    lift_store32(cpu->edi + 0x1A4u, (uint64_t)(lift_load32(cpu->edi + 0x1A4u)) + 1u);
    cpu->eax = lift_load32(cpu->edi + 0x1A4u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1A0u)) > (uint32_t)(cpu->eax)) goto label_000ACCBA;
    lift_store32(cpu->edi + 0x1A4u, cpu->ebp);
    label_000ACCBA:
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x1A8u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->edi + 0x1A8u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ACCC8;
    lift_store32(cpu->edi + 0x1A4u, cpu->ebp);
    label_000ACCC8:
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACCD8u)); sfera_sub_004AC880(cpu, LIFT_CODE_TOKEN_VA(0x4ACCD8u));
    cpu->ecx = lift_load32(cpu->edi + 0x1C4u);
    cpu->eax = lift_load32(cpu->edi + 0x1C0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000ACD1E;
    label_000ACCE8:
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->ebx)) goto label_000ACCF3;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000ACCE8;
    label_000ACCF3:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000ACD1E;
    cpu->ecx = (uint32_t)(cpu->edi + 0x198u);
    lift_store32(cpu->edi + 0x260u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACD08u)); sfera_sub_004AF350(cpu, LIFT_CODE_TOKEN_VA(0x4ACD08u));
    cpu->ecx = lift_load32(cpu->eax + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x58u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->edi + 0x268u, cpu->ebp);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    --cpu->ecx;
    lift_store32(cpu->edi + 0x264u, cpu->ecx);
    label_000ACD1E:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACD25u)); sfera_sub_004A9FF0(cpu, LIFT_CODE_TOKEN_VA(0x4ACD25u));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xACD2Du)); sfera_sub_004A97C0(cpu, LIFT_CODE_TOKEN_RVA(0xACD2Du));
    label_000ACD2D:
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x94u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACD41u)); sfera_sub_004AE200(cpu, LIFT_CODE_TOKEN_VA(0x4ACD41u));
    cpu->ecx = lift_load32(cpu->esp + 0x8Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x84u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ACD70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x10u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000ACD9E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000ACD9E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000ACD9E:
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000ACDCD;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000ACDCD;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000ACDCD:
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000ACDFC;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000ACDFC;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000ACDFC:
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACE08u)); sfera_sub_004AC950(cpu, LIFT_CODE_TOKEN_VA(0x4ACE08u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ACE10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x68u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x78u);
    cpu->edi = lift_load32(cpu->esp + 0x80u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x7Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1D4Cu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000ACEE4;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ACE79;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x66u)) goto label_000AD051;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACE6Fu)); sfera_sub_004A98B0(cpu, LIFT_CODE_TOKEN_VA(0x4ACE6Fu));
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000ACE79:
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x24u, 0xFu);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store8(cpu->esp + 0x10u, 0u);
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    label_000ACE93:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000ACE93;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACEA7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4ACEA7u));
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x7Cu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACEC2u)); sfera_sub_004ACBB0(cpu, LIFT_CODE_TOKEN_VA(0x4ACEC2u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) < (uint32_t)(0x10u)) goto label_000AD04A;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACED7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ACED7u));
    cpu->esp += 4u;
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000ACEE4:
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFE2B3u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(0xBu)) goto label_000AD051;
    switch ((uint32_t)(cpu->edx)) {
        case 0u: goto label_000ACEFA;
        case 1u: goto label_000ACF0C;
        case 2u: goto label_000ACF1F;
        case 3u: case 4u: case 5u: case 6u: goto label_000AD051;
        case 7u: goto label_000ACF30;
        case 8u: goto label_000ACF6E;
        case 9u: goto label_000ACFAD;
        case 10u: goto label_000AD001;
        case 11u: goto label_000AD029;
        default: lift_trap(cpu, 0x4ACEF3u, "resolved jump-table index out of range"); return;
    }
label_000ACEFA: ;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACF02u)); sfera_sub_004AA7A0(cpu, LIFT_CODE_TOKEN_VA(0x4ACF02u));
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000ACF0C:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACF15u)); sfera_sub_004ABCC0(cpu, LIFT_CODE_TOKEN_VA(0x4ACF15u));
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000ACF1F:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACF26u)); sfera_sub_004AA830(cpu, LIFT_CODE_TOKEN_VA(0x4ACF26u));
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000ACF30:
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AD04A;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACF45u)); sfera_sub_004AA900(cpu, LIFT_CODE_TOKEN_VA(0x4ACF45u));
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000ACF4D;
    cpu->eax = lift_load32(cpu->eax);
    label_000ACF4D:
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    label_000ACF51:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ACF51;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACF64u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ACF64u));
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000ACF6E:
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AD04A;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACF83u)); sfera_sub_004AA990(cpu, LIFT_CODE_TOKEN_VA(0x4ACF83u));
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000ACF8B;
    cpu->eax = lift_load32(cpu->eax);
    label_000ACF8B:
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_000ACF90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ACF90;
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ACFA3u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ACFA3u));
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000ACFAD:
    cpu->ebx = 0x10u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000ACFD2;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1E4u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x1D0u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ACFC6;
    cpu->eax = lift_load32(cpu->eax);
    label_000ACFC6:
    cpu->ecx -= cpu->eax;
    label_000ACFC8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->ecx + cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000ACFC8;
    label_000ACFD2:
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AD04A;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x200u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x1ECu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ACFE6;
    cpu->eax = lift_load32(cpu->eax);
    label_000ACFE6:
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000ACFF0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ACFF0;
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000AD001:
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AD04A;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x238u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x224u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000AD016;
    cpu->eax = lift_load32(cpu->eax);
    label_000AD016:
    cpu->ecx -= cpu->eax;
    label_000AD018:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->ecx + cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000AD018;
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000AD029:
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AD04A;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x21Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x208u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000AD03E;
    cpu->eax = lift_load32(cpu->eax);
    label_000AD03E:
    cpu->ecx -= cpu->eax;
    label_000AD040:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->ecx + cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000AD040;
    label_000AD04A:
    cpu->eax = 1u;
    goto label_000AD05B;
    label_000AD051:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAD05Bu)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_RVA(0xAD05Bu));
    label_000AD05B:
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AD0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000AD26B;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_000AD0E1;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD0D5u)); sfera_sub_004A9AA0(cpu, LIFT_CODE_TOKEN_VA(0x4AD0D5u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AD0E1:
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AD197;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD0FDu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AD0FDu));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD10Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD10Eu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD11Fu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AD11Fu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD128u)); sfera_sub_004AC290(cpu, LIFT_CODE_TOKEN_VA(0x4AD128u));
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD134u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD134u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->ebp);
    lift_store32(cpu->ecx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000AD152;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000AD152;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000AD152:
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000AD178;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000AD178;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AD178:
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD18Bu)); sfera_sub_004AC4D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD18Bu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AD197:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD1A9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AD1A9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD1B0u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AD1B0u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD1C1u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AD1C1u));
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000AD1E1;
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000AD1E1;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AD1E1:
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD1F9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AD1F9u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD202u)); sfera_sub_004AC290(cpu, LIFT_CODE_TOKEN_VA(0x4AD202u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD213u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD213u));
    cpu->esp -= 0xCu;
    cpu->esi = 0u;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->esi);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000AD231;
    cpu->ebx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000AD231;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AD231:
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD240u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD240u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000AD25E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000AD25E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000AD25E:
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAD26Bu)); sfera_sub_004ACD70(cpu, LIFT_CODE_TOKEN_RVA(0xAD26Bu));
    label_000AD26B:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AD280(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD290u)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4AD290u));
    cpu->eax = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD2A2u)); sfera_sub_004AD0B0(cpu, LIFT_CODE_TOKEN_VA(0x4AD2A2u));
    cpu->ecx = (uint32_t)(cpu->edi + 0x1B0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD2B4u)); sfera_sub_004A9980(cpu, LIFT_CODE_TOKEN_VA(0x4AD2B4u));
    cpu->edx = (uint32_t)(cpu->edi + 0x1C0u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD2C6u)); sfera_sub_004A9980(cpu, LIFT_CODE_TOKEN_VA(0x4AD2C6u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ebx = (uint32_t)(cpu->edi + 0x1D0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1D0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD2DCu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AD2DCu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ebx += 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1ECu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD2EFu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AD2EFu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edi + 0x208u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x208u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD305u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AD305u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x224u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x224u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD31Bu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AD31Bu));
    cpu->edx = lift_load32(cpu->edi + 0x240u);
    lift_store32(cpu->esi + 0x240u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x244u);
    lift_store32(cpu->esi + 0x244u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x248u);
    lift_store32(cpu->esi + 0x248u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x24Cu);
    lift_store32(cpu->esi + 0x24Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x250u);
    lift_store32(cpu->esi + 0x250u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x254u);
    lift_store32(cpu->esi + 0x254u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x258u);
    lift_store32(cpu->esi + 0x258u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x25Cu);
    lift_store32(cpu->esi + 0x25Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x260u);
    lift_store32(cpu->esi + 0x260u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x264u);
    lift_store32(cpu->esi + 0x264u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x268u);
    lift_store32(cpu->esi + 0x268u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x26Cu);
    lift_store32(cpu->esi + 0x26Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x270u);
    lift_store32(cpu->esi + 0x270u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x274u);
    lift_store32(cpu->esi + 0x274u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x278u);
    lift_store32(cpu->esi + 0x278u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x27Cu);
    lift_store32(cpu->esi + 0x27Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x280u);
    lift_store32(cpu->esi + 0x280u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x284u);
    lift_store32(cpu->esi + 0x284u, cpu->ecx);
    cpu->edi += 0x288u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x288u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD405u)); sfera_sub_004AAB50(cpu, LIFT_CODE_TOKEN_VA(0x4AD405u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AD410(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD441u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4AD441u));
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(cpu->esi + 0x198u);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextChatListControl*>(cpu->esi));
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x34u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD465u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AD465u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AD55D;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B8u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    cpu->eax = 0xFu;
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    lift_store32(cpu->esi + 0x1E0u, cpu->ebx);
    lift_store8(cpu->esi + 0x1D0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x200u, cpu->eax);
    lift_store32(cpu->esi + 0x1FCu, cpu->ebx);
    lift_store8(cpu->esi + 0x1ECu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x21Cu, cpu->eax);
    lift_store32(cpu->esi + 0x218u, cpu->ebx);
    lift_store8(cpu->esi + 0x208u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x238u, cpu->eax);
    lift_store32(cpu->esi + 0x234u, cpu->ebx);
    lift_store8(cpu->esi + 0x224u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x288u, cpu->ebx);
    lift_store32(cpu->esi + 0x28Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x290u, cpu->ebx);
    cpu->edi = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x34u, 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD51Fu)); sfera_sub_004AD280(cpu, LIFT_CODE_TOKEN_VA(0x4AD51Fu));
    if ((uint32_t)(lift_load32(cpu->edi + 0x26Cu)) == (uint32_t)(cpu->ebx)) goto label_000AD542;
    cpu->ecx = lift_load32(cpu->edi + 0x26Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x26Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAD542u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xAD542u));
    label_000AD542:
    lift_store8(cpu->esi + 0x4Bu, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AD55D:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD587u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AD587u));
    lift_trap(cpu, 0x4AD587u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AD590(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x69u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD5C3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AD5C3u));
    lift_push32(cpu, 0x298u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD5CDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AD5CDu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AD5F9;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD5E8u)); sfera_sub_004AD410(cpu, LIFT_CODE_TOKEN_VA(0x4AD5E8u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AD5F9:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AD610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x50u)) == (uint32_t)(0u)) goto label_000AD6D8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x40u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD632u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AD632u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD63Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD63Eu));
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000AD6CC;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    label_000AD651:
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AD659;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000AD65C;
    label_000AD659:
    cpu->edx = lift_load32(cpu->ebp);
    label_000AD65C:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->esi = cpu->ebx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->edi = cpu->ebx;
    cpu->eax = cpu->esi;
    cpu->edi &= 3u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AD671;
    cpu->eax -= cpu->ecx;
    label_000AD671:
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_000AD6B2;
    cpu->edx = 0x5Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD68Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AD68Cu));
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000AD694;
    cpu->ecx = 0u;
    goto label_000AD697;
    label_000AD694:
    cpu->ecx = lift_load32(cpu->ebp);
    label_000AD697:
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->esi)) goto label_000AD6A0;
    cpu->esi -= cpu->eax;
    label_000AD6A0:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD6AFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AD6AFu));
    cpu->esp += 4u;
    label_000AD6B2:
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD6C1u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD6C1u));
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000AD651;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000AD6CC:
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    sfera_sub_0049FA40(cpu, stop_address); return;
    label_000AD6D8:
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AD6E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x74u);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    cpu->edi = lift_load32(cpu->esp + 0x80u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = 0u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD73Du)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD73Du));
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x6Cu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000AD749;
    cpu->eax = lift_load32(cpu->eax);
    label_000AD749:
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += 0xFFFFFFFEu;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD764u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4AD764u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x58u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x6Cu, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000AD780;
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD77Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AD77Du));
    cpu->esp += 4u;
    label_000AD780:
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD78Au)); sfera_sub_004312A0(cpu, LIFT_CODE_TOKEN_VA(0x4AD78Au));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD79Bu)); sfera_sub_00431220(cpu, LIFT_CODE_TOKEN_VA(0x4AD79Bu));
    cpu->eax = lift_load32(cpu->edi);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esp + 0x78u))) goto label_000AD871;
    cpu->edx = 0x6Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD7BAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AD7BAu));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD7C1u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AD7C1u));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store32(cpu->esp + 0x6Cu, 1u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000AD817;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x44u, 0xFu);
    lift_store32(cpu->esp + 0x40u, 0u);
    lift_store8(cpu->esp + 0x30u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD7FBu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4AD7FBu));
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x70u, 2u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD815u)); sfera_sub_00431490(cpu, LIFT_CODE_TOKEN_VA(0x4AD815u));
    goto label_000AD819;
    label_000AD817:
    cpu->eax = 0u;
    label_000AD819:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x70u, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD833u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4AD833u));
    lift_store32(cpu->esp + 0x6Cu, 0xFFFFFFFFu);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_000AD869;
    if ((uint32_t)(lift_load32(cpu->esp + 0x3Cu)) < (uint32_t)(0x10u)) goto label_000AD854;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD851u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AD851u));
    cpu->esp += 4u;
    label_000AD854:
    lift_store32(cpu->esp + 0x3Cu, 0xFu);
    lift_store32(cpu->esp + 0x38u, 0u);
    lift_store8(cpu->esp + 0x28u, 0u);
    label_000AD869:
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi, cpu->edx);
    goto label_000AD873;
    label_000AD871:
    lift_store32(cpu->edi, cpu->eax);
    label_000AD873:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD881u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4AD881u));
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x60u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AD8B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xE8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xFCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = lift_load32(cpu->esp + 0x10Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x11Cu);
    cpu->edi = lift_load32(cpu->esp + 0x118u);
    cpu->eax = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD917u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD917u));
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x104u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000AD928;
    cpu->eax = lift_load32(cpu->eax);
    label_000AD928:
    cpu->edx = lift_load32(cpu->esp + 0x114u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    cpu->edx += 0xFFFFFFFEu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD947u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4AD947u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x9Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x104u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000AD96C;
    cpu->edx = lift_load32(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD969u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AD969u));
    cpu->esp += 4u;
    label_000AD96C:
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD976u)); sfera_sub_004312A0(cpu, LIFT_CODE_TOKEN_VA(0x4AD976u));
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD987u)); sfera_sub_00431220(cpu, LIFT_CODE_TOKEN_VA(0x4AD987u));
    cpu->eax = lift_load32(cpu->edi);
    cpu->eax += lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(lift_load32(cpu->esp + 0x110u))) goto label_000AD9A9;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->edi, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD9A4u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4AD9A4u));
    goto label_000AE0CC;
    label_000AD9A9:
    cpu->eax = 0xFu;
    lift_store32(cpu->esp + 0xB8u, cpu->eax);
    lift_store32(cpu->esp + 0xB4u, cpu->esi);
    lift_store8(cpu->esp + 0xA4u, 0u);
    lift_store32(cpu->esp + 0x104u, 1u);
    lift_store32(cpu->esp + 0x64u, cpu->eax);
    lift_store32(cpu->esp + 0x60u, cpu->esi);
    lift_store8(cpu->esp + 0x50u, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esp + 0x108u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AD9F3u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4AD9F3u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0xB0u);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0x110u, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADA14u)); sfera_sub_00490040(cpu, LIFT_CODE_TOKEN_VA(0x4ADA14u));
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x9Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x104u, 2u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ADA3B;
    cpu->eax = lift_load32(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADA38u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ADA38u));
    cpu->esp += 4u;
    label_000ADA3B:
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000ADA58;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADA53u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4ADA53u));
    goto label_000AE06E;
    label_000ADA58:
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADA64u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADA64u));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx -= cpu->esi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0xC8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0x110u, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADA83u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4ADA83u));
    cpu->ebx = 0x10u;
    lift_store8(cpu->esp + 0x104u, 6u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x80u)) < (uint32_t)(cpu->ebx)) goto label_000ADAA6;
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADAA3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ADAA3u));
    cpu->esp += 4u;
    label_000ADAA6:
    cpu->ecx = lift_load32(cpu->esp + 0xD0u);
    cpu->ecx -= lift_load32(cpu->esp + 0xB4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCCu);
    lift_store32(cpu->esp + 0x8Cu, 0xFu);
    lift_store32(cpu->esp + 0x88u, 0u);
    lift_store8(cpu->esp + 0x78u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADAE6u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4ADAE6u));
    cpu->ecx = lift_load32(cpu->esp + 0xC0u);
    lift_store8(cpu->esp + 0x104u, 7u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xD4u)) >= (uint32_t)(cpu->ebx)) goto label_000ADB05;
    cpu->ecx = (uint32_t)(cpu->esp + 0xC0u);
    label_000ADB05:
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADB1Au)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADB1Au));
    cpu->ecx = lift_load32(cpu->esp + 0xA4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xB8u)) >= (uint32_t)(cpu->ebx)) goto label_000ADB31;
    cpu->ecx = (uint32_t)(cpu->esp + 0xA4u);
    label_000ADB31:
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADB42u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADB42u));
    cpu->eax = lift_load32(cpu->edi);
    cpu->eax += lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(lift_load32(cpu->esp + 0x110u))) goto label_000ADCC2;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xC8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADB6Au)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x4ADB6Au));
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) == (uint32_t)(0xFFFFFFFFu)) goto label_000ADEA4;
    cpu->eax = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADB8Au)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADB8Au));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = 0u;
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0x110u, 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADBA4u)); sfera_sub_00490040(cpu, LIFT_CODE_TOKEN_VA(0x4ADBA4u));
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x9Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x104u, 7u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ADBCB;
    cpu->edx = lift_load32(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADBC8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ADBC8u));
    cpu->esp += 4u;
    label_000ADBCB:
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000ADDBD;
    cpu->eax = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADBE2u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADBE2u));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0x110u, 9u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADBFDu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4ADBFDu));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(0xBu) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_store8(cpu->esp + 0x104u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADC12u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ADC12u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADC24u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x4ADC24u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x80u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000ADC36;
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    label_000ADC36:
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADC47u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADC47u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x64u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000ADC56;
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    label_000ADC56:
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADC67u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADC67u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->edx = 0xA9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADC7Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4ADC7Cu));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADC83u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4ADC83u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store8(cpu->esp + 0x104u, 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ADE8C;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADCB5u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADCB5u));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    goto label_000AE034;
    label_000ADCC2:
    if ((uint32_t)(lift_load32(cpu->esp + 0x60u)) == (uint32_t)(0u)) goto label_000ADDA2;
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x64u)) >= (uint32_t)(cpu->ebx)) goto label_000ADCDB;
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    label_000ADCDB:
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADCECu)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADCECu));
    cpu->edx = 0xB5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADCFBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4ADCFBu));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADD02u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4ADD02u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store8(cpu->esp + 0x104u, 0xDu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ADD30;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADD2Eu)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADD2Eu));
    goto label_000ADD32;
    label_000ADD30:
    cpu->eax = 0u;
    label_000ADD32:
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x108u, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADD4Eu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4ADD4Eu));
    cpu->edx = 0xB6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADD5Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4ADD5Du));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADD64u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4ADD64u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store8(cpu->esp + 0x104u, 0xEu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ADD88;
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADD86u)); sfera_sub_00431490(cpu, LIFT_CODE_TOKEN_VA(0x4ADD86u));
    goto label_000ADD8A;
    label_000ADD88:
    cpu->eax = 0u;
    label_000ADD8A:
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x108u, 7u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xADDA2u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0xADDA2u));
    label_000ADDA2:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADDB7u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4ADDB7u));
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_store32(cpu->edi, cpu->ecx);
    label_000ADDBD:
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000ADE9B;
    cpu->edx = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADDD9u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADDD9u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0xB0u);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0x110u, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADDFAu)); sfera_sub_00490040(cpu, LIFT_CODE_TOKEN_VA(0x4ADDFAu));
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x9Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x104u, 7u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ADE21;
    cpu->eax = lift_load32(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADE1Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ADE1Eu));
    cpu->esp += 4u;
    label_000ADE21:
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000ADF4A;
    if ((uint32_t)(lift_load32(cpu->esp + 0xF0u)) < (uint32_t)(0x10u)) goto label_000ADE43;
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADE40u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ADE40u));
    cpu->esp += 4u;
    label_000ADE43:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xD4u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xF0u, 0xFu);
    lift_store32(cpu->esp + 0xECu, 0u);
    lift_store8(cpu->esp + 0xDCu, 0u);
    lift_store8(cpu->esp + 0x104u, 2u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000ADA58;
    cpu->edx = lift_load32(cpu->esp + 0xC0u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADE84u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4ADE84u));
    cpu->esp += 4u;
    goto label_000ADA58;
    label_000ADE8C:
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    goto label_000AE034;
    label_000ADE9B:
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = 0x10u;
    label_000ADEA4:
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x64u)) >= (uint32_t)(cpu->ebx)) goto label_000ADEB2;
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    label_000ADEB2:
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADEC3u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADEC3u));
    cpu->edx = 0xC1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADED2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4ADED2u));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADED9u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4ADED9u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store8(cpu->esp + 0x104u, 0xFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ADF09;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF07u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADF07u));
    goto label_000ADF0B;
    label_000ADF09:
    cpu->eax = 0u;
    label_000ADF0B:
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x108u, 7u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF25u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4ADF25u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF31u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ADF31u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xC0u);
    lift_store8(cpu->esp + 0x104u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF45u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ADF45u));
    goto label_000AE073;
    label_000ADF4A:
    cpu->eax = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF59u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4ADF59u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0x110u, 0x11u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF70u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4ADF70u));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(0x13u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_store8(cpu->esp + 0x104u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF85u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4ADF85u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADF97u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x4ADF97u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x80u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000ADFA9;
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    label_000ADFA9:
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADFBEu)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADFBEu));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x64u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000ADFCD;
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    label_000ADFCD:
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADFDEu)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4ADFDEu));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->edx = 0xCFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADFF3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4ADFF3u));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ADFFAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4ADFFAu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store8(cpu->esp + 0x104u, 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AE02A;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE028u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE028u));
    goto label_000AE02C;
    label_000AE02A:
    cpu->eax = 0u;
    label_000AE02C:
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    label_000AE034:
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x108u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE045u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4AE045u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE04Eu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4AE04Eu));
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE05Au)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4AE05Au));
    cpu->ecx = (uint32_t)(cpu->esp + 0xC0u);
    lift_store8(cpu->esp + 0x104u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAE06Eu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0xAE06Eu));
    label_000AE06E:
    cpu->ebx = 0x10u;
    label_000AE073:
    cpu->edx = 0xD4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE082u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AE082u));
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE088u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE088u));
    cpu->esp += 4u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x64u)) < (uint32_t)(cpu->ebx)) goto label_000AE09E;
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE09Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE09Bu));
    cpu->esp += 4u;
    label_000AE09E:
    lift_store32(cpu->esp + 0x64u, 0xFu);
    lift_store32(cpu->esp + 0x60u, 0u);
    lift_store8(cpu->esp + 0x50u, 0u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xB8u)) < (uint32_t)(cpu->ebx)) goto label_000AE0CC;
    cpu->ecx = lift_load32(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE0C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE0C9u));
    cpu->esp += 4u;
    label_000AE0CC:
    cpu->ecx = lift_load32(cpu->esp + 0xFCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xF4u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AE100(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->ebx = 0u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edi = 0xFu;
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE149u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AE149u));
    cpu->ebp = (uint32_t)(cpu->esi + 0x1Cu);
    lift_store32(cpu->ebp + 0x14u, cpu->edi);
    lift_store32(cpu->ebp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->ebp, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edi = (uint32_t)(cpu->esi + 0x40u);
    lift_store32(cpu->esi + 0x38u, cpu->ecx);
    lift_store32(cpu->esi + 0x3Cu, cpu->edx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x30u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE17Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AE17Cu));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AE1CF;
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x58u, cpu->ebx);
    lift_store32(cpu->esi + 0x5Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x60u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esi + 0x40u);
    lift_store8(cpu->esp + 0x30u, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE1B7u)); sfera_sub_00490C50(cpu, LIFT_CODE_TOKEN_VA(0x4AE1B7u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000AE1CF:
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE1F9u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AE1F9u));
    lift_trap(cpu, 0x4AE1F9u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AE200(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x58u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AE216;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE213u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE213u));
    cpu->esp += 4u;
    label_000AE216:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x40u);
    lift_store32(cpu->esi + 0x58u, cpu->ebx);
    lift_store32(cpu->esi + 0x5Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x60u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE228u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4AE228u));
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE231u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE231u));
    cpu->edi = 0x10u;
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) < (uint32_t)(cpu->edi)) goto label_000AE24D;
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE24Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE24Au));
    cpu->esp += 4u;
    label_000AE24D:
    lift_store32(cpu->esi + 0x30u, 0xFu);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esi + 0x1Cu, cpu->ebx & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000AE26B;
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE268u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE268u));
    cpu->esp += 4u;
    label_000AE26B:
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AE280(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x120u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x134u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x5Cu);
    cpu->eax = lift_load32(cpu->esi + 0x58u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AE2E9;
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ecx)) goto label_000AE2E6;
    cpu->edi = cpu->ecx;
    cpu->edi -= cpu->eax;
    label_000AE2D1:
    cpu->ebx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax + cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->edx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_000AE2D1;
    label_000AE2E6:
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    label_000AE2E9:
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x50u)) == (uint32_t)(cpu->ebx)) goto label_000AE7F0;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0x140u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE306u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AE306u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AE818;
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
    cpu->esi += 0x40u;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x140u, 1u);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE356u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AE356u));
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE362u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE362u));
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000AE764;
    label_000AE374:
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AE380;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000AE382;
    label_000AE380:
    cpu->edx = lift_load32(cpu->edi);
    label_000AE382:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->ebx = cpu->ebp;
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->ebx;
    cpu->ebp &= 3u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AE395;
    cpu->eax -= cpu->ecx;
    label_000AE395:
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AE57B;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AE3E4;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AE73B;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000AE3BF;
    cpu->edx = 0u;
    goto label_000AE3C1;
    label_000AE3BF:
    cpu->edx = lift_load32(cpu->edi);
    label_000AE3C1:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AE3CC;
    cpu->eax -= cpu->ecx;
    label_000AE3CC:
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE3DFu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4AE3DFu));
    goto label_000AE73B;
    label_000AE3E4:
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) == (uint32_t)(0u)) goto label_000AE54E;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE407u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE407u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE40Eu)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x4AE40Eu));
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AE418;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_000AE41A;
    label_000AE418:
    cpu->esi = lift_load32(cpu->ecx);
    label_000AE41A:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AE42E;
    cpu->eax -= cpu->edx;
    label_000AE42E:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_000AE54E;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE451u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x4AE451u));
    cpu->edi = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AE45F;
    cpu->ecx = 0u;
    goto label_000AE461;
    label_000AE45F:
    cpu->ecx = lift_load32(cpu->eax);
    label_000AE461:
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AE46C;
    cpu->eax -= cpu->edx;
    label_000AE46C:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->eax = (uint32_t)(cpu->esp + 0x114u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE482u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE482u));
    cpu->esi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x140u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE49Bu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE49Bu));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xC4u);
    lift_store8(cpu->esp + 0x140u, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE4B2u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE4B2u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x140u, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE4C2u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x4AE4C2u));
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0xD4u)) < (uint32_t)(cpu->esi)) goto label_000AE4E0;
    cpu->edx = lift_load32(cpu->esp + 0xC0u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE4DDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE4DDu));
    cpu->esp += 4u;
    label_000AE4E0:
    cpu->edi = 0u;
    cpu->ebx = 0xFu;
    lift_store32(cpu->esp + 0xD4u, cpu->ebx);
    lift_store32(cpu->esp + 0xD0u, cpu->edi);
    lift_store8(cpu->esp + 0xC0u, 0u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x9Cu)) < (uint32_t)(cpu->esi)) goto label_000AE516;
    cpu->eax = lift_load32(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE513u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE513u));
    cpu->esp += 4u;
    label_000AE516:
    lift_store32(cpu->esp + 0x9Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x98u, cpu->edi);
    lift_store8(cpu->esp + 0x88u, 0u);
    lift_store8(cpu->esp + 0x13Cu, 1u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x128u)) < (uint32_t)(cpu->esi)) goto label_000AE73B;
    cpu->ecx = lift_load32(cpu->esp + 0x114u);
    lift_push32(cpu, cpu->ecx);
    goto label_000AE733;
    label_000AE54E:
    if ((uint32_t)(cpu->edi) != 0u) goto label_000AE556;
    cpu->edx = 0u;
    goto label_000AE558;
    label_000AE556:
    cpu->edx = lift_load32(cpu->edi);
    label_000AE558:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AE563;
    cpu->eax -= cpu->ecx;
    label_000AE563:
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE576u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4AE576u));
    goto label_000AE73B;
    label_000AE57B:
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) == (uint32_t)(0u)) goto label_000AE705;
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE59Bu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE59Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE5A2u)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x4AE5A2u));
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AE5AC;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_000AE5AE;
    label_000AE5AC:
    cpu->esi = lift_load32(cpu->ecx);
    label_000AE5AE:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AE5C2;
    cpu->eax -= cpu->edx;
    label_000AE5C2:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_000AE705;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE5E5u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x4AE5E5u));
    cpu->edi = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AE5F3;
    cpu->ecx = 0u;
    goto label_000AE5F5;
    label_000AE5F3:
    cpu->ecx = lift_load32(cpu->eax);
    label_000AE5F5:
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AE600;
    cpu->eax -= cpu->edx;
    label_000AE600:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->eax = (uint32_t)(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE616u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE616u));
    cpu->esi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x140u, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE62Fu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE62Fu));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xFCu);
    lift_store8(cpu->esp + 0x140u, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE646u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE646u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x140u, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE656u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x4AE656u));
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10Cu)) < (uint32_t)(cpu->esi)) goto label_000AE674;
    cpu->edx = lift_load32(cpu->esp + 0xF8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE671u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE671u));
    cpu->esp += 4u;
    label_000AE674:
    cpu->edi = 0xFu;
    lift_store32(cpu->esp + 0x10Cu, cpu->edi);
    lift_store32(cpu->esp + 0x108u, 0u);
    lift_store8(cpu->esp + 0xF8u, 0u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xB8u)) < (uint32_t)(cpu->esi)) goto label_000AE6AC;
    cpu->eax = lift_load32(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE6A9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE6A9u));
    cpu->esp += 4u;
    label_000AE6AC:
    lift_store32(cpu->esp + 0xB8u, cpu->edi);
    lift_store32(cpu->esp + 0xB4u, 0u);
    lift_store8(cpu->esp + 0xA4u, 0u);
    lift_store8(cpu->esp + 0x13Cu, 1u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xF0u)) < (uint32_t)(cpu->esi)) goto label_000AE6E7;
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE6E4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE6E4u));
    cpu->esp += 4u;
    label_000AE6E7:
    lift_store32(cpu->esp + 0xF0u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0xECu, 0u);
    lift_store8(cpu->esp + 0xDCu, 0u);
    label_000AE705:
    cpu->edx = 0x4Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE714u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AE714u));
    if ((uint32_t)(cpu->edi) != 0u) goto label_000AE71C;
    cpu->ecx = 0u;
    goto label_000AE71E;
    label_000AE71C:
    cpu->ecx = lift_load32(cpu->edi);
    label_000AE71E:
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AE729;
    cpu->eax -= cpu->edx;
    label_000AE729:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    lift_push32(cpu, cpu->eax);
    label_000AE733:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE738u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE738u));
    cpu->esp += 4u;
    label_000AE73B:
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    ++cpu->ebp;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE754u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE754u));
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebx = 0u;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000AE374;
    label_000AE764:
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE772u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AE772u));
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE780u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AE780u));
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x24u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AE7A5;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AE7A5;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_000AE7A5:
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x30u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AE7CC;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AE7CC;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_000AE7CC:
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE7DAu)); sfera_sub_0048FF40(cpu, LIFT_CODE_TOKEN_VA(0x4AE7DAu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE7E3u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4AE7E3u));
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE7EDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AE7EDu));
    cpu->esp += 4u;
    label_000AE7F0:
    cpu->ecx = lift_load32(cpu->esp + 0x134u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x12Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AE818:
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE842u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AE842u));
    lift_trap(cpu, 0x4AE842u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AE850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 0x58u);
    cpu->ecx = lift_load32(cpu->ebp + 0x5Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ebp + 0x58u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AE88F;
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ecx)) goto label_000AE88C;
    cpu->esi = cpu->ecx;
    cpu->esi -= cpu->eax;
    label_000AE873:
    cpu->edi = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->edx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_000AE873;
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    label_000AE88C:
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000AE88F:
    cpu->eax = lift_load32(cpu->ebp + 0x50u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000AE908;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE8ACu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AE8ACu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE8B3u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AE8B3u));
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AE8BD;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_000AE8BF;
    label_000AE8BD:
    cpu->esi = lift_load32(cpu->ecx);
    label_000AE8BF:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AE8D3;
    cpu->eax -= cpu->edx;
    label_000AE8D3:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000AE9A7;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE901u)); sfera_sub_004AB070(cpu, LIFT_CODE_TOKEN_VA(0x4AE901u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AE908:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AE98A;
    (void)cpu;
    label_000AE910:
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE923u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AE923u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE92Au)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4AE92Au));
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AE934;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_000AE936;
    label_000AE934:
    cpu->esi = lift_load32(cpu->ecx);
    label_000AE936:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AE94A;
    cpu->eax -= cpu->edx;
    label_000AE94A:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_000AE97E;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AE97B;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAE97Bu)); sfera_sub_004AB070(cpu, LIFT_CODE_TOKEN_RVA(0xAE97Bu));
    label_000AE97B:
    cpu->ebx = (uint32_t)(cpu->edi + 1u);
    label_000AE97E:
    ++cpu->edi;
    cpu->eax = cpu->ebp;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->eax + 0x50u))) goto label_000AE910;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_000AE98A:
    cpu->eax = lift_load32(cpu->ebp + 0x50u);
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->eax)) goto label_000AE9A6;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    --cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAE9A6u)); sfera_sub_004AB070(cpu, LIFT_CODE_TOKEN_RVA(0xAE9A6u));
    label_000AE9A6:
    cpu->ebx = lift_pop32(cpu);
    label_000AE9A7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AE9B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x50u)) == (uint32_t)(cpu->ebx)) goto label_000AEBD7;
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0x68u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AE9F7u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AE9F7u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AEBED;
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x50u, cpu->ebx);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_store32(cpu->esp + 0x68u, 1u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEA42u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AEA42u));
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEA4Fu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AEA4Fu));
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000AEB3D;
    label_000AEA61:
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AEA6D;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000AEA6F;
    label_000AEA6D:
    cpu->edx = lift_load32(cpu->eax);
    label_000AEA6F:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->esi = cpu->ebp;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->edi = cpu->ebp;
    cpu->eax = cpu->esi;
    cpu->edi &= 3u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AEA84;
    cpu->eax -= cpu->ecx;
    label_000AEA84:
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AEADB;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AEB19;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000AEAA7;
    cpu->eax = 0u;
    goto label_000AEAA9;
    label_000AEAA7:
    cpu->eax = lift_load32(cpu->eax);
    label_000AEAA9:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->esi)) goto label_000AEAB2;
    cpu->esi -= cpu->ecx;
    label_000AEAB2:
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x74u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEAD9u)); sfera_sub_004AD6E0(cpu, LIFT_CODE_TOKEN_VA(0x4AEAD9u));
    goto label_000AEB19;
    label_000AEADB:
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000AEAE7;
    cpu->eax = 0u;
    goto label_000AEAE9;
    label_000AEAE7:
    cpu->eax = lift_load32(cpu->eax);
    label_000AEAE9:
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->esi)) goto label_000AEAF2;
    cpu->esi -= cpu->ecx;
    label_000AEAF2:
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x74u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAEB19u)); sfera_sub_004AD8B0(cpu, LIFT_CODE_TOKEN_RVA(0xAEB19u));
    label_000AEB19:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x40u;
    ++cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEB2Bu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AEB2Bu));
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000AEA61;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_000AEB3D:
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEB4Bu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AEB4Bu));
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEB59u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AEB59u));
    cpu->eax = lift_load32(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x80u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AEB81;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AEB81;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AEB81:
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x8Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AEBAB;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AEBAB;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AEBAB:
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEBBAu)); sfera_sub_0048FF40(cpu, LIFT_CODE_TOKEN_VA(0x4AEBBAu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEBC1u)); sfera_sub_004AE850(cpu, LIFT_CODE_TOKEN_VA(0x4AEBC1u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEBCAu)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4AEBCAu));
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEBD4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AEBD4u));
    cpu->esp += 4u;
    label_000AEBD7:
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000AEBED:
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEC17u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AEC17u));
    lift_trap(cpu, 0x4AEC17u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AEC20(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(cpu->esi) != 0u) goto label_000AEC27;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AEC27:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"RIGHT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xAEC36u), LIFT_CODE_TOKEN_RVA(0xAEC34u))) { return; }
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AEC44;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AEC44:
    lift_push32(cpu, (uintptr_t)"CENTER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xAEC4Cu), LIFT_CODE_TOKEN_RVA(0xAEC4Au))) { return; }
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AEC5A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AEC5A:
    lift_push32(cpu, (uintptr_t)"PARAGRAPH"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xAEC62u), LIFT_CODE_TOKEN_RVA(0xAEC60u))) { return; }
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFDu;
    cpu->eax += 3u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AEC80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000AEC80;
    label_000A6170:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x34u);
    cpu->esi -= lift_load32(cpu->ecx + 0x30u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A61D9;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    label_000A61A0:
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_store8(cpu->edi + cpu->edx + 0x124u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->ecx + 0x30u);
    lift_store8(cpu->edi + cpu->eax + 0x125u, cpu->ebx & 0xFFu);
    cpu->esi = lift_load32(cpu->ecx + 0x34u);
    cpu->esi -= lift_load32(cpu->ecx + 0x30u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    ++cpu->ebp;
    cpu->eax += cpu->edx;
    cpu->edi += 0x128u;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->eax)) goto label_000A61A0;
    cpu->edi = lift_pop32(cpu);
    label_000A61D9:
    cpu->esi = lift_load32(cpu->ecx + 0x44u);
    cpu->esi -= lift_load32(cpu->ecx + 0x40u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000A621C;
    cpu->eax = 0u;
    label_000A6200:
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    lift_store8(cpu->edx + cpu->eax + 0x124u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    lift_store8(cpu->edx + cpu->eax + 0x125u, cpu->ebx & 0xFFu);
    cpu->eax += 0x128u;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A6200;
    label_000A621C:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AEC80:
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AECD9;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x2A8u)) >= (int32_t)(uint32_t)(0u)) goto label_000AEC9F;
    lift_store32(cpu->eax + 0x2A8u, 0u);
    label_000AEC9F:
    cpu->edx = lift_load32(cpu->eax + 0x2A4u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x2A8u)) <= (uint32_t)(cpu->edx)) goto label_000AECB3;
    lift_store32(cpu->eax + 0x2A8u, cpu->edx);
    label_000AECB3:
    cpu->edx = lift_load32(cpu->eax + 0x2A8u);
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    lift_store32(cpu->eax + 0x2B0u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x2Cu);
    lift_store32(cpu->eax + 0x2ACu, 0u);
    lift_store32(cpu->eax + 0x2B4u, cpu->edx);
    goto label_000A6170;
    label_000AECD9:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AECE0(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2CCu)) != (uint8_t)(0u)) goto label_000AED34;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000AED33;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AED33;
    cpu->edx = lift_load32((uintptr_t)"buffer");
    lift_store32(cpu->ecx + 0x1A0u, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"buffer") + 4u)) & 0xFFFFu);
    lift_store16(cpu->ecx + 0x1A4u, cpu->edx & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"buffer") + 6u)) & 0xFFu);
    lift_store8(cpu->ecx + 0x1A6u, cpu->edx & 0xFFu);
    lift_store8(cpu->ecx + 0x2A0u, 0u);
    lift_store32(cpu->ecx + 0x300u, cpu->esi);
    lift_store32(cpu->ecx + 0x304u, cpu->eax);
    label_000AED33:
    cpu->esi = lift_pop32(cpu);
    label_000AED34:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AED40(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2CCu)) != (uint8_t)(0u)) goto label_000AED7F;
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AED78;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x1A0u);
    cpu->esi -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000AED60:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000AED60;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0xCu)) & 0xFFu);
    lift_store8(cpu->ecx + 0x2A0u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000AED78:
    lift_store8(cpu->ecx + 0x1A0u, 0u);
    label_000AED7F:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AED90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x50u);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AEE7B;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Au)) goto label_000AEDCE;
    label_000AEDC0:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000AEDCE;
    ++cpu->esi;
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Au)) goto label_000AEDC0;
    label_000AEDCE:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HTS"); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xAEDE4u), LIFT_CODE_TOKEN_RVA(0xAEDE2u))) { return; }
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AEE3C;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000AEE79;
    label_000AEDF7:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x5Cu)) goto label_000AEE18;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000AEDF7;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AEE18:
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_000AEE79;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEE27u)); sfera_sub_004AED40(cpu, LIFT_CODE_TOKEN_VA(0x4AEE27u));
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AEE3C:
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"mailto"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xAEE48u), LIFT_CODE_TOKEN_RVA(0xAEE46u))) { return; }
    cpu->esp += 8u;
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AEE57;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    goto label_000AEE5D;
    label_000AEE57:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"explorer");
    label_000AEE5D:
    lift_push32(cpu, (uintptr_t)"open"); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ShellExecuteA), LIFT_CODE_TOKEN_VA(0x4AEE64u));
    cpu->edx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::ShowWindow), LIFT_CODE_TOKEN_RVA(0xAEE73u));
    label_000AEE79:
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AEE7B:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AEE90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 0x198u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AEE9D;
    cpu->eax = lift_load32(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AEE9D:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AEEA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x118u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x12Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x130u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEEDFu)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4AEEDFu));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"textFormat");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEEECu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4AEEECu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AEF16;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.text_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEEFEu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4AEEFEu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AEF16;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.text_value[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEF0Cu)); sfera_sub_004AEC20(cpu, LIFT_CODE_TOKEN_VA(0x4AEF0Cu));
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ebx + 0x19Cu, cpu->eax);
    label_000AEF16:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"hyperText");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEF23u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4AEF23u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AEF47;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.text_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEF35u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4AEF35u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AEF47;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.text_value[0]);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAEF47u)); sfera_sub_004AED40(cpu, LIFT_CODE_TOKEN_RVA(0xAEF47u));
    label_000AEF47:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"scrollbar");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEF5Bu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4AEF5Bu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AEF7F;
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEF71u)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4AEF71u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebx + 0x2D8u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAEF7Fu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xAEF7Fu));
    label_000AEF7F:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"linkcolor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEF8Cu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4AEF8Cu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AEFC9;
    cpu->eax = (uint32_t)(cpu->ebx + 0x2F8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x2F4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%x %x"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4AEFA7u));
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000AEFC9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"HyperTextCtrl::LoadUI(%s) -> Not enough params in key 'linkcolor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEFC0u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4AEFC0u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEFC6u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4AEFC6u));
    cpu->esp += 0xCu;
    label_000AEFC9:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"flags");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEFD6u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4AEFD6u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF00A;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AEFE8u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4AEFE8u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF00A;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)"DISCARD_OLD_TEXT"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4AEFF6u));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AF00A;
    lift_store8(cpu->ebx + 0x308u, 1u);
    label_000AF00A:
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF016u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4AF016u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x118u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000AF325;
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x48u)) != (uint8_t)(0u)) goto label_000AF0A0;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000AF0A0;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000AF089;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000AF089:
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000AF0A0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_000AF0F0;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AF0DA;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF0D8u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_VA(0x4AF0D8u));
    cpu->edx = 0u;
    label_000AF0DA:
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->edi + 0x34u);
    cpu->edi += lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_000AF0F0:
    cpu->edi = lift_load32(cpu->esi + 0x30u);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->esi + 0x34u);
    cpu->ebx += lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ebp = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000AF114;
    cpu->eax += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->edi = 0u;
    label_000AF114:
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000AF11C;
    cpu->ebp += cpu->ebx;
    cpu->ebx = 0u;
    label_000AF11C:
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = g_sfera_graphics_runtime.display_width;
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000AF12E;
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000AF12E:
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000AF13E;
    cpu->eax -= cpu->ebx;
    cpu->ebp = cpu->eax;
    label_000AF13E:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = 0u;
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF180u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4AF180u));
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF1B0u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4AF1B0u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->eax);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x2C4u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AF253;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2C8u));
    cpu->edx = lift_load32(cpu->esi + 0xDCu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0xDCu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000AF205;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000AF205:
    cpu->edx = lift_load32(cpu->esi + 0x2C0u);
    lift_store16(cpu->esp + 8u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 8u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2BCu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->edx -= lift_load32(cpu->esi + 0x2B8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx += lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAF253u)); sfera_sub_004A65D0(cpu, LIFT_CODE_TOKEN_RVA(0xAF253u));
    label_000AF253:
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AF2C5;
    cpu->edx = lift_load32(cpu->esi + 0xDCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0xDCu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000AF273;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000AF273:
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x2C8u))));
    cpu->edx = lift_load32(cpu->esi + 0x2B4u);
    lift_store16(cpu->esp + 8u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 8u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2B0u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->edx -= lift_load32(cpu->esi + 0x2ACu);
    lift_push32(cpu, cpu->eax);
    cpu->edx += lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAF2C5u)); sfera_sub_004A65D0(cpu, LIFT_CODE_TOKEN_RVA(0xAF2C5u));
    label_000AF2C5:
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF2D5u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4AF2D5u));
    cpu->ecx = lift_load32(cpu->esi + 0x2D8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AF325;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000AF318;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000AF301;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000AF301:
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000AF318:
    cpu->ecx = lift_load32(cpu->esi + 0x2D8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000AF325:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x2ECu)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF364u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AF364u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF36Bu)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x4AF36Bu));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AF373;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000AF373:
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AF389;
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->eax -= cpu->edx;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AF389:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF3A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000AF3FD;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000AF3B3:
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AF3C0;
    cpu->eax -= cpu->edx;
    label_000AF3C0:
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ecx)) goto label_000AF3CD;
    cpu->ecx -= cpu->esi;
    label_000AF3CD:
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF3E3u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4AF3E3u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    ++cpu->eax;
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000AF3B3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AF3FD:
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ebx, cpu->eax);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x20u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF410(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF460;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AF42A;
    cpu->eax -= cpu->ecx;
    label_000AF42A:
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000AF442;
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF43Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF43Fu));
    cpu->esp += 4u;
    label_000AF442:
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, 0u);
    lift_store8(cpu->edi, 0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x10u, v); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AF460;
    lift_store32(cpu->esi + 0xCu, 0u);
    label_000AF460:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000AF4C7;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000AF480:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AF4C2;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AF497;
    cpu->eax -= cpu->ecx;
    label_000AF497:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000AF4AE;
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF4ABu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF4ABu));
    cpu->esp += 4u;
    label_000AF4AE:
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store8(cpu->edi, cpu->ebx & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AF4C2;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000AF4C2:
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) != (uint32_t)(cpu->ebx)) goto label_000AF480;
    label_000AF4C7:
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebx)) goto label_000AF4EB;
    cpu->edi = cpu->edi;
    label_000AF4D0:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    --cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AF4E7;
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF4E4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF4E4u));
    cpu->esp += 4u;
    label_000AF4E7:
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->ebx)) goto label_000AF4D0;
    label_000AF4EB:
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000AF4FB;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF4F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF4F8u));
    cpu->esp += 4u;
    label_000AF4FB:
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(0u)) goto label_000AF564;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000AF534;
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF531u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF531u));
    cpu->esp += 4u;
    label_000AF534:
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, 0u);
    lift_store8(cpu->edi, 0u);
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000AF558;
    lift_store32(cpu->esi + 0xCu, 0u);
    label_000AF558:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AF564;
    lift_store32(cpu->esi + 0xCu, 0u);
    label_000AF564:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF570(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(cpu->ebx)) goto label_000AF646;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000AF590:
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    --cpu->ebx;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AF5A1;
    cpu->ecx = 0u;
    goto label_000AF5A3;
    label_000AF5A1:
    cpu->ecx = lift_load32(cpu->eax);
    label_000AF5A3:
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ebx)) goto label_000AF5AE;
    cpu->eax -= cpu->edx;
    label_000AF5AE:
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    --cpu->ebp;
    lift_store32(cpu->esp + 0x38u, cpu->ebp);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AF5C5;
    cpu->edx = 0u;
    goto label_000AF5C7;
    label_000AF5C5:
    cpu->edx = lift_load32(cpu->eax);
    label_000AF5C7:
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->ebp;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->ebp)) goto label_000AF5D2;
    cpu->eax -= cpu->ecx;
    label_000AF5D2:
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000AF636;
    cpu->ebp = 0x10u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000AF5F1;
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF5EEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF5EEu));
    cpu->esp += 4u;
    label_000AF5F1:
    cpu->ebx = 0u;
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store8(cpu->edi, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) >= (uint32_t)(cpu->ebp)) goto label_000AF616;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4AF60Bu));
    cpu->esp += 0xCu;
    goto label_000AF61C;
    label_000AF616:
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->edi, cpu->edx);
    lift_store32(cpu->esi, cpu->ebx);
    label_000AF61C:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->edi + 0x14u, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    label_000AF636:
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) != (uint32_t)(cpu->ebx)) goto label_000AF590;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AF646:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ecx, 0u);
    lift_store32(cpu->ecx + 4u, 0u);
    lift_store32(cpu->ecx + 8u, cpu->ebp);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF668;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF668;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->edx);
    label_000AF668:
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF670(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_000AF748;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000AF686:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AF692;
    cpu->edi = 0u;
    goto label_000AF694;
    label_000AF692:
    cpu->edi = lift_load32(cpu->eax);
    label_000AF694:
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->edx = cpu->ebp;
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->ebp)) goto label_000AF69F;
    cpu->edx -= cpu->eax;
    label_000AF69F:
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000AF6AB;
    cpu->ecx = 0u;
    goto label_000AF6AD;
    label_000AF6AB:
    cpu->ecx = lift_load32(cpu->eax);
    label_000AF6AD:
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->eax)) goto label_000AF6BA;
    cpu->eax -= cpu->esi;
    label_000AF6BA:
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000AF72F;
    cpu->ebp = 0x10u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000AF6DF;
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF6DCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF6DCu));
    cpu->esp += 4u;
    label_000AF6DF:
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, 0u);
    lift_store8(cpu->edi, 0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) >= (uint32_t)(cpu->ebp)) goto label_000AF707;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4AF6FCu));
    cpu->esp += 0xCu;
    goto label_000AF711;
    label_000AF707:
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->edi, cpu->ecx);
    lift_store32(cpu->esi, 0u);
    label_000AF711:
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->edi + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->edi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_000AF72F:
    lift_store32(cpu->esp + 0x34u, (uint64_t)(lift_load32(cpu->esp + 0x34u)) + 1u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->esp + 0x28u))) goto label_000AF686;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000AF748:
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->ecx, 0u);
    lift_store32(cpu->ecx + 4u, 0u);
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF768;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF775;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->edx);
    label_000AF768:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
    label_000AF775:
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF790(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000AF7C7;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAF7C7u)); sfera_sub_0049FBD0(cpu, LIFT_CODE_TOKEN_RVA(0xAF7C7u));
    label_000AF7C7:
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000AF7D1;
    cpu->edi = lift_load32(cpu->esi + 8u);
    label_000AF7D1:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    --cpu->edi;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_000AF7EF;
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF7E2u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AF7E2u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF842;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    label_000AF7EF:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AF828;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAF828u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xAF828u));
    label_000AF828:
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AF842:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF870u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AF870u));
    lift_trap(cpu, 0x4AF870u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF8A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000AF8D7;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAF8D7u)); sfera_sub_0049FBD0(cpu, LIFT_CODE_TOKEN_RVA(0xAF8D7u));
    label_000AF8D7:
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    cpu->edi += lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edi)) goto label_000AF8E6;
    cpu->edi -= cpu->eax;
    label_000AF8E6:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_000AF903;
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF8F6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4AF8F6u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AF953;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    label_000AF903:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AF93C;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xAF93Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xAF93Cu));
    label_000AF93C:
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000AF953:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF981u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4AF981u));
    lift_trap(cpu, 0x4AF981u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AF990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AF9AF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AF9AF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000AF9B5;
    label_000AF9AF:
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000AF9BB;
    label_000AF9B5:
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000AF9BB:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AF9D3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AF9D3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000AF9D7;
    label_000AF9D3:
    cpu->edi = 0u;
    goto label_000AF9D9;
    label_000AF9D7:
    cpu->edi = lift_load32(cpu->eax);
    label_000AF9D9:
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AF9F3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AF9F3;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000AF9F3;
    cpu->ecx = lift_load32(cpu->eax);
    label_000AF9F3:
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFA0Fu)); sfera_sub_004AF3A0(cpu, LIFT_CODE_TOKEN_VA(0x4AFA0Fu));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AFA3B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AFA3B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->esi, cpu->ecx);
    label_000AFA3B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AFA50(LiftCpu* cpu, uint32_t stop_address) {
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
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFA7B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFA7B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFA7B:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFAA2;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFAA2;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFAA2:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFAC9;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFAC9;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_000AFAC9:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFAD7u)); sfera_sub_004AF570(cpu, LIFT_CODE_TOKEN_VA(0x4AFAD7u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AFAE0(LiftCpu* cpu, uint32_t stop_address) {
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
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFB0B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFB0B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFB0B:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFB32;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFB32;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFB32:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFB59;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000AFB59;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_000AFB59:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFB67u)); sfera_sub_004AF670(cpu, LIFT_CODE_TOKEN_VA(0x4AFB67u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AFB70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000AFBB4;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->eax;
    label_000AFBB4:
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000AFBC9;
    cpu->eax -= cpu->edx;
    cpu->ecx = cpu->eax;
    label_000AFBC9:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000AFC1D;
    cpu->ebp = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    cpu->ebx = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->ecx, cpu->ebp);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 4u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + 0xCu, cpu->ebp);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->esi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    lift_store32(cpu->eax + 0xCu, cpu->ebx);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->ecx + 0x10u, cpu->esi);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    cpu->esi = lift_load32(cpu->eax + 0x14u);
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_store32(cpu->ecx + 0x14u, cpu->esi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    label_000AFC1D:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AFC40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x3Cu;
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    cpu->eax -= cpu->edi;
    cpu->ebx = cpu->esi;
    cpu->ebx -= cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000AFC7A;
    label_000AFC69:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_000AFC69;
    label_000AFC7A:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000AFD43;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000AFD43;
    goto label_000AFC93;
    label_000AFC90:
    cpu->esi = lift_load32(cpu->ebp + 0x1Cu);
    label_000AFC93:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    cpu->ecx += cpu->edi;
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    cpu->edx = cpu->edi;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_000AFCB8;
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    cpu->ebx = lift_load32(cpu->ecx);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    goto label_000AFCD9;
    label_000AFCB8:
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->esi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    cpu->ebx = lift_load32(cpu->ecx);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    goto label_000AFCD9;
    label_000AFCD1:
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    label_000AFCD9:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFCE2u)); sfera_sub_004AFB70(cpu, LIFT_CODE_TOKEN_VA(0x4AFCE2u));
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx -= cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000AFD0E;
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    cpu->esi += cpu->edx;
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    goto label_000AFD27;
    label_000AFD0E:
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->eax = cpu->edi;
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    label_000AFD27:
    cpu->esi = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x3Cu))) goto label_000AFCD1;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    --cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000AFC90;
    label_000AFD43:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
