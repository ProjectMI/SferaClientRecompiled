#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004C3750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint8_t*)(cpu->edi + 0x48u) != 0u) goto label_000C3970;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->esi == cpu->ebp) goto label_000C37AC;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebp;
    if (cpu->ecx == cpu->ebp) goto label_000C379E;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC379Eu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC379Eu));
    label_000C379E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000C37AC:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x34u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->esp + 0x18u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u];
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C37F8u)); sfera_sub_004C3A20(cpu, LIFT_CODE_TOKEN_VA(0x4C37F8u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C37FFu)); sfera_sub_004C3AC0(cpu, LIFT_CODE_TOKEN_VA(0x4C37FFu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3816u)); sfera_sub_004C3A20(cpu, LIFT_CODE_TOKEN_VA(0x4C3816u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C381Du)); sfera_sub_004C3AB0(cpu, LIFT_CODE_TOKEN_VA(0x4C381Du));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xDCu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->esp -= 0x10u;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ecx <<= 24u;
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx |= 0xFFFFFFu;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->edx = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C386Fu)); sfera_sub_004CEE10(cpu, LIFT_CODE_TOKEN_VA(0x4C386Fu));
    cpu->ebx = g_sfera_world_objects.controlled_object_handle;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->ebp) goto label_000C396D;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->esi == cpu->ebp) goto label_000C38BA;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if (cpu->ecx == cpu->ebp) goto label_000C38AC;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC38ACu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC38ACu));
    label_000C38AC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    label_000C38BA:
    cpu->eax += 0x7Fu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->ecx += 0x84u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->esi = cpu->ebx;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000C38F1;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC38F1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0xC38F1u));
    label_000C38F1:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x194u);
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->edx + 0x14u);
    if (cpu->eax == cpu->ebp) goto label_000C396D;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->esp -= 0x14u;
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->ecx |= 0xFFFFFFFFu;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->ecx;
    lift_x87_push(cpu, 28.0);
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->ecx;
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x194u);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x28u);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC396Du)); sfera_sub_004CEE60(cpu, LIFT_CODE_TOKEN_RVA(0xC396Du));
    label_000C396D:
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000C3970:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x1Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C39B9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C39B9u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C39C0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C39C0u));
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
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_minimap_texture_runtime.singleton;
    if (cpu->eax != 0u) goto label_000C3A94;
    cpu->edx = cpu->eax + 0x54u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3A57u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C3A57u));
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3A5Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C3A5Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_000C3A8D;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3A78u)); sfera_sub_004C3980(cpu, LIFT_CODE_TOKEN_VA(0x4C3A78u));
    g_sfera_minimap_texture_runtime.singleton = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C3A8D:
    cpu->eax = 0u;
    g_sfera_minimap_texture_runtime.singleton = cpu->eax;
    label_000C3A94:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0x100u;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3B1Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C3B1Bu));
    cpu->esp += 4u;
    label_000C3B1E:
    cpu->edi = lift_pop32(cpu);
    label_000C3B1F:
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3B2Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C3B2Bu));
    cpu->esp += 4u;
    label_000C3B2E:
    g_sfera_minimap_texture_runtime.singleton = 0u;
    cpu->esi = lift_pop32(cpu);
    label_000C3B39:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3B40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi != 0u) goto label_000C3B4B;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C3B4B:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xC3B5Au), LIFT_CODE_TOKEN_RVA(0xC3B58u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000C3B64;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C3B64:
    lift_push32(cpu, (uintptr_t)"PERCENT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xC3B6Cu), LIFT_CODE_TOKEN_RVA(0xC3B6Au))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000C3B7B;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C3B7B:
    lift_push32(cpu, (uintptr_t)"STYLE1"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xC3B83u), LIFT_CODE_TOKEN_RVA(0xC3B81u))) { return; }
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xFFFFFFFEu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 2u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3BA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3BA8u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4C3BA8u));
    lift_x87_push(cpu, 0.0);
    cpu->eax = 0u;
    *(float*)(cpu->esi + 0x1A4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x1ACu) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::ProgressBar*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x19Cu) = 0x64u;
    *(uint32_t*)(cpu->esi + 0x50u) = 4u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C3DDD;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C3DDD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == 0u) goto label_000C3C58;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000C3C4A;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC3C4Au)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC3C4Au));
    label_000C3C4A:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000C3C58:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(float*)(cpu->esp + 0xCu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    if (cpu->ecx == 0u) goto label_000C3D18;
    { const double lift_left=0.0; const double lift_right=((double)*(float*)(cpu->esi + 0x1A4u)); if (!(lift_left<lift_right)) goto label_000C3D18; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->ecx >= 0) goto label_000C3CC9;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C3CC9:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000C3CEA;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C3CEA:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x1A4u)));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3D10u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_VA(0x4C3D10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    label_000C3D18:
    if (*(uint32_t*)(cpu->esi + 0x1A8u) <= 0u) goto label_000C3DD8;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1ECu)))));
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3D34u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C3D34u));
    cpu->edi = cpu->eax;
    g_sfera_screen_clip_runtime.left = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1F0u)))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3D47u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C3D47u));
    cpu->ecx = cpu->edi + 0x64u;
    cpu->edx = cpu->eax + 0x64u;
    g_sfera_screen_clip_runtime.top = cpu->eax;
    g_sfera_screen_clip_runtime.right = cpu->ecx;
    g_sfera_screen_clip_runtime.bottom = cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != 0xFFu) goto label_000C3D85;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000C3D85;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3D7Au)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4C3D7Au));
    cpu->edi = g_sfera_screen_clip_runtime.left;
    cpu->eax = g_sfera_screen_clip_runtime.top;
    label_000C3D85:
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x1ACu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3DB4u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C3DB4u));
    if (*(uint32_t*)(cpu->esi + 0xDCu) != 0xFFu) goto label_000C3DDC;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000C3DDC;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000C3DD8:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C3DDC:
    cpu->edi = lift_pop32(cpu);
    label_000C3DDD:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3DF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u)))));
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (fabs(((double)*(float*)(cpu->esp + 4u))));
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->esi + 0x1A4u) = cpu->fpu[0u];
    lift_x87_push(cpu, 1.0);
    { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; lift_x87_pop(cpu); if (!(lift_left<lift_right)) goto label_000C3E4B; }
    *(float*)(cpu->esi + 0x1A4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000C3E4D;
    label_000C3E4B:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C3E4D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    if (cpu->eax == 0u) goto label_000C3E9E;
    if ((--cpu->eax) == 0u) goto label_000C3E77;
    if ((--cpu->eax) != 0u) goto label_000C3E9E;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d / %d");
    cpu->esi += 0x1ACu;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C3E6Bu));
    cpu->esp += 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C3E77:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x1A4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (100.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3E88u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C3E88u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d%%");
    cpu->esi += 0x1ACu;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C3E95u));
    cpu->esp += 0xCu;
    label_000C3E9E:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = cpu->eax + 0xFFFFF82Fu;
    if (cpu->edx > 9u) goto label_000C3F8D;
    cpu->eax += 0xFFFFF82Fu;
    if (cpu->eax > 9u) goto label_000C3F88;
    switch (cpu->eax) {
        case 0u: goto label_000C3EDF;
        case 1u: goto label_000C3F22;
        case 3u: goto label_000C3F54;
        case 9u: goto label_000C3F74;
        default: goto label_000C3F88;
    }
