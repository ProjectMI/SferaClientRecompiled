#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004CD1A0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (uintptr_t)"options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD1ADu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD1ADu));
    lift_test[0]=(cpu->ebx & 0xFFu)==0u;
    cpu->ebx = lift_pop32(cpu);
    if (lift_test[0]) goto label_000CD1D3;
    if (cpu->eax != 0u) goto label_000CD1D2;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD1C4u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CD1C4u));
    if (cpu->eax == 0u) goto label_000CD1D2;
    SphereUI::bindEventHandler(reinterpret_cast<SphereUI::Window*>(cpu->eax), SphereUI::WindowEventHandler::options);
    label_000CD1D2:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD1D3:
    if (cpu->eax == 0u) goto label_000CD1D2;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    sfera_sub_004B8700(cpu, stop_address); return;
}






__declspec(noinline) void sfera_sub_004CDF00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    x87_v0 = 1.0;
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x8Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x94u) = cpu->ecx;
    *(float*)(cpu->eax + 0x18u) = x87_v0;
    x87_v1 = 0.0;
    cpu->edx |= 0xFFFFFFFFu;
    *(float*)(cpu->eax + 0x14u) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    *(float*)(cpu->eax + 0x38u) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->ecx;
    *(float*)(cpu->eax + 0x34u) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x60u) = cpu->ecx;
    *(float*)(cpu->eax + 0x58u) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x80u) = cpu->ecx;
    *(float*)(cpu->eax + 0x54u) = x87_v1;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + 0x78u) = x87_v1; 
    *(float*)(cpu->eax + 0x74u) = x87_v0; 
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDF70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (cpu->edi == 0u) goto label_000CDFBC;
    cpu->edx = 0xA6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDF8Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CDF8Eu));
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_000CDF93:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CDF93;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDFA3u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4CDFA3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_000CDFB0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000CDFB0;
    goto label_000CDFC2;
    label_000CDFBC:
    *(uint32_t*)(cpu->esi) = 0u;
    label_000CDFC2:
    if (cpu->ebx == 0u) goto label_000CDFDE;
    cpu->edx = 0xACu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDFD5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CDFD5u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDFDBu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CDFDBu));
    cpu->esp += 4u;
    label_000CDFDE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDFF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x94u);
    if (cpu->eax == cpu->ebp) goto label_000CE0D4;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x90u) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_000CE078;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (cpu->eax == 0u) goto label_000CE059;
    cpu->edi = 0u;
    label_000CE020:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    if (*(uint32_t*)(cpu->edi + cpu->eax) == 0u) goto label_000CE04D;
    cpu->edx = 0xBAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE03Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE03Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE04Au)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CE04Au));
    cpu->esp += 4u;
    label_000CE04D:
    ++cpu->ebx;
    cpu->edi += 0x3Cu;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x94u)) goto label_000CE020;
    label_000CE059:
    cpu->edx = 0xBCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE068u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE068u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE074u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CE074u));
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu);
    label_000CE078:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->edi;
    if (cpu->ebp == cpu->edi) goto label_000CE0D3;
    cpu->edx = 0xC3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE099u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE099u));
    cpu->eax = cpu->ebp;
    cpu->edx = 0x3Cu;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE0B1u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4CE0B1u));
    cpu->ecx = cpu->ebp;
    cpu->ecx <<= 4u;
    cpu->ecx -= cpu->ebp;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->ebp;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4CE0CBu));
    cpu->esp += 0x10u;
    label_000CE0D3:
    cpu->edi = lift_pop32(cpu);
    label_000CE0D4:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE0E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (g_sfera_sprite_runtime.render_mode == cpu->esi) goto label_000CE137;
    cpu->eax = cpu->esi;
    if ((cpu->eax) == 0u) goto label_000CE126;
    if ((--cpu->eax) == 0u) goto label_000CE10F;
    if ((--cpu->eax) != 0u) goto label_000CE131;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE107u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x4CE107u));
    g_sfera_sprite_runtime.render_mode = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CE10F:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE11Eu)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x4CE11Eu));
    g_sfera_sprite_runtime.render_mode = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CE126:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCE131u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_RVA(0xCE131u));
    label_000CE131:
    g_sfera_sprite_runtime.render_mode = cpu->esi;
    label_000CE137:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE4F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + (cpu->edx * 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000CE558;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx + 1u;
    label_000CE524:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CE524;
    cpu->ecx -= cpu->edi;
    cpu->edi = cpu->eax + 1u;
    label_000CE530:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CE530;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu);
    if (cpu->ecx <= cpu->eax) goto label_000CE585;
    cpu->edx = 0x23Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE54Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE54Du));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE555u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CE555u));
    cpu->esp += 4u;
    label_000CE558:
    cpu->edx = 0x23Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE567u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE567u));
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_000CE570:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CE570;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE580u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4CE580u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_000CE585:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->ebp;
    label_000CE590:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000CE590;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5A1u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4CE5A1u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000CE5BD;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Sprite::Texture not found '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5B4u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE5B4u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5BAu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE5BAu));
    cpu->esp += 0xCu;
    label_000CE5BD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5C9u)); sfera_sub_0044FC60(cpu, LIFT_CODE_TOKEN_VA(0x4CE5C9u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->eax == 0u) goto label_000CE689;
    cpu->edx = *(uint32_t*)(cpu->eax);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE5E3;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE5E3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE5F5;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE5F5:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0xCu) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u))));
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if ((int32_t)cpu->edx >= 0) goto label_000CE60A;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE60A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE61C;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE61C:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x1Cu) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 8u))));
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if ((int32_t)cpu->edx >= 0) goto label_000CE631;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE631:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE643;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE643:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0xCu))));
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->edx >= 0) goto label_000CE658;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE658:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE66A;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE66A:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x24u) = x87_v0; 
    *(float*)(cpu->esi + 0x10u) = (double)*(float*)(cpu->esi + 0x14u);
    *(float*)(cpu->esi + 0x20u) = (double)*(float*)(cpu->esi + 0x1Cu);
    *(float*)(cpu->esi + 0x18u) = (double)*(float*)(cpu->esi + 0xCu);
    *(float*)(cpu->esi + 0x28u) = (double)*(float*)(cpu->esi + 0x24u);
    goto label_000CE6A5;
    label_000CE689:
    x87_v0 = 0.0;
    *(float*)(cpu->esi + 0x1Cu) = x87_v0;
    *(float*)(cpu->esi + 0xCu) = x87_v0;
    x87_v1 = 1.0;
    *(float*)(cpu->esi + 0x10u) = x87_v1;
    *(float*)(cpu->esi + 0x24u) = x87_v1;
    *(float*)(cpu->esi + 0x14u) = x87_v1;
    *(float*)(cpu->esi + 0x28u) = x87_v1; 
    *(float*)(cpu->esi + 0x20u) = x87_v0;
    *(float*)(cpu->esi + 0x18u) = x87_v0; 
    label_000CE6A5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->eax == 0u) goto label_000CE6C3;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    goto label_000CE6DC;
    label_000CE6C3:
    *(uint32_t*)(cpu->esi + 0x34u) = 0u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000CE6DC:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE700(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax >= *(uint32_t*)(cpu->ecx + 0x94u)) goto label_000CE88D;
    cpu->edx = cpu->eax;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + (cpu->edx * 4u);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_000CE88C;
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE745u)); sfera_sub_0044FC60(cpu, LIFT_CODE_TOKEN_VA(0x4CE745u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_000CE88C;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE75F;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE75F:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE771;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE771:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0xCu) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE786;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE786:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE798;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE798:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x1Cu) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 8u))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE7AD;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE7AD:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE7BF;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE7BF:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x10u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0xCu))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE7D4;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE7D4:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE7E6;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE7E6:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x20u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x10u))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE7FB;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE7FB:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE80D;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE80D:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x14u))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE822;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE822:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE834;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE834:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x24u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x18u))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE849;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE849:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE85B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE85B:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x18u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE875;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000CE875:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE887;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000CE887:
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    label_000CE88C:
    cpu->esi = lift_pop32(cpu);
    label_000CE88D:
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x148u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x150u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x164u);
    cpu->ebp = cpu->ecx;
    { const uint32_t __parser_arg_021_13_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_021_13_1 = static_cast<uint32_t>((uintptr_t)"name");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_13_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_021_13_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000CE908;
    cpu->eax = cpu->esp + 0x54u;
    { const uint32_t __parser_arg_021_14_0 = static_cast<uint32_t>(cpu->eax); const uint32_t __parser_arg_021_14_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_021_14_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_021_14_0))))); }
    if (cpu->eax == 0u) goto label_000CE908;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE906u)); sfera_sub_004CDF70(cpu, LIFT_CODE_TOKEN_VA(0x4CE906u));
    goto label_000CE923;
    label_000CE908:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Name not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE91Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE91Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE920u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE920u));
    cpu->esp += 0x14u;
    label_000CE923:
    { const uint32_t __parser_arg_021_15_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_021_15_1 = static_cast<uint32_t>((uintptr_t)"size");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_15_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_021_15_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000CE94E;
    { const uint32_t __parser_arg_021_16_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(__parser_direct->readInt(__parser_arg_021_16_0)); }
    { const uint32_t __parser_arg_021_17_0 = static_cast<uint32_t>(1u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(__parser_direct->readInt(__parser_arg_021_17_0)); }
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    goto label_000CE969;
    label_000CE94E:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Size not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE960u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE960u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE966u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE966u));
    cpu->esp += 0x14u;
    label_000CE969:
    cpu->eax = cpu->esp + 0x1Cu;
    { const uint32_t __parser_arg_021_18_0 = static_cast<uint32_t>(cpu->eax);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->getScanRange(reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_021_18_0))); }
    { const uint32_t __parser_arg_021_19_0 = static_cast<uint32_t>(cpu->edi);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setScanRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_021_19_0))); }
    { const uint32_t __parser_arg_021_20_0 = static_cast<uint32_t>((uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_20_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000CE9A5;
    (void)cpu;
    label_000CE990:
    { const uint32_t __parser_arg_021_21_0 = static_cast<uint32_t>((uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_21_0))) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000CE990;
    if (cpu->ebx != 0u) goto label_000CE9C4;
    label_000CE9A5:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> At least one texture must be specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9BBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE9BBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9C1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE9C1u));
    cpu->esp += 0x14u;
    label_000CE9C4:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9CCu)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CE9CCu));
    if ((int32_t)cpu->ebx <= 0) goto label_000CEB41;
    { const uint32_t __parser_arg_021_22_0 = static_cast<uint32_t>(cpu->edi);
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setScanRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_021_22_0))); }
    { const uint32_t __parser_arg_021_23_0 = static_cast<uint32_t>((uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_23_0))) ? 1u : 0u; }
    cpu->ebp = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000CEA97;
    label_000CE9F8:
    cpu->ecx = cpu->esp + 0x54u;
    { const uint32_t __parser_arg_021_24_0 = static_cast<uint32_t>(cpu->ecx); const uint32_t __parser_arg_021_24_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_021_24_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_021_24_0))))); }
    if (cpu->eax == 0u) goto label_000CEA83;
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_sprite_runtime.texture_token[0]);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%s %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xCEA40u));
    cpu->esp += 0x2Cu;
    if (cpu->eax == 9u) goto label_000CEA69;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'texture'.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA60u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA60u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA66u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA66u));
    cpu->esp += 0x14u;
    label_000CEA69:
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA82u)); sfera_sub_004CE4F0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA82u));
    ++cpu->ebx;
    label_000CEA83:
    { const uint32_t __parser_arg_021_25_0 = static_cast<uint32_t>((uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_25_0))) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000CE9F8;
    label_000CEA97:
    { const uint32_t __parser_arg_021_26_0 = static_cast<uint32_t>(cpu->edi);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setScanRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_021_26_0))); }
    { const uint32_t __parser_arg_021_27_0 = static_cast<uint32_t>((uintptr_t)"tcoords");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_27_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000CEB41;
    cpu->ebx = cpu->esi + 0x10u;
    label_000CEAB6:
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    lift_native_call(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xCEAF1u));
    cpu->esp += 0x2Cu;
    if (cpu->eax == 9u) goto label_000CEB1A;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'tcoords'.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB11u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CEB11u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB17u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CEB17u));
    cpu->esp += 0x14u;
    label_000CEB1A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB2Du)); sfera_sub_004CE700(cpu, LIFT_CODE_TOKEN_VA(0x4CEB2Du));
    { const uint32_t __parser_arg_021_28_0 = static_cast<uint32_t>((uintptr_t)"tcoords");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_021_28_0))) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000CEAB6;
    label_000CEB41:
    cpu->ecx = cpu->esp + 0x1Cu;
    { const uint32_t __parser_arg_021_29_0 = static_cast<uint32_t>(cpu->ecx);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setScanRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_021_29_0))); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x148u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CEC50(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    g_sfera_scene_render_runtime.interface_quad[0].diffuse = cpu->ecx;
    x87_v1 = 0.5;
    x87_v0 = (x87_v0) - (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 4u);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x) = x87_v1;
    x87_v2 = (double)*(float*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 8u) = 2u;
    x87_v2 = (x87_v2) - (x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].y) = x87_v2;
    x87_v3 = 1.0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].rhw) = x87_v3;
    x87_v4 = 0.0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].z) = x87_v4;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].u) = (double)*(float*)(cpu->edx);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].v) = (double)*(float*)(cpu->edx + 4u);
    x87_v5 = (double)*(float*)(cpu->esp + 0xCu);
    g_sfera_scene_render_runtime.interface_quad[1].diffuse = cpu->ecx;
    x87_v5 = (x87_v5) - (x87_v0);
    *(uint32_t*)(cpu->esp + 0xCu) = (uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x;
    *(float*)(cpu->esp + 4u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 4u);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].x) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].y) = x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].rhw) = x87_v4;
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].z) = x87_v4;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].u) = (double)*(float*)(cpu->edx + 8u);
    x87_v5 = (double)*(float*)(cpu->edx + 0xCu);
    g_sfera_scene_render_runtime.interface_quad[2].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].v) = x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].x) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x20u;
    x87_v0 = x87_v4 - x87_v0; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->esp + 4u) = 6u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].y) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].rhw) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].z) = x87_v3;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].u) = (double)*(float*)(cpu->edx + 0x10u);
    x87_v4 = (double)*(float*)(cpu->edx + 0x14u);
    g_sfera_scene_render_runtime.interface_quad[3].diffuse = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].v) = x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].x) = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].y) = x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].rhw) = x87_v1; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].z) = x87_v0; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].u) = (double)*(float*)(cpu->edx + 0x18u);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].v) = (double)*(float*)(cpu->edx + 0x1Cu);
    sfera_sub_004D9050(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004CEDA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->eax > 0) goto label_000CEDBA;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEDB8u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4CEDB8u));
    goto label_000CEDD3;
    label_000CEDBA:
    cpu->ecx = cpu->eax;
    if ((uint32_t)(g_sfera_sprite_runtime.render_mode) != 0u) goto label_000CEDC9;
    cpu->edx = 0u;
    goto label_000CEDCE;
    label_000CEDC9:
    cpu->edx = 1u;
    label_000CEDCE:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCEDD3u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_RVA(0xCEDD3u));
    label_000CEDD3:
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEE00u)); sfera_sub_004CEC50(cpu, LIFT_CODE_TOKEN_VA(0x4CEE00u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_000CF182;
    cpu->edx = 0x88u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF177u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF177u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF17Fu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CF17Fu));
    cpu->esp += 4u;
    label_000CF182:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF191u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CF191u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF1A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF1AEu)); sfera_sub_004CDF70(cpu, LIFT_CODE_TOKEN_VA(0x4CF1AEu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF1B7u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CF1B7u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF1C5u)); sfera_sub_004CE4F0(cpu, LIFT_CODE_TOKEN_VA(0x4CF1C5u));
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x7Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x38u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF280(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x8Cu);
    if ((int32_t)cpu->eax <= 0) goto label_000CF296;
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x8Cu) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CF296:
    cpu->edx = 0x9Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2A5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF2A5u));
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_000CF2C4;
    cpu->edx = 0x88u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2B9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF2B9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2C1u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CF2C1u));
    cpu->esp += 4u;
    label_000CF2C4:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D3u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D3u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D9u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D9u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_ui_tool_tip_ctrl_reset(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->reset(); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_tool_tip_ctrl_show_at(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->showAt(static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u))), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 8u)))); cpu->esp += 12u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_tool_tip_ctrl_handle_input(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->SphereUI::ToolTipCtrl::handleInput(*reinterpret_cast<const SphereUI::WindowInput*>(static_cast<std::uintptr_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u))))); cpu->esp += 8u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_tool_tip_ctrl_draw(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->SphereUI::ToolTipCtrl::draw(); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_tool_tip_ctrl_initialize(LiftCpu* cpu, uint32_t stop_address) { auto* self = std::construct_at(reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))); self->initialize(); cpu->eax = address32(self); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_tool_tip_ctrl_handle_message(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->SphereUI::ToolTipCtrl::handleMessage(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 8u)), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 12u))); cpu->esp += 16u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_sub_004D0F50(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx != 0u) goto label_000D0F57;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D0F57:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetDlgItem), LIFT_CODE_TOKEN_VA(0x4D0F5Cu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000D0FAE;
    label_000D0F87:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->esi + 8u) != cpu->edx) goto label_000D0FA8;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0FA0u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D0FA0u));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    goto label_000D0FAA;
    label_000D0FA8:
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000D0FAA:
    if (cpu->esi != cpu->ebx) goto label_000D0F87;
    label_000D0FAE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::PeekMessageA);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::PeekMessageA)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu), *(uint32_t*)(cpu->esp + 0x10u)); cpu->esp += 0x14u;
    if (cpu->eax == 0u) goto label_000D1046;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::TranslateMessage);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::IsDialogMessageA);
    lift_push32(cpu, cpu->esi);
    label_000D0FF0:
    if (*(uint32_t*)(cpu->esp + 0x14u) == 0x12u) goto label_000D104B;
    cpu->eax = g_sfera_win32_dialog_registry.sentinel;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000D101E;
    label_000D1002:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->edx = cpu->esp + 0x10u;

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::IsDialogMessageA)))(cpu->eax, cpu->edx);
    if (cpu->eax != 0u) goto label_000D1030;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != g_sfera_win32_dialog_registry.sentinel) goto label_000D1002;
    label_000D101E:
    cpu->eax = cpu->esp + 0x10u;

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::TranslateMessage)))(cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::DispatchMessageA), LIFT_CODE_TOKEN_RVA(0xD102Au));
    label_000D1030:
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::PeekMessageA)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu), *(uint32_t*)(cpu->esp + 0x10u)); cpu->esp += 0x14u;
    if (cpu->eax != 0u) goto label_000D0FF0;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000D1046:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D104B:
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_VA(0x4D104Du));
    cpu->eip = 0x4D1053u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004D1060(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000D1090;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == cpu->esi) goto label_000D107C;
    label_000D1071:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000D1095;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->esi) goto label_000D1071;
    label_000D107C:
    cpu->eax = cpu->ecx;
    label_000D107E:
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != 0xAu) goto label_000D10A1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::EnableWindow), LIFT_CODE_TOKEN_RVA(0xD108Au));
    label_000D1090:
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D1095:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax == 0u) goto label_000D107C;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x20u);
    goto label_000D107E;
    label_000D10A1:
    if (cpu->edx != 7u) goto label_000D10B2;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetFocus), LIFT_CODE_TOKEN_VA(0x4D10A7u));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D10B2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SendMessageA), LIFT_CODE_TOKEN_VA(0x4D10BEu));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D10D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == cpu->esi) goto label_000D10FF;
    label_000D10E0:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000D10F5;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->esi) goto label_000D10E0;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D10EDu));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D10F5:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax == 0u) goto label_000D10FF;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    label_000D10FF:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D1101u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1110(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == cpu->esi) goto label_000D1146;
    label_000D1120:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000D113C;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->esi) goto label_000D1120;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D1132u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D113C:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax == 0u) goto label_000D1146;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    label_000D1146:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D114Du));
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ecx + 0x34u) == cpu->esi) goto label_000D118D;
    label_000D1168:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x34u);
    if (cpu->eax == cpu->esi) goto label_000D1188;
    ++*(uint32_t*)(cpu->ecx + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    if (*(uint32_t*)(cpu->ecx + 0x2Cu) > cpu->edx) goto label_000D117D;
    *(uint32_t*)(cpu->ecx + 0x30u) = cpu->esi;
    label_000D117D:
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->eax;
    if (cpu->eax != cpu->esi) goto label_000D1188;
    *(uint32_t*)(cpu->ecx + 0x30u) = cpu->esi;
    label_000D1188:
    if (*(uint32_t*)(cpu->ecx + 0x34u) != cpu->esi) goto label_000D1168;
    label_000D118D:
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D11A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0x3Cu) != 0u) goto label_000D11B5;
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D11B5:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D11C3u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4D11C3u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx == 0u) goto label_000D11CB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000D11CB:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edx > cpu->eax) goto label_000D11D7;
    cpu->eax -= cpu->edx;
    label_000D11D7:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    lift_push32(cpu, cpu->edi);
    std::memmove((void*)(*(uint32_t*)(cpu->esp + 0x20u)),(void*)(cpu->esi),28u); cpu->ecx = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->edx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->edx) goto label_000D120E;
    ++*(uint32_t*)(cpu->ebp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x30u);
    if (*(uint32_t*)(cpu->ebp + 0x2Cu) > cpu->ecx) goto label_000D1203;
    *(uint32_t*)(cpu->ebp + 0x30u) = cpu->edx;
    label_000D1203:
    --cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x34u) = cpu->eax;
    if (cpu->eax != cpu->edx) goto label_000D120E;
    *(uint32_t*)(cpu->ebp + 0x30u) = cpu->edx;
    label_000D120E:
    --*(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D12C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi == 0u) goto label_000D1352;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->esi;
    if (cpu->eax == 0u) goto label_000D12EC;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DestroyWindow), LIFT_CODE_TOKEN_VA(0x4D12D8u));
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x20u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD12ECu)); sfera_sub_004D1160(cpu, LIFT_CODE_TOKEN_RVA(0xD12ECu));
    label_000D12EC:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_win32_dialog_registry.sentinel;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D12FCu)); sfera_sub_004D0F70(cpu, LIFT_CODE_TOKEN_VA(0x4D12FCu));
    cpu->edx = 0xA2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D130Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D130Bu));
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1313u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4D1313u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D131Cu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D131Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x24u) = 0u;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    cpu->edi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000D1338;
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1335u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D1335u));
    cpu->esp += 4u;
    label_000D1338:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D134Fu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D134Fu));
    cpu->esp += 4u;
    label_000D1352:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1360(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx != 0u) goto label_000D1367;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1367:
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D136Du)); sfera_sub_004D11A0(cpu, LIFT_CODE_TOKEN_VA(0x4D136Du));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    *(uint8_t*)(cpu->edi) = cpu->ebx & 0xFFu;
    cpu->esi = cpu->edi + 0x24u;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x34u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D13C6u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4D13C6u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D1400;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x3Cu) = cpu->ebx;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1400:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D142Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D142Au));
    cpu->eip = 0x4D142Au; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004D1430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->eax != 0u) goto label_000D1441;
    label_000D143B:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D1441:
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    cpu->eax = cpu->eax & 0xFFFFu;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateDialogParamA(reinterpret_cast<HINSTANCE>(static_cast<uintptr_t>(cpu->ecx)), reinterpret_cast<LPCSTR>(static_cast<uintptr_t>(cpu->eax)), nullptr, &sfera_dialog_proc, 0)));
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    if (cpu->eax == 0u) goto label_000D143B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x4D1469u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, 0x71u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::LoadIconA), LIFT_CODE_TOKEN_VA(0x4D1478u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, 0xFFFFFFF2u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetClassLongA), LIFT_CODE_TOKEN_VA(0x4D1485u));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D14A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x8Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D14D4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D14D4u));
    lift_push32(cpu, 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D14DBu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4D14DBu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000D14F9;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D14F5u)); sfera_sub_004D1370(cpu, LIFT_CODE_TOKEN_VA(0x4D14F5u));
    cpu->esi = cpu->eax;
    goto label_000D14FB;
    label_000D14F9:
    cpu->esi = 0u;
    label_000D14FB:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D150Fu)); sfera_sub_004D1430(cpu, LIFT_CODE_TOKEN_VA(0x4D150Fu));
    if (cpu->eax != 0u) goto label_000D1580;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1522u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D1522u));
    if (cpu->esi == 0u) goto label_000D156C;
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D152Eu)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4D152Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1537u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D1537u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x24u) = 0u;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000D1552;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D154Fu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D154Fu));
    cpu->esp += 4u;
    label_000D1552:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1569u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D1569u));
    cpu->esp += 4u;
    label_000D156C:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1580:
    cpu->eax = g_sfera_win32_dialog_registry.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = cpu->eax + 4u;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_win32_dialog_registry.sentinel;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D159Cu)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4D159Cu));
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= g_sfera_win32_dialog_registry.size;
    if (cpu->edx >= 1u) goto label_000D15B7;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1580u); throw std::length_error("std::length_error");
    label_000D15B7:
    ++g_sfera_win32_dialog_registry.size;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}




