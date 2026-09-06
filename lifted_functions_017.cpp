#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004A7700(LiftCpu* cpu, uint32_t stop_address) {
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
    if (cpu->ebx <= 0xDD67C8u) goto label_000A7743;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A7700u); throw std::length_error("std::length_error");
    label_000A7743:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= cpu->ebx) goto label_000A77CB;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A776Au)); sfera_sub_004A6270(cpu, LIFT_CODE_TOKEN_VA(0x4A776Au));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7786u)); sfera_sub_004A6440(cpu, LIFT_CODE_TOKEN_VA(0x4A7786u));
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ebx == 0u) goto label_000A77AD;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A77AAu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A77AAu));
    cpu->esp += 4u;
    label_000A77AD:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x128u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x128u);
    cpu->eax += cpu->ecx;
    cpu->edi += cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    label_000A77CB:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A7800(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->esi))) >> 32u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = 0xDD67C8u;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->esi) goto label_000A7836;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A7800u); throw std::length_error("std::length_error");
    label_000A7836:
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->esi <= cpu->eax) goto label_000A787C;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->edi = 0xDD67C8u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000A7868;
    cpu->eax = 0u;
    goto label_000A786A;
    label_000A7868:
    cpu->eax += cpu->edx;
    label_000A786A:
    if (cpu->eax >= cpu->esi) goto label_000A7870;
    cpu->eax = cpu->esi;
    label_000A7870:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    sfera_sub_004A7700(cpu, stop_address); return;
    label_000A787C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A78F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edi;
    lift_push32(cpu, 0xA4u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7935u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A7935u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->edi) goto label_000A79CC;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x50u) = 0xFF50A0A0u;
    *(uint32_t*)(cpu->esi + 0x54u) = 0xFFFFFF00u;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->edi;
    cpu->edx = 0xC4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    *(uint8_t*)(cpu->esp + 0x28u) = 3u;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x24u) = 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A799Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A799Cu));
    lift_push32(cpu, 0x190u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A79A6u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A79A6u));
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A79B0u));
    cpu->esp += 0x10u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A79CC:
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A79F6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A79F6u));
    cpu->eip = 0x4A79F6u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004A7A00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 3u;
    if (*(uint32_t*)(cpu->esi) == cpu->ebx) goto label_000A7A53;
    cpu->edx = 0xD0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A48u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7A48u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A50u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7A50u));
    cpu->esp += 4u;
    label_000A7A53:
    if (*(uint32_t*)(cpu->esi + 4u) == cpu->ebx) goto label_000A7A73;
    cpu->edx = 0xD1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A67u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7A67u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A70u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7A70u));
    cpu->esp += 4u;
    label_000A7A73:
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->ebx) goto label_000A7A93;
    cpu->edx = 0xD2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A87u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7A87u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7A90u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7A90u));
    cpu->esp += 4u;
    label_000A7A93:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->ebp);
    if (cpu->edi == cpu->ebp) goto label_000A7ABB;
    label_000A7AA0:
    if (*(uint32_t*)(cpu->edi + 8u) != 9u) goto label_000A7AB5;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xA0u);
    if (cpu->ecx == cpu->ebx) goto label_000A7AB5;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA7AB5u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_RVA(0xA7AB5u));
    label_000A7AB5:
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != cpu->ebp) goto label_000A7AA0;
    label_000A7ABB:
    if (*(uint32_t*)(cpu->esi + 0x1Cu) == cpu->ebx) goto label_000A7B48;
    cpu->ebp = 0u;
    if (*(uint32_t*)(cpu->esi + 0x24u) <= cpu->ebx) goto label_000A7B2D;
    label_000A7AD0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (*(uint32_t*)(cpu->eax + (cpu->ebp * 4u)) == cpu->ebx) goto label_000A7B27;
    cpu->edx = 0xE2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7AE7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7AE7u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    if (cpu->edi == cpu->ebx) goto label_000A7B27;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->edi)) goto label_000A7B16;
    label_000A7B03:
    cpu->ebx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B0Bu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7B0Bu));
    cpu->esp += 4u;
    cpu->eax = cpu->ebx;
    if (cpu->ebx != *(uint32_t*)(cpu->edi)) goto label_000A7B03;
    cpu->ebx = 0u;
    label_000A7B16:
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B1Eu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7B1Eu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B24u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7B24u));
    cpu->esp += 8u;
    label_000A7B27:
    ++cpu->ebp;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0x24u)) goto label_000A7AD0;
    label_000A7B2D:
    cpu->edx = 0xE4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B3Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A7B3Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B45u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7B45u));
    cpu->esp += 4u;
    label_000A7B48:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x58u);
    if (cpu->eax == cpu->ebx) goto label_000A7B58;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B55u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7B55u));
    cpu->esp += 4u;
    label_000A7B58:
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    if (cpu->eax == cpu->ebx) goto label_000A7B71;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B6Eu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7B6Eu));
    cpu->esp += 4u;
    label_000A7B71:
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->eax == cpu->ebx) goto label_000A7B8A;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7B87u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7B87u));
    cpu->esp += 4u;
    label_000A7B8A:
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x10u)) goto label_000A7BBA;
    label_000A7BA8:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7BB0u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7BB0u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0x10u)) goto label_000A7BA8;
    label_000A7BBA:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A7BC3u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A7BC3u));
    cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A80D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x310u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x318u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x318u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->edi);
    --cpu->esi;
    cpu->edi = cpu->ecx;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->edx >= (int32_t)cpu->esi) goto label_000A815A;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xCu);
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_000A8120:
    cpu->eax = cpu->edx;
    if ((int32_t)cpu->edx >= 0) goto label_000A8128;
    cpu->eax = 0u;
    label_000A8128:
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000A812F;
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    label_000A812F:
    if (cpu->ebx == 0u) goto label_000A8155;
    cpu->eax = *(uint32_t*)(cpu->ebx + (cpu->eax * 4u));
    if (cpu->eax == 0u) goto label_000A8155;
    cpu->edi = cpu->eax + 1u;
    label_000A8140:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A8140;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax -= cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp = cpu->eax + cpu->ebp + 1u;
    label_000A8155:
    ++cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)cpu->esi) goto label_000A8120;
    label_000A815A:
    cpu->edx = 0x1F9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    cpu->esi = cpu->ebp + cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A816Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A816Du));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8173u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A8173u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A817Au));
    cpu->esp += 0x10u;
    cpu->edx = 0x1FCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8191u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A8191u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8197u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A8197u));
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->esi;
    cpu->ebx = cpu->edi + 0x10u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 4u) = 0u;
    if (cpu->ecx == *(uint32_t*)(cpu->ebx)) goto label_000A81D5;
    label_000A81C4:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A81CCu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A81CCu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    if (cpu->esi != *(uint32_t*)(cpu->ebx)) goto label_000A81C4;
    label_000A81D5:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ebx = cpu->edi + 0x30u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    if (cpu->ebp == cpu->edx) goto label_000A820D;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_000A820A;
    label_000A81F0:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebp;
    cpu->eax += 0x128u;
    cpu->ebp += 0x128u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),296u); cpu->esi += 296u; cpu->edi += 296u; cpu->ecx = 0u;
    if (cpu->eax != cpu->edx) goto label_000A81F0;
    label_000A820A:
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ebp;
    label_000A820D:
    lift_push32(cpu, 0x1Eu);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8216u)); sfera_sub_004A7700(cpu, LIFT_CODE_TOKEN_VA(0x4A8216u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x5Cu);
    if (cpu->edi == cpu->ecx) goto label_000A8243;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ebp = cpu->eax * 4u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A8235u));
    cpu->esp += 0xCu;
    cpu->ebp += cpu->edi;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->ebp;
    label_000A8243:
    lift_push32(cpu, 0x64u);
    cpu->ecx = cpu->esi + 0x58u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A824Du)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4A824Du));
    cpu->edi = cpu->esi;
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x44u);
    cpu->ebx = cpu->edi + 0x40u;
    if (cpu->ebp == cpu->edx) goto label_000A8283;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_000A827C;
    label_000A8262:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebp;
    cpu->eax += 0x128u;
    cpu->ebp += 0x128u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),296u); cpu->esi += 296u; cpu->edi += 296u; cpu->ecx = 0u;
    if (cpu->eax != cpu->edx) goto label_000A8262;
    label_000A827C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ebp;
    label_000A8283:
    lift_push32(cpu, 0xAu);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A828Cu)); sfera_sub_004A7700(cpu, LIFT_CODE_TOKEN_VA(0x4A828Cu));
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->ebp);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0xB8u) = cpu->ecx;
    cpu->edx = cpu->esp + 0x30u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A82BBu)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A82BBu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000A82D5;
    label_000A82CA:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A82CAu); throw std::length_error("std::length_error");
    label_000A82D5:
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    --cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000A85DF;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    label_000A8300:
    cpu->eax = cpu->edx;
    if ((int32_t)cpu->edx >= 0) goto label_000A8308;
    cpu->eax = 0u;
    label_000A8308:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000A8316;
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    label_000A8316:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->ecx == 0u) goto label_000A85C6;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    if (cpu->esi == 0u) goto label_000A85C6;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) != 0x20u) goto label_000A8342;
    label_000A8332:
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A85BE;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_000A8332;
    label_000A8342:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A85BE;
    label_000A8350:
    if ((cpu->eax & 0xFFu) != 0x3Cu) goto label_000A85A8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8367u)); sfera_sub_004A5F10(cpu, LIFT_CODE_TOKEN_VA(0x4A8367u));
    if (cpu->eax == 0u) goto label_000A85A2;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x30u) == 3u;
    cpu->ecx = cpu->esi + cpu->eax + 2u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xBCu) = 0u;
    if (!sub_pred[0]) goto label_000A846D;
    lift_push32(cpu, 0x128u);
    cpu->edx = cpu->esp + 0xD0u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A839Cu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_000A83B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x38u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0xCCu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A83B0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->esp + 0xCCu;
    *(uint8_t*)(cpu->esp + 0x1F0u) = cpu->ecx & 0xFFu;
    if (cpu->eax >= cpu->edi) goto label_000A841C;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->ecx = cpu->esp + 0xCCu;
    if (cpu->eax > cpu->ecx) goto label_000A841C;
    cpu->ecx -= cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    if (cpu->edi != *(uint32_t*)(cpu->ebp + 8u)) goto label_000A840A;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA840Au)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA840Au));
    label_000A840A:
    cpu->edi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x128u);
    cpu->esi += *(uint32_t*)(cpu->ebp);
    if (cpu->edi == 0u) goto label_000A843F;
    goto label_000A8438;
    label_000A841C:
    if (cpu->edi != *(uint32_t*)(cpu->ebp + 8u)) goto label_000A842A;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA842Au)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA842Au));
    label_000A842A:
    cpu->edi = *(uint32_t*)(cpu->ebp + 4u);
    if (cpu->edi == 0u) goto label_000A843F;
    cpu->esi = cpu->esp + 0xCCu;
    label_000A8438:
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),296u); cpu->esi += 296u;
    label_000A843F:
    *(uint32_t*)(cpu->ebp + 4u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 4u)) + (uint64_t)(0x128u) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ecx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    label_000A846D:
    if (*(uint32_t*)(cpu->esp + 0x30u) != 0xAu) goto label_000A855A;
    if (*(uint8_t*)(cpu->esp + 0x38u) != 0x23u) goto label_000A84A1;
    lift_push32(cpu, 0x80u);
    cpu->ecx = cpu->esp + 0x3Du;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A848Du)); sfera_sub_004B9140(cpu, LIFT_CODE_TOKEN_VA(0x4A848Du));
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1FCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4A8496u));
    cpu->esp += 0xCu;
    goto label_000A84B3;
    label_000A84A1:
    cpu->eax = 0u;
    label_000A84A3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x38u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x1F4u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A84A3;
    label_000A84B3:
    cpu->edi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->esp + 0x1F4u;
    *(uint8_t*)(cpu->esp + 0x318u) = 0u;
    if (cpu->eax >= cpu->edi) goto label_000A850A;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = cpu->esp + 0x1F4u;
    if (cpu->eax > cpu->ecx) goto label_000A850A;
    cpu->ecx -= cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    if (cpu->edi != *(uint32_t*)(cpu->ebx + 8u)) goto label_000A84F9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA84F9u)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA84F9u));
    label_000A84F9:
    cpu->edi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x128u);
    cpu->esi += *(uint32_t*)(cpu->ebx);
    if (cpu->edi == 0u) goto label_000A852D;
    goto label_000A8526;
    label_000A850A:
    if (cpu->edi != *(uint32_t*)(cpu->ebx + 8u)) goto label_000A8518;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA8518u)); sfera_sub_004A7800(cpu, LIFT_CODE_TOKEN_RVA(0xA8518u));
    label_000A8518:
    cpu->edi = *(uint32_t*)(cpu->ebx + 4u);
    if (cpu->edi == 0u) goto label_000A852D;
    cpu->esi = cpu->esp + 0x1F4u;
    label_000A8526:
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),296u);
    label_000A852D:
    *(uint32_t*)(cpu->ebx + 4u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 4u)) + (uint64_t)(0x128u) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ecx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    label_000A855A:
    *(uint8_t*)(cpu->edi) = 0u;
    cpu->esi = *(uint32_t*)(cpu->ebp);
    ++cpu->edi;
    cpu->edx = cpu->esp + 0x30u;
    *(uint32_t*)(cpu->esp + 0xB8u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A857Du)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A857Du));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx < 1u) goto label_000A82CA;
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_000A85B0;
    label_000A85A2:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    *(uint8_t*)(cpu->edi) = cpu->edx & 0xFFu;
    goto label_000A85AA;
    label_000A85A8:
    *(uint8_t*)(cpu->edi) = cpu->eax & 0xFFu;
    label_000A85AA:
    ++cpu->edi;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_000A85B0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000A8350;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    label_000A85BE:
    *(uint8_t*)(cpu->edi) = 0x20u;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_000A85C6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    ++cpu->edx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)cpu->ecx) goto label_000A8300;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_000A85DF:
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4A85EBu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x310u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A8610(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x410u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8646u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A8646u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8650u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A8650u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (cpu->eax == 0u) goto label_000A866E;
    cpu->ecx = cpu->eax;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->initialize(); cpu->eax = cpu->ecx; }
    cpu->esi = cpu->eax;
    goto label_000A8670;
    label_000A866E:
    cpu->esi = 0u;
    label_000A8670:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    { const uint32_t __parser_arg_017_1_0 = static_cast<uint32_t>(cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->load(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_017_1_0))); }
    { const uint32_t __parser_arg_017_2_0 = static_cast<uint32_t>(1u); const uint32_t __parser_arg_017_2_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esp + 0x10u;
    const uint32_t __parser_arg_017_2_2 = static_cast<uint32_t>(cpu->ecx); const uint32_t __parser_arg_017_2_3 = static_cast<uint32_t>((uintptr_t)"hypertext");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_017_2_3)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_017_2_2)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_017_2_1)), static_cast<int32_t>(__parser_arg_017_2_0)) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000A86D6;
    cpu->edx = 0x417u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86ACu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A86ACu));
    if (cpu->esi == 0u) goto label_000A86C0;
    cpu->ecx = cpu->esi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->release(); }
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86BDu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A86BDu));
    cpu->esp += 4u;
    label_000A86C0:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A86D6:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86E3u)); sfera_sub_004A80D0(cpu, LIFT_CODE_TOKEN_VA(0x4A86E3u));
    cpu->edx = 0x41Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A86F2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A86F2u));
    if (cpu->esi == 0u) goto label_000A8706;
    cpu->ecx = cpu->esi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->release(); }
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8703u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A8703u));
    cpu->esp += 4u;
    label_000A8706:
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A8A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    if (cpu->ecx == 0u) goto label_000A8A66;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A8A5Cu)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4A8A5Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_000A8A66:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A8C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == 0u) goto label_000A8C60;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A8C60;
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_000A8C60:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    if (cpu->edx == 0u) goto label_000A8C89;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000A8C89;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000A8C89:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A8E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004AEE90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x198u);
    if (cpu->eax == 0u) goto label_000AEE9D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000AEE9D:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004AF340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ecx + 0x2ECu) == cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
