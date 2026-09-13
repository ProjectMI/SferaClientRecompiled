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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
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



















} // namespace lifted