label_000C3EDF: ;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    if (*(uint32_t*)(cpu->ecx + 0x1A0u) == cpu->edx) goto label_000C3F1A;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x198u);
    *(uint32_t*)(cpu->ecx + 0x1A0u) = cpu->edx;
    if ((int32_t)cpu->edx >= (int32_t)cpu->eax) goto label_000C3F01;
    *(uint32_t*)(cpu->ecx + 0x1A0u) = cpu->eax;
    label_000C3F01:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x19Cu);
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x1A0u) <= (int32_t)cpu->eax) goto label_000C3F15;
    *(uint32_t*)(cpu->ecx + 0x1A0u) = cpu->eax;
    label_000C3F15:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC3F1Au)); sfera_sub_004C3DF0(cpu, LIFT_CODE_TOKEN_RVA(0xC3F1Au));
    label_000C3F1A:
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C3F22:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x19Cu) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1A0u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000C3F15;
    ++cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x19Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3F4Cu)); sfera_sub_004C3DF0(cpu, LIFT_CODE_TOKEN_VA(0x4C3F4Cu));
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C3F54:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x19Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C3F74:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C3F88:
    cpu->eax = 0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C3F8D:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    sfera_sub_004D2DD0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C3FC0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3FD9u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4C3FD9u));
    if (*(uint32_t*)(cpu->esi + 0x9Cu) != 0u) goto label_000C3FFC;
    lift_push32(cpu, 0x6Bu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ProgressBar.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3FF3u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C3FF3u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3FF9u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C3FF9u));
    cpu->esp += 0x10u;
    label_000C3FFC:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"drawMethod");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C400Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C400Du));
    if (cpu->eax == 0u) goto label_000C40AE;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4023u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C4023u));
    if (cpu->eax == 0u) goto label_000C40AE;
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"SPRITE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xC403Du), LIFT_CODE_TOKEN_RVA(0xC403Bu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000C4097;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4052u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C4052u));
    if (cpu->eax == 0u) goto label_000C40AE;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4066u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4C4066u));
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000C40AE;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ProgressBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C408Cu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C408Cu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4092u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C4092u));
    cpu->esp += 0x18u;
    goto label_000C40AE;
    label_000C4097:
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xC40A3u), LIFT_CODE_TOKEN_RVA(0xC40A1u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000C40AE;
    *(uint32_t*)(cpu->esi + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x24u)) | (uint64_t)(2u);
    label_000C40AE:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"statusShow");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C40BBu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C40BBu));
    if (cpu->eax == 0u) goto label_000C40E1;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C40CDu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C40CDu));
    if (cpu->eax == 0u) goto label_000C40E1;
    cpu->ecx = (uintptr_t)&g_sfera_ui_load_scratch_runtime.progress_bar_value[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C40DBu)); sfera_sub_004C3B40(cpu, LIFT_CODE_TOKEN_VA(0x4C40DBu));
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    label_000C40E1:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"range");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C40EEu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C40EEu));
    if (cpu->eax == 0u) goto label_000C4156;
    cpu->ebx = cpu->esi + 0x19Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebp = cpu->esi + 0x198u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C4109u));
    cpu->esp += 0x10u;
    if ((int32_t)cpu->eax >= (int32_t)2u) goto label_000C413A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ProgressBar::LoadUI(%s,%d,%d) -> Not enough args in 'range'.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4131u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C4131u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4137u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C4137u));
    cpu->esp += 0x14u;
    label_000C413A:
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000C4148;
    *(uint32_t*)(cpu->ebp) = cpu->ecx;
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_000C4148:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    sub_pred[0] = *(uint32_t*)(cpu->ebp) == cpu->eax;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    if (!sub_pred[0]) goto label_000C4156;
    ++cpu->eax;
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_000C4156:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"progressPos");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4163u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C4163u));
    if (cpu->eax == 0u) goto label_000C419A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4170u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C4170u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000C4186;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ecx;
    label_000C4186:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1A0u) <= (int32_t)cpu->eax) goto label_000C419A;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    label_000C419A:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"statusPos");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C41A7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C41A7u));
    if (cpu->eax == 0u) goto label_000C41F0;
    cpu->edx = cpu->esi + 0x1F0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x1ECu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C41C2u));
    cpu->esp += 0x10u;
    if ((int32_t)cpu->eax >= (int32_t)2u) goto label_000C41F0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ProgressBar::LoadUI(%s,%d,%d) -> Not enough args in 'statusPos'.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C41E7u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C41E7u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C41EDu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C41EDu));
    cpu->esp += 0x14u;
    label_000C41F0:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C41F7u)); sfera_sub_004C3DF0(cpu, LIFT_CODE_TOKEN_VA(0x4C41F7u));
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4203u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4C4203u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C4220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C422Fu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4C422Fu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1A0u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edx;
    *(float*)(cpu->esi + 0x1A4u) = (double)*(float*)(cpu->edi + 0x1A4u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1A8u);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    cpu->eax = cpu->esi + 0x1ACu;
    cpu->ecx -= cpu->esi;
    cpu->ebp = 0x40u;
    label_000C4280:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->eax));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if ((--cpu->ebp) != 0u) goto label_000C4280;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1F0u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C42B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xD9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ProgressBar.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C42E4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C42E4u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C42EEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C42EEu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000C430C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4308u)); sfera_sub_004C3BA0(cpu, LIFT_CODE_TOKEN_VA(0x4C4308u));
    cpu->esi = cpu->eax;
    goto label_000C430E;
    label_000C430C:
    cpu->esi = 0u;
    label_000C430E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C431Eu)); sfera_sub_004C4220(cpu, LIFT_CODE_TOKEN_VA(0x4C431Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000C4346;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC4346u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC4346u));
    label_000C4346:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C4360(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x1A8u) != 0u) goto label_000C438C;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    if (cpu->ecx == 0u) goto label_000C438C;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x3Cu);
    lift_push32(cpu, 8u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x3EAu); lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    label_000C438C:
    *(uint8_t*)(cpu->esi + 0x1A8u) = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004A1350(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C43A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C43A8u)); sfera_sub_004A0E60(cpu, LIFT_CODE_TOKEN_VA(0x4C43A8u));
    std::construct_at(reinterpret_cast<SphereUI::RadioButtonCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 8u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C43C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x56u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\RadioButton.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C43F4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C43F4u));
    lift_push32(cpu, 0x1C8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C43FEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C43FEu));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->esi == 0u) goto label_000C4429;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C441Au)); sfera_sub_004A0E60(cpu, LIFT_CODE_TOKEN_VA(0x4C441Au));
    std::construct_at(reinterpret_cast<SphereUI::RadioButtonCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 8u;
    goto label_000C442B;
    label_000C4429:
    cpu->esi = 0u;
    label_000C442B:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C443Bu)); sfera_sub_004A1690(cpu, LIFT_CODE_TOKEN_VA(0x4C443Bu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000C4463;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC4463u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC4463u));
    label_000C4463:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C4480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4497u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4C4497u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"scrollbar");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C44AFu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4C44AFu));
    if (cpu->eax == 0u) goto label_000C44D7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C44C9u)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4C44C9u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC44D7u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC44D7u));
    label_000C44D7:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C44E3u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4C44E3u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C44F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = cpu->esi + 0x1C0u;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)"_";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4513u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C4513u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu)))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->ecx;
    if ((int32_t)cpu->edx >= 0) goto label_000C452D;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C452D:
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C453B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C453B:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4550u)); sfera_sub_004EED66(cpu, LIFT_CODE_TOKEN_VA(0x4C4550u));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->esp += 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (1.0);
    cpu->edi = lift_pop32(cpu);
    *(uint16_t*)(cpu->esp + 0x10u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x10u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 4u);
    *(uint64_t*)(cpu->esp + 4u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0xCu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C45A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x10u);
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C45C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1CCu);
    if (cpu->ecx == 0u) goto label_000C4668;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->esi -= *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C4u);
    cpu->esi = cpu->edx + 1u;
    cpu->ebx = 0u;
    if (cpu->eax <= cpu->esi) goto label_000C4632;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax + 0xFFFFFFFFu;
    label_000C4632:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0x17u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4666u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_VA(0x4C4666u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C4668:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C46D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    --*(uint32_t*)(cpu->ecx + 0x1ACu); sub_pred[1] = (int32_t)(*(uint32_t*)(cpu->ecx + 0x1ACu)) < 0;
    lift_push32(cpu, cpu->edi);
    if (!sub_pred[1]) goto label_000C470F;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if (cpu->eax == 0u) goto label_000C4705;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->edi + (cpu->edx * 4u) + 0xFFFFFFF4u);
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1A8u) = cpu->eax;
    goto label_000C470F;
    label_000C4705:
    *(uint32_t*)(cpu->ecx + 0x1ACu) = 0u;
    label_000C470F:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C4723;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4723:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->edi += cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C473E;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C473E:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u) >= (int32_t)0u) goto label_000C4751;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C4751:
    sfera_sub_004C45C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C4760(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    ++*(uint32_t*)(cpu->ecx + 0x1ACu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1A8u);
    cpu->edx = cpu->esi * 8u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->edx -= cpu->esi;
    cpu->ebx = *(uint32_t*)(cpu->edi + (cpu->edx * 4u) + 0x10u);
    if (*(uint32_t*)(cpu->ecx + 0x1ACu) <= cpu->ebx) goto label_000C47C8;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x19Cu);
    cpu->edi -= *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->edx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    if (cpu->esi >= cpu->edx) goto label_000C47C2;
    ++cpu->esi;
    *(uint32_t*)(cpu->ecx + 0x1ACu) = 0u;
    *(uint32_t*)(cpu->ecx + 0x1A8u) = cpu->esi;
    goto label_000C47C8;
    label_000C47C2:
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->ebx;
    label_000C47C8:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C47DC;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C47DC:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    cpu->edi = lift_pop32(cpu);
    sub_pred[0] = cpu->esi < cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C47F9;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C47F9:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u) >= (int32_t)0u) goto label_000C480C;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C480C:
    sfera_sub_004C45C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C4820(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    lift_push32(cpu, cpu->esi);
    if ((int32_t)cpu->eax <= 0) goto label_000C485E;
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1ACu);
    if (cpu->esi == 0u) goto label_000C4857;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->edx = cpu->edi + (cpu->edx * 4u) + 0xFFFFFFE4u;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    if (cpu->esi <= cpu->edx) goto label_000C4857;
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->edx;
    label_000C4857:
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x1A8u) = cpu->eax;
    label_000C485E:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C4872;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4872:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    sub_pred[0] = cpu->esi < cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C488D;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C488D:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u) >= (int32_t)0u) goto label_000C48A0;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C48A0:
    sfera_sub_004C45C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C48B0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x19Cu);
    cpu->esi -= *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x1A8u);
    cpu->edx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    if (cpu->edi >= cpu->edx) goto label_000C4910;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1ACu);
    if (cpu->edx == 0u) goto label_000C4909;
    cpu->eax = cpu->edi + 1u;
    cpu->esi = cpu->eax * 8u;
    cpu->esi -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->eax = cpu->eax + (cpu->esi * 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    if (cpu->edx <= cpu->eax) goto label_000C4909;
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->eax;
    label_000C4909:
    ++cpu->edi;
    *(uint32_t*)(cpu->ecx + 0x1A8u) = cpu->edi;
    label_000C4910:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C4924;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4924:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    cpu->edi = lift_pop32(cpu);
    sub_pred[0] = cpu->esi < cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C4940;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4940:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u) >= (int32_t)0u) goto label_000C4953;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C4953:
    sfera_sub_004C45C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C4960(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1C4u);
    if ((int32_t)(*(uint32_t*)(cpu->ecx + 0x1A8u) -= cpu->esi) >= 0) goto label_000C4979;
    *(uint32_t*)(cpu->ecx + 0x1A8u) = 0u;
    label_000C4979:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1ACu);
    if (cpu->edx == 0u) goto label_000C49AA;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->eax * 8u;
    cpu->ebx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->eax = cpu->eax + (cpu->ebx * 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ebx = lift_pop32(cpu);
    if (cpu->edx <= cpu->eax) goto label_000C49AA;
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->eax;
    label_000C49AA:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C49BE;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C49BE:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->edx += cpu->esi;
    if (cpu->edx >= cpu->eax) goto label_000C49D2;
    cpu->eax -= cpu->esi;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C49D2:
    sub_pred[0] = (int32_t)(*(uint32_t*)(cpu->ecx + 0x1C8u)) < (int32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C49E6;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C49E6:
    sfera_sub_004C45C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C49F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    *(uint32_t*)(cpu->ecx + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x1A8u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x19Cu);
    cpu->esi -= *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + 0xFFFFFFFFu;
    lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->ecx + 0x1A8u) <= cpu->edx) goto label_000C4A30;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x1A8u) = cpu->eax;
    label_000C4A30:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1ACu);
    if (cpu->edx == 0u) goto label_000C4A5F;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    cpu->esi = cpu->eax * 8u;
    cpu->esi -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->eax = cpu->eax + (cpu->esi * 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    if (cpu->edx <= cpu->eax) goto label_000C4A5F;
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->eax;
    label_000C4A5F:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C4A73;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4A73:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->edx += cpu->ebx;
    if (cpu->edx >= cpu->eax) goto label_000C4A87;
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4A87:
    sub_pred[0] = (int32_t)(*(uint32_t*)(cpu->ecx + 0x1C8u)) < (int32_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C4A9D;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C4A9D:
    sfera_sub_004C45C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C4AB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->eax|=*(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->eax!=0u) goto label_000C4AD5;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4AC9u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4C4AC9u));
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edx;
    label_000C4AD5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4ADAu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4C4ADAu));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x1B0u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1B4u) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    *(float*)(cpu->esp + 4u) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 8u)))))) / (10000.0));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; lift_x87_pop(cpu); if (!(lift_left<lift_right)) goto label_000C4B24; }
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4B14u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4C4B14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edx;
    label_000C4B24:
    lift_x87_push(cpu, 0.4000000059604645);
    { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; if (!(lift_left<lift_right)) goto label_000C4B6C; }
    cpu->fpu[1u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->esp + 4u))) / (cpu->fpu[0u]);
    *(uint16_t*)(cpu->esp + 4u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 4u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 8u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 8u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x1B8u) = cpu->ecx & 0xFFu;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 4u);
    goto label_000C4B70;
    label_000C4B6C:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C4B70:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000C4C18;
    if (*(uint8_t*)(cpu->esi + 0x1B8u) == 0u) goto label_000C4C18;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000C4BA3;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C4BA3:
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->ecx -= 2u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4BC5u)); sfera_sub_004A5330(cpu, LIFT_CODE_TOKEN_VA(0x4C4BC5u));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"_");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4BF2u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C4BF2u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->edx >= 0) goto label_000C4C06;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C4C06:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4C0Fu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C4C0Fu));
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC4C18u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_RVA(0xC4C18u));
    label_000C4C18:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C4C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = 0u;
    cpu->ebp = cpu->ecx;
    if (cpu->edi == cpu->esi) goto label_000C4D4A;
    if (cpu->edi == 1u) goto label_000C4D77;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000C4D77;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint8_t*)(cpu->ecx) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    --cpu->edi;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    if (cpu->eax == 0u) goto label_000C4D4A;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    lift_push32(cpu, cpu->ebx);
    label_000C4CA0:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x198u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000C4CB2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C4CB2:
    cpu->ecx = cpu->eax;
    cpu->edi = cpu->ecx + 1u;
    label_000C4CB7:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C4CB7;
    cpu->ecx -= cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx + cpu->esi + 1u;
    if ((int32_t)cpu->ebx > (int32_t)cpu->edi) goto label_000C4D53;
    cpu->ecx = cpu->eax;
    label_000C4CD2:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C4CD2;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->edi = cpu->edx + 0xFFFFFFFFu;
    label_000C4CE4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000C4CE4;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = cpu->edx + 0xFFFFFFFFu;
    label_000C4D00:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000C4D00;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    *(uint16_t*)(cpu->edi) = cpu->ecx & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0x198u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    ++cpu->edi;
    cpu->eax += cpu->edx;
    cpu->esi = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if (cpu->edi < cpu->eax) goto label_000C4CA0;
    cpu->ebx = lift_pop32(cpu);
    label_000C4D4A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000C4D53:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi -= cpu->esi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4C4D5Fu));
    cpu->esp += 0xCu;
    cpu->edi += cpu->esi;
    *(uint8_t*)(cpu->edi + cpu->ebx) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000C4D77:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->edx) = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C4D90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if (*(uint8_t*)(cpu->esi + 0x48u) != (cpu->ebx & 0xFFu)) goto label_000C510D;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C510D;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->ebx) goto label_000C4DF6;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_000C4DE8;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC4DE8u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC4DE8u));
    label_000C4DE8:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    label_000C4DF6:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4E23u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C4E23u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    g_sfera_screen_clip_runtime.left = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4E3Au)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C4E3Au));
    cpu->ebp = cpu->eax;
    g_sfera_screen_clip_runtime.top = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    if ((int32_t)cpu->ecx >= 0) goto label_000C4E52;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C4E52:
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4E5Bu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C4E5Bu));
    g_sfera_screen_clip_runtime.right = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu)))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->edx >= 0) goto label_000C4E70;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C4E70:
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4E77u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C4E77u));
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = 0u;
    cpu->edx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4ECCu)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4C4ECCu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ebx;
    if (cpu->edi >= cpu->eax) goto label_000C4EE6;
    cpu->edi = cpu->eax;
    label_000C4EE6:
    if (cpu->ebp >= cpu->ebx) goto label_000C4EEC;
    cpu->ebp = cpu->ebx;
    label_000C4EEC:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->ebx + cpu->edi;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000C4EFB;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000C4EFB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->eax + cpu->ebp;
    if ((int32_t)cpu->ecx <= (int32_t)cpu->edx) goto label_000C4F0A;
    cpu->edx -= cpu->ebp;
    cpu->eax = cpu->edx;
    label_000C4F0A:
    if ((int32_t)cpu->edi >= 0) goto label_000C4F12;
    cpu->ebx += cpu->edi;
    cpu->edi = 0u;
    label_000C4F12:
    if ((int32_t)cpu->ebp >= 0) goto label_000C4F1A;
    cpu->eax += cpu->ebp;
    cpu->ebp = 0u;
    label_000C4F1A:
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    cpu->edx = cpu->ebx + cpu->edi;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ecx) goto label_000C4F2B;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000C4F2B:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = cpu->eax + cpu->ebp;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ecx) goto label_000C4F3C;
    cpu->ecx -= cpu->ebp;
    cpu->eax = cpu->ecx;
    label_000C4F3C:
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    lift_x87_push(cpu, 1.0);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C4F68u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4C4F68u));
    if (*(uint32_t*)(cpu->esi + 0xDCu) != 0xFFu) goto label_000C4F84;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000C4F84;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC4F84u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xC4F84u));
    label_000C4F84:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x198u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if ((int32_t)cpu->eax <= 0) goto label_000C5046;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->eax -= cpu->ecx;
    ++cpu->edx;
    if (cpu->eax <= cpu->edx) goto label_000C4FC8;
    cpu->eax = cpu->edx;
    label_000C4FC8:
    if ((int32_t)cpu->eax <= 0) goto label_000C5046;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = cpu->ecx * 8u;
    cpu->edi -= cpu->ecx;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->ebx = cpu->eax;
    (void)cpu;
    label_000C4FE0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->eax += cpu->edi;
    cpu->edi += 0x1Cu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000C4FF3;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C4FF3:
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C501Cu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C501Cu));
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5025u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C5025u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C0u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1C0u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000C503B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C503B:
    --cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->ebx != 0u) goto label_000C4FE0;
    label_000C5046:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x1C0u));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C506B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C506B:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->esp -= 8u;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C508Cu)); sfera_sub_004C4AB0(cpu, LIFT_CODE_TOKEN_VA(0x4C508Cu));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xDCu) == 0xFFu;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C50AD;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000C50AD;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC50ADu)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xC50ADu));
    label_000C50AD:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C50BDu)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4C50BDu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (cpu->ecx == 0u) goto label_000C510D;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000C5100;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C50E9;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C50E9:
    cpu->fpu[0u] = (cpu->fpu[0u]) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000C5100:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1CCu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000C510D:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C5120(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    (void)0; /* source SEH registration eliminated */
    cpu->eax = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->esi = cpu->eax * 8u;
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x198u);
    cpu->esi -= cpu->eax;
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    cpu->ebx = 0u;
    cpu->ecx = 0x10u;
    cpu->esi = cpu->edx + (cpu->esi * 4u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ecx) goto label_000C5198;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    goto label_000C519C;
    label_000C5198:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000C519C:
    *(uint8_t*)(cpu->esp + 0x19u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x44u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebp;
    *(uint8_t*)(cpu->esp + 0x30u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebp;
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->ecx) goto label_000C51BD;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_000C51BF;
    label_000C51BD:
    cpu->ecx = cpu->esi;
    label_000C51BF:
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint8_t*)(cpu->edi + 0x8Du);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C51DDu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C51DDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C52E7;
    label_000C51F0:
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x8Du);
    ++*(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x8Cu);
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C521Au)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C521Au));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1BCu);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->edx > *(uint32_t*)(cpu->edi + 0x28u)) goto label_000C52BB;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x18u));
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax -= cpu->ebp;
    if (cpu->eax <= 1u) goto label_000C532B;
    cpu->esi = cpu->ebp + 1u;
    if (cpu->esi > 0xFFFFFFFEu) goto label_000C532B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    if (cpu->eax >= cpu->esi) goto label_000C530A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5266u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x4C5266u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    if (cpu->esi == 0u) goto label_000C529D;
    label_000C5272:
    sub_pred[0] = cpu->eax < 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    if (!sub_pred[0]) goto label_000C527F;
    cpu->eax = cpu->esp + 0x30u;
    label_000C527F:
    *(uint8_t*)(cpu->eax + cpu->ebp) = cpu->ebx & 0xFFu;
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x44u) < 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    if (!sub_pred[1]) goto label_000C5295;
    cpu->eax = cpu->esp + 0x30u;
    label_000C5295:
    *(uint8_t*)(cpu->eax + cpu->esi) = 0u;
    label_000C5299:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    label_000C529D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    if ((cpu->eax & 0xFFu) != 0u) goto label_000C51F0;
    label_000C52BB:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ebx <= 0) goto label_000C52D3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC52D3u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_RVA(0xC52D3u));
    label_000C52D3:
    if (*(uint32_t*)(cpu->esp + 0x44u) < 0x10u) goto label_000C52E7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C52E4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C52E4u));
    cpu->esp += 4u;
    label_000C52E7:
    cpu->eax = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000C530A:
    if (cpu->esi != 0u) goto label_000C5272;
    sub_pred[2] = cpu->eax < 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    if (!sub_pred[2]) goto label_000C5323;
    cpu->eax = cpu->esp + 0x30u;
    label_000C5323:
    *(uint8_t*)(cpu->eax) = 0u;
    goto label_000C5299;
    label_000C532B:
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4C532Bu), "std::length_error");
    lift_trap(cpu, 0x4C5336u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004C5340(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->edi = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->ecx -= cpu->edi;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ebx = cpu->edx;
    cpu->ebx >>= 31u;
    cpu->ebx += cpu->edx;
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->edi;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->esi = cpu->ebx;
    if (cpu->ebx == 0u) goto label_000C53D1;
    label_000C53C0:
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->esi, 32u, 1u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = cpu->edx;
    if (cpu->edx != 0u) goto label_000C53C0;
    label_000C53D1:
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000C54C3;
    if ((int32_t)cpu->eax <= 0) goto label_000C54C3;
    cpu->ecx = cpu->ebx * 8u;
    cpu->ecx -= cpu->ebx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->esi = cpu->edi + (cpu->edx * 4u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    goto label_000C5410;
    label_000C5404:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000C5410:
    cpu->ecx += cpu->esi;
    if (cpu->ecx != cpu->ebp) goto label_000C5418;
    cpu->ecx = cpu->edi;
    label_000C5418:
    if (cpu->esi == cpu->ecx) goto label_000C546C;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    label_000C546C:
    cpu->edi = cpu->ebp;
    cpu->edi -= cpu->ecx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ebx >= (int32_t)cpu->eax) goto label_000C548F;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x1Cu);
    goto label_000C54A3;
    label_000C548F:
    cpu->ecx = cpu->ebx;
    cpu->ecx -= cpu->eax;
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->ecx + (cpu->eax * 4u);
    label_000C54A3:
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_000C5418;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) - (uint64_t)(0x1Cu) - (uint64_t)(0u);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax > 0) goto label_000C5404;
    label_000C54C3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C54F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::RichEditCtrl*>(cpu->esi));
    cpu->edi = 0u;
    g_sfera_texture_cache_runtime.render_gate = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (*(uint32_t*)(cpu->esi + 0x1CCu) == cpu->edi) goto label_000C555F;
    cpu->edx = 0x8Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\RichEditCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5546u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C5546u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (cpu->ecx == cpu->edi) goto label_000C5559;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000C5559:
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->edi;
    label_000C555F:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == cpu->edi) goto label_000C558F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esi + 0x1A4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5580u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4C5580u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C558Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C558Cu));
    cpu->esp += 4u;
    label_000C558F:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C55B0u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4C55B0u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C55D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    goto label_000C55D0;
    label_000C4680:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C4694;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4694:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    sub_pred[0] = cpu->esi < cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C46B0;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C46B0:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u) >= (int32_t)0u) goto label_000C46C3;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C46C3:
    sfera_sub_004C45C0(cpu, stop_address); return;
    label_000C55D0:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ecx = cpu->ebx * 8u;
    cpu->ecx -= cpu->ebx;
    cpu->ecx = cpu->eax + (cpu->ecx * 4u);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->ecx + 0x10u) <= cpu->ebp) goto label_000C56D1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ACu);
    if (cpu->eax != cpu->ebp) goto label_000C56C0;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ebp -= *(uint32_t*)(cpu->esi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 1u);
    cpu->edx += cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax <= 1u) goto label_000C578F;
    if (cpu->ebx == 0u) goto label_000C578F;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->ebx);
    --cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5645u)); sfera_sub_004C5120(cpu, LIFT_CODE_TOKEN_VA(0x4C5645u));
    if ((int32_t)cpu->eax <= 0) goto label_000C56A6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edx + (cpu->ecx * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5669u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4C5669u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u) + 0x10u) != 0u) goto label_000C56A6;
    if ((int32_t)cpu->eax <= 0) goto label_000C5695;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->ecx = cpu->ecx + (cpu->edx * 4u);
    label_000C5695:
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC56A6u)); sfera_sub_0040B7D0(cpu, LIFT_CODE_TOKEN_RVA(0xC56A6u));
    label_000C56A6:
    --*(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ebp;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000C4680;
    label_000C56C0:
    --cpu->eax;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C56CFu)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4C56CFu));
    goto label_000C5745;
    label_000C56D1:
    if ((int32_t)cpu->ebx <= (int32_t)cpu->ebp) goto label_000C573F;
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->ecx * 8u;
    cpu->edx -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->eax + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C56F7u)); sfera_sub_0040A270(cpu, LIFT_CODE_TOKEN_VA(0x4C56F7u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1A4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx + 0xFFFFFFE4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5711u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4C5711u));
    *(uint32_t*)(cpu->esi + 0x19Cu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x19Cu)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u);
    --*(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x10u);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ecx;
    goto label_000C5745;
    label_000C573F:
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ebp;
    label_000C5745:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x1C8u)) goto label_000C5759;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C5759:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if (cpu->edx >= cpu->eax) goto label_000C5773;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C5773:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C8u) >= (int32_t)cpu->ebp) goto label_000C5781;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ebp;
    label_000C5781:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004C45C0(cpu, stop_address); return;
    label_000C578F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C57A0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    goto label_000C57A0;
    label_000C4680:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u)) goto label_000C4694;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C4694:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1C8u);
    cpu->esi += cpu->edx;
    sub_pred[0] = cpu->esi < cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000C46B0;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = cpu->eax;
    label_000C46B0:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x1C8u) >= (int32_t)0u) goto label_000C46C3;
    *(uint32_t*)(cpu->ecx + 0x1C8u) = 0u;
    label_000C46C3:
    sfera_sub_004C45C0(cpu, stop_address); return;
    label_000C57A0:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->eax = cpu->edi * 8u;
    cpu->eax -= cpu->edi;
    cpu->ecx = cpu->ebx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax == 0u) goto label_000C57DC;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    if (cpu->edx == cpu->eax) goto label_000C57DC;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C57D7u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4C57D7u));
    goto label_000C5937;
    label_000C57DC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1ACu);
    if (cpu->ecx != cpu->eax) goto label_000C58C2;
    if (cpu->ecx == 0u) goto label_000C58C2;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->edx = cpu->edx + cpu->ecx + 0xFFFFFFFFu;
    if (cpu->edi == cpu->edx) goto label_000C58C2;
    cpu->eax = cpu->edi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5823u)); sfera_sub_004C5120(cpu, LIFT_CODE_TOKEN_VA(0x4C5823u));
    if ((int32_t)cpu->eax <= 0) goto label_000C58B5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    ++cpu->eax;
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edx + (cpu->ecx * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C584Cu)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4C584Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u) + 0x2Cu) != 0u) goto label_000C58B5;
    ++cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_000C5880;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->ecx = cpu->ecx + (cpu->edx * 4u) + 0x1Cu;
    label_000C5880:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx += 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5894u)); sfera_sub_0040A270(cpu, LIFT_CODE_TOKEN_VA(0x4C5894u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esi + 0x1A4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edx + 0xFFFFFFE4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C58AEu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4C58AEu));
    *(uint32_t*)(cpu->esi + 0x19Cu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x19Cu)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u);
    label_000C58B5:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000C4680;
    label_000C58C2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000C5937;
    --cpu->eax;
    if (cpu->edi == cpu->eax) goto label_000C5937;
    cpu->eax = cpu->ebx;
    if ((int32_t)cpu->edi <= 0) goto label_000C58F8;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->ecx * 8u;
    cpu->edx -= cpu->ecx;
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    label_000C58F8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->eax + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C590Cu)); sfera_sub_0040A270(cpu, LIFT_CODE_TOKEN_VA(0x4C590Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1A4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx + 0xFFFFFFE4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5926u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4C5926u));
    *(uint32_t*)(cpu->esi + 0x19Cu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x19Cu)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0u;
    label_000C5937:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x1C8u)) goto label_000C594B;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C594B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if (cpu->edx >= cpu->eax) goto label_000C5965;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C5965:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C8u) >= (int32_t)0u) goto label_000C5978;
    *(uint32_t*)(cpu->esi + 0x1C8u) = 0u;
    label_000C5978:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004C45C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C5990(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5998u)); sfera_sub_004C54F0(cpu, LIFT_CODE_TOKEN_VA(0x4C5998u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C59A8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C59A5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C59A5u));
    cpu->esp += 4u;
    label_000C59A8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C59B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C59BEu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4C59BEu));
    cpu->eax = cpu->edi + 0x198u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C59D0u)); sfera_sub_004C3290(cpu, LIFT_CODE_TOKEN_VA(0x4C59D0u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1A8u);
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1ACu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1B0u);
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1B8u));
    *(uint8_t*)(cpu->esi + 0x1B8u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1BCu);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1C0u);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C4u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1CCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C5A50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->esi >= cpu->ecx) goto label_000C5AD2;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if (cpu->eax > cpu->esi) goto label_000C5AD2;
    cpu->esi -= cpu->eax;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_000C5AA9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5AA9u)); sfera_sub_00411060(cpu, LIFT_CODE_TOKEN_RVA(0xC5AA9u));
    label_000C5AA9:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi * 8u;
    cpu->eax -= cpu->esi;
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000C5B0E;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    goto label_000C5AFD;
    label_000C5AD2:
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_000C5AE0;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5AE0u)); sfera_sub_00411060(cpu, LIFT_CODE_TOKEN_RVA(0xC5AE0u));
    label_000C5AE0:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (cpu->ecx == cpu->edx) goto label_000C5B0E;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    label_000C5AFD:
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5B0Eu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xC5B0Eu));
    label_000C5B0E:
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C5B30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ebp = cpu->edx;
    cpu->ebp = cpu->ebp >> 31u;
    cpu->ebp += cpu->edx;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000C5B83;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5B83u)); sfera_sub_00411060(cpu, LIFT_CODE_TOKEN_RVA(0xC5B83u));
    label_000C5B83:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000C5BC0;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    cpu->eax = cpu->edi;
    cpu->ebx = cpu->eax + 1u;
    label_000C5BB0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C5BB0;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5BC0u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xC5BC0u));
    label_000C5BC0:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->ebp * 8u;
    cpu->edi -= cpu->ebp;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->edx = cpu->eax + 0xFFFFFFE4u;
    cpu->ecx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFFFFFFFFu;
    if (cpu->ecx == cpu->edx) goto label_000C5BF5;
    if (cpu->edx == cpu->eax) goto label_000C5BF5;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5BF5u)); sfera_sub_004C5340(cpu, LIFT_CODE_TOKEN_RVA(0xC5BF5u));
    label_000C5BF5:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx += cpu->edi;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C5C20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ebp = cpu->edx;
    cpu->ebp = cpu->ebp >> 31u;
    cpu->ebp += cpu->edx;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000C5C72;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5C72u)); sfera_sub_00411060(cpu, LIFT_CODE_TOKEN_RVA(0xC5C72u));
    label_000C5C72:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (cpu->ecx == 0u) goto label_000C5CA8;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5CA8u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xC5CA8u));
    label_000C5CA8:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->ebp * 8u;
    cpu->edi -= cpu->ebp;
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->edx = cpu->eax + 0xFFFFFFE4u;
    cpu->ecx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    if (cpu->ecx == cpu->edx) goto label_000C5CDD;
    if (cpu->edx == cpu->eax) goto label_000C5CDD;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5CDDu)); sfera_sub_004C5340(cpu, LIFT_CODE_TOKEN_RVA(0xC5CDDu));
    label_000C5CDD:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx += cpu->edi;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C5D00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x30u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5D3Bu)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4C5D3Bu));
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::RichEditCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x18u;
    *(uint8_t*)(cpu->esp + 0x40u) = 1u;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x50u) = 0x11u;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5DC0u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C5DC0u));
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    *(uint8_t*)(cpu->esp + 0x3Cu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5DD5u)); sfera_sub_004C5A50(cpu, LIFT_CODE_TOKEN_VA(0x4C5DD5u));
    if (*(uint32_t*)(cpu->esp + 0x24u) < 0x10u) goto label_000C5DE9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5DE6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C5DE6u));
    cpu->esp += 4u;
    label_000C5DE9:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C5E10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x6Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\RichEditCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5E44u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C5E44u));
    lift_push32(cpu, 0x1D0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5E4Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C5E4Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000C5E6C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5E68u)); sfera_sub_004C5D00(cpu, LIFT_CODE_TOKEN_VA(0x4C5E68u));
    cpu->esi = cpu->eax;
    goto label_000C5E6E;
    label_000C5E6C:
    cpu->esi = 0u;
    label_000C5E6E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5E7Eu)); sfera_sub_004C59B0(cpu, LIFT_CODE_TOKEN_VA(0x4C5E7Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000C5EA6;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5EA6u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC5EA6u));
    label_000C5EA6:
    if (*(uint32_t*)(cpu->edi + 0x1CCu) == 0u) goto label_000C5ECA;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1CCu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC5ECAu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC5ECAu));
    label_000C5ECA:
    cpu->eax = *(uint8_t*)(cpu->edi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5ED9u)); sfera_sub_004C44F0(cpu, LIFT_CODE_TOKEN_VA(0x4C5ED9u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5EE0u)); sfera_sub_004C45C0(cpu, LIFT_CODE_TOKEN_VA(0x4C5EE0u));
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C5F00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x4Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x60u));
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x198u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->ebp = cpu->ecx + 0x198u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx -= cpu->esi;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->eax & 0xFFu;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    *(uint8_t*)(cpu->esp + 0x15u) = 0u;
    if (cpu->ebx < cpu->ecx) goto label_000C5FD5;
    cpu->esi = 0u;
    cpu->eax = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x40u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x2Cu) = 0u;
    cpu->edx = cpu->eax + 1u;
    label_000C5F90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C5F90;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5FA8u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C5FA8u));
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5FB8u)); sfera_sub_004C5A50(cpu, LIFT_CODE_TOKEN_VA(0x4C5FB8u));
    if (*(uint32_t*)(cpu->esp + 0x40u) < 0x10u) goto label_000C60A1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5FCDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C5FCDu));
    cpu->esp += 4u;
    goto label_000C60A1;
    label_000C5FD5:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->edi = cpu->ebx * 8u;
    cpu->edi -= cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edi += cpu->edi;
    lift_push32(cpu, 1u);
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C5FF6u)); sfera_sub_0048E480(cpu, LIFT_CODE_TOKEN_VA(0x4C5FF6u));
    cpu->esi = *(uint32_t*)(cpu->ebp);
    cpu->esi += cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_000C60A1;
    label_000C6005:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000C600F;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_000C6011;
    label_000C600F:
    cpu->ecx = cpu->esi;
    label_000C6011:
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint8_t*)(cpu->eax + 0x8Du);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->eax + 0x8Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6033u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C6033u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1BCu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->ecx <= *(uint32_t*)(cpu->eax + 0x28u)) goto label_000C60A1;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000C6050;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_000C6052;
    label_000C6050:
    cpu->ecx = cpu->esi;
    label_000C6052:
    cpu->eax = cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    label_000C6060:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C6060;
    cpu->eax -= *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->ecx + 0xFFFFFFFFu));
    --cpu->eax;
    lift_push32(cpu, 1u);
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C607Eu)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4C607Eu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->ebx + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6092u)); sfera_sub_004C5F00(cpu, LIFT_CODE_TOKEN_VA(0x4C6092u));
    cpu->esi = *(uint32_t*)(cpu->ebp);
    cpu->esi += cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x10u) != 0u) goto label_000C6005;
    label_000C60A1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C60D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x60u;
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->edi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000C6167;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    if (cpu->eax == cpu->ecx) goto label_000C6167;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6146u)); sfera_sub_0040A270(cpu, LIFT_CODE_TOKEN_VA(0x4C6146u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x1A4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6161u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4C6161u));
    *(uint32_t*)(cpu->edi + 0x19Cu) = cpu->ebp;
    label_000C6167:
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    *(uint8_t*)(cpu->esp + 0x24u) = 0u;
    sub_pred[0] = *(uint8_t*)(cpu->ebx) == 0u;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebp;
    *(uint8_t*)(cpu->esp + 0x19u) = 0u;
    if (sub_pred[0]) goto label_000C622D;
    label_000C6190:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx));
    ++cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) != 0xAu) goto label_000C61A2;
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    goto label_000C61DE;
    label_000C61A2:
    cpu->edx = *(uint8_t*)(cpu->edi + 0x8Du);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x8Cu);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C61C8u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C61C8u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1BCu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax += cpu->ebp;
    if (cpu->eax <= *(uint32_t*)(cpu->edi + 0x28u)) goto label_000C61FD;
    lift_push32(cpu, cpu->ecx);
    label_000C61DE:
    cpu->ecx = cpu->edi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C61E9u)); sfera_sub_004C5A50(cpu, LIFT_CODE_TOKEN_VA(0x4C61E9u));
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C61F9u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C61F9u));
    cpu->ebp = 0u;
    goto label_000C620D;
    label_000C61FD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6209u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x4C6209u));
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000C620D:
    if (*(uint8_t*)(cpu->ebx) != 0u) goto label_000C6190;
    if (*(uint32_t*)(cpu->esp + 0x34u) <= 0u) goto label_000C622D;
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC622Du)); sfera_sub_004C5A50(cpu, LIFT_CODE_TOKEN_RVA(0xC622Du));
    label_000C622D:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->edi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    cpu->ebx = 0x10u;
    if (cpu->ecx != 0u) goto label_000C62A5;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x48u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x58u) = 0u;
    *(uint8_t*)(cpu->esp + 0x48u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6278u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C6278u));
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x198u;
    *(uint8_t*)(cpu->esp + 0x6Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C628Du)); sfera_sub_004C5A50(cpu, LIFT_CODE_TOKEN_VA(0x4C628Du));
    *(uint8_t*)(cpu->esp + 0x68u) = 0u;
    if (*(uint32_t*)(cpu->esp + 0x54u) < cpu->ebx) goto label_000C62A5;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C62A2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C62A2u));
    cpu->esp += 4u;
    label_000C62A5:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->edi + 0x198u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->eax = cpu->edx + cpu->ecx + 0xFFFFFFFFu;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    *(uint32_t*)(cpu->edi + 0x1A8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1A8u);
    *(uint32_t*)(cpu->edi + 0x1ACu) = cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->edi + 0x1C8u)) goto label_000C62F9;
    *(uint32_t*)(cpu->edi + 0x1C8u) = cpu->eax;
    label_000C62F9:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1C4u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if (cpu->edx >= cpu->eax) goto label_000C6313;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x1C8u) = cpu->eax;
    label_000C6313:
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x1C8u) >= (int32_t)0u) goto label_000C6326;
    *(uint32_t*)(cpu->edi + 0x1C8u) = 0u;
    label_000C6326:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C632Du)); sfera_sub_004C45C0(cpu, LIFT_CODE_TOKEN_VA(0x4C632Du));
    if (*(uint32_t*)(cpu->esp + 0x38u) < cpu->ebx) goto label_000C6340;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C633Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C633Du));
    cpu->esp += 4u;
    label_000C6340:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->eax != 0x1771u) goto label_000C6395;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->eax == 0u) goto label_000C638C;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC638Cu)); sfera_sub_004C60D0(cpu, LIFT_CODE_TOKEN_RVA(0xC638Cu));
    label_000C638C:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C6395:
    if (cpu->eax != 0x1772u) goto label_000C63BA;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->eax == 0u) goto label_000C63B1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC63B1u)); sfera_sub_004C4C20(cpu, LIFT_CODE_TOKEN_RVA(0xC63B1u));
    label_000C63B1:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C63BA:
    if (cpu->eax != 0x66u) goto label_000C63E0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_000C63D7;
    *(uint32_t*)(cpu->esi + 0x1C8u) = 0u;
    label_000C63D7:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C63E0:
    if (cpu->eax != 0x69u) goto label_000C6441;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp + 0xCu) != 0u);
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C6438;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    *(uint8_t*)(cpu->esi + 0x4Au) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C640Cu)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4C640Cu));
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6420u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4C6420u));
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6434u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4C6434u));
    *(uint8_t*)(cpu->esi + 0x4Au) = 1u;
    label_000C6438:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C6441:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6453u)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4C6453u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx + (cpu->ecx * 4u);
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x25u) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000C6498;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    goto label_000C649A;
    label_000C6498:
    cpu->ecx = cpu->edi;
    label_000C649A:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C64B8u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C64B8u));
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C64DAu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C64DAu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != *(uint32_t*)(cpu->edi + 0x10u)) goto label_000C658E;
    if (cpu->ecx < *(uint32_t*)(cpu->esi + 0x28u)) goto label_000C6579;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x198u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ecx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    if (cpu->edi != cpu->ecx) goto label_000C655A;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    if ((int32_t)cpu->edi <= 0) goto label_000C653F;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->ecx * 8u;
    cpu->edx -= cpu->ecx;
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    label_000C653F:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6558u)); sfera_sub_004C5B30(cpu, LIFT_CODE_TOKEN_VA(0x4C6558u));
    goto label_000C6566;
    label_000C655A:
    ++cpu->edi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC6566u)); sfera_sub_004C5F00(cpu, LIFT_CODE_TOKEN_RVA(0xC6566u));
    label_000C6566:
    cpu->ebx = 1u;
    *(uint32_t*)(cpu->esi + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1A8u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ebx;
    goto label_000C65C0;
    label_000C6579:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6583u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x4C6583u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    goto label_000C65C0;
    label_000C658E:
    if (cpu->ecx < *(uint32_t*)(cpu->esi + 0x28u)) goto label_000C65AB;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C65A3u)); sfera_sub_004C5F00(cpu, LIFT_CODE_TOKEN_VA(0x4C65A3u));
    ++*(uint32_t*)(cpu->esi + 0x1ACu);
    goto label_000C65C0;
    label_000C65AB:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C65BAu)); sfera_sub_0048E480(cpu, LIFT_CODE_TOKEN_VA(0x4C65BAu));
    *(uint32_t*)(cpu->esi + 0x1ACu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1ACu)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    label_000C65C0:
    cpu->edx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1ACu) >= (int32_t)cpu->edx) goto label_000C65D0;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edx;
    label_000C65D0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->ecx * 4u) + 0x10u);
    if (*(uint32_t*)(cpu->esi + 0x1ACu) <= cpu->ecx) goto label_000C65F7;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ecx;
    label_000C65F7:
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x1C8u)) goto label_000C6605;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C6605:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edi += cpu->ecx;
    if (cpu->edi >= cpu->eax) goto label_000C661F;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C661F:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C8u) >= (int32_t)cpu->edx) goto label_000C662D;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->edx;
    label_000C662D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6634u)); sfera_sub_004C45C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6634u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6640(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x38u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->edi = cpu->ecx + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 0x10u)) goto label_000C66D3;
    cpu->ebx = 0u;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_000C66A9;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->ecx = cpu->ecx + (cpu->edx * 4u);
    label_000C66A9:
    cpu->eax = cpu->ecx + 0x1Cu;
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C66C2u)); sfera_sub_004C5B30(cpu, LIFT_CODE_TOKEN_VA(0x4C66C2u));
    ++*(uint32_t*)(cpu->esi + 0x1A8u);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ebx;
    goto label_000C679F;
    label_000C66D3:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000C66DD;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000C66DF;
    label_000C66DD:
    cpu->eax = cpu->edi;
    label_000C66DF:
    cpu->ecx = cpu->edx + cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFu;
    cpu->edx = cpu->eax + 1u;
    label_000C6700:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000C6700;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6714u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C6714u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ebx = 0u;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C672Eu)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4C672Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1A8u) <= (int32_t)cpu->ebx) goto label_000C674E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx = cpu->ecx * 8u;
    cpu->edx -= cpu->ecx;
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    label_000C674E:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6767u)); sfera_sub_004C5C20(cpu, LIFT_CODE_TOKEN_VA(0x4C6767u));
    ++*(uint32_t*)(cpu->esi + 0x1A8u);
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x2Cu) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x40u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_000C678F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C678Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C678Cu));
    cpu->esp += 4u;
    label_000C678F:
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ebx & 0xFFu;
    label_000C679F:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x1C8u)) goto label_000C67B3;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C67B3:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edx += cpu->ecx;
    if (cpu->edx >= cpu->eax) goto label_000C67CD;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000C67CD:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C8u) >= (int32_t)cpu->ebx) goto label_000C67DB;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ebx;
    label_000C67DB:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C67E2u)); sfera_sub_004C45C0(cpu, LIFT_CODE_TOKEN_VA(0x4C67E2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000C6826;
    g_sfera_texture_cache_runtime.render_gate = 1u;
    label_000C6826:
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C69BD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    if (cpu->edi == cpu->ebx) goto label_000C6870;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_000C6862;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC6862u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC6862u));
    label_000C6862:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x14u);
    label_000C6870:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000C691A;
    cpu->eax = *(uint8_t*)(cpu->edi + 0x15u);
    if ((cpu->eax & 0xFFu) < 0x20u) goto label_000C688E;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC688Eu)); sfera_sub_004C6460(cpu, LIFT_CODE_TOKEN_RVA(0xC688Eu));
    label_000C688E:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x14u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C691A;
    cpu->eax = cpu->eax & 0xFFu;
    cpu->eax += 0xFFFFFFF8u;
    if (cpu->eax > 0x26u) goto label_000C691A;
    switch (cpu->eax) {
        case 0u: goto label_000C68B2;
        case 5u: goto label_000C68FD;
        case 25u: goto label_000C690F;
        case 26u: goto label_000C6906;
        case 27u: goto label_000C68F4;
        case 28u: goto label_000C68E8;
        case 29u: goto label_000C68C4;
        case 30u: goto label_000C68D6;
        case 31u: goto label_000C68CD;
        case 32u: goto label_000C68DF;
        case 38u: goto label_000C68BB;
        default: goto label_000C691A;
    }
