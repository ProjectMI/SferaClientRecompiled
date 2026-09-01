#include "lifted_functions.h"
#include <cmath>
#include <cstdio>
namespace lifted {

__declspec(noinline) void sfera_sub_004EB520(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if (cpu->esi == cpu->ebx) goto label_000EB884;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ebx;
    if (g_sfera_memory_runtime.lock_initialized != (cpu->ebx & 0xFFu)) goto label_000EB57A;
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB56Du));
    g_sfera_memory_runtime.lock_initialized = 1u;
    label_000EB57A:
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB57Fu));
    g_sfera_memory_runtime.lock_held = 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    if ((uint8_t)(g_sfera_memory_runtime.tracking_initialized) != 0u) goto label_000EB5BE;
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, (uintptr_t)"free2: test system not initialized"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = 0x1E4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB5BBu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB5BBu));
    cpu->esp += 8u;
    label_000EB5BE:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edx = 5u;
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB5D3u)); sfera_sub_004EB1D0(cpu, LIFT_CODE_TOKEN_VA(0x4EB5D3u));
    cpu->esi += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB5E4u)); sfera_sub_004EDDF0(cpu, LIFT_CODE_TOKEN_VA(0x4EB5E4u));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000EB61A;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, (uintptr_t)"Free of wrong pointer or double free. %s %d %d"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = 0xDBu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB612u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB612u));
    cpu->esp += 0x14u;
    goto label_000EB868;
    label_000EB61A:
    SphereUI::unbindEventHandler(reinterpret_cast<void*>(static_cast<std::uintptr_t>(cpu->esi + 4u)));
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->edx + 8u);
    cpu->esi = cpu->eax + cpu->edx + 4u;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->ebp + 0xBu) = *(uint32_t*)(cpu->ecx + cpu->eax + 4u) != 0x61CCC864u;
    if (*(uint32_t*)(cpu->eax) == 0x61CCC864u) goto label_000EB6DD;
    *(uint32_t*)(cpu->eax) = 0x61CCC864u;
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EB657:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EB657;
    cpu->eax -= cpu->edx;
    if ((int32_t)(--cpu->eax) < 0) goto label_000EB66C;
    label_000EB663:
    if (*(uint8_t*)(cpu->eax + cpu->edi) == 0x5Cu) goto label_000EB66C;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EB663;
    label_000EB66C:
    cpu->edx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = cpu->eax + cpu->edi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB68Eu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EB68Eu));
    cpu->ecx = (uintptr_t)"free: MEM CORRUPTED! ";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
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
    if (*(uint8_t*)(cpu->ebp + 0xBu) == 0u) goto label_000EB789;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + cpu->eax + 4u) = 0x61CCC864u;
    cpu->eax = cpu->edi;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EB700:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EB700;
    cpu->eax -= cpu->edx;
    if ((int32_t)(--cpu->eax) < 0) goto label_000EB719;
    label_000EB710:
    if (*(uint8_t*)(cpu->eax + cpu->edi) == 0x5Cu) goto label_000EB719;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EB710;
    label_000EB719:
    cpu->ecx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = cpu->eax + cpu->edi + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB73Bu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EB73Bu));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"free: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
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
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB797u)); sfera_sub_004EDE50(cpu, LIFT_CODE_TOKEN_VA(0x4EB797u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EB7C1;
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, (uintptr_t)"validate_and_remove_pointer: pointer not in hash"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = 0xE9u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB7BEu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB7BEu));
    cpu->esp += 8u;
    label_000EB7C1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (cpu->eax != g_sfera_memory_runtime.tracker_floor) goto label_000EB7D5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_floor = cpu->ecx;
    label_000EB7D5:
    if (cpu->eax != g_sfera_memory_runtime.tracker_ceiling) goto label_000EB7E6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_ceiling = cpu->edx;
    label_000EB7E6:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax == 0x3B9ACA00u) goto label_000EB802;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    *(uint32_t*)(cpu->eax + cpu->edx + 0x10u) = cpu->ecx;
    goto label_000EB80A;
    label_000EB802:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_primary = cpu->eax;
    label_000EB80A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->eax == 0x3B9ACA00u) goto label_000EB826;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    *(uint32_t*)(cpu->eax + cpu->edx + 0xCu) = cpu->ecx;
    goto label_000EB82E;
    label_000EB826:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    g_sfera_memory_runtime.tracker_auxiliary = cpu->eax;
    label_000EB82E:
    cpu->eax = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->eax &= 0x3FFu;
    --g_sfera_memory_runtime.bucket_allocations[cpu->eax];
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = (cpu->eax * 4u) + ((uintptr_t)g_sfera_memory_runtime.bucket_allocations);
    cpu->eax = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax &= 0x3FFu;
    g_sfera_memory_runtime.bucket_bytes[cpu->eax] = (uint64_t)(g_sfera_memory_runtime.bucket_bytes[cpu->eax]) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    --g_sfera_memory_runtime.live_allocation_count;
    cpu->eax = (cpu->eax * 4u) + ((uintptr_t)g_sfera_memory_runtime.bucket_bytes);
    label_000EB868:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x4EB869u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = 0u;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEB87Eu));
    label_000EB884:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EB8A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    cpu->edi = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edi;
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if (cpu->esi != cpu->ebx) goto label_000EB8FB;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB8E7u)); sfera_sub_004EB300(cpu, LIFT_CODE_TOKEN_VA(0x4EB8E7u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000EB8FB:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    if (g_sfera_memory_runtime.lock_initialized != (cpu->ebx & 0xFFu)) goto label_000EB91F;
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB912u));
    g_sfera_memory_runtime.lock_initialized = 1u;
    label_000EB91F:
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EB924u));
    g_sfera_memory_runtime.lock_held = 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    if ((uint8_t)(g_sfera_memory_runtime.tracking_initialized) != 0u) goto label_000EB95F;
    lift_push32(cpu, 0x1388u);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB94Cu)); sfera_sub_004EDD40(cpu, LIFT_CODE_TOKEN_VA(0x4EB94Cu));
    lift_push32(cpu, 0x32u);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB958u)); sfera_sub_004EDA60(cpu, LIFT_CODE_TOKEN_VA(0x4EB958u));
    g_sfera_memory_runtime.tracking_initialized = 1u;
    label_000EB95F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->edx = 5u;
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB977u)); sfera_sub_004EB1D0(cpu, LIFT_CODE_TOKEN_VA(0x4EB977u));
    if ((int32_t)cpu->edi > 0) goto label_000EB9A2;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"realloc2: Wrong size value. Size = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0x1FBu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB99Fu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB99Fu));
    cpu->esp += 0xCu;
    label_000EB9A2:
    cpu->esi += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB9B3u)); sfera_sub_004EDDF0(cpu, LIFT_CODE_TOKEN_VA(0x4EB9B3u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000EB9E5;
    cpu->ecx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"realloc2 with wrong pointer"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0xDEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EB9DDu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EB9DDu));
    cpu->esp += 8u;
    goto label_000EBC39;
    label_000EB9E5:
    cpu->eax = g_sfera_allocation_hash_runtime.records;
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->eax + 8u);
    cpu->esi = cpu->edx + cpu->eax + 4u;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->ebp + 0xFu) = *(uint32_t*)(cpu->eax + cpu->ecx + 4u) != 0x61CCC864u;
    if (*(uint32_t*)(cpu->eax) == 0x61CCC864u) goto label_000EBAAC;
    *(uint32_t*)(cpu->eax) = 0x61CCC864u;
    cpu->eax = cpu->ebx;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000EBA23:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EBA23;
    cpu->eax -= cpu->edx;
    if ((int32_t)(--cpu->eax) < 0) goto label_000EBA39;
    (void)cpu;
    label_000EBA30:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) == 0x5Cu) goto label_000EBA39;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EBA30;
    label_000EBA39:
    cpu->edx = g_sfera_diagnostic_log_byte;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = cpu->eax + cpu->ebx + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBA5Eu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EBA5Eu));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"realloc: MEM CORRUPTED! ";
    lift_push32(cpu, (uintptr_t)" (underflow). "); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
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
    if (*(uint8_t*)(cpu->ebp + 0xFu) == 0u) goto label_000EBB5D;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->ebx;
    *(uint32_t*)(cpu->ecx + cpu->edx + 4u) = 0x61CCC864u;
    g_sfera_memory_runtime.diagnostics_dirty = 1u;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_000EBAD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EBAD0;
    cpu->eax -= cpu->edx;
    if ((int32_t)(--cpu->eax) < 0) goto label_000EBAE9;
    label_000EBAE0:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) == 0x5Cu) goto label_000EBAE9;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EBAE0;
    label_000EBAE9:
    cpu->ecx = g_sfera_diagnostic_log_byte;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"\n"); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" ");
    cpu->eax = cpu->eax + cpu->ebx + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)". ");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB0Eu)); sfera_sub_004EA990(cpu, LIFT_CODE_TOKEN_VA(0x4EBB0Eu));
    cpu->ecx = (uintptr_t)"realloc: MEM CORRUPTED! ";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" (overflow). "); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
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
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB6Bu)); sfera_sub_004EDE50(cpu, LIFT_CODE_TOKEN_VA(0x4EBB6Bu));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EBB95;
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"validate_and_remove_pointer: pointer not in hash"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0xE9u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBB92u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EBB92u));
    cpu->esp += 8u;
    label_000EBB95:
    if (cpu->edi != g_sfera_memory_runtime.tracker_floor) goto label_000EBBA6;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_floor = cpu->ecx;
    label_000EBBA6:
    if (cpu->edi != g_sfera_memory_runtime.tracker_ceiling) goto label_000EBBB7;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_ceiling = cpu->edx;
    label_000EBBB7:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax == 0x3B9ACA00u) goto label_000EBBD3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    *(uint32_t*)(cpu->eax + cpu->edx + 0x10u) = cpu->ecx;
    goto label_000EBBDB;
    label_000EBBD3:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    g_sfera_memory_runtime.tracker_primary = cpu->eax;
    label_000EBBDB:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->eax == 0x3B9ACA00u) goto label_000EBBF7;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = g_sfera_allocation_hash_runtime.records;
    *(uint32_t*)(cpu->eax + cpu->edx + 0xCu) = cpu->ecx;
    goto label_000EBBFF;
    label_000EBBF7:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    g_sfera_memory_runtime.tracker_auxiliary = cpu->eax;
    label_000EBBFF:
    cpu->eax = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->eax &= 0x3FFu;
    --g_sfera_memory_runtime.bucket_allocations[cpu->eax];
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = (cpu->eax * 4u) + ((uintptr_t)g_sfera_memory_runtime.bucket_allocations);
    cpu->eax = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax &= 0x3FFu;
    g_sfera_memory_runtime.bucket_bytes[cpu->eax] = (uint64_t)(g_sfera_memory_runtime.bucket_bytes[cpu->eax]) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    --g_sfera_memory_runtime.live_allocation_count;
    cpu->eax = (cpu->eax * 4u) + ((uintptr_t)g_sfera_memory_runtime.bucket_bytes);
    label_000EBC39:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = cpu->edi + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EBC41u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi != 0u) goto label_000EBC77;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"realloc2: Not enough memory. Request size = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0x203u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBC74u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EBC74u));
    cpu->esp += 0xCu;
    label_000EBC77:
    cpu->ecx = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi) = 0x61CCC864u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_allocation_hash_runtime;
    *(uint32_t*)(cpu->esi + cpu->edi + 4u) = 0x61CCC864u;
    *(uint32_t*)(cpu->ebp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBC9Bu)); sfera_sub_004EDEF0(cpu, LIFT_CODE_TOKEN_VA(0x4EBC9Bu));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_000EBCC7;
    cpu->edx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, (uintptr_t)"store_pointer: pointer already in hash"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = (uintptr_t)"Memory\\MemoryMgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = 0xFEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBCC4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EBCC4u));
    cpu->esp += 8u;
    label_000EBCC7:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uintptr_t)&g_sfera_memory_source_hash_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBCD2u)); sfera_sub_004EDC70(cpu, LIFT_CODE_TOKEN_VA(0x4EBCD2u));
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = cpu->eax & 0xFFFFu;
    if (cpu->edx == 0x3B9ACA00u) goto label_000EBCFB;
    cpu->ebx = g_sfera_allocation_hash_runtime.records;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1Au);
    *(uint32_t*)(cpu->edx + cpu->ebx + 0xCu) = cpu->edi;
    cpu->edx = g_sfera_memory_runtime.tracker_primary;
    goto label_000EBD01;
    label_000EBCFB:
    g_sfera_memory_runtime.tracker_auxiliary = cpu->edi;
    label_000EBD01:
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = 0x3B9ACA00u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint16_t*)(cpu->edx + 0x14u) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax &= 0x3FFu;
    g_sfera_memory_runtime.tracker_primary = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->edi;
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->eax + cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_bytes)) = (uint64_t)(*(uint32_t*)(cpu->eax + cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_bytes))) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->eax += cpu->eax;
    cpu->edx = 1u;
    *(uint32_t*)(cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_allocations)) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uintptr_t)g_sfera_memory_runtime.bucket_allocations))) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    g_sfera_memory_runtime.live_allocation_count = (uint64_t)(g_sfera_memory_runtime.live_allocation_count) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = 0u;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBD5Cu));
    cpu->eax = cpu->esi + 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EBD80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    if ((uint8_t)(g_sfera_memory_runtime.lock_initialized) != 0u) goto label_000EBDC7;
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBDBAu));
    g_sfera_memory_runtime.lock_initialized = 1u;
    label_000EBDC7:
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::TryEnterCriticalSection), LIFT_CODE_TOKEN_VA(0x4EBDCCu));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if (cpu->eax != 1u) goto label_000EBE07;
    if (g_sfera_memory_runtime.lock_held != 0u) goto label_000EBDFC;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"verify before terminate"); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEBDFCu)); sfera_sub_004EAA20(cpu, LIFT_CODE_TOKEN_RVA(0xEBDFCu));
    label_000EBDFC:
    lift_push32(cpu, (uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEBE01u));
    label_000EBE07:
    cpu->ecx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EBE20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->ecx == 0u) goto label_000EBE4F;
    cpu->eax = g_sfera_memory_runtime.allocation_source_line;
    cpu->edx = g_sfera_memory_runtime.allocation_source_file;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBE3Bu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4EBE3Bu));
    g_sfera_memory_runtime.allocation_source_file = (uintptr_t)"Unknown";
    g_sfera_memory_runtime.allocation_source_line = 0u;
    label_000EBE4F:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EBE60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBE6Fu)); sfera_sub_004EB300(cpu, LIFT_CODE_TOKEN_VA(0x4EBE6Fu));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EBE80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBE92u)); sfera_sub_004EB8A0(cpu, LIFT_CODE_TOKEN_VA(0x4EBE92u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EBEA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = g_sfera_memory_runtime.allocation_source_line;
    cpu->ecx = g_sfera_memory_runtime.allocation_source_file;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
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
    g_sfera_memory_runtime.allocation_source_file = (uintptr_t)"Unknown";
    g_sfera_memory_runtime.allocation_source_line = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EBF40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = 0x1204u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBF4Du)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x4EBF4Du));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x14u;
    cpu->ecx = cpu->ebp + 0xFFFFEE0Cu;
    *(uint32_t*)(cpu->ebp + 0xFFFFEDFCu) = (uintptr_t)"stackdump.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFEE00u) = (uintptr_t)"errorsmgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFEE04u) = (uintptr_t)"crt0.c";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBF86u)); sfera_sub_004EE2C0(cpu, LIFT_CODE_TOKEN_VA(0x4EBF86u));
    *(uint8_t*)(cpu->ebp + 0xFFFFF6CCu) = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_000EC06D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ebp + 0xFFFFEE30u;
    *(uint32_t*)(cpu->ebp + 0xFFFFEE08u) = cpu->eax;
    label_000EBFA4:
    cpu->esi = 0u;
    cpu->edi = cpu->ebx + 0xFFFFFFDCu;
    label_000EBFB0:
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->esi * 4u) + 0xFFFFEDFCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4EBFB9u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000EBFCE;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)3u) goto label_000EBFB0;
    goto label_000EBFD3;
    label_000EBFCE:
    if ((int32_t)cpu->esi < (int32_t)3u) goto label_000EC026;
    label_000EBFD3:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x44u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"(%s:%u)\t(%hs+%I64X)\n");
    cpu->ecx = cpu->ebp + 0xFFFFFF8Cu;
    lift_push32(cpu, 0x6Fu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EBFECu));
    cpu->eax = cpu->ebp + 0xFFFFFF8Cu;
    cpu->esp += 0x20u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    cpu->esi = cpu->eax;
    label_000EC000:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC000;
    cpu->edi = cpu->ebp + 0xFFFFF6CCu;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000EC010:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000EC010;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    label_000EC026:
    cpu->ebx += 0x70u;
    if ((--*(uint32_t*)(cpu->ebp + 0xFFFFEE08u)) != 0u) goto label_000EBFA4;
    sub_pred[0] = *(uint8_t*)(cpu->ebp + 0xFFFFF6CCu) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000EC06D;
    cpu->edx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFF6CCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Stack:\n");
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC05Fu)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EC05Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC066u)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x4EC066u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC06Du)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0xEC06Du));
    label_000EC06D:
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC07Bu)); sfera_sub_00434D50(cpu, LIFT_CODE_TOKEN_RVA(0xEC07Bu));
    label_000EC07D:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC090(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"critLogTmp.$$$"); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0ADu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000EC1A6;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x8000u); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0C9u));
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_000EC0ED;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0DFu));
    cpu->esp += 8u;
    goto label_000EC1A6;
    label_000EC0ED:
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0F8u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000EC11F;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4EC10Au));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC116u));
    cpu->esp += 0xCu;
    label_000EC11F:
    cpu->eax = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC126u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4EC126u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_000EC189;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = 0u - (uint64_t)(cpu->edi);
    label_000EC140:
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4EC144u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000EC189;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4EC158u));
    cpu->esp += 0xCu;
    if (cpu->eax != cpu->esi) goto label_000EC189;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4EC16Eu));
    cpu->esp += 0xCu;
    if (cpu->eax != cpu->esi) goto label_000EC189;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    ++cpu->eax;
    cpu->edi += cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebp + 8u)) goto label_000EC140;
    label_000EC189:
    cpu->esi = native_function_address32(&::_close);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4EC19Du));
    cpu->esp += 0xCu;
    label_000EC1A6:
    cpu->esp = cpu->ebp + 0xFFFFFFE4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC1E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = (uintptr_t)"Criticals.log";
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC202u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000EC2CC;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::fputs);
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000EC273;
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC224u));
    cpu->edx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC22Eu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC240u));
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC258u));
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->ecx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0x38u;
    label_000EC273:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(cpu->edx, cpu->esi);

    if (*(uint8_t*)(cpu->ebp + 8u) == 0u) goto label_000EC28E;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))((uintptr_t)"\n", cpu->esi);

    label_000EC28E:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4EC28Fu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4EC296u));
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4EC29Fu));
    cpu->esp += 0xCu;
    if (*(uint8_t*)(cpu->ebp + 0xCu) == 0u) goto label_000EC2CB;
    if ((int32_t)cpu->edi <= (int32_t)0x108000u) goto label_000EC2CB;
    cpu->ecx = (uintptr_t)"Criticals.log";
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
__declspec(noinline) void sfera_sub_004EC2E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x83Cu;
    cpu->eax = g_sfera_critical_diagnostics_runtime.processing_depth;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->edi);
    g_sfera_critical_diagnostics_runtime.processing_depth = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->esi) goto label_000EC3D0;
    if (cpu->eax != 2u) goto label_000EC3C1;
    cpu->eax = (uintptr_t)"Criticals.log";
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC322u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000EC3BC;
    cpu->ecx = cpu->ebp + 0xFFFFF7C4u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC33Cu));
    cpu->edx = cpu->ebp + 0xFFFFF7C4u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC349u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC35Bu));
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC373u));
    cpu->edi = native_function_address32(&::fputs);
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->ecx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Error processing reenter. Terminating");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
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
    g_sfera_critical_diagnostics_runtime.serial_number = cpu->eax;
    if (cpu->eax != 0x3E8u) goto label_000EC3ED;
    g_sfera_critical_diagnostics_runtime.serial_number = 0u;
    label_000EC3ED:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = cpu->ebp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, 0x800u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x4EC401u));
    cpu->edi = cpu->ebp + 0xFFFFF7CCu;
    cpu->esp += 0x10u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFCBu) = 0u;
    --cpu->edi;
    label_000EC415:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EC415;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    if (cpu->eax == 0u) goto label_000EC4D4;
    if ((cpu->eax -= cpu->esi) == 0u) goto label_000EC47D;
    if ((cpu->eax -= cpu->esi) != 0u) goto label_000EC4E9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC451u)); sfera_sub_004EC1E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC451u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC466u)); sfera_sub_004ED100(cpu, LIFT_CODE_TOKEN_VA(0x4EC466u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC46Du)); sfera_sub_004EBF40(cpu, LIFT_CODE_TOKEN_VA(0x4EC46Du));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    cpu->eax = sfera_client_critical_error(reinterpret_cast<const char*>(static_cast<uintptr_t>(cpu->ecx)), cpu->edx);
    goto label_000EC4B9;
    label_000EC47D:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC492u)); sfera_sub_004ED100(cpu, LIFT_CODE_TOKEN_VA(0x4EC492u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC499u)); sfera_sub_004EBF40(cpu, LIFT_CODE_TOKEN_VA(0x4EC499u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    cpu->eax = sfera_client_critical_error(reinterpret_cast<const char*>(static_cast<uintptr_t>(cpu->ecx)), cpu->edx);
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EC4E9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = (uintptr_t)"terminating cause of LERROR";
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
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_log_warnings_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC4E9u)); sfera_sub_004ED100(cpu, LIFT_CODE_TOKEN_RVA(0xEC4E9u));
    label_000EC4E9:
    g_sfera_critical_diagnostics_runtime.processing_depth = (uint64_t)(g_sfera_critical_diagnostics_runtime.processing_depth) - (uint64_t)(cpu->esi) - (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC500(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esi;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->ebx;
    cpu->eax >>= 3u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC547u)); sfera_sub_004EE390(cpu, LIFT_CODE_TOKEN_VA(0x4EC547u));
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0x14u) == 0u; sub_pred[1] = (int32_t)(*(uint32_t*)(cpu->ebp + 0x14u)) < (int32_t)(0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if ((sub_pred[0]) || (sub_pred[1])) goto label_000EC583;
    if ((((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_000EC583;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE4u;
    lift_push32(cpu, (uintptr_t)"Log::Log: trunc log %s and dayly files are mutualy exclusive capabilities."); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = (uintptr_t)"Logs\\Log.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0x1Fu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC580u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC580u));
    cpu->esp += 0xCu;
    label_000EC583:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->eax + 1u;
    label_000EC590:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC590;
    cpu->ebx = native_function_address32(&::malloc);
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax + 1u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::malloc)))(cpu->edi);

    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EC5D6;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp + 0xFFFFFFE4u;
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = (uintptr_t)"Logs\\Log.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0x23u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC5D3u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC5D3u));
    cpu->esp += 0xCu;
    label_000EC5D6:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    label_000EC5E0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EC5E0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->eax != 0u) goto label_000EC5F6;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    goto label_000EC650;
    label_000EC5F6:
    cpu->edx = cpu->eax + 1u;
    label_000EC600:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC600;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax + 1u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::malloc)))(cpu->edi);

    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EC640;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->ebp + 0xFFFFFFE4u;
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = (uintptr_t)"Logs\\Log.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0x2Du;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC63Du)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC63Du));
    cpu->esp += 0xCu;
    label_000EC640:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    label_000EC646:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EC646;
    label_000EC650:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x18u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0x1F4u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::malloc)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EC6A3;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp + 0xFFFFFFE4u;
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = (uintptr_t)"Logs\\Log.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0x38u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC6A0u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC6A0u));
    cpu->esp += 0xCu;
    label_000EC6A3:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax = 0u;
    *(uint8_t*)(cpu->edx) = 0u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x14u) > (int32_t)cpu->eax) goto label_000EC6BB;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    goto label_000EC6F7;
    label_000EC6BB:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::malloc)))(0x2000u);

    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EC6F7;
    lift_push32(cpu, 0x2000u);
    cpu->eax = cpu->ebp + 0xFFFFFFE4u;
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = (uintptr_t)"Logs\\Log.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0x43u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC6F4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC6F4u));
    cpu->esp += 0xCu;
    label_000EC6F7:
    if (((*(uint8_t*)(cpu->ebp + 0x10u)) & (8u)) == 0u) goto label_000EC73A;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::malloc)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EC734;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp + 0xFFFFFFE4u;
    lift_push32(cpu, (uintptr_t)"Log::Log: Not enough memory. Len = %d"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = (uintptr_t)"Logs\\Log.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0x4Bu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC731u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC731u));
    cpu->esp += 0xCu;
    label_000EC734:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint8_t*)(cpu->edx) = 0u;
    label_000EC73A:
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->eax = g_sfera_critical_diagnostics_runtime.log_chain_head;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    g_sfera_critical_diagnostics_runtime.log_chain_head = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000EC757;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    label_000EC757:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->esp -= 0x10u;
    cpu->edx = cpu->eax + 1u;
    label_000EC780:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC780;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_000EC7A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC7A0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->esi = cpu->ebx + cpu->esi + 1u;
    if ((int32_t)cpu->esi <= (int32_t)*(uint32_t*)(cpu->ecx)) goto label_000EC7FA;
    cpu->eax = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EC7BFu));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EC7FA;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFF0u;
    lift_push32(cpu, (uintptr_t)"Log::append_realloc(): Not enough memory. Len = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = (uintptr_t)"Logs\\Log.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = 0x127u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC7F7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC7F7u));
    cpu->esp += 0xCu;
    label_000EC7FA:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4EC807u));
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + cpu->esi + 0xFFFFFFFFu) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC830(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    label_000EC850:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC850;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax + 1u;
    cpu->eax = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC863u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4EC863u));
    cpu->esi = cpu->esp;
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->esi;
    label_000EC870:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EC870;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + cpu->edi + 0xFFFFFFFEu) = 0x24u;
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x4EC885u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4EC88Cu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC89Au));
    cpu->esp += 0x14u;
    cpu->esp = cpu->ebp + 0xFFFFFFECu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = cpu->ebp + 0xFFFFFFD4u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC8DBu));
    cpu->ecx = cpu->ebp + 0xFFFFFFD4u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC8E5u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"_%y%m%d");
    cpu->edx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC8F7u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->esp += 0x18u;
    cpu->edx = 0u;
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_000EC923;
    label_000EC910:
    if ((cpu->eax & 0xFFu) == 0u) goto label_000EC923;
    *(uint8_t*)(cpu->edi) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + cpu->ecx + 1u));
    ++cpu->edx;
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0x2Eu) goto label_000EC910;
    label_000EC923:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    cpu->ebx = cpu->edi;
    cpu->ecx = cpu->eax;
    cpu->ebx -= cpu->ecx;
    label_000EC930:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->ebx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC930;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_000EC942:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000EC942;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000EC950:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000EC950;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x84u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->eax != 0u) goto label_000EC9BC;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx = cpu->eax + 1u;
    label_000EC9A3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC9A3;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EC9BC:
    cpu->edx = 0x80u;
    cpu->ecx = cpu->ebp + 0xFFFFFF7Cu;
    *(uint8_t*)(cpu->ebp + 0xFFFFFF7Cu) = 0u;
    std::snprintf(reinterpret_cast<char*>(static_cast<uintptr_t>(cpu->ecx)), cpu->edx, "%u ", g_sfera_critical_diagnostics_runtime.serial_number);
    *(uint8_t*)(cpu->ecx + cpu->edx - 1u) = 0u;
    cpu->eax = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC9E6u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4EC9E6u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ECA00(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->edx&=0x1FFFu;
    cpu->esi = cpu->edx + cpu->eax;
    cpu->esi = (int32_t)(cpu->esi) >> 13u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->esi <= 0) goto label_000ECA7F;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->esi;
    label_000ECA30:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4ECA37u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000ECA73;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x18u);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4ECA4Fu));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000ECA73;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4ECA6Au));
    cpu->esp += 0xCu;
    label_000ECA73:
    *(uint32_t*)(cpu->ebp + 0xCu) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0xCu)) + (uint64_t)(0x2000u) + (uint64_t)(0u);
    if ((--*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu)) != 0u) goto label_000ECA30;
    label_000ECA7F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->eax&=0x80001FFFu; lift_test[0]=cpu->eax==0u;
    if (((cpu->eax)&0x80000000u)==0u) goto label_000ECA90;
    --cpu->eax;
    cpu->eax|=0xFFFFE000u;
    ++cpu->eax; lift_test[0]=cpu->eax == 0u;
    label_000ECA90:
    *(uint32_t*)(cpu->ebp + 0x14u) = cpu->eax;
    if (lift_test[0]) goto label_000ECAD6;
    cpu->esi <<= 13u;
    cpu->esi += *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4ECA9Fu));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000ECAD6;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x18u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4ECAB6u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000ECAD6;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4ECACDu));
    cpu->esp += 0xCu;
    label_000ECAD6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ECAE0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_test[0]=(*(uint8_t*)(cpu->esi + 0x10u)&2u)==0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (lift_test[0]) goto label_000ECB1C;
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_000ECB01:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000ECB01;
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
    if (cpu->edi == 0u) goto label_000ECB93;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4ECB36u));
    cpu->esp += 8u;
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (4u)) == 0u) goto label_000ECB4F;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4ECB46u));
    cpu->esp += 4u;
    label_000ECB4F:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x14u) <= (int32_t)0u) goto label_000ECB89;
    ++*(uint32_t*)(cpu->esi + 0x1Cu);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1Cu) < (int32_t)0x1F4u) goto label_000ECB89;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0u;
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4ECB69u));
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4ECB72u));
    cpu->esp += 8u;
    if ((int32_t)cpu->ebx <= (int32_t)*(uint32_t*)(cpu->esi + 0x14u)) goto label_000ECB93;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECB87u)); sfera_sub_004EC830(cpu, LIFT_CODE_TOKEN_VA(0x4ECB87u));
    goto label_000ECB93;
    label_000ECB89:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4ECB8Au));
    cpu->esp += 4u;
    label_000ECB93:
    cpu->esp = cpu->ebp + 0xFFFFFFF0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ECBB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x18u) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_000ECE61;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = cpu->eax + 1u;
    label_000ECBD5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000ECBD5;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax + 1u;
    cpu->eax = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECBEBu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4ECBEBu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ebx;
    cpu->edx = cpu->ebx;
    label_000ECBF5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000ECBF5;
    lift_push32(cpu, 0u);
    *(uint8_t*)(cpu->ebx + cpu->edi + 0xFFFFFFFEu) = 0x24u;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECC0Fu));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000ECC24;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    goto label_000ECC3E;
    label_000ECC24:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x4ECC25u));
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECC2Fu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    label_000ECC3E:
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECC46u));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000ECC5B;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_000ECC7A;
    label_000ECC5B:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x4ECC5Cu));
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECC66u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000ECC91;
    label_000ECC7A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000ECE61;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 0x14u)) goto label_000ECE61;
    goto label_000ECC94;
    label_000ECC91:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    label_000ECC94:
    if (cpu->eax != 0xFFFFFFFFu) goto label_000ECCA9;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECC9Eu));
    goto label_000ECE5E;
    label_000ECCA9:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECCB1u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4ECCB1u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    cpu->edx = cpu->ebx;
    label_000ECCC0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000ECCC0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint16_t*)(cpu->ebx + cpu->eax + 0xFFFFFFFDu) = 0x2424u;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECCD9u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000ECE61;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECCF8u));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000ECD34;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECD0Cu));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECD17u));
    cpu->esp += 0xCu;
    cpu->esp = cpu->ebp + 0xFFFFFFDCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ECD34:
    cpu->ebx |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) == cpu->ebx) goto label_000ECD8D;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECD47u));
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_000ECD8D;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4ECD58u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECD62u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECD70u));
    cpu->esp += 0x10u;
    cpu->esp = cpu->ebp + 0xFFFFFFDCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ECD8D:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4ECD98u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000ECDE4;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_close);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4ECDB9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4ECDC7u));
    cpu->esp += 0x14u;
    cpu->esp = cpu->ebp + 0xFFFFFFDCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ECDE4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    if ((int32_t)cpu->edx < (int32_t)cpu->ecx) goto label_000ECDF4;
    lift_push32(cpu, cpu->ecx);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    goto label_000ECE29;
    label_000ECDF4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_000ECE26;
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->edx <= (int32_t)*(uint32_t*)(cpu->esi + 0x14u)) goto label_000ECE14;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x14u);
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
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    label_000ECE26:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    label_000ECE29:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECE32u)); sfera_sub_004ECA00(cpu, LIFT_CODE_TOKEN_VA(0x4ECE32u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_close);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = native_function_address32(&::remove);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0xCu;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_000ECE61;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    label_000ECE5E:
    cpu->esp += 8u;
    label_000ECE61:
    cpu->esp = cpu->ebp + 0xFFFFFFDCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ECE80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    sub_pred[0] = *(uint8_t*)(cpu->edi) == 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->ecx;
    if (sub_pred[0]) goto label_000ECF41;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x14u);
    *(uint8_t*)(cpu->edi) = 1u;
    if (cpu->eax != 1u) goto label_000ECEB6;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    goto label_000ECF3C;
    label_000ECEB6:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"[%d] ");
    cpu->ecx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4ECEC2u));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->esp += 0x10u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    cpu->edx = cpu->eax + 1u;
    label_000ECED5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000ECED5;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    cpu->esi = cpu->eax + 1u;
    label_000ECEE6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000ECEE6;
    cpu->eax -= cpu->esi;
    cpu->eax = cpu->eax + cpu->edx + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECEF8u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4ECEF8u));
    cpu->ebx = cpu->esp;
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    cpu->edx -= cpu->ecx;
    label_000ECF03:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000ECF03;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = cpu->eax;
    label_000ECF12:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000ECF12;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->ebx + 0xFFFFFFFFu;
    label_000ECF20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000ECF20;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ebx);
    label_000ECF3C:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xECF41u)); sfera_sub_004ECAE0(cpu, LIFT_CODE_TOKEN_RVA(0xECF41u));
    label_000ECF41:
    cpu->esp = cpu->ebp + 0xFFFFFFCCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ECF60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (*(uint8_t*)(cpu->eax) == 0u) goto label_000ECFD5;
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) != 0u) goto label_000ECF79;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF77u)); sfera_sub_004ECAE0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF77u));
    goto label_000ECFC3;
    label_000ECF79:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF86u)); sfera_sub_004EE5D0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF86u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000ECFC2;
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF92u)); sfera_sub_004EE4C0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF92u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000ECFA6;
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECF9Eu)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ECF9Eu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xECFA6u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_RVA(0xECFA6u));
    label_000ECFA6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ECFB6u)); sfera_sub_004EE690(cpu, LIFT_CODE_TOKEN_VA(0x4ECFB6u));
    if (cpu->eax == 0u) goto label_000ECFC2;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xECFC2u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_RVA(0xECFC2u));
    label_000ECFC2:
    cpu->edi = lift_pop32(cpu);
    label_000ECFC3:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    *(uint8_t*)(cpu->eax) = 0u;
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ECFD5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint8_t*)(cpu->ecx) = 0u;
    label_000ECFD5:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ECFE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0xCu) != 0u) goto label_000ED00D;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED00D:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = cpu->edi;
    if (*(uint8_t*)(cpu->edi) == 0u) goto label_000ED0DB;
    label_000ED020:
    if (*(uint8_t*)(cpu->edi) != 0x24u) goto label_000ED0D1;
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = cpu->esi + 0x28u;
    cpu->eax = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->edi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED03Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED03Cu));
    *(uint8_t*)(cpu->edi) = 0x24u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    if ((cpu->ecx & 0xFFu) == 0u) goto label_000ED0EB;
    if ((cpu->ecx & 0xFFu) != 0x64u) goto label_000ED08F;
    cpu->eax = cpu->ebp + 0xFFFFFFD4u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED053u));
    cpu->ecx = cpu->ebp + 0xFFFFFFD4u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED05Du));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->edx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED06Fu));
    cpu->esp += 0x18u;
    cpu->eax = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED088u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED088u));
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED08F:
    if ((cpu->ecx & 0xFFu) != 0x74u) goto label_000ED0B8;
    cpu->ecx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED098u));
    cpu->esp += 4u;
    cpu->edx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED0B1u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED0B1u));
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED0B8:
    if ((cpu->ecx & 0xFFu) != 0x75u) goto label_000ED0CA;
    if (*(uint32_t*)(cpu->esi + 0x20u) == 0u) goto label_000ED0CA;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED0CAu)); sfera_sub_004EC980(cpu, LIFT_CODE_TOKEN_RVA(0xED0CAu));
    label_000ED0CA:
    cpu->edi += 2u;
    cpu->ecx = cpu->edi;
    goto label_000ED0D2;
    label_000ED0D1:
    ++cpu->edi;
    label_000ED0D2:
    if (*(uint8_t*)(cpu->edi) != 0u) goto label_000ED020;
    label_000ED0DB:
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED0EBu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED0EBu));
    label_000ED0EB:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED100(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED10Bu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED10Bu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED112u)); sfera_sub_004ECFE0(cpu, LIFT_CODE_TOKEN_VA(0x4ED112u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED125u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED125u));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED13E;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED13Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED13Eu));
    label_000ED13E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED145u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED145u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_critical_diagnostics_runtime.log_chain_head;
    if (cpu->esi == 0u) goto label_000ED196;
    lift_push32(cpu, cpu->edi);
    label_000ED160:
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED18E;
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED16Eu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED16Eu));
    if ((int32_t)cpu->eax <= 0) goto label_000ED18E;
    label_000ED172:
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED17Au)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED17Au));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED182u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED182u));
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED18Au)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED18Au));
    if ((int32_t)cpu->eax > 0) goto label_000ED172;
    label_000ED18E:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->esi != 0u) goto label_000ED160;
    cpu->edi = lift_pop32(cpu);
    label_000ED196:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED380(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED385u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED385u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED390(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    sub_pred[0] = *(uint8_t*)(cpu->eax) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x24u;
    if (!sub_pred[0]) goto label_000ED3B4;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED3B4u)); sfera_sub_004ECFE0(cpu, LIFT_CODE_TOKEN_RVA(0xED3B4u));
    label_000ED3B4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d");
    cpu->edx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4ED3C3u));
    cpu->esp += 0x10u;
    cpu->eax = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED3E0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED3E0u));
    if ((int32_t)cpu->eax <= (int32_t)0x800u) goto label_000ED3EE;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED3EEu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED3EEu));
    label_000ED3EE:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED410(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    sub_pred[0] = *(uint8_t*)(cpu->eax) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x24u;
    if (!sub_pred[0]) goto label_000ED427;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED427u)); sfera_sub_004ECFE0(cpu, LIFT_CODE_TOKEN_RVA(0xED427u));
    label_000ED427:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED438u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED438u));
    lift_test[0]=(*(uint8_t*)(cpu->esi + 0x10u)&8u)==0u;
    cpu->edi = cpu->eax;
    if (lift_test[0]) goto label_000ED450;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED450u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED450u));
    label_000ED450:
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)cpu->edi <= (int32_t)0x800u) goto label_000ED460;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED460u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED460u));
    label_000ED460:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = 0u;
    cpu->edx=0u;
    label_000ED474:
    cpu->eax = cpu->edx;
    cpu->ecx >>= 1u;
    cpu->eax >>= 1u;
    if (((cpu->edx & 0xFFu)&1u)==0u) goto label_000ED48A;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    label_000ED48A:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000ED49F;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000ED4A1;
    label_000ED49F:
    cpu->eax >>= 1u;
    label_000ED4A1:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000ED4B6;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000ED4B8;
    label_000ED4B6:
    cpu->eax >>= 1u;
    label_000ED4B8:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000ED4CD;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000ED4CF;
    label_000ED4CD:
    cpu->eax >>= 1u;
    label_000ED4CF:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000ED4E4;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000ED4E6;
    label_000ED4E4:
    cpu->eax >>= 1u;
    label_000ED4E6:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000ED4FB;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000ED4FD;
    label_000ED4FB:
    cpu->eax >>= 1u;
    label_000ED4FD:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000ED512;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000ED514;
    label_000ED512:
    cpu->eax >>= 1u;
    label_000ED514:
    cpu->ecx >>= 1u;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000ED520;
    cpu->ecx ^= 0xEDB88320u;
    label_000ED520:
    g_sfera_string_lookup_runtime.hash_mix[(uint8_t)cpu->edx] = cpu->ecx & 0xFFFFu;
    ++cpu->edx;
    if ((int32_t)(cpu->edx) < (int32_t)(0x100u)) goto label_000ED474;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED5C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000ED5C0;
    label_000ED540:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    std::memmove((void*)(cpu->ebp + 0xFFFFFFE0u),(void*)((uintptr_t)"QWERTYUIOPASDFGHJKLZXCVBNM"),27u);
    std::memmove((void*)(cpu->ebp + 0xFFFFFFC4u),(void*)((uintptr_t)"qwertyuiopasdfghjklzxcvbnm"),27u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    label_000ED580:
    g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax] = cpu->eax & 0xFFu;
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x100u) goto label_000ED580;
    cpu->eax = 0u;
    label_000ED590:
    cpu->ecx = *(uint8_t*)(cpu->ebp + cpu->eax + 0xFFFFFFE0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + cpu->eax + 0xFFFFFFC4u));
    ++cpu->eax;
    g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx] = cpu->edx & 0xFFu;
    if (cpu->eax < 0x1Bu) goto label_000ED590;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED5C0:
    if ((uint32_t)(g_sfera_string_lookup_runtime.initialized) != 0u) goto label_000ED5DD;
    g_sfera_string_lookup_runtime.initialized = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED5D8u)); sfera_sub_004ED470(cpu, LIFT_CODE_TOKEN_VA(0x4ED5D8u));
    goto label_000ED540;
    label_000ED5DD:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED5E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x14u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"operator[]: out of range. Size=%d, Index=%d"); lift_push32(cpu, 1u); lift_push32(cpu, 0x13u); lift_push32(cpu, (uintptr_t)"Containers\\Containers.cpp");
    cpu->ecx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED60Au)); sfera_sub_004013B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED60Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED610u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED610u));
    cpu->esp += 0x10u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED631u)); sfera_sub_004ED5C0(cpu, LIFT_CODE_TOKEN_VA(0x4ED631u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFFu) = cpu->edx & 0xFFu;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ebp + 0xFFFFFFFFu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x4ED644u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000ED6ED;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->ebp + 0xFFFFFFFFu));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx]);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFFu) = cpu->edx & 0xFFu;
    goto label_000ED66D;
    label_000ED664:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    label_000ED66D:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->ecx));
    if (cpu->edx == 0u) goto label_000ED6EB;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->ecx]);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ebp + 0xFFFFFFFFu));
    if (cpu->edx != cpu->eax) goto label_000ED6E6;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    goto label_000ED6B2;
    label_000ED6A0:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    label_000ED6B2:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx));
    if (cpu->eax != 0u) goto label_000ED6C4;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    goto label_000ED76B;
    label_000ED6C4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->ecx));
    cpu->eax = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->ecx));
    cpu->ecx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]);
    if (cpu->eax == cpu->ecx) goto label_000ED6E4;
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
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edx;
    label_000ED6F8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax));
    if (cpu->ecx == 0u) goto label_000ED769;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->ebp + 0xFFFFFFFFu));
    if (cpu->eax != cpu->ecx) goto label_000ED767;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->eax += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    goto label_000ED736;
    label_000ED724:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx += 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    label_000ED736:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax));
    if (cpu->ecx != 0u) goto label_000ED745;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    goto label_000ED76B;
    label_000ED745:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ecx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax]);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->edx = (int8_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->eax]);
    if (cpu->ecx == cpu->edx) goto label_000ED765;
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
__declspec(noinline) void sfera_sub_004ED770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 0x17u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED785u)); sfera_sub_004EB300(cpu, LIFT_CODE_TOKEN_VA(0x4ED785u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED790(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED7A9u)); sfera_sub_004EB8A0(cpu, LIFT_CODE_TOKEN_VA(0x4ED7A9u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED7B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 0x21u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED7C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4ED7C2u));
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->eax == 0u) goto label_000ED7E1;
    if (cpu->eax == 1u) goto label_000ED7E1;
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED7E1:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED7F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    cpu->esp -= 0x18u;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_000ED834;
    if ((--cpu->eax) == 0u) goto label_000ED808;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED808:
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"FileMap::size: open file %s error"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Files\\FileMap.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x75u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED82Bu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED82Bu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED834:
    cpu->ecx = cpu->ebp + 0xFFFFFFE8u;
    lift_push32(cpu, (uintptr_t)"FileMap::size: file is not opened"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = (uintptr_t)"Files\\FileMap.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 0x72u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED853u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED853u));
    cpu->esp += 8u;
    cpu->eax = 0u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED860(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((cpu->eax) == 0u) goto label_000ED87A;
    if ((--cpu->eax) == 0u) goto label_000ED8A0;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000ED87A:
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"FileMap::get_ptr: file is not opened"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Files\\FileMap.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x85u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED89Du)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED89Du));
    cpu->esp += 8u;
    label_000ED8A0:
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFE8u;
    lift_push32(cpu, (uintptr_t)"FileMap::get_ptr: open file %s error"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = (uintptr_t)"Files\\FileMap.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 0x87u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED8C7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED8C7u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED8E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000ED92B;
    if (cpu->eax == 1u) goto label_000ED92B;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x4ED8F5u));
    if (cpu->eax != 0u) goto label_000ED925;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->eax = cpu->esi + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"Error unmappnig file %s"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Files\\FileMap.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x63u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED922u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED922u));
    cpu->esp += 0xCu;
    label_000ED925:
    *(uint32_t*)(cpu->esi) = 0u;
    label_000ED92B:
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED930(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == 0u) goto label_000ED97C;
    if (cpu->eax == 1u) goto label_000ED97C;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x4ED946u));
    if (cpu->eax != 0u) goto label_000ED976;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    cpu->eax = cpu->esi + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"Error unmappnig file %s"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Files\\FileMap.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x63u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED973u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED973u));
    cpu->esp += 0xCu;
    label_000ED976:
    *(uint32_t*)(cpu->esi) = 0u;
    label_000ED97C:
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 0x20u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED988u)); sfera_sub_004EE7D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED988u));
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4ED98Du));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esi + 0x27u) = 0u;
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4ED9ADu));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000ED9CA;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi) = 1u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000ED9CA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetFileSize), LIFT_CODE_TOKEN_VA(0x4ED9CEu));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x4ED9E2u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_000EDA11;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::CloseHandle);
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x4EDA01u));
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    if (*(uint32_t*)(cpu->esi) != 0u) goto label_000EDA22;
    label_000EDA11:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi) = 1u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDA22:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDA30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint8_t*)(cpu->esi + 8u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDA49u)); sfera_sub_004ED930(cpu, LIFT_CODE_TOKEN_VA(0x4EDA49u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDA60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = cpu->edi * 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4EDA76u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EDAAB;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"CHash8Mem: init error"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Memory\\hash8mem.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDAA8u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDAA8u));
    cpu->esp += 8u;
    label_000EDAAB:
    lift_push32(cpu, 0x800u);
    cpu->edx = cpu->esi + 0xAu;
    cpu->ecx = 0u;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->edx);
    *(uint16_t*)(cpu->esi + 8u) = cpu->ecx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EDAC2u));
    cpu->ecx = cpu->edi + 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_000EDAEB;
    label_000EDAD3:
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->edx = cpu->eax + 1u;
    *(uint16_t*)(cpu->edi + (cpu->eax * 8u) + 4u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u)) = 0u;
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000EDAD3;
    label_000EDAEB:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = 0xFFFFu;
    *(uint16_t*)(cpu->ebx + cpu->eax + 0xFFFFFFFCu) = cpu->ecx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + cpu->edx + 0xFFFFFFF8u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDB10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = 0xFFFFu;
    if (*(uint16_t*)(cpu->esi + 8u) != (cpu->eax & 0xFFFFu)) goto label_000EDC32;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = 2u;
    if (*(uint32_t*)(cpu->esi + 4u) != cpu->eax) goto label_000EDB56;
    cpu->ecx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"CHash8Mem::register_str: more than 65535 elements"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Memory\\hash8mem.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x31u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDB53u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDB53u));
    cpu->esp += 8u;
    label_000EDB56:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if ((int32_t)cpu->edi >= (int32_t)0x32u) goto label_000EDB71;
    cpu->edi = 0x32u;
    label_000EDB71:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((cpu->ecx & 0xFFFFu) & 0xFFFFu);
    *(uint16_t*)(cpu->esi + 8u) = cpu->edx & 0xFFFFu;
    if ((int32_t)cpu->eax <= (int32_t)0xFFFFu) goto label_000EDB95;
    cpu->ecx = 0xFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = 0xFFFFu;
    label_000EDB95:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EDBA2u));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EDBDD;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"CHash8Memory::register_str: Not enough memory. Request size = %d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Memory\\hash8mem.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x3Du;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDBDAu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDBDAu));
    cpu->esp += 0xCu;
    label_000EDBDD:
    cpu->ecx = cpu->edi + 0xFFFFFFFFu;
    cpu->eax = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_000EDC0E;
    label_000EDBE6:
    cpu->ecx = *(uint16_t*)(cpu->esi + 8u);
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->edx = cpu->ecx + cpu->eax + 1u;
    cpu->ecx += cpu->eax;
    *(uint16_t*)(cpu->ebx + (cpu->ecx * 8u) + 4u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + (cpu->edx * 8u)) = 0u;
    ++cpu->eax;
    cpu->ecx = cpu->edi + 0xFFFFFFFFu;
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000EDBE6;
    label_000EDC0E:
    cpu->edx = *(uint16_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx += cpu->edi;
    cpu->ecx = 0xFFFFu;
    *(uint16_t*)(cpu->eax + (cpu->edx * 8u) + 0xFFFFFFFCu) = cpu->ecx & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx += cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + (cpu->edx * 8u) + 0xFFFFFFF8u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    label_000EDC32:
    cpu->ecx = *(uint16_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->edx + (cpu->ecx * 8u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax + 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->esi + 8u);
    *(uint16_t*)(cpu->esi + 8u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->ebp + 0xCu);
    cpu->edx = cpu->esi + (cpu->edx * 2u) + 0xAu;
    cpu->esi = (cpu->esi & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx));
    *(uint16_t*)(cpu->eax + 4u) = cpu->esi & 0xFFFFu;
    *(uint16_t*)(cpu->edx) = cpu->ecx & 0xFFFFu;
    cpu->eax = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDC70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = cpu->edi;
    cpu->ebx >>= 4u;
    cpu->ebx &= 0x3FFu;
    cpu->esi = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u) + 0xAu);
    cpu->edx = 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    if ((cpu->esi & 0xFFFFu) == (cpu->edx & 0xFFFFu)) goto label_000EDCD0;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->esi * 8u) + 4u);
    cpu->edx = cpu->ecx + (cpu->esi * 8u);
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 8u)) == cpu->edi) goto label_000EDCC1;
    label_000EDCA6:
    cpu->edx = 0xFFFFu;
    if ((cpu->eax & 0xFFFFu) == (cpu->edx & 0xFFFFu)) goto label_000EDCCD;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edx = cpu->ecx + (cpu->edx * 8u);
    cpu->esi = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint16_t*)(cpu->edx + 4u);
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_000EDCA6;
    label_000EDCC1:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi & 0xFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDCCD:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    label_000EDCD0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDCD7u)); sfera_sub_004EDB10(cpu, LIFT_CODE_TOKEN_VA(0x4EDCD7u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDCE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint8_t*)(cpu->edi) = 0u;
    if ((int32_t)cpu->eax < 0) goto label_000EDD35;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 4u)) goto label_000EDD35;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx == 0u) goto label_000EDD35;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_000EDD07:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000EDD07;
    cpu->eax -= cpu->esi;
    if ((int32_t)(--cpu->eax) < 0) goto label_000EDD1C;
    label_000EDD13:
    if (*(uint8_t*)(cpu->ecx + cpu->eax) == 0x5Cu) goto label_000EDD1C;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EDD13;
    label_000EDD1C:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ecx + cpu->eax + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EDD26u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->edi + cpu->esi + 0xFFFFFFFFu) = 0u;
    cpu->esi = lift_pop32(cpu);
    label_000EDD35:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDD40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = cpu->edi;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4EDD54u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EDD89;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"CHash32Mem: init. Not enough memory"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Memory\\hash32mem.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0xBu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDD86u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDD86u));
    cpu->esp += 8u;
    label_000EDD89:
    lift_push32(cpu, 0x40000u);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EDDA1u));
    cpu->edx = cpu->edi + 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)cpu->edx <= 0) goto label_000EDDD4;
    cpu->ecx = 0u;
    label_000EDDB4:
    cpu->edi = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    *(uint32_t*)(cpu->ecx + cpu->edi) = cpu->eax;
    cpu->ecx += 0x1Au;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000EDDB4;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + cpu->edx + 0xFFFFFFE6u) = 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDDD4:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + cpu->eax + 0xFFFFFFE6u) = 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDDF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = cpu->edi;
    cpu->eax >>= 9u;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u) + 0xCu);
    if (cpu->eax != 0xFFFFFFFFu) goto label_000EDE0F;
    cpu->eax |= cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDE0F:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->esi);
    if (*(uint32_t*)(cpu->ecx + cpu->esi + 4u) == cpu->edi) goto label_000EDE3E;
    label_000EDE20:
    if (cpu->edx == 0xFFFFFFFFu) goto label_000EDE3B;
    cpu->ecx = cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->esi);
    if (*(uint32_t*)(cpu->ecx + cpu->esi + 4u) != cpu->edi) goto label_000EDE20;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDE3B:
    cpu->eax |= 0xFFFFFFFFu;
    label_000EDE3E:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EDE50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = cpu->ebx;
    cpu->eax >>= 9u;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ecx + (cpu->edx * 4u) + 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    if (cpu->esi != 0xFFFFFFFFu) goto label_000EDE7C;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDE7C:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->edi);
    cpu->eax += cpu->edi;
    if (*(uint32_t*)(cpu->eax + 4u) == cpu->ebx) goto label_000EDEC6;
    label_000EDE90:
    if (cpu->edx == 0xFFFFFFFFu) goto label_000EDEDE;
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    cpu->eax += cpu->edi;
    cpu->esi = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebx) goto label_000EDE90;
    if (cpu->ecx == 0u) goto label_000EDEC3;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EDEC3:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    label_000EDEC6:
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
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
__declspec(noinline) void sfera_sub_004EDEF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDF03u)); sfera_sub_004EDDF0(cpu, LIFT_CODE_TOKEN_VA(0x4EDF03u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_000EDF13;
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000EDF13:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 8u) == 0xFFFFFFFFu;
    lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_000EDFBD;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x55555556u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if ((int32_t)cpu->edi >= (int32_t)0x32u) goto label_000EDF39;
    cpu->edi = 0x32u;
    label_000EDF39:
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EDF4Au));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EDF86;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"CHash32Mem: register_str. Not enough memory. Requested size = %d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Memory\\hash32mem.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x36u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EDF83u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EDF83u));
    cpu->esp += 0xCu;
    label_000EDF86:
    cpu->eax = cpu->edi + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_000EDFAB;
    (void)cpu;
    label_000EDF90:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->eax += cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    *(uint32_t*)(cpu->eax + cpu->ebx) = cpu->edx;
    ++cpu->ecx;
    cpu->eax = cpu->edi + 0xFFFFFFFFu;
    if ((int32_t)cpu->ecx < (int32_t)cpu->eax) goto label_000EDF90;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    label_000EDFAB:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax += cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1Au);
    *(uint32_t*)(cpu->eax + cpu->ecx + 0xFFFFFFE6u) = 0xFFFFFFFFu;
    label_000EDFBD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx += *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ebx;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    cpu->edx = cpu->ecx + 4u;
    cpu->ebx >>= 9u;
    cpu->edi = cpu->ebx & 0xFFFFu;
    cpu->esi = cpu->esi + (cpu->edi * 4u) + 0xCu;
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x534u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAECu) = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF0u) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE027u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, 0xA4u);
    cpu->eax = cpu->ebp + 0xFFFFFB00u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF4u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE043u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xC4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB8u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u);
    cpu->eax = 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFB24u) = cpu->edx;
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFB08u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFB2Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFB20u) = cpu->eax;
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFB00u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB4u);
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFB18u) = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp + 0xFFFFFB00u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u) = 0u;
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE0A9u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE0B6u));
    if (cpu->eax == 0u) goto label_000EE2A4;
    cpu->esi += 0x68u;
    label_000EE0D0:
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFB18u) == cpu->eax) goto label_000EE2A4;
    *(uint32_t*)(cpu->esi + 0xFFFFFFB8u) = cpu->eax;
    cpu->edx = 0x6E6B6E55u;
    cpu->ebx = cpu->esi + 0xFFFFFF98u;
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"Unknown") + 4u);
    cpu->edx = cpu->ebp + 0xFFFFFAD0u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0xFFFFFFBCu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0xFFFFFAFFu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAD4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAD8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFADCu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAE0u) = cpu->eax;
    cpu->eax = cpu->ebp + 0xFFFFFACCu;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAD0u) = 0x14u;
    lift_native_call(cpu, native_function_address32(&::SymGetLineFromAddr), LIFT_CODE_TOKEN_VA(0x4EE13Bu));
    if (cpu->eax == 0u) goto label_000EE1AD;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFADCu);
    cpu->eax = cpu->edx;
    *(uint8_t*)(cpu->ebp + 0xFFFFFAFFu) = 1u;
    cpu->edi = cpu->eax + 1u;
    label_000EE157:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EE157;
    cpu->eax -= cpu->edi;
    cpu->edi = cpu->eax;
    cpu->eax = cpu->edi + 0xFFFFFFFFu;
    if ((int32_t)cpu->eax < 0) goto label_000EE179;
    label_000EE170:
    if (*(uint8_t*)(cpu->eax + cpu->edx) == 0x5Cu) goto label_000EE179;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EE170;
    label_000EE179:
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    if ((int32_t)cpu->edi < (int32_t)0x1Fu) goto label_000EE18C;
    cpu->edi = 0x1Fu;
    goto label_000EE190;
    label_000EE18C:
    if ((int32_t)cpu->edi <= 0) goto label_000EE1AD;
    label_000EE190:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFAD8u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->eax + cpu->edx + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0xFFFFFFB8u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE1A0u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->ebx + cpu->edi) = 0u;
    label_000EE1AD:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFAF4u);
    cpu->ecx = cpu->ebp + 0xFFFFFBA4u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = 0u;
    cpu->edx = cpu->ebp + 0xFFFFFAE4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAE4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAE8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFBA4u) = 0x458u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFBF4u) = 0x400u;
    lift_native_call(cpu, native_function_address32(&::SymFromAddr), LIFT_CODE_TOKEN_VA(0x4EE1ECu));
    if (cpu->eax == 0u) goto label_000EE243;
    cpu->eax = cpu->ebp + 0xFFFFFBF8u;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_000EE200:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EE200;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi < (int32_t)0x3Fu) goto label_000EE217;
    cpu->edi = 0x3Fu;
    goto label_000EE21B;
    label_000EE217:
    if ((int32_t)cpu->edi <= 0) goto label_000EE24C;
    label_000EE21B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFAE4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp + 0xFFFFFBF8u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esi + 0xFFFFFFBCu;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE233u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->ebx + cpu->edi + 0x24u) = 0u;
    goto label_000EE24C;
    label_000EE243:
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFAFFu) == 0u) goto label_000EE26A;
    label_000EE24C:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u);
    ++cpu->eax;
    cpu->esi += 0x70u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0xFFFFFAECu)) goto label_000EE2AA;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFAF4u);
    label_000EE26A:
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFAF0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFB00u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE289u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE296u));
    if (cpu->eax != 0u) goto label_000EE0D0;
    label_000EE2A4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u);
    label_000EE2AA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE2C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2ECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFD14u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFD18u) = cpu->ecx;
    lift_push32(cpu, 4u);
    lift_native_call(cpu, native_function_address32(&::SymSetOptions), LIFT_CODE_TOKEN_VA(0x4EE2E3u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE2EDu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4EE2F4u));
    if (*(uint32_t*)(cpu->ebp + 8u) == 0u) goto label_000EE315;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = cpu->ebp + 0xFFFFFD28u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),716u); cpu->esi += 716u; cpu->edi += 716u; cpu->ecx = 0u;
    goto label_000EE366;
    label_000EE315:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEE31Au)); sfera_sub_004EE31A(cpu, LIFT_CODE_TOKEN_RVA(0xEE31Au));
    sfera_sub_004EE31A(cpu, stop_address); return;
    label_000EE366:
    cpu->edx = cpu->ebp + 0xFFFFFD28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFD14u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFD18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu)); sfera_sub_004EE000(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE31A(LiftCpu* cpu, uint32_t stop_address) {
    *(uint32_t*)(cpu->ebp + 0xFFFFFD24u) = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFD20u) = cpu->ebp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFD1Cu) = cpu->esp;
    lift_push32(cpu, 0x2CCu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFD28u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE33Au));
    cpu->esp += 0xCu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFD24u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFDE0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFD20u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFDDCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFD1Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFDECu) = cpu->ecx;
    cpu->edx = cpu->ebp + 0xFFFFFD28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFD14u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFD18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu)); sfera_sub_004EE000(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE390(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x280u);
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE3A6u));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint8_t*)(cpu->ebp + 0xCu) == 0u;
    *(uint32_t*)(cpu->edi + 0x280u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x284u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x288u) = cpu->esi;
    if (sub_pred[0]) goto label_000EE461;
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::malloc);
    cpu->edi += 4u;
    *(uint32_t*)(cpu->ebp + 0xCu) = 0x14u;
    label_000EE3E0:
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::malloc)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EE416;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFF0u;
    lift_push32(cpu, (uintptr_t)"Not enough memory. len = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = (uintptr_t)"Logs\\AntifloodQueue.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = 0x1Bu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE413u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE413u));
    cpu->esp += 0xCu;
    label_000EE416:
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->esi;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::malloc)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EE44D;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp + 0xFFFFFFE4u;
    lift_push32(cpu, (uintptr_t)"Not enough memory. len = %d"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = (uintptr_t)"Logs\\AntifloodQueue.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0x20u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE44Au)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE44Au));
    cpu->esp += 0xCu;
    label_000EE44D:
    cpu->edi += 0x20u;
    if ((--*(uint32_t*)(cpu->ebp + 0xCu)) != 0u) goto label_000EE3E0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000EE461:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::free);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx + 0xCu;
    cpu->edi = 0x14u;
    label_000EE481:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFF8u);
    if (cpu->eax == 0u) goto label_000EE48E;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000EE48E:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000EE49A;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000EE49A:
    cpu->esi += 0x20u;
    if ((--cpu->edi) != 0u) goto label_000EE481;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x280u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ecx + 0x280u) == 0x14u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE4D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((*(uint32_t*)(cpu->esi + 0x280u) != 0u) && ((int32_t)(*(uint32_t*)(cpu->esi + 0x280u)) >= (int32_t)(0u))) goto label_000EE508;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"AntifloodQueue::pop_record: queue underflow"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Logs\\AntifloodQueue.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x74u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE505u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE505u));
    cpu->esp += 8u;
    label_000EE508:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x288u);
    --*(uint32_t*)(cpu->esi + 0x280u);
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    ++cpu->ecx;
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->ecx;
    if (cpu->ecx != 0x14u) goto label_000EE531;
    *(uint32_t*)(cpu->esi + 0x288u) = 0u;
    label_000EE531:
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->eax + 1u;
    label_000EE550:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EE550;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if ((int32_t)cpu->esi <= (int32_t)*(uint32_t*)(cpu->ebx)) goto label_000EE5AA;
    cpu->eax = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x4EE572u));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000EE5AA;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, (uintptr_t)"AntifloodQueue::copy_str: not enough memory. Len = %d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = (uintptr_t)"Logs\\AntifloodQueue.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x98u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE5A7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE5A7u));
    cpu->esp += 0xCu;
    label_000EE5AA:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4EE5B2u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE5D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x280u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x288u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if ((cpu->eax==0u) || (((cpu->eax)&0x80000000u)!=0u)) goto label_000EE684;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    label_000EE600:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->edi;
    cpu->esi <<= 5u;
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->ecx + 0xCu);
    label_000EE610:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->ebx) < *(uint8_t*)(cpu->edx);
    if ((uint8_t)(cpu->ebx) != *(uint8_t*)(cpu->edx)) goto label_000EE630;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000EE62C;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->ebx) < *(uint8_t*)(cpu->edx + 1u);
    if ((uint8_t)(cpu->ebx) != *(uint8_t*)(cpu->edx + 1u)) goto label_000EE630;
    cpu->eax += 2u;
    cpu->edx += 2u;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000EE610;
    label_000EE62C:
    cpu->eax = 0u;
    goto label_000EE635;
    label_000EE630:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000EE635:
    if (cpu->eax != 0u) goto label_000EE648;
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->ecx + 0x14u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    if (*(uint8_t*)(cpu->esi + cpu->ecx) != (cpu->eax & 0xFFu)) goto label_000EE648;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->edi;
    label_000EE648:
    ++cpu->edi;
    if (cpu->edi != 0x14u) goto label_000EE650;
    cpu->edi=0u;
    label_000EE650:
    if ((--*(uint32_t*)(cpu->ebp + 0xFFFFFFF8u)) != 0u) goto label_000EE600;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000EE684;
    if ((int32_t)(*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu)) < (int32_t)(0xAu)) goto label_000EE684;
    cpu->eax <<= 5u;
    ++*(uint32_t*)(cpu->eax + cpu->ecx + 0x14u);
    cpu->eax += cpu->ecx;
    cpu->eax += 0x18u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EE672u));
    cpu->esp += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000EE684:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE690(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[4];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[2] = (int32_t)(*(uint32_t*)(cpu->esi + 0x280u)) < (int32_t)(0x14u);
    lift_push32(cpu, cpu->edi);
    if (sub_pred[2]) goto label_000EE6CA;
    cpu->eax = cpu->ebp + 0xFFFFFFE8u;
    lift_push32(cpu, (uintptr_t)"AntifloodQueue::push_record: queue overflow"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = (uintptr_t)"Logs\\AntifloodQueue.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = 0x4Eu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE6C7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4EE6C7u));
    cpu->esp += 8u;
    label_000EE6CA:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x284u);
    cpu->edi = cpu->eax;
    cpu->edi <<= 5u;
    ++cpu->eax;
    cpu->edi += cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->eax;
    if (cpu->eax != 0x14u) goto label_000EE6EB;
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->ebx;
    label_000EE6EB:
    ++*(uint32_t*)(cpu->esi + 0x280u);
    cpu->ecx = cpu->edi + 0x18u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EE6F5u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esp += 4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x14u) = 1u;
    *(uint8_t*)(cpu->edi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE71Bu)); sfera_sub_004EE540(cpu, LIFT_CODE_TOKEN_VA(0x4EE71Bu));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE72Eu)); sfera_sub_004EE540(cpu, LIFT_CODE_TOKEN_VA(0x4EE72Eu));
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x280u) == 0u; sub_pred[3] = (int32_t)(*(uint32_t*)(cpu->esi + 0x280u)) < (int32_t)(0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x288u);
    if ((sub_pred[1]) || (sub_pred[3])) goto label_000EE7C2;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x280u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->edx;
    label_000EE750:
    cpu->eax = cpu->ebx;
    cpu->eax <<= 5u;
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->esi + 0xCu);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    label_000EE761:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000EE781;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000EE77D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000EE781;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000EE761;
    label_000EE77D:
    cpu->eax = 0u;
    goto label_000EE786;
    label_000EE781:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000EE786:
    lift_test[0]=cpu->eax==0u;
    cpu->eax = 1u;
    if (!lift_test[0]) goto label_000EE792;
    *(uint32_t*)(cpu->ebp + 8u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 8u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000EE792:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    if (*(uint8_t*)(cpu->ecx) != 0u) goto label_000EE79D;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000EE79D:
    cpu->ebx += cpu->eax;
    if (cpu->ebx != 0x14u) goto label_000EE7A6;
    cpu->ebx = 0u;
    label_000EE7A6:
    if ((*(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) -= cpu->eax) != 0u) goto label_000EE750;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 8u) >= (int32_t)0xAu) goto label_000EE7C2;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) != 1u) goto label_000EE7C2;
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
__declspec(noinline) void sfera_sub_004EE7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_000EE7D6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000EE7D6;
    cpu->eax -= cpu->esi;
    --cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)(cpu->eax) < 0) goto label_000EE7EC;
    label_000EE7E3:
    if (*(uint8_t*)(cpu->eax + cpu->ecx) == 0x5Cu) goto label_000EE7EC;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EE7E3;
    label_000EE7EC:
    cpu->eax = cpu->eax + cpu->ecx + 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
