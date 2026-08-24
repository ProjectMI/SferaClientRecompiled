#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EB520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB520u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000EB884;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 1u);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->ebx);
    if ((uint8_t)(g_sfera_memory_runtime.lock_initialized) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000EB57A;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB56Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB573u);
    g_sfera_memory_runtime.lock_initialized = (uint8_t)(1u);
    label_000EB57A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB57Au);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB57Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB585u);
    g_sfera_memory_runtime.lock_held = (uint8_t)(1u);
    { uint64_t l=(uint64_t)(g_sfera_memory_runtime.tracking_initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EB5BE;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, (uintptr_t)"free2: test system not initialized"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0x1E4u);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB5BBu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000EB5BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB5BEu);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edx = 5u;
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB5D3u); lift_push32(cpu, r); sfera_sub_004EB1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB5E4u); lift_push32(cpu, r); sfera_sub_004EDDF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000EB61A;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, (uintptr_t)"Free of wrong pointer or double free. %s %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0xDBu);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB612u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    goto label_000EB868;
    label_000EB61A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB61Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = lift_load32(cpu->eax + cpu->edx + 8u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + cpu->eax + 4u)), r=(uint64_t)(0x61CCC864u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->ebp + 0xBu, (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0x61CCC864u)) goto label_000EB6DD;
    lift_store32(cpu->eax, 0x61CCC864u);
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = (uint8_t)(1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000EB657: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB657u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EB657;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EB66C;
    label_000EB663: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB663u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->edi)) == (uint8_t)(0x5Cu)) goto label_000EB66C;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EB663;
    label_000EB66C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB66Cu);
    cpu->edx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". ");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB68Eu); lift_push32(cpu, r); sfera_sub_004EA990(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"free: MEM CORRUPTED! ";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6A5u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6ACu); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6B3u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6BAu); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6C1u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6C8u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6CFu); lift_push32(cpu, r); sfera_sub_004ED390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB6D6u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEB6DDu); lift_push32(cpu, r); sfera_sub_004ED380(cpu,r); if (cpu->eip != r) return; }
    label_000EB6DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB6DDu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xBu)) == (uint8_t)(0u)) goto label_000EB789;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->edx + cpu->eax + 4u, 0x61CCC864u);
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = (uint8_t)(1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000EB700: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB700u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EB700;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EB719;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EB710: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB710u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->edi)) == (uint8_t)(0x5Cu)) goto label_000EB719;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EB710;
    label_000EB719: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB719u);
    cpu->ecx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". ");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB73Bu); lift_push32(cpu, r); sfera_sub_004EA990(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"free: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB751u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB758u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB75Fu); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB766u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB76Du); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB774u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB77Bu); lift_push32(cpu, r); sfera_sub_004ED390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB782u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEB789u); lift_push32(cpu, r); sfera_sub_004ED380(cpu,r); if (cpu->eip != r) return; }
    label_000EB789: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB789u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB797u); lift_push32(cpu, r); sfera_sub_004EDE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EB7C1;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, (uintptr_t)"validate_and_remove_pointer: pointer not in hash"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0xE9u);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB7BEu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000EB7C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB7C1u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_memory_runtime.tracker_floor)) goto label_000EB7D5;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_floor = (uint32_t)(cpu->ecx);
    label_000EB7D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB7D5u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_memory_runtime.tracker_ceiling)) goto label_000EB7E6;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_ceiling = (uint32_t)(cpu->edx);
    label_000EB7E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB7E6u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EB802;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0x10u, cpu->ecx);
    goto label_000EB80A;
    label_000EB802: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB802u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->eax);
    label_000EB80A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB80Au);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EB826;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0xCu, cpu->ecx);
    goto label_000EB82E;
    label_000EB826: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB826u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->eax);
    label_000EB82E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB82Eu);
    cpu->eax = lift_load16(cpu->esi + 0x14u);
    cpu->eax &= 0x3FFu;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations), (uint64_t)(lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations))) - 1u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations));
    cpu->eax = lift_load16(cpu->esi + 0x14u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax &= 0x3FFu;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes), (uint64_t)(lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes))) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    lift_store32((uint32_t)(uintptr_t)&g_sfera_memory_runtime.live_allocation_count, (uint64_t)(g_sfera_memory_runtime.live_allocation_count) - 1u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes));
    label_000EB868: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB868u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x4EB869u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB86Fu);
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEB87Eu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEB884u);
    label_000EB884: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB884u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EB8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB8A0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->edx;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000EB8FB;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB8E7u); lift_push32(cpu, r); sfera_sub_004EB300(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000EB8FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB8FBu);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 1u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    if ((uint8_t)(g_sfera_memory_runtime.lock_initialized) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000EB91F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB912u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB918u);
    g_sfera_memory_runtime.lock_initialized = (uint8_t)(1u);
    label_000EB91F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB91Fu);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB924u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB92Au);
    g_sfera_memory_runtime.lock_held = (uint8_t)(1u);
    { uint64_t l=(uint64_t)(g_sfera_memory_runtime.tracking_initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EB95F;
    lift_push32(cpu, 0x1388u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB94Cu); lift_push32(cpu, r); sfera_sub_004EDD40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_memory_source_hash_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB958u); lift_push32(cpu, r); sfera_sub_004EDA60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_memory_runtime.tracking_initialized = (uint8_t)(1u);
    label_000EB95F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB95Fu);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->edx = 5u;
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB977u); lift_push32(cpu, r); sfera_sub_004EB1D0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->edi) > 0) goto label_000EB9A2;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"realloc2: Wrong size value. Size = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0x1FBu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB99Fu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EB9A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB9A2u);
    cpu->esi += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_store32(cpu->ebp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB9B3u); lift_push32(cpu, r); sfera_sub_004EDDF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000EB9E5;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"realloc2 with wrong pointer"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0xDEu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EB9DDu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    goto label_000EBC39;
    label_000EB9E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EB9E5u);
    cpu->eax = g_sfera_allocation_hash_runtime.records;
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = lift_load32(cpu->edx + cpu->eax + 8u);
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + cpu->ecx + 4u)), r=(uint64_t)(0x61CCC864u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->ebp + 0xFu, (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0x61CCC864u)) goto label_000EBAAC;
    lift_store32(cpu->eax, 0x61CCC864u);
    cpu->eax = cpu->ebx;
    g_sfera_memory_runtime.diagnostics_dirty = (uint8_t)(1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000EBA23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBA23u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EBA23;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EBA39;
    (void)cpu;
    label_000EBA30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBA30u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) == (uint8_t)(0x5Cu)) goto label_000EBA39;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EBA30;
    label_000EBA39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBA39u);
    cpu->edx = g_sfera_diagnostic_log_byte;
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". ");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA5Eu); lift_push32(cpu, r); sfera_sub_004EA990(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"realloc: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA74u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA7Bu); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA82u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA89u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA90u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA97u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBA9Eu); lift_push32(cpu, r); sfera_sub_004ED390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBAA5u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEBAACu); lift_push32(cpu, r); sfera_sub_004ED380(cpu,r); if (cpu->eip != r) return; }
    label_000EBAAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBAACu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xFu)) == (uint8_t)(0u)) goto label_000EBB5D;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = cpu->ebx;
    lift_store32(cpu->ecx + cpu->edx + 4u, 0x61CCC864u);
    g_sfera_memory_runtime.diagnostics_dirty = (uint8_t)(1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000EBAD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBAD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EBAD0;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EBAE9;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EBAE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBAE0u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) == (uint8_t)(0x5Cu)) goto label_000EBAE9;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EBAE0;
    label_000EBAE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBAE9u);
    cpu->ecx = g_sfera_diagnostic_log_byte;
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebx + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". ");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB0Eu); lift_push32(cpu, r); sfera_sub_004EA990(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"realloc: MEM CORRUPTED! ";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB25u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB2Cu); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB33u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB3Au); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB41u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB48u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB4Fu); lift_push32(cpu, r); sfera_sub_004ED390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB56u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEBB5Du); lift_push32(cpu, r); sfera_sub_004ED380(cpu,r); if (cpu->eip != r) return; }
    label_000EBB5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBB5Du);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB6Bu); lift_push32(cpu, r); sfera_sub_004EDE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EBB95;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"validate_and_remove_pointer: pointer not in hash"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0xE9u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBB92u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000EBB95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBB95u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_memory_runtime.tracker_floor)) goto label_000EBBA6;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_floor = (uint32_t)(cpu->ecx);
    label_000EBBA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBBA6u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_memory_runtime.tracker_ceiling)) goto label_000EBBB7;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_ceiling = (uint32_t)(cpu->edx);
    label_000EBBB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBBB7u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EBBD3;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0x10u, cpu->ecx);
    goto label_000EBBDB;
    label_000EBBD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBBD3u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->eax);
    label_000EBBDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBBDBu);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EBBF7;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0xCu, cpu->ecx);
    goto label_000EBBFF;
    label_000EBBF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBBF7u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->eax);
    label_000EBBFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBBFFu);
    cpu->eax = lift_load16(cpu->esi + 0x14u);
    cpu->eax &= 0x3FFu;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations), (uint64_t)(lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations))) - 1u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations));
    cpu->eax = lift_load16(cpu->esi + 0x14u);
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->eax &= 0x3FFu;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes), (uint64_t)(lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes))) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    lift_store32((uint32_t)(uintptr_t)&g_sfera_memory_runtime.live_allocation_count, (uint64_t)(g_sfera_memory_runtime.live_allocation_count) - 1u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes));
    label_000EBC39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBC39u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = (uint32_t)(cpu->edi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EBC41u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBC47u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000EBC77;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"realloc2: Not enough memory. Request size = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0x203u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBC74u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EBC77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBC77u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi, 0x61CCC864u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_store32(cpu->esi + cpu->edi + 4u, 0x61CCC864u);
    lift_store32(cpu->ebp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBC9Bu); lift_push32(cpu, r); sfera_sub_004EDEF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000EBCC7;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"store_pointer: pointer already in hash"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0xFEu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBCC4u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000EBCC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBCC7u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_memory_source_hash_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBCD2u); lift_push32(cpu, r); sfera_sub_004EDC70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = cpu->eax & 0xFFFFu;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0x3B9ACA00u)) goto label_000EBCFB;
    cpu->ebx = g_sfera_allocation_hash_runtime.records;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1Au);
    lift_store32(cpu->edx + cpu->ebx + 0xCu, cpu->edi);
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    goto label_000EBD01;
    label_000EBCFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBCFBu);
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->edi);
    label_000EBD01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBD01u);
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    lift_store32(cpu->ecx + 8u, 0x3B9ACA00u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_store16(cpu->edx + 0x14u, cpu->eax & 0xFFFFu);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax &= 0x3FFu;
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->edx + 0x10u, cpu->edi);
    cpu->eax += cpu->eax;
    lift_store32(cpu->eax + cpu->eax + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes), (uint64_t)(lift_load32(cpu->eax + cpu->eax + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_bytes))) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->eax += cpu->eax;
    cpu->edx = 1u;
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations), (uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)g_sfera_memory_runtime.bucket_allocations))) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    lift_store32((uint32_t)(uintptr_t)&g_sfera_memory_runtime.live_allocation_count, (uint64_t)(g_sfera_memory_runtime.live_allocation_count) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBD5Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBD62u);
    cpu->eax = (uint32_t)(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBD80u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    { uint64_t l=(uint64_t)(g_sfera_memory_runtime.lock_initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EBDC7;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBDBAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBDC0u);
    g_sfera_memory_runtime.lock_initialized = (uint8_t)(1u);
    label_000EBDC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBDC7u);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::TryEnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBDCCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBDD2u);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EBE07;
    if ((uint8_t)(g_sfera_memory_runtime.lock_held) != (uint8_t)(0u)) goto label_000EBDFC;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"verify before terminate"); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEBDFCu); lift_push32(cpu, r); sfera_sub_004EAA20(cpu,r); if (cpu->eip != r) return; }
    label_000EBDFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBDFCu);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEBE01u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEBE07u);
    label_000EBE07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBE07u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBE20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000EBE4F;
    cpu->eax = g_sfera_memory_runtime.allocation_source_line;
    cpu->edx = g_sfera_memory_runtime.allocation_source_file;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBE3Bu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    g_sfera_memory_runtime.allocation_source_file = (uint32_t)(((uint32_t)(uintptr_t)"Unknown"));
    g_sfera_memory_runtime.allocation_source_line = (uint32_t)(0u);
    label_000EBE4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBE4Fu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBE60u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBE6Fu); lift_push32(cpu, r); sfera_sub_004EB300(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBE80u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBE92u); lift_push32(cpu, r); sfera_sub_004EB8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBEA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBEA0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = g_sfera_memory_runtime.allocation_source_line;
    cpu->ecx = g_sfera_memory_runtime.allocation_source_file;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBEBEu); lift_push32(cpu, r); sfera_sub_004EB300(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EBEC4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBEC9u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    g_sfera_memory_runtime.allocation_source_file = (uint32_t)(((uint32_t)(uintptr_t)"Unknown"));
    g_sfera_memory_runtime.allocation_source_line = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBEF0u);
    cpu->eax = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->edx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"%d ");
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EBF03u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBF09u);
    cpu->esp += 0x10u;
    lift_store8(cpu->edi + cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBF20u);
    g_sfera_critical_diagnostics_runtime.stack_dump_callback = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBF30u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::printf), LIFT_CODE_TOKEN_VA(0x4EBF31u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBF37u);
    cpu->esp += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBF40u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = 0x1204u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBF4Du); lift_push32(cpu, r); sfera_sub_004EEAF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x14u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFEE0Cu);
    lift_store32(cpu->ebp + 0xFFFFEDFCu, (uintptr_t)"stackdump.cpp");
    lift_store32(cpu->ebp + 0xFFFFEE00u, (uintptr_t)"errorsmgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFEE04u, (uintptr_t)"crt0.c");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EBF86u); lift_push32(cpu, r); sfera_sub_004EE2C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->ebp + 0xFFFFF6CCu, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000EC06D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->ebp + 0xFFFFEE30u);
    lift_store32(cpu->ebp + 0xFFFFEE08u, cpu->eax);
    label_000EBFA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBFA4u);
    cpu->esi = 0u;
    cpu->edi = (uint32_t)(cpu->ebx + 0xFFFFFFDCu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EBFB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBFB0u);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(cpu->esi) * 4u) + 0xFFFFEDFCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4EBFB9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBFBFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EBFCE;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(3u)) goto label_000EBFB0;
    goto label_000EBFD3;
    label_000EBFCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBFCEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(3u)) goto label_000EC026;
    label_000EBFD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBFD3u);
    cpu->ecx = lift_load32(cpu->ebx + 0x48u);
    cpu->edx = lift_load32(cpu->ebx + 0x44u);
    cpu->eax = lift_load32(cpu->ebx + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"(%s:%u)\t(%hs+%I64X)\n");
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, 0x6Fu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EBFECu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EBFF2u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF8Cu);
    cpu->esp += 0x20u;
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    cpu->esi = cpu->eax;
    cpu->edi = cpu->edi;
    label_000EC000: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC000u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC000;
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFF6CCu);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000EC010: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC010u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EC010;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    label_000EC026: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC026u);
    cpu->ebx += 0x70u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFEE08u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xFFFFEE08u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EBFA4;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xFFFFF6CCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000EC06D;
    cpu->edx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFF6CCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Stack:\n");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC05Fu); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC066u); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEC06Du); lift_push32(cpu, r); sfera_sub_004ED380(cpu,r); if (cpu->eip != r) return; }
    label_000EC06D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC06Du);
    cpu->eax = g_sfera_critical_diagnostics_runtime.stack_dump_callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EC07D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xEC07Du), LIFT_CODE_TOKEN_RVA(0xEC07Bu))) { return; }
    label_000EC07D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC07Du);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC090u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"critLogTmp.$$$"); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0ADu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC0B3u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC1A6;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x8000u); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0C9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC0CFu);
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFFu)) goto label_000EC0ED;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0DFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC0E5u);
    cpu->esp += 8u;
    goto label_000EC1A6;
    label_000EC0ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC0EDu);
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0F8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC0FEu);
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000EC11F;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4EC10Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC110u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC116u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC11Cu);
    cpu->esp += 0xCu;
    label_000EC11F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC11Fu);
    cpu->eax = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC126u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000EC189;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = 0u - (uint64_t)(cpu->edi);
    cpu->edi = cpu->edi;
    label_000EC140: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC140u);
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4EC144u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC14Au);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000EC189;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4EC158u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC15Eu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EC189;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4EC16Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC174u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EC189;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    ++cpu->eax;
    cpu->edi += cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_000EC140;
    label_000EC189: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC189u);
    cpu->esi = native_function_address32(&::_close);
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xEC192u), LIFT_CODE_TOKEN_RVA(0xEC190u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC192u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xEC198u), LIFT_CODE_TOKEN_RVA(0xEC196u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC198u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4EC19Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC1A3u);
    cpu->esp += 0xCu;
    label_000EC1A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC1A6u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC1C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC1C0u);
    g_sfera_memory_runtime.critical_error_callback = (uint32_t)(cpu->ecx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000EC1D4;
    g_sfera_memory_runtime.critical_error_callback = LIFT_FUNCTION(sfera_sub_004EBF30);
    label_000EC1D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC1D4u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC1E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC1E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = (uint32_t)(uintptr_t)"Criticals.log";
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    lift_store32(cpu->ebp + 0xFFFFFFC8u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC202u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC208u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000EC2CC;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::fputs);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000EC273;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC224u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC22Au);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC22Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC234u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC240u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC246u);
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC258u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC25Eu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC269u), LIFT_CODE_TOKEN_RVA(0xEC267u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC269u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC270u), LIFT_CODE_TOKEN_RVA(0xEC26Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC270u);
    cpu->esp += 0x38u;
    label_000EC273: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC273u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC27Au), LIFT_CODE_TOKEN_RVA(0xEC278u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC27Au);
    cpu->esp += 8u;
    if ((uint8_t)(lift_load8(cpu->ebp + 8u)) == (uint8_t)(0u)) goto label_000EC28E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC28Bu), LIFT_CODE_TOKEN_RVA(0xEC289u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC28Bu);
    cpu->esp += 8u;
    label_000EC28E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC28Eu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4EC28Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC295u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4EC296u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC29Cu);
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4EC29Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC2A5u);
    cpu->esp += 0xCu;
    if ((uint8_t)(lift_load8(cpu->ebp + 0xCu)) == (uint8_t)(0u)) goto label_000EC2CB;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(0x108000u)) goto label_000EC2CB;
    cpu->ecx = (uint32_t)(uintptr_t)"Criticals.log";
    lift_push32(cpu, 0x200u);
    cpu->edx = 0x800u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEC2CBu); lift_push32(cpu, r); sfera_sub_004EC090(cpu,r); if (cpu->eip != r) return; }
    label_000EC2CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC2CBu);
    cpu->edi = lift_pop32(cpu);
    label_000EC2CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC2CCu);
    cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC2E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC2E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x83Cu;
    cpu->eax = g_sfera_critical_diagnostics_runtime.processing_depth;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->edi);
    g_sfera_critical_diagnostics_runtime.processing_depth = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000EC3D0;
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_000EC3C1;
    cpu->eax = (uint32_t)(uintptr_t)"Criticals.log";
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC322u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC328u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000EC3BC;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7C4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC33Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC342u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFF7C4u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC349u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC34Fu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC35Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC361u);
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC373u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC379u);
    cpu->edi = native_function_address32(&::fputs);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC38Au), LIFT_CODE_TOKEN_RVA(0xEC388u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC38Au);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC391u), LIFT_CODE_TOKEN_RVA(0xEC38Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC391u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Error processing reenter. Terminating");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC399u), LIFT_CODE_TOKEN_RVA(0xEC397u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC399u);
    cpu->esp += 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC3A4u), LIFT_CODE_TOKEN_RVA(0xEC3A2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3A4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4EC3A5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3ABu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4EC3ACu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3B2u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4EC3B3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3B9u);
    cpu->esp += 0x14u;
    label_000EC3BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3BCu);
    cpu->esi = 1u;
    label_000EC3C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3C1u);
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EC3C3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3C9u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_RVA(0xEC3CAu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEC3D0u);
    label_000EC3D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3D0u);
    cpu->eax = g_sfera_critical_diagnostics_runtime.serial_number;
    cpu->eax += cpu->esi;
    g_sfera_critical_diagnostics_runtime.serial_number = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3E8u)) goto label_000EC3ED;
    g_sfera_critical_diagnostics_runtime.serial_number = (uint32_t)(0u);
    label_000EC3ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC3EDu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x4EC401u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC407u);
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    cpu->esp += 0x10u;
    lift_store8(cpu->ebp + 0xFFFFFFCBu, 0u);
    --cpu->edi;
    label_000EC415: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC415u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC415;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    lift_store16(cpu->edi, cpu->edx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000EC4D4;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000EC47D;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EC4E9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC451u); lift_push32(cpu, r); sfera_sub_004EC1E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC466u); lift_push32(cpu, r); sfera_sub_004ED100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC46Du); lift_push32(cpu, r); sfera_sub_004EBF40(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_memory_runtime.critical_error_callback), LIFT_CODE_TOKEN_RVA(0xEC47Bu), LIFT_CODE_TOKEN_RVA(0xEC475u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC47Bu);
    goto label_000EC4B9;
    label_000EC47D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC47Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC492u); lift_push32(cpu, r); sfera_sub_004ED100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC499u); lift_push32(cpu, r); sfera_sub_004EBF40(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_memory_runtime.critical_error_callback), LIFT_CODE_TOKEN_RVA(0xEC4A7u), LIFT_CODE_TOKEN_RVA(0xEC4A1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC4A7u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC4E9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"terminating cause of LERROR";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEC4B9u); lift_push32(cpu, r); sfera_sub_004EC1E0(cpu,r); if (cpu->eip != r) return; }
    label_000EC4B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC4B9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC4BEu); lift_push32(cpu, r); sfera_sub_004EBD80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC4C3u); lift_push32(cpu, r); sfera_sub_004ED150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EC4C5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC4CBu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_VA(0x4EC4CCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC4D2u);
    goto label_000EC4E9;
    label_000EC4D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC4D4u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_warnings_object;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEC4E9u); lift_push32(cpu, r); sfera_sub_004ED100(cpu,r); if (cpu->eip != r) return; }
    label_000EC4E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC4E9u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_critical_diagnostics_runtime.processing_depth, (uint64_t)(g_sfera_critical_diagnostics_runtime.processing_depth) - (uint64_t)(cpu->esi) - (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC500u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint64_t l=cpu->esp, r=(uint64_t)(4u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esi);
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC547u); lift_push32(cpu, r); sfera_sub_004EE390(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000EC583;
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_000EC583;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: trunc log %s and dayly files are mutualy exclusive capabilities."); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x1Fu);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC580u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EC583: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC583u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC590: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC590u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC590;
    cpu->ebx = native_function_address32(&::malloc);
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC5A5u), LIFT_CODE_TOKEN_RVA(0xEC5A3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC5A5u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC5D6;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x23u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC5D3u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EC5D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC5D6u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC5E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC5E0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC5E0;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC5F6;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    goto label_000EC650;
    label_000EC5F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC5F6u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC600: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC600u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC600;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC60Fu), LIFT_CODE_TOKEN_RVA(0xEC60Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC60Fu);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC640;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x2Du);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC63Du); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EC640: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC640u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    label_000EC646: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC646u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC646;
    label_000EC650: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC650u);
    cpu->edi = lift_load32(cpu->ebp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->ebp + 0x14u);
    cpu->eax = lift_load32(cpu->ebp + 0x18u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, 0x1F4u);
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC672u), LIFT_CODE_TOKEN_RVA(0xEC670u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC672u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC6A3;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x38u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC6A0u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EC6A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC6A3u);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->eax = 0u;
    lift_store8(cpu->edx, 0u);
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) > (int32_t)(uint32_t)(cpu->eax)) goto label_000EC6BB;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    goto label_000EC6F7;
    label_000EC6BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC6BBu);
    lift_push32(cpu, 0x2000u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC6C2u), LIFT_CODE_TOKEN_RVA(0xEC6C0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC6C2u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC6F7;
    lift_push32(cpu, 0x2000u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x43u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC6F4u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EC6F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC6F7u);
    if ((uint8_t)((lift_load8(cpu->ebp + 0x10u)) & (8u)) == 0u) goto label_000EC73A;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC703u), LIFT_CODE_TOKEN_RVA(0xEC701u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC703u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC734;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x4Bu);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC731u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EC734: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC734u);
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    lift_store8(cpu->edx, 0u);
    label_000EC73A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC73Au);
    lift_store32(cpu->esi, 0u);
    cpu->eax = g_sfera_critical_diagnostics_runtime.log_chain_head;
    lift_store32(cpu->esi + 4u, cpu->eax);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EC757;
    lift_store32(cpu->eax, cpu->esi);
    label_000EC757: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC757u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC770u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->esp -= 0x10u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC780: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC780u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC780;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC7A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC7A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC7A0;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->esi = (uint32_t)(cpu->ebx + cpu->esi + 1u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(lift_load32(cpu->ecx))) goto label_000EC7FA;
    cpu->eax = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EC7BFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC7C5u);
    cpu->esp += 8u;
    lift_store32(cpu->edi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC7FA;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, (uintptr_t)"Log::append_realloc(): Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF4u, 0x127u);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC7F7u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EC7FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC7FAu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4EC807u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC80Cu);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->ecx + cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC830u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000EC850: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC850u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC850;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->eax = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC863u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->esp;
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->esi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC870: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC870u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC870;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + cpu->edi + 0xFFFFFFFEu, 0x24u);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x4EC885u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC88Bu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4EC88Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC892u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC89Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC8A0u);
    cpu->esp += 0x14u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC8C0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC8DBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC8E1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC8E5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC8EBu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"_%y%m%d");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC8F7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC8FDu);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->esp += 0x18u;
    cpu->edx = 0u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_000EC923;
    label_000EC910: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC910u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000EC923;
    lift_store8(cpu->edi, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + cpu->ecx + 1u)) & 0xFFu);
    ++cpu->edx;
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Eu)) goto label_000EC910;
    label_000EC923: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC923u);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->ebx = cpu->edi;
    cpu->ecx = cpu->eax;
    cpu->ebx -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000EC930: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC930u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->ebx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC930;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_000EC942: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC942u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000EC942;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_000EC950: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC950u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EC950;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC980u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x84u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC9BC;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000EC9A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC9A3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC9A3;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000EC9BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC9BCu);
    cpu->edx = 0x80u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_store8(cpu->ebp + 0xFFFFFF7Cu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xEC9D0u), LIFT_CODE_TOKEN_RVA(0xEC9CEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EC9D0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EC9E6u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA00u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x1FFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(0xDu), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000ECA7F;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000ECA30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA30u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4ECA37u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA3Du);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECA73;
    cpu->edx = lift_load32(cpu->edi + 0x18u);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4ECA4Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA55u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECA73;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4ECA6Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA70u);
    cpu->esp += 0xCu;
    label_000ECA73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA73u);
    lift_store32(cpu->ebp + 0xCu, (uint64_t)(lift_load32(cpu->ebp + 0xCu)) + (uint64_t)(0x2000u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xFFFFFFFCu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ECA30;
    label_000ECA7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA7Fu);
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80001FFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000ECA90;
    --cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFE000u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    label_000ECA90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECA90u);
    lift_store32(cpu->ebp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ECAD6;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(0xDu), 32u);
    cpu->esi += lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4ECA9Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECAA5u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECAD6;
    cpu->esi = lift_load32(cpu->ebp + 0x14u);
    cpu->edx = lift_load32(cpu->edi + 0x18u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4ECAB6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECABCu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECAD6;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4ECACDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECAD3u);
    cpu->esp += 0xCu;
    label_000ECAD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECAD6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECAE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x10u)), r=(uint64_t)(2u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ECB1C;
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000ECB01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB01u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECB01;
    cpu->eax -= cpu->edx;
    cpu->eax += 0x20u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECB12u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->esp;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xECB1Cu); lift_push32(cpu, r); sfera_sub_004EC8C0(cpu,r); if (cpu->eip != r) return; }
    label_000ECB1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB1Cu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4ECB22u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB28u);
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000ECB93;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4ECB36u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB3Cu);
    cpu->esp += 8u;
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (4u)) == 0u) goto label_000ECB4F;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4ECB46u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB4Cu);
    cpu->esp += 4u;
    label_000ECB4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB4Fu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u)) <= (int32_t)(uint32_t)(0u)) goto label_000ECB89;
    lift_store32(cpu->esi + 0x1Cu, (uint64_t)(lift_load32(cpu->esi + 0x1Cu)) + 1u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (int32_t)(uint32_t)(0x1F4u)) goto label_000ECB89;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, 0u);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4ECB69u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB6Fu);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4ECB72u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB78u);
    cpu->esp += 8u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_000ECB93;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECB87u); lift_push32(cpu, r); sfera_sub_004EC830(cpu,r); if (cpu->eip != r) return; }
    goto label_000ECB93;
    label_000ECB89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB89u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4ECB8Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB90u);
    cpu->esp += 4u;
    label_000ECB93: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECB93u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECBB0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ECE61;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000ECBD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECBD5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECBD5;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->eax = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECBEBu); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ebx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->ebx);
    cpu->edx = cpu->ebx;
    label_000ECBF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECBF5u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000ECBF5;
    lift_push32(cpu, 0u);
    lift_store8(cpu->ebx + cpu->edi + 0xFFFFFFFEu, 0x24u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECC0Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC15u);
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECC24;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    goto label_000ECC3E;
    label_000ECC24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC24u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x4ECC25u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC2Bu);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECC2Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC35u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    label_000ECC3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC3Eu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECC46u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC4Cu);
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECC5B;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    goto label_000ECC7A;
    label_000ECC5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC5Bu);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x4ECC5Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC62u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECC66u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC6Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECC91;
    label_000ECC7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC7Au);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECE61;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_000ECE61;
    goto label_000ECC94;
    label_000ECC91: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC91u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    label_000ECC94: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECC94u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECCA9;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECC9Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECCA4u);
    goto label_000ECE5E;
    label_000ECCA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECCA9u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECCB1u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ebx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    cpu->edx = cpu->ebx;
    label_000ECCC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECCC0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000ECCC0;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_store16(cpu->ebx + cpu->eax + 0xFFFFFFFDu, 0x2424u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECCD9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECCDFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ECE61;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECCF8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECCFEu);
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECD34;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECD0Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD12u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECD17u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD1Du);
    cpu->esp += 0xCu;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ECD34: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD34u);
    cpu->ebx |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)) == (uint32_t)(cpu->ebx)) goto label_000ECD8D;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECD47u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD4Du);
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECD8D;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECD58u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD5Eu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECD62u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD68u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECD70u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD76u);
    cpu->esp += 0x10u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ECD8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD8Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECD98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECD9Eu);
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECDE4;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_close);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xECDB2u), LIFT_CODE_TOKEN_RVA(0xECDB0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECDB2u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xECDB5u), LIFT_CODE_TOKEN_RVA(0xECDB3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECDB5u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECDB9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECDBFu);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECDC7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECDCDu);
    cpu->esp += 0x14u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ECDE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECDE4u);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000ECDF4;
    lift_push32(cpu, cpu->ecx);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    goto label_000ECE29;
    label_000ECDF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECDF4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECE26;
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_000ECE14;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx -= lift_load32(cpu->esi + 0x14u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    goto label_000ECE17;
    label_000ECE14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    label_000ECE17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE17u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECE20u); lift_push32(cpu, r); sfera_sub_004ECA00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    label_000ECE26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE26u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    label_000ECE29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE29u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECE32u); lift_push32(cpu, r); sfera_sub_004ECA00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_close);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xECE3Bu), LIFT_CODE_TOKEN_RVA(0xECE39u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE3Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xECE41u), LIFT_CODE_TOKEN_RVA(0xECE3Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE41u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = native_function_address32(&::remove);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xECE4Du), LIFT_CODE_TOKEN_RVA(0xECE4Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE4Du);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECE61;
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xECE58u), LIFT_CODE_TOKEN_RVA(0xECE56u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE58u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xECE5Eu), LIFT_CODE_TOKEN_RVA(0xECE5Cu))) { return; }
    label_000ECE5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE5Eu);
    cpu->esp += 8u;
    label_000ECE61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE61u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECE80u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->ebp + 0xFFFFFFD8u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ECF41;
    cpu->eax = lift_load32(cpu->edi + 0x14u);
    lift_store8(cpu->edi, 1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000ECEB6;
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    goto label_000ECF3C;
    label_000ECEB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECEB6u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"[%d] ");
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4ECEC2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECEC8u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->esp += 0x10u;
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000ECED5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECED5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECED5;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000ECEE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECEE6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECEE6;
    cpu->eax -= cpu->esi;
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECEF8u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->esp;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    cpu->edx -= cpu->ecx;
    label_000ECF03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECF03u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECF03;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->edx = cpu->eax;
    label_000ECF12: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECF12u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECF12;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    cpu->edi = cpu->edi;
    label_000ECF20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECF20u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ECF20;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ebx);
    label_000ECF3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECF3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xECF41u); lift_push32(cpu, r); sfera_sub_004ECAE0(cpu,r); if (cpu->eip != r) return; }
    label_000ECF41: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECF41u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECF60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_000ECFD5;
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) != 0u) goto label_000ECF79;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECF77u); lift_push32(cpu, r); sfera_sub_004ECAE0(cpu,r); if (cpu->eip != r) return; }
    goto label_000ECFC3;
    label_000ECF79: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECF79u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECF86u); lift_push32(cpu, r); sfera_sub_004EE5D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000ECFC2;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECF92u); lift_push32(cpu, r); sfera_sub_004EE4C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000ECFA6;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECF9Eu); lift_push32(cpu, r); sfera_sub_004EE4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xECFA6u); lift_push32(cpu, r); sfera_sub_004ECE80(cpu,r); if (cpu->eip != r) return; }
    label_000ECFA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECFA6u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ECFB6u); lift_push32(cpu, r); sfera_sub_004EE690(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ECFC2;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xECFC2u); lift_push32(cpu, r); sfera_sub_004ECE80(cpu,r); if (cpu->eip != r) return; }
    label_000ECFC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECFC2u);
    cpu->edi = lift_pop32(cpu);
    label_000ECFC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECFC3u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_store8(cpu->eax, 0u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ECFD5;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_store8(cpu->ecx, 0u);
    label_000ECFD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECFD5u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECFE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ECFE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) != (uint32_t)(0u)) goto label_000ED00D;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ED00D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED00Du);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = cpu->edi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED0DB;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000ED020: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED020u);
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0x24u)) goto label_000ED0D1;
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = (uint32_t)(cpu->esi + 0x28u);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->edi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED03Cu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->edi, 0x24u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000ED0EB;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x64u)) goto label_000ED08F;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED053u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED059u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED05Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED063u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED06Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED075u);
    cpu->esp += 0x18u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED088u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED08F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED08Fu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x74u)) goto label_000ED0B8;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED098u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED09Eu);
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED0B1u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED0B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED0B8u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x75u)) goto label_000ED0CA;
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) == (uint32_t)(0u)) goto label_000ED0CA;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED0CAu); lift_push32(cpu, r); sfera_sub_004EC980(cpu,r); if (cpu->eip != r) return; }
    label_000ED0CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED0CAu);
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED0D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED0D1u);
    ++cpu->edi;
    label_000ED0D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED0D2u);
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0u)) goto label_000ED020;
    label_000ED0DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED0DBu);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED0EBu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED0EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED0EBu);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED100u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED10Bu); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED112u); lift_push32(cpu, r); sfera_sub_004ECFE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED125u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED13E;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED13Eu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED13E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED13Eu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED145u); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED150u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_critical_diagnostics_runtime.log_chain_head;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000ED196;
    lift_push32(cpu, cpu->edi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000ED160: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED160u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED18E;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED16Eu); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED18E;
    label_000ED172: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED172u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED17Au); lift_push32(cpu, r); sfera_sub_004EE4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED182u); lift_push32(cpu, r); sfera_sub_004ECE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED18Au); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED172;
    label_000ED18E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED18Eu);
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000ED160;
    cpu->edi = lift_pop32(cpu);
    label_000ED196: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED196u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED380u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED385u); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED390u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ED3B4;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED3B4u); lift_push32(cpu, r); sfera_sub_004ECFE0(cpu,r); if (cpu->eip != r) return; }
    label_000ED3B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED3B4u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4ED3C3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED3C9u);
    cpu->esp += 0x10u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED3E0u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x800u)) goto label_000ED3EE;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED3EEu); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    label_000ED3EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED3EEu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED410u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ED427;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED427u); lift_push32(cpu, r); sfera_sub_004ECFE0(cpu,r); if (cpu->eip != r) return; }
    label_000ED427: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED427u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED438u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x10u)), r=(uint64_t)(8u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED450;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED450u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED450: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED450u);
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(0x800u)) goto label_000ED460;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED460u); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    label_000ED460: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED460u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED470u);
    cpu->ecx = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    label_000ED474: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED474u);
    cpu->eax = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED48A;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    label_000ED48A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED48Au);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED49F;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4A1;
    label_000ED49F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED49Fu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4A1u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4B6;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4B8;
    label_000ED4B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4B6u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4B8u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4CD;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4CF;
    label_000ED4CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4CDu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4CFu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4E4;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4E6;
    label_000ED4E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4E4u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4E6u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4FB;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4FD;
    label_000ED4FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4FBu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED4FDu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED512;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED514;
    label_000ED512: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED512u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED514: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED514u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000ED520;
    cpu->ecx ^= 0xEDB88320u;
    label_000ED520: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED520u);
    g_sfera_string_lookup_runtime.hash_mix[(uint8_t)cpu->edx] = (uint16_t)(cpu->ecx & 0xFFFFu);
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000ED474;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED5C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000ED5C0;
    label_000ED540: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED540u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"QWERTYUIOPASDFGHJKLZXCVBNM";
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"qwertyuiopasdfghjklzxcvbnm";
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000ED580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED580u);
    g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax] = (uint8_t)(cpu->eax & 0xFFu);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_000ED580;
    cpu->eax = 0u;
    label_000ED590: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED590u);
    cpu->ecx = lift_load8(cpu->ebp + cpu->eax + 0xFFFFFFE0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + cpu->eax + 0xFFFFFFC4u)) & 0xFFu);
    ++cpu->eax;
    g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx] = (uint8_t)(cpu->edx & 0xFFu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x1Bu)) goto label_000ED590;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ED5C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED5C0u);
    if ((uint32_t)(g_sfera_string_lookup_runtime.initialized) != (uint32_t)(0u)) goto label_000ED5DD;
    g_sfera_string_lookup_runtime.initialized = (uint32_t)(1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED5D8u); lift_push32(cpu, r); sfera_sub_004ED470(cpu,r); if (cpu->eip != r) return; }
    goto label_000ED540;
    label_000ED5DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED5DDu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED5E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x14u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"operator[]: out of range. Size=%d, Index=%d"); lift_push32(cpu, 1u); lift_push32(cpu, 0x13u); lift_push32(cpu, (uintptr_t)"Containers\\Containers.cpp");
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED60Au); lift_push32(cpu, r); sfera_sub_004013B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED610u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED620u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED631u); lift_push32(cpu, r); sfera_sub_004ED5C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFFFFu, cpu->edx & 0xFFu);
    cpu->eax = (int8_t)(lift_load8(cpu->ebp + 0xFFFFFFFFu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x4ED644u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED64Au);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED6ED;
    cpu->ecx = (int8_t)(lift_load8(cpu->ebp + 0xFFFFFFFFu));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx]) & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFFFFu, cpu->edx & 0xFFu);
    goto label_000ED66D;
    label_000ED664: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED664u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    label_000ED66D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED66Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = (int8_t)(lift_load8(cpu->ecx));
    if ((uint32_t)(cpu->edx) == 0u) goto label_000ED6EB;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx]);
    cpu->eax = (int8_t)(lift_load8(cpu->ebp + 0xFFFFFFFFu));
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_000ED6E6;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edx);
    goto label_000ED6B2;
    label_000ED6A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6A0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->ecx);
    label_000ED6B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6B2u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ED6C4;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    goto label_000ED76B;
    label_000ED6C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6C4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = (int8_t)(lift_load8(cpu->ecx));
    cpu->eax = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = (int8_t)(lift_load8(cpu->ecx));
    cpu->ecx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000ED6E4;
    goto label_000ED6E6;
    label_000ED6E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6E4u);
    goto label_000ED6A0;
    label_000ED6E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6E6u);
    goto label_000ED664;
    label_000ED6EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6EBu);
    goto label_000ED769;
    label_000ED6ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6EDu);
    goto label_000ED6F8;
    label_000ED6EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6EFu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->edx);
    label_000ED6F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED6F8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000ED769;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    cpu->ecx = (int8_t)(lift_load8(cpu->ebp + 0xFFFFFFFFu));
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000ED767;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->eax);
    goto label_000ED736;
    label_000ED724: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED724u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edx);
    label_000ED736: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED736u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000ED745;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    goto label_000ED76B;
    label_000ED745: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED745u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    cpu->ecx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax]);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    cpu->edx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax]);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000ED765;
    goto label_000ED767;
    label_000ED765: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED765u);
    goto label_000ED724;
    label_000ED767: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED767u);
    goto label_000ED6EF;
    label_000ED769: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED769u);
    cpu->eax = 0u;
    label_000ED76B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED76Bu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED770u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x17u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED785u); lift_push32(cpu, r); sfera_sub_004EB300(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED790u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED7A9u); lift_push32(cpu, r); sfera_sub_004EB8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED7B0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x21u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED7C2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED7D0u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED7E1;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000ED7E1;
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
    label_000ED7E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED7E1u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED7F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    cpu->esp -= 0x18u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED834;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED808;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ED808: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED808u);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"FileMap::size: open file %s error"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x75u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED82Bu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ED834: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED834u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, (uintptr_t)"FileMap::size: file is not opened"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0x72u);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED853u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->eax = 0u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED860u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED87A;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED8A0;
    cpu->eax = lift_load32(cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000ED87A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED87Au);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"FileMap::get_ptr: file is not opened"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x85u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED89Du); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000ED8A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED8A0u);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, (uintptr_t)"FileMap::get_ptr: open file %s error"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0x87u);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED8C7u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED8E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED8E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED92B;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000ED92B;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x4ED8F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED8FBu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ED925;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"Error unmappnig file %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x63u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED922u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000ED925: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED925u);
    lift_store32(cpu->esi, 0u);
    label_000ED92B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED92Bu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED930u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED97C;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000ED97C;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x4ED946u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED94Cu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ED976;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"Error unmappnig file %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x63u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED973u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000ED976: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED976u);
    lift_store32(cpu->esi, 0u);
    label_000ED97C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED97Cu);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x20u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED988u); lift_push32(cpu, r); sfera_sub_004EE7D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4ED98Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED993u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esi + 0x27u, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4ED9ADu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED9B3u);
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ED9CA;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000ED9CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED9CAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetFileSize), LIFT_CODE_TOKEN_VA(0x4ED9CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED9D4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x4ED9E2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED9E8u);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_000EDA11;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::CloseHandle);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED9F8u), LIFT_CODE_TOKEN_RVA(0xED9F6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED9F8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x4EDA01u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDA07u);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEDA0Cu), LIFT_CODE_TOKEN_RVA(0xEDA0Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDA0Cu);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(0u)) goto label_000EDA22;
    label_000EDA11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDA11u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDA22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDA22u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDA30u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store8(cpu->esi + 8u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDA49u); lift_push32(cpu, r); sfera_sub_004ED930(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDA60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDA60u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4EDA76u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDA7Cu);
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EDAAB;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"CHash8Mem: init error"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Memory\\hash8mem.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDAA8u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000EDAAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDAABu);
    lift_push32(cpu, 0x800u);
    cpu->edx = (uint32_t)(cpu->esi + 0xAu);
    cpu->ecx = 0u;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->edx);
    lift_store16(cpu->esi + 8u, cpu->ecx & 0xFFFFu);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EDAC2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDAC7u);
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000EDAEB;
    label_000EDAD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDAD3u);
    cpu->edi = lift_load32(cpu->esi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store16(cpu->edi + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 8u), 0u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000EDAD3;
    label_000EDAEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDAEBu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = 0xFFFFu;
    lift_store16(cpu->ebx + cpu->eax + 0xFFFFFFFCu, cpu->ecx & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + cpu->edx + 0xFFFFFFF8u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDB10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = 0xFFFFu;
    if ((uint16_t)(lift_load16(cpu->esi + 8u)) != (uint16_t)((cpu->eax & 0xFFFFu))) goto label_000EDC32;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = 2u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EDB56;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"CHash8Mem::register_str: more than 65535 elements"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Memory\\hash8mem.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x31u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDB53u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000EDB56: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDB56u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x32u)) goto label_000EDB71;
    cpu->edi = 0x32u;
    label_000EDB71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDB71u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)((cpu->ecx & 0xFFFFu)) & 0xFFFFu);
    lift_store16(cpu->esi + 8u, cpu->edx & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFFFu)) goto label_000EDB95;
    cpu->ecx = 0xFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    lift_store32(cpu->esi + 4u, 0xFFFFu);
    label_000EDB95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDB95u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EDBA2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDBA8u);
    cpu->esp += 8u;
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EDBDD;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"CHash8Memory::register_str: Not enough memory. Request size = %d"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Memory\\hash8mem.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x3Du);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDBDAu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EDBDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDBDDu);
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000EDC0E;
    label_000EDBE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDBE6u);
    cpu->ecx = lift_load16(cpu->esi + 8u);
    cpu->ebx = lift_load32(cpu->esi);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    cpu->ecx += cpu->eax;
    lift_store16(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u) + 4u, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load16(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx += cpu->eax;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edx) * 8u), 0u);
    ++cpu->eax;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000EDBE6;
    label_000EDC0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDC0Eu);
    cpu->edx = lift_load16(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx += cpu->edi;
    cpu->ecx = 0xFFFFu;
    lift_store16(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + 0xFFFFFFFCu, cpu->ecx & 0xFFFFu);
    cpu->edx = lift_load16(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx += cpu->edi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + 0xFFFFFFF8u, 0u);
    cpu->ebx = lift_pop32(cpu);
    label_000EDC32: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDC32u);
    cpu->ecx = lift_load16(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + 4u)) & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load16(cpu->esi + 8u);
    lift_store16(cpu->esi + 8u, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load16(cpu->ebp + 0xCu);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0xAu);
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx)) & 0xFFFFu);
    lift_store16(cpu->eax + 4u, cpu->esi & 0xFFFFu);
    lift_store16(cpu->edx, cpu->ecx & 0xFFFFu);
    cpu->eax = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDC70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDC70u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = cpu->edi;
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(4u), 32u);
    cpu->ebx &= 0x3FFu;
    cpu->esi = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + 0xAu);
    cpu->edx = 0xFFFFu;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ecx);
    if ((uint16_t)((cpu->esi & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_000EDCD0;
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 8u) + 4u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 8u))), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000EDCC1;
    label_000EDCA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDCA6u);
    cpu->edx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_000EDCCD;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 8u));
    cpu->esi = cpu->eax & 0xFFFFu;
    cpu->eax = lift_load16(cpu->edx + 4u);
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->edi)) goto label_000EDCA6;
    label_000EDCC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDCC1u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi & 0xFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDCCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDCCDu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000EDCD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDCD0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDCD7u); lift_push32(cpu, r); sfera_sub_004EDB10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDCE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDCE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    lift_store8(cpu->edi, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000EDD35;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000EDD35;
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000EDD35;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000EDD07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD07u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000EDD07;
    cpu->eax -= cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EDD1C;
    label_000EDD13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD13u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->eax)) == (uint8_t)(0x5Cu)) goto label_000EDD1C;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EDD13;
    label_000EDD1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD1Cu);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EDD26u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD2Cu);
    cpu->esp += 0xCu;
    lift_store8(cpu->edi + cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->esi = lift_pop32(cpu);
    label_000EDD35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD35u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD40u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = cpu->edi;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4EDD54u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD5Au);
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EDD89;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"CHash32Mem: init. Not enough memory"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Memory\\hash32mem.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0xBu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDD86u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000EDD89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDD89u);
    lift_push32(cpu, 0x40000u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EDDA1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDDA6u);
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000EDDD4;
    cpu->ecx = 0u;
    label_000EDDB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDDB4u);
    cpu->edi = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_store32(cpu->ecx + cpu->edi, cpu->eax);
    cpu->ecx += 0x1Au;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000EDDB4;
    cpu->edx = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + cpu->edx + 0xFFFFFFE6u, 0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDDD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDDD4u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + cpu->eax + 0xFFFFFFE6u, 0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDDF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDDF0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->eax = cpu->edi;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(9u), 32u);
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0xCu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000EDE0F;
    cpu->eax |= cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDE0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDE0Fu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = lift_load32(cpu->ecx + cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ecx + cpu->esi + 4u)) == (uint32_t)(cpu->edi)) goto label_000EDE3E;
    label_000EDE20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDE20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFFFFFu)) goto label_000EDE3B;
    cpu->ecx = cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ecx + cpu->esi + 4u)) != (uint32_t)(cpu->edi)) goto label_000EDE20;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDE3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDE3Bu);
    cpu->eax |= 0xFFFFFFFFu;
    label_000EDE3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDE3Eu);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDE50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDE50u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(9u), 32u);
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ecx);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_000EDE7C;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDE7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDE7Cu);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + cpu->edi);
    cpu->eax += cpu->edi;
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) == (uint32_t)(cpu->ebx)) goto label_000EDEC6;
    cpu->edi = cpu->edi;
    label_000EDE90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDE90u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFFFFFu)) goto label_000EDEDE;
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->eax += cpu->edi;
    cpu->esi = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebx)) goto label_000EDE90;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000EDEC3;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 8u, cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDEC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDEC3u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000EDEC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDEC6u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edi, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 8u, cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EDEDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDEDEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDEF0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDF03u); lift_push32(cpu, r); sfera_sub_004EDDF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000EDF13;
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000EDF13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDF13u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EDFBD;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x32u)) goto label_000EDF39;
    cpu->edi = 0x32u;
    label_000EDF39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDF39u);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EDF4Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDF50u);
    cpu->esp += 8u;
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EDF86;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"CHash32Mem: register_str. Not enough memory. Requested size = %d"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Memory\\hash32mem.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x36u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EDF83u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EDF86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDF86u);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000EDFAB;
    (void)cpu;
    label_000EDF90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDF90u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ebx = lift_load32(cpu->esi);
    cpu->eax += cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_store32(cpu->eax + cpu->ebx, cpu->edx);
    ++cpu->ecx;
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000EDF90;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    label_000EDFAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDFABu);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax += cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_store32(cpu->eax + cpu->ecx + 0xFFFFFFE6u, 0xFFFFFFFFu);
    label_000EDFBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EDFBDu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->ecx + 4u, cpu->ebx);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ecx + 4u);
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(9u), 32u);
    cpu->edi = cpu->ebx & 0xFFFFu;
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0xCu);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->ecx, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE000u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x534u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFAECu, cpu->edx);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFAF0u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE027u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE02Du);
    cpu->edi = cpu->eax;
    lift_push32(cpu, 0xA4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFAF4u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE043u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE048u);
    cpu->edx = lift_load32(cpu->ebx + 0xC4u);
    cpu->ecx = lift_load32(cpu->ebx + 0xB8u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u);
    cpu->eax = 3u;
    lift_store32(cpu->ebp + 0xFFFFFB24u, cpu->edx);
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFB08u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFB2Cu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFB20u, cpu->eax);
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFB00u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xB4u);
    lift_push32(cpu, 0u);
    lift_store32(cpu->ebp + 0xFFFFFB18u, cpu->ecx);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFAF8u, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE0A9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE0AFu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE0B6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE0BCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE2A4;
    cpu->esi += 0x68u;
    label_000EE0D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE0D0u);
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFB18u)) == (uint32_t)(cpu->eax)) goto label_000EE2A4;
    lift_store32(cpu->esi + 0xFFFFFFB8u, cpu->eax);
    cpu->edx = 0x6E6B6E55u;
    cpu->ebx = (uint32_t)(cpu->esi + 0xFFFFFF98u);
    lift_store32(cpu->ebx, cpu->edx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"Unknown") + 4u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFAD0u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store8(cpu->esi + 0xFFFFFFBCu, cpu->eax & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFAFFu, cpu->eax & 0xFFu);
    lift_store32(cpu->ebp + 0xFFFFFAD4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFAD8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFADCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFAE0u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFACCu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFAD0u, 0x14u);
    lift_native_call(cpu, native_function_address32(&::SymGetLineFromAddr), LIFT_CODE_TOKEN_VA(0x4EE13Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE141u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE1AD;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFADCu);
    cpu->eax = cpu->edx;
    lift_store8(cpu->ebp + 0xFFFFFAFFu, 1u);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000EE157: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE157u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EE157;
    cpu->eax -= cpu->edi;
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000EE179;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE170: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE170u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->edx)) == (uint8_t)(0x5Cu)) goto label_000EE179;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EE170;
    label_000EE179: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE179u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x1Fu)) goto label_000EE18C;
    cpu->edi = 0x1Fu;
    goto label_000EE190;
    label_000EE18C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE18Cu);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000EE1AD;
    label_000EE190: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE190u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFAD8u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->eax + cpu->edx + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0xFFFFFFB8u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE1A0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE1A6u);
    cpu->esp += 0xCu;
    lift_store8(cpu->ebx + cpu->edi, 0u);
    label_000EE1AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE1ADu);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFAF4u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBA4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = 0u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFAE4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFAE4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFAE8u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFBA4u, 0x458u);
    lift_store32(cpu->ebp + 0xFFFFFBF4u, 0x400u);
    lift_native_call(cpu, native_function_address32(&::SymFromAddr), LIFT_CODE_TOKEN_VA(0x4EE1ECu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE1F2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE243;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFBF8u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000EE200: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE200u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EE200;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x3Fu)) goto label_000EE217;
    cpu->edi = 0x3Fu;
    goto label_000EE21B;
    label_000EE217: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE217u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000EE24C;
    label_000EE21B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE21Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFAE4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBF8u);
    lift_store32(cpu->esi, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE233u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE239u);
    cpu->esp += 0xCu;
    lift_store8(cpu->ebx + cpu->edi + 0x24u, 0u);
    goto label_000EE24C;
    label_000EE243: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE243u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xFFFFFAFFu)) == (uint8_t)(0u)) goto label_000EE26A;
    label_000EE24C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE24Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFAF8u);
    ++cpu->eax;
    cpu->esi += 0x70u;
    lift_store32(cpu->ebp + 0xFFFFFAF8u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFAECu))) goto label_000EE2AA;
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFAF4u);
    label_000EE26A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE26Au);
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFAF0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE289u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE28Fu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE296u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE29Cu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE0D0;
    label_000EE2A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE2A4u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFAF8u);
    label_000EE2AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE2AAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE2C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE2C0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2ECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFD14u, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFD18u, cpu->ecx);
    lift_push32(cpu, 4u);
    lift_native_call(cpu, native_function_address32(&::SymSetOptions), LIFT_CODE_TOKEN_VA(0x4EE2E3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE2E9u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE2EDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE2F3u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4EE2F4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE2FAu);
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000EE315;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    cpu->ecx = 0xB3u;
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFD28u);
    lift_movs32(cpu, 1u);
    goto label_000EE366;
    label_000EE315: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE315u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEE31Au); lift_push32(cpu, r); sfera_sub_004EE31A(cpu,r); if (cpu->eip != r) return; }
    sfera_sub_004EE31A(cpu, stop_address); return;
    label_000EE366: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE366u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFD28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFD14u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFD18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE37Eu); lift_push32(cpu, r); sfera_sub_004EE000(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE31A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE31Au);
    lift_store32(cpu->ebp + 0xFFFFFD24u, lift_pop32(cpu));
    lift_store32(cpu->ebp + 0xFFFFFD20u, cpu->ebp);
    lift_store32(cpu->ebp + 0xFFFFFD1Cu, cpu->esp);
    lift_push32(cpu, 0x2CCu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFD28u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE33Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE33Fu);
    cpu->esp += 0xCu;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFD24u);
    lift_store32(cpu->ebp + 0xFFFFFDE0u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFD20u);
    lift_store32(cpu->ebp + 0xFFFFFDDCu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFD1Cu);
    lift_store32(cpu->ebp + 0xFFFFFDECu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFD28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFD14u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFD18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE37Eu); lift_push32(cpu, r); sfera_sub_004EE000(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE390u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x280u);
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE3A6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE3ABu);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->edi + 0x280u, cpu->esi);
    lift_store32(cpu->edi + 0x284u, cpu->esi);
    lift_store32(cpu->edi + 0x288u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000EE461;
    cpu->esi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::malloc);
    cpu->edi += 4u;
    lift_store32(cpu->ebp + 0xCu, 0x14u);
    cpu->edi = cpu->edi;
    label_000EE3E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE3E0u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->edi + 4u, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE3E6u), LIFT_CODE_TOKEN_RVA(0xEE3E4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE3E6u);
    cpu->esp += 4u;
    lift_store32(cpu->edi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE416;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, (uintptr_t)"Not enough memory. len = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, (uintptr_t)"Logs\\AntifloodQueue.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF4u, 0x1Bu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE413u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EE416: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE416u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->edi + 0xCu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE41Cu), LIFT_CODE_TOKEN_RVA(0xEE41Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE41Cu);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE44D;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Not enough memory. len = %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\AntifloodQueue.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x20u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE44Au); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EE44D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE44Du);
    cpu->edi += 0x20u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xCu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE3E0;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000EE461: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE461u);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE470u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::free);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ecx + 0xCu);
    cpu->edi = 0x14u;
    label_000EE481: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE481u);
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFF8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE48E;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE48Bu), LIFT_CODE_TOKEN_RVA(0xEE489u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE48Bu);
    cpu->esp += 4u;
    label_000EE48E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE48Eu);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE49A;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE497u), LIFT_CODE_TOKEN_RVA(0xEE495u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE497u);
    cpu->esp += 4u;
    label_000EE49A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE49Au);
    cpu->esi += 0x20u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE481;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE4B0u);
    cpu->eax = lift_load32(cpu->ecx + 0x280u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE4C0u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x280u)), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE4D0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x280u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_000EE508;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"AntifloodQueue::pop_record: queue underflow"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Logs\\AntifloodQueue.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x74u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE505u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000EE508: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE508u);
    cpu->ecx = lift_load32(cpu->esi + 0x288u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x280u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x280u, v); }
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    ++cpu->ecx;
    cpu->eax += cpu->esi;
    lift_store32(cpu->esi + 0x288u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x14u)) goto label_000EE531;
    lift_store32(cpu->esi + 0x288u, 0u);
    label_000EE531: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE531u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE540u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->esp -= 0xCu;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE550: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE550u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EE550;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(lift_load32(cpu->ebx))) goto label_000EE5AA;
    cpu->eax = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EE572u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE578u);
    cpu->esp += 8u;
    lift_store32(cpu->edi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE5AA;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"AntifloodQueue::copy_str: not enough memory. Len = %d"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Logs\\AntifloodQueue.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x98u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE5A7u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000EE5AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE5AAu);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4EE5B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE5B7u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE5D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE5D0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->ecx + 0x280u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x288u);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, 0xFFFFFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000EE684;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->edi;
    label_000EE600: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE600u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->edi;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    cpu->edx = lift_load32(cpu->esi + cpu->ecx + 0xCu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE610: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE610u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE630;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000EE62C;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE630;
    cpu->eax += 2u;
    cpu->edx += 2u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000EE610;
    label_000EE62C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE62Cu);
    cpu->eax = 0u;
    goto label_000EE635;
    label_000EE630: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE630u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EE635: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE635u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE648;
    cpu->edx = lift_load32(cpu->esi + cpu->ecx + 0x14u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    if ((uint8_t)(lift_load8(cpu->esi + cpu->ecx)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_000EE648;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->edi);
    label_000EE648: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE648u);
    ++cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE650;
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    label_000EE650: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE650u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xFFFFFFF8u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE600;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000EE684;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000EE684;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_store32(cpu->eax + cpu->ecx + 0x14u, (uint64_t)(lift_load32(cpu->eax + cpu->ecx + 0x14u)) + 1u);
    cpu->eax += cpu->ecx;
    cpu->eax += 0x18u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EE672u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE678u);
    cpu->esp += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000EE684: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE684u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE690u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x280u)), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000EE6CA;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, (uintptr_t)"AntifloodQueue::push_record: queue overflow"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uintptr_t)"Logs\\AntifloodQueue.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0x4Eu);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE6C7u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000EE6CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE6CAu);
    cpu->eax = lift_load32(cpu->esi + 0x284u);
    cpu->edi = cpu->eax;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    ++cpu->eax;
    cpu->edi += cpu->esi;
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x284u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x14u)) goto label_000EE6EB;
    lift_store32(cpu->esi + 0x284u, cpu->ebx);
    label_000EE6EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE6EBu);
    lift_store32(cpu->esi + 0x280u, (uint64_t)(lift_load32(cpu->esi + 0x280u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EE6F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE6FBu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->esp += 4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->edi + 0x14u, 1u);
    lift_store8(cpu->edi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE71Bu); lift_push32(cpu, r); sfera_sub_004EE540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE72Eu); lift_push32(cpu, r); sfera_sub_004EE540(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x280u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x288u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000EE7C2;
    cpu->edx = lift_load32(cpu->esi + 0x280u);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->edx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE750: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE750u);
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = lift_load32(cpu->eax + cpu->esi + 0xCu);
    cpu->eax += cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    label_000EE761: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE761u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE781;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000EE77D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE781;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000EE761;
    label_000EE77D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE77Du);
    cpu->eax = 0u;
    goto label_000EE786;
    label_000EE781: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE781u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EE786: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE786u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = 1u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE792;
    lift_store32(cpu->ebp + 8u, (uint64_t)(lift_load32(cpu->ebp + 8u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000EE792: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE792u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0u)) goto label_000EE79D;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000EE79D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE79Du);
    cpu->ebx += cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x14u)) goto label_000EE7A6;
    cpu->ebx = 0u;
    label_000EE7A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE7A6u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->ebp + 0xFFFFFFF8u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE750;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 8u)) >= (int32_t)(uint32_t)(0xAu)) goto label_000EE7C2;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) != (uint32_t)(1u)) goto label_000EE7C2;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000EE7C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE7C2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE7D0u);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000EE7D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE7D6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000EE7D6;
    cpu->eax -= cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EE7EC;
    label_000EE7E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE7E3u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ecx)) == (uint8_t)(0x5Cu)) goto label_000EE7EC;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EE7E3;
    label_000EE7EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE7ECu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 1u);
    lift_return(cpu, 0u, stop_address); return;
}






LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE81F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE81Fu);
    const uint32_t callback_address = lift_load32(cpu->esp + 4u);
    auto callback = reinterpret_cast<void(__cdecl*)()>(static_cast<uintptr_t>(callback_address));
    cpu->eax = std::atexit(callback) == 0 ? callback_address : 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE8C0u);
    cpu->edi = cpu->edi;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, lift_load32(cpu->ebp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE8CDu); lift_push32(cpu, r); sfera_sub_004EE81F(cpu,r); if (cpu->eip != r) return; }
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ecx = lift_pop32(cpu);
    --cpu->eax;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE8D7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE8D7u);
    cpu->edi = cpu->edi;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 8u)), r=(uint64_t)(2u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000EE90A;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004EF5B4));
    cpu->esi = (uint32_t)(cpu->edi + 0xFFFFFFFCu);
    lift_push32(cpu, lift_load32(cpu->esi)); lift_push32(cpu, 0xCu); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE8F8u); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->ebp + 8u)) & (1u)) == 0u) goto label_000EE905;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE904u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu);
    label_000EE905: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE905u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_000EE91E;
    label_000EE90A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE90Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE90Fu); lift_push32(cpu, r); sfera_sub_004EF5B4(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->ebp + 8u)) & (1u)) == 0u) goto label_000EE91C;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EE91Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu);
    label_000EE91C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE91Cu);
    cpu->eax = cpu->edi;
    label_000EE91E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE91Eu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE92A(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(0x4EE92Au); (void)stop_address; lift_trap(cpu, 0x4EE92Au, "client C++ exception path reached"); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE940u);
    { uint64_t l=(uint64_t)(g_sfera_crt_startup_runtime.processor_feature_10), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u)) {
        sfera_sub_004EE976(cpu, stop_address);
        return;
    }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE949u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    cpu->esp &= 0xFFFFFFF8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(int32_t)trunc(lift_load_f64(cpu->esp));
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE976(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE976u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x20u;
    cpu->esp &= 0xFFFFFFF0u;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0x10u)))));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE9D5;
    label_000EE999: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE999u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000EE9BD;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp);
    cpu->ecx ^= 0x80000000u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x7FFFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint64_t)(cpu->edx) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    goto label_000EE9E9;
    label_000EE9BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE9BDu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x7FFFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    goto label_000EE9E9;
    label_000EE9D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE9D5u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)((cpu->edx) & (0x7FFFFFFFu)) != 0u) goto label_000EE999;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000EE9E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE9E9u);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9EC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE9ECu);
    lift_x87_set(cpu, 0u, std::sqrt(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9F2(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE9F2u);
    lift_x87_set(cpu, 0u, std::cos(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE9F8u);
    lift_x87_set(cpu, 0u, std::sin(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9FE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EE9FEu);
    const double right = lift_x87_get(cpu, 0u);
    const double left = lift_x87_get(cpu, 1u);
    lift_x87_set(cpu, 1u, std::pow(left, right));
    lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEA10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    cpu->ecx -= cpu->eax;
    cpu->ecx &= 0xFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax |= cpu->ecx;
    cpu->ecx = lift_pop32(cpu);
    sfera_sub_004EEAF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEA40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEA40u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->edi = 0u;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000EEA61;
    ++cpu->edi;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    label_000EEA61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEA61u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000EEA7D;
    ++cpu->edi;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    label_000EEA7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEA7Du);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EEA99;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx = cpu->ebx;
    goto label_000EEADA;
    label_000EEA99: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEA99u);
    cpu->ebx = cpu->eax;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_000EEAA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEAA7u);
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->ecx = lift_rotate_carry_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = lift_rotate_carry_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->ebx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EEAA7;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->esi = cpu->eax;
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x1Cu), 32u, 0u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000EEAD5;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000EEAD5;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000EEAD6;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000EEAD6;
    label_000EEAD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEAD5u);
    --cpu->esi;
    label_000EEAD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEAD6u);
    cpu->edx = 0u;
    cpu->eax = cpu->esi;
    label_000EEADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEADAu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EEAE4;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EEAE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEAE4u);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEAF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEAF0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = ~((uint64_t)(cpu->eax));
    cpu->ecx &= cpu->eax;
    cpu->eax = cpu->esp;
    cpu->eax &= 0xFFFFF000u;
    label_000EEB04: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB04u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_000EEB12;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_pop32(cpu);
    {
        uint64_t left = cpu->esp;
        uint64_t right = cpu->eax;
        cpu->esp = right;
        cpu->eax = left;
    }
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp, cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
    label_000EEB12: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB12u);
    cpu->eax -= 0x1000u;
    (void)(lift_load32(cpu->eax));
    goto label_000EEB04;
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB28(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB28u);
    lift_push32(cpu, 0x14u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEB34u); lift_push32(cpu, r); sfera_sub_004EF270(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) & (uint64_t)(0u));
    label_000EEB38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB38u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EEB77;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->ecx -= lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 8u, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ebp + 0x14u)), LIFT_CODE_TOKEN_RVA(0xEEB49u), LIFT_CODE_TOKEN_RVA(0xEEB46u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB49u);
    goto label_000EEB38;
    label_000EEB77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB77u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEB83u); lift_push32(cpu, r); sfera_sub_004EF2B5(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB4B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB4Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0xE06D7363u)) goto label_000EEB6F;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    lift_return(cpu, 0u, stop_address); return;
    label_000EEB6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB6Fu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEEB74u); lift_push32(cpu, r); sfera_sub_004EF2DA(cpu,r); if (cpu->eip != r) return; }
    sfera_sub_004EEB74(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB74(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB74u);
    cpu->esp = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEB83u); lift_push32(cpu, r); sfera_sub_004EF2B5(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB86(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEB86u);
    lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEB92u); lift_push32(cpu, r); sfera_sub_004EF270(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) & (uint64_t)(0u));
    cpu->esi = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 0x10u));
    lift_store32(cpu->ebp + 8u, (uint64_t)(lift_load32(cpu->ebp + 8u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) & (uint64_t)(0u));
    label_000EEBA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEBA6u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EEBB6;
    lift_store32(cpu->ebp + 8u, (uint64_t)(lift_load32(cpu->ebp + 8u)) - (uint64_t)(cpu->esi) - (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ebp + 0x14u)), LIFT_CODE_TOKEN_RVA(0xEEBB4u), LIFT_CODE_TOKEN_RVA(0xEEBB1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEBB4u);
    goto label_000EEBA6;
    label_000EEBB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEBB6u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 1u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEBC9u); lift_push32(cpu, r); sfera_sub_004EEBD1(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEBCEu); lift_push32(cpu, r); sfera_sub_004EF2B5(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEBD1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEBD1u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) != (uint32_t)(0u)) goto label_000EEBE8;
    lift_push32(cpu, lift_load32(cpu->ebp + 0x14u)); lift_push32(cpu, lift_load32(cpu->ebp + 0x10u)); lift_push32(cpu, lift_load32(cpu->ebp + 0xCu)); lift_push32(cpu, lift_load32(cpu->ebp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEEBE8u); lift_push32(cpu, r); sfera_sub_004EEB28(cpu,r); if (cpu->eip != r) return; }
    label_000EEBE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEBE8u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEBE9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEBE9u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEBF5u); lift_push32(cpu, r); sfera_sub_004EF270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    label_000EEC00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC00u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x10u))) goto label_000EEC1B;
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->ecx = cpu->esi;
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ebp + 0x14u)), LIFT_CODE_TOKEN_RVA(0xEEC10u), LIFT_CODE_TOKEN_RVA(0xEEC0Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC10u);
    cpu->esi += lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) + 1u);
    goto label_000EEC00;
    label_000EEC1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC1Bu);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 1u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEC2Eu); lift_push32(cpu, r); sfera_sub_004EEC36(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEC33u); lift_push32(cpu, r); sfera_sub_004EF2B5(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC36(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC36u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE0u)) != (uint32_t)(0u)) goto label_000EEC4D;
    lift_push32(cpu, lift_load32(cpu->ebp + 0x18u)); lift_push32(cpu, lift_load32(cpu->ebp + 0xFFFFFFE4u)); lift_push32(cpu, lift_load32(cpu->ebp + 0xCu)); lift_push32(cpu, lift_load32(cpu->ebp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEEC4Du); lift_push32(cpu, r); sfera_sub_004EEB28(cpu,r); if (cpu->eip != r) return; }
    label_000EEC4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC4Du);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC4E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC4Eu);
    const double right = lift_x87_get(cpu, 0u);
    const double left = lift_x87_get(cpu, 1u);
    lift_x87_set(cpu, 1u, std::atan2(left, right));
    lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC54(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC54u);
    lift_x87_set(cpu, 0u, std::exp(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC60u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000EEC80;
    ++cpu->edi;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    label_000EEC80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC80u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000EEC9B;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    label_000EEC9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEC9Bu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EECBA;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->eax = cpu->edx;
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EED06;
    goto label_000EED0D;
    label_000EECBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EECBAu);
    cpu->ebx = cpu->eax;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    label_000EECC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EECC8u);
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->ecx = lift_rotate_carry_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = lift_rotate_carry_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->ebx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EECC8;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ecx = cpu->eax;
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x18u), 32u, 0u);
    {
        uint64_t left = cpu->ecx;
        uint64_t right = cpu->eax;
        cpu->ecx = right;
        cpu->eax = left;
    }
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x14u), 32u, 0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000EECF3;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000EECF3;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000EECFB;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esp + 0xCu))) goto label_000EECFB;
    label_000EECF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EECF3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esp + 0x18u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EECFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EECFBu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0xCu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esp + 0x10u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EED0D;
    label_000EED06: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED06u);
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EED0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED0Du);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED20u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EED39;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    lift_return(cpu, 16u, stop_address); return;
    label_000EED39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED39u);
    lift_push32(cpu, cpu->ebx);
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x14u), 32u, 0u);
    cpu->ebx += cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx += cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED54(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED54u);
    lift_x87_set(cpu, 0u, std::tan(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED5A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED5Au);
    lift_x87_set(cpu, 0u, std::acos(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED60u);
    lift_x87_set(cpu, 0u, std::atan(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED66(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED66u);
    lift_x87_push(cpu, std::floor(lift_load_f64(cpu->esp + 4u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED6C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED6Cu);
    lift_x87_set(cpu, 0u, std::asin(lift_x87_get(cpu, 0u)));
    lift_return(cpu, 0u, stop_address); return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EED80u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EEDA2;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx = cpu->ebx;
    goto label_000EEDE3;
    label_000EEDA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEDA2u);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    label_000EEDB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEDB0u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->ebx = lift_rotate_carry_right(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = lift_rotate_carry_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EEDB0;
    lift_divide_accumulator(cpu, cpu->ebx, 32u, 0u);
    cpu->esi = cpu->eax;
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x18u), 32u, 0u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000EEDDE;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000EEDDE;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000EEDDF;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esp + 0xCu))) goto label_000EEDDF;
    label_000EEDDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEDDEu);
    --cpu->esi;
    label_000EEDDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEDDFu);
    cpu->edx = 0u;
    cpu->eax = cpu->esi;
    label_000EEDE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEDE3u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEDF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEDF0u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) >= (uint8_t)(0x40u)) goto label_000EEE0A;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000EEE00;
    cpu->edx = lift_double_shift_left(cpu, cpu->edx, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    lift_return(cpu, 0u, stop_address); return;
    label_000EEE00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEE00u);
    cpu->edx = cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    lift_return(cpu, 0u, stop_address); return;
    label_000EEE0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEE0Au);
    cpu->eax = 0u;
    cpu->edx = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEE10u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) >= (uint8_t)(0x40u)) goto label_000EEE2A;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000EEE20;
    cpu->eax = lift_double_shift_right(cpu, cpu->eax, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    lift_return(cpu, 0u, stop_address); return;
    label_000EEE20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEE20u);
    cpu->eax = cpu->edx;
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    lift_return(cpu, 0u, stop_address); return;
    label_000EEE2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEE2Au);
    cpu->eax = 0u;
    cpu->edx = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE61(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEE61u);
    g_sfera_crt_startup_runtime.mainargs_result = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF088(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF088u);
    g_sfera_crt_startup_runtime.managed_app = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EF10Eu); lift_push32(cpu, r); sfera_sub_004EF33C(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EF113u); lift_push32(cpu, r); sfera_sub_004EF510(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EF12Du); lift_push32(cpu, r); sfera_sub_004EF4E8(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF142(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF142;
    label_000EEEAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEEAFu);
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEEBBu); lift_push32(cpu, r); sfera_sub_004EF270(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetStartupInfoW), LIFT_CODE_TOKEN_VA(0x4EEEC4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEECAu);
    if ((uint32_t)(lift_load32((uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.heap_compatibility_flag)) != (uint32_t)(cpu->ebx)) goto label_000EEEDD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::HeapSetInformation), LIFT_CODE_TOKEN_RVA(0xEEED7u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEEEDDu);
    label_000EEEDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEEDDu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    cpu->eax = lift_fs_load32(cpu, 0x18u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->ebx);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.startup_lock;
    label_000EEEF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEEF1u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedCompareExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->esi), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 12u;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEEFAu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000EEF17;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EEF0A;
    cpu->esi = 0u;
    ++cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esi);
    goto label_000EEF1A;
    label_000EEF0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF0Au);
    lift_push32(cpu, 0x3E8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x4EEF0Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF15u);
    goto label_000EEEF1;
    label_000EEF17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF17u);
    cpu->esi = 0u;
    ++cpu->esi;
    label_000EEF1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF1Au);
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EEF2D;
    lift_push32(cpu, 0x1Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF2Au); lift_push32(cpu, r); sfera_sub_004EF336(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu);
    goto label_000EEF68;
    label_000EEF2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF2Du);
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EEF62;
    g_sfera_crt_startup_runtime.startup_state = (uint32_t)(cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF4Bu); lift_push32(cpu, r); sfera_sub_004EF088(cpu,r); if (cpu->eip != r) return; }
    if (cpu->eax == 0u) {
        { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF4Bu); lift_push32(cpu, r); sfera_sub_004EF2C9(cpu,r); if (cpu->eip != r) return; }
        if (cpu->eax == 0u) {
            { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF4Bu); lift_push32(cpu, r); sfera_sub_004EF328(cpu,r); if (cpu->eip != r) return; }
        }
    }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EEF68;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->eax = 0xFFu;
    goto label_000EF082;
    label_000EEF62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF62u);
    g_sfera_crt_startup_runtime.has_cctor = (uint32_t)(cpu->esi);
    label_000EEF68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF68u);
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EEF8C;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004EEE61(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004FA041(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4AE0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4B10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4B50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4B80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4BC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4BF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4C30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4C60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4CA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4CD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4D10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4D40(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4D80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4DB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4DF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4E20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4E60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4EA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4ED0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4F10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4F40(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4F80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4FB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F4FF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5070(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F50E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F50F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5120(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5160(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5190(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F51D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F51F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5270(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5330(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5360(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F53A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F53D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5450(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5480(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F54C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F54F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5530(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5550(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5570(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5580(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5590(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F55B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F55E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5620(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5690(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5700(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5770(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F57A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F57E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5810(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5850(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5870(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5890(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5920(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F59B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5A40(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5AD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5B60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5BF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5C80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5C90(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5D20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5DB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5DD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5DE0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5E50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5EC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5F30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F5FA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6010(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6080(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F60F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6160(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F61D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6240(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F62B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6320(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6390(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6400(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6470(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6510(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6580(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6650(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6720(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F67F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F68C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6950(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F69C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6A30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6AA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6B10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6B80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6C10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6C80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6CF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6D60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6DD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6E40(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6EB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6F20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F6FA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7010(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7080(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F70F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7160(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F71D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7240(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F72B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7320(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7390(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7400(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7470(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F74E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7550(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F75C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7630(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F76A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7710(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7780(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F77B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F77F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7820(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7860(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7890(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F78D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7900(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7940(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7970(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F79B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F79E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7A20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7A50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7A90(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7AC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7B00(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7B30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7B70(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7BA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7BE0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7BF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7C20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7CA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7CD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7D10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7D40(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7D80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7DB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7DF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7E00(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7E30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7E70(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7EA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7EE0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7EF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7F20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7F60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7F90(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F7FD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8000(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8040(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8070(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F80B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8120(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8150(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8190(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F81C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8200(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8220(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8240(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8270(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F82B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F82D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F82F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8320(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8360(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8390(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F83D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F83F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8410(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8440(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8480(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F84A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F84C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F84F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8530(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8550(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8570(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F85A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F85E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F85F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8620(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8660(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8680(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F86A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F86D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8710(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8780(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F87A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F87C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F87F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8830(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8850(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8870(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F88A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F88E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8900(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8920(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8950(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8990(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F89B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F89D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8A00(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8A40(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8A60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8A80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8AB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8AF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8B10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8B30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8B90(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8BF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8C50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8C60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8D20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8D80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8DA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8DD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8E10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8E30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8E50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8E80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8EC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8EF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8F30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8F50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8F70(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F8FA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9080(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F90B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F90F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9110(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9130(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9160(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F91A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F91C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F91E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9210(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9250(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9280(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F92C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F92E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9300(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9330(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9370(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9390(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F93B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F93E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9420(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9440(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9460(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9490(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F94D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F94F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9510(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9540(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9580(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F95A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F95C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F95F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9630(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9650(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9670(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F96A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F96E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9700(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9720(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9730(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9750(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9780(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F97C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F97E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9800(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9830(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9870(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F98A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F98E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9900(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9920(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9950(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9990(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F99B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F99D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9A00(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9A40(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9A60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9A80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9AB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9AF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9B50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9B80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9BC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9BE0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9C00(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9C20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9C50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9C90(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9CC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9D00(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9D30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9D70(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9DA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9DE0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9E10(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9E50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9E80(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9EC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9EF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9F30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9F60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9FA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004F9FD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEF80u); lift_push32(cpu, r); sfera_sub_004FA010(cpu,r); if (cpu->eip != r) return; }
    g_sfera_crt_startup_runtime.startup_state = (uint32_t)(2u);
    label_000EEF8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF8Cu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFDCu)) != (uint32_t)(cpu->ebx)) goto label_000EEF99;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 8u;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF99u);
    label_000EEF99: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF99u);
    if ((uint32_t)(g_sfera_crt_startup_runtime.dynamic_tls_init_callback) == (uint32_t)(cpu->ebx)) goto label_000EEFBA;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.dynamic_tls_init_callback);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEFABu); lift_push32(cpu, r); sfera_sub_004EF420(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EEFBA;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_crt_startup_runtime.dynamic_tls_init_callback), LIFT_CODE_TOKEN_RVA(0xEEFBAu), LIFT_CODE_TOKEN_RVA(0xEEFB4u))) { return; }
    label_000EEFBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEFBAu);
    cpu->esi = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::GetCommandLineA()));
    label_000EEFC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEFC1u);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->esi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(0x20u)) goto label_000EF013;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000EEFD3;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) != (uint32_t)(cpu->ebx)) goto label_000EF013;
    label_000EEFD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEFD3u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000EEFE3;
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(0x20u)) goto label_000EEFE3;
    ++cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->esi);
    goto label_000EEFD3;
    label_000EEFE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEFE3u);
    if ((uint8_t)((lift_load8(cpu->ebp + 0xFFFFFFC0u)) & (1u)) == 0u) goto label_000EEFEF;
    cpu->eax = lift_load16(cpu->ebp + 0xFFFFFFC4u);
    goto label_000EEFF2;
    label_000EEFEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEFEFu);
    lift_push32(cpu, 0xAu);
    cpu->eax = lift_pop32(cpu);
    label_000EEFF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEFF2u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, lift_process_module_handle());
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EEFFFu); lift_push32(cpu, r); sfera_sub_0047D770(cpu,r); if (cpu->eip != r) return; }
    g_sfera_crt_startup_runtime.main_return_code = (uint32_t)(cpu->eax);
    if ((uint32_t)(g_sfera_crt_startup_runtime.managed_app) != (uint32_t)(cpu->ebx)) goto label_000EF068;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0xEF00Du));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEF013u);
    label_000EF013: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF013u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x22u)) goto label_000EF022;
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ecx);
    label_000EF022: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF022u);
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_ismbblead), LIFT_CODE_TOKEN_VA(0x4EF026u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF02Cu);
    cpu->ecx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EF035;
    ++cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->esi);
    label_000EF035: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF035u);
    ++cpu->esi;
    goto label_000EEFC1;
    label_000EF068: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF068u);
    if ((uint32_t)(g_sfera_crt_startup_runtime.has_cctor) != (uint32_t)(cpu->ebx)) goto label_000EF076;
    lift_native_call(cpu, native_function_address32(&::_cexit), LIFT_CODE_TOKEN_RVA(0xEF070u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEF076u);
    label_000EF076: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF076u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->eax = g_sfera_crt_startup_runtime.main_return_code;
    label_000EF082: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF082u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EF087u); lift_push32(cpu, r); sfera_sub_004EF2B5(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
    label_000EF142: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF142u);
    goto label_000EEEAF;
}



LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF270u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esp + 0x10u);
    cpu->esp -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esp);
    lift_push32(cpu, lift_load32(cpu->ebp + 0xFFFFFFF8u));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2B5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF2B5u);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2C9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF2C9u);
    lift_push32(cpu, 0xAu);
    lift_native_call(cpu, native_function_address32(&::IsProcessorFeaturePresent), LIFT_CODE_TOKEN_VA(0x4EF2CBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF2D1u);
    g_sfera_crt_startup_runtime.processor_feature_10 = (uint32_t)(cpu->eax);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2DA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF2DAu);
    lift_trap(cpu, cpu->eip, "std::terminate");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2E6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF2E6u);
    cpu->edi = cpu->edi;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(0xE06D7363u)) goto label_000EF322;
    if ((uint32_t)(lift_load32(cpu->eax + 0x10u)) != (uint32_t)(3u)) goto label_000EF322;
    cpu->eax = lift_load32(cpu->eax + 0x14u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x19930520u)) goto label_000EF31D;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x19930521u)) goto label_000EF31D;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x19930522u)) goto label_000EF31D;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x1994000u)) goto label_000EF322;
    label_000EF31D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF31Du);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEF322u); lift_push32(cpu, r); sfera_sub_004EF2DA(cpu,r); if (cpu->eip != r) return; }
    label_000EF322: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF322u);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF328(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF328u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004EF2E6));
    lift_native_call(cpu, native_function_address32(&::SetUnhandledExceptionFilter), LIFT_CODE_TOKEN_VA(0x4EF32Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF333u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF336(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF336u);
    lift_trap(cpu, cpu->eip, "CRT startup failure");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF33C(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(0x4EF33Cu); (void)stop_address; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF362(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(0x4EF362u); (void)stop_address; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF390(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(0x4EF390u); (void)stop_address; cpu->eax = lift_load32(cpu->esp + 4u) == lift_process_module_handle() ? 1u : 0u; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF3D0(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(0x4EF3D0u); (void)stop_address; cpu->eax = 0u; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF420(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(0x4EF420u); (void)stop_address; { uint32_t target = lift_load32(cpu->esp + 4u); uint32_t rva = lift_source_rva(target); uint32_t tls_slot = (uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.dynamic_tls_init_callback; cpu->eax = target == tls_slot || lift_is_native_code_address(target) || (rva >= 0x1000u && rva < 0xFC200u) ? 1u : 0u; } LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4AB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF4ABu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0xC0000005u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4BE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF4BEu);
    cpu->esp = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4E8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF4E8u);
    cpu->edi = cpu->edi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x30000u); lift_push32(cpu, 0x10000u);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_controlfp_s), LIFT_CODE_TOKEN_VA(0x4EF4F8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF4FDu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EF50E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xEF50Eu); lift_push32(cpu, r); sfera_sub_004EF5BA(cpu,r); if (cpu->eip != r) return; }
    label_000EF50E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF50Eu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF510u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5B4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF5B4u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5BA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF5BAu);
    lift_trap(cpu, cpu->eip, "invalid CRT parameter");
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF781(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF781u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, lift_fs_load32(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    cpu->esp -= lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = cpu->eax;
    lift_push32(cpu, 0u); lift_push32(cpu, lift_load32(cpu->ebp + 0xFFFFFFFCu));
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF7B4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF7B4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF7D0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF860u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF868(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF868u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF870u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF8A0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF8D0u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF900u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF908(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF908;
    label_00002CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x402CC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0u)) goto label_00002CE4;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402CD8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402CE1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00002CE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x402CE4u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000EF908: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF908u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    goto label_00002CC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF930u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF960u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF990u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF9C0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EF9CDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF9F0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EF9FDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFA20u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFA2Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFA50u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA58(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFA58u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFA80u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFA8Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFAB0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFABDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFAE0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFAEDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFB10u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFB1Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB21(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFB21u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFB50u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFB5Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFB80u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFB88u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFB90u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFB98u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFBF0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFBFDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFC20u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFC2Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFC50u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFC5Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFC80u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFC8Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC91(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFC91u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFCC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFCC0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFCCDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFCF0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4EFCFDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD01(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFD01u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFD30u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD38(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFD38u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFD40u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFD70u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFDA0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDA8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFDA8;
    label_00002CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x402CC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0u)) goto label_00002CE4;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402CD8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402CE1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00002CE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x402CE4u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000EFDA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFDA8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    goto label_00002CC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFDD0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDD8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFDD8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00402D20(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFE00u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFE30u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFE60u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFE68;
    label_000061E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4061E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) < (uint32_t)(0x10u)) goto label_000061F5;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4061F2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000061F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4061F5u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x18u, 0xFu);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store8(cpu->esi + 4u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000EFE68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFE68u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    goto label_000061E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFEA0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEA8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFEA8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFEB0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFEE0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFEE8;
    label_00006260: cpu->eip = LIFT_CODE_TOKEN_VA(0x406260u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000062B1;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4062A5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4062AEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000062B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4062B1u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000062C2;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4062BFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000062C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4062C2u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000EFEE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFEE8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_00006260;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFEF0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFF20u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF28(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFF28u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFF30u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFF60u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFF90u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFF98u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFFA0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFA8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFFA8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EFFD0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0000u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0030u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0038(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0038;
    label_000061E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4061E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) < (uint32_t)(0x10u)) goto label_000061F5;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4061F2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000061F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4061F5u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x18u, 0xFu);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store8(cpu->esi + 4u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0038: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0038u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    goto label_000061E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0070u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0078(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0078u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0080u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F00B0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFBCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F00B8;
    label_00006260: cpu->eip = LIFT_CODE_TOKEN_VA(0x406260u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000062B1;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4062A5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4062AEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000062B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4062B1u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000062C2;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4062BFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000062C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4062C2u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F00B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F00B8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_00006260;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F00C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F00F0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F00F8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0130u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0138(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0138u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0140u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0170u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0178(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0178u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0180(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0180;
    label_000062F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4062F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00006305;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406302u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00006305: cpu->eip = LIFT_CODE_TOKEN_VA(0x406305u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esi + 8u, cpu->eax & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->eax)) goto label_00006332;
    cpu->edx = (uint32_t)(cpu->eax + 0x27u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406326u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40632Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00006332: cpu->eip = LIFT_CODE_TOKEN_VA(0x406332u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0180: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0180u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    goto label_000062F0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F01B0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01B8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F01B8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F01C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F01F0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0220u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0228(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0228u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0230u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0238(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0238u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0270u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0278(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0278u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0280u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0288(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0288u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F02C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02C8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F02C8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F02D0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02D8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F02D8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0310(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0310;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0310: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0310u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0318(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0318u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0340(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0340;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0340: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0340u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0348(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0348;
    label_00014B90: cpu->eip = LIFT_CODE_TOKEN_VA(0x414B90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414BC5u); lift_push32(cpu, r); sfera_sub_004149A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414BCDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F0348: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0348u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_00014B90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0370(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0370;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0370: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0370u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0378(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0378;
    label_00014D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x414D30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D38u); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D40u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0378: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0378u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_00014D30;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F03A0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F03A9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03AB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F03ABu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F03B4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03B6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F03B6u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F03BFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03C1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F03C1u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F03CAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F03F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F03F0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F8;
    label_00015050: cpu->eip = LIFT_CODE_TOKEN_VA(0x415050u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415095u); lift_push32(cpu, r); sfera_sub_00406340(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41509Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F03F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F03F8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015050;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0420(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0420;
    label_000161C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161C0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4161C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0420: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0420u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0450(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0450;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0450: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0450u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0458(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0458;
    label_00015300: cpu->eip = LIFT_CODE_TOKEN_VA(0x415300u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415345u); lift_push32(cpu, r); sfera_sub_00409F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41534Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F0458: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0458u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015300;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0480(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0480;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0480: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0480u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0488(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0488;
    label_000154E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4154E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415525u); lift_push32(cpu, r); sfera_sub_0040D400(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41552Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F0488: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0488u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_000154E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F04B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F04B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B8;
    label_00015550: cpu->eip = LIFT_CODE_TOKEN_VA(0x415550u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415595u); lift_push32(cpu, r); sfera_sub_0040D4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41559Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F04B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F04B8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015550;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F04E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F04E0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E8;
    label_000155C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4155C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415605u); lift_push32(cpu, r); sfera_sub_0040D5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41560Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F04E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F04E8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_000155C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0510(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0510;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0510: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0510u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0518(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0518;
    label_00015630: cpu->eip = LIFT_CODE_TOKEN_VA(0x415630u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415675u); lift_push32(cpu, r); sfera_sub_0040D670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41567Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F0518: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0518u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015630;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0540u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0549u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F054B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F054Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0554u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0580;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0580u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0588(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0588;
    label_000B3CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3CD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D15u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D1Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F0588: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0588u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F05B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F05B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B8;
    label_00016330: cpu->eip = LIFT_CODE_TOKEN_VA(0x416330u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416375u); lift_push32(cpu, r); sfera_sub_0040A7A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41637Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F05B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F05B8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_00016330;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05E0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F05E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F05E0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05E8;
    label_000161C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161C0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4161C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F05E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F05E8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0610(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0610;
    label_00014990: cpu->eip = LIFT_CODE_TOKEN_VA(0x414990u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414998u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0610: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0610u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0640(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0640;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0640: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0640u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0648(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0648u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0653(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0653u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F065E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F065E;
    label_000166B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4166B0u);
    sfera_sub_00416650(cpu, stop_address); return;
    label_000F065E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F065Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000166B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0690(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0690;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0690: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0690u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0698(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0698;
    label_000166C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4166C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4166F5u); lift_push32(cpu, r); sfera_sub_0040A060(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4166FDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F0698: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0698u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_000166C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06A3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F06A3u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06AE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06AE;
    label_000167E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4167E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016817;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416814u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016817: cpu->eip = LIFT_CODE_TOKEN_VA(0x416817u);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416832u); lift_push32(cpu, r); sfera_sub_0040A060(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41683Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F06AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F06AEu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000167E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F06E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F06E0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E8;
    label_00016720: cpu->eip = LIFT_CODE_TOKEN_VA(0x416720u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416755u); lift_push32(cpu, r); sfera_sub_00408A50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41675Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F06E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F06E8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016720;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06F3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F06F3u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06FE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06FE;
    label_00016850: cpu->eip = LIFT_CODE_TOKEN_VA(0x416850u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00016887;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416884u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00016887: cpu->eip = LIFT_CODE_TOKEN_VA(0x416887u);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4168A2u); lift_push32(cpu, r); sfera_sub_00408A50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4168AAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F06FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F06FEu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00016850;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0730(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0730;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0730: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0730u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0738(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0738;
    label_00016780: cpu->eip = LIFT_CODE_TOKEN_VA(0x416780u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4167B5u); lift_push32(cpu, r); sfera_sub_0040A0C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4167BDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F0738: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0738u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016780;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0743(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0743u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F074E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F074E;
    label_000168C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4168C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000168F7;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4168F4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000168F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4168F7u);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416912u); lift_push32(cpu, r); sfera_sub_0040A0C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41691Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F074E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F074Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000168C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0780(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0780;
    label_00014990: cpu->eip = LIFT_CODE_TOKEN_VA(0x414990u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414998u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0780: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0780u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07B0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F07B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F07B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07B8;
    label_00014D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x414D30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D38u); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414D40u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F07B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F07B8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00014D30;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07C3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F07C3u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07CE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07CE;
    label_00017150: cpu->eip = LIFT_CODE_TOKEN_VA(0x417150u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017163;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417160u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017163: cpu->eip = LIFT_CODE_TOKEN_VA(0x417163u);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417180u); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417189u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F07CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F07CEu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017150;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0800(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0800;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0800: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0800u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0808(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0808;
    label_00016930: cpu->eip = LIFT_CODE_TOKEN_VA(0x416930u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416938u); lift_push32(cpu, r); sfera_sub_0040BB40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416940u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0808: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0808u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016930;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0813(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0813u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F081E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F081E;
    label_00017190: cpu->eip = LIFT_CODE_TOKEN_VA(0x417190u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000171A3;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4171A0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000171A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4171A3u);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4171C0u); lift_push32(cpu, r); sfera_sub_0040BB40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4171C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F081E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F081Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017190;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0850;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0850: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0850u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0858(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0858;
    label_00016950: cpu->eip = LIFT_CODE_TOKEN_VA(0x416950u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416958u); lift_push32(cpu, r); sfera_sub_0040BBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416960u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0858: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0858u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0863(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0863u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F086E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F086E;
    label_000171D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4171D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000171E3;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4171E0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000171E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4171E3u);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417200u); lift_push32(cpu, r); sfera_sub_0040BBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417209u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F086E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F086Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000171D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F08A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F08A0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A8;
    label_00016970: cpu->eip = LIFT_CODE_TOKEN_VA(0x416970u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4169A5u); lift_push32(cpu, r); sfera_sub_0040D740(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4169ADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F08A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F08A8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016970;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08B3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F08B3u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08BE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08BE;
    label_00017210: cpu->eip = LIFT_CODE_TOKEN_VA(0x417210u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00017247;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417244u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00017247: cpu->eip = LIFT_CODE_TOKEN_VA(0x417247u);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x417262u); lift_push32(cpu, r); sfera_sub_0040D740(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41726Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F08BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F08BEu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F08F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F08F0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F8;
    label_000169D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4169D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416A05u); lift_push32(cpu, r); sfera_sub_0040BC20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416A0Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F08F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F08F8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_000169D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0903(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0903u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F090E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F090E;
    label_00017280: cpu->eip = LIFT_CODE_TOKEN_VA(0x417280u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000172B7;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4172B4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000172B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4172B7u);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4172D2u); lift_push32(cpu, r); sfera_sub_0040BC20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4172DAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F090E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F090Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017280;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0940u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0949u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F094B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F094Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0954u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0956(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0956u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F095Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0980(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0980;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0980: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0980u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0988(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0988;
    label_00014990: cpu->eip = LIFT_CODE_TOKEN_VA(0x414990u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414998u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0988: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0988u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09B0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F09B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F09B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09B8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F09B8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09E0;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F09E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F09E0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A10(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A10;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0A10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A10u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A18(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A18;
    label_00018270: cpu->eip = LIFT_CODE_TOKEN_VA(0x418270u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0001829C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00018290;
    label_00018282: cpu->eip = LIFT_CODE_TOKEN_VA(0x418282u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418289u); lift_push32(cpu, r); sfera_sub_00402CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 8u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_00018282;
    label_00018290: cpu->eip = LIFT_CODE_TOKEN_VA(0x418290u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418298u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    label_0001829C: cpu->eip = LIFT_CODE_TOKEN_VA(0x41829Cu);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx, 0u);
    lift_store32(cpu->ebx + 4u, 0u);
    lift_store32(cpu->ebx + 8u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0A18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A18u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    goto label_00018270;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A40(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A40;
    label_00015040: cpu->eip = LIFT_CODE_TOKEN_VA(0x415040u);
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0A40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A40u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A48(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A48;
    label_000183C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4183C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000183E6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4183DBu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4183E3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000183E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4183E6u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0A48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A48u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A70u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0A79u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A7B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A7Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0A84u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A86(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A86u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0A8Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A91(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A91u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0A9Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A9C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0A9Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0AA5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0AD0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_0042B7D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B00(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B00;
    label_00018890: cpu->eip = LIFT_CODE_TOKEN_VA(0x418890u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418893u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418899u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F0B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0B00u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    goto label_00018890;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0B30u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_0042B7D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B60;
    label_00018890: cpu->eip = LIFT_CODE_TOKEN_VA(0x418890u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418893u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x418899u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F0B60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0B60u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFDD8u);
    goto label_00018890;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0BA0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0BA9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0BD0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0BD9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0C00u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_0047ED10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0C30u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB4u);
    sfera_sub_0047ED10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C3B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0C3Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB0u);
    sfera_sub_0047EDB0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0C80u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0C89u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0CC0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0CC9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0CF0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0CF9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CFB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0CFBu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D04u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D06(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D06u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D0Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D11(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D11u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D1Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D1C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D1Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D25u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D50u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D5Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D5E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D5Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D6Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D6C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D6Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D78u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D7A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D7Au);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D86u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D88u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0D94u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D96(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0D96u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0DA2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0DE0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E10u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E19u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E1Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E24u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E26u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E2Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E31(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E31u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E3Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E3C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E3Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E45u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E47(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E47u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E50u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E52(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E52u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E5Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E5D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E5Du);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0E66u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0E90u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_items;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0EC0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0EC0;
    label_000161C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161C0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4161C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0EC0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0EF0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0EF9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0F20u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0F50u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0F80u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0FB0;
    label_0002E1E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E1E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E20A;
    cpu->edx = 0x65u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E1FEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E207u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002E20A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E20Au);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F0FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0FB0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_0002E1E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0FE0u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0FE9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FEB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F0FEBu);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F0FF4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1020(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1020;
    label_000313C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4313C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_000313D5;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4313D2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000313D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4313D5u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esi + 8u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F1020: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1020u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_000313C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1050(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1050;
    label_00031410: cpu->eip = LIFT_CODE_TOKEN_VA(0x431410u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x48u)) < (uint32_t)(0x10u)) goto label_00031426;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431423u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00031426: cpu->eip = LIFT_CODE_TOKEN_VA(0x431426u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x48u, 0xFu);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    lift_store8(cpu->esi + 0x34u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00031447;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431444u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00031447: cpu->eip = LIFT_CODE_TOKEN_VA(0x431447u);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F1050: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1050u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00031410;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1080u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F108Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F10C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F10C0u);
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F10F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F10F0u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F10F9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1120u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1129u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F112B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F112Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1134u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1170u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE44u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F117Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F117E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F117Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE44u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F118Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F11C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F11C0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F11C8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F11C8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1200u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1230u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1238(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1238u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1270u);
    cpu->eax = g_sfera_frame_runtime.color_lookup_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_frame_runtime.color_lookup_flags = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A0;
    label_00051CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x451CE0u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451CEEu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
    label_000F12A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F12A0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A8;
    label_00051CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x451CE0u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451CEEu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
    label_000F12A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F12A8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E0;
    label_00051CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x451CE0u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451CEEu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
    label_000F12E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F12E0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E8;
    label_00051CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x451CE0u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x451CEEu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
    label_000F12E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F12E8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1320u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1350u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1359u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F135B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F135Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1364u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1366(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1366u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F136Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1371(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1371u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F137Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F137C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F137Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1385u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1387(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1387u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1390u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1392(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1392u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F139Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F13D0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE1Cu);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13DB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F13DBu);
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13E9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F13E9u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE0Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F13F5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1430u);
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1460u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1490u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1498(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1498u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F14D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F14D0u);
    cpu->eax = g_sfera_grass_map_runtime.init_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_grass_map_runtime.init_guard = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1510u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F151Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F151E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F151Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F152Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F152C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F152Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1538u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F153A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F153Au);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1546u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1548(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1548u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1554u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1556(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1556u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1562u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1564(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1564u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1570u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1572(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1572u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F157Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F15B0;
    label_000161C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161C0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4161C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F15B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F15B0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F15E0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F15E9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15EB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F15EBu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F15F4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1620u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEC4u);
    sfera_sub_0047ED10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F162B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F162Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_0047EDB0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1670u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1679u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F16B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F16B0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F16B9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F16F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F16F0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F16F9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1730u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF68u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F173Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F173E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F173Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF68u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F174Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F174C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F174Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF58u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1758u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1790u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1799u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F17D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F17D0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0xC80u;
    sfera_sub_00430BC0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1800u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFF2C4u);
    cpu->ecx += 0xC80u;
    sfera_sub_00430BC0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1860u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1868(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1868u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFACu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1871u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F18A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F18A0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F18D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F18D0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1900u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1918;
    lift_store32(cpu->ebp + 0xFFFFFFB4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFB4u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1918: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1918u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1950u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1968;
    lift_store32(cpu->ebp + 0xFFFFFFCCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFCCu)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1968: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1968u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1969(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1969u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F19A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F19A0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F19B8;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE8u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F19B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F19B8u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F19E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F19E0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F19F8;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F19F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F19F8u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1A20u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A28(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1A28u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1A40;
    lift_store32(cpu->ebp + 0xFFFFFF90u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFF90u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1A40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1A40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A41(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1A41u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1A59;
    lift_store32(cpu->ebp + 0xFFFFFF90u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFF90u)) & (uint64_t)(0xFFFFFFFDu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1A59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1A59u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1A90u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1A98u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1AD0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AD8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1AD8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1AE0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AEB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1AEBu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AF3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1AF3u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AFE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1AFEu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B09(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B09u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B14(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B14u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B1C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B1Cu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B27(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B27u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B2F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B2Fu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEC8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1B3Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B3D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B3Du);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B45(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B45u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEC8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1B51u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B53(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B53u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B5B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B5Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B66(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1B66u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEC8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1B72u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BB0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE4Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BBB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BBBu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE30u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BC6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BC6u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFDF8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BD1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BD1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BDC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BDCu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE84u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BE7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BE7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE14u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BF2(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BF2u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BFD(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1BFDu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C08(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C08u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C10u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C1Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C26u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE68u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C31(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C31u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEA0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C3C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C3Cu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C44(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C44u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C4F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C4Fu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C57(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C57u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C62(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1C62u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1CA0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1CB8;
    lift_store32(cpu->ebp + 0xFFFFFFECu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFECu)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1CB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1CB8u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1CE0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CE8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1CE8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1CF0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D30u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1D39u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D3B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D3Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D43(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D43u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D4B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D4Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1D54u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D56(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D56u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D5E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D5Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1D67u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D69(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D69u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1D72u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D74(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1D74u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F1D7Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1DB0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF70u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DBC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1DBC;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F1DBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1DBCu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF70u);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DC7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1DC7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DCF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1DCFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DD7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1DD7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DDF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1DDFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E20u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E29(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1E29;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F1E29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E29u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E31(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E31u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E39(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E39u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E41(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E41u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E80u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x3Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E88u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x20u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E90u);
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1E98u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EA3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1EA3u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE84u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EAE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1EAEu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE68u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EB9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1EB9u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EC1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1EC1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE4Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1ECC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1ECCu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEA0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1ED7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1ED7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EDF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1EDFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EEA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1EEAu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EF5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1EF5u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F00u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F08(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F08u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F13(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F13u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F1Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F26u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F60u);
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F68(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F68u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF4Cu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F74(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1F74;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F1F74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F74u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF4Cu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F7F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F7Fu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F87(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1F87u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FC0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FC8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FC8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF38u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FD4(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1FD4;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F1FD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FD4u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF38u);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FDF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FDFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FE7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FE7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FEF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FEFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FF7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FF7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FFF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F1FFFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2040u);
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2048(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2048u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF6Cu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2054(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2054;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F2054: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2054u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF6Cu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F205F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F205Fu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2067(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2067u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F206F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F206Fu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F20B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F20B0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F20E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F20E0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFDA4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F20ECu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2120u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_effect_items;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2150u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2159u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2180u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F218Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F21C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F21C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFDC8u);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2200u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2230u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F22A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F22A0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2320u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2350u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F235Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2380u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F238Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F23D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F23D0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F23D8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F23D8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2410u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2419u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2480u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F248B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F248Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x30u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2496(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2496u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x40u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24A1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F24A1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x58u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F24D0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24DB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F24DBu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x30u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24E6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F24E6u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x40u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24F1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F24F1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x58u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2520u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2529u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2550u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2580u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F25B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F25B0;
    label_000A8F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A8F90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A8F9Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F25B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F25B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2600u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2608(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2608;
    label_000AA210: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AA210u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AA245u); lift_push32(cpu, r); sfera_sub_004A9AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AA24Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F2608: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2608u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x198u;
    goto label_000AA210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2616(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2616u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x1B0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2624(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2624u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x1C0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2632(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2632u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x1D0u;
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2640u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x208u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F264E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F264Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x224u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F265C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F265Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x288u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F266A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F266A;
    label_000A8F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A8F90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A8F9Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F266A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F266Au);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F26B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F26B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F26B9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F26B9;
    label_000A8F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A8F90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A8F9Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F26B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F26B9u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2700u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2730u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2738(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2738u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x1Cu;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2743(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2743;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F2743: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2743u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x40u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2770u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    sfera_sub_004AE200(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27B0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27BB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27BBu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27C6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27C6u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27D1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27D1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27D9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27D9u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27E4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27E4u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27EF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27EFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27F7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F27F7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2802(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2802u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2840u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2890u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    sfera_sub_004AE200(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F28D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F28D0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2900u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2908(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2908u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2911(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2911;
    label_000AA210: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AA210u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AA245u); lift_push32(cpu, r); sfera_sub_004A9AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AA24Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F2911: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2911u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x198u;
    goto label_000AA210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F291F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F291Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x1B0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F292D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F292Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x1C0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F293B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F293Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x1D0u;
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2949(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2949u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x208u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2957(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2957u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x224u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2965(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2965u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x288u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2990u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2998(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2998u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F29A1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29A3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F29A3u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFACu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F29BB;
    lift_store32(cpu->ebp + 0xFFFFFFACu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFACu)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F29BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F29BBu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F29F0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F29F8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A00u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A0B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A0Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A13(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A13u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A1E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A1Eu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A26u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A2E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A2Eu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A36(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A36u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A3E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A3Eu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A49(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A49u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2A55u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A57(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A57u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2A63u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A65(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A65u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2A71u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A73(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A73u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A7B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A7Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2A87u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A89(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A89u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A91(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A91u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A9C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2A9Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF0Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2AA8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2AE0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AE8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2AE8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x1Cu;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AF3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2AF3u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AFC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2AFC;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F2AFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2AFCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x40u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B07(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B07u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x58u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B30u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEE4u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B3C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2B3C;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F2B3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B3Cu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEE4u);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B47(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B47u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B4F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B4Fu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B5A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B5Au);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B62(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B62u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B6A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B6Au);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B75(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2B75u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2BB0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BB9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2BB9;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F2BB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2BB9u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2BE0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2BEDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2C40u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C48(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2C48;
    label_000AF880: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AF880u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF888u); lift_push32(cpu, r); sfera_sub_004AF470(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF890u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F2C48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2C48u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x2DCu;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2C80u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2C88u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2CB0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2CB9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2CBB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2CBBu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2D10u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2D19u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2D1Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F2D24u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DB0;
    label_000B1320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1320u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1338u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F2DB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2DB0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DE0;
    label_000B1320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1320u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1338u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F2DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2DE0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DF0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DF0;
    label_000B1320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1320u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1338u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F2DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2DF0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E20;
    label_000B1320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1320u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1338u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F2E20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2E20u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E30(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E30;
    label_000B1320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1320u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1338u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F2E30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2E30u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2E80u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2EB0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EE0;
    label_000B1320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1320u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1338u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F2EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2EE0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EE8;
    label_000B1320: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1320u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1338u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F2EE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2EE8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2F10u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F18(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2F18u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2F50u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F58(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2F58u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2F90u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F2FC0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F30A0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30A8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F30A8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F30B1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30B3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F30B3u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F30CB;
    lift_store32(cpu->ebp + 0xFFFFFFC8u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFC8u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F30CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F30CBu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3100u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F3118;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFF0u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F3118: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3118u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3140u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F314C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F314C;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F314C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F314Cu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3157(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3157u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F315F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F315Fu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F31A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F31A0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3250u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3258(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3258u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3261(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3261;
    label_000AF880: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AF880u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF888u); lift_push32(cpu, r); sfera_sub_004AF470(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF890u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3261: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3261u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x198u;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F326F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F326F;
    label_000B3CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3CD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D15u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D1Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F326F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F326Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1B8u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F327D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F327Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1C8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F328B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F328Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1E4u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3299(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3299u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F32C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32C8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F32C8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F32D0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32D8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F32D8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F32E0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF74u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F32ECu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3320u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEE4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F3341;
    lift_store32(cpu->ebp + 0xFFFFFEE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFEE4u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFEE8u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F3341: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3341u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3342(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3342u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3355(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3355u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F335D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F335Du);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33AB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33ABu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33B6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33B6u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33C1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33C1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33CC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33CCu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33D7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33D7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33DF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33DFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33E7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33E7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33EF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33EFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33F7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F33F7u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3402(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3402u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F344B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F344Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3456(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3456u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F345E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F345Eu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3469(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3469u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3474(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3474u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F347C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F347Cu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3487(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3487u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F348F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F348Fu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F349A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F349Au);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34A5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F34A5u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F34E0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34E8;
    label_000AF880: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AF880u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF888u); lift_push32(cpu, r); sfera_sub_004AF470(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF890u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F34E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F34E8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x198u;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34F6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34F6;
    label_000B3CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3CD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D15u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D1Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F34F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F34F6u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x1B8u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3504(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3504u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x1C8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3512(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3512u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x1E4u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3520(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3520;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3520: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3520u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x200u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F352E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F352E;
    label_000161C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161C0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4161C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F352E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F352Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3560u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F356B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F356Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3576(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3576u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3581(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3581u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F358C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F358Cu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3597(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3597u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35A2(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F35A2u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35AD(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F35ADu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F35F0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F35F8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3630u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3638(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3638u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3641(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3641;
    label_000AF880: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AF880u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF888u); lift_push32(cpu, r); sfera_sub_004AF470(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AF890u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3641: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3641u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x198u;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F364F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F364F;
    label_000B3CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3CD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D15u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3D1Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F364F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F364Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1B8u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F365D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F365Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1C8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F366B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F366Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1E4u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3679(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3679u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3682(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3682;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3682: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3682u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x200u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F36B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F36B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F36E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F36E0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F36E9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3710u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3719u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F371B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F371Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3724u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3780u);
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F378E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F378Eu);
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F37C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F37C0u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F37CDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F37D1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F37D1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3800u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F380Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3811(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3811u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3840u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFDA8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F384Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3880u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3889u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F38B0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFD94u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F38BCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F38F0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F38F8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3930u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3938(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3938u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3940u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3970u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F397Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F39A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F39A0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F39ADu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F39B1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F39B1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A23(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3A23u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF54u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F3A44;
    lift_store32(cpu->ebp + 0xFFFFFF54u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFF54u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFF58u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F3A44: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3A44u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3A70u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A7B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3A7Bu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A86(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3A86u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3AC0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3AF0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3B40u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B48(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3B48u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3B54u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B56(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3B56u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3B90u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3BC0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3BC8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3BC8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x19Cu;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3C00u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3C09u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3C30u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3C39u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3C60u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3C68;
    label_000BFB50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFB50u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BFB76;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFB6Bu); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFB73u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BFB76: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFB76u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3C68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3C68u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x1A0u;
    goto label_000BFB50;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3CA0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CA8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3CA8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3CE0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3CEDu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3D10u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3D1Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3D60u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3D6Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D71(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3D71u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3D7Eu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3DA0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3DD0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3DD9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DDB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3DDBu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DE3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3DE3;
    label_000C26D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C26D0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C26F6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C26EBu); lift_push32(cpu, r); sfera_sub_004C24B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C26F3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C26F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C26F6u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3DE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3DE3u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x210u;
    goto label_000C26D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3E10u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3E1Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3E40u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3E49u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3E70u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3ED0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3ED8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3ED8;
    label_000183C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4183C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000183E6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4183DBu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4183E3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000183E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4183E6u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3ED8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3ED8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x198u;
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3F10u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3F1Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F21(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3F21u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3F2Eu); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3F50u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3F5Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3F80u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F3F8Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3FB0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FB8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3FB8;
    label_000183C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4183C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000183E6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4183DBu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4183E3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000183E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4183E6u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F3FB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3FB8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    cpu->ecx += 0x198u;
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FC6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F3FC6u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4000u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4008(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4008u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4040u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4049u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4070u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4078(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4078u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x1B8u;
    sfera_sub_004CF160(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4086(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4086u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x260u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F40B0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F40B9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40BB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F40BBu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F40C4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40C6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F40C6u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F40CFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4120u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4150u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4180u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F41B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41B8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F41B8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x198u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F41F0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F41F8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx += 0x198u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4206(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4206u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F420Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4211(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4211u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F421Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4240u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4249u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F424B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F424Bu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4254u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4280u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4288(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4288u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F42B0u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F42B9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F42E0u);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F42E9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42EB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F42EBu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F42F4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4320u);
    cpu->eax = g_sfera_control_reference_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_control_reference_registry_guard = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4350u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F435B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F435Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x54u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4366(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4366u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x70u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4371(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4371u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xA0u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F437F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F437Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xACu;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F438D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F438Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4396(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4396;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F4396: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4396u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xBCu;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43A4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F43A4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x178u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F43D0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}