label_000C68B2: ;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C68B9u)); sfera_sub_004C55D0(cpu, LIFT_CODE_TOKEN_VA(0x4C68B9u));
    goto label_000C6916;
    label_000C68BB:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C68C2u)); sfera_sub_004C57A0(cpu, LIFT_CODE_TOKEN_VA(0x4C68C2u));
    goto label_000C6916;
    label_000C68C4:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C68CBu)); sfera_sub_004C46D0(cpu, LIFT_CODE_TOKEN_VA(0x4C68CBu));
    goto label_000C6916;
    label_000C68CD:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C68D4u)); sfera_sub_004C4760(cpu, LIFT_CODE_TOKEN_VA(0x4C68D4u));
    goto label_000C6916;
    label_000C68D6:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C68DDu)); sfera_sub_004C4820(cpu, LIFT_CODE_TOKEN_VA(0x4C68DDu));
    goto label_000C6916;
    label_000C68DF:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C68E6u)); sfera_sub_004C48B0(cpu, LIFT_CODE_TOKEN_VA(0x4C68E6u));
    goto label_000C6916;
    label_000C68E8:
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0u;
    goto label_000C6916;
    label_000C68F4:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C68FBu)); sfera_sub_004C45A0(cpu, LIFT_CODE_TOKEN_VA(0x4C68FBu));
    goto label_000C6916;
    label_000C68FD:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6904u)); sfera_sub_004C6640(cpu, LIFT_CODE_TOKEN_VA(0x4C6904u));
    goto label_000C6916;
    label_000C6906:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C690Du)); sfera_sub_004C49F0(cpu, LIFT_CODE_TOKEN_VA(0x4C690Du));
    goto label_000C6916;
    label_000C690F:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC6916u)); sfera_sub_004C4960(cpu, LIFT_CODE_TOKEN_RVA(0xC6916u));
    label_000C6916:
    *(uint8_t*)(cpu->edi + 0x14u) = 0u;
    label_000C691A:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (cpu->ecx == 0u) goto label_000C692C;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000C692C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += cpu->ebp;
    cpu->ecx += cpu->ebx;
    if (((*(uint8_t*)(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000C69BA;
    cpu->edx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_000C69AB;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    if ((int32_t)cpu->edx >= (int32_t)cpu->ebx) goto label_000C69AB;
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->edi < (int32_t)cpu->ecx) goto label_000C69AB;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_000C69AB;
    if (*(uint8_t*)(cpu->esi + 0x4Au) != 0u) goto label_000C69BA;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6975u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4C6975u));
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6989u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4C6989u));
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C699Du)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4C699Du));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x4Au) = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C69AB:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x69u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C69BA:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C69BD:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6A28u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4C6A28u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    *(uint16_t*)(cpu->esi + 0x1D0u) = cpu->eax & 0xFFFFu;
    *(uint8_t*)(cpu->esi + 0x1D2u) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1C8u) = 1u;
    *(uint32_t*)(cpu->esi + 0x1CCu) = 0x14u;
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1F0u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x50u) = 5u;
    *(uint32_t*)(cpu->esi + 0x1C0u) = 0x64u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6AD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x1B0u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[0]) goto label_000C6B31;
    cpu->edx = 0x5Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6B1Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6B1Eu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    if (cpu->ecx == 0u) goto label_000C6B31;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000C6B31:
    if (*(uint32_t*)(cpu->esi + 0x1B4u) == 0u) goto label_000C6B5C;
    cpu->edx = 0x5Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6B49u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6B49u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->ecx == 0u) goto label_000C6B5C;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000C6B5C:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6B6Bu)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6B6Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6B97u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4C6B97u));
    if (*(uint32_t*)(cpu->esi + 0x9Cu) != 0u) goto label_000C6BBA;
    lift_push32(cpu, 0x6Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6BB1u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6BB1u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6BB7u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6BB7u));
    cpu->esp += 0x10u;
    label_000C6BBA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"horizontal");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6BCDu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C6BCDu));
    if (cpu->eax == 0u) goto label_000C6BE8;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6BDAu)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4C6BDAu));
    if (cpu->eax == 0u) goto label_000C6BE8;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 1u;
    label_000C6BE8:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"bounds");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6BF5u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C6BF5u));
    if (cpu->eax == 0u) goto label_000C6C4C;
    cpu->ecx = cpu->esi + 0x1ECu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x1E8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x1E4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1E0u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C6C1Eu));
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000C6C4C;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Invalid args in 'bounds'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6C43u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6C43u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6C49u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6C49u));
    cpu->esp += 0x14u;
    label_000C6C4C:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"postMessage");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6C59u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C6C59u));
    if (cpu->eax == 0u) goto label_000C6C71;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6C66u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4C6C66u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->eax!=0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x1D2u) = cpu->eax & 0xFFu;
    label_000C6C71:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"drawMethod");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6C7Eu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C6C7Eu));
    if (cpu->eax == 0u) goto label_000C6D1F;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6C94u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C6C94u));
    if (cpu->eax == 0u) goto label_000C6D1F;
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"SPRITE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xC6CAEu), LIFT_CODE_TOKEN_RVA(0xC6CACu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000C6D08;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6CC3u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C6CC3u));
    if (cpu->eax == 0u) goto label_000C6D1F;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6CD7u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4C6CD7u));
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000C6D1F;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6CFDu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6CFDu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6D03u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6D03u));
    cpu->esp += 0x18u;
    goto label_000C6D1F;
    label_000C6D08:
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xC6D14u), LIFT_CODE_TOKEN_RVA(0xC6D12u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000C6D1F;
    *(uint32_t*)(cpu->esi + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x24u)) | (uint64_t)(2u);
    label_000C6D1F:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"scrollSpr");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6D2Cu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C6D2Cu));
    if (cpu->eax == 0u) goto label_000C6DD3;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6D42u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C6D42u));
    if (cpu->eax == 0u) goto label_000C6DD3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6D5Au)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4C6D5Au));
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000C6D89;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6D80u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6D80u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6D86u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6D86u));
    cpu->esp += 0x18u;
    label_000C6D89:
    cpu->ecx = cpu->esi + 0x1A0u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x19Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.scroll_bar_value[0]);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%s %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C6DA5u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000C6DD3;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ScrollBar::LoadUI(%s,%d,%d) -> Not enough args in 'scrollSpr'.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6DCAu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6DCAu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6DD0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C6DD0u));
    cpu->esp += 0x14u;
    label_000C6DD3:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"leftbutton");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6DE7u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4C6DE7u));
    cpu->ebx = 6u;
    if (cpu->eax == 0u) goto label_000C6E20;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 1u); lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6E06u)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4C6E06u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6E14u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6E14u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    *(uint32_t*)(cpu->eax + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x1A8u)) | (uint64_t)(cpu->ebx);
    label_000C6E20:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"rightbutton");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6E34u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4C6E34u));
    if (cpu->eax == 0u) goto label_000C6E68;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 2u); lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6E4Eu)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4C6E4Eu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6E5Cu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4C6E5Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    *(uint32_t*)(cpu->eax + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x1A8u)) | (uint64_t)(cpu->ebx);
    label_000C6E68:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"deltaStep");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6E75u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C6E75u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000C6E91;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6E84u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C6E84u));
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1D1u) = 1u;
    label_000C6E91:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6EA6u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4C6EA6u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C6EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C7110;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C7110;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == 0u) goto label_000C6F18;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000C6F0A;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC6F0Au)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC6F0Au));
    label_000C6F0A:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000C6F18:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(float*)(cpu->esp + 0xCu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    if (cpu->ecx==0u) goto label_000C6FBF;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->ecx >= 0) goto label_000C6F76;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C6F76:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000C6F97;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C6F97:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6FB7u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_VA(0x4C6FB7u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    label_000C6FBF:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->edi == 0u) goto label_000C7067;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 0x1BCu)) goto label_000C7067;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1A4u)))));
    lift_push32(cpu, cpu->ebx);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C6FEFu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C6FEFu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1A8u)))));
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7000u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C7000u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx <<= 24u;
    cpu->ecx |= 0xFFFFFFu;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x5Cu) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x7Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->esp -= 0x10u;
    cpu->edx += cpu->ebx;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7064u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_VA(0x4C7064u));
    cpu->ebx = lift_pop32(cpu);
    goto label_000C706B;
    label_000C7067:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C706B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edi = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_000C70BC;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000C70AF;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C7098;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C7098:
    cpu->fpu[0u] = (cpu->fpu[0u]) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x10u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000C70AF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000C70BC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->ecx == 0u) goto label_000C7110;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000C70FF;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C70E8;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C70E8:
    cpu->fpu[0u] = (cpu->fpu[0u]) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x10u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000C70FF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C7110:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7120(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if (cpu->ecx == 0u) goto label_000C714E;
    lift_push32(cpu, cpu->ebx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000C714E:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->ecx == 0u) goto label_000C7160;
    lift_push32(cpu, cpu->ebx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000C7160:
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7174u)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4C7174u));
    cpu->ebp = 1u;
    if (cpu->eax == 0u) goto label_000C7216;
    cpu->edi = 0x3E9u;
    label_000C7186:
    if (*(uint32_t*)(cpu->esp + 0x2Cu) != cpu->edi) goto label_000C7202;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if ((cpu->eax -= cpu->ebp) == 0u) goto label_000C71BA;
    if ((cpu->eax -= cpu->ebp) != 0u) goto label_000C7202;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C0u);
    if (cpu->eax == cpu->ecx) goto label_000C7202;
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000C71E0;
    goto label_000C71DA;
    label_000C71BA:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    if (cpu->eax == cpu->ecx) goto label_000C7202;
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000C71E0;
    label_000C71DA:
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    label_000C71E0:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == 0u) goto label_000C7202;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_line.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7202u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xC7202u));
    label_000C7202:
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C720Eu)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4C720Eu));
    if (cpu->eax != 0u) goto label_000C7186;
    label_000C7216:
    if (*(uint32_t*)(cpu->ebx + 8u) == 0u) goto label_000C7320;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    if (cpu->edi == 0u) goto label_000C7320;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000C7251;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7251u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC7251u));
    label_000C7251:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->ebp = *(uint32_t*)(cpu->ebx);
    cpu->edx += cpu->eax;
    cpu->edi += cpu->ecx;
    if ((int32_t)cpu->ebp < (int32_t)cpu->eax) goto label_000C7320;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edx) goto label_000C7320;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000C7320;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edi) goto label_000C7320;
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000C72B9;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x1BCu)) goto label_000C72B9;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x1C0u)) goto label_000C72B9;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_line.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC72B9u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xC72B9u));
    label_000C72B9:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->ecx >= 0) goto label_000C72D8;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x1C4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1C4u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    goto label_000C72E7;
    label_000C72D8:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x1C4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1C4u)) - (uint64_t)(cpu->edx) - (uint64_t)(0u);
    label_000C72E7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C4u) <= (int32_t)cpu->eax) goto label_000C72FB;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000C72FB:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C4u) >= (int32_t)cpu->eax) goto label_000C730F;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000C730F:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    label_000C7320:
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (1u)) == 0u) goto label_000C73E6;
    if (*(uint8_t*)(cpu->esi + 0x1D0u) != 0u) goto label_000C73E6;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->edx = 0u;
    cpu->edi = 0u;
    if (cpu->ebp == cpu->edx) goto label_000C7374;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000C7366;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7366u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC7366u));
    label_000C7366:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x10u);
    label_000C7374:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ebp = *(uint32_t*)(cpu->ebx);
    cpu->eax += cpu->edx;
    cpu->ecx += cpu->edi;
    if ((int32_t)cpu->ebp < (int32_t)cpu->eax) goto label_000C73BA;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ebx += cpu->eax;
    sub_pred[3] = (int32_t)(cpu->ebp) < (int32_t)(cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    if (!sub_pred[3]) goto label_000C73BA;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000C73BA;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ebp += cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ebp) goto label_000C73BA;
    *(uint8_t*)(cpu->esi + 0x1D0u) = 1u;
    label_000C73BA:
    cpu->edx += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x34u);
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000C73E6;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx += cpu->edx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000C73E6;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_000C73E6;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->edi;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000C73E6;
    *(uint8_t*)(cpu->esi + 0x1F0u) = 1u;
    label_000C73E6:
    if (((*(uint8_t*)(cpu->ebx + 0x10u)) & (1u)) != 0u) goto label_000C73FA;
    *(uint8_t*)(cpu->esi + 0x1D0u) = 0u;
    *(uint8_t*)(cpu->esi + 0x1F0u) = 0u;
    label_000C73FA:
    if (*(uint8_t*)(cpu->esi + 0x1D0u) == 0u) goto label_000C7540;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->ecx = 0u;
    cpu->eax = 0u;
    if (cpu->edi == cpu->ebp) goto label_000C7446;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if (cpu->ecx == cpu->ebp) goto label_000C7438;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7438u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC7438u));
    label_000C7438:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    label_000C7446:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edx += cpu->eax;
    if (((*(uint8_t*)(cpu->esi + 0x1ACu)) & (1u)) == 0u) goto label_000C74CD;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)(cpu->eax) >= 0) goto label_000C7467;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000C7467:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->eax <= cpu->ecx) goto label_000C7472;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_000C7472:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000C749C;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C749C:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x14u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C74ABu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C74ABu));
    if (*(uint32_t*)(cpu->esi + 0x1C4u) == cpu->eax) goto label_000C7540;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->ecx = 1u;
    goto label_000C7544;
    label_000C74CD:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)(cpu->eax) >= 0) goto label_000C74DE;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000C74DE:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->eax <= cpu->ecx) goto label_000C74E9;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_000C74E9:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000C7513;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C7513:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x14u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7522u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C7522u));
    if (*(uint32_t*)(cpu->esi + 0x1C4u) == cpu->eax) goto label_000C7540;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->ecx = 1u;
    goto label_000C7544;
    label_000C7540:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000C7544:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x14u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C75D1;
    if (cpu->ecx != 0u) goto label_000C784F;
    cpu->eax = cpu->eax & 0xFFu;
    if ((cpu->eax -= 0x21u) == 0u) goto label_000C75AF;
    if ((--cpu->eax) != 0u) goto label_000C75D9;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C0u);
    if (cpu->eax == cpu->ecx) goto label_000C75D9;
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000C7588;
    label_000C7582:
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    label_000C7588:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000C784F;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_page.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C75AAu)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_VA(0x4C75AAu));
    goto label_000C784F;
    label_000C75AF:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    if (cpu->eax == cpu->ecx) goto label_000C75D9;
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000C7588;
    goto label_000C7582;
    label_000C75D1:
    if (cpu->ecx != 0u) goto label_000C784F;
    label_000C75D9:
    if (*(uint8_t*)(cpu->esi + 0x1D0u) != 0u) goto label_000C7861;
    if (*(uint8_t*)(cpu->esi + 0x1F0u) == 0u) goto label_000C7861;
    if (((*(uint8_t*)(cpu->ebx + 0x10u)) & (1u)) == 0u) goto label_000C7861;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7602u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4C7602u));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x1D8u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x1D8u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1DCu) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x14u)))))) / (10000.0));
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=0.10000000149011612; if (!(lift_left>lift_right)) goto label_000C7861; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C763Eu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4C763Eu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->edx;
    if (cpu->edi == 0u) goto label_000C7687;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000C7679;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7679u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC7679u));
    label_000C7679:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    label_000C7687:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebp += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx = cpu->ecx + cpu->ebp;
    cpu->ebp += *(uint32_t*)(cpu->esi + 0x1E4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    cpu->edx = cpu->edi + cpu->eax;
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1E0u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_000C7861;
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1E8u);
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_000C7861;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)cpu->ebp) goto label_000C7861;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_000C7861;
    if (((*(uint8_t*)(cpu->esi + 0x1ACu)) & (1u)) == 0u) goto label_000C779B;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1E8u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1E0u);
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    if ((int32_t)(cpu->eax) >= 0) goto label_000C7731;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C7731:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1BCu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7754u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C7754u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    if (cpu->ecx == cpu->eax) goto label_000C7861;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx -= cpu->ebx;
    cpu->ebx = cpu->edx + cpu->edi;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->ebx) goto label_000C778A;
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->eax) goto label_000C7846;
    goto label_000C7840;
    label_000C778A:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ebx += cpu->edx;
    cpu->ebx += cpu->edi;
    sub_pred[1] = cpu->ebp == cpu->ebx; sub_pred[2] = (int32_t)(cpu->ebp) < (int32_t)(cpu->ebx);
    goto label_000C782E;
    label_000C779B:
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1E4u);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    if ((int32_t)(cpu->ecx) >= 0) goto label_000C77C5;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C77C5:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1BCu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C77E8u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C77E8u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    if (cpu->ecx == cpu->eax) goto label_000C7861;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx -= cpu->edi;
    cpu->edi = cpu->edx + cpu->ebp;
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edi) goto label_000C7822;
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->eax) goto label_000C7817;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000C7817:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    goto label_000C784F;
    label_000C7822:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edi += cpu->edx;
    cpu->edi += cpu->ebp;
    sub_pred[1] = cpu->ebx == cpu->edi; sub_pred[2] = (int32_t)(cpu->ebx) < (int32_t)(cpu->edi);
    label_000C782E:
    if ((sub_pred[1]) || (sub_pred[2])) goto label_000C7861;
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    if ((int32_t)cpu->ecx <= (int32_t)cpu->eax) goto label_000C7846;
    label_000C7840:
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000C7846:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    label_000C784F:
    if (*(uint32_t*)(cpu->esi + 0x9Cu) == 0u) goto label_000C7861;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->loadControlParameters(cpu);
    label_000C7861:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7880(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1C4u)))));
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1BCu);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0x1B8u) = cpu->fpu[0u];
    lift_x87_push(cpu, 0.0);
    { const double lift_left=cpu->fpu[0u]; const double lift_right=cpu->fpu[1u]; cpu->fpu[1u]=cpu->fpu[0u]; lift_x87_pop(cpu); if (!(lift_left>lift_right)) goto label_000C78C4; }
    *(float*)(cpu->esi + 0x1B8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000C78C6;
    label_000C78C4:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C78C6:
    lift_x87_push(cpu, 1.0);
    { const double lift_left=cpu->fpu[0u]; const double lift_right=((double)*(float*)(cpu->esi + 0x1B8u)); if (!(lift_left<lift_right)) goto label_000C78DD; }
    *(float*)(cpu->esi + 0x1B8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000C78DF;
    label_000C78DD:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C78DF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1E8u);
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1E0u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x1E4u);
    cpu->ecx -= cpu->ebx;
    cpu->edi -= cpu->ebp;
    if (((*(uint8_t*)(cpu->esi + 0x1ACu)) & (1u)) == 0u) goto label_000C794E;
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = cpu->edi;
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1A0u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x1B8u)));
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7936u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C7936u));
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1A4u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1A8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C794E:
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax = cpu->ecx;
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x1B8u)));
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C797Au)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C797Au));
    *(uint32_t*)(cpu->esi + 0x1A4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1A4u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1A8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C79A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 1u;
    cpu->esi = cpu->ecx;
    if ((uint8_t)((*(uint8_t*)(cpu->edi + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_000C79FB;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x1BCu) != cpu->eax) goto label_000C79CF;
    cpu->ebx = 0u;
    label_000C79CF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    if (cpu->ecx == 0u) goto label_000C79E5;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C79E5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->ecx == 0u) goto label_000C79FB;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C79FB:
    if (((*(uint8_t*)(cpu->edi + 4u)) & (4u)) == 0u) goto label_000C7A2E;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000C7A1A;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    label_000C7A1A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C4u) <= (int32_t)cpu->eax) goto label_000C7A2E;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000C7A2E:
    if (((*(uint8_t*)(cpu->edi + 4u)) & (2u)) == 0u) goto label_000C7A3D;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ecx;
    label_000C7A3D:
    if (((*(uint8_t*)(cpu->edi + 4u)) & (0x10u)) == 0u) goto label_000C7A55;
    if (*(uint8_t*)(cpu->esi + 0x1D1u) != 0u) goto label_000C7A55;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->edx;
    label_000C7A55:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->ecx)->updateControlState(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1BCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C0u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1CCu);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1C4u);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1C8u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->eax + 0xFFFFF63Bu;
    if (cpu->ecx > 0x63u) goto label_000C7C4B;
    cpu->ecx = cpu->eax + 0xFFFFF63Bu;
    if (cpu->ecx > 0x63u) goto label_000C7C4B;
    switch (cpu->ecx) {
        case 0u: goto label_000C7AE3;
        case 1u: goto label_000C7B23;
        case 2u: goto label_000C7BB2;
        case 3u: goto label_000C7B88;
        case 4u: goto label_000C7BD3;
        case 5u: goto label_000C7BE8;
        case 6u: goto label_000C7C29;
        case 99u: goto label_000C7B9D;
        default: goto label_000C7C4B;
    }
