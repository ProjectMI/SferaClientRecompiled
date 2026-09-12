#include "lifted_functions.h"
#include <cmath>
namespace lifted {


















__declspec(noinline) void sfera_sub_0048DBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax != 1u) goto label_0008DBBF;
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008DBB1;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008DBB1:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0xCu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint8_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008DBBF:
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008DBC7;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008DBC7:
    cpu->ecx += *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48DBD3u));
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DC80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    if (cpu->esi >= cpu->edx) goto label_0008DCD3;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_0008DC9D;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_0008DC9F;
    label_0008DC9D:
    cpu->eax = cpu->edi;
    label_0008DC9F:
    cpu->ebx = cpu->edx + cpu->eax;
    if (cpu->ecx < 0x10u) goto label_0008DCAB;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_0008DCAD;
    label_0008DCAB:
    cpu->eax = cpu->edi;
    label_0008DCAD:
    cpu->esi += cpu->eax;
    if (cpu->esi >= cpu->ebx) goto label_0008DCD3;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0008DCB7:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x48DCC1u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0008DCDD;
    ++cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_0008DCB7;
    label_0008DCD3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008DCDD:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0008DCE5;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_0008DCE5:
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DCF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->edx == 0u) goto label_0008DD6D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ecx >= cpu->edx) goto label_0008DD0E;
    cpu->edx = cpu->ecx;
    goto label_0008DD0F;
    label_0008DD0E:
    --cpu->edx;
    label_0008DD0F:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0008DD17;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0008DD17:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = native_memchr_address32();
    cpu->esi = cpu->eax + cpu->edx;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi));

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_memchr_address32()))(cpu->ebx, cpu->eax, cpu->edi);

    if (cpu->eax == 0u) goto label_0008DD55;
    label_0008DD37:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DD40u)); sfera_sub_004020B0(cpu, LIFT_CODE_TOKEN_VA(0x48DD40u));
    if (cpu->esi == cpu->eax) goto label_0008DD6D;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->esi + 0xFFFFFFFFu));
    --cpu->esi;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_memchr_address32()))(cpu->ebx, cpu->ecx, cpu->edi);

    if (cpu->eax != 0u) goto label_0008DD37;
    label_0008DD55:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008DD61;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008DD61:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax -= cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008DD6D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    if (cpu->ecx == 0u) goto label_0008DDA3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0008DDA3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008DDA3:
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DDB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ecx;
    if (*(uint32_t*)(cpu->esp + 0x10u) == cpu->esi) goto label_0008DE2E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    label_0008DDC0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    --cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if (cpu->edx!=0u) goto label_0008DDD1;
    cpu->edi=0u;
    goto label_0008DDD3;
    label_0008DDD1:
    cpu->edi = *(uint32_t*)(cpu->edx);
    label_0008DDD3:
    cpu->ebx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx = cpu->esi;
    cpu->edx >>= 2u;
    cpu->esi &= 3u;
    if (cpu->ebx > cpu->edx) goto label_0008DDE4;
    cpu->edx -= cpu->ebx;
    label_0008DDE4:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u));
    cpu->ebp = cpu->edx + (cpu->esi * 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    --cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    if (cpu->edx!=0u) goto label_0008DE02;
    cpu->ebx=0u;
    goto label_0008DE04;
    label_0008DE02:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    label_0008DE04:
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = cpu->esi;
    cpu->edx >>= 2u;
    cpu->esi &= 3u;
    if (cpu->edi > cpu->edx) goto label_0008DE15;
    cpu->edx -= cpu->edi;
    label_0008DE15:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->esi) goto label_0008DDC0;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008DE2E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx == 0u) goto label_0008DE4E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008DE58;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008DE4E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
    label_0008DE58:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DE70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if (cpu->edx == *(uint32_t*)(cpu->esp + 0x20u)) goto label_0008DEFB;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0008DE90:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->eax==0u) goto label_0008DE9A;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0008DE9A:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 2u;
    cpu->edx &= 3u;
    if (cpu->ecx > cpu->edi) goto label_0008DEAB;
    cpu->edi -= cpu->ecx;
    label_0008DEAB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->ecx!=0u) goto label_0008DEB7;
    cpu->ebp=0u;
    goto label_0008DEB9;
    label_0008DEB7:
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    label_0008DEB9:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->ebx;
    cpu->esi >>= 2u;
    cpu->ebx &= 3u;
    if (cpu->ecx > cpu->esi) goto label_0008DECA;
    cpu->esi -= cpu->ecx;
    label_0008DECA:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u));
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(uint32_t*)(cpu->eax + (cpu->ebx * 4u)) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x38u);
    ++cpu->edx;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if (cpu->edx != *(uint32_t*)(cpu->esp + 0x2Cu)) goto label_0008DE90;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0008DEFB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebx;
    if (cpu->ecx == 0u) goto label_0008DF1D;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0008DF1D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008DF1D:
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax == cpu->ecx) goto label_0008DFA2;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0008DF40:
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if (cpu->eax == cpu->ecx) goto label_0008DF9E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->ecx;
    cpu->esi >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edx > cpu->esi) goto label_0008DF5E;
    cpu->esi -= cpu->edx;
    label_0008DF5E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx = cpu->eax;
    cpu->edx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->ebx > cpu->edx) goto label_0008DF73;
    cpu->edx -= cpu->ebx;
    label_0008DF73:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->esi * 4u));
    cpu->ecx = cpu->esi + (cpu->ecx * 4u);
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi + (cpu->edx * 4u));
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_0008DF40;
    label_0008DF9E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008DFA2:
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->edi != *(uint32_t*)(cpu->edx + 0x10u)) goto label_0008E021;
    if (*(uint32_t*)(cpu->edx + 0x14u) < 0x10u) goto label_0008DFC7;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_0008DFC7:
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x14u);
    if (cpu->esi < 0x10u) goto label_0008DFD3;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    goto label_0008DFD5;
    label_0008DFD3:
    cpu->eax = cpu->ecx;
    label_0008DFD5:
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->esi < 0x10u) goto label_0008DFE4;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    goto label_0008DFE6;
    label_0008DFE4:
    cpu->esi = cpu->ecx;
    label_0008DFE6:
    if (cpu->esi == cpu->eax) goto label_0008E017;
    cpu->edi = native_function_address32(&::toupper);
    cpu->ebp = cpu->edx;
    cpu->ebp -= cpu->esi;
    label_0008DFF4:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->ebp));
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::toupper)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = (int8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::toupper)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 8u;
    if (*(uint32_t*)(cpu->esp + 0x10u) != cpu->eax) goto label_0008E021;
    ++cpu->esi;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0008DFF4;
    label_0008E017:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008E021:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E030(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->edi == 0xFFFFFFFFu) goto label_0008E089;
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008E089;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E04F;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E051;
    label_0008E04F:
    cpu->eax = cpu->esi;
    label_0008E051:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edi));
    cpu->eax = (((cpu->eax & 0xFFu) == 0x5Cu) || ((cpu->eax & 0xFFu) == 0x2Fu)) ? 0u : 0xFFFFFFFFu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0008E089;
    if (cpu->ebx == 0u) goto label_0008E081;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E07C;
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_0008E07C:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->edi));
    *(uint8_t*)(cpu->ebx) = cpu->edx & 0xFFu;
    label_0008E081:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008E089:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == 0u) goto label_0008E0B0;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008E0B0;
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_0008E0B0:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    if (cpu->edx == 0u) goto label_0008E0D9;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008E0D9;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E0D9:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx = 0xFFFFFFFu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx -= cpu->eax;
    if (cpu->ecx >= cpu->edi) goto label_0008E134;
    lift_push32(cpu, (uintptr_t)"deque<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E110u); throw std::length_error("std::length_error");
    label_0008E134:
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 1u;
    if (cpu->ecx >= 8u) goto label_0008E142;
    cpu->ecx = 8u;
    label_0008E142:
    if (cpu->edi >= cpu->ecx) goto label_0008E157;
    cpu->edx = 0xFFFFFFFu;
    cpu->edx -= cpu->ecx;
    if (cpu->eax > cpu->edx) goto label_0008E157;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->edi = cpu->ecx;
    label_0008E157:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x15u;
    cpu->ebp = cpu->ebp >> 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E16Au)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x48E16Au));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->eax;
    cpu->esi = cpu->ebp * 4u;
    cpu->eax = cpu->esi + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax -= *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E1A2u));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esp += 0xCu;
    if (cpu->ebp > cpu->edi) goto label_0008E1F3;
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->edx = cpu->esi;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E1C8u));
    cpu->edx = cpu->eax;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    if ((cpu->esi -= cpu->ebp) == 0u) goto label_0008E1E7;
    cpu->eax = 0u;
    std::memset((void*)(cpu->edx),0x00,(cpu->esi)*4u); cpu->ecx = 0u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_0008E1E7:
    if (cpu->ebp == 0u) goto label_0008E240;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp;
    goto label_0008E238;
    label_0008E1F3:
    cpu->ebp = cpu->edi * 4u;
    cpu->edx = cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E206u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->eax + cpu->ebp;
    cpu->esi -= cpu->ecx;
    cpu->esi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E224u));
    cpu->esp += 0x18u;
    cpu->edx = cpu->esi + cpu->eax;
    if (cpu->edi == 0u) goto label_0008E240;
    cpu->ecx = cpu->edi;
    cpu->edi = cpu->edx;
    label_0008E238:
    std::memset((void*)cpu->edi,0,cpu->ecx*4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_0008E240:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_0008E252;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E24Fu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x48E24Fu));
    cpu->esp += 4u;
    label_0008E252:
    *(uint32_t*)(cpu->ebx + 8u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 8u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->eax >= cpu->ecx) goto label_0008E28D;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E270u); throw std::out_of_range("std::out_of_range");
    label_0008E28D:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= cpu->ecx;
    if (cpu->eax >= cpu->ebx) goto label_0008E29A;
    cpu->ebx = cpu->eax;
    label_0008E29A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    if (cpu->ecx > cpu->ebx) goto label_0008E2B1;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E29Au); throw std::length_error("std::length_error");
    label_0008E2B1:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebx == 0u) goto label_0008E34E;
    cpu->edi = cpu->eax + cpu->ebx;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008E2CD;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E2B1u); throw std::length_error("std::length_error");
    label_0008E2CD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008E2F7;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E2DDu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48E2DDu));
    if (cpu->edi == 0u) goto label_0008E34E;
    label_0008E2E1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008E2ED;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008E2ED:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E31B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E31D;
    label_0008E2F7:
    if (cpu->edi != 0u) goto label_0008E2E1;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008E310;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E310:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E31B:
    cpu->eax = cpu->esi;
    label_0008E31D:
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48E329u));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008E348;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E348:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008E34E:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E360(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp == 0u) goto label_0008E3C5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_0008E378;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E37A;
    label_0008E378:
    cpu->eax = cpu->esi;
    label_0008E37A:
    if (cpu->ebp < cpu->eax) goto label_0008E3C5;
    if (cpu->ecx < 0x10u) goto label_0008E387;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E389;
    label_0008E387:
    cpu->eax = cpu->esi;
    label_0008E389:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx += cpu->eax;
    if (cpu->edx <= cpu->ebp) goto label_0008E3C5;
    if (cpu->ecx < 0x10u) goto label_0008E3AE;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E3A9u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x48E3A9u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E3AE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E3C0u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x48E3C0u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E3C5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx -= cpu->eax;
    if (cpu->edx > cpu->ebx) goto label_0008E3E1;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E3C5u); throw std::length_error("std::length_error");
    label_0008E3E1:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebx == 0u) goto label_0008E471;
    cpu->edi = cpu->eax + cpu->ebx;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008E3FD;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E3E1u); throw std::length_error("std::length_error");
    label_0008E3FD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008E41B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E40Du)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48E40Du));
    if (cpu->edi == 0u) goto label_0008E471;
    label_0008E411:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E441;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E443;
    label_0008E41B:
    if (cpu->edi != 0u) goto label_0008E411;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008E435;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E435:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E441:
    cpu->eax = cpu->esi;
    label_0008E443:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48E44Bu));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008E46B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E46B:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008E471:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E480(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax >= cpu->ebx) goto label_0008E49A;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E480u); throw std::out_of_range("std::out_of_range");
    label_0008E49A:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx -= cpu->eax;
    if (cpu->ecx > cpu->ebp) goto label_0008E4B3;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E49Au); throw std::length_error("std::length_error");
    label_0008E4B3:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebp == 0u) goto label_0008E569;
    cpu->edi = cpu->eax + cpu->ebp;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008E4CF;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E4B3u); throw std::length_error("std::length_error");
    label_0008E4CF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008E4F3;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E4DFu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48E4DFu));
    if (cpu->edi == 0u) goto label_0008E569;
    label_0008E4E7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax < 0x10u) goto label_0008E519;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_0008E51B;
    label_0008E4F3:
    if (cpu->edi != 0u) goto label_0008E4E7;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008E50D;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E50D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E519:
    cpu->ecx = cpu->esi;
    label_0008E51B:
    if (cpu->eax < 0x10u) goto label_0008E524;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E526;
    label_0008E524:
    cpu->eax = cpu->esi;
    label_0008E526:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx -= cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebx;
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E534u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E54Bu)); sfera_sub_0048DBA0(cpu, LIFT_CODE_TOKEN_VA(0x48E54Bu));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008E563;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E563:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008E569:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E580(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E5AB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E5AB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E5AB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E5D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E5D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E5D2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E5F9;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E5F9;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E5F9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E607u)); sfera_sub_0048DDB0(cpu, LIFT_CODE_TOKEN_VA(0x48E607u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E610(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E63B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E63B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E63B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E662;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E662;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E662:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E689;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E689;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E689:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E697u)); sfera_sub_0048DE70(cpu, LIFT_CODE_TOKEN_VA(0x48E697u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    if ((((cpu->ecx & 0xFFu)) & (3u)) != 0u) goto label_0008E6C9;
    cpu->eax += 4u;
    cpu->eax >>= 2u;
    if (*(uint32_t*)(cpu->esi + 8u) > cpu->eax) goto label_0008E6C9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8E6C9u)); sfera_sub_0048E110(cpu, LIFT_CODE_TOKEN_RVA(0x8E6C9u));
    label_0008E6C9:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ebx += *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = cpu->ebx;
    cpu->edi >>= 2u;
    if (cpu->eax > cpu->edi) goto label_0008E6DD;
    cpu->edi -= cpu->eax;
    label_0008E6DD:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->edx + (cpu->edi * 4u)) != 0u) goto label_0008E6FA;
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E6EDu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x48E6EDu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0008E71E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) = cpu->eax;
    label_0008E6FA:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    cpu->ebx &= 3u;
    cpu->eax = cpu->edx + (cpu->ebx * 4u);
    if (cpu->eax == 0u) goto label_0008E712;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E712:
    ++*(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008E71E:
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E74Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x48E74Cu));
    cpu->eip = 0x48E74Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0048E750(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_test[0]=(*(uint8_t*)(cpu->esi + 0xCu)&3u)==0u;
    lift_push32(cpu, cpu->edi);
    if (!lift_test[0]) goto label_0008E773;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax += 4u;
    cpu->eax >>= 2u;
    if (*(uint32_t*)(cpu->esi + 8u) > cpu->eax) goto label_0008E773;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8E773u)); sfera_sub_0048E110(cpu, LIFT_CODE_TOKEN_RVA(0x8E773u));
    label_0008E773:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->ebx!=0u) goto label_0008E781;
    cpu->ebx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebx += cpu->ebx;
    cpu->ebx += cpu->ebx;
    label_0008E781:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    --cpu->ebx;
    cpu->edi = cpu->ebx;
    cpu->edi >>= 2u;
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) != 0u) goto label_0008E7A4;
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E797u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x48E797u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0008E7CD;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->edi * 4u)) = cpu->eax;
    label_0008E7A4:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->eax = cpu->ebx;
    cpu->eax &= 3u;
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    if (cpu->eax == 0u) goto label_0008E7BE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E7BE:
    ++*(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008E7CD:
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E7FBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x48E7FBu));
    cpu->eip = 0x48E7FBu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0048E800(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x3Cu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->esi;
    cpu->ebx = cpu->edi;
    cpu->ebx -= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->esi <= cpu->edi) goto label_0008E82D;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    label_0008E82D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx == 0u) goto label_0008E844;
    label_0008E835:
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edx;
    if (cpu->edx != 0u) goto label_0008E835;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_0008E844:
    if ((int32_t)cpu->eax >= (int32_t)cpu->ebx) goto label_0008E944;
    if ((int32_t)cpu->eax <= 0) goto label_0008E944;
    goto label_0008E859;
    label_0008E856:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x1Cu);
    label_0008E859:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    cpu->esi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ebx = cpu->esi;
    if (cpu->eax != cpu->edi) goto label_0008E87B;
    cpu->eax = cpu->ebp + 8u;
    goto label_0008E88B;
    label_0008E87B:
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->eax = cpu->esp + 0x28u;
    label_0008E88B:
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    label_0008E890:
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    cpu->esi >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->esi) goto label_0008E8A3;
    cpu->esi -= cpu->edx;
    label_0008E8A3:
    cpu->edx = cpu->ebx;
    cpu->ebx&=3u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx >>= 2u;
    if (cpu->ebx > cpu->edx) goto label_0008E8BC;
    cpu->edx -= cpu->ebx;
    label_0008E8BC:
    cpu->ebx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->esi * 4u));
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->eax * 4u));
    cpu->esi = cpu->esi + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->edx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    cpu->ebx = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) >= (int32_t)cpu->edx) goto label_0008E909;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    cpu->eax = cpu->esp + 0x30u;
    goto label_0008E924;
    label_0008E909:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->edx;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    cpu->eax = cpu->esp + 0x38u;
    label_0008E924:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x44u)) goto label_0008E890;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax > 0) goto label_0008E856;
    label_0008E944:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0048EAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    if (*(uint32_t*)(cpu->ecx + 0x10u) > cpu->eax) goto label_0008EAD7;
    lift_push32(cpu, (uintptr_t)"invalid deque<T> subscript");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EAC0u); throw std::out_of_range("std::out_of_range");
    label_0008EAD7:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EAE8u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48EAE8u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EAEFu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48EAEFu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_0008EAF9;
    cpu->esi=0u;
    goto label_0008EAFB;
    label_0008EAF9:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008EAFB:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008EB0F;
    cpu->ecx -= cpu->edx;
    label_0008EB0F:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB38u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48EB38u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB3Fu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48EB3Fu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_0008EB49;
    cpu->esi=0u;
    goto label_0008EB4B;
    label_0008EB49:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008EB4B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008EB5F;
    cpu->ecx -= cpu->edx;
    label_0008EB5F:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB85u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48EB85u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB8Cu)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x48EB8Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_0008EB96;
    cpu->esi=0u;
    goto label_0008EB98;
    label_0008EB96:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008EB98:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008EBAC;
    cpu->ecx -= cpu->edx;
    label_0008EBAC:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EBC0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->ebx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008EBEB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008EBEB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008EBEB:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EBFEu)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x48EBFEu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008EC1E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008EC1E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008EC1E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EC31u)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x48EC31u));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EC3Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48EC3Du));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ebp = cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EC60u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48EC60u));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax -= cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi < cpu->eax);
    cpu->esp -= 0xCu;
    sub_pred[0] = (uint8_t)(cpu->eax) == (uint8_t)(cpu->ebx);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    if (sub_pred[0]) goto label_0008ED14;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ecx == cpu->ebx) goto label_0008EC96;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008EC96;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008EC96:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008ECBD;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008ECBD;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008ECBD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ECD5u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48ECD5u));
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ECDEu)); sfera_sub_0048E580(cpu, LIFT_CODE_TOKEN_VA(0x48ECDEu));
    if (cpu->ebp <= cpu->ebx) goto label_0008ED85;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    label_0008ECF0:
    if (cpu->ecx == cpu->ebx) goto label_0008ED0C;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    ++*(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    if (cpu->edx > *(uint32_t*)(cpu->esi + 0xCu)) goto label_0008ED06;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0008ED06:
    if ((--cpu->ecx) != 0u) goto label_0008ED0C;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0008ED0C:
    if ((--cpu->ebp) != 0u) goto label_0008ECF0;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    goto label_0008ED85;
    label_0008ED14:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->ecx == cpu->ebx) goto label_0008ED26;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008ED26;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008ED26:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED3Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48ED3Eu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008ED5E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008ED5E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008ED5E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED6Eu)); sfera_sub_0048E610(cpu, LIFT_CODE_TOKEN_VA(0x48ED6Eu));
    if (cpu->ebp <= cpu->ebx) goto label_0008ED85;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    label_0008ED75:
    if (cpu->eax == cpu->ebx) goto label_0008ED7F;
    if ((--cpu->eax) != 0u) goto label_0008ED7F;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0008ED7F:
    if ((--cpu->ebp) != 0u) goto label_0008ED75;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    label_0008ED85:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED97u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48ED97u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED9Eu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48ED9Eu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EDB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    if (cpu->ecx > cpu->ebx) goto label_0008EDCF;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EDB0u); throw std::length_error("std::length_error");
    label_0008EDCF:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebx == 0u) goto label_0008EE4D;
    cpu->edi = cpu->eax + cpu->ebx;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008EDE7;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EDCFu); throw std::length_error("std::length_error");
    label_0008EDE7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008EE23;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EDF7u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48EDF7u));
    if (cpu->edi == 0u) goto label_0008EE4D;
    label_0008EDFB:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EE0Cu)); sfera_sub_0048DBA0(cpu, LIFT_CODE_TOKEN_VA(0x48EE0Cu));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008EE47;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EE23:
    if (cpu->edi != 0u) goto label_0008EDFB;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008EE3C;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EE3C:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EE47:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008EE4D:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EE60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->ecx < cpu->ebp) goto label_0008EFD1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax < cpu->edx) goto label_0008EFD1;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->edx;
    if (cpu->eax >= cpu->edi) goto label_0008EE93;
    cpu->edi = cpu->eax;
    label_0008EE93:
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx > cpu->edi) goto label_0008EEA7;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EE93u); throw std::length_error("std::length_error");
    label_0008EEA7:
    lift_push32(cpu, cpu->ebx);
    if (cpu->edi == 0u) goto label_0008EFC8;
    cpu->ebx = cpu->ecx + cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ebx <= 0xFFFFFFFEu) goto label_0008EEC7;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EEA7u); throw std::length_error("std::length_error");
    label_0008EEC7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->ebx) goto label_0008EEEB;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EED7u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48EED7u));
    if (cpu->ebx == 0u) goto label_0008EFC8;
    label_0008EEDF:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax < 0x10u) goto label_0008EF10;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_0008EF12;
    label_0008EEEB:
    if (cpu->ebx != 0u) goto label_0008EEDF;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    if (cpu->eax < 0x10u) goto label_0008EF04;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax) = cpu->ebx & 0xFFu;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EF04:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EF10:
    cpu->ecx = cpu->esi;
    label_0008EF12:
    if (cpu->eax < 0x10u) goto label_0008EF1B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008EF1D;
    label_0008EF1B:
    cpu->eax = cpu->esi;
    label_0008EF1D:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebx = native_function_address32(&::memmove);
    cpu->edx -= cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::memmove)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    if (cpu->esi != cpu->ecx) goto label_0008EF7F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ebp >= cpu->edx) goto label_0008EF48;
    cpu->edx += cpu->edi;
    label_0008EF48:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax < 0x10u) goto label_0008EF54;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_0008EF56;
    label_0008EF54:
    cpu->ecx = cpu->esi;
    label_0008EF56:
    if (cpu->eax < 0x10u) goto label_0008EF6D;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::memmove)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    cpu->ebx = 0x10u;
    goto label_0008EFA4;
    label_0008EF6D:
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->edx;
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::memmove)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    cpu->ebx = 0x10u;
    goto label_0008EFA4;
    label_0008EF7F:
    cpu->ebx = 0x10u;
    if (*(uint32_t*)(cpu->ecx + 0x14u) < cpu->ebx) goto label_0008EF8B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008EF8B:
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->ebx) goto label_0008EF94;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008EF96;
    label_0008EF94:
    cpu->eax = cpu->esi;
    label_0008EF96:
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48EF9Fu));
    label_0008EFA4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->ebx) goto label_0008EFC2;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + cpu->ecx) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EFC2:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->ecx) = 0u;
    label_0008EFC8:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EFD1:
    lift_push32(cpu, (uintptr_t)"invalid string position");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EFD1u); throw std::out_of_range("std::out_of_range");
}