__declspec(noinline) void sfera_ui_window_control_kind(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->control_kind; cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_window_align_to_screen(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->alignToScreen(false); cpu->esp += 4u; cpu->eip = stop_address; }

__declspec(noinline) void sfera_sub_004D1C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000D1C4A;
    label_000D1C40:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000D1C40;
    label_000D1C4A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_ui_window_update_animation(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->updateAnimation(); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_window_start_animation(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->startAnimation(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u))); cpu->esp += 8u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_window_begin_close(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->beginClose((*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)) & 255u) != 0u); cpu->esp += 8u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_sub_004D2180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->eax < 0x3FFFFFFEu) goto label_000D21A2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2194u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D2194u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2180u); throw std::length_error("std::length_error");
    label_000D21A2:
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (cpu->eax != cpu->edx) goto label_000D21CC;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_000D21ED;
    label_000D21CC:
    if (*(uint8_t*)(cpu->esp + 0x10u) == (cpu->ebx & 0xFFu)) goto label_000D21DF;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_000D21ED;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_000D21ED;
    label_000D21DF:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_000D21ED;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_000D21ED:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000D238E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000D2200:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_000D22CF;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000D2232;
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    *(uint8_t*)(cpu->esi + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000D2380;
    label_000D2232:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_000D2271;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D224B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000D224B:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_000D225E;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_000D226C;
    label_000D225E:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_000D2269;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_000D226C;
    label_000D2269:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_000D226C:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_000D2271:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D2299;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_000D2299:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_000D22B2;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D237D;
    label_000D22B2:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_000D22C5;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D237D;
    label_000D22C5:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D237D;
    label_000D22CF:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000D22F2;
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    *(uint8_t*)(cpu->esi + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000D2380;
    label_000D22F2:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_000D2332;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D230A;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000D230A:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_000D231D;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_000D232C;
    label_000D231D:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000D232A;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D232C;
    label_000D232A:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_000D232C:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_000D2332:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D235A;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_000D235A:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_000D236D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_000D237B;
    label_000D236D:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_000D2378;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_000D237B;
    label_000D2378:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_000D237B:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_000D237D:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_000D2380:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x10u) == (cpu->ebx & 0xFFu)) goto label_000D2200;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000D238E:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x10u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D23B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x14u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D23BDu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4D23BDu));
    cpu->edx = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->edx) goto label_000D23F1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->eax + 0xCu;
    *(uint16_t*)(cpu->eax + 0x10u) = cpu->edx & 0xFFFFu;
    if (cpu->ecx == cpu->edx) goto label_000D23EA;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000D23EA:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D23F1:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D241Bu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D241Bu));
    cpu->eip = 0x4D241Bu; ::DebugBreak(); return;
}