label_000C7AE3: ;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->eax) goto label_000C7AFD;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000C7AFD:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C4u) <= (int32_t)cpu->eax) goto label_000C7B11;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000C7B11:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C7B23:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    cpu->edi = 1u;
    if (cpu->eax != cpu->ecx) goto label_000C7B49;
    cpu->edi = 0u;
    label_000C7B49:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    if (cpu->ecx == 0u) goto label_000C7B5F;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C7B5F:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->ecx == 0u) goto label_000C7B75;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C7B75:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C7B88:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7B94u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_VA(0x4C7B94u));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C7B9D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C7BB2:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C7BD3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7BDFu)); sfera_sub_004C7A70(cpu, LIFT_CODE_TOKEN_VA(0x4C7BDFu));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C7BE8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C0u);
    if (cpu->eax == cpu->ecx) goto label_000C7C20;
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000C7C0E;
    label_000C7C08:
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    label_000C7C0E:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->updateControlState(cpu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::ScrollBar*>(cpu->esi)->loadControlParameters(cpu);
    label_000C7C20:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C7C29:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    if (cpu->eax == cpu->ecx) goto label_000C7C20;
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000C7C0E;
    goto label_000C7C08;
    label_000C7C4B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7C5Du)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4C7C5Du));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x9Cu) == 0u) goto label_000C7D39;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->edx = cpu->edx & 0xFFu;
    cpu->edx = -cpu->edx;
    cpu->edx = (cpu->edx != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->edx += 0x66u;
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C7D39:
    if (*(uint8_t*)(cpu->esi + 0x1D2u) == 0u) goto label_000C7D85;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax += 0x66u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000C7D85;
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7D85u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xC7D85u));
    label_000C7D85:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + 0x1ACu) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1ACu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7DC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7DC8u)); sfera_sub_004C6AD0(cpu, LIFT_CODE_TOKEN_VA(0x4C7DC8u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C7DD8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7DD5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C7DD5u));
    cpu->esp += 4u;
    label_000C7DD8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7DEEu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4C7DEEu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1A0u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1A4u);
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1A8u);
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1ACu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1B0u);
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->ecx;
    *(float*)(cpu->esi + 0x1B8u) = (double)*(float*)(cpu->edi + 0x1B8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1BCu);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C0u);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1C4u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x1D0u);
    *(uint8_t*)(cpu->esi + 0x1D0u) = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1D1u));
    *(uint8_t*)(cpu->esi + 0x1D1u) = cpu->edx & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1D2u));
    *(uint8_t*)(cpu->esi + 0x1D2u) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1D8u);
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1DCu);
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1E0u);
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1E4u);
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1E8u);
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x1F0u);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x1F0u) = cpu->ecx & 0xFFu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C7F20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xF0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7F54u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C7F54u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7F5Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C7F5Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000C7F7C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7F78u)); sfera_sub_004C6A20(cpu, LIFT_CODE_TOKEN_VA(0x4C7F78u));
    cpu->esi = cpu->eax;
    goto label_000C7F7E;
    label_000C7F7C:
    cpu->esi = 0u;
    label_000C7F7E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C7F8Eu)); sfera_sub_004C7DE0(cpu, LIFT_CODE_TOKEN_VA(0x4C7F8Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0x1B0u) == 0u) goto label_000C7FB6;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7FB6u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC7FB6u));
    label_000C7FB6:
    if (*(uint32_t*)(cpu->edi + 0x1B4u) == 0u) goto label_000C7FDA;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7FDAu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC7FDAu));
    label_000C7FDA:
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000C7FFE;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC7FFEu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC7FFEu));
    label_000C7FFE:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C8020(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8028u)); sfera_sub_004C6A20(cpu, LIFT_CODE_TOKEN_VA(0x4C8028u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x238u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1F8u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x240u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x23Cu) = cpu->eax;
    std::construct_at(reinterpret_cast<SphereUI::SliderCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 0xBu;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 1u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C8060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x9Cu);
    if (cpu->ecx == 0u) goto label_000C80A2;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xD8u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x1C4u);
    cpu->edx = cpu->esp;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0xCu) = 0xED8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC80A2u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xC80A2u));
    label_000C80A2:
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C80C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C80D9u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4C80D9u));
    if (*(uint32_t*)(cpu->edi + 0x9Cu) != 0u) goto label_000C80FF;
    lift_push32(cpu, 0x8Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SliderCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C80F6u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C80F6u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C80FCu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C80FCu));
    cpu->esp += 0x10u;
    label_000C80FF:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"range");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8110u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C8110u));
    cpu->ebp = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000C815A;
    cpu->ecx = cpu->edi + 0x1C0u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x1BCu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xC8133u), LIFT_CODE_TOKEN_RVA(0xC8131u))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000C815A;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SliderCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'range'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8151u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C8151u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8157u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C8157u));
    cpu->esp += 0x14u;
    label_000C815A:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"step");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8167u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C8167u));
    if (cpu->eax == 0u) goto label_000C817A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8174u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C8174u));
    *(uint32_t*)(cpu->edi + 0x1C8u) = cpu->eax;
    label_000C817A:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"page");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8187u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C8187u));
    if (cpu->eax == 0u) goto label_000C819A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8194u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C8194u));
    *(uint32_t*)(cpu->edi + 0x1CCu) = cpu->eax;
    label_000C819A:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"defaultPos");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C81A7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C81A7u));
    if (cpu->eax == 0u) goto label_000C81BA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C81B4u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C81B4u));
    *(uint32_t*)(cpu->edi + 0x1C4u) = cpu->eax;
    label_000C81BA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"statusPos");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C81C7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C81C7u));
    if (cpu->eax == 0u) goto label_000C820B;
    cpu->ecx = cpu->edi + 0x240u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x23Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xC81E4u), LIFT_CODE_TOKEN_RVA(0xC81E2u))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000C820B;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SliderCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'statusPos'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8202u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C8202u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8208u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C8208u));
    cpu->esp += 0x14u;
    label_000C820B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"statusShow");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8218u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C8218u));
    if (cpu->eax == 0u) goto label_000C823E;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.slider_status_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C822Au)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C822Au));
    if (cpu->eax == 0u) goto label_000C823E;
    cpu->ecx = (uintptr_t)&g_sfera_ui_load_scratch_runtime.slider_status_value[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8238u)); sfera_sub_004C3B40(cpu, LIFT_CODE_TOKEN_VA(0x4C8238u));
    *(uint32_t*)(cpu->edi + 0x238u) = cpu->eax;
    label_000C823E:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C824Au)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4C824Au));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8258u)); sfera_sub_004C6B80(cpu, LIFT_CODE_TOKEN_VA(0x4C8258u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C8270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8278u)); sfera_sub_004C7880(cpu, LIFT_CODE_TOKEN_VA(0x4C8278u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x238u);
    if (cpu->eax == 0u) goto label_000C82DA;
    if ((--cpu->eax) == 0u) goto label_000C82B3;
    if ((--cpu->eax) != 0u) goto label_000C82DA;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d / %d");
    cpu->esi += 0x1F8u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C82A8u));
    cpu->esp += 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C82B3:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x1B8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (100.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C82C4u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C82C4u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d%%");
    cpu->esi += 0x1F8u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C82D1u));
    cpu->esp += 0xCu;
    label_000C82DA:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C82E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C83EA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C82F5u)); sfera_sub_004C6EC0(cpu, LIFT_CODE_TOKEN_VA(0x4C82F5u));
    if (*(uint32_t*)(cpu->esi + 0x238u) <= 0u) goto label_000C83EA;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = 0u;
    cpu->edi = 0u;
    if (cpu->ebx == 0u) goto label_000C8341;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000C8333;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8333u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC8333u));
    label_000C8333:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x10u);
    label_000C8341:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x23Cu);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (2u & 0xFFu);
    cpu->ecx += cpu->eax;
    g_sfera_screen_clip_runtime.left = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x240u);
    cpu->edx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax = cpu->ecx + 0x64u;
    cpu->edx += cpu->edi;
    g_sfera_screen_clip_runtime.right = cpu->eax;
    cpu->eax = cpu->edx + 0x64u;
    cpu->edi = 0xFFu;
    g_sfera_screen_clip_runtime.top = cpu->edx;
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->edi) goto label_000C839D;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= (cpu->ebx & 0xFFu)) goto label_000C839D;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8391u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4C8391u));
    cpu->ecx = g_sfera_screen_clip_runtime.left;
    cpu->edx = g_sfera_screen_clip_runtime.top;
    label_000C839D:
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esi + 0x1F8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C83C8u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C83C8u));
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->edi) goto label_000C83E8;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= (cpu->ebx & 0xFFu)) goto label_000C83E8;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000C83E8:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C83EA:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C83F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C83FFu)); sfera_sub_004C7DE0(cpu, LIFT_CODE_TOKEN_VA(0x4C83FFu));
    cpu->ecx = cpu->ebp;
    cpu->eax = cpu->esi + 0x1F8u;
    cpu->ecx -= cpu->esi;
    cpu->edi = 0x40u;
    label_000C8410:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->eax));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if ((--cpu->edi) != 0u) goto label_000C8410;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x238u);
    *(uint32_t*)(cpu->esi + 0x238u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x23Cu);
    *(uint32_t*)(cpu->esi + 0x23Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x240u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x240u) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C8450(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x53u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SliderCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8485u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C8485u));
    lift_push32(cpu, 0x248u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C848Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C848Fu));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    if (cpu->esi == cpu->ebx) goto label_000C84DA;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C84A9u)); sfera_sub_004C6A20(cpu, LIFT_CODE_TOKEN_VA(0x4C84A9u));
    std::construct_at(reinterpret_cast<SphereUI::SliderCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 0xBu;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 1u;
    *(uint32_t*)(cpu->esi + 0x238u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1F8u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x240u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x23Cu) = cpu->ebx;
    goto label_000C84DC;
    label_000C84DA:
    cpu->esi = 0u;
    label_000C84DC:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C84ECu)); sfera_sub_004C83F0(cpu, LIFT_CODE_TOKEN_VA(0x4C84ECu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0x1B0u) == cpu->ebx) goto label_000C8513;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8513u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC8513u));
    label_000C8513:
    if (*(uint32_t*)(cpu->edi + 0x1B4u) == cpu->ebx) goto label_000C8536;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8536u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC8536u));
    label_000C8536:
    if (*(uint32_t*)(cpu->edi + 0xECu) == cpu->ebx) goto label_000C8559;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8559u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC8559u));
    label_000C8559:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C8570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    if (*(uint8_t*)(cpu->eax + 0x48u) == 0u) goto label_000C8599;
    cpu->eax = 0u;
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000C8599:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xD8u);
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = 0x138Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C85BEu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4C85BEu));
    cpu->eax = 1u;
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C85E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C8CF8;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C8CF8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->ebp) goto label_000C863C;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if (cpu->ecx == cpu->ebp) goto label_000C862E;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC862Eu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC862Eu));
    label_000C862E:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    label_000C863C:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ecx);
    *(float*)(cpu->esp + 0x14u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A4u);
    { int64_t v=(int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx); cpu->eax= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    *(float*)(cpu->esp + 0x10u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->eax <<= 16u;
    cpu->eax^=*(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ebx <<= 16u;
    cpu->eax &= 0xFFFFFFu;
    cpu->eax^=cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->edx = cpu->ecx;
    cpu->edx <<= 24u;
    cpu->ebx &= 0xFFFFFFu;
    cpu->edi = cpu->edx;
    cpu->ebx |= cpu->edx;
    cpu->edi |= 0xFFFFFFu;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x250u) == 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    if (sub_pred[0]) goto label_000C8702;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == cpu->ebp) goto label_000C8702;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B4u)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B0u)))));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8700u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4C8700u));
    goto label_000C874F;
    label_000C8702:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx == cpu->ebp) goto label_000C874B;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B4u)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B0u)))));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8749u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4C8749u));
    goto label_000C874F;
    label_000C874B:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C874F:
    if (*(uint8_t*)(cpu->esi + 0x251u) == 0u) goto label_000C8821;
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1F4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x214u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x234u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x1BCu) >= cpu->eax) goto label_000C87A4;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->eax -= cpu->edx;
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    label_000C87A4:
    if (*(uint32_t*)(cpu->esi + 0x1C0u) >= cpu->ecx) goto label_000C87BE;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->ecx -= cpu->eax;
    cpu->ecx >>= 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    label_000C87BE:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    cpu->ecx = cpu->esi + 0x1B8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x2Cu) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) + (((double)*(float*)(cpu->esp + 0x20u))));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u)))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x3Cu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8821u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_RVA(0xC8821u));
    label_000C8821:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x288u);
    if (cpu->eax == cpu->ebp) goto label_000C8862;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edi;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1.0);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x288u);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8862u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_RVA(0xC8862u));
    label_000C8862:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28Cu);
    if (cpu->eax == cpu->ebp) goto label_000C88F5;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu)))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28Cu);
    if ((int32_t)cpu->edx >= 0) goto label_000C8892;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C8892:
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x10u)));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ecx + 8u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C88A6;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C88A6:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->esp -= 8u;
    cpu->fpu[1u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000C88CD;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C88CD:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ecx + 4u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C88E1;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C88E1:
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC88F5u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_RVA(0xC88F5u));
    label_000C88F5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x290u);
    if (cpu->eax == cpu->ebp) goto label_000C89B0;
    lift_x87_push(cpu, (double)3.0f);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edi;
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edi;
    lift_x87_push(cpu, (double)2.0f);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->edi;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    lift_x87_push(cpu, 1.0);
    if (cpu->eax != 0xFFFFFFFFu) goto label_000C893C;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000C893E;
    label_000C893C:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C893E:
    if (cpu->eax != 0xFFFFFFFEu) goto label_000C894F;
    *(float*)(cpu->esp + 0x18u) = (double)(0.0);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000C8951;
    label_000C894F:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000C8951:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x18u)));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x290u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu)))));
    if ((int32_t)cpu->edx >= 0) goto label_000C896F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C896F:
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ecx + 8u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000C8981;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C8981:
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp -= 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (1.0);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x34u);
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->esp + 0x24u))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC89B0u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_RVA(0xC89B0u));
    label_000C89B0:
    if (*(uint32_t*)(cpu->esi + 0x64u) <= cpu->ebp) goto label_000C8CA6;
    if (*(uint8_t*)(cpu->esi + 0x251u) != 0u) goto label_000C89CC;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (4u)) == 0u) goto label_000C8CA6;
    label_000C89CC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    if (*(uint8_t*)(cpu->esi + 0x49u) == 0u) goto label_000C89DE;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x98u);
    label_000C89DE:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->ecx <<= 24u;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->eax &= 0xFFFFFFu;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C89FDu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C89FDu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    g_sfera_screen_clip_runtime.left = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8A0Du)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8A0Du));
    g_sfera_screen_clip_runtime.top = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    if ((int32_t)cpu->ecx >= 0) goto label_000C8A22;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C8A22:
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8A2Bu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8A2Bu));
    g_sfera_screen_clip_runtime.right = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu)))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->edx >= 0) goto label_000C8A40;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000C8A40:
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8A47u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8A47u));
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    cpu->edi = 0u;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x118u) == cpu->ebp) goto label_000C8AD5;
    cpu->eax = cpu->esi + 0x54u;
    if (*(uint32_t*)(cpu->esi + 0x68u) < 0x10u) goto label_000C8A63;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C8A63:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8A83u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C8A83u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x118u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000C8A9D;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->ebp >= cpu->eax) goto label_000C8A9D;
    cpu->eax -= cpu->ebp;
    cpu->edi = cpu->eax;
    label_000C8A9D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if ((((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_000C8AB1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->ecx >= cpu->eax) goto label_000C8AB1;
    cpu->eax -= cpu->ecx;
    cpu->ebx = cpu->eax;
    label_000C8AB1:
    if ((((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000C8AC3;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->ebp >= cpu->eax) goto label_000C8AC3;
    cpu->eax -= cpu->ebp;
    cpu->eax >>= 1u;
    cpu->edi = cpu->eax;
    label_000C8AC3:
    if ((((cpu->edx & 0xFFu)) & (8u)) == 0u) goto label_000C8AD5;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->ecx >= cpu->eax) goto label_000C8AD5;
    cpu->eax -= cpu->ecx;
    cpu->eax >>= 1u;
    cpu->ebx = cpu->eax;
    label_000C8AD5:
    cpu->edi += *(uint32_t*)(cpu->esi + 0x27Cu);
    cpu->ebx += *(uint32_t*)(cpu->esi + 0x280u);
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0xDCu) == 0xFFu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    if (!sub_pred[1]) goto label_000C8B05;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000C8B05;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8B05u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xC8B05u));
    label_000C8B05:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->edi = cpu->esi + 0x54u;
    cpu->ebp = cpu->ebp << 24u;
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000C8B1F;
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    goto label_000C8B23;
    label_000C8B1F:
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    label_000C8B23:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x10u)));
    *(double*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8B3Au)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8B3Au));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(double*)(cpu->esp + 0x38u) = cpu->fpu[0u];
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8B53u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8B53u));
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8B7Eu)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C8B7Eu));
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000C8B8C;
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    goto label_000C8B90;
    label_000C8B8C:
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    label_000C8B90:
    lift_x87_push(cpu, *(double*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8B9Fu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8B9Fu));
    cpu->fpu[0u] = (*(double*)(cpu->esp + 0x38u)) - (cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8BACu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8BACu));
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8BD7u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C8BD7u));
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000C8BE1;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000C8BE3;
    label_000C8BE1:
    cpu->eax = cpu->edi;
    label_000C8BE3:
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8C08u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C8C08u));
    cpu->ebx = 0x10u;
    if (*(uint32_t*)(cpu->edi + 0x14u) < cpu->ebx) goto label_000C8C16;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000C8C18;
    label_000C8C16:
    cpu->eax = cpu->edi;
    label_000C8C18:
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8C3Fu)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C8C3Fu));
    if (*(uint32_t*)(cpu->edi + 0x14u) < cpu->ebx) goto label_000C8C46;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_000C8C46:
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, *(double*)(cpu->esp + 0x38u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8C6Du)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8C6Du));
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, *(double*)(cpu->esp + 0x50u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8C78u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4C8C78u));
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8C81u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4C8C81u));
    if (*(uint32_t*)(cpu->esi + 0xDCu) != 0xFFu) goto label_000C8CA0;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000C8CA0;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8CA0u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xC8CA0u));
    label_000C8CA0:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = 0u;
    label_000C8CA6:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    if (cpu->eax == cpu->ebp) goto label_000C8CF5;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->ebx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B4u)))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->esp -= 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x34u);
    *(float*)(cpu->esp + 0x34u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B0u)))))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8CF5u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_RVA(0xC8CF5u));
    label_000C8CF5:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C8CF8:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C8D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C8F3F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->edx) goto label_000C8D5B;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000C8D4D;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8D4Du)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC8D4Du));
    label_000C8D4D:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x18u);
    label_000C8D5B:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += cpu->edx;
    cpu->edi += cpu->eax;
    cpu->ebp += cpu->ecx;
    if (g_sfera_direct_input_runtime.keyboard_state[0x2A] != 0u) goto label_000C8D86;
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x36]) == 0u) goto label_000C8D8B;
    label_000C8D86:
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    label_000C8D8B:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_000C8EB0;
    if ((int32_t)cpu->edx >= (int32_t)cpu->edi) goto label_000C8EB0;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000C8EB0;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ebp) goto label_000C8EB0;
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (1u)) == 0u) goto label_000C8DEB;
    if (*(uint8_t*)(cpu->esi + 0x25Cu) != 0u) goto label_000C8DEB;
    if (*(uint8_t*)(cpu->esi + 0x25Eu) != 0u) goto label_000C8DEB;
    if (*(uint8_t*)(cpu->esp + 0x13u) != 0u) goto label_000C8DEB;
    *(uint8_t*)(cpu->esi + 0x25Cu) = 1u;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->ecx;
    label_000C8DEB:
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (2u)) == 0u) goto label_000C8DF8;
    *(uint8_t*)(cpu->esi + 0x25Du) = 1u;
    label_000C8DF8:
    if (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03 != 0u) goto label_000C8EB0;
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (4u)) == 0u) goto label_000C8E41;
    if (*(uint8_t*)(cpu->esp + 0x13u) != 0u) goto label_000C8E41;
    if (*(uint8_t*)(cpu->esi + 0x25Cu) == 0u) goto label_000C8E41;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x3E9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8E41u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xC8E41u));
    label_000C8E41:
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (8u)) == 0u) goto label_000C8E7D;
    if (*(uint8_t*)(cpu->esp + 0x13u) != 0u) goto label_000C8E7D;
    if (*(uint8_t*)(cpu->esi + 0x25Du) == 0u) goto label_000C8E7D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x3EDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8E7Du)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xC8E7Du));
    label_000C8E7D:
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (1u)) == 0u) goto label_000C8E8E;
    if (*(uint8_t*)(cpu->esp + 0x13u) == 0u) goto label_000C8E8E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_000C8E90;
    label_000C8E8E:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    label_000C8E90:
    cpu->eax = cpu->esi + 0x260u;
    if (*(uint32_t*)(cpu->esi + 0x274u) < 0x10u) goto label_000C8EA1;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C8EA1:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8EA9u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4C8EA9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8EB0u)); sfera_sub_004A2740(cpu, LIFT_CODE_TOKEN_RVA(0xC8EB0u));
    label_000C8EB0:
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (8u)) == 0u) goto label_000C8EBD;
    *(uint8_t*)(cpu->esi + 0x25Du) = 0u;
    label_000C8EBD:
    if (((*(uint8_t*)(cpu->ebx + 0x10u)) & (1u)) != 0u) goto label_000C8ED1;
    *(uint8_t*)(cpu->esi + 0x25Cu) = 0u;
    *(uint8_t*)(cpu->esi + 0x25Eu) = 0u;
    label_000C8ED1:
    if (*(uint8_t*)(cpu->esi + 0x25Cu) == 0u) goto label_000C8F3C;
    if (*(uint8_t*)(cpu->esi + 0x25Eu) != 0u) goto label_000C8F3C;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x254u);
    cpu->eax -= *(uint32_t*)(cpu->ebx);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax > (int32_t)2u) goto label_000C8F08;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x258u);
    cpu->eax -= *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)2u) goto label_000C8F3C;
    label_000C8F08:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x138Bu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8F2Eu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4C8F2Eu));
    *(uint8_t*)(cpu->esi + 0x25Cu) = 0u;
    *(uint8_t*)(cpu->esi + 0x25Eu) = 1u;
    label_000C8F3C:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C8F3F:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C8F60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8F8Eu)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4C8F8Eu));
    cpu->ebx = 0u;
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    std::construct_at(reinterpret_cast<SphereUI::SlotCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A4u) = 0x80u;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C8FCBu)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4C8FCBu));
    *(uint16_t*)(cpu->esi + 0x250u) = cpu->ebx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + 0x25Cu) = cpu->ebx & 0xFFFFu;
    *(uint8_t*)(cpu->esi + 0x25Eu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x274u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x270u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x260u) = cpu->ebx & 0xFFu;
    cpu->eax = 2u;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esi + 0x280u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x8Cu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x28Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x290u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 0xEu;
    *(uint8_t*)(cpu->esi + 0x4Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x27Cu) = 0xFFFFFFFEu;
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x118u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1A8u) = 0x141414u;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0xFF9E7C6Au;
    *(uint32_t*)(cpu->esi + 0x90u) = 0xFFFFFFFFu;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::SlotCtrl*>(cpu->esi));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x288u);
    *(uint32_t*)(cpu->esp + 0x14u) = 2u;
    if (cpu->ecx == 0u) goto label_000C90C5;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC90C5u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_RVA(0xC90C5u));
    label_000C90C5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28Cu);
    if (cpu->ecx == 0u) goto label_000C90D4;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC90D4u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_RVA(0xC90D4u));
    label_000C90D4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x290u);
    if (cpu->ecx == 0u) goto label_000C90E3;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC90E3u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_RVA(0xC90E3u));
    label_000C90E3:
    if (*(uint32_t*)(cpu->esi + 0x274u) < 0x10u) goto label_000C90FB;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x260u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C90F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C90F8u));
    cpu->esp += 4u;
    label_000C90FB:
    *(uint32_t*)(cpu->esi + 0x274u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x270u) = 0u;
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint8_t*)(cpu->esi + 0x260u) = 0u;
    *(uint8_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9126u)); sfera_sub_004CF160(cpu, LIFT_CODE_TOKEN_VA(0x4C9126u));
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9135u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4C9135u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9158u)); sfera_sub_004C9080(cpu, LIFT_CODE_TOKEN_VA(0x4C9158u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C9168;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9165u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C9165u));
    cpu->esp += 4u;
    label_000C9168:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9170(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp != cpu->ebx) goto label_000C91F2;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esi + 0x54u;
    *(uint16_t*)(cpu->esi + 0x250u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9196u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C9196u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esi + 0x260u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C91A7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C91A7u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x290u);
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_000C91C2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C91BCu)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_VA(0x4C91BCu));
    *(uint32_t*)(cpu->esi + 0x290u) = cpu->ebx;
    label_000C91C2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x288u);
    if (cpu->ecx == cpu->ebx) goto label_000C91D7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C91D1u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_VA(0x4C91D1u));
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->ebx;
    label_000C91D7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28Cu);
    if (cpu->ecx == cpu->ebx) goto label_000C923F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C91E6u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_VA(0x4C91E6u));
    *(uint32_t*)(cpu->esi + 0x28Cu) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C91F2:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B8u);
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == cpu->ebx) goto label_000C9229;
    cpu->edx = cpu->ebp;
    (void)cpu;
    label_000C9200:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->ecx) < *(uint8_t*)(cpu->edx);
    if ((uint8_t)(cpu->ecx) != *(uint8_t*)(cpu->edx)) goto label_000C9220;
    if ((cpu->ecx & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000C921C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->ecx) < *(uint8_t*)(cpu->edx + 1u);
    if ((uint8_t)(cpu->ecx) != *(uint8_t*)(cpu->edx + 1u)) goto label_000C9220;
    cpu->eax += 2u;
    cpu->edx += 2u;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000C9200;
    label_000C921C:
    cpu->eax = 0u;
    goto label_000C9225;
    label_000C9220:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000C9225:
    if (cpu->eax == cpu->ebx) goto label_000C9235;
    label_000C9229:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 0x1B8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC9235u)); sfera_sub_004CF1A0(cpu, LIFT_CODE_TOKEN_RVA(0xC9235u));
    label_000C9235:
    *(uint16_t*)(cpu->esi + 0x250u) = 0x100u;
    cpu->edi = lift_pop32(cpu);
    label_000C923F:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9250(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x34u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax = cpu->ecx + 0xFFFFEC77u;
    if (cpu->eax > 0xBu) goto label_000C9589;
    switch (cpu->eax) {
        case 0u: goto label_000C92A0;
        case 1u: goto label_000C9316;
        case 2u: case 3u: goto label_000C9589;
        case 4u: goto label_000C92B2;
        case 5u: goto label_000C9533;
        case 6u: goto label_000C950C;
        case 7u: goto label_000C9519;
        case 8u: goto label_000C9526;
        case 9u: goto label_000C9375;
        case 10u: goto label_000C9483;
        case 11u: goto label_000C93FA;
        default: lift_trap(cpu, 0x4C9299u, "resolved jump-table index out of range"); return;
    }
label_000C92A0: ;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC92A8u)); sfera_sub_004C9170(cpu, LIFT_CODE_TOKEN_RVA(0xC92A8u));
    label_000C92A8:
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C92B2:
    if (cpu->edi == 0u) goto label_000C92FB;
    cpu->eax = cpu->esi + 0x260u;
    if (*(uint32_t*)(cpu->esi + 0x274u) < 0x10u) goto label_000C92C7;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C92C7:
    cpu->ecx = cpu->edi;
    label_000C92D0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000C92F0;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000C92EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000C92F0;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C92D0;
    label_000C92EC:
    cpu->eax = 0u;
    goto label_000C92F5;
    label_000C92F0:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000C92F5:
    if (cpu->eax == 0u) goto label_000C930C;
    goto label_000C9300;
    label_000C92FB:
    cpu->edi = (uintptr_t)"";
    label_000C9300:
    cpu->ecx = cpu->esi + 0x260u;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC930Cu)); sfera_sub_0049D560(cpu, LIFT_CODE_TOKEN_RVA(0xC930Cu));
    label_000C930C:
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9316:
    if ((cpu->edi) == 0u) goto label_000C934D;
    if ((--cpu->edi) == 0u) goto label_000C9328;
    if ((--cpu->edi) != 0u) goto label_000C92A8;
    cpu->eax = 0x366425u;
    goto label_000C932D;
    label_000C9328:
    cpu->eax = 0x821C1Bu;
    label_000C932D:
    *(uint32_t*)(cpu->esi + 0x1A4u) = 0x8Cu;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    label_000C9343:
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C934D:
    *(uint32_t*)(cpu->esi + 0x1A8u) = 0x141414u;
    *(uint32_t*)(cpu->esi + 0x1A4u) = 0x80u;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0xFF9E7C6Au;
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9375:
    if (cpu->edi != 0u) goto label_000C9396;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x288u);
    if (cpu->ecx == 0u) goto label_000C9343;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9388u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_VA(0x4C9388u));
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->edi;
    cpu->eax = cpu->edi + 1u;
    goto label_000C9597;
    label_000C9396:
    if (*(uint32_t*)(cpu->esi + 0x288u) != 0u) goto label_000C93E4;
    cpu->edx = 0x253u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C93AEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C93AEu));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C93B8u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C93B8u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0u;
    if (cpu->eax == 0u) goto label_000C93D4;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C93D2u)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4C93D2u));
    goto label_000C93D6;
    label_000C93D4:
    cpu->eax = 0u;
    label_000C93D6:
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->eax;
    label_000C93E4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x288u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C93F0u)); sfera_sub_004CF1A0(cpu, LIFT_CODE_TOKEN_VA(0x4C93F0u));
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C93FA:
    if (cpu->edi != 0u) goto label_000C941F;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x290u);
    if (cpu->ecx == 0u) goto label_000C9343;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9411u)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_VA(0x4C9411u));
    *(uint32_t*)(cpu->esi + 0x290u) = cpu->edi;
    cpu->eax = cpu->edi + 1u;
    goto label_000C9597;
    label_000C941F:
    if (*(uint32_t*)(cpu->esi + 0x290u) != 0u) goto label_000C946D;
    cpu->edx = 0x264u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9437u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C9437u));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9441u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C9441u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 1u;
    if (cpu->eax == 0u) goto label_000C945D;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C945Bu)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4C945Bu));
    goto label_000C945F;
    label_000C945D:
    cpu->eax = 0u;
    label_000C945F:
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x290u) = cpu->eax;
    label_000C946D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x290u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9479u)); sfera_sub_004CF1A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9479u));
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9483:
    if (cpu->edi != 0u) goto label_000C94A8;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28Cu);
    if (cpu->ecx == 0u) goto label_000C9343;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C949Au)); sfera_sub_004CF280(cpu, LIFT_CODE_TOKEN_VA(0x4C949Au));
    *(uint32_t*)(cpu->esi + 0x28Cu) = cpu->edi;
    cpu->eax = cpu->edi + 1u;
    goto label_000C9597;
    label_000C94A8:
    if (*(uint32_t*)(cpu->esi + 0x28Cu) != 0u) goto label_000C94F6;
    cpu->edx = 0x275u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C94C0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C94C0u));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C94CAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C94CAu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 2u;
    if (cpu->eax == 0u) goto label_000C94E6;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C94E4u)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4C94E4u));
    goto label_000C94E8;
    label_000C94E6:
    cpu->eax = 0u;
    label_000C94E8:
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x28Cu) = cpu->eax;
    label_000C94F6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28Cu);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9502u)); sfera_sub_004CF1A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9502u));
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C950C:
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->edi;
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9519:
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->edi;
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9526:
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edi;
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9533:
    if (*(uint32_t*)(cpu->esi + 0x284u) == cpu->edi) goto label_000C9343;
    if (cpu->edi != 0u) goto label_000C955B;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9550u)); sfera_sub_0049D560(cpu, LIFT_CODE_TOKEN_VA(0x4C9550u));
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->edi;
    cpu->eax = cpu->edi + 1u;
    goto label_000C9597;
    label_000C955B:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C9566u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C957Cu)); sfera_sub_0049D560(cpu, LIFT_CODE_TOKEN_VA(0x4C957Cu));
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->edi;
    cpu->eax = 1u;
    goto label_000C9597;
    label_000C9589:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC9597u)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_RVA(0xC9597u));
    label_000C9597:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C95F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 8u;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9607u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4C9607u));
    if (*(uint32_t*)(cpu->edi + 0x9Cu) != 0u) goto label_000C962D;
    lift_push32(cpu, 0xA1u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9624u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C9624u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C962Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C962Au));
    cpu->esp += 0x10u;
    label_000C962D:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotpic");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C963Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C963Fu));
    if (cpu->eax != 0u) goto label_000C9654;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotFull");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9650u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C9650u));
    if (cpu->eax == 0u) goto label_000C969F;
    label_000C9654:
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9662u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9662u));
    if (cpu->eax == 0u) goto label_000C9698;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9676u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4C9676u));
    *(uint32_t*)(cpu->edi + 0x198u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000C9698;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, (uintptr_t)"SlotCtrl:: Sprite not found '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C968Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C968Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9695u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C9695u));
    cpu->esp += 0xCu;
    label_000C9698:
    *(uint8_t*)(cpu->edi + 0x250u) = 1u;
    label_000C969F:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotempty");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C96ACu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C96ACu));
    if (cpu->eax == 0u) goto label_000C96F4;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C96BEu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C96BEu));
    if (cpu->eax == 0u) goto label_000C96F4;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C96D2u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4C96D2u));
    *(uint32_t*)(cpu->edi + 0x19Cu) = cpu->eax;
    if (cpu->eax != 0u) goto label_000C96F4;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, (uintptr_t)"SlotCtrl:: Sprite not found '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C96EBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C96EBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C96F1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C96F1u));
    cpu->esp += 0xCu;
    label_000C96F4:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotborder");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9701u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C9701u));
    if (cpu->eax == 0u) goto label_000C9749;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9713u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9713u));
    if (cpu->eax == 0u) goto label_000C9749;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9727u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4C9727u));
    *(uint32_t*)(cpu->edi + 0x1A0u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000C9749;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, (uintptr_t)"SlotCtrl:: Sprite not found '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9740u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C9740u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9746u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C9746u));
    cpu->esp += 0xCu;
    label_000C9749:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotpicofs");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9757u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C9757u));
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000C97A2;
    cpu->ecx = cpu->edi + 0x1B4u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x1B0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xC977Au), LIFT_CODE_TOKEN_RVA(0xC9778u))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000C97A2;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SlotCtrl::LoadUI(%s,%d,%d) Invalid args in 'slotpicofs'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9799u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C9799u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C979Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C979Fu));
    cpu->esp += 0x14u;
    label_000C97A2:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"textofs");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C97AFu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C97AFu));
    if (cpu->eax == 0u) goto label_000C97F4;
    cpu->ecx = cpu->edi + 0x280u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x27Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xC97CCu), LIFT_CODE_TOKEN_RVA(0xC97CAu))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000C97F4;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"SlotCtrl::LoadUI(%s,%d,%d) Invalid args in 'textofs'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C97EBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C97EBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C97F1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C97F1u));
    cpu->esp += 0x14u;
    label_000C97F4:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotnumber");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9801u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C9801u));
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000C9847;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C980Fu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C980Fu));
    if (cpu->eax == 0u) goto label_000C9847;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C981Eu));
    cpu->eax = (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value;
    cpu->esp += 0xCu;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_000C9830:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9830;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC9847u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xC9847u));
    label_000C9847:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"slotItem");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9854u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C9854u));
    cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000C9877;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9867u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9867u));
    if (cpu->eax == 0u) goto label_000C9877;
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.slot_value);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC9877u)); sfera_sub_004C9170(cpu, LIFT_CODE_TOKEN_RVA(0xC9877u));
    label_000C9877:
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9883u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4C9883u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C989Eu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4C989Eu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1A0u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1A4u);
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1A8u);
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1ACu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1B0u);
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    cpu->edx = cpu->edi + 0x1B8u;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x1B8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9910u)); sfera_sub_004CEFF0(cpu, LIFT_CODE_TOKEN_VA(0x4C9910u));
    cpu->eax = *(uint8_t*)(cpu->edi + 0x250u);
    *(uint8_t*)(cpu->esi + 0x250u) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x251u);
    *(uint8_t*)(cpu->esi + 0x251u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x254u);
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x258u);
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x25Cu);
    *(uint8_t*)(cpu->esi + 0x25Cu) = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x25Du));
    lift_push32(cpu, 0xFFFFFFFFu);
    *(uint8_t*)(cpu->esi + 0x25Du) = cpu->edx & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->edi + 0x25Eu);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi + 0x260u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x260u;
    *(uint8_t*)(cpu->esi + 0x25Eu) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C997Eu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4C997Eu));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x27Cu);
    *(uint32_t*)(cpu->esi + 0x27Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x280u);
    *(uint32_t*)(cpu->esi + 0x280u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x284u);
    *(uint32_t*)(cpu->esi + 0x284u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x288u);
    *(uint32_t*)(cpu->esi + 0x288u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x28Cu);
    *(uint32_t*)(cpu->esi + 0x28Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x290u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x290u) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C99D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x1B0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9A04u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C9A04u));
    lift_push32(cpu, 0x298u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9A0Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C9A0Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000C9A2C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9A28u)); sfera_sub_004C8F60(cpu, LIFT_CODE_TOKEN_VA(0x4C9A28u));
    cpu->esi = cpu->eax;
    goto label_000C9A2E;
    label_000C9A2C:
    cpu->esi = 0u;
    label_000C9A2E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9A3Eu)); sfera_sub_004C9890(cpu, LIFT_CODE_TOKEN_VA(0x4C9A3Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000C9A66;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC9A66u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC9A66u));
    label_000C9A66:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%dx%d %d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4C9A95u));
    cpu->esp += 0x14u;
    cpu->eax = (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9AF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"SSKS_NUMBER";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9AFFu)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4C9AFFu));
    cpu->ecx = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_000C9B13;
    label_000C9B05:
    if (cpu->esi == *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_control_options.working_bindings[0]))) goto label_000C9B48;
    ++cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)cpu->eax) goto label_000C9B05;
    label_000C9B13:
    if (cpu->esi == 0u) goto label_000C9B48;
    if (cpu->esi == 0x1Bu) goto label_000C9B48;
    if (cpu->esi == 0x70u) goto label_000C9B48;
    if (cpu->esi == 0xDu) goto label_000C9B48;
    cpu->eax = cpu->esi + 0xFFFFFFD0u;
    if (cpu->eax <= 9u) goto label_000C9B48;
    if (cpu->esi == 0x10u) goto label_000C9B48;
    if (cpu->esi == 0x11u) goto label_000C9B48;
    cpu->esi += 0xFFFFFFDBu;
    cpu->ecx = 3u;
    cpu->eax = (cpu->ecx < cpu->esi) ? 0xFFFFFFFFu : 0u;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C9B48:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9B50(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_graphics_options_runtime.dialog_state = 0u;
    g_sfera_control_options.working_bindings[0] = 0x57u;
    g_sfera_control_options.working_bindings[1] = 0x53u;
    g_sfera_control_options.working_bindings[2] = 0x41u;
    g_sfera_control_options.working_bindings[3] = 0x44u;
    g_sfera_control_options.working_bindings[4] = 0x20u;
    g_sfera_control_options.working_bindings[5] = 0xC0u;
    g_sfera_control_options.working_bindings[6] = 0xBDu;
    g_sfera_control_options.working_bindings[7] = 9u;
    g_sfera_control_options.working_bindings[8] = 0x52u;
    g_sfera_control_options.working_bindings[9] = 0x49u;
    g_sfera_control_options.working_bindings[10] = 0x4Bu;
    g_sfera_control_options.working_bindings[11] = 0x48u;
    g_sfera_control_options.working_bindings[12] = 0x54u;
    g_sfera_control_options.working_bindings[13] = 0x4Eu;
    g_sfera_control_options.working_bindings[14] = 0x50u;
    g_sfera_control_options.working_bindings[15] = 0x4Du;
    g_sfera_control_options.working_bindings[16] = 0x4Au;
    g_sfera_control_options.working_bindings[17] = 0x4Fu;
    g_sfera_control_options.working_bindings[18] = 0x59u;
    g_sfera_control_options.working_bindings[19] = 0xBFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9C30(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    if (*(uint32_t*)(cpu->edx + 8u) != 0x64u) goto label_000C9C3D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    goto label_000C9CD0;
    label_000C9C3D:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C9CD0:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (uintptr_t)"authors";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9CDDu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4C9CDDu));
    lift_test[0]=(cpu->ebx & 0xFFu)==0u;
    cpu->ebx = lift_pop32(cpu);
    if (lift_test[0]) goto label_000C9D0C;
    if (cpu->eax != 0u) goto label_000C9D0B;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9CEDu)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9CEDu));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"authors";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9CFDu)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4C9CFDu));
    if (cpu->eax == 0u) goto label_000C9D0B;
    *(uint32_t*)(cpu->eax + 0xF8u) = LIFT_CALLBACK(sfera_sub_004C9C30);
    label_000C9D0B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C9D0C:
    if (cpu->eax == 0u) goto label_000C9D0B;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9D1Cu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4C9D1Cu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    sfera_sub_004CD1A0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C9C40(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    if (cpu->eax == 0x64u) goto label_000C9C5F;
    if (cpu->eax != 0x3E9u) goto label_000C9C5E;
    cpu->eax = 1u;
    if (*(uint32_t*)(cpu->edx + 4u) != cpu->eax) goto label_000C9C5E;
    g_sfera_render_lookup_runtime.initialized = cpu->eax;
    label_000C9C5E:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C9C5F:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (uintptr_t)"quit";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9C7Du)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4C9C7Du));
    lift_test[0]=(cpu->ebx & 0xFFu)==0u;
    cpu->ebx = lift_pop32(cpu);
    if (lift_test[0]) goto label_000C9CAC;
    if (cpu->eax != 0u) goto label_000C9CAB;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9C8Du)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9C8Du));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"quit";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9C9Du)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4C9C9Du));
    if (cpu->eax == 0u) goto label_000C9CAB;
    *(uint32_t*)(cpu->eax + 0xF8u) = LIFT_CALLBACK(sfera_sub_004C9C40);
    label_000C9CAB:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C9CAC:
    if (cpu->eax == 0u) goto label_000C9CAB;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9CBCu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4C9CBCu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    sfera_sub_004CD1A0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C9D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.widget_keys_initialized;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx -= *(uint32_t*)(cpu->ecx);
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9D60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.end;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->edx -= cpu->ebp;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->esi >>= 31u;
    cpu->edi = 0u;
    cpu->esi += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->esi == 0u) goto label_000C9DA6;
    cpu->eax = cpu->ebp + 8u;
    (void)cpu;
    label_000C9D90:
    if (*(uint32_t*)(cpu->eax + 0xFFFFFFF8u) != cpu->ecx) goto label_000C9D9E;
    if (*(uint32_t*)(cpu->eax + 0xFFFFFFFCu) != cpu->ebx) goto label_000C9D9E;
    if (*(uint32_t*)(cpu->eax) == cpu->edx) goto label_000C9DDE;
    label_000C9D9E:
    ++cpu->edi;
    cpu->eax += 0xCu;
    if (cpu->edi < cpu->esi) goto label_000C9D90;
    label_000C9DA6:
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    if ((int32_t)cpu->eax < 0) goto label_000C9DD4;
    cpu->edi = g_sfera_scene_control_runtime.timing_anchor;
    cpu->ebx = g_sfera_recovered_static_runtime.scene_state_07;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx = cpu->ebp + (cpu->ecx * 4u) + 4u;
    label_000C9DC0:
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->edx) goto label_000C9DCE;
    if (*(uint32_t*)(cpu->ecx + 0xFFFFFFFCu) > cpu->edi) goto label_000C9DCE;
    if (*(uint32_t*)(cpu->ecx) <= cpu->ebx) goto label_000C9DD7;
    label_000C9DCE:
    cpu->ecx -= 0xCu;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000C9DC0;
    label_000C9DD4:
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    label_000C9DD7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C9DDE:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C9DF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.end;
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->edx -= cpu->edi;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9E72u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C9E72u));
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
__declspec(noinline) void sfera_sub_004C9EB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT21";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9EBBu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9EBBu));
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_000C9EC7;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9EC7:
    cpu->edx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[0][0];
    cpu->edx -= cpu->eax;
    label_000C9ED0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9ED0;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT20";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9EE4u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9EE4u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_000C9EEB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9EEB:
    cpu->edx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[1][0];
    cpu->edx -= cpu->eax;
    label_000C9EF2:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9EF2;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT19";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9F06u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9F06u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_000C9F0D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9F0D:
    cpu->edx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[2][0];
    cpu->edx -= cpu->eax;
    label_000C9F14:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9F14;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT18";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9F28u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9F28u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_000C9F2F;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9F2F:
    cpu->edx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[3][0];
    cpu->edx -= cpu->eax;
    label_000C9F36:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9F36;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9F4Au)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9F4Au));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_000C9F51;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9F51:
    cpu->edx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[4][0];
    cpu->edx -= cpu->eax;
    label_000C9F58:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9F58;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9F6Cu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9F6Cu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_000C9F73;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9F73:
    cpu->edx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edx -= cpu->eax;
    label_000C9F80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9F80;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9F94u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9F94u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_000C9F9B;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9F9B:
    cpu->edx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[6][0];
    cpu->edx -= cpu->eax;
    label_000C9FA2:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9FA2;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT36";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9FB6u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C9FB6u));
    sub_pred[0] = *(uint32_t*)(cpu->eax + 0x14u) < cpu->esi;
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000C9FBE;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C9FBE:
    cpu->edx = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->edx -= cpu->eax;
    label_000C9FC5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C9FC5;
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_004CA0E5(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA0EEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CA0EEu));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA0FAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4CA0FAu));
    lift_trap(cpu, 0x4CA0FAu, "INT3"); return;
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
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->ebx <= 0x15555555u) goto label_000CA053;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4CA010u), "std::length_error");
    label_000CA053:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
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
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ebx == 0u) goto label_000CA0B7;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA0B4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CA0B4u));
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
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000CA100:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->edx -= cpu->edi;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = 0x15555555u;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->esi) goto label_000CA133;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4CA100u), "std::length_error");
    label_000CA133:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esi += cpu->eax;
    cpu->edx -= cpu->edi;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
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
__declspec(noinline) void sfera_sub_004CA180(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax -= 0x64u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->eax == 0u) goto label_000CA2D8;
    if ((--cpu->eax) == 0u) goto label_000CA2E0;
    if ((cpu->eax -= 0x384u) != 0u) goto label_000CA21B;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if ((--cpu->edx) == 0u) goto label_000CA276;
    if ((--cpu->edx) == 0u) goto label_000CA2D8;
    if ((cpu->edx -= 7u) != 0u) goto label_000CA21B;
    sub_pred[0] = (uint32_t)(g_sfera_graphics_options_runtime.graphics_values[12]) == cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (sub_pred[0]);
    g_sfera_graphics_options_runtime.graphics_values[12] = cpu->eax;
    if (cpu->eax != 0u) goto label_000CA21D;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT33";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA1D0u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA1D0u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA1DA;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA1DC;
    label_000CA1DA:
    cpu->ecx = cpu->eax;
    label_000CA1DC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA202;
    cpu->edx = (uintptr_t)"";
    label_000CA202:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CA207:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA207;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA21Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA21Au));
    cpu->edi = lift_pop32(cpu);
    label_000CA21B:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA21D:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT34";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA227u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA227u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA231;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA233;
    label_000CA231:
    cpu->ecx = cpu->eax;
    label_000CA233:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA259;
    cpu->edx = (uintptr_t)"";
    label_000CA259:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CA260:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA260;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA273u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA273u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA276:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_sphere_options_runtime.saved_music_volume); lift_push32(cpu, 0xA28u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.audio_settings); lift_push32(cpu, 0xA28u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[12];
    g_sfera_graphics_options_runtime.graphics_values[7] = cpu->ecx;
    label_000CA2D8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    goto label_000CA300;
    label_000CA2E0:
    sub_pred[1] = *(uint32_t*)(cpu->edx + 4u) == 7u;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->esi = lift_pop32(cpu);
    if (!sub_pred[1]) goto label_000CA2EF;
    sfera_sub_004982F0(cpu, stop_address); return;
    label_000CA2EF:
    sfera_sub_00497B60(cpu, stop_address); return;
    label_000CA300:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (uintptr_t)"sound_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA30Du)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CA30Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CA49F;
    if (cpu->eax != 0u) goto label_000CA445;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA324u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA324u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"sound_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA334u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CA334u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx == 0u) goto label_000CA445;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebx + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CA180);
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x4CA34Au));
    g_sfera_sphere_options_runtime.saved_music_volume = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA359u)); sfera_sub_00497980(cpu, LIFT_CODE_TOKEN_VA(0x4CA359u));
    g_sfera_options_dialog_runtime.audio_settings = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = g_sfera_sphere_options_runtime.saved_music_volume;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_native_call(cpu, native_function_address32(&SI_GetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA3D7u));
    cpu->eax = cpu->eax & 0xFFu;
    g_sfera_graphics_options_runtime.graphics_values[7] = cpu->eax;
    g_sfera_graphics_options_runtime.graphics_values[12] = cpu->eax;
    if (cpu->eax != 0u) goto label_000CA447;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT33";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA3F8u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA3F8u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA402;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA404;
    label_000CA402:
    cpu->ecx = cpu->eax;
    label_000CA404:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA42A;
    cpu->edx = (uintptr_t)"";
    label_000CA42A:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    (void)cpu;
    label_000CA430:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA430;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA443u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA443u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000CA445:
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA447:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT34";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA451u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA451u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA45B;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA45D;
    label_000CA45B:
    cpu->ecx = cpu->eax;
    label_000CA45D:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA483;
    cpu->edx = (uintptr_t)"";
    label_000CA483:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CA488:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA488;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA49Bu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA49Bu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA49F:
    if (cpu->eax == 0u) goto label_000CA445;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4AFu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CA4AFu));
    cpu->ecx = g_sfera_sphere_options_runtime.saved_music_volume;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4BAu)); sfera_sub_004982F0(cpu, LIFT_CODE_TOKEN_VA(0x4CA4BAu));
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4C5u)); sfera_sub_00497B60(cpu, LIFT_CODE_TOKEN_VA(0x4CA4C5u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4CCu)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA4CCu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.graphics_values[7]) != 0u);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&SI_SetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA4DAu));
    cpu->esp += 4u;
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4EDu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CA4EDu));
    cpu->edx = g_sfera_options_dialog_runtime.audio_settings;
    cpu->ecx = (uintptr_t)"SNDVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4FDu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CA4FDu));
    cpu->edx = g_sfera_sphere_options_runtime.saved_music_volume;
    cpu->ecx = (uintptr_t)"MUSVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA50Du)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CA50Du));
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[7];
    cpu->ecx = (uintptr_t)"HWMIX";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA51Du)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CA51Du));
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00448490(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004CA530(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    sub_pred[0] = cpu->eax == 0x3E9u;
    if (cpu->eax > 0x3E9u) goto label_000CA804;
    if (sub_pred[0]) goto label_000CA60A;
    if (cpu->eax == 0xFu) goto label_000CA565;
    if (cpu->eax != 0x64u) goto label_000CA800;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000CA890;
    label_000CA565:
    if (g_sfera_control_options.active_slot == 0xFFFFFFFFu) goto label_000CA800;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA57Bu)); sfera_sub_004B8230(cpu, LIFT_CODE_TOKEN_VA(0x4CA57Bu));
    cpu->esi = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = (uintptr_t)"control_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA588u)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CA588u));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_000CA800;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA599u)); sfera_sub_004C9AF0(cpu, LIFT_CODE_TOKEN_VA(0x4CA599u));
    cpu->edx = g_sfera_control_options.active_slot;
    if (cpu->eax == 0u) goto label_000CA5AA;
    *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_control_options.working_bindings[0])) = cpu->esi;
    label_000CA5AA:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA5C2u)); sfera_sub_004B8750(cpu, LIFT_CODE_TOKEN_VA(0x4CA5C2u));
    cpu->edx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = g_sfera_control_options.active_slot;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_control_options.working_bindings[0]));
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA5E3u)); sfera_sub_004BEC00(cpu, LIFT_CODE_TOKEN_VA(0x4CA5E3u));
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CA5EE;
    cpu->edx = (uintptr_t)"";
    label_000CA5EE:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CA5F3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA5F3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA606u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA606u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA60A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    --cpu->eax;
    if (cpu->eax > 5u) goto label_000CA800;
    switch (cpu->eax) {
        case 0u: goto label_000CA61E;
        case 1u: goto label_000CA62F;
        case 2u: case 4u: goto label_000CA800;
        case 3u: goto label_000CA63B;
        case 5u: goto label_000CA6EB;
        default: lift_trap(cpu, 0x4CA617u, "resolved jump-table index out of range"); return;
    }
