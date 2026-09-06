#include "lifted_functions.h"
#include <cmath>
namespace lifted {













__declspec(noinline) void sfera_sub_004C9D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.widget_keys_initialized;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004C9E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000C9EA7;
    if (cpu->ecx > 0x15555555u) goto label_000C9E79;
    cpu->eax = cpu->ecx + (cpu->ecx * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9E72u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4C9E72u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000C9EA7;
    label_000C9E79:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC9EA7u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xC9EA7u));
    label_000C9EA7:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_000C9FFF;
    lift_push32(cpu, cpu->esi);
    label_000C9FE0:
    if (cpu->eax == 0u) goto label_000C9FF4;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    label_000C9FF4:
    cpu->ecx += 0xCu;
    cpu->eax += 0xCu;
    if (cpu->ecx != cpu->edx) goto label_000C9FE0;
    cpu->esi = lift_pop32(cpu);
    label_000C9FFF:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CA100(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000CA100;
    label_000CA010:
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
    if (cpu->ebx <= 0x15555555u) goto label_000CA053;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA010u); throw std::length_error("std::length_error");
    label_000CA053:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= cpu->ebx) goto label_000CA0D1;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA077u)); sfera_sub_004C9E50(cpu, LIFT_CODE_TOKEN_VA(0x4CA077u));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA093u)); sfera_sub_004C9FD0(cpu, LIFT_CODE_TOKEN_VA(0x4CA093u));
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ebx == 0u) goto label_000CA0B7;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA0B4u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CA0B4u));
    cpu->esp += 4u;
    label_000CA0B7:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_000CA0D1:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000CA100:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->edx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->edx))) >> 32u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = 0x15555555u;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->esi) goto label_000CA133;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA100u); throw std::length_error("std::length_error");
    label_000CA133:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esi += cpu->eax;
    cpu->edx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->esi <= cpu->eax) goto label_000CA174;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->edi = 0x15555555u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000CA161;
    cpu->eax = 0u;
    goto label_000CA163;
    label_000CA161:
    cpu->eax += cpu->edx;
    label_000CA163:
    if (cpu->eax >= cpu->esi) goto label_000CA169;
    cpu->eax = cpu->esi;
    label_000CA169:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    goto label_000CA010;
    label_000CA174:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_ui_handle_control_options_event(LiftCpu* cpu, uint32_t stop_address) { SphereUI::Runtime::invokeEventHandler(SphereUI::WindowEventHandler::control_options, SferaAbi::pointer<SphereUI::Window>(cpu->ecx), *SferaAbi::pointer<const SphereUI::WindowEvent>(cpu->edx)); cpu->esp += 4u; cpu->eip = stop_address; }



} // namespace lifted