__declspec(noinline) void sfera_sub_0048F090(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    lift_push32(cpu, 1u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F0AAu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F0AAu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == 0u) goto label_0008F0D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0008F0D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008F0D2:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F0E5u)); sfera_sub_0048EBC0(cpu, LIFT_CODE_TOKEN_VA(0x48F0E5u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F0F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_0008F17B;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ebx == cpu->ebp) goto label_0008F17B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_0008F11E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F11E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F122;
    label_0008F11E:
    cpu->edx = 0u;
    goto label_0008F124;
    label_0008F122:
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_0008F124:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_0008F138;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F138;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F13C;
    label_0008F138:
    cpu->ecx = 0u;
    goto label_0008F13E;
    label_0008F13C:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F13E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_0008F152;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F152;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F156;
    label_0008F152:
    cpu->eax = 0u;
    goto label_0008F158;
    label_0008F156:
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0008F158:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F167u)); sfera_sub_0048E800(cpu, LIFT_CODE_TOKEN_VA(0x48F167u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_0008F17B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    if (cpu->eax == 0u) goto label_0008F19D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F19D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    label_0008F19D:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F1B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edi;
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F1E9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F1E9u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_0008F400;
    cpu->ecx >>= 1u;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) > cpu->ecx) goto label_0008F348;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    label_0008F220:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_0008F27D;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx!=0u) goto label_0008F230;
    cpu->esi=0u;
    goto label_0008F232;
    label_0008F230:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008F232:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008F243;
    cpu->ecx -= cpu->edx;
    label_0008F243:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F254u)); sfera_sub_0048E750(cpu, LIFT_CODE_TOKEN_VA(0x48F254u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->eax;
    goto label_0008F220;
    label_0008F27D:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F292u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F292u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F299u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F299u));
    cpu->edx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F2A4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F2A4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    if (cpu->eax == 0u) goto label_0008F2BB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F2BB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F2BF;
    label_0008F2BB:
    cpu->ecx = 0u;
    goto label_0008F2C1;
    label_0008F2BF:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F2C1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_0008F2D9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F2D9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F2DD;
    label_0008F2D9:
    cpu->ecx = 0u;
    goto label_0008F2DF;
    label_0008F2DD:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F2DF:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F2E9u)); sfera_sub_0048DF30(cpu, LIFT_CODE_TOKEN_VA(0x48F2E9u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F306u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F306u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F30Du)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F30Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F314u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F314u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F329u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F329u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F330u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F330u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F340u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F340u));
    cpu->ecx = cpu->ebp + 0xFFFFFFA8u;
    goto label_0008F3FB;
    label_0008F348:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    (void)cpu;
    label_0008F350:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_0008F3AD;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx!=0u) goto label_0008F360;
    cpu->esi=0u;
    goto label_0008F362;
    label_0008F360:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008F362:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008F373;
    cpu->ecx -= cpu->edx;
    label_0008F373:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F384u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x48F384u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->eax;
    goto label_0008F350;
    label_0008F3AD:
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3BDu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48F3BDu));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFA8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3D2u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F3D2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3D9u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F3D9u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3F1u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F3F1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3F8u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F3F8u));
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    label_0008F3FB:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8F400u)); sfera_sub_0048F0F0(cpu, LIFT_CODE_TOKEN_RVA(0x8F400u));
    label_0008F400:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0048F7E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esp;
    if (cpu->edx == 0u) goto label_0008F80E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008F80E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008F80E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->edx == 0u) goto label_0008F83D;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008F83D;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008F83D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->edx == 0u) goto label_0008F86C;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008F86C;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008F86C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F878u)); sfera_sub_0048F1B0(cpu, LIFT_CODE_TOKEN_VA(0x48F878u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}




__declspec(noinline) void sfera_sub_0048FF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FF51u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48FF51u));
    cpu->esp -= 0xCu;
    cpu->edi = 0u;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->edx == cpu->edi) goto label_0008FF71;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->edi) goto label_0008FF71;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0008FF71:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FF83u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48FF83u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->edx == cpu->edi) goto label_0008FFA1;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->edi) goto label_0008FFA1;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0008FFA1:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FFB3u)); sfera_sub_0048EBC0(cpu, LIFT_CODE_TOKEN_VA(0x48FFB3u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->ecx == cpu->edi) goto label_0008FFD3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edi) goto label_0008FFD3;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008FFD3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edi) goto label_0008FFFA;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edi) goto label_0008FFFA;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008FFFA:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->edx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49000Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x49000Du));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->edx == cpu->edi) goto label_0009002B;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->edi) goto label_0009002B;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0009002B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490038u)); sfera_sub_0048F7E0(cpu, LIFT_CODE_TOKEN_VA(0x490038u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490190(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4901AAu)); sfera_sub_0048E480(cpu, LIFT_CODE_TOKEN_VA(0x4901AAu));
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4901C3u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4901C3u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004901D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->edx + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    if (cpu->edi <= cpu->ebp) goto label_00090208;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->ebp -= cpu->edi;
    if (cpu->ebp < cpu->eax) goto label_00090208;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490206u)); sfera_sub_0048EE60(cpu, LIFT_CODE_TOKEN_VA(0x490206u));
    goto label_00090214;
    label_00090208:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x90214u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_RVA(0x90214u));
    label_00090214:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49022Du)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x49022Du));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49025Au)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x49025Au));
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490273u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x490273u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490350(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esp;
    if (cpu->edx == 0u) goto label_0009037E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0009037E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0009037E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->edx == 0u) goto label_000903AD;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000903AD;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000903AD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4903B9u)); sfera_sub_0048FF40(cpu, LIFT_CODE_TOKEN_VA(0x4903B9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004903C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    cpu->ebp = cpu->eax + 1u;
    label_000903D7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000903D7;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4903E9u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4903E9u));
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490402u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x490402u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}













} // namespace lifted