label_000CA61E: ;
    cpu->ecx = 0x40u;
    cpu->esi = (uintptr_t)&g_sfera_control_options.working_bindings[0];
    cpu->edi = (uintptr_t)&g_sfera_control_options.configured_bindings[0];
    lift_movs32(cpu, 1u);
    label_000CA62F:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000CA890;
    label_000CA63B:
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.dialog_state) == cpu->eax);
    g_sfera_graphics_options_runtime.dialog_state = cpu->eax;
    if (cpu->eax != 0u) goto label_000CA69D;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT23";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA659u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA659u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA663;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA665;
    label_000CA663:
    cpu->ecx = cpu->eax;
    label_000CA665:
    cpu->edx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA681;
    cpu->edx = (uintptr_t)"";
    label_000CA681:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CA686:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA686;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA699u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA699u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA69D:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT24";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA6A7u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA6A7u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA6B1;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA6B3;
    label_000CA6B1:
    cpu->ecx = cpu->eax;
    label_000CA6B3:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA6CF;
    cpu->edx = (uintptr_t)"";
    label_000CA6CF:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CA6D4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA6D4;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA6E7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA6E7u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA6EB:
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA6F1u)); sfera_sub_004C9B50(cpu, LIFT_CODE_TOKEN_VA(0x4CA6F1u));
    if (g_sfera_graphics_options_runtime.dialog_state != 0u) goto label_000CA739;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT23";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA704u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA704u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA70E;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA710;
    label_000CA70E:
    cpu->ecx = cpu->eax;
    label_000CA710:
    cpu->edx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CA72A;
    cpu->ecx = (uintptr_t)"";
    label_000CA72A:
    cpu->eax = cpu->ecx;
    cpu->ebx = cpu->eax + 1u;
    (void)cpu;
    label_000CA730:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CA730;
    goto label_000CA777;
    label_000CA739:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT24";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA743u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA743u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA74D;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA74F;
    label_000CA74D:
    cpu->ecx = cpu->eax;
    label_000CA74F:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CA769;
    cpu->ecx = (uintptr_t)"";
    label_000CA769:
    cpu->eax = cpu->ecx;
    cpu->ebx = cpu->eax + 1u;
    label_000CA770:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CA770;
    label_000CA777:
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA783u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA783u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"SSKS_NUMBER";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA7A7u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA7A7u));
    cpu->ebp = cpu->eax;
    cpu->esi = 0u;
    if ((int32_t)cpu->ebp <= 0) goto label_000CA7FE;
    (void)cpu;
    label_000CA7B0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA7BBu)); sfera_sub_004B8750(cpu, LIFT_CODE_TOKEN_VA(0x4CA7BBu));
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.working_bindings[0]));
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA7D6u)); sfera_sub_004BEC00(cpu, LIFT_CODE_TOKEN_VA(0x4CA7D6u));
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CA7E1;
    cpu->edx = (uintptr_t)"";
    label_000CA7E1:
    cpu->eax = cpu->edx;
    cpu->ebx = cpu->eax + 1u;
    label_000CA7E6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA7E6;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA7F9u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA7F9u));
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebp) goto label_000CA7B0;
    label_000CA7FE:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000CA800:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA804:
    if (cpu->eax != 0xFA1u) goto label_000CA800;
    if (*(uint32_t*)(cpu->esi + 0xCu) != 0x3E9u) goto label_000CA800;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = *(uint16_t*)(cpu->esi + 0x10u);
    if (*(uint16_t*)(cpu->esi + 0x12u) != 3u) goto label_000CA800;
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA83Bu)); sfera_sub_004B8750(cpu, LIFT_CODE_TOKEN_VA(0x4CA83Bu));
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx += 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA859u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA859u));
    g_sfera_control_options.active_slot = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = LIFT_CALLBACK(sfera_sub_004CA530);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004B8230(cpu, stop_address); return;
    label_000CA890:
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uintptr_t)"control_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA8ADu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CA8ADu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CAB0E;
    if (cpu->eax != 0u) goto label_000CABB6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA8C4u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA8C4u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"control_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA8D4u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CA8D4u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx == 0u) goto label_000CABB6;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x100u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_control_options.configured_bindings[0]);
    *(uint32_t*)(cpu->ebx + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CA530);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4CA8F5u));
    cpu->esp += 0xCu;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"SSKS_NUMBER";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA909u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA909u));
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    cpu->esi = 0u;
    label_000CA911:
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA91Du)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA91Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA924u)); sfera_sub_004BEBA0(cpu, LIFT_CODE_TOKEN_VA(0x4CA924u));
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0])) = cpu->eax;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)5u) goto label_000CA911;
    cpu->esi = 5u;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->esi) goto label_000CA958;
    label_000CA940:
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA94Cu)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA94Cu));
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0])) = cpu->eax;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebp) goto label_000CA940;
    label_000CA958:
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"INMS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA964u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA964u));
    cpu->ecx = 0x40u;
    cpu->esi = (uintptr_t)&g_sfera_control_options.configured_bindings[0];
    cpu->edi = (uintptr_t)&g_sfera_control_options.working_bindings[0];
    g_sfera_control_options.configured_bindings[63] = cpu->eax;
    lift_movs32(cpu, 1u);
    if (cpu->eax != 0u) goto label_000CA9BC;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT23";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA988u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA988u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA992;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA994;
    label_000CA992:
    cpu->ecx = cpu->eax;
    label_000CA994:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CA9AE;
    cpu->ecx = (uintptr_t)"";
    label_000CA9AE:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CA9B3:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CA9B3;
    goto label_000CA9F8;
    label_000CA9BC:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT24";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA9C6u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA9C6u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA9D0;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA9D2;
    label_000CA9D0:
    cpu->ecx = cpu->eax;
    label_000CA9D2:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CA9EC;
    cpu->ecx = (uintptr_t)"";
    label_000CA9EC:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CA9F1:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CA9F1;
    label_000CA9F8:
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAA04u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAA04u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if ((int32_t)cpu->ebp <= 0) goto label_000CAAF1;
    goto label_000CAA2B;
    label_000CAA27:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000CAA2B:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xFA2u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAA46u)); sfera_sub_004B8750(cpu, LIFT_CODE_TOKEN_VA(0x4CAA46u));
    cpu->edi = cpu->eax;
    cpu->eax = cpu->esi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"UISTR_WT_KEY%02u"); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0]);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CAA5Au));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAA6Du)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAA6Du));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAA75;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000CAA75:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->ebx = *(uint32_t*)(cpu->edx + 8u);
    cpu->ecx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CAA8D;
    cpu->ecx = (uintptr_t)"";
    label_000CAA8D:
    cpu->eax = cpu->ecx;
    cpu->ebp = cpu->eax + 1u;
    label_000CAA92:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CAA92;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAAA5u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAAA5u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAAC0u)); sfera_sub_004BEC00(cpu, LIFT_CODE_TOKEN_VA(0x4CAAC0u));
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CAACB;
    cpu->edx = (uintptr_t)"";
    label_000CAACB:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAAD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAAD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAAE3u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAAE3u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_000CAA27;
    label_000CAAF1:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_options_dialog_runtime.widget_keys_initialized = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CAB0E:
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_000CABB6;
    cpu->edx = cpu->ebx + 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB22u)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CAB22u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB29u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAB29u));
    cpu->edx = g_sfera_control_options.configured_bindings[63];
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uintptr_t)"INMS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB3Au)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAB3Au));
    cpu->esi = 0u;
    label_000CAB40:
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB4Du)); sfera_sub_004BEB80(cpu, LIFT_CODE_TOKEN_VA(0x4CAB4Du));
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB59u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAB59u));
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)5u) goto label_000CAB40;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"SSKS_NUMBER";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB6Bu)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CAB6Bu));
    cpu->edi = cpu->eax;
    cpu->esi = 5u;
    if ((int32_t)cpu->edi <= (int32_t)cpu->esi) goto label_000CAB97;
    label_000CAB80:
    cpu->edx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB92u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAB92u));
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->edi) goto label_000CAB80;
    label_000CAB97:
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x10u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CABB0u)); sfera_sub_004BA680(cpu, LIFT_CODE_TOKEN_VA(0x4CABB0u));
    g_sfera_options_dialog_runtime.widget_keys_initialized = cpu->ebx;
    label_000CABB6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CABD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    goto label_000CABD0;
    label_000BC440:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC44Bu)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x4BC44Bu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000BC46F;
    label_000BC456:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x4Eu) == 0u) goto label_000BC469;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC464u)); sfera_sub_004D1A60(cpu, LIFT_CODE_TOKEN_VA(0x4BC464u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BC469:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->eax) goto label_000BC456;
    label_000BC46F:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C9AB0:
    cpu->esp -= 0x20u;
    cpu->eax = 0u;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 8u) = 0x10u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C9AD7u)); sfera_sub_004BA680(cpu, LIFT_CODE_TOKEN_VA(0x4C9AD7u));
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CABD0:
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->eax == 0x64u) goto label_000CB0A7;
    if (cpu->eax != 0x3E9u) goto label_000CAE2A;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    --cpu->eax;
    if (cpu->eax > 0x15u) goto label_000CAE2A;
    lift_push32(cpu, cpu->edi);
    switch (cpu->eax) {
        case 0u: goto label_000CAC06;
        case 1u: goto label_000CAC17;
        case 5u: goto label_000CADA6;
        case 6u: goto label_000CAC20;
        case 7u: goto label_000CACA2;
        case 8u: goto label_000CAD2C;
        case 10u: goto label_000CADAD;
        case 11u: goto label_000CAE2C;
        case 14u: goto label_000CAEAC;
        case 15u: goto label_000CAF2C;
        case 18u: goto label_000CAFB2;
        case 20u: goto label_000CB02A;
        case 21u: goto label_000CB09E;
        default: goto label_000CAE29;
    }
