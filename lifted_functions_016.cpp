#include "lifted_functions.h"
#include <cmath>
namespace lifted {






__declspec(noinline) void sfera_sub_0049F1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_0009F227;
    if (cpu->ecx > 0x3FFFFFFFu) goto label_0009F1F9;
    cpu->eax = cpu->ecx * 4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F1F2u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x49F1F2u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009F227;
    label_0009F1F9:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F227u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x9F227u));
    label_0009F227:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0049F5D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx += *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0049F9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    if (cpu->ecx == 0u) goto label_0009F9E3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0009F9E3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FA40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_0009FA62;
    label_0009FA50:
    if (cpu->eax == cpu->ebx) goto label_0009FA5D;
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009FA5D;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0009FA5D:
    if (*(uint32_t*)(cpu->esi + 0x10u) != cpu->ebx) goto label_0009FA50;
    label_0009FA62:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->edi <= cpu->ebx) goto label_0009FA8B;
    label_0009FA70:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    --cpu->edi;
    sub_pred[0] = *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == cpu->ebx;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    if (sub_pred[0]) goto label_0009FA87;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FA84u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49FA84u));
    cpu->esp += 4u;
    label_0009FA87:
    if (cpu->edi > cpu->ebx) goto label_0009FA70;
    label_0009FA8B:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    if (cpu->eax == cpu->ebx) goto label_0009FA9C;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FA99u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49FA99u));
    cpu->esp += 4u;
    label_0009FA9C:
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FBD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx = 0x9249249u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx -= cpu->eax;
    if (cpu->ecx >= cpu->ebp) goto label_0009FBF4;
    lift_push32(cpu, (uintptr_t)"deque<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FBD0u); throw std::length_error("std::length_error");
    label_0009FBF4:
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 1u;
    if (cpu->ecx >= 8u) goto label_0009FC02;
    cpu->ecx = 8u;
    label_0009FC02:
    if (cpu->ebp >= cpu->ecx) goto label_0009FC13;
    cpu->edx = 0x9249249u;
    cpu->edx -= cpu->ecx;
    if (cpu->eax > cpu->edx) goto label_0009FC13;
    cpu->ebp = cpu->ecx;
    label_0009FC13:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0xCu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x15u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FC27u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x49FC27u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->eax;
    cpu->esi = cpu->edi * 4u;
    cpu->eax = cpu->esi + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax -= *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FC5Fu));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esp += 0xCu;
    if (cpu->edi > cpu->ebp) goto label_0009FCB0;
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->edx = cpu->esi;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FC85u));
    cpu->edx = cpu->eax;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esp += 0xCu;
    if ((cpu->esi -= cpu->edi) == 0u) goto label_0009FCA4;
    cpu->eax = 0u;
    std::memset((void*)(cpu->edx),0x00,(cpu->esi)*4u); cpu->ecx = 0u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0009FCA4:
    if (cpu->edi == 0u) goto label_0009FCF7;
    cpu->ecx = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    goto label_0009FCF3;
    label_0009FCB0:
    cpu->edi = cpu->ebp * 4u;
    cpu->edx = cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FCC3u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->edi + cpu->eax;
    cpu->esi -= cpu->ecx;
    cpu->esi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FCE1u));
    cpu->esp += 0x18u;
    cpu->edi = cpu->esi + cpu->eax;
    if (cpu->ebp == 0u) goto label_0009FCF7;
    cpu->ecx = cpu->ebp;
    label_0009FCF3:
    std::memset((void*)cpu->edi,0,cpu->ecx*4u);
    label_0009FCF7:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_0009FD09;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FD06u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49FD06u));
    cpu->esp += 4u;
    label_0009FD09:
    *(uint32_t*)(cpu->ebx + 8u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
















} // namespace lifted