__declspec(noinline) void sfera_ui_window_draw_tool_tips(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->drawToolTips(); cpu->esp += 4u; cpu->eip = stop_address; }




__declspec(noinline) void sfera_sub_004D2D30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x11u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (!sub_pred[0]) goto label_000D2D5A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    label_000D2D45:
    if (*(uint32_t*)(cpu->eax + 0xCu) >= cpu->esi) goto label_000D2D4F;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_000D2D53;
    label_000D2D4F:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000D2D53:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000D2D45;
    cpu->esi = lift_pop32(cpu);
    label_000D2D5A:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->edx == cpu->eax) goto label_000D2D7D;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if (cpu->ecx < *(uint32_t*)(cpu->edx + 0xCu)) goto label_000D2D7D;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D2D7D:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2DA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2DB5u)); sfera_sub_004D2D30(cpu, LIFT_CODE_TOKEN_VA(0x4D2DB5u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = 0u;
    sub_pred[0] = cpu->edx == *(uint32_t*)(cpu->esi + 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (!sub_pred[0]);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}



__declspec(noinline) void sfera_ui_window_queue_event(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->queueEvent(*reinterpret_cast<const SphereUI::WindowEvent*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 4u)))); cpu->esp += 8u; cpu->eip = stop_address; }

__declspec(noinline) void sfera_ui_window_poll_event(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->pollEvent(*reinterpret_cast<SphereUI::WindowEvent*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 4u)))); cpu->esp += 8u; cpu->eip = stop_address; }