label_000CAC06: ;
    cpu->ecx = 9u;
    cpu->esi = (uintptr_t)&g_sfera_graphics_options_runtime.interface_values[0];
    cpu->edi = (uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[0];
    lift_movs32(cpu, 1u);
    label_000CAC17:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004CB100(cpu, stop_address); return;
    label_000CAC20:
    cpu->edx = 0u;
    sub_pred[0] = (uint32_t)(g_sfera_graphics_options_runtime.interface_values[0]) == cpu->edx;
    lift_push32(cpu, 0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->ecx = (uintptr_t)"ISSN";
    g_sfera_graphics_options_runtime.interface_values[0] = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAC3Du)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAC3Du));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[0]) == 0u) goto label_000CAC50;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CAC50:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAC55u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAC55u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAC5F;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CAC61;
    label_000CAC5F:
    cpu->ecx = cpu->eax;
    label_000CAC61:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CAC83;
    cpu->edx = (uintptr_t)"";
    label_000CAC83:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAC88:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAC88;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAC9Bu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAC9Bu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CACA2:
    cpu->eax = 0u;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[1]) == cpu->eax);
    g_sfera_graphics_options_runtime.interface_values[1] = cpu->eax;
    if (cpu->eax == 0u) goto label_000CACC0;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CACC0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CACC5u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CACC5u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CACCF;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CACD1;
    label_000CACCF:
    cpu->ecx = cpu->eax;
    label_000CACD1:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CACF5;
    cpu->edx = (uintptr_t)"";
    label_000CACF5:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAD00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAD00;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAD13u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAD13u));
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[1];
    lift_push32(cpu, 0u);
    cpu->ecx = (uintptr_t)"ISAD";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAD25u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAD25u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAD2C:
    cpu->eax = 0u;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[2]) == cpu->eax);
    g_sfera_graphics_options_runtime.interface_values[2] = cpu->eax;
    if (cpu->eax == 0u) goto label_000CAD4A;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CAD4A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAD4Fu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAD4Fu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAD59;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CAD5B;
    label_000CAD59:
    cpu->ecx = cpu->eax;
    label_000CAD5B:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CAD81;
    cpu->edx = (uintptr_t)"";
    label_000CAD81:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAD86:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAD86;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAD99u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAD99u));
    cpu->ecx = g_sfera_graphics_options_runtime.interface_values[2];
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    sfera_sub_004B87D0(cpu, stop_address); return;
    label_000CADA6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000BC440;
    label_000CADAD:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[3]) == cpu->ecx);
    g_sfera_graphics_options_runtime.interface_values[3] = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CADC3u)); sfera_sub_004B87C0(cpu, LIFT_CODE_TOKEN_VA(0x4CADC3u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[3]) == 0u) goto label_000CADD6;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CADD6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CADDBu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CADDBu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CADE5;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CADE7;
    label_000CADE5:
    cpu->ecx = cpu->eax;
    label_000CADE7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CAE11;
    cpu->edx = (uintptr_t)"";
    label_000CAE11:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAE16:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAE16;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCAE29u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xCAE29u));
    label_000CAE29:
    cpu->edi = lift_pop32(cpu);
    label_000CAE2A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CAE2C:
    cpu->eax = 0u;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[4]) == cpu->eax);
    g_sfera_graphics_options_runtime.interface_values[4] = cpu->eax;
    if (cpu->eax == 0u) goto label_000CAE4A;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CAE4A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAE4Fu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAE4Fu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAE59;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CAE5B;
    label_000CAE59:
    cpu->edx = cpu->eax;
    label_000CAE5B:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0xBu;
    label_000CAE68:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CAE68;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CAE79;
    cpu->edx = (uintptr_t)"";
    label_000CAE79:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAE80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAE80;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAE93u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAE93u));
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[4];
    lift_push32(cpu, 0u);
    cpu->ecx = (uintptr_t)"IAPM";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAEA5u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAEA5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAEAC:
    cpu->eax = 0u;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[5]) == cpu->eax);
    g_sfera_graphics_options_runtime.interface_values[5] = cpu->eax;
    if (cpu->eax == 0u) goto label_000CAECA;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CAECA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAECFu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAECFu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAED9;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CAEDB;
    label_000CAED9:
    cpu->edx = cpu->eax;
    label_000CAEDB:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CAEE8:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CAEE8;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CAEFB;
    cpu->edx = (uintptr_t)"";
    label_000CAEFB:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAF00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAF00;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAF13u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAF13u));
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[5];
    lift_push32(cpu, 0u);
    cpu->ecx = (uintptr_t)"MBST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAF25u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAF25u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAF2C:
    cpu->eax = 0u;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[6]) == cpu->eax);
    g_sfera_graphics_options_runtime.interface_values[6] = cpu->eax;
    if (cpu->eax == 0u) goto label_000CAF4A;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CAF4A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAF4Fu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAF4Fu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAF59;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CAF5B;
    label_000CAF59:
    cpu->edx = cpu->eax;
    label_000CAF5B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 3u;
    label_000CAF68:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CAF68;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CAF81;
    cpu->edx = (uintptr_t)"";
    label_000CAF81:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAF86:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAF86;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAF99u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAF99u));
    cpu->edx = g_sfera_graphics_options_runtime.interface_values[6];
    lift_push32(cpu, 0u);
    cpu->ecx = (uintptr_t)"BALR";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAFABu)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAFABu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CAFB2:
    cpu->eax = 0u;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[7]) == cpu->eax);
    g_sfera_graphics_options_runtime.interface_values[7] = cpu->eax;
    if (cpu->eax == 0u) goto label_000CAFD0;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CAFD0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAFD5u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAFD5u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAFDF;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CAFE1;
    label_000CAFDF:
    cpu->edx = cpu->eax;
    label_000CAFE1:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 3u;
    label_000CAFF0:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CAFF0;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CB00B;
    cpu->edx = (uintptr_t)"";
    label_000CB00B:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB010:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB010;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB023u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB023u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CB02A:
    cpu->eax = 0u;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[8]) == cpu->eax);
    g_sfera_graphics_options_runtime.interface_values[8] = cpu->eax;
    if (cpu->eax == 0u) goto label_000CB048;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB048:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB04Du)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB04Du));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CB057;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CB059;
    label_000CB057:
    cpu->edx = cpu->eax;
    label_000CB059:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 4u;
    label_000CB066:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CB066;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CB07F;
    cpu->edx = (uintptr_t)"";
    label_000CB07F:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB084:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB084;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB097u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB097u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_000C9AB0;
    label_000CB09E:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    goto label_000CD260;
    label_000CB0A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004CB100(cpu, stop_address); return;
    label_000CD260:
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"font_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD27Cu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD27Cu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CD3AD;
    if (cpu->eax != 0u) goto label_000CD410;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD293u)); sfera_sub_004CB100(cpu, LIFT_CODE_TOKEN_VA(0x4CD293u));
    cpu->ecx = (uintptr_t)"options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD29Du)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD29Du));
    if (cpu->eax == 0u) goto label_000CD2AD;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCD2ADu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_RVA(0xCD2ADu));
    label_000CD2AD:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"font_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD2BDu)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CD2BDu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_000CD410;
    lift_push32(cpu, 2u);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    *(uint32_t*)(cpu->esi + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CD1F0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD2DDu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4CD2DDu));
    lift_push32(cpu, 2u);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD2E9u)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4CD2E9u));
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    *(uint32_t*)(cpu->esp + 0xCu) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD300u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4CD300u));
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    *(uint32_t*)(cpu->esp + 0xCu) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD317u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4CD317u));
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD321u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CD321u));
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->ecx = (uintptr_t)"CHAT_LIST_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD331u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CD331u));
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx += 4u;
    cpu->ecx = (uintptr_t)"CHAT_EDIT_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD344u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CD344u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.end;
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD39Cu)); sfera_sub_004AB160(cpu, LIFT_CODE_TOKEN_VA(0x4CD39Cu));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD3AD:
    cpu->esi = 0u;
    if (cpu->eax == cpu->esi) goto label_000CD410;
    cpu->edx = cpu->esi + 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3BDu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CD3BDu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3C4u)); sfera_sub_004CB100(cpu, LIFT_CODE_TOKEN_VA(0x4CD3C4u));
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3CEu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CD3CEu));
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = (uintptr_t)"CHAT_LIST_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3DFu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD3DFu));
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = (uintptr_t)"CHAT_EDIT_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F2u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F7u)); sfera_sub_00448490(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F7u));
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x14u) = 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCD410u)); sfera_sub_004BA680(cpu, LIFT_CODE_TOKEN_RVA(0xCD410u));
    label_000CD410:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CB100(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"interface_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB11Cu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CB11Cu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CB5AA;
    if (cpu->eax != 0u) goto label_000CB6E2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB133u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB133u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"interface_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB143u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CB143u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx == 0u) goto label_000CB6E2;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"ISSN";
    *(uint32_t*)(cpu->ebx + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CABD0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB163u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CB163u));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"ISAD";
    g_sfera_graphics_options_runtime.saved_interface_values[0] = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB174u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CB174u));
    g_sfera_graphics_options_runtime.saved_interface_values[1] = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB17Eu)); sfera_sub_004B87E0(cpu, LIFT_CODE_TOKEN_VA(0x4CB17Eu));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"INAW";
    g_sfera_graphics_options_runtime.saved_interface_values[2] = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB18Fu)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CB18Fu));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"IAPM";
    g_sfera_graphics_options_runtime.saved_interface_values[3] = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB1A0u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CB1A0u));
    cpu->ecx = (uintptr_t)"config.cfg";
    g_sfera_graphics_options_runtime.saved_interface_values[4] = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB1AFu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CB1AFu));
    cpu->edx = (uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[5];
    cpu->ecx = (uintptr_t)"MBST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB1BEu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CB1BEu));
    cpu->edx = (uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[6];
    cpu->ecx = (uintptr_t)"BALR";
    g_sfera_graphics_options_runtime.saved_interface_values[6] = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB1D7u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CB1D7u));
    if ((int32_t)g_sfera_graphics_options_runtime.saved_interface_values[6] >= (int32_t)0u) goto label_000CB1FA;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)"BALR";
    g_sfera_graphics_options_runtime.saved_interface_values[6] = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB1F5u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CB1F5u));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCB1FAu)); sfera_sub_00448490(cpu, LIFT_CODE_TOKEN_RVA(0xCB1FAu));
    label_000CB1FA:
    sub_pred[1] = (uint32_t)(g_sfera_graphics_options_runtime.saved_interface_values[0]) == 0u;
    cpu->ecx = g_sfera_interface_runtime.invite_messages;
    cpu->eax = g_sfera_interface_runtime.description_auto_popup;
    g_sfera_graphics_options_runtime.saved_interface_values[8] = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 9u;
    cpu->esi = (uintptr_t)&g_sfera_graphics_options_runtime.saved_interface_values[0];
    cpu->edi = (uintptr_t)&g_sfera_graphics_options_runtime.interface_values[0];
    g_sfera_graphics_options_runtime.saved_interface_values[7] = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if (sub_pred[1]) goto label_000CB235;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB235:
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB23Bu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB23Bu));
    cpu->ebp = 0x10u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB249;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CB24B;
    label_000CB249:
    cpu->ecx = cpu->eax;
    label_000CB24B:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CB26B;
    cpu->ecx = (uintptr_t)"";
    label_000CB26B:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CB270:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CB270;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB283u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB283u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[1]) == 0u) goto label_000CB296;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB296:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB29Bu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB29Bu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB2A4;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CB2A6;
    label_000CB2A4:
    cpu->ecx = cpu->eax;
    label_000CB2A6:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CB2CA;
    cpu->edx = (uintptr_t)"";
    label_000CB2CA:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    (void)cpu;
    label_000CB2D0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB2D0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB2E3u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB2E3u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[2]) == 0u) goto label_000CB2F6;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB2F6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB2FBu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB2FBu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB304;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CB306;
    label_000CB304:
    cpu->ecx = cpu->eax;
    label_000CB306:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CB32C;
    cpu->edx = (uintptr_t)"";
    label_000CB32C:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB331:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB331;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB344u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB344u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[3]) == 0u) goto label_000CB357;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB357:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB35Cu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB35Cu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB365;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CB367;
    label_000CB365:
    cpu->ecx = cpu->eax;
    label_000CB367:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CB391;
    cpu->edx = (uintptr_t)"";
    label_000CB391:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB396:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB396;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB3A9u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB3A9u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[4]) == 0u) goto label_000CB3BC;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB3BC:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB3C1u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB3C1u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB3CA;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CB3CC;
    label_000CB3CA:
    cpu->edx = cpu->eax;
    label_000CB3CC:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0xBu;
    label_000CB3E0:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CB3E0;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CB3F1;
    cpu->edx = (uintptr_t)"";
    label_000CB3F1:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB3F6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB3F6;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB409u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB409u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[5]) == 0u) goto label_000CB41C;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB41C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB421u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB421u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB42A;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CB42C;
    label_000CB42A:
    cpu->edx = cpu->eax;
    label_000CB42C:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CB440:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CB440;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CB453;
    cpu->edx = (uintptr_t)"";
    label_000CB453:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB458:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB458;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB46Bu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB46Bu));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[6]) == 0u) goto label_000CB47E;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB47E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB483u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB483u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB48C;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CB48E;
    label_000CB48C:
    cpu->edx = cpu->eax;
    label_000CB48E:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 3u;
    label_000CB4A0:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CB4A0;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CB4B9;
    cpu->edx = (uintptr_t)"";
    label_000CB4B9:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB4C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB4C0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB4D3u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB4D3u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[7]) == 0u) goto label_000CB4E6;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB4E6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB4EBu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB4EBu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000CB4F4;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CB4F6;
    label_000CB4F4:
    cpu->edx = cpu->eax;
    label_000CB4F6:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 3u;
    label_000CB503:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CB503;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CB51E;
    cpu->edx = (uintptr_t)"";
    label_000CB51E:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB523:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB523;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB536u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB536u));
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    if ((uint32_t)(g_sfera_graphics_options_runtime.interface_values[8]) == 0u) goto label_000CB549;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    label_000CB549:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB54Eu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB54Eu));
    sub_pred[0] = *(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000CB558;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CB55A;
    label_000CB558:
    cpu->edx = cpu->eax;
    label_000CB55A:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 4u;
    label_000CB567:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CB567;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CB580;
    cpu->edx = (uintptr_t)"";
    label_000CB580:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CB585:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CB585;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB598u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CB598u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CB5AA:
    cpu->esi = 0u;
    if (cpu->eax == cpu->esi) goto label_000CB6E2;
    cpu->edx = cpu->esi + 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB5BEu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CB5BEu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB5C5u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CB5C5u));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[0];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"ISSN";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB5D6u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CB5D6u));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[1];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"ISAD";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB5E7u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CB5E7u));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[2];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"INSN";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB5F8u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CB5F8u));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[3];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"INAW";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB609u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CB609u));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[4];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"IAPM";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB61Au)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CB61Au));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[5];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"MBST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB62Bu)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CB62Bu));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[6];
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"BALR";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB63Cu)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CB63Cu));
    cpu->ecx = g_sfera_graphics_options_runtime.saved_interface_values[7];
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[8];
    g_sfera_interface_runtime.description_auto_popup = cpu->ecx;
    cpu->ecx = (uintptr_t)"config.cfg";
    g_sfera_interface_runtime.invite_messages = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB65Eu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CB65Eu));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[5];
    cpu->ecx = (uintptr_t)"MBST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB66Eu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CB66Eu));
    cpu->edx = g_sfera_graphics_options_runtime.saved_interface_values[6];
    cpu->ecx = (uintptr_t)"BALR";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB67Eu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CB67Eu));
    cpu->edx = g_sfera_graphics_runtime.hardware_cursor_enabled;
    cpu->ecx = (uintptr_t)"HARDWARE_CURSOR";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB68Eu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CB68Eu));
    cpu->edx = g_sfera_interface_runtime.description_auto_popup;
    cpu->ecx = (uintptr_t)"DESCR_AUTO_POPUP";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB69Eu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CB69Eu));
    cpu->edx = g_sfera_interface_runtime.invite_messages;
    cpu->ecx = (uintptr_t)"INVITE_MESSAGES";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB6AEu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CB6AEu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB6B3u)); sfera_sub_00448490(cpu, LIFT_CODE_TOKEN_VA(0x4CB6B3u));
    cpu->ecx = g_sfera_graphics_options_runtime.saved_interface_values[2];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB6BEu)); sfera_sub_004B87D0(cpu, LIFT_CODE_TOKEN_VA(0x4CB6BEu));
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x10u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB6D7u)); sfera_sub_004BA680(cpu, LIFT_CODE_TOKEN_VA(0x4CB6D7u));
    cpu->ecx = g_sfera_graphics_options_runtime.saved_interface_values[3];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCB6E2u)); sfera_sub_004B87C0(cpu, LIFT_CODE_TOKEN_RVA(0xCB6E2u));
    label_000CB6E2:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
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
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
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
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
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
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0xCB7EFu), LIFT_CODE_TOKEN_RVA(0xCB7EDu))) { return; }
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
    if (!lift_call_indirect(cpu, cpu->ecx, LIFT_CODE_TOKEN_RVA(0xCB831u), LIFT_CODE_TOKEN_RVA(0xCB82Fu))) { return; }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->edi < 0x320u) goto label_000CB8BE;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->ebp < 0x258u) goto label_000CB8BE;
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.end;
    cpu->ecx -= g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
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
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
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
__declspec(noinline) void sfera_sub_004CB950(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[5];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    cpu->esi = cpu->ecx;
    sub_pred[0] = cpu->eax == 0x3E9u;
    if (cpu->eax > 0x3E9u) goto label_000CBA23;
    if (sub_pred[0]) goto label_000CB985;
    if ((cpu->eax -= 0x64u) == 0u) goto label_000CBA16;
    if ((--cpu->eax) == 0u) goto label_000CC1D8;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CB985:
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    if ((--cpu->eax) == 0u) goto label_000CB9E4;
    if ((--cpu->eax) != 0u) goto label_000CC224;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CB999u)); sfera_sub_004CC280(cpu, LIFT_CODE_TOKEN_VA(0x4CB999u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_sphere_options_runtime.saved_fog_distance.f32));
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[9];
    g_sfera_graphics_runtime.fog_distance = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[8];
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_sphere_options_runtime.saved_lod_distance.f32));
    cpu->edx = g_sfera_sphere_options_runtime.saved_lods_enabled;
    *(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25) = cpu->eax;
    cpu->eax = g_sfera_graphics_options_runtime.graphics_page;
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26) = cpu->ecx;
    g_sfera_graphics_runtime.lods_enabled = cpu->edx;
    g_sfera_options_dialog_runtime.reflection_quality = cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CB9E4:
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32));
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 7u;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    cpu->esi = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->edi = (uintptr_t)&g_sfera_graphics_options_runtime.graphics_values[0];
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_movs32(cpu, 1u);
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCBA16u)); sfera_sub_0041C1B0(cpu, LIFT_CODE_TOKEN_RVA(0xCBA16u));
    label_000CBA16:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_004CC280(cpu, stop_address); return;
    label_000CBA23:
    if (cpu->eax != 0x157Du) goto label_000CC224;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax += 0xFFFFFFF1u;
    if (cpu->eax > 0x24u) goto label_000CC1D8;
    lift_push32(cpu, cpu->ebx);
    switch (cpu->eax) {
        case 0u: goto label_000CBA4C;
        case 2u: goto label_000CBAA3;
        case 3u: goto label_000CBB03;
        case 9u: goto label_000CBF22;
        case 11u: goto label_000CBB7C;
        case 19u: goto label_000CBF73;
        case 24u: goto label_000CBD7F;
        case 28u: goto label_000CBC1C;
        case 36u: goto label_000CC126;
        default: goto label_000CC1D7;
    }
