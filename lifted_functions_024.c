#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EB520(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB56Du));
    g_sfera_memory_runtime.lock_initialized = (uint8_t)(1u);
    label_000EB57A:
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB57Fu));
    g_sfera_memory_runtime.lock_held = (uint8_t)(1u);
    { uint64_t l=(uint64_t)(g_sfera_memory_runtime.tracking_initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EB5BE;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, (uintptr_t)"free2: test system not initialized"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0x1E4u);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB5BBu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB5BBu));
    cpu->esp += 8u;
    label_000EB5BE:
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edx = 5u;
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB5D3u)); sfera_sub_004EB1D0(cpu, LIFT_CODE_TOKEN_VA(0x4EB5D3u));
    cpu->esi += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB5E4u)); sfera_sub_004EDDF0(cpu, LIFT_CODE_TOKEN_VA(0x4EB5E4u));
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000EB61A;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, (uintptr_t)"Free of wrong pointer or double free. %s %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0xDBu);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB612u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB612u));
    cpu->esp += 0x14u;
    goto label_000EB868;
    label_000EB61A:
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
    label_000EB657:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EB657;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EB66C;
    label_000EB663:
    if ((uint8_t)(lift_load8(cpu->eax + cpu->edi)) == (uint8_t)(0x5Cu)) goto label_000EB66C;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EB663;
    label_000EB66C:
    cpu->edx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB68Eu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EB68Eu));
    cpu->ecx = (uint32_t)(uintptr_t)"free: MEM CORRUPTED! ";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6A5u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB6A5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6ACu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB6ACu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6B3u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB6B3u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6BAu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB6BAu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6C1u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB6C1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6C8u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB6C8u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6CFu)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EB6CFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB6D6u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB6D6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEB6DDu)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEB6DDu));
    label_000EB6DD:
    if ((uint8_t)(lift_load8(cpu->ebp + 0xBu)) == (uint8_t)(0u)) goto label_000EB789;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->edx + cpu->eax + 4u, 0x61CCC864u);
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = (uint8_t)(1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000EB700:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EB700;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EB719;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EB710:
    if ((uint8_t)(lift_load8(cpu->eax + cpu->edi)) == (uint8_t)(0x5Cu)) goto label_000EB719;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EB710;
    label_000EB719:
    cpu->ecx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB73Bu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EB73Bu));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"free: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB751u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB751u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB758u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB758u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB75Fu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB75Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB766u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB766u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB76Du)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB76Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB774u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB774u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB77Bu)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EB77Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB782u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EB782u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEB789u)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEB789u));
    label_000EB789:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB797u)); sfera_sub_004EDE50(cpu, LIFT_CODE_TOKEN_VA(0x4EB797u));
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EB7C1;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, (uintptr_t)"validate_and_remove_pointer: pointer not in hash"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0xE9u);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB7BEu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB7BEu));
    cpu->esp += 8u;
    label_000EB7C1:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_memory_runtime.tracker_floor)) goto label_000EB7D5;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_floor = (uint32_t)(cpu->ecx);
    label_000EB7D5:
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_memory_runtime.tracker_ceiling)) goto label_000EB7E6;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_ceiling = (uint32_t)(cpu->edx);
    label_000EB7E6:
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EB802;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0x10u, cpu->ecx);
    goto label_000EB80A;
    label_000EB802:
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->eax);
    label_000EB80A:
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EB826;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0xCu, cpu->ecx);
    goto label_000EB82E;
    label_000EB826:
    cpu->eax = lift_load32(cpu->esi + 8u);
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->eax);
    label_000EB82E:
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
    label_000EB868:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x4EB869u));
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEB87Eu));
    label_000EB884:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EB8A0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB8E7u)); sfera_sub_004EB300(cpu, LIFT_CODE_TOKEN_VA(0x4EB8E7u));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000EB8FB:
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 1u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    if ((uint8_t)(g_sfera_memory_runtime.lock_initialized) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000EB91F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB912u));
    g_sfera_memory_runtime.lock_initialized = (uint8_t)(1u);
    label_000EB91F:
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB924u));
    g_sfera_memory_runtime.lock_held = (uint8_t)(1u);
    { uint64_t l=(uint64_t)(g_sfera_memory_runtime.tracking_initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EB95F;
    lift_push32(cpu, 0x1388u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB94Cu)); sfera_sub_004EDD40(cpu, LIFT_CODE_TOKEN_VA(0x4EB94Cu));
    lift_push32(cpu, 0x32u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB958u)); sfera_sub_004EDA60(cpu, LIFT_CODE_TOKEN_VA(0x4EB958u));
    g_sfera_memory_runtime.tracking_initialized = (uint8_t)(1u);
    label_000EB95F:
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->edx = 5u;
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB977u)); sfera_sub_004EB1D0(cpu, LIFT_CODE_TOKEN_VA(0x4EB977u));
    if ((int32_t)(uint32_t)(cpu->edi) > 0) goto label_000EB9A2;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"realloc2: Wrong size value. Size = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0x1FBu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB99Fu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB99Fu));
    cpu->esp += 0xCu;
    label_000EB9A2:
    cpu->esi += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB9B3u)); sfera_sub_004EDDF0(cpu, LIFT_CODE_TOKEN_VA(0x4EB9B3u));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000EB9E5;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"realloc2 with wrong pointer"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0xDEu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB9DDu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB9DDu));
    cpu->esp += 8u;
    goto label_000EBC39;
    label_000EB9E5:
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
    label_000EBA23:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EBA23;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EBA39;
    (void)cpu;
    label_000EBA30:
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) == (uint8_t)(0x5Cu)) goto label_000EBA39;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EBA30;
    label_000EBA39:
    cpu->edx = g_sfera_diagnostic_log_byte;
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA5Eu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EBA5Eu));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"realloc: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA74u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBA74u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA7Bu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBA7Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA82u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBA82u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA89u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBA89u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA90u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBA90u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA97u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBA97u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA9Eu)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EBA9Eu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBAA5u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBAA5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEBAACu)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEBAACu));
    label_000EBAAC:
    if ((uint8_t)(lift_load8(cpu->ebp + 0xFu)) == (uint8_t)(0u)) goto label_000EBB5D;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = cpu->ebx;
    lift_store32(cpu->ecx + cpu->edx + 4u, 0x61CCC864u);
    g_sfera_memory_runtime.diagnostics_dirty = (uint8_t)(1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000EBAD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EBAD0;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EBAE9;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EBAE0:
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) == (uint8_t)(0x5Cu)) goto label_000EBAE9;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EBAE0;
    label_000EBAE9:
    cpu->ecx = g_sfera_diagnostic_log_byte;
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebx + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB0Eu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EBB0Eu));
    cpu->ecx = (uint32_t)(uintptr_t)"realloc: MEM CORRUPTED! ";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB25u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBB25u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB2Cu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBB2Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB33u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBB33u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB3Au)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBB3Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB41u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBB41u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB48u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBB48u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB4Fu)); sfera_sub_004ED390(cpu, LIFT_CODE_TOKEN_VA(0x4EBB4Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB56u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EBB56u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEBB5Du)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEBB5Du));
    label_000EBB5D:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB6Bu)); sfera_sub_004EDE50(cpu, LIFT_CODE_TOKEN_VA(0x4EBB6Bu));
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EBB95;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"validate_and_remove_pointer: pointer not in hash"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0xE9u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB92u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EBB92u));
    cpu->esp += 8u;
    label_000EBB95:
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_memory_runtime.tracker_floor)) goto label_000EBBA6;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_floor = (uint32_t)(cpu->ecx);
    label_000EBBA6:
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_memory_runtime.tracker_ceiling)) goto label_000EBBB7;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_ceiling = (uint32_t)(cpu->edx);
    label_000EBBB7:
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EBBD3;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0x10u, cpu->ecx);
    goto label_000EBBDB;
    label_000EBBD3:
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->eax);
    label_000EBBDB:
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3B9ACA00u)) goto label_000EBBF7;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    lift_store32(cpu->eax + cpu->edx + 0xCu, cpu->ecx);
    goto label_000EBBFF;
    label_000EBBF7:
    cpu->eax = lift_load32(cpu->esi + 8u);
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->eax);
    label_000EBBFF:
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
    label_000EBC39:
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = (uint32_t)(cpu->edi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EBC41u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000EBC77;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"realloc2: Not enough memory. Request size = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0x203u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBC74u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EBC74u));
    cpu->esp += 0xCu;
    label_000EBC77:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi, 0x61CCC864u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_store32(cpu->esi + cpu->edi + 4u, 0x61CCC864u);
    lift_store32(cpu->ebp + 0xCu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBC9Bu)); sfera_sub_004EDEF0(cpu, LIFT_CODE_TOKEN_VA(0x4EBC9Bu));
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000EBCC7;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, (uintptr_t)"store_pointer: pointer already in hash"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, (uintptr_t)"Memory\\MemoryMgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 0xFEu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBCC4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EBCC4u));
    cpu->esp += 8u;
    label_000EBCC7:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBCD2u)); sfera_sub_004EDC70(cpu, LIFT_CODE_TOKEN_VA(0x4EBCD2u));
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = cpu->eax & 0xFFFFu;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0x3B9ACA00u)) goto label_000EBCFB;
    cpu->ebx = g_sfera_allocation_hash_runtime.records;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1Au);
    lift_store32(cpu->edx + cpu->ebx + 0xCu, cpu->edi);
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    goto label_000EBD01;
    label_000EBCFB:
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->edi);
    label_000EBD01:
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
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBD5Cu));
    cpu->eax = (uint32_t)(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBD80(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBDBAu));
    g_sfera_memory_runtime.lock_initialized = (uint8_t)(1u);
    label_000EBDC7:
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::TryEnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBDCCu));
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EBE07;
    if ((uint8_t)(g_sfera_memory_runtime.lock_held) != (uint8_t)(0u)) goto label_000EBDFC;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"verify before terminate"); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEBDFCu)); sfera_sub_004EAA20(cpu, LIFT_CODE_TOKEN_RVA(0xEBDFCu));
    label_000EBDFC:
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEBE01u));
    label_000EBE07:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000EBE4F;
    cpu->eax = g_sfera_memory_runtime.allocation_source_line;
    cpu->edx = g_sfera_memory_runtime.allocation_source_file;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBE3Bu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4EBE3Bu));
    g_sfera_memory_runtime.allocation_source_file = (uint32_t)(((uint32_t)(uintptr_t)"Unknown"));
    g_sfera_memory_runtime.allocation_source_line = (uint32_t)(0u);
    label_000EBE4F:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBE6Fu)); sfera_sub_004EB300(cpu, LIFT_CODE_TOKEN_VA(0x4EBE6Fu));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBE92u)); sfera_sub_004EB8A0(cpu, LIFT_CODE_TOKEN_VA(0x4EBE92u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBEA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = g_sfera_memory_runtime.allocation_source_line;
    cpu->ecx = g_sfera_memory_runtime.allocation_source_file;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBEBEu)); sfera_sub_004EB300(cpu, LIFT_CODE_TOKEN_VA(0x4EBEBEu));
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EBEC4u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    g_sfera_memory_runtime.allocation_source_file = (uint32_t)(((uint32_t)(uintptr_t)"Unknown"));
    g_sfera_memory_runtime.allocation_source_line = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->edx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"%d ");
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EBF03u));
    cpu->esp += 0x10u;
    lift_store8(cpu->edi + cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF20(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_critical_diagnostics_runtime.stack_dump_callback = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::printf), LIFT_CODE_TOKEN_VA(0x4EBF31u));
    cpu->esp += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = 0x1204u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBF4Du)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x4EBF4Du));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x14u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFEE0Cu);
    lift_store32(cpu->ebp + 0xFFFFEDFCu, (uintptr_t)"stackdump.cpp");
    lift_store32(cpu->ebp + 0xFFFFEE00u, (uintptr_t)"errorsmgr.cpp");
    lift_store32(cpu->ebp + 0xFFFFEE04u, (uintptr_t)"crt0.c");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBF86u)); sfera_sub_004EE2C0(cpu, LIFT_CODE_TOKEN_VA(0x4EBF86u));
    lift_store8(cpu->ebp + 0xFFFFF6CCu, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000EC06D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->ebp + 0xFFFFEE30u);
    lift_store32(cpu->ebp + 0xFFFFEE08u, cpu->eax);
    label_000EBFA4:
    cpu->esi = 0u;
    cpu->edi = (uint32_t)(cpu->ebx + 0xFFFFFFDCu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EBFB0:
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(cpu->esi) * 4u) + 0xFFFFEDFCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4EBFB9u));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EBFCE;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(3u)) goto label_000EBFB0;
    goto label_000EBFD3;
    label_000EBFCE:
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(3u)) goto label_000EC026;
    label_000EBFD3:
    cpu->ecx = lift_load32(cpu->ebx + 0x48u);
    cpu->edx = lift_load32(cpu->ebx + 0x44u);
    cpu->eax = lift_load32(cpu->ebx + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"(%s:%u)\t(%hs+%I64X)\n");
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, 0x6Fu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EBFECu));
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF8Cu);
    cpu->esp += 0x20u;
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    cpu->esi = cpu->eax;
    cpu->edi = cpu->edi;
    label_000EC000:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC000;
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFF6CCu);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000EC010:
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
    label_000EC026:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC05Fu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EC05Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC066u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EC066u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC06Du)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEC06Du));
    label_000EC06D:
    cpu->eax = g_sfera_critical_diagnostics_runtime.stack_dump_callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EC07D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xEC07Du), LIFT_CODE_TOKEN_RVA(0xEC07Bu))) { return; }
    label_000EC07D:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC090(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"critLogTmp.$$$"); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0ADu));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC1A6;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x8000u); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0C9u));
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFFu)) goto label_000EC0ED;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0DFu));
    cpu->esp += 8u;
    goto label_000EC1A6;
    label_000EC0ED:
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0F8u));
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000EC11F;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4EC10Au));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC116u));
    cpu->esp += 0xCu;
    label_000EC11F:
    cpu->eax = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC126u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4EC126u));
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000EC189;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = 0u - (uint64_t)(cpu->edi);
    cpu->edi = cpu->edi;
    label_000EC140:
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4EC144u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000EC189;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4EC158u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EC189;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4EC16Eu));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EC189;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    ++cpu->eax;
    cpu->edi += cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_000EC140;
    label_000EC189:
    cpu->esi = native_function_address32(&::_close);
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xEC192u), LIFT_CODE_TOKEN_RVA(0xEC190u))) { return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xEC198u), LIFT_CODE_TOKEN_RVA(0xEC196u))) { return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4EC19Du));
    cpu->esp += 0xCu;
    label_000EC1A6:
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC1C0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_memory_runtime.critical_error_callback = (uint32_t)(cpu->ecx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000EC1D4;
    g_sfera_memory_runtime.critical_error_callback = LIFT_FUNCTION(sfera_sub_004EBF30);
    label_000EC1D4:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC1E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = (uint32_t)(uintptr_t)"Criticals.log";
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    lift_store32(cpu->ebp + 0xFFFFFFC8u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC202u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000EC2CC;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::fputs);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000EC273;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC224u));
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC22Eu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC240u));
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC258u));
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC269u), LIFT_CODE_TOKEN_RVA(0xEC267u))) { return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC270u), LIFT_CODE_TOKEN_RVA(0xEC26Eu))) { return; }
    cpu->esp += 0x38u;
    label_000EC273:
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC27Au), LIFT_CODE_TOKEN_RVA(0xEC278u))) { return; }
    cpu->esp += 8u;
    if ((uint8_t)(lift_load8(cpu->ebp + 8u)) == (uint8_t)(0u)) goto label_000EC28E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC28Bu), LIFT_CODE_TOKEN_RVA(0xEC289u))) { return; }
    cpu->esp += 8u;
    label_000EC28E:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4EC28Fu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4EC296u));
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4EC29Fu));
    cpu->esp += 0xCu;
    if ((uint8_t)(lift_load8(cpu->ebp + 0xCu)) == (uint8_t)(0u)) goto label_000EC2CB;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(0x108000u)) goto label_000EC2CB;
    cpu->ecx = (uint32_t)(uintptr_t)"Criticals.log";
    lift_push32(cpu, 0x200u);
    cpu->edx = 0x800u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC2CBu)); sfera_sub_004EC090(cpu, LIFT_CODE_TOKEN_RVA(0xEC2CBu));
    label_000EC2CB:
    cpu->edi = lift_pop32(cpu);
    label_000EC2CC:
    cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC2E0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC322u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000EC3BC;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7C4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC33Cu));
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFF7C4u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC349u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC35Bu));
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC373u));
    cpu->edi = native_function_address32(&::fputs);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC38Au), LIFT_CODE_TOKEN_RVA(0xEC388u))) { return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC391u), LIFT_CODE_TOKEN_RVA(0xEC38Fu))) { return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Error processing reenter. Terminating");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC399u), LIFT_CODE_TOKEN_RVA(0xEC397u))) { return; }
    cpu->esp += 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEC3A4u), LIFT_CODE_TOKEN_RVA(0xEC3A2u))) { return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4EC3A5u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4EC3ACu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4EC3B3u));
    cpu->esp += 0x14u;
    label_000EC3BC:
    cpu->esi = 1u;
    label_000EC3C1:
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EC3C3u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_RVA(0xEC3CAu));
    label_000EC3D0:
    cpu->eax = g_sfera_critical_diagnostics_runtime.serial_number;
    cpu->eax += cpu->esi;
    g_sfera_critical_diagnostics_runtime.serial_number = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3E8u)) goto label_000EC3ED;
    g_sfera_critical_diagnostics_runtime.serial_number = (uint32_t)(0u);
    label_000EC3ED:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x4EC401u));
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    cpu->esp += 0x10u;
    lift_store8(cpu->ebp + 0xFFFFFFCBu, 0u);
    --cpu->edi;
    label_000EC415:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC451u)); sfera_sub_004EC1E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC451u));
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC466u)); sfera_sub_004ED100(cpu, LIFT_CODE_TOKEN_VA(0x4EC466u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC46Du)); sfera_sub_004EBF40(cpu, LIFT_CODE_TOKEN_VA(0x4EC46Du));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_memory_runtime.critical_error_callback), LIFT_CODE_TOKEN_RVA(0xEC47Bu), LIFT_CODE_TOKEN_RVA(0xEC475u))) { return; }
    goto label_000EC4B9;
    label_000EC47D:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC492u)); sfera_sub_004ED100(cpu, LIFT_CODE_TOKEN_VA(0x4EC492u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC499u)); sfera_sub_004EBF40(cpu, LIFT_CODE_TOKEN_VA(0x4EC499u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_memory_runtime.critical_error_callback), LIFT_CODE_TOKEN_RVA(0xEC4A7u), LIFT_CODE_TOKEN_RVA(0xEC4A1u))) { return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC4E9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"terminating cause of LERROR";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC4B9u)); sfera_sub_004EC1E0(cpu, LIFT_CODE_TOKEN_RVA(0xEC4B9u));
    label_000EC4B9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC4BEu)); sfera_sub_004EBD80(cpu, LIFT_CODE_TOKEN_VA(0x4EC4BEu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC4C3u)); sfera_sub_004ED150(cpu, LIFT_CODE_TOKEN_VA(0x4EC4C3u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EC4C5u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_VA(0x4EC4CCu));
    goto label_000EC4E9;
    label_000EC4D4:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFF7CCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_warnings_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC4E9u)); sfera_sub_004ED100(cpu, LIFT_CODE_TOKEN_RVA(0xEC4E9u));
    label_000EC4E9:
    lift_store32((uint32_t)(uintptr_t)&g_sfera_critical_diagnostics_runtime.processing_depth, (uint64_t)(g_sfera_critical_diagnostics_runtime.processing_depth) - (uint64_t)(cpu->esi) - (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC500(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC547u)); sfera_sub_004EE390(cpu, LIFT_CODE_TOKEN_VA(0x4EC547u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC580u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC580u));
    cpu->esp += 0xCu;
    label_000EC583:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC590:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC590;
    cpu->ebx = native_function_address32(&::malloc);
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC5A5u), LIFT_CODE_TOKEN_RVA(0xEC5A3u))) { return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC5D6;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x23u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC5D3u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC5D3u));
    cpu->esp += 0xCu;
    label_000EC5D6:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC5E0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC5E0;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC5F6;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    goto label_000EC650;
    label_000EC5F6:
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC600:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC600;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC60Fu), LIFT_CODE_TOKEN_RVA(0xEC60Du))) { return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC640;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x2Du);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC63Du)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC63Du));
    cpu->esp += 0xCu;
    label_000EC640:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    label_000EC646:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC646;
    label_000EC650:
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
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC6A3;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x38u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC6A0u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC6A0u));
    cpu->esp += 0xCu;
    label_000EC6A3:
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->eax = 0u;
    lift_store8(cpu->edx, 0u);
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) > (int32_t)(uint32_t)(cpu->eax)) goto label_000EC6BB;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    goto label_000EC6F7;
    label_000EC6BB:
    lift_push32(cpu, 0x2000u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC6C2u), LIFT_CODE_TOKEN_RVA(0xEC6C0u))) { return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC6F7;
    lift_push32(cpu, 0x2000u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x43u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC6F4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC6F4u));
    cpu->esp += 0xCu;
    label_000EC6F7:
    if ((uint8_t)((lift_load8(cpu->ebp + 0x10u)) & (8u)) == 0u) goto label_000EC73A;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEC703u), LIFT_CODE_TOKEN_RVA(0xEC701u))) { return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC734;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\Log.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x4Bu);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC731u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC731u));
    cpu->esp += 0xCu;
    label_000EC734:
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    lift_store8(cpu->edx, 0u);
    label_000EC73A:
    lift_store32(cpu->esi, 0u);
    cpu->eax = g_sfera_critical_diagnostics_runtime.log_chain_head;
    lift_store32(cpu->esi + 4u, cpu->eax);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EC757;
    lift_store32(cpu->eax, cpu->esi);
    label_000EC757:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->esp -= 0x10u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC780:
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
    label_000EC7A0:
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
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EC7BFu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC7F7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC7F7u));
    cpu->esp += 0xCu;
    label_000EC7FA:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4EC807u));
    cpu->ecx = lift_load32(cpu->edi);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->ecx + cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC830(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EC850:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC850;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->eax = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC863u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4EC863u));
    cpu->esi = cpu->esp;
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->esi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EC870:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000EC870;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + cpu->edi + 0xFFFFFFFEu, 0x24u);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x4EC885u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4EC88Cu));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC89Au));
    cpu->esp += 0x14u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC8DBu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC8E5u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"_%y%m%d");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC8F7u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->esp += 0x18u;
    cpu->edx = 0u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_000EC923;
    label_000EC910:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000EC923;
    lift_store8(cpu->edi, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + cpu->ecx + 1u)) & 0xFFu);
    ++cpu->edx;
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Eu)) goto label_000EC910;
    label_000EC923:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->ebx = cpu->edi;
    cpu->ecx = cpu->eax;
    cpu->ebx -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000EC930:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->ebx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC930;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_000EC942:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000EC942;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_000EC950:
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x84u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EC9BC;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000EC9A3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EC9A3;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EC9BC:
    cpu->edx = 0x80u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_store8(cpu->ebp + 0xFFFFFF7Cu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xEC9D0u), LIFT_CODE_TOKEN_RVA(0xEC9CEu))) { return; }
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC9E6u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4EC9E6u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECA00(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000ECA30:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4ECA37u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECA73;
    cpu->edx = lift_load32(cpu->edi + 0x18u);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4ECA4Fu));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECA73;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4ECA6Au));
    cpu->esp += 0xCu;
    label_000ECA73:
    lift_store32(cpu->ebp + 0xCu, (uint64_t)(lift_load32(cpu->ebp + 0xCu)) + (uint64_t)(0x2000u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xFFFFFFFCu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ECA30;
    label_000ECA7F:
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80001FFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000ECA90;
    --cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFE000u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    label_000ECA90:
    lift_store32(cpu->ebp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ECAD6;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(0xDu), 32u);
    cpu->esi += lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4ECA9Fu));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECAD6;
    cpu->esi = lift_load32(cpu->ebp + 0x14u);
    cpu->edx = lift_load32(cpu->edi + 0x18u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4ECAB6u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECAD6;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4ECACDu));
    cpu->esp += 0xCu;
    label_000ECAD6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECAE0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000ECB01:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECB01;
    cpu->eax -= cpu->edx;
    cpu->eax += 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECB12u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4ECB12u));
    cpu->edi = cpu->esp;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xECB1Cu)); sfera_sub_004EC8C0(cpu, LIFT_CODE_TOKEN_RVA(0xECB1Cu));
    label_000ECB1C:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4ECB22u));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000ECB93;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4ECB36u));
    cpu->esp += 8u;
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (4u)) == 0u) goto label_000ECB4F;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4ECB46u));
    cpu->esp += 4u;
    label_000ECB4F:
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u)) <= (int32_t)(uint32_t)(0u)) goto label_000ECB89;
    lift_store32(cpu->esi + 0x1Cu, (uint64_t)(lift_load32(cpu->esi + 0x1Cu)) + 1u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (int32_t)(uint32_t)(0x1F4u)) goto label_000ECB89;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, 0u);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4ECB69u));
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4ECB72u));
    cpu->esp += 8u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_000ECB93;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECB87u)); sfera_sub_004EC830(cpu, LIFT_CODE_TOKEN_VA(0x4ECB87u));
    goto label_000ECB93;
    label_000ECB89:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4ECB8Au));
    cpu->esp += 4u;
    label_000ECB93:
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECBB0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000ECBD5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECBD5;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->eax = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECBEBu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4ECBEBu));
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ebx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->ebx);
    cpu->edx = cpu->ebx;
    label_000ECBF5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000ECBF5;
    lift_push32(cpu, 0u);
    lift_store8(cpu->ebx + cpu->edi + 0xFFFFFFFEu, 0x24u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECC0Fu));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECC24;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    goto label_000ECC3E;
    label_000ECC24:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x4ECC25u));
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECC2Fu));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    label_000ECC3E:
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECC46u));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECC5B;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    goto label_000ECC7A;
    label_000ECC5B:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x4ECC5Cu));
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECC66u));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECC91;
    label_000ECC7A:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECE61;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_000ECE61;
    goto label_000ECC94;
    label_000ECC91:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    label_000ECC94:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECCA9;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECC9Eu));
    goto label_000ECE5E;
    label_000ECCA9:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECCB1u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4ECCB1u));
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ebx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    cpu->edx = cpu->ebx;
    label_000ECCC0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000ECCC0;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_store16(cpu->ebx + cpu->eax + 0xFFFFFFFDu, 0x2424u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECCD9u));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ECE61;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECCF8u));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECD34;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECD0Cu));
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECD17u));
    cpu->esp += 0xCu;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ECD34:
    cpu->ebx |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)) == (uint32_t)(cpu->ebx)) goto label_000ECD8D;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECD47u));
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECD8D;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECD58u));
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECD62u));
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECD70u));
    cpu->esp += 0x10u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ECD8D:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECD98u));
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000ECDE4;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_close);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xECDB2u), LIFT_CODE_TOKEN_RVA(0xECDB0u))) { return; }
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xECDB5u), LIFT_CODE_TOKEN_RVA(0xECDB3u))) { return; }
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECDB9u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECDC7u));
    cpu->esp += 0x14u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ECDE4:
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000ECDF4;
    lift_push32(cpu, cpu->ecx);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    goto label_000ECE29;
    label_000ECDF4:
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
    label_000ECE14:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    label_000ECE17:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECE20u)); sfera_sub_004ECA00(cpu, LIFT_CODE_TOKEN_VA(0x4ECE20u));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    label_000ECE26:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    label_000ECE29:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECE32u)); sfera_sub_004ECA00(cpu, LIFT_CODE_TOKEN_VA(0x4ECE32u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_close);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xECE3Bu), LIFT_CODE_TOKEN_RVA(0xECE39u))) { return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xECE41u), LIFT_CODE_TOKEN_RVA(0xECE3Fu))) { return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = native_function_address32(&::remove);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xECE4Du), LIFT_CODE_TOKEN_RVA(0xECE4Bu))) { return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_000ECE61;
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xECE58u), LIFT_CODE_TOKEN_RVA(0xECE56u))) { return; }
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xECE5Eu), LIFT_CODE_TOKEN_RVA(0xECE5Cu))) { return; }
    label_000ECE5E:
    cpu->esp += 8u;
    label_000ECE61:
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECE80(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000ECEB6:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"[%d] ");
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4ECEC2u));
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->esp += 0x10u;
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000ECED5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECED5;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000ECEE6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECEE6;
    cpu->eax -= cpu->esi;
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECEF8u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4ECEF8u));
    cpu->ebx = cpu->esp;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    cpu->edx -= cpu->ecx;
    label_000ECF03:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECF03;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->edx = cpu->eax;
    label_000ECF12:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000ECF12;
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    cpu->edi = cpu->edi;
    label_000ECF20:
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
    label_000ECF3C:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xECF41u)); sfera_sub_004ECAE0(cpu, LIFT_CODE_TOKEN_RVA(0xECF41u));
    label_000ECF41:
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECF60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_000ECFD5;
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) != 0u) goto label_000ECF79;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF77u)); sfera_sub_004ECAE0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF77u));
    goto label_000ECFC3;
    label_000ECF79:
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF86u)); sfera_sub_004EE5D0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF86u));
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000ECFC2;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF92u)); sfera_sub_004EE4C0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF92u));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000ECFA6;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF9Eu)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF9Eu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xECFA6u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_RVA(0xECFA6u));
    label_000ECFA6:
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECFB6u)); sfera_sub_004EE690(cpu, LIFT_CODE_TOKEN_VA(0x4ECFB6u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ECFC2;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xECFC2u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_RVA(0xECFC2u));
    label_000ECFC2:
    cpu->edi = lift_pop32(cpu);
    label_000ECFC3:
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_store8(cpu->eax, 0u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ECFD5;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_store8(cpu->ecx, 0u);
    label_000ECFD5:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECFE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) != (uint32_t)(0u)) goto label_000ED00D;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED00D:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = cpu->edi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED0DB;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000ED020:
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0x24u)) goto label_000ED0D1;
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = (uint32_t)(cpu->esi + 0x28u);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->edi, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED03Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED03Cu));
    lift_store8(cpu->edi, 0x24u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000ED0EB;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x64u)) goto label_000ED08F;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED053u));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED05Du));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED06Fu));
    cpu->esp += 0x18u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED088u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED088u));
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED08F:
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x74u)) goto label_000ED0B8;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED098u));
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED0B1u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED0B1u));
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED0B8:
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x75u)) goto label_000ED0CA;
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) == (uint32_t)(0u)) goto label_000ED0CA;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED0CAu)); sfera_sub_004EC980(cpu, LIFT_CODE_TOKEN_RVA(0xED0CAu));
    label_000ED0CA:
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED0D1:
    ++cpu->edi;
    label_000ED0D2:
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0u)) goto label_000ED020;
    label_000ED0DB:
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED0EBu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED0EBu));
    label_000ED0EB:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED100(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED10Bu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED10Bu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED112u)); sfera_sub_004ECFE0(cpu, LIFT_CODE_TOKEN_VA(0x4ED112u));
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED125u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED125u));
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED13E;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED13Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED13Eu));
    label_000ED13E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED145u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED145u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_critical_diagnostics_runtime.log_chain_head;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000ED196;
    lift_push32(cpu, cpu->edi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000ED160:
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED18E;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED16Eu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED16Eu));
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED18E;
    label_000ED172:
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED17Au)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED17Au));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED182u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED182u));
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED18Au)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED18Au));
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED172;
    label_000ED18E:
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000ED160;
    cpu->edi = lift_pop32(cpu);
    label_000ED196:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED380(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED385u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED385u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED390(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED3B4u)); sfera_sub_004ECFE0(cpu, LIFT_CODE_TOKEN_RVA(0xED3B4u));
    label_000ED3B4:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4ED3C3u));
    cpu->esp += 0x10u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->ebp + 0xFFFFFFFBu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED3E0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED3E0u));
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x800u)) goto label_000ED3EE;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED3EEu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED3EEu));
    label_000ED3EE:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED410(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000ED427;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED427u)); sfera_sub_004ECFE0(cpu, LIFT_CODE_TOKEN_RVA(0xED427u));
    label_000ED427:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED438u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED438u));
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x10u)), r=(uint64_t)(8u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED450;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED450u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED450u));
    label_000ED450:
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(0x800u)) goto label_000ED460;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED460u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED460u));
    label_000ED460:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    label_000ED474:
    cpu->eax = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED48A;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    label_000ED48A:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED49F;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4A1;
    label_000ED49F:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4A1:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4B6;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4B8;
    label_000ED4B6:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4B8:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4CD;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4CF;
    label_000ED4CD:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4CF:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4E4;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4E6;
    label_000ED4E4:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4E6:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED4FB;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED4FD;
    label_000ED4FB:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED4FD:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000ED512;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000ED514;
    label_000ED512:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000ED514:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000ED520;
    cpu->ecx ^= 0xEDB88320u;
    label_000ED520:
    g_sfera_string_lookup_runtime.hash_mix[(uint8_t)cpu->edx] = (uint16_t)(cpu->ecx & 0xFFFFu);
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000ED474;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED5C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000ED5C0;
    label_000ED540:
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
    label_000ED580:
    g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax] = (uint8_t)(cpu->eax & 0xFFu);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_000ED580;
    cpu->eax = 0u;
    label_000ED590:
    cpu->ecx = lift_load8(cpu->ebp + cpu->eax + 0xFFFFFFE0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + cpu->eax + 0xFFFFFFC4u)) & 0xFFu);
    ++cpu->eax;
    g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx] = (uint8_t)(cpu->edx & 0xFFu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x1Bu)) goto label_000ED590;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED5C0:
    if ((uint32_t)(g_sfera_string_lookup_runtime.initialized) != (uint32_t)(0u)) goto label_000ED5DD;
    g_sfera_string_lookup_runtime.initialized = (uint32_t)(1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED5D8u)); sfera_sub_004ED470(cpu, LIFT_CODE_TOKEN_VA(0x4ED5D8u));
    goto label_000ED540;
    label_000ED5DD:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED5E0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED60Au)); sfera_sub_004013B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED60Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED610u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED610u));
    cpu->esp += 0x10u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED631u)); sfera_sub_004ED5C0(cpu, LIFT_CODE_TOKEN_VA(0x4ED631u));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFFFFu, cpu->edx & 0xFFu);
    cpu->eax = (int8_t)(lift_load8(cpu->ebp + 0xFFFFFFFFu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x4ED644u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED6ED;
    cpu->ecx = (int8_t)(lift_load8(cpu->ebp + 0xFFFFFFFFu));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx]) & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFFFFu, cpu->edx & 0xFFu);
    goto label_000ED66D;
    label_000ED664:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    label_000ED66D:
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
    label_000ED6A0:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->ecx);
    label_000ED6B2:
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ED6C4;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    goto label_000ED76B;
    label_000ED6C4:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = (int8_t)(lift_load8(cpu->ecx));
    cpu->eax = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = (int8_t)(lift_load8(cpu->ecx));
    cpu->ecx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000ED6E4;
    goto label_000ED6E6;
    label_000ED6E4:
    goto label_000ED6A0;
    label_000ED6E6:
    goto label_000ED664;
    label_000ED6EB:
    goto label_000ED769;
    label_000ED6ED:
    goto label_000ED6F8;
    label_000ED6EF:
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->edx);
    label_000ED6F8:
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
    label_000ED724:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx += 1u;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edx);
    label_000ED736:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000ED745;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    goto label_000ED76B;
    label_000ED745:
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    cpu->ecx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax]);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    cpu->edx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax]);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000ED765;
    goto label_000ED767;
    label_000ED765:
    goto label_000ED724;
    label_000ED767:
    goto label_000ED6EF;
    label_000ED769:
    cpu->eax = 0u;
    label_000ED76B:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x17u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED785u)); sfera_sub_004EB300(cpu, LIFT_CODE_TOKEN_VA(0x4ED785u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED790(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED7A9u)); sfera_sub_004EB8A0(cpu, LIFT_CODE_TOKEN_VA(0x4ED7A9u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x21u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED7C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4ED7C2u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED7E1;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000ED7E1;
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED7E1:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7F0(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED808:
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"FileMap::size: open file %s error"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x75u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED82Bu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED82Bu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED834:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, (uintptr_t)"FileMap::size: file is not opened"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0x72u);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED853u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED853u));
    cpu->esp += 8u;
    cpu->eax = 0u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED860(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED87A:
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"FileMap::get_ptr: file is not opened"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x85u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED89Du)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED89Du));
    cpu->esp += 8u;
    label_000ED8A0:
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, (uintptr_t)"FileMap::get_ptr: open file %s error"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0x87u);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED8C7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED8C7u));
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED8E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED92B;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000ED92B;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x4ED8F5u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ED925;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"Error unmappnig file %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x63u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED922u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED922u));
    cpu->esp += 0xCu;
    label_000ED925:
    lift_store32(cpu->esi, 0u);
    label_000ED92B:
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED930(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x4ED946u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000ED976;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"Error unmappnig file %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Files\\FileMap.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x63u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED973u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED973u));
    cpu->esp += 0xCu;
    label_000ED976:
    lift_store32(cpu->esi, 0u);
    label_000ED97C:
    cpu->edi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0x20u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED988u)); sfera_sub_004EE7D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED988u));
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4ED98Du));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esi + 0x27u, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4ED9ADu));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000ED9CA;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000ED9CA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetFileSize), LIFT_CODE_TOKEN_VA(0x4ED9CEu));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x4ED9E2u));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_000EDA11;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::CloseHandle);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED9F8u), LIFT_CODE_TOKEN_RVA(0xED9F6u))) { return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x4EDA01u));
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xEDA0Cu), LIFT_CODE_TOKEN_RVA(0xEDA0Au))) { return; }
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(0u)) goto label_000EDA22;
    label_000EDA11:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDA22:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDA30(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDA49u)); sfera_sub_004ED930(cpu, LIFT_CODE_TOKEN_VA(0x4EDA49u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDA60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4EDA76u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EDAAB;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"CHash8Mem: init error"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Memory\\hash8mem.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDAA8u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDAA8u));
    cpu->esp += 8u;
    label_000EDAAB:
    lift_push32(cpu, 0x800u);
    cpu->edx = (uint32_t)(cpu->esi + 0xAu);
    cpu->ecx = 0u;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->edx);
    lift_store16(cpu->esi + 8u, cpu->ecx & 0xFFFFu);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EDAC2u));
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000EDAEB;
    label_000EDAD3:
    cpu->edi = lift_load32(cpu->esi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store16(cpu->edi + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 8u), 0u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000EDAD3;
    label_000EDAEB:
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = 0xFFFFu;
    lift_store16(cpu->ebx + cpu->eax + 0xFFFFFFFCu, cpu->ecx & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + cpu->edx + 0xFFFFFFF8u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDB10(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDB53u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDB53u));
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000EDB56:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x32u)) goto label_000EDB71;
    cpu->edi = 0x32u;
    label_000EDB71:
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)((cpu->ecx & 0xFFFFu)) & 0xFFFFu);
    lift_store16(cpu->esi + 8u, cpu->edx & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFFFu)) goto label_000EDB95;
    cpu->ecx = 0xFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    lift_store32(cpu->esi + 4u, 0xFFFFu);
    label_000EDB95:
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EDBA2u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDBDAu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDBDAu));
    cpu->esp += 0xCu;
    label_000EDBDD:
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000EDC0E;
    label_000EDBE6:
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
    label_000EDC0E:
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
    label_000EDC32:
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDC70(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EDCA6:
    cpu->edx = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_000EDCCD;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 8u));
    cpu->esi = cpu->eax & 0xFFFFu;
    cpu->eax = lift_load16(cpu->edx + 4u);
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->edi)) goto label_000EDCA6;
    label_000EDCC1:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi & 0xFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDCCD:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000EDCD0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDCD7u)); sfera_sub_004EDB10(cpu, LIFT_CODE_TOKEN_VA(0x4EDCD7u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDCE0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EDD07:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000EDD07;
    cpu->eax -= cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EDD1C;
    label_000EDD13:
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->eax)) == (uint8_t)(0x5Cu)) goto label_000EDD1C;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EDD13;
    label_000EDD1C:
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EDD26u));
    cpu->esp += 0xCu;
    lift_store8(cpu->edi + cpu->esi + 0xFFFFFFFFu, 0u);
    cpu->esi = lift_pop32(cpu);
    label_000EDD35:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDD40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = cpu->edi;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4EDD54u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EDD89;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, (uintptr_t)"CHash32Mem: init. Not enough memory"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, (uintptr_t)"Memory\\hash32mem.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0xBu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDD86u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDD86u));
    cpu->esp += 8u;
    label_000EDD89:
    lift_push32(cpu, 0x40000u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EDDA1u));
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000EDDD4;
    cpu->ecx = 0u;
    label_000EDDB4:
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDDD4:
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + cpu->eax + 0xFFFFFFE6u, 0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDDF0(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDE0F:
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = lift_load32(cpu->ecx + cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ecx + cpu->esi + 4u)) == (uint32_t)(cpu->edi)) goto label_000EDE3E;
    label_000EDE20:
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFFFFFu)) goto label_000EDE3B;
    cpu->ecx = cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ecx + cpu->esi + 4u)) != (uint32_t)(cpu->edi)) goto label_000EDE20;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDE3B:
    cpu->eax |= 0xFFFFFFFFu;
    label_000EDE3E:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDE50(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDE7C:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + cpu->edi);
    cpu->eax += cpu->edi;
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) == (uint32_t)(cpu->ebx)) goto label_000EDEC6;
    cpu->edi = cpu->edi;
    label_000EDE90:
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDEC3:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000EDEC6:
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDEDE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDEF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDF03u)); sfera_sub_004EDDF0(cpu, LIFT_CODE_TOKEN_VA(0x4EDF03u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000EDF13;
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000EDF13:
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
    label_000EDF39:
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EDF4Au));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDF83u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDF83u));
    cpu->esp += 0xCu;
    label_000EDF86:
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000EDFAB;
    (void)cpu;
    label_000EDF90:
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
    label_000EDFAB:
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax += cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_store32(cpu->eax + cpu->ecx + 0xFFFFFFE6u, 0xFFFFFFFFu);
    label_000EDFBD:
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
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x534u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFAECu, cpu->edx);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFAF0u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE027u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, 0xA4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFAF4u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE043u));
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
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE0A9u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE0B6u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE2A4;
    cpu->esi += 0x68u;
    label_000EE0D0:
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
    lift_native_call(cpu, native_function_address32(&::SymGetLineFromAddr), LIFT_CODE_TOKEN_VA(0x4EE13Bu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE1AD;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFADCu);
    cpu->eax = cpu->edx;
    lift_store8(cpu->ebp + 0xFFFFFAFFu, 1u);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000EE157:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EE157;
    cpu->eax -= cpu->edi;
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000EE179;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE170:
    if ((uint8_t)(lift_load8(cpu->eax + cpu->edx)) == (uint8_t)(0x5Cu)) goto label_000EE179;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EE170;
    label_000EE179:
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x1Fu)) goto label_000EE18C;
    cpu->edi = 0x1Fu;
    goto label_000EE190;
    label_000EE18C:
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000EE1AD;
    label_000EE190:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFAD8u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->eax + cpu->edx + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0xFFFFFFB8u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE1A0u));
    cpu->esp += 0xCu;
    lift_store8(cpu->ebx + cpu->edi, 0u);
    label_000EE1AD:
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
    lift_native_call(cpu, native_function_address32(&::SymFromAddr), LIFT_CODE_TOKEN_VA(0x4EE1ECu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE243;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFBF8u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000EE200:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000EE200;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x3Fu)) goto label_000EE217;
    cpu->edi = 0x3Fu;
    goto label_000EE21B;
    label_000EE217:
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000EE24C;
    label_000EE21B:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFAE4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBF8u);
    lift_store32(cpu->esi, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE233u));
    cpu->esp += 0xCu;
    lift_store8(cpu->ebx + cpu->edi + 0x24u, 0u);
    goto label_000EE24C;
    label_000EE243:
    if ((uint8_t)(lift_load8(cpu->ebp + 0xFFFFFAFFu)) == (uint8_t)(0u)) goto label_000EE26A;
    label_000EE24C:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFAF8u);
    ++cpu->eax;
    cpu->esi += 0x70u;
    lift_store32(cpu->ebp + 0xFFFFFAF8u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFAECu))) goto label_000EE2AA;
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFAF4u);
    label_000EE26A:
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFAF0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE289u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE296u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE0D0;
    label_000EE2A4:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFAF8u);
    label_000EE2AA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE2C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2ECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFD14u, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFD18u, cpu->ecx);
    lift_push32(cpu, 4u);
    lift_native_call(cpu, native_function_address32(&::SymSetOptions), LIFT_CODE_TOKEN_VA(0x4EE2E3u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE2EDu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4EE2F4u));
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000EE315;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    cpu->ecx = 0xB3u;
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFD28u);
    lift_movs32(cpu, 1u);
    goto label_000EE366;
    label_000EE315:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEE31Au)); sfera_sub_004EE31A(cpu, LIFT_CODE_TOKEN_RVA(0xEE31Au));
    sfera_sub_004EE31A(cpu, stop_address); return;
    label_000EE366:
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFD28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFD14u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFD18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu)); sfera_sub_004EE000(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE31A(LiftCpu* cpu, uint32_t stop_address) {
    lift_store32(cpu->ebp + 0xFFFFFD24u, lift_pop32(cpu));
    lift_store32(cpu->ebp + 0xFFFFFD20u, cpu->ebp);
    lift_store32(cpu->ebp + 0xFFFFFD1Cu, cpu->esp);
    lift_push32(cpu, 0x2CCu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFD28u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE33Au));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu)); sfera_sub_004EE000(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x280u);
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE3A6u));
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
    label_000EE3E0:
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->edi + 4u, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE3E6u), LIFT_CODE_TOKEN_RVA(0xEE3E4u))) { return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE416;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, (uintptr_t)"Not enough memory. len = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, (uintptr_t)"Logs\\AntifloodQueue.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFF4u, 0x1Bu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE413u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE413u));
    cpu->esp += 0xCu;
    label_000EE416:
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->edi + 0xCu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE41Cu), LIFT_CODE_TOKEN_RVA(0xEE41Au))) { return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE44D;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, (uintptr_t)"Not enough memory. len = %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uintptr_t)"Logs\\AntifloodQueue.cpp");
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0x20u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE44Au)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE44Au));
    cpu->esp += 0xCu;
    label_000EE44D:
    cpu->edi += 0x20u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0xCu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE3E0;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000EE461:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::free);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ecx + 0xCu);
    cpu->edi = 0x14u;
    label_000EE481:
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFF8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE48E;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE48Bu), LIFT_CODE_TOKEN_RVA(0xEE489u))) { return; }
    cpu->esp += 4u;
    label_000EE48E:
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EE49A;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xEE497u), LIFT_CODE_TOKEN_RVA(0xEE495u))) { return; }
    cpu->esp += 4u;
    label_000EE49A:
    cpu->esi += 0x20u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE481;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 0x280u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x280u)), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4D0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE505u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE505u));
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000EE508:
    cpu->ecx = lift_load32(cpu->esi + 0x288u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x280u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x280u, v); }
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    ++cpu->ecx;
    cpu->eax += cpu->esi;
    lift_store32(cpu->esi + 0x288u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x14u)) goto label_000EE531;
    lift_store32(cpu->esi + 0x288u, 0u);
    label_000EE531:
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->esp -= 0xCu;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE550:
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
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EE572u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE5A7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE5A7u));
    cpu->esp += 0xCu;
    label_000EE5AA:
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4EE5B2u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE5D0(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EE600:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->edi;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    cpu->edx = lift_load32(cpu->esi + cpu->ecx + 0xCu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE610:
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
    label_000EE62C:
    cpu->eax = 0u;
    goto label_000EE635;
    label_000EE630:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EE635:
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EE648;
    cpu->edx = lift_load32(cpu->esi + cpu->ecx + 0x14u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    if ((uint8_t)(lift_load8(cpu->esi + cpu->ecx)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_000EE648;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->edi);
    label_000EE648:
    ++cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE650;
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    label_000EE650:
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
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EE672u));
    cpu->esp += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EE684:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE690(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE6C7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE6C7u));
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000EE6CA:
    cpu->eax = lift_load32(cpu->esi + 0x284u);
    cpu->edi = cpu->eax;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    ++cpu->eax;
    cpu->edi += cpu->esi;
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x284u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x14u)) goto label_000EE6EB;
    lift_store32(cpu->esi + 0x284u, cpu->ebx);
    label_000EE6EB:
    lift_store32(cpu->esi + 0x280u, (uint64_t)(lift_load32(cpu->esi + 0x280u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EE6F5u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE71Bu)); sfera_sub_004EE540(cpu, LIFT_CODE_TOKEN_VA(0x4EE71Bu));
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE72Eu)); sfera_sub_004EE540(cpu, LIFT_CODE_TOKEN_VA(0x4EE72Eu));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x280u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x288u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000EE7C2;
    cpu->edx = lift_load32(cpu->esi + 0x280u);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->edx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000EE750:
    cpu->eax = cpu->ebx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = lift_load32(cpu->eax + cpu->esi + 0xCu);
    cpu->eax += cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    label_000EE761:
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
    label_000EE77D:
    cpu->eax = 0u;
    goto label_000EE786;
    label_000EE781:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EE786:
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = 1u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE792;
    lift_store32(cpu->ebp + 8u, (uint64_t)(lift_load32(cpu->ebp + 8u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000EE792:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0u)) goto label_000EE79D;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000EE79D:
    cpu->ebx += cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x14u)) goto label_000EE7A6;
    cpu->ebx = 0u;
    label_000EE7A6:
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->ebp + 0xFFFFFFF8u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EE750;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 8u)) >= (int32_t)(uint32_t)(0xAu)) goto label_000EE7C2;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) != (uint32_t)(1u)) goto label_000EE7C2;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000EE7C2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000EE7D6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000EE7D6;
    cpu->eax -= cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EE7EC;
    label_000EE7E3:
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ecx)) == (uint8_t)(0x5Cu)) goto label_000EE7EC;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EE7E3;
    label_000EE7EC:
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 1u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}






LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE81F(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t callback_address = lift_load32(cpu->esp + 4u);
    auto callback = reinterpret_cast<void(__cdecl*)()>(static_cast<uintptr_t>(callback_address));
    cpu->eax = std::atexit(callback) == 0 ? callback_address : 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edi = cpu->edi;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, lift_load32(cpu->ebp + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE8CDu)); sfera_sub_004EE81F(cpu, LIFT_CODE_TOKEN_VA(0x4EE8CDu));
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ecx = lift_pop32(cpu);
    --cpu->eax;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE8D7(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE8F8u)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x4EE8F8u));
    if ((uint8_t)((lift_load8(cpu->ebp + 8u)) & (1u)) == 0u) goto label_000EE905;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE904u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4EE904u));
    cpu->ecx = lift_pop32(cpu);
    label_000EE905:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_000EE91E;
    label_000EE90A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE90Fu)); sfera_sub_004EF5B4(cpu, LIFT_CODE_TOKEN_VA(0x4EE90Fu));
    if ((uint8_t)((lift_load8(cpu->ebp + 8u)) & (1u)) == 0u) goto label_000EE91C;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE91Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4EE91Bu));
    cpu->ecx = lift_pop32(cpu);
    label_000EE91C:
    cpu->eax = cpu->edi;
    label_000EE91E:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE92A(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; lift_trap(cpu, 0x4EE92Au, "client C++ exception path reached"); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE940(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_crt_startup_runtime.processor_feature_10), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u)) {
        sfera_sub_004EE976(cpu, stop_address);
        return;
    }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    cpu->esp &= 0xFFFFFFF8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(int32_t)trunc(lift_load_f64(cpu->esp));
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE976(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EE999:
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
    label_000EE9BD:
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x7FFFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    goto label_000EE9E9;
    label_000EE9D5:
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)((cpu->edx) & (0x7FFFFFFFu)) != 0u) goto label_000EE999;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000EE9E9:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9EC(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::sqrt(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9F2(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::cos(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9F8(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::sin(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9FE(LiftCpu* cpu, uint32_t stop_address) {
    const double right = lift_x87_get(cpu, 0u);
    const double left = lift_x87_get(cpu, 1u);
    lift_x87_set(cpu, 1u, std::pow(left, right));
    lift_x87_pop(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEA10(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EEA61:
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
    label_000EEA7D:
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
    label_000EEA99:
    cpu->ebx = cpu->eax;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_000EEAA7:
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
    label_000EEAD5:
    --cpu->esi;
    label_000EEAD6:
    cpu->edx = 0u;
    cpu->eax = cpu->esi;
    label_000EEADA:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EEAE4;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EEAE4:
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEAF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = ~((uint64_t)(cpu->eax));
    cpu->ecx &= cpu->eax;
    cpu->eax = cpu->esp;
    cpu->eax &= 0xFFFFF000u;
    label_000EEB04:
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
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEB12:
    cpu->eax -= 0x1000u;
    (void)(lift_load32(cpu->eax));
    goto label_000EEB04;
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB28(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x14u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEB34u)); sfera_sub_004EF270(cpu, LIFT_CODE_TOKEN_VA(0x4EEB34u));
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) & (uint64_t)(0u));
    label_000EEB38:
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EEB77;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->ecx -= lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 8u, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ebp + 0x14u)), LIFT_CODE_TOKEN_RVA(0xEEB49u), LIFT_CODE_TOKEN_RVA(0xEEB46u))) { return; }
    goto label_000EEB38;
    label_000EEB77:
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEB83u)); sfera_sub_004EF2B5(cpu, LIFT_CODE_TOKEN_VA(0x4EEB83u));
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB4B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(0xE06D7363u)) goto label_000EEB6F;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEB6F:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEEB74u)); sfera_sub_004EF2DA(cpu, LIFT_CODE_TOKEN_RVA(0xEEB74u));
    sfera_sub_004EEB74(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB74(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEB83u)); sfera_sub_004EF2B5(cpu, LIFT_CODE_TOKEN_VA(0x4EEB83u));
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB86(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEB92u)); sfera_sub_004EF270(cpu, LIFT_CODE_TOKEN_VA(0x4EEB92u));
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) & (uint64_t)(0u));
    cpu->esi = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 0x10u));
    lift_store32(cpu->ebp + 8u, (uint64_t)(lift_load32(cpu->ebp + 8u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0xFFFFFFFCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) & (uint64_t)(0u));
    label_000EEBA6:
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000EEBB6;
    lift_store32(cpu->ebp + 8u, (uint64_t)(lift_load32(cpu->ebp + 8u)) - (uint64_t)(cpu->esi) - (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ebp + 0x14u)), LIFT_CODE_TOKEN_RVA(0xEEBB4u), LIFT_CODE_TOKEN_RVA(0xEEBB1u))) { return; }
    goto label_000EEBA6;
    label_000EEBB6:
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 1u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEBC9u)); sfera_sub_004EEBD1(cpu, LIFT_CODE_TOKEN_VA(0x4EEBC9u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEBCEu)); sfera_sub_004EF2B5(cpu, LIFT_CODE_TOKEN_VA(0x4EEBCEu));
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEBD1(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) != (uint32_t)(0u)) goto label_000EEBE8;
    lift_push32(cpu, lift_load32(cpu->ebp + 0x14u)); lift_push32(cpu, lift_load32(cpu->ebp + 0x10u)); lift_push32(cpu, lift_load32(cpu->ebp + 0xCu)); lift_push32(cpu, lift_load32(cpu->ebp + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEEBE8u)); sfera_sub_004EEB28(cpu, LIFT_CODE_TOKEN_RVA(0xEEBE8u));
    label_000EEBE8:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEBE9(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x10u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEBF5u)); sfera_sub_004EF270(cpu, LIFT_CODE_TOKEN_VA(0x4EEBF5u));
    cpu->eax = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    label_000EEC00:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x10u))) goto label_000EEC1B;
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->ecx = cpu->esi;
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ebp + 0x14u)), LIFT_CODE_TOKEN_RVA(0xEEC10u), LIFT_CODE_TOKEN_RVA(0xEEC0Du))) { return; }
    cpu->esi += lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) + 1u);
    goto label_000EEC00;
    label_000EEC1B:
    lift_store32(cpu->ebp + 0xFFFFFFE0u, 1u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEC2Eu)); sfera_sub_004EEC36(cpu, LIFT_CODE_TOKEN_VA(0x4EEC2Eu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEC33u)); sfera_sub_004EF2B5(cpu, LIFT_CODE_TOKEN_VA(0x4EEC33u));
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC36(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE0u)) != (uint32_t)(0u)) goto label_000EEC4D;
    lift_push32(cpu, lift_load32(cpu->ebp + 0x18u)); lift_push32(cpu, lift_load32(cpu->ebp + 0xFFFFFFE4u)); lift_push32(cpu, lift_load32(cpu->ebp + 0xCu)); lift_push32(cpu, lift_load32(cpu->ebp + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEEC4Du)); sfera_sub_004EEB28(cpu, LIFT_CODE_TOKEN_RVA(0xEEC4Du));
    label_000EEC4D:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC4E(LiftCpu* cpu, uint32_t stop_address) {
    const double right = lift_x87_get(cpu, 0u);
    const double left = lift_x87_get(cpu, 1u);
    lift_x87_set(cpu, 1u, std::atan2(left, right));
    lift_x87_pop(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC54(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::exp(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC60(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EEC80:
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000EEC9B;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    label_000EEC9B:
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
    label_000EECBA:
    cpu->ebx = cpu->eax;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    label_000EECC8:
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
    label_000EECF3:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esp + 0x18u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EECFB:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0xCu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esp + 0x10u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000EED0D;
    label_000EED06:
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(0u) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000EED0D:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000EED39;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000EED39:
    lift_push32(cpu, cpu->ebx);
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x14u), 32u, 0u);
    cpu->ebx += cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx += cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED54(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::tan(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED5A(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::acos(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED60(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::atan(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED66(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, std::floor(lift_load_f64(cpu->esp + 4u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED6C(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_set(cpu, 0u, std::asin(lift_x87_get(cpu, 0u)));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED80(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EEDA2:
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    label_000EEDB0:
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
    label_000EEDDE:
    --cpu->esi;
    label_000EEDDF:
    cpu->edx = 0u;
    cpu->eax = cpu->esi;
    label_000EEDE3:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEDF0(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint8_t)((cpu->ecx & 0xFFu)) >= (uint8_t)(0x40u)) goto label_000EEE0A;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000EEE00;
    cpu->edx = lift_double_shift_left(cpu, cpu->edx, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEE00:
    cpu->edx = cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEE0A:
    cpu->eax = 0u;
    cpu->edx = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE10(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint8_t)((cpu->ecx & 0xFFu)) >= (uint8_t)(0x40u)) goto label_000EEE2A;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000EEE20;
    cpu->eax = lift_double_shift_right(cpu, cpu->eax, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEE20:
    cpu->eax = cpu->edx;
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEE2A:
    cpu->eax = 0u;
    cpu->edx = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE61(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.mainargs_result = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF088(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.managed_app = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF10Eu)); sfera_sub_004EF33C(cpu, LIFT_CODE_TOKEN_VA(0x4EF10Eu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF113u)); sfera_sub_004EF510(cpu, LIFT_CODE_TOKEN_VA(0x4EF113u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF12Du)); sfera_sub_004EF4E8(cpu, LIFT_CODE_TOKEN_VA(0x4EF12Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF142(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF142;
    label_000EEEAF:
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEEBBu)); sfera_sub_004EF270(cpu, LIFT_CODE_TOKEN_VA(0x4EEEBBu));
    cpu->ebx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetStartupInfoW), LIFT_CODE_TOKEN_VA(0x4EEEC4u));
    if ((uint32_t)(lift_load32((uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.heap_compatibility_flag)) != (uint32_t)(cpu->ebx)) goto label_000EEEDD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::HeapSetInformation), LIFT_CODE_TOKEN_RVA(0xEEED7u));
    label_000EEEDD:
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    cpu->eax = lift_fs_load32(cpu, 0x18u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->ebx);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.startup_lock;
    label_000EEEF1:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedCompareExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->esi), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 12u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000EEF17;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EEF0A;
    cpu->esi = 0u;
    ++cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esi);
    goto label_000EEF1A;
    label_000EEF0A:
    lift_push32(cpu, 0x3E8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x4EEF0Fu));
    goto label_000EEEF1;
    label_000EEF17:
    cpu->esi = 0u;
    ++cpu->esi;
    label_000EEF1A:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EEF2D;
    lift_push32(cpu, 0x1Fu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF2Au)); sfera_sub_004EF336(cpu, LIFT_CODE_TOKEN_VA(0x4EEF2Au));
    cpu->ecx = lift_pop32(cpu);
    goto label_000EEF68;
    label_000EEF2D:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000EEF62;
    g_sfera_crt_startup_runtime.startup_state = (uint32_t)(cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF088(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
    if (cpu->eax == 0u) {
        lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF2C9(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
        if (cpu->eax == 0u) {
            lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF328(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
        }
    }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EEF68;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->eax = 0xFFu;
    goto label_000EF082;
    label_000EEF62:
    g_sfera_crt_startup_runtime.has_cctor = (uint32_t)(cpu->esi);
    label_000EEF68:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000EEF8C;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004EEE61(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004FA041(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4AE0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4B10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4B50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4B80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4BC0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4BF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4C30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4C60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4CA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4CD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4D10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4D40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4D80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4DB0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4DF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4E20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4E60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4EA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4ED0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4F10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4F40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4F80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4FB0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4FF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5070(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F50E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F50F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5120(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5160(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5190(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F51D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F51F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5270(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5330(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5360(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F53A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F53D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5450(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5480(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F54C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F54F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5530(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5550(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5570(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5580(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5590(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F55B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F55E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5620(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5690(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5700(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5770(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F57A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F57E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5810(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5850(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5870(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5890(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5920(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F59B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5A40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5AD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5B60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5BF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5C80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5C90(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5D20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5DB0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5DD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5DE0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5E50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5EC0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5F30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5FA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6010(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6080(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F60F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6160(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F61D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6240(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F62B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6320(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6390(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6400(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6470(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6510(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6580(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6650(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6720(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F67F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F68C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6950(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F69C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6A30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6AA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6B10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6B80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6C10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6C80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6CF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6D60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6DD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6E40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6EB0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6F20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6FA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7010(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7080(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F70F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7160(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F71D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7240(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F72B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7320(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7390(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7400(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7470(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F74E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7550(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F75C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7630(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F76A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7710(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7780(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F77B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F77F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7820(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7860(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7890(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F78D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7900(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7940(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7970(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F79B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F79E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7A20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7A50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7A90(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7AC0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7B00(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7B30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7B70(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7BA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7BE0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7BF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7C20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7CA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7CD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7D10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7D40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7D80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7DB0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7DF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7E00(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7E30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7E70(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7EA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7EE0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7EF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7F20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7F60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7F90(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7FD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8000(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8040(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8070(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F80B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8120(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8150(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8190(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F81C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8200(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8220(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8240(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8270(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F82B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F82D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F82F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8320(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8360(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8390(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F83D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F83F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8410(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8440(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8480(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F84A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F84C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F84F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8530(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8550(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8570(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F85A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F85E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F85F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8620(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8660(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8680(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F86A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F86D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8710(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8740(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8780(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F87A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F87C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F87F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8830(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8850(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8870(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F88A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F88E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8900(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8920(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8950(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8990(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F89B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F89D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8A00(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8A40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8A60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8A80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8AB0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8AF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8B10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8B30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8B90(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8BF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8C50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8C60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8D20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8D80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8DA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8DD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8E10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8E30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8E50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8E80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8EC0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8EF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8F30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8F50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8F70(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F8FA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9080(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F90B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F90F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9110(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9130(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9160(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F91A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F91C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F91E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9210(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9250(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9280(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F92C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F92E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9300(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9330(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9370(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9390(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F93B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F93E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9420(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9440(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9460(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9490(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F94D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F94F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9510(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9540(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9580(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F95A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F95C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F95F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9630(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9650(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9670(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F96A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F96E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9700(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9720(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9730(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9740(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9750(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9780(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F97C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F97E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9800(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9830(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9870(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F98A0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F98E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9900(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9920(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9950(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9990(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F99B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F99D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9A00(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9A40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9A60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9A80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9AB0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9AF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9B50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9B80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9BC0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9BE0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9C00(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9C20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9C50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9C90(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9CC0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9D00(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9D30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9D70(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9DA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9DE0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9E10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9E50(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9E80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9EC0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9EF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9F30(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9F60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9FA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9FD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004FA010(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    g_sfera_crt_startup_runtime.startup_state = (uint32_t)(2u);
    label_000EEF8C:
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFDCu)) != (uint32_t)(cpu->ebx)) goto label_000EEF99;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 8u;
    label_000EEF99:
    if ((uint32_t)(g_sfera_crt_startup_runtime.dynamic_tls_init_callback) == (uint32_t)(cpu->ebx)) goto label_000EEFBA;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.dynamic_tls_init_callback);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEFABu)); sfera_sub_004EF420(cpu, LIFT_CODE_TOKEN_VA(0x4EEFABu));
    cpu->ecx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EEFBA;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_crt_startup_runtime.dynamic_tls_init_callback), LIFT_CODE_TOKEN_RVA(0xEEFBAu), LIFT_CODE_TOKEN_RVA(0xEEFB4u))) { return; }
    label_000EEFBA:
    cpu->esi = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::GetCommandLineA()));
    label_000EEFC1:
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->esi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(0x20u)) goto label_000EF013;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000EEFD3;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) != (uint32_t)(cpu->ebx)) goto label_000EF013;
    label_000EEFD3:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000EEFE3;
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(0x20u)) goto label_000EEFE3;
    ++cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->esi);
    goto label_000EEFD3;
    label_000EEFE3:
    if ((uint8_t)((lift_load8(cpu->ebp + 0xFFFFFFC0u)) & (1u)) == 0u) goto label_000EEFEF;
    cpu->eax = lift_load16(cpu->ebp + 0xFFFFFFC4u);
    goto label_000EEFF2;
    label_000EEFEF:
    lift_push32(cpu, 0xAu);
    cpu->eax = lift_pop32(cpu);
    label_000EEFF2:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, lift_process_module_handle());
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEFFFu)); sfera_sub_0047D770(cpu, LIFT_CODE_TOKEN_VA(0x4EEFFFu));
    g_sfera_crt_startup_runtime.main_return_code = (uint32_t)(cpu->eax);
    if ((uint32_t)(g_sfera_crt_startup_runtime.managed_app) != (uint32_t)(cpu->ebx)) goto label_000EF068;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0xEF00Du));
    label_000EF013:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x22u)) goto label_000EF022;
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ecx);
    label_000EF022:
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_ismbblead), LIFT_CODE_TOKEN_VA(0x4EF026u));
    cpu->ecx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EF035;
    ++cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->esi);
    label_000EF035:
    ++cpu->esi;
    goto label_000EEFC1;
    label_000EF068:
    if ((uint32_t)(g_sfera_crt_startup_runtime.has_cctor) != (uint32_t)(cpu->ebx)) goto label_000EF076;
    lift_native_call(cpu, native_function_address32(&::_cexit), LIFT_CODE_TOKEN_RVA(0xEF070u));
    label_000EF076:
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->eax = g_sfera_crt_startup_runtime.main_return_code;
    label_000EF082:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF087u)); sfera_sub_004EF2B5(cpu, LIFT_CODE_TOKEN_VA(0x4EF087u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EF142:
    goto label_000EEEAF;
}



LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF270(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2B5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2C9(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xAu);
    lift_native_call(cpu, native_function_address32(&::IsProcessorFeaturePresent), LIFT_CODE_TOKEN_VA(0x4EF2CBu));
    g_sfera_crt_startup_runtime.processor_feature_10 = (uint32_t)(cpu->eax);
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2DA(LiftCpu* cpu, uint32_t stop_address) {
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4EF2DAu), "std::terminate");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2E6(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000EF31D:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEF322u)); sfera_sub_004EF2DA(cpu, LIFT_CODE_TOKEN_RVA(0xEF322u));
    label_000EF322:
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF328(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004EF2E6));
    lift_native_call(cpu, native_function_address32(&::SetUnhandledExceptionFilter), LIFT_CODE_TOKEN_VA(0x4EF32Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF336(LiftCpu* cpu, uint32_t stop_address) {
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4EF336u), "CRT startup failure");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF33C(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->esp += 4u; cpu->eip = stop_address; return; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF362(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->esp += 4u; cpu->eip = stop_address; return; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF390(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->eax = lift_load32(cpu->esp + 4u) == lift_process_module_handle() ? 1u : 0u; cpu->esp += 4u; cpu->eip = stop_address; return; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF3D0(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->eax = 0u; cpu->esp += 4u; cpu->eip = stop_address; return; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF420(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; { uint32_t target = lift_load32(cpu->esp + 4u); uint32_t rva = lift_source_rva(target); uint32_t tls_slot = (uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.dynamic_tls_init_callback; cpu->eax = target == tls_slot || lift_is_native_code_address(target) || (rva >= 0x1000u && rva < 0xFC200u) ? 1u : 0u; } cpu->esp += 4u; cpu->eip = stop_address; return; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4AB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0xC0000005u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4BE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4E8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edi = cpu->edi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x30000u); lift_push32(cpu, 0x10000u);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_controlfp_s), LIFT_CODE_TOKEN_VA(0x4EF4F8u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EF50E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEF50Eu)); sfera_sub_004EF5BA(cpu, LIFT_CODE_TOKEN_RVA(0xEF50Eu));
    label_000EF50E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5B4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5BA(LiftCpu* cpu, uint32_t stop_address) {
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4EF5BAu), "invalid CRT parameter");
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF781(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF7B4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF868(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF908(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF908;
    label_00002CC0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0u)) goto label_00002CE4;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402CD8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x402CD8u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402CE1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x402CE1u));
    cpu->esp += 4u;
    label_00002CE4:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EF908:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    goto label_00002CC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF9CDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EF9CDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF9FDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EF9FDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFA2Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFA2Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA58(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFA8Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFA8Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFABDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFABDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFAEDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFAEDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFB1Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFB1Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB21(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFB5Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFB5Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFBFDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFBFDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFC2Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFC2Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFC5Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFC5Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFC8Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFC8Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC91(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFCC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFCCDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFCCDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EFCFDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4EFCFDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD01(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD38(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDA8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFDA8;
    label_00002CC0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0u)) goto label_00002CE4;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402CD8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x402CD8u));
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402CE1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x402CE1u));
    cpu->esp += 4u;
    label_00002CE4:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EFDA8:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    goto label_00002CC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDD8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00402D20(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFE68;
    label_000061E0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) < (uint32_t)(0x10u)) goto label_000061F5;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4061F2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4061F2u));
    cpu->esp += 4u;
    label_000061F5:
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x18u, 0xFu);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store8(cpu->esi + 4u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EFE68:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    goto label_000061E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEA8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFEE8;
    label_00006260:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4062A5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4062A5u));
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4062AEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4062AEu));
    cpu->esp += 4u;
    label_000062B1:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000062C2;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4062BFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4062BFu));
    cpu->esp += 4u;
    label_000062C2:
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EFEE8:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_00006260;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF28(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFA8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0038(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0038;
    label_000061E0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) < (uint32_t)(0x10u)) goto label_000061F5;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4061F2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4061F2u));
    cpu->esp += 4u;
    label_000061F5:
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x18u, 0xFu);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store8(cpu->esi + 4u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0038:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    goto label_000061E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0078(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFBCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F00B8;
    label_00006260:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4062A5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4062A5u));
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4062AEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4062AEu));
    cpu->esp += 4u;
    label_000062B1:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000062C2;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4062BFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4062BFu));
    cpu->esp += 4u;
    label_000062C2:
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F00B8:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_00006260;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0138(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0178(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0180(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0180;
    label_000062F0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00006305;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406302u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x406302u));
    cpu->esp += 4u;
    label_00006305:
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esi + 8u, cpu->eax & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->eax)) goto label_00006332;
    cpu->edx = (uint32_t)(cpu->eax + 0x27u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406326u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x406326u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40632Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40632Fu));
    cpu->esp += 4u;
    label_00006332:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0180:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    goto label_000062F0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01B8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0228(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0238(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0278(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0288(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02C8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02D8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00402CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0310(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0310;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0310:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0318(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0340(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0340;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0340:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0348(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0348;
    label_00014B90:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414BC5u)); sfera_sub_004149A0(cpu, LIFT_CODE_TOKEN_VA(0x414BC5u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414BCDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414BCDu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0348:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_00014B90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0370(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0370;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0370:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0378(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0378;
    label_00014D30:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D38u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x414D38u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D40u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414D40u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0378:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_00014D30;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F03A9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F03A9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03AB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F03B4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F03B4u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03B6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F03BFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F03BFu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03C1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F03CAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F03CAu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F03F0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F8;
    label_00015050:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415095u)); sfera_sub_00406340(cpu, LIFT_CODE_TOKEN_VA(0x415095u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41509Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41509Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F03F8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015050;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0420(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0420;
    label_000161C0:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0420:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0450(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0450;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0450:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0458(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0458;
    label_00015300:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415345u)); sfera_sub_00409F90(cpu, LIFT_CODE_TOKEN_VA(0x415345u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41534Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41534Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0458:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015300;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0480(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0480;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0480:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0488(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0488;
    label_000154E0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415525u)); sfera_sub_0040D400(cpu, LIFT_CODE_TOKEN_VA(0x415525u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41552Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41552Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0488:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_000154E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F04B0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B8;
    label_00015550:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415595u)); sfera_sub_0040D4D0(cpu, LIFT_CODE_TOKEN_VA(0x415595u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41559Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41559Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F04B8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015550;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F04E0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E8;
    label_000155C0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415605u)); sfera_sub_0040D5A0(cpu, LIFT_CODE_TOKEN_VA(0x415605u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41560Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41560Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F04E8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_000155C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0510(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0510;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0510:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0518(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0518;
    label_00015630:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x415675u)); sfera_sub_0040D670(cpu, LIFT_CODE_TOKEN_VA(0x415675u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41567Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41567Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0518:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x14u;
    goto label_00015630;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0549u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0549u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F054B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0554u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0554u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0580;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0580:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0588(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0588;
    label_000B3CD0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0588:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F05B0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B8;
    label_00016330:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416375u)); sfera_sub_0040A7A0(cpu, LIFT_CODE_TOKEN_VA(0x416375u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41637Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41637Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F05B8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    goto label_00016330;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05E0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F05E0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05E8;
    label_000161C0:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F05E8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0610(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0610;
    label_00014990:
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414998u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414998u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0610:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0640(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0640;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0640:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0648(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0653(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F065E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F065E;
    label_000166B0:
    sfera_sub_00416650(cpu, stop_address); return;
    label_000F065E:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000166B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0690(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0690;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0690:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0698(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0698;
    label_000166C0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4166F5u)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x4166F5u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4166FDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4166FDu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0698:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_000166C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06A3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06AE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06AE;
    label_000167E0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416814u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416814u));
    cpu->esp += 4u;
    label_00016817:
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416832u)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x416832u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41683Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41683Au));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F06AE:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000167E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F06E0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E8;
    label_00016720:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416755u)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x416755u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41675Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41675Du));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F06E8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016720;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06F3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06FE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06FE;
    label_00016850:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416884u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416884u));
    cpu->esp += 4u;
    label_00016887:
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4168A2u)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x4168A2u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4168AAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4168AAu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F06FE:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00016850;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0730(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0730;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0730:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0738(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0738;
    label_00016780:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4167B5u)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x4167B5u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4167BDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4167BDu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0738:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016780;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0743(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F074E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F074E;
    label_000168C0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4168F4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4168F4u));
    cpu->esp += 4u;
    label_000168F7:
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416912u)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x416912u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41691Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41691Au));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F074E:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000168C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0780(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0780;
    label_00014990:
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414998u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414998u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0780:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07B0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F07B0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07B8;
    label_00014D30:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D38u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x414D38u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414D40u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414D40u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F07B8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00014D30;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07C3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07CE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07CE;
    label_00017150:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00017163;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417160u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417160u));
    cpu->esp += 4u;
    label_00017163:
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417180u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x417180u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417189u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417189u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F07CE:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017150;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0800(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0800;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0800:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0808(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0808;
    label_00016930:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416938u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x416938u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416940u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416940u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0808:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016930;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0813(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F081E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F081E;
    label_00017190:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000171A3;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4171A0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4171A0u));
    cpu->esp += 4u;
    label_000171A3:
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4171C0u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x4171C0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4171C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4171C9u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F081E:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017190;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0850;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0850:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0858(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0858;
    label_00016950:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416958u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x416958u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416960u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416960u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0858:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0863(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F086E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F086E;
    label_000171D0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000171E3;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4171E0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4171E0u));
    cpu->esp += 4u;
    label_000171E3:
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0u);
    lift_store32(cpu->esi + 0x18u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417200u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x417200u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417209u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417209u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F086E:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_000171D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F08A0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A8;
    label_00016970:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4169A5u)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x4169A5u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4169ADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4169ADu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F08A8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_00016970;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08B3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08BE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08BE;
    label_00017210:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417244u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x417244u));
    cpu->esp += 4u;
    label_00017247:
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417262u)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x417262u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41726Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x41726Au));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F08BE:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F08F0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F8;
    label_000169D0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416A05u)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x416A05u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416A0Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x416A0Du));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F08F8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 4u;
    goto label_000169D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0903(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F090E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F090E;
    label_00017280:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4172B4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4172B4u));
    cpu->esp += 4u;
    label_000172B7:
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4172D2u)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x4172D2u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4172DAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4172DAu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F090E:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x14u;
    goto label_00017280;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0949u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0949u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F094B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0954u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0954u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0956(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F095Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F095Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0980(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0980;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0980:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0988(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0988;
    label_00014990:
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414998u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x414998u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0988:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09B0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F09B0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09B8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09E0;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F09E0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A10(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A10;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0A10:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A18(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A18;
    label_00018270:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0001829C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00018290;
    label_00018282:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418289u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x418289u));
    cpu->esi += 8u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_00018282;
    label_00018290:
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418298u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x418298u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    label_0001829C:
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx, 0u);
    lift_store32(cpu->ebx + 4u, 0u);
    lift_store32(cpu->ebx + 8u, 0u);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0A18:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    goto label_00018270;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A40(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A40;
    label_00015040:
    sfera_sub_00401E50(cpu, stop_address); return;
    label_000F0A40:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A48(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A48;
    label_000183C0:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000183E6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4183DBu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4183DBu));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4183E3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4183E3u));
    cpu->esp += 4u;
    label_000183E6:
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0A48:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0A79u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0A79u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A7B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0A84u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0A84u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A86(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0A8Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0A8Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A91(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0A9Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0A9Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A9C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0AA5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0AA5u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_0042B7D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B00(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B00;
    label_00018890:
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418893u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0B00:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    goto label_00018890;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_0042B7D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B60;
    label_00018890:
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418893u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0B60:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFDD8u);
    goto label_00018890;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0BA9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0BA9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0BD9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0BD9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_0047ED10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB4u);
    sfera_sub_0047ED10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C3B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB0u);
    sfera_sub_0047EDB0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0C89u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0C89u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0CC9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0CC9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0CF9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0CF9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CFB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D04u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D04u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D06(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D0Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D0Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D11(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D1Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D1Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D1C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D25u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D25u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D5Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D5Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D5E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D6Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D6Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D6C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D78u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D78u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D7A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D86u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D86u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0D94u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0D94u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D96(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0DA2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0DA2u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E19u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E19u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E24u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E24u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E2Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E2Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E31(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E3Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E3Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E3C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E45u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E45u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E47(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E50u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E50u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E52(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E5Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E5Bu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E5D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0E66u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0E66u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_items;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0EC0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0EC0;
    label_000161C0:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0EC0:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0EF9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0EF9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_00425E70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0FB0;
    label_0002E1E0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E20A;
    cpu->edx = 0x65u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E1FEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E1FEu));
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E207u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E207u));
    cpu->esp += 4u;
    label_0002E20A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F0FB0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_0002E1E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0FE9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0FE9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FEB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F0FF4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F0FF4u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1020(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1020;
    label_000313C0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_000313D5;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4313D2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4313D2u));
    cpu->esp += 4u;
    label_000313D5:
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store8(cpu->esi + 8u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F1020:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_000313C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1050(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1050;
    label_00031410:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x48u)) < (uint32_t)(0x10u)) goto label_00031426;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431423u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x431423u));
    cpu->esp += 4u;
    label_00031426:
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x48u, 0xFu);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    lift_store8(cpu->esi + 0x34u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00031447;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431444u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x431444u));
    cpu->esp += 4u;
    label_00031447:
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F1050:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_00031410;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F108Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F108Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F10C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F10F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F10F9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F10F9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1129u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1129u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F112B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1134u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1134u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE44u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F117Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F117Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F117E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE44u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F118Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F118Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F11C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F11C8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1238(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_frame_runtime.color_lookup_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_frame_runtime.color_lookup_flags = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A0;
    label_00051CE0:
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F12A0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A8;
    label_00051CE0:
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F12A8:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E0;
    label_00051CE0:
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F12E0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E8;
    label_00051CE0:
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x451CEEu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F12E8:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1359u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1359u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F135B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1364u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1364u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1366(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F136Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F136Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1371(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F137Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F137Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F137C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1385u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1385u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1387(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1390u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1390u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1392(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F139Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F139Bu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE1Cu);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13DB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13E9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFE0Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F13F5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F13F5u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1498(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F14D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_grass_map_runtime.init_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_grass_map_runtime.init_guard = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F151Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F151Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F151E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F152Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F152Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F152C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1538u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1538u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F153A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1546u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1546u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1548(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1554u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1554u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1556(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1562u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1562u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1564(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1570u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1570u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1572(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F157Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F157Eu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F15B0;
    label_000161C0:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F15B0:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F15E9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F15E9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15EB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F15F4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F15F4u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEC4u);
    sfera_sub_0047ED10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F162B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_0047EDB0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1679u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1679u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F16B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F16B9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F16B9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F16F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFBCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F16F9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F16F9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF68u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F173Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F173Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F173E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF68u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F174Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F174Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F174C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF58u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1758u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1758u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1799u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1799u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F17D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0xC80u;
    sfera_sub_00430BC0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFF2C4u);
    cpu->ecx += 0xC80u;
    sfera_sub_00430BC0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1868(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFACu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1871u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1871u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F18A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F18D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1918;
    lift_store32(cpu->ebp + 0xFFFFFFB4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFB4u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1918:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1968;
    lift_store32(cpu->ebp + 0xFFFFFFCCu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFCCu)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1968:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1969(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F19A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F19B8;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE8u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F19B8:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F19E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F19F8;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFE4u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F19F8:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A28(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1A40;
    lift_store32(cpu->ebp + 0xFFFFFF90u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFF90u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1A40:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A41(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1A59;
    lift_store32(cpu->ebp + 0xFFFFFF90u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFF90u)) & (uint64_t)(0xFFFFFFFDu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1A59:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AD8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AEB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AF3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AFE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B09(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B14(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B1C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B27(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B2F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEC8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1B3Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1B3Bu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B3D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B45(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEC8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1B51u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1B51u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B53(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B5B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B66(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEC8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1B72u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1B72u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE4Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BBB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE30u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BC6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFDF8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BD1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BDC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE84u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BE7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE14u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BF2(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BFD(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C08(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE68u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C31(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEA0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C3C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C44(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C4F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C57(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C62(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F1CB8;
    lift_store32(cpu->ebp + 0xFFFFFFECu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFECu)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F1CB8:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CE8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1D39u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1D39u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D3B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D43(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D4B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1D54u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1D54u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D56(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D5E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1D67u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1D67u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D69(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1D72u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1D72u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D74(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F1D7Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F1D7Du));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF70u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F1DB0u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DBC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1DBC;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F1DBC:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF70u);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DC7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DCF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DD7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DDF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F1E20u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E29(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1E29;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F1E29:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E31(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E39(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E41(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0x3Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0x20u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E98(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EA3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE84u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EAE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE68u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EB9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EC1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE4Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1ECC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEA0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1ED7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EDF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EEA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EF5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F08(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F13(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F68(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF4Cu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F1F68u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F74(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1F74;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F1F74:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF4Cu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F7F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F87(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FC8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF38u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F1FC8u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FD4(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1FD4;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F1FD4:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF38u);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FDF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FE7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FEF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FF7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FFF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2048(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF6Cu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F2048u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2054(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2054;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2054:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF6Cu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F205F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2067(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F206F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F20B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F20E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFDA4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F20ECu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F20ECu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_effect_items;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2159u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2159u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFED8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F218Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F218Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F21C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFDC8u);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_00480390(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F22A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F235Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F235Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F238Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F238Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F23D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F23D8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2419u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2419u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x10u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F248B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x30u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2496(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x40u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24A1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x58u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x10u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24DB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x30u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24E6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x40u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24F1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x58u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2529u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2529u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F25B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F25B0;
    label_000A8F90:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8F9Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A8F9Bu));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F25B0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2608(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2608;
    label_000AA210:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA245u)); sfera_sub_004A9AA0(cpu, LIFT_CODE_TOKEN_VA(0x4AA245u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA24Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA24Du));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2608:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x198u;
    goto label_000AA210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2616(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x1B0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2624(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x1C0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2632(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x1D0u;
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x208u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F264E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x224u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F265C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x288u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F266A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F266A;
    label_000A8F90:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8F9Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A8F9Bu));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F266A:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F26B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F26B0u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F26B9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F26B9;
    label_000A8F90:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8F9Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A8F9Bu));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F26B9:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2738(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x1Cu;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2743(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2743;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2743:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x40u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    sfera_sub_004AE200(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEBCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27BB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27C6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27D1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27D9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27E4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27EF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27F7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2802(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    sfera_sub_004AE200(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F28D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2908(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F2908u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2911(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2911;
    label_000AA210:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA245u)); sfera_sub_004A9AA0(cpu, LIFT_CODE_TOKEN_VA(0x4AA245u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AA24Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AA24Du));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2911:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x198u;
    goto label_000AA210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F291F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x1B0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F292D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x1C0u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F293B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x1D0u;
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2949(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x208u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2957(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x224u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2965(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->ecx += 0x288u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2998(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F29A1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F29A1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29A3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFACu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F29BB;
    lift_store32(cpu->ebp + 0xFFFFFFACu, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFACu)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F29BB:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A0B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A13(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A1E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A26(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A2E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A36(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A3E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A49(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2A55u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2A55u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A57(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2A63u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2A63u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A65(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2A71u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2A71u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A73(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A7B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2A87u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2A87u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A89(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A91(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A9C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF0Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2AA8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2AA8u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AE8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x1Cu;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AF3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F2AF3u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AFC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2AFC;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2AFC:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x40u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B07(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ecx += 0x58u;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEE4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F2B30u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B3C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2B3C;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2B3C:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEE4u);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B47(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B4F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B5A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B62(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B6A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B75(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F2BB0u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BB9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2BB9;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2BB9:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2BEDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F2BEDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C48(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2C48;
    label_000AF880:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u)); sfera_sub_004AF470(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2C48:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x2DCu;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C88(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F2C88u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2CB9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2CB9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2CBB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2D19u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2D19u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D1B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F2D24u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F2D24u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DB0;
    label_000B1320:
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2DB0:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DE0;
    label_000B1320:
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2DE0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DF0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DF0;
    label_000B1320:
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2DF0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E20;
    label_000B1320:
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2E20:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E30(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E30;
    label_000B1320:
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2E30:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EE0;
    label_000B1320:
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2EE0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EE8;
    label_000B1320:
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + cpu->eax + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1338;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_tail_indirect(cpu, (uint32_t)(cpu->eax), stop_address, LIFT_CODE_TOKEN_RVA(0xB1336u)); return;
    label_000B1338:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F2EE8:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F18(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F58(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30A8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F30B1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F30B1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30B3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F30CB;
    lift_store32(cpu->ebp + 0xFFFFFFC8u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFC8u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F30CB:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F3118;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFF0u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F3118:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F3140u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F314C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F314C;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F314C:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3157(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F315F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F31A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3258(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F3258u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3261(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3261;
    label_000AF880:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u)); sfera_sub_004AF470(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3261:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x198u;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F326F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F326F;
    label_000B3CD0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F326F:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1B8u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F327D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1C8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F328B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1E4u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3299(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F3299u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32C8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32D8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF74u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F32ECu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F32ECu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEE4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F3341;
    lift_store32(cpu->ebp + 0xFFFFFEE4u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFEE4u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFEE8u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F3341:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3342(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3355(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F335D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33AB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33B6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33C1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33CC(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33D7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33DF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33E7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33EF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33F7(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3402(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F344B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3456(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F345E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3469(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF10u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3474(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F347C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF64u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3487(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F348F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF48u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F349A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEF4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34A5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34E8;
    label_000AF880:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u)); sfera_sub_004AF470(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F34E8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x198u;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34F6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34F6;
    label_000B3CD0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F34F6:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x1B8u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3504(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x1C8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3512(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x1E4u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3520(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3520;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3520:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x200u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F352E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F352E;
    label_000161C0:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F352E:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F356B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3576(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3581(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F358C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3597(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35A2(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35AD(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3638(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F3638u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3641(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3641;
    label_000AF880:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u)); sfera_sub_004AF470(cpu, LIFT_CODE_TOKEN_VA(0x4AF888u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AF890u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3641:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x198u;
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F364F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F364F;
    label_000B3CD0:
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4B3D15u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B3D1Eu));
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F364F:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1B8u;
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F365D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1C8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F366B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x1E4u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3679(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F3679u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3682(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3682;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3682:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x200u;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F36B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F36E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F36E9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F36E9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3719u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3719u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F371B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3724u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3724u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F378E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_cursor_manager_runtime.initialized_flags;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F37C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F37CDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F37CDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F37D1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F380Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F380Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3811(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFDA8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F384Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F384Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3889u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3889u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFD94u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F38BCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F38BCu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3938(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F397Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F397Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F39A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F39ADu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F39ADu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F39B1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A23(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF54u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000F3A44;
    lift_store32(cpu->ebp + 0xFFFFFF54u, (uint64_t)(lift_load32(cpu->ebp + 0xFFFFFF54u)) & (uint64_t)(0xFFFFFFFEu));
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFF58u);
    sfera_sub_004061B0(cpu, stop_address); return;
    label_000F3A44:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFEB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A7B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFE9Cu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A86(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFED4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B48(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3B54u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3B54u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B56(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF80u);
    sfera_sub_00406210(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F3B90u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3BC8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x19Cu;
    sfera_sub_00429AF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3C09u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3C09u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3C39u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3C39u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3C68;
    label_000BFB50:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BFB76;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFB6Bu)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4BFB6Bu));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFB73u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BFB73u));
    cpu->esp += 4u;
    label_000BFB76:
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3C68:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x1A0u;
    goto label_000BFB50;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CA8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3CEDu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3CEDu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3D1Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3D1Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3D6Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3D6Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D71(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3D7Eu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3D7Eu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3DD9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3DD9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DDB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DE3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3DE3;
    label_000C26D0:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C26F6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C26EBu)); sfera_sub_004C24B0(cpu, LIFT_CODE_TOKEN_VA(0x4C26EBu));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C26F3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C26F3u));
    cpu->esp += 4u;
    label_000C26F6:
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3DE3:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x210u;
    goto label_000C26D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3E1Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3E1Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3E49u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F3E49u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3ED8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3ED8;
    label_000183C0:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000183E6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4183DBu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4183DBu));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4183E3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4183E3u));
    cpu->esp += 4u;
    label_000183E6:
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3ED8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x198u;
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3F1Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3F1Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F21(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3F2Eu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3F2Eu));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3F5Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3F5Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F3F8Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F3F8Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FB8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3FB8;
    label_000183C0:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000183E6;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4183DBu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4183DBu));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4183E3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4183E3u));
    cpu->esp += 4u;
    label_000183E6:
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F3FB8:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    cpu->ecx += 0x198u;
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FC6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4008(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4049u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4049u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4078(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x1B8u;
    sfera_sub_004CF160(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4086(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x260u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F40B9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F40B9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40BB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F40C4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F40C4u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40C6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F40CFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F40CFu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD4u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41B8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x198u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41F8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx += 0x198u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4206(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F420Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F420Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4211(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F421Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F421Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4249u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4249u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F424B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4254u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4254u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4288(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F4288u), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F42B9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F42B9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F42E9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F42E9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42EB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F42F4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F42F4u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_control_reference_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_control_reference_registry_guard = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F435B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x54u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4366(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x70u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4371(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xA0u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F437F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xACu;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F438D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F438Du), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4396(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4396;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F4396:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xBCu;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43A4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x178u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}