__declspec(noinline) void sfera_ui_window_process_events(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->processEvents(); cpu->esp += 4u; cpu->eip = stop_address; }

__declspec(noinline) void sfera_sub_004D3430(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = 1u;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_control_reference_registry_guard)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_000D34BC;
    *(uint32_t*)((uintptr_t)&g_sfera_control_reference_registry_guard) = (uint64_t)(g_sfera_control_reference_registry_guard) | (uint64_t)(cpu->ebx);
    lift_push32(cpu, 0x14u);
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    g_sfera_control_reference_registry.size = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3480u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4D3480u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000D34D2;
    g_sfera_control_reference_registry.sentinel = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ebx & 0xFFu;
    cpu->ecx = g_sfera_control_reference_registry.sentinel;
    *(uint8_t*)(cpu->ecx + 0x11u) = cpu->ebx & 0xFFu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC030) ? 0u : 0xFFFFFFFFu;
    label_000D34BC:
    cpu->eax = (uintptr_t)&g_sfera_control_reference_registry;
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D34D2:
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3500u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D3500u));
    cpu->eip = 0x4D3500u; ::DebugBreak(); return;
}


__declspec(noinline) void sfera_ui_create_control(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = address32(SphereUI::Runtime::makeControl(cpu->ecx)); cpu->esp += 4u; cpu->eip = stop_address; }


} // namespace lifted