label_000CBA4C: ;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    g_sfera_options_dialog_runtime.graphics_snapshot[5] = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->ecx = cpu->ecx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBA80u)); sfera_sub_004C9A80(cpu, LIFT_CODE_TOKEN_VA(0x4CBA80u));
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CBA8B;
    cpu->edx = (uintptr_t)"";
    label_000CBA8B:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CBA90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBA90;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x54u;
    goto label_000CC1D2;
    label_000CBAA3:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = g_sfera_shadow_runtime.manager;
    g_sfera_options_dialog_runtime.graphics_snapshot[2] = cpu->eax;
    *(uint8_t*)(cpu->ecx + 0xA0u) = cpu->eax & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax <<= 9u;
    cpu->eax += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[0][0];
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CBAE6;
    cpu->edx = (uintptr_t)"";
    label_000CBAE6:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CBAF0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBAF0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x54u;
    goto label_000CC1D2;
    label_000CBB03:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    g_sfera_options_dialog_runtime.graphics_snapshot[3] = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    g_sfera_main_render_runtime.grass_depth_mode = cpu->edx;
    sub_pred[2] = *(uint32_t*)(cpu->ebp + 0xCu) == 2u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (*(uint32_t*)(cpu->ebp + 0xCu) >= 2u) goto label_000CBB64;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax <<= 9u;
    cpu->eax += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edx = cpu->eax;
    if (!sub_pred[2]) goto label_000CBB4C;
    cpu->edx = (uintptr_t)"";
    label_000CBB4C:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CBB51:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBB51;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    goto label_000CC1D2;
    label_000CBB64:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = cpu->eax + 1u;
    (void)cpu;
    label_000CBB70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBB70;
    goto label_000CC1C7;
    label_000CBB7C:
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ebp + 0xCu) == cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->ecx >= 2u) goto label_000CBBE3;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 5u;
    label_000CBBA0:
    --cpu->edx; sub_pred[3] = cpu->edx == 0u;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CBBA0;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx <<= 9u;
    cpu->ecx += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edx = cpu->ecx;
    if (!sub_pred[3]) goto label_000CBBC4;
    cpu->edx = (uintptr_t)"";
    label_000CBBC4:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CBBD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBBD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    goto label_000CC1D2;
    label_000CBBE3:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 5u;
    label_000CBBF0:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CBBF0;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = cpu->eax + 1u;
    label_000CBC10:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBC10;
    goto label_000CC1C7;
    label_000CBC1C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 1u) goto label_000CBCFE;
    cpu->ecx = 8u;
    label_000CBC35:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBC35;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[6][0];
    cpu->edi = cpu->eax + 1u;
    label_000CBC50:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBC50;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[6][0]);
    cpu->ecx = cpu->edx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBC67u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CBC67u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBC74:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBC74;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBCA2:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBCA2;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (12.0);
    *(uint16_t*)(cpu->esp + 0x12u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x12u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_push32(cpu, 0u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x18u);
    *(uint64_t*)(cpu->esp + 0x1Cu) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    g_sfera_graphics_runtime.lods_enabled = 1u;
    goto label_000CC1D7;
    label_000CBCFE:
    cpu->edx = 8u;
    label_000CBD03:
    --cpu->edx; sub_pred[4] = cpu->edx == 0u;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CBD03;
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx <<= 9u;
    cpu->ecx += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edx = cpu->ecx;
    if (!sub_pred[4]) goto label_000CBD25;
    cpu->edx = (uintptr_t)"";
    label_000CBD25:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CBD30:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBD30;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBD43u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CBD43u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBD50:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBD50;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    g_sfera_graphics_runtime.lods_enabled = 0u;
    goto label_000CC1D7;
    label_000CBD7F:
    cpu->ebp = 1u;
    cpu->ecx = cpu->edx;
    if (*(uint32_t*)(cpu->ecx + 0xCu) != cpu->ebp) goto label_000CBE2B;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBD99u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CBD99u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CBDA3;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CBDA5;
    label_000CBDA3:
    cpu->edx = cpu->eax;
    label_000CBDA5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 6u;
    label_000CBDB2:
    cpu->ecx -= cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBDB2;
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CBDCE;
    cpu->edx = (uintptr_t)"";
    label_000CBDCE:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CBDD3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBDD3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBDE6u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CBDE6u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBDF3:
    cpu->ecx -= cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBDF3;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_x87_push(cpu, (double)g_sfera_graphics_runtime.fog_distance);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25) = cpu->ebp;
    g_sfera_graphics_runtime.saved_fog_distance = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    goto label_000CC1D7;
    label_000CBE2B:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBE35u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CBE35u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CBE3F;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CBE41;
    label_000CBE3F:
    cpu->edx = cpu->eax;
    label_000CBE41:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 6u;
    label_000CBE50:
    cpu->ecx -= cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBE50;
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CBE6C;
    cpu->edx = (uintptr_t)"";
    label_000CBE6C:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CBE71:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBE71;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBE84u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CBE84u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBE91:
    cpu->ecx -= cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBE91;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0xAAu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_x87_push(cpu, (double)g_sfera_graphics_runtime.saved_fog_distance);
    g_sfera_graphics_runtime.fog_distance = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CBECB:
    cpu->ecx -= cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBECB;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (30.0);
    *(uint16_t*)(cpu->esp + 0x12u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x12u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, 0u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Cu);
    *(uint64_t*)(cpu->esp + 0x1Cu) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25) = 0u;
    goto label_000CC1D7;
    label_000CBF22:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    g_sfera_options_dialog_runtime.reflection_quality = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CBF37:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBF37;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx <<= 9u;
    cpu->eax = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[4][0];
    cpu->eax -= cpu->ecx;
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CBF59;
    cpu->edx = (uintptr_t)"";
    label_000CBF59:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CBF60:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBF60;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    goto label_000CC1D2;
    label_000CBF73:
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ebp + 0xCu) != 1u);
    g_sfera_options_dialog_runtime.graphics_snapshot[4] = cpu->eax;
    if (cpu->eax != 1u) goto label_000CBFD1;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT61";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBF90u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CBF90u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CBF9A;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CBF9C;
    label_000CBF9A:
    cpu->edx = cpu->eax;
    label_000CBF9C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0x11u;
    label_000CBFB0:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBFB0;
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CBFC3;
    cpu->edx = (uintptr_t)"";
    label_000CBFC3:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CBFC8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CBFC8;
    goto label_000CC017;
    label_000CBFD1:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT62";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CBFDBu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CBFDBu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CBFE5;
    cpu->edx = *(uint32_t*)(cpu->eax);
    goto label_000CBFE7;
    label_000CBFE5:
    cpu->edx = cpu->eax;
    label_000CBFE7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0x11u;
    label_000CBFF4:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CBFF4;
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edx != 0u) goto label_000CC007;
    cpu->edx = (uintptr_t)"";
    label_000CC007:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000CC010:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CC010;
    label_000CC017:
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC023u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC023u));
    cpu->eax = g_sfera_options_dialog_runtime.graphics_snapshot[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->ebx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 4u);
    cpu->ebp = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 8u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_options_dialog_runtime.graphics_snapshot[4]) == 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC04Eu)); sfera_sub_004CB790(cpu, LIFT_CODE_TOKEN_VA(0x4CC04Eu));
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC058u)); sfera_sub_004C9D60(cpu, LIFT_CODE_TOKEN_VA(0x4CC058u));
    g_sfera_options_dialog_runtime.graphics_snapshot[5] = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 7u;
    label_000CC070:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC070;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_modes;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC086u)); sfera_sub_004C9D40(cpu, LIFT_CODE_TOKEN_VA(0x4CC086u));
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x157Fu);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC0A3:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC0A3;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.graphics_snapshot[5];
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = g_sfera_options_dialog_runtime.graphics_snapshot[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->edx + (cpu->ecx * 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC0EFu)); sfera_sub_004C9A80(cpu, LIFT_CODE_TOKEN_VA(0x4CC0EFu));
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CC0FA;
    cpu->edx = (uintptr_t)"";
    label_000CC0FA:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    (void)cpu;
    label_000CC100:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CC100;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC113u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC113u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    g_sfera_options_dialog_runtime.graphics_snapshot[0] = 0u;
    goto label_000CC1D7;
    label_000CC126:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    g_sfera_options_dialog_runtime.graphics_snapshot[6] = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    g_sfera_graphics_runtime.post_effects_enabled = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->ecx >= 2u) goto label_000CC190;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 8u;
    label_000CC150:
    --cpu->edx; sub_pred[1] = cpu->edx == 0u;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CC150;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx <<= 9u;
    cpu->ecx += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edx = cpu->ecx;
    if (!sub_pred[1]) goto label_000CC174;
    cpu->edx = (uintptr_t)"";
    label_000CC174:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CC180:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CC180;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    goto label_000CC1D2;
    label_000CC190:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 8u;
    label_000CC1A0:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC1A0;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = cpu->eax + 1u;
    label_000CC1C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CC1C0;
    label_000CC1C7:
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0]);
    cpu->ecx = cpu->edx + 0x54u;
    label_000CC1D2:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCC1D7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xCC1D7u));
    label_000CC1D7:
    cpu->ebx = lift_pop32(cpu);
    label_000CC1D8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    if (cpu->eax == 0x1Cu) goto label_000CC208;
    if (cpu->eax != 0x2Eu) goto label_000CC224;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebp + 0xCu)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CC1F5;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CC1F5:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (12.0);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CC208:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebp + 0xCu)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CC218;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CC218:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (30.0);
    g_sfera_graphics_runtime.fog_distance = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000CC224:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CC280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (uintptr_t)"gfx_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC290u)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CC290u));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CCEE0;
    if (cpu->eax != 0u) goto label_000CCEDB;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC2A8u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CC2A8u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"gfx_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC2B8u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CC2B8u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_000CCEDA;
    *(uint32_t*)(cpu->esi + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CB950);
    lift_x87_push(cpu, (double)g_sfera_graphics_runtime.fog_distance);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25;
    *(float*)((uintptr_t)&g_sfera_sphere_options_runtime.saved_fog_distance.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    cpu->edx = g_sfera_graphics_runtime.lods_enabled;
    *(float*)((uintptr_t)&g_sfera_sphere_options_runtime.saved_lod_distance.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebp);
    g_sfera_graphics_options_runtime.graphics_values[9] = cpu->eax;
    cpu->eax = g_sfera_options_dialog_runtime.reflection_quality;
    lift_push32(cpu, cpu->edi);
    g_sfera_graphics_options_runtime.graphics_values[8] = cpu->ecx;
    g_sfera_sphere_options_runtime.saved_lods_enabled = cpu->edx;
    g_sfera_graphics_options_runtime.graphics_page = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC317u)); sfera_sub_004C9EB0(cpu, LIFT_CODE_TOKEN_VA(0x4CC317u));
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC321u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CC321u));
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = (uintptr_t)"XRES";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC339u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CC339u));
    cpu->edx = g_sfera_graphics_runtime.display_height;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = (uintptr_t)"YRES";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC351u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CC351u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_window_runtime.windowed) == 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC360u)); sfera_sub_004CB790(cpu, LIFT_CODE_TOKEN_VA(0x4CC360u));
    cpu->ebp = g_sfera_shadow_runtime.manager;
    if (cpu->ebp != 0u) goto label_000CC387;
    lift_push32(cpu, 0x2B6u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SphereOptions.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC37Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CC37Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC384u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CC384u));
    cpu->esp += 0x10u;
    label_000CC387:
    cpu->edi = g_sfera_graphics_display_depth_bits;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC39Bu)); sfera_sub_004C9D60(cpu, LIFT_CODE_TOKEN_VA(0x4CC39Bu));
    cpu->ecx = g_sfera_main_render_runtime.grass_depth_mode;
    g_sfera_graphics_options_runtime.graphics_values[3] = cpu->ecx;
    cpu->ecx = g_sfera_window_runtime.windowed;
    g_sfera_graphics_options_runtime.graphics_values[5] = cpu->eax;
    g_sfera_graphics_options_runtime.graphics_values[1] = cpu->edi;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0xA0u);
    g_sfera_graphics_options_runtime.graphics_values[2] = cpu->edx;
    cpu->edx = g_sfera_graphics_runtime.post_effects_enabled;
    g_sfera_graphics_options_runtime.graphics_values[4] = cpu->ecx;
    g_sfera_options_dialog_runtime.pending_graphics_value = cpu->eax;
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[0];
    g_sfera_graphics_options_runtime.graphics_values[6] = cpu->edx;
    g_sfera_options_dialog_runtime.comparison_graphics_value = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    g_sfera_graphics_options_runtime.graphics_values[10] = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    g_sfera_graphics_options_runtime.graphics_values[11] = cpu->edi;
    cpu->ecx = 7u;
    (void)cpu;
    label_000CC400:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC400;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.end;
    cpu->edx -= g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->edx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC444:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC444;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[5];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 4u;
    label_000CC471:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC471;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 4u;
    label_000CC4A0:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC4A0;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[2];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0x11u;
    label_000CC4D1:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC4D1;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0x11u;
    label_000CC4F7:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC4F7;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[3];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 5u;
    label_000CC522:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC522;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26 == 0u) goto label_000CC5C4;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC556u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CC556u));
    cpu->ebx = 0x10u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CC564;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CC566;
    label_000CC564:
    cpu->ecx = cpu->eax;
    label_000CC566:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 5u;
    label_000CC573:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CC573;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CC58E;
    cpu->ecx = (uintptr_t)"";
    label_000CC58E:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CC593:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CC593;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC5A6u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC5A6u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 5u;
    label_000CC5B3:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC5B3;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    goto label_000CC640;
    label_000CC5C4:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC5CEu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CC5CEu));
    cpu->ebx = 0x10u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CC5DC;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CC5DE;
    label_000CC5DC:
    cpu->ecx = cpu->eax;
    label_000CC5DE:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 5u;
    label_000CC5F0:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CC5F0;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CC60B;
    cpu->ecx = (uintptr_t)"";
    label_000CC60B:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CC610:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CC610;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC623u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC623u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 5u;
    label_000CC630:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC630;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    label_000CC640:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC660:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC660;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    if (g_sfera_graphics_runtime.lods_enabled == 0u) goto label_000CC7A2;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC69Au)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CC69Au));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CC6A3;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CC6A5;
    label_000CC6A3:
    cpu->ecx = cpu->eax;
    label_000CC6A5:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 8u;
    label_000CC6B2:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CC6B2;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CC6CB;
    cpu->ecx = (uintptr_t)"";
    label_000CC6CB:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CC6D0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CC6D0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC6E3u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC6E3u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC6F0:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC6F0;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CC720:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC720;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CC750:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC750;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (12.0);
    *(uint16_t*)(cpu->esp + 0x12u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x12u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, 0u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x20u);
    *(uint64_t*)(cpu->esp + 0x20u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    goto label_000CC851;
    label_000CC7A2:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC7ACu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CC7ACu));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CC7B5;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CC7B7;
    label_000CC7B5:
    cpu->ecx = cpu->eax;
    label_000CC7B7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = 8u;
    label_000CC7C4:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CC7C4;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CC7DD;
    cpu->ecx = (uintptr_t)"";
    label_000CC7DD:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CC7E2:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CC7E2;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC7F5u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC7F5u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 7u;
    label_000CC802:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CC802;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CC831:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC831;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CC851:
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%dx%d %d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CC877u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text;
    cpu->esp += 0x14u;
    cpu->edi = cpu->eax + 1u;
    (void)cpu;
    label_000CC8A0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CC8A0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.resolution_text);
    cpu->ecx += 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC8B7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC8B7u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[2];
    cpu->eax <<= 9u;
    cpu->eax += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[0][0];
    cpu->ecx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CC8E8;
    cpu->ecx = (uintptr_t)"";
    label_000CC8E8:
    cpu->eax = cpu->ecx;
    cpu->ebp = cpu->eax + 1u;
    label_000CC8F0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CC8F0;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC903u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC903u));
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[3];
    if (cpu->eax >= 2u) goto label_000CC950;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax <<= 9u;
    cpu->eax += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edi = cpu->eax;
    if (cpu->eax != 0u) goto label_000CC93B;
    cpu->edi = (uintptr_t)"";
    label_000CC93B:
    cpu->eax = cpu->edi;
    cpu->ebp = cpu->eax + 1u;
    label_000CC940:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CC940;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx += 0x54u;
    goto label_000CC987;
    label_000CC950:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->edi = cpu->eax + 1u;
    label_000CC975:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CC975;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0]);
    cpu->ecx = cpu->edx + 0x54u;
    label_000CC987:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC98Cu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CC98Cu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = 0x13u;
    label_000CC9A0:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CC9A0;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25 == 0u) goto label_000CCA79;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT16";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CC9D2u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CC9D2u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CC9DB;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CC9DD;
    label_000CC9DB:
    cpu->ecx = cpu->eax;
    label_000CC9DD:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 6u;
    label_000CC9F0:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CC9F0;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CCA0B;
    cpu->ecx = (uintptr_t)"";
    label_000CCA0B:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CCA10:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CCA10;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCA23u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CCA23u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0x13u;
    label_000CCA30:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CCA30;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CCA58:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCA58;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    goto label_000CCB7D;
    label_000CCA79:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT17";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCA83u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CCA83u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CCA8C;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CCA8E;
    label_000CCA8C:
    cpu->ecx = cpu->eax;
    label_000CCA8E:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 6u;
    label_000CCAA0:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CCAA0;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CCABB;
    cpu->ecx = (uintptr_t)"";
    label_000CCABB:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CCAC0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CCAC0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCAD3u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CCAD3u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0x13u;
    label_000CCAE0:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CCAE0;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CCB07:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCB07;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0xAAu); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x9C6u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 9u;
    label_000CCB34:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCB34;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_x87_push(cpu, (double)g_sfera_graphics_runtime.fog_distance);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (30.0);
    *(uint16_t*)(cpu->esp + 0x12u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x12u);
    cpu->eax|=0xC00u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, 0u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x20u);
    *(uint64_t*)(cpu->esp + 0x20u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CCB7D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0x17u;
    label_000CCB90:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCB90;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0x17u;
    label_000CCBB5:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCBB5;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_options_dialog_runtime.reflection_quality;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 7u;
    label_000CCBE0:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCBE0;
    cpu->edx = g_sfera_options_dialog_runtime.reflection_quality;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx <<= 9u;
    cpu->ecx = (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[4][0];
    if ((cpu->ecx -= cpu->edx) != 0u) goto label_000CCC03;
    cpu->ecx = (uintptr_t)"";
    label_000CCC03:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CCC08:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CCC08;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCC1Bu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CCC1Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0xBu;
    label_000CCC28:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCC28;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    if (g_sfera_window_runtime.windowed == 0u) goto label_000CCCC8;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT61";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCC58u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CCC58u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CCC61;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CCC63;
    label_000CCC61:
    cpu->ecx = cpu->eax;
    label_000CCC63:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 0x11u;
    label_000CCC70:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CCC70;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CCC83;
    cpu->ecx = (uintptr_t)"";
    label_000CCC83:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CCC88:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CCC88;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCC9Bu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CCC9Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0xBu;
    label_000CCCA8:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCCA8;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    goto label_000CCD47;
    label_000CCCC8:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT62";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCCD2u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CCCD2u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebx) goto label_000CCCDB;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CCCDD;
    label_000CCCDB:
    cpu->ecx = cpu->eax;
    label_000CCCDD:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 0x11u;
    label_000CCCF0:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CCCF0;
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CCD03;
    cpu->ecx = (uintptr_t)"";
    label_000CCD03:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CCD08:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CCD08;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCD1Bu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CCD1Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0xBu;
    label_000CCD28:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCD28;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edi = 0u;
    label_000CCD47:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCD52u)); sfera_sub_004D8360(cpu, LIFT_CODE_TOKEN_VA(0x4CCD52u));
    if ((cpu->eax & 0xFFu) != 1u) goto label_000CCDB8;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0xAu;
    label_000CCD63:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCD63;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0xAu;
    (void)cpu;
    label_000CCD90:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCD90;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[6];
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x157Eu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    goto label_000CCE24;
    label_000CCDB8:
    g_sfera_graphics_options_runtime.graphics_values[6] = cpu->edi;
    g_sfera_options_dialog_runtime.graphics_snapshot[6] = cpu->edi;
    g_sfera_graphics_runtime.post_effects_enabled = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = 0xAu;
    label_000CCDD7:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCDD7;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Fu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0xAu;
    label_000CCE04:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000CCE04;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, 0x157Eu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CCE24:
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[6];
    if ((int32_t)(cpu->ecx) >= (int32_t)(2u)) goto label_000CCE80;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = 8u;
    label_000CCE40:
    --cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx != 0u) goto label_000CCE40;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx <<= 9u;
    cpu->ecx += (uintptr_t)&g_sfera_sphere_options_runtime.option_labels[5][0];
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CCE64;
    cpu->edx = (uintptr_t)"";
    label_000CCE64:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CCE70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CCE70;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    goto label_000CCEC2;
    label_000CCE80:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = 8u;
    label_000CCE90:
    --cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->ecx != 0u) goto label_000CCE90;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    cpu->esi = cpu->eax + 1u;
    label_000CCEB0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CCEB0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0]);
    cpu->ecx = cpu->edx + 0x54u;
    label_000CCEC2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCEC7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CCEC7u));
    cpu->ecx = 7u;
    cpu->esi = (uintptr_t)&g_sfera_graphics_options_runtime.graphics_values[0];
    cpu->edi = (uintptr_t)&g_sfera_options_dialog_runtime.graphics_snapshot[0];
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000CCEDA:
    cpu->esi = lift_pop32(cpu);
    label_000CCEDB:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CCEE0:
    if (cpu->eax == 0u) goto label_000CCEDB;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCEF0u)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CCEF0u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCEF7u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CCEF7u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(void*)&g_sfera_graphics_options_runtime.graphics_values[2]);
    cpu->ecx = g_sfera_shadow_runtime.manager;
    *(uint8_t*)(cpu->ecx + 0xA0u) = cpu->eax & 0xFFu;
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[3];
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[4];
    cpu->ecx = (uintptr_t)"config.cfg";
    g_sfera_main_render_runtime.grass_depth_mode = cpu->edx;
    g_sfera_window_runtime.windowed = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCF28u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CCF28u));
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->edx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->ecx = (uintptr_t)"XRES";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCF43u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCF43u));
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->ecx = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u) + 4u);
    cpu->ecx = (uintptr_t)"YRES";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCF5Fu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCF5Fu));
    cpu->eax = g_sfera_graphics_options_runtime.graphics_values[5];
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = g_sfera_options_dialog_runtime.graphics_modes.begin;
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 8u);
    cpu->ecx = (uintptr_t)"DEPTH";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCF7Au)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCF7Au));
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[3];
    cpu->ecx = (uintptr_t)"GRASS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCF8Au)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCF8Au));
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[4];
    cpu->ecx = (uintptr_t)"WINDOWED";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCF9Au)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCF9Au));
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[2];
    cpu->ecx = (uintptr_t)"SHAD";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCFAAu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCFAAu));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25;
    cpu->ecx = (uintptr_t)"AUTOFOG";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCFBAu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCFBAu));
    lift_x87_push(cpu, (double)g_sfera_graphics_runtime.fog_distance);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCFC5u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4CCFC5u));
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)"FOGDIST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCFD1u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCFD1u));
    cpu->edx = g_sfera_options_dialog_runtime.reflection_quality;
    cpu->ecx = (uintptr_t)"REFLQUAL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCFE1u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCFE1u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    cpu->ecx = (uintptr_t)"EFFECTS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CCFF1u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CCFF1u));
    cpu->edx = g_sfera_graphics_runtime.lods_enabled;
    cpu->ecx = (uintptr_t)"LODS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD001u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD001u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD00Cu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4CD00Cu));
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)"LOD_DISTANCE";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD018u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD018u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD023u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4CD023u));
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)"MIN_LOD_DIST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD02Fu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD02Fu));
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[6];
    cpu->ecx = (uintptr_t)"POSTEFFECTS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD03Fu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD03Fu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD04Au)); sfera_sub_004261B0(cpu, LIFT_CODE_TOKEN_VA(0x4CD04Au));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD04Fu)); sfera_sub_00448490(cpu, LIFT_CODE_TOKEN_VA(0x4CD04Fu));
    cpu->ecx = g_sfera_graphics_options_runtime.graphics_values[10];
    if (cpu->ecx != g_sfera_graphics_options_runtime.graphics_values[0]) goto label_000CD07C;
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[11];
    if (cpu->edx != g_sfera_graphics_options_runtime.graphics_values[1]) goto label_000CD07C;
    cpu->eax = g_sfera_options_dialog_runtime.comparison_graphics_value;
    if (cpu->eax == g_sfera_graphics_options_runtime.graphics_values[4]) goto label_000CCEDB;
    label_000CD07C:
    cpu->ecx = 0x65687073u;
    cpu->edx = *(uint32_t*)(((uintptr_t)"sphere.exe") + 4u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"sphere.exe") + 8u));
    (*(uint32_t*)(void*)&g_sfera_process_runtime.executable_path[0]) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"sphere.exe") + 0xAu));
    *(uint32_t*)((uintptr_t)&g_sfera_process_runtime.executable_path[4]) = cpu->edx;
    *(uint16_t*)((uintptr_t)&g_sfera_process_runtime.executable_path[8]) = cpu->eax & 0xFFFFu;
    *(uint8_t*)((uintptr_t)&g_sfera_process_runtime.executable_path[10]) = cpu->ecx & 0xFFu;
    g_sfera_relaunch_runtime.argument[0] = (char)0u;
    g_sfera_render_lookup_runtime.initialized = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