[[noreturn]] __declspec(noinline) void sfera_sub_004EE92A(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->eip = 0x4EE92Au; throw std::runtime_error("client C++ exception path reached"); }
__declspec(noinline) void sfera_sub_004EE940(LiftCpu* cpu, uint32_t stop_address, double value) {
    if (((uint32_t)(g_sfera_crt_startup_runtime.processor_feature_10) == 0u)) {
        sfera_sub_004EE976(cpu, stop_address, value);
        return;
    }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    cpu->esp &= 0xFFFFFFF8u;
    *(double*)(cpu->esp) = value;
    cpu->eax = (uint32_t)(int32_t)trunc(*(double*)(cpu->esp));
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
     cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE976(LiftCpu* cpu, uint32_t stop_address, double value) { double value_0, value_1;
 bool sub_pred[1]; double x87_p0;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x20u;
    cpu->esp &= 0xFFFFFFF0u;
    x87_p0 = value;
    *(float*)(cpu->esp + 0x18u) = x87_p0;
    *(uint64_t*)(cpu->esp + 0x10u) = static_cast<int64_t>(std::nearbyint(x87_p0));
    x87_p0 = (double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x10u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
     value_0 = x87_p0; if (cpu->eax == 0u) goto label_000EE9D5;
label_000EE999:
    value_1 = value - value_0; 
     if ((int32_t)cpu->edx >= 0) goto label_000EE9BD;
    *(float*)(cpu->esp) = value_1; 
    cpu->ecx = *(uint32_t*)(cpu->esp);
    cpu->ecx ^= 0x80000000u;
    cpu->ecx += 0x7FFFFFFFu;
    cpu->eax += (cpu->ecx < 0x7FFFFFFFu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += ((cpu->ecx < 0x7FFFFFFFu) && cpu->eax == 0u);
     goto label_000EE9E9;
label_000EE9BD:
    *(float*)(cpu->esp) = value_1; 
    cpu->ecx = *(uint32_t*)(cpu->esp);
    cpu->ecx += 0x7FFFFFFFu;
    sub_pred[0] = cpu->eax < 0u || ((cpu->ecx < 0x7FFFFFFFu) && cpu->eax == 0u); cpu->eax -= (cpu->ecx < 0x7FFFFFFFu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx -= (sub_pred[0]);
     goto label_000EE9E9;
label_000EE9D5:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (((cpu->edx) & (0x7FFFFFFFu)) != 0u) goto label_000EE999;
    *(float*)(cpu->esp + 0x18u) = value_0; 
    *(float*)(cpu->esp + 0x18u) = value; 
label_000EE9E9:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}




__declspec(noinline) void sfera_sub_004EEA10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 8u;
    cpu->ecx -= cpu->eax;
    cpu->ecx &= 0xFu;
    cpu->eax += cpu->ecx;
    cpu->ecx = (cpu->eax < cpu->ecx) ? 0xFFFFFFFFu : 0u;
    cpu->eax |= cpu->ecx;
    cpu->ecx = lift_pop32(cpu);
    sfera_sub_004EEAF0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004EEA40(LiftCpu* cpu, uint32_t stop_address) {
    const uint64_t left_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 8u) << 32u) | *(uint32_t*)(cpu->esp + 4u);
    const uint64_t right_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 0x10u) << 32u) | *(uint32_t*)(cpu->esp + 0xCu);
    const bool left_negative = (left_bits & 0x8000000000000000ull) != 0u, right_negative = (right_bits & 0x8000000000000000ull) != 0u;
    const uint64_t left = left_negative ? 0u - left_bits : left_bits, right = right_negative ? 0u - right_bits : right_bits;
    const bool negative = left_negative != right_negative;
    uint64_t quotient = left / right;
    if (negative) quotient = 0u - quotient;
    cpu->eax = (uint32_t)quotient; cpu->edx = (uint32_t)(quotient >> 32u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EEAF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    sub_pred[0] = cpu->ecx < cpu->eax; cpu->ecx -= cpu->eax;
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 0u;
    cpu->eax = ~((uint64_t)(cpu->eax));
    cpu->ecx &= cpu->eax;
    cpu->eax = cpu->esp;
    cpu->eax &= 0xFFFFF000u;
    label_000EEB04:
    if (cpu->ecx < cpu->eax) goto label_000EEB12;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_pop32(cpu);
    {
        uint64_t left = cpu->esp;
        uint64_t right = cpu->eax;
        cpu->esp = right;
        cpu->eax = left;
    }
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEB12:
    cpu->eax -= 0x1000u;
    (void)(*(uint32_t*)(cpu->eax));
    goto label_000EEB04;
}
__declspec(noinline) void sfera_sub_004EEC60(LiftCpu* cpu, uint32_t stop_address) {
    const uint64_t left_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 8u) << 32u) | *(uint32_t*)(cpu->esp + 4u);
    const uint64_t right_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 0x10u) << 32u) | *(uint32_t*)(cpu->esp + 0xCu);
    const bool negative = (left_bits & 0x8000000000000000ull) != 0u, right_negative = (right_bits & 0x8000000000000000ull) != 0u;
    const uint64_t left = negative ? 0u - left_bits : left_bits, right = right_negative ? 0u - right_bits : right_bits;
    uint64_t remainder = left % right;
    if (negative) remainder = 0u - remainder;
    cpu->eax = (uint32_t)remainder; cpu->edx = (uint32_t)(remainder >> 32u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EED20(LiftCpu* cpu, uint32_t stop_address) {
    const uint64_t left = ((uint64_t)*(uint32_t*)(cpu->esp + 8u) << 32u) | *(uint32_t*)(cpu->esp + 4u);
    const uint64_t right = ((uint64_t)*(uint32_t*)(cpu->esp + 0x10u) << 32u) | *(uint32_t*)(cpu->esp + 0xCu);
    const uint64_t product = left * right;
    cpu->eax = (uint32_t)product; cpu->edx = (uint32_t)(product >> 32u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}





__declspec(noinline) void sfera_sub_004EED80(LiftCpu* cpu, uint32_t stop_address) {
    const uint64_t left = ((uint64_t)*(uint32_t*)(cpu->esp + 8u) << 32u) | *(uint32_t*)(cpu->esp + 4u);
    const uint64_t right = ((uint64_t)*(uint32_t*)(cpu->esp + 0x10u) << 32u) | *(uint32_t*)(cpu->esp + 0xCu);
    const uint64_t quotient = left / right;
    cpu->eax = (uint32_t)quotient; cpu->edx = (uint32_t)(quotient >> 32u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EEDF0(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t count = cpu->ecx & 0xFFu;
    const uint64_t value = ((uint64_t)cpu->edx << 32u) | cpu->eax;
    const uint64_t result = count < 64u ? value << count : 0u;
    cpu->eax = (uint32_t)result;
    cpu->edx = (uint32_t)(result >> 32u);
    if (count >= 32u && count < 64u) cpu->ecx &= 0xFFFFFF1Fu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EEE10(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t count = cpu->ecx & 0xFFu;
    const uint64_t value = ((uint64_t)cpu->edx << 32u) | cpu->eax;
    const uint64_t result = count < 64u ? value >> count : 0u;
    cpu->eax = (uint32_t)result;
    cpu->edx = (uint32_t)(result >> 32u);
    if (count >= 32u && count < 64u) cpu->ecx &= 0xFFFFFF1Fu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EEE61(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.mainargs_result = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF088(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.managed_app = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF10Eu)); sfera_sub_004EF33C(cpu, LIFT_CODE_TOKEN_VA(0x4EF10Eu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF113u)); sfera_sub_004EF510(cpu, LIFT_CODE_TOKEN_VA(0x4EF113u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF12Du)); sfera_sub_004EF4E8(cpu, LIFT_CODE_TOKEN_VA(0x4EF12Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF142(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF142;
    label_000EEEAF:
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEEBBu)); sfera_sub_004EF270(cpu, LIFT_CODE_TOKEN_VA(0x4EEEBBu));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ebx;
    cpu->eax = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetStartupInfoW), LIFT_CODE_TOKEN_VA(0x4EEEC4u));
    if (g_sfera_crt_startup_runtime.heap_compatibility_flag != cpu->ebx) goto label_000EEEDD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::HeapSetInformation), LIFT_CODE_TOKEN_RVA(0xEEED7u));
    label_000EEEDD:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    cpu->esi = static_cast<uint32_t>(::GetCurrentThreadId());
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->ebx;
    cpu->edi = (uintptr_t)&g_sfera_crt_startup_runtime.startup_lock;
    label_000EEEF1:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedCompareExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->esi), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 12u;
    if (cpu->eax == cpu->ebx) goto label_000EEF17;
    if (cpu->eax != cpu->esi) goto label_000EEF0A;
    cpu->esi = 0u;
    ++cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esi;
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
    if (cpu->eax != cpu->esi) goto label_000EEF2D;
    lift_push32(cpu, 0x1Fu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF2Au)); sfera_sub_004EF336(cpu, LIFT_CODE_TOKEN_VA(0x4EEF2Au));
    cpu->ecx = lift_pop32(cpu);
    goto label_000EEF68;
    label_000EEF2D:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if (cpu->eax != 0u) goto label_000EEF62;
    g_sfera_crt_startup_runtime.startup_state = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF088(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
    if (cpu->eax == 0u) {
        lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF2C9(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
        if (cpu->eax == 0u) {
            lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF328(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
        }
    }
    if (cpu->eax == 0u) goto label_000EEF68;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    cpu->eax = 0xFFu;
    goto label_000EF082;
    label_000EEF62:
    g_sfera_crt_startup_runtime.has_cctor = cpu->esi;
    label_000EEF68:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if (cpu->eax != cpu->esi) goto label_000EEF8C;
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
    g_sfera_crt_startup_runtime.startup_state = 2u;
    label_000EEF8C:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) != cpu->ebx) goto label_000EEF99;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 8u;
    label_000EEF99:
    cpu->esi = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::GetCommandLineA()));
    label_000EEFC1:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->esi;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) > 0x20u) goto label_000EF013;
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000EEFD3;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) != cpu->ebx) goto label_000EF013;
    label_000EEFD3:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000EEFE3;
    if ((cpu->eax & 0xFFu) > 0x20u) goto label_000EEFE3;
    ++cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->esi;
    goto label_000EEFD3;
    label_000EEFE3:
    if (((*(uint8_t*)(cpu->ebp + 0xFFFFFFC0u)) & (1u)) == 0u) goto label_000EEFEF;
    cpu->eax = *(uint16_t*)(cpu->ebp + 0xFFFFFFC4u);
    goto label_000EEFF2;
    label_000EEFEF:
    lift_push32(cpu, 0xAu);
    cpu->eax = lift_pop32(cpu);
    label_000EEFF2:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uint32_t)(uintptr_t)::GetModuleHandleW(nullptr));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEFFFu)); sfera_sub_0047D770(cpu, LIFT_CODE_TOKEN_VA(0x4EEFFFu));
    g_sfera_crt_startup_runtime.main_return_code = cpu->eax;
    if (g_sfera_crt_startup_runtime.managed_app != cpu->ebx) goto label_000EF068;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0xEF00Du));
    label_000EF013:
    if ((cpu->eax & 0xFFu) != 0x22u) goto label_000EF022;
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    label_000EF022:
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_ismbblead), LIFT_CODE_TOKEN_VA(0x4EF026u));
    cpu->ecx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000EF035;
    ++cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->esi;
    label_000EF035:
    ++cpu->esi;
    goto label_000EEFC1;
    label_000EF068:
    if (g_sfera_crt_startup_runtime.has_cctor != cpu->ebx) goto label_000EF076;
    lift_native_call(cpu, native_function_address32(&::_cexit), LIFT_CODE_TOKEN_RVA(0xEF070u));
    label_000EF076:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    cpu->eax = g_sfera_crt_startup_runtime.main_return_code;
    label_000EF082:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF087u)); sfera_sub_004EF2B5(cpu, LIFT_CODE_TOKEN_VA(0x4EF087u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EF142:
    goto label_000EEEAF;
}
__declspec(noinline) void sfera_sub_004EF270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    cpu->ebp = cpu->esp + 0x10u;
    cpu->esp -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esp;
    lift_push32(cpu, *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->eax = cpu->ebp + 0xFFFFFFF0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF2B5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF2C9(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xAu);
    lift_native_call(cpu, native_function_address32(&::IsProcessorFeaturePresent), LIFT_CODE_TOKEN_VA(0x4EF2CBu));
    g_sfera_crt_startup_runtime.processor_feature_10 = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
[[noreturn]] __declspec(noinline) void sfera_sub_004EF2DA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF2DAu); std::terminate();
}
__declspec(noinline) void sfera_sub_004EF328(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::SetUnhandledExceptionFilter(&sfera_cpp_exception_filter)));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
[[noreturn]] __declspec(noinline) void sfera_sub_004EF336(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF336u); throw std::runtime_error("CRT startup failure");
}
__declspec(noinline) void sfera_sub_004EF33C(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->esp += 4u; cpu->eip = stop_address; return; }
__declspec(noinline) void sfera_sub_004EF4E8(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x30000u); lift_push32(cpu, 0x10000u);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_controlfp_s), LIFT_CODE_TOKEN_VA(0x4EF4F8u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_000EF50E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEF50Eu)); sfera_sub_004EF5BA(cpu, LIFT_CODE_TOKEN_RVA(0xEF50Eu));
    label_000EF50E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
[[noreturn]] __declspec(noinline) void sfera_sub_004EF5BA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF5BAu); std::terminate();
}
} // namespace lifted
