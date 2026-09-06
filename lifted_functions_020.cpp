#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004C3980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    cpu->edx = 0x1Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C39B9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C39B9u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C39C0u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4C39C0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_000C39EE;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x15u); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C39ECu)); sfera_sub_004DA880(cpu, LIFT_CODE_TOKEN_VA(0x4C39ECu));
    goto label_000C39F0;
    label_000C39EE:
    cpu->eax = 0u;
    label_000C39F0:
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000C3A08;
    cpu->ecx = (uintptr_t)"SphereUI::CMinimapTexture::CMinimapTexture(): failed to create a texture";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC3A08u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xC3A08u));
    label_000C3A08:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = g_sfera_minimap_texture_runtime.singleton;
    if (cpu->eax != 0u) goto label_000C3A94;
    cpu->edx = cpu->eax + 0x54u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3A57u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C3A57u));
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3A5Eu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4C3A5Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_000C3A8D;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3A78u)); sfera_sub_004C3980(cpu, LIFT_CODE_TOKEN_VA(0x4C3A78u));
    g_sfera_minimap_texture_runtime.singleton = cpu->eax;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C3A8D:
    cpu->eax = 0u;
    g_sfera_minimap_texture_runtime.singleton = cpu->eax;
    label_000C3A94:
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3AD0(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_minimap_texture_runtime.singleton == 0u) goto label_000C3B39;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x5Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3AE9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C3AE9u));
    cpu->esi = g_sfera_minimap_texture_runtime.singleton;
    if (cpu->esi == 0u) goto label_000C3B2E;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_000C3B1F;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x4Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3B08u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C3B08u));
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->edi == 0u) goto label_000C3B1E;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3B15u)); sfera_sub_004DA4D0(cpu, LIFT_CODE_TOKEN_VA(0x4C3B15u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3B1Bu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4C3B1Bu));
    cpu->esp += 4u;
    label_000C3B1E:
    cpu->edi = lift_pop32(cpu);
    label_000C3B1F:
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3B2Bu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4C3B2Bu));
    cpu->esp += 4u;
    label_000C3B2E:
    g_sfera_minimap_texture_runtime.singleton = 0u;
    cpu->esi = lift_pop32(cpu);
    label_000C3B39:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}








__declspec(noinline) void sfera_sub_004C9D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.widget_keys_initialized;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9DF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.end;
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->edx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->esi = 0u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000C9E36;
    cpu->edx = cpu->edi + 8u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_000C9E20:
    if (*(uint32_t*)(cpu->edx + 0xFFFFFFF8u) != cpu->ecx) goto label_000C9E2E;
    if (*(uint32_t*)(cpu->edx + 0xFFFFFFFCu) != cpu->ebx) goto label_000C9E2E;
    if (*(uint32_t*)(cpu->edx) == cpu->edi) goto label_000C9E3E;
    label_000C9E2E:
    ++cpu->esi;
    cpu->edx += 0xCu;
    if (cpu->esi < cpu->eax) goto label_000C9E20;
    label_000C9E36:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C9E3E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_004CB700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->esi >= cpu->ecx) goto label_000CB75D;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if (cpu->eax > cpu->esi) goto label_000CB75D;
    cpu->esi -= cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->esi))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_000CB735;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCB735u)); sfera_sub_004CA100(cpu, LIFT_CODE_TOKEN_RVA(0xCB735u));
    label_000CB735:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi + (cpu->esi * 2u);
    cpu->ecx = cpu->ecx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax == 0u) goto label_000CB782;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000CB75D:
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_000CB76B;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCB76Bu)); sfera_sub_004CA100(cpu, LIFT_CODE_TOKEN_RVA(0xCB76Bu));
    label_000CB76B:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax == 0u) goto label_000CB782;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    label_000CB782:
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CB790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x40u;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->esp + 0xCu) = cpu->ecx & 0xFFu;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = 0x17u;
    *(uint32_t*)(cpu->esp + 0x38u) = 0x16u;
    if (cpu->ecx == g_sfera_options_dialog_runtime.graphics_modes.end) goto label_000CB7D5;
    g_sfera_options_dialog_runtime.graphics_modes.end = cpu->ecx;
    label_000CB7D5:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    label_000CB7E0:
    cpu->ebx = *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0xCB7EDu));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->ebx != 0x16u) goto label_000CB802;
    *(uint32_t*)(cpu->esp + 0x14u) = 0x20u;
    goto label_000CB812;
    label_000CB802:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (cpu->ebx != 0x17u);
    --cpu->ecx;
    cpu->ecx &= 0x10u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    label_000CB812:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if ((int32_t)cpu->eax <= 0) goto label_000CB8D9;
    label_000CB820:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->ecx, LIFT_CODE_TOKEN_RVA(0xCB82Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->edi < 0x320u) goto label_000CB8BE;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->ebp < 0x258u) goto label_000CB8BE;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.end;
    cpu->ecx -= g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->esi = 0u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000CB890;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx += 8u;
    label_000CB876:
    if (*(uint32_t*)(cpu->ecx + 0xFFFFFFF8u) != cpu->edi) goto label_000CB888;
    if (*(uint32_t*)(cpu->ecx + 0xFFFFFFFCu) != cpu->ebp) goto label_000CB888;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint32_t*)(cpu->ecx) == cpu->edx) goto label_000CB8BE;
    label_000CB888:
    ++cpu->esi;
    cpu->ecx += 0xCu;
    if (cpu->esi < cpu->eax) goto label_000CB876;
    label_000CB890:
    if (*(uint8_t*)(cpu->esp + 0x10u) == 0u) goto label_000CB89F;
    if (cpu->ebp >= g_sfera_recovered_static_runtime.scene_state_07) goto label_000CB8BE;
    label_000CB89F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_modes;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCB8BEu)); sfera_sub_004CB700(cpu, LIFT_CODE_TOKEN_RVA(0xCB8BEu));
    label_000CB8BE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x30u)) goto label_000CB820;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000CB8D9:
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->edi < 2u) goto label_000CB7E0;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.end;
    cpu->ecx -= g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax != 0u) goto label_000CB933;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Found ZERO video modes!"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SphereOptions.cpp";
    *(uint32_t*)(cpu->esp + 0x20u) = 0x1ACu;
    *(uint32_t*)(cpu->esp + 0x24u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB930u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4CB930u));
    cpu->esp += 8u;
    label_000CB933:
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
