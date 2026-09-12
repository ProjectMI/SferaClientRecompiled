#include "lifted_functions.h"
#include <cmath>
namespace lifted {






















__declspec(noinline) void sfera_sub_004974B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->esi + 0x10u) == cpu->ebx) goto label_000974D8;
    cpu->edx = cpu->ebx + 0x48u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4974C9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4974C9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4974D2u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4974D2u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    label_000974D8:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebp -= *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    cpu->ebp = (int32_t)(cpu->ebp) >> 2u;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_0009752D;
    label_000974F0:
    cpu->edx = 0x4Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4974FFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4974FFu));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u));
    if (cpu->eax == 0u) goto label_00097528;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = cpu->eax + 0xFFFFFFFCu;
    { uint32_t current = cpu->eax + 0xC0u * cpu->edx; uint32_t count = cpu->edx; while (count-- != 0u) { current -= 0xC0u; cpu->ecx = current; SferaAbi::pointer<CSoundEffect>(cpu->ecx)->destroy(); } }
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497525u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x497525u));
    cpu->esp += 4u;
    label_00097528:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_000974F0;
    label_0009752D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->ebp = lift_pop32(cpu);
    if (cpu->edi == cpu->ecx) goto label_00097556;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ebx = cpu->eax * 4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x497548u));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    label_00097556:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}






__declspec(noinline) void sfera_sub_004980F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&SI_SetLogFile), LIFT_CODE_TOKEN_VA(0x4980F5u));
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xAC44u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&SI_CreateInterface), LIFT_CODE_TOKEN_VA(0x49810Au));
    cpu->esp += 0x14u;
    if (cpu->eax == 0u) goto label_000981E1;
    lift_push32(cpu, cpu->edi);
    cpu->eax = SferaAbi::address(g_sfera_sound_runtime.ensureManager());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00098160;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x498127u));
    if (cpu->eax != 0u) goto label_00098159;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0u) goto label_00098148;
    label_00098138:
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop();
    cpu->esi = *(uint32_t*)(cpu->esi + 0x70u);
    if (cpu->esi != 0u) goto label_00098138;
    label_00098148:
    cpu->ecx = cpu->edi;
    SferaAbi::pointer<CSoundManager>(cpu->ecx)->clear();
    *(uint32_t*)(cpu->edi + 0xCu) = 0u;
    cpu->esi = lift_pop32(cpu);
    goto label_00098160;
    label_00098159:
    *(uint32_t*)(cpu->edi + 0xCu) = 1u;
    label_00098160:
    cpu->eax = 0x64u;
    cpu->ecx = (uintptr_t)"config.cfg";
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49817Fu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x49817Fu));
    cpu->edx = cpu->esp + 0xCu;
    cpu->ecx = (uintptr_t)"SNDVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49818Du)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x49818Du));
    cpu->edx = cpu->esp + 8u;
    cpu->ecx = (uintptr_t)"MUSVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49819Bu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x49819Bu));
    cpu->edx = cpu->esp + 4u;
    cpu->ecx = (uintptr_t)"HWMIX";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4981A9u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4981A9u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp + 4u) != 0u);
    cpu->edx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&SI_SetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4981B5u));
    cpu->esp += 4u;
    g_sfera_sound_runtime.loadDefinitions();
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = static_cast<std::uint32_t>((SI_SetStreamVolume(static_cast<std::int32_t>(cpu->ecx)), 1u));
    cpu->ecx = g_sfera_sound_runtime.manager;
    cpu->edi = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_000981E1;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    SferaAbi::pointer<CSoundManager>(cpu->ecx)->setVolume(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)));  cpu->esp += 4u;
    label_000981E1:
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}















































__declspec(noinline) void sfera_sub_0049A730(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4;
 bool sub_pred[1]; double x87_p0, x87_p1, x87_p2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x34u;
    sub_pred[0] = (uint32_t)(g_sfera_profiler_runtime.frame_count) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_0009A883;
    if (g_sfera_profiler_runtime.frame_time_total == 0u) goto label_0009A883;
    lift_push32(cpu, (uintptr_t)"a"); lift_push32(cpu, (uintptr_t)"logs\\profile.txt");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49A760u));
    cpu->ebx = native_function_address32(&::fprintf);
    cpu->edi = cpu->eax;
    lift_push32(cpu, (uintptr_t)"\n\nProfile results:\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A774u));
    x87_p0 = (double)(((int32_t)(g_sfera_profiler_runtime.frame_time_total)));
    cpu->eax = g_sfera_profiler_runtime.frame_time_total;
    cpu->esp += 0x10u;
     value_1 = x87_p0; if ((int32_t)cpu->eax >= 0) { value_0 = value_1; goto label_0009A78E; }
    value_2 = (value_1) + (((double)4294967296.0f)); value_0 = value_2;
label_0009A78E:
    value_3 = (value_0) / ((double)(((int32_t)(g_sfera_profiler_runtime.frame_count))));
    *(float*)(cpu->esp + 0x34u) = value_3; 
    { const auto result = WorldClock::microseconds(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    value_4 = (double)*(float*)(cpu->esp + 0x34u);
    g_sfera_profiler_runtime.report_clock_snapshot.low = cpu->eax;
    g_sfera_profiler_runtime.report_clock_snapshot.high = cpu->edx;
    *(uint64_t*)(cpu->esp + 0x38u) = static_cast<int64_t>(std::trunc(value_4));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = g_sfera_profiler_runtime.report_clock_snapshot.low;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ecx); cpu->eax = n / d; cpu->edx = n % d; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Average frame time = %d  (fps = %d)\n\n"); lift_push32(cpu, cpu->edi);
     lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A7DFu));
    cpu->esp += 0x10u;
    cpu->esi = 0u;
label_0009A7F0:
    cpu->eax = g_sfera_profiler_runtime.call_count[cpu->esi];
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0009A86F;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009A812;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"N=%d,  ERROR\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A80Bu));
    cpu->esp += 0xCu;
    goto label_0009A86F;
label_0009A812:
    x87_p0 = (double)(((int32_t)(g_sfera_profiler_runtime.frame_count)));
    cpu->esp -= 0x18u;
    *(float*)(cpu->esp + 0x50u) = x87_p0; 
    x87_p0 = (double)(((int64_t)(*(uint64_t*)((uintptr_t)&g_sfera_profiler_runtime.accumulated_ticks[cpu->esi]))));
    x87_p1 = (double)*(float*)(cpu->esp + 0x50u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 / x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x50u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x50u); x87_p2 = x87_p1;
    x87_p2 = (x87_p2) / (((double)*(float*)(cpu->esp + 0x4Cu)));
    x87_p2 = (x87_p2) * (100.0);
    *(float*)(cpu->esp + 0x50u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x50u);
    *(double*)(cpu->esp + 0x10u) = x87_p2;
    *(double*)(cpu->esp + 8u) = x87_p1;
    x87_p0 = ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x48u))))) / (x87_p0);
    *(float*)(cpu->esp + 0x50u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x50u);
    *(double*)(cpu->esp) = x87_p0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"N=%d,  ANoC = %5.2f,  AT = %7.1f,  AP = %5.2f\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A86Au));
    cpu->esp += 0x24u;
label_0009A86F:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x64u) goto label_0009A7F0;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49A87Au));
    cpu->esp += 4u;
label_0009A883:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    *(uint8_t*)(cpu->eax) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint8_t*)(cpu->eax + 1u) = 1u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x124u) = 1u;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->eax + 0x434u) = cpu->ebx;
    cpu->esi = cpu->eax + 0x10u;
    *(uint32_t*)(cpu->eax + 0x638u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x63Cu) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x640u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x644u) = cpu->ebx;
    cpu->esi -= cpu->ecx;
    label_0009A997:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0009A997;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A9B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x638u);
    if ((int32_t)cpu->eax <= 0) goto label_0009A9F5;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x63Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A9D0u)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x49A9D0u));
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x638u);
    cpu->edi = cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A9E4u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x49A9E4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x434u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009A9F5:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edx) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x434u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x198u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0009B0EB;
    cpu->eax = 3u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009B0EB:
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x202u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x49B0F5u));
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009B11C;
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009B11C:
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->esi + 0x10u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x49B126u));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == 0u) goto label_0009B13B;
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x49B134u));
    goto label_0009B152;
    label_0009B13B:
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x49B13Bu));
    lift_push32(cpu, 2u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::gethostbyaddr), LIFT_CODE_TOKEN_VA(0x49B14Du));
    label_0009B152:
    cpu->ebp = cpu->eax;
    if (cpu->ebp != 0u) goto label_0009B165;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B158u));
    cpu->eax = cpu->ebp + 5u;
    goto label_0009B28E;
    label_0009B165:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x110u) = cpu->eax;
    cpu->edi = cpu->esi + 0x110u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->ebp + 0xAu));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x114u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B18Eu));
    cpu->eax = *(uint16_t*)(cpu->esi + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->ebp + 8u));
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x49B1A2u));
    lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    *(uint16_t*)(cpu->esi + 0x112u) = cpu->eax & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x49B1B4u));
    cpu->ecx = cpu->esi + 0x124u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x8004667Eu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x120u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::ioctlsocket), LIFT_CODE_TOKEN_VA(0x49B1CCu));
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009B1E5;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B1D6u));
    cpu->eax = 4u;
    goto label_0009B28E;
    label_0009B1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x120u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::connect), LIFT_CODE_TOKEN_VA(0x49B1EFu));
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009B211;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x49B1F9u));
    if (cpu->eax == 0x2733u) goto label_0009B211;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B205u));
    cpu->eax = 6u;
    goto label_0009B28E;
    label_0009B211:
    cpu->eax = cpu->esi + 8u;
    *(uint8_t*)(cpu->esi) = 0u;
    *(uint8_t*)(cpu->esi + 1u) = 0u;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_update_download_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->esi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->eax)))));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009B241;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B235u));
    cpu->eax = 2u;
    goto label_0009B28E;
    label_0009B241:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1A8u);
    cpu->edx = cpu->esi + 0x438u;
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_0009B262;
    ++cpu->eax;
    cpu->edx -= cpu->eax;
    label_0009B256:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B256;
    goto label_0009B26E;
    label_0009B262:
    cpu->edx -= cpu->eax;
    label_0009B264:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B264;
    label_0009B26E:
    *(uint32_t*)(cpu->esi + 0x434u) = 1u;
    *(uint32_t*)(cpu->esi + 0x638u) = 0u;
    *(uint32_t*)(cpu->esi + 0x63Cu) = 0u;
    cpu->eax = 0u;
    label_0009B28E:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    cpu->eax = 0x6E726157u;
    cpu->edx = 0x6C2E3030u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x676F)) & 0xFFFFu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = 0x73676E69u;
    *(uint16_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint8_t*)(cpu->esp + 0x1Au) = cpu->ecx & 0xFFu;
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + 0x30u;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = cpu->esp + 0xCu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esp + 0x1Du) = cpu->ecx & 0xFFu;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49B334u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebx == 0u) goto label_0009B45C;
    if (cpu->esi < 0xAu) goto label_0009B358;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B358u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B358u));
    label_0009B358:
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x850u);
    cpu->edi += cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x448u) != 1u) goto label_0009B3C4;
    if (cpu->esi < 0xAu) goto label_0009B3A0;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B37Cu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B37Cu));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B388u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B388u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B394u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B394u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B3A0u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B3A0u));
    label_0009B3A0:
    cpu->edx = cpu->edi + 0x44Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%s %s\n%s\n%s\n\n"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x49B3B9u));
    cpu->esp += 0x18u;
    goto label_0009B42E;
    label_0009B3C4:
    if (cpu->esi < 0xAu) goto label_0009B405;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3D5u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3D5u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3E1u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3E1u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3EDu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3EDu));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3F9u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3F9u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B405u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B405u));
    label_0009B405:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x448u);
    cpu->eax = cpu->edi + 0x44Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x48u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%s %s\n(%d) %s\n%s\n\n"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x49B425u));
    cpu->esp += 0x1Cu;
    label_0009B42E:
    if (cpu->esi < 0xAu) goto label_0009B43F;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B43Fu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B43Fu));
    label_0009B43F:
    if (*(uint32_t*)(cpu->edi + 0x84Cu) != 1u) goto label_0009B452;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x49B449u));
    cpu->esp += 4u;
    label_0009B452:
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49B453u));
    cpu->esp += 4u;
    label_0009B45C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B470(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx;
    sub_pred[0] = cpu->esi < 0xAu;
    label_0009B47C:
    if (sub_pred[0]) goto label_0009B48A;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B48Au)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B48Au));
    label_0009B48A:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->eax|=*(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax==0u) goto label_0009B4B7;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B499u)); sfera_sub_0049B2B0(cpu, LIFT_CODE_TOKEN_VA(0x49B499u));
    if (cpu->esi < 0xAu) goto label_0009B4AA;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B4AAu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B4AAu));
    label_0009B4AA:
    *(uint32_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    label_0009B4B7:
    ++cpu->esi;
    cpu->edi += 0x850u;
    sub_pred[0] = cpu->esi < 0xAu;
    if ((int32_t)(cpu->esi) < (int32_t)(0xAu)) goto label_0009B47C;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B4D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi;
    sub_pred[0] = cpu->ebp < 0xAu;
    label_0009B4E6:
    if (sub_pred[0]) goto label_0009B4F4;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B4F4u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B4F4u));
    label_0009B4F4:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->eax|=*(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax==0u) goto label_0009B51E;
    if (cpu->ebp < 0xAu) goto label_0009B50C;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B50Cu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B50Cu));
    label_0009B50C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->edi + 0x48u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->ecx, cpu->eax);

    if (cpu->eax == 0u) goto label_0009B52C;
    label_0009B51E:
    ++cpu->ebp;
    cpu->edi += 0x850u;
    sub_pred[0] = cpu->ebp < 0xAu;
    if ((int32_t)(cpu->ebp) < (int32_t)(0xAu)) goto label_0009B4E6;
    goto label_0009B572;
    label_0009B52C:
    if (cpu->ebp < 0xAu) goto label_0009B53D;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B53Du)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B53Du));
    label_0009B53D:
    cpu->edi = cpu->ebp;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x850u);
    ++*(uint32_t*)(cpu->edi + cpu->esi + 0x448u);
    cpu->edi += cpu->esi;
    if (cpu->ebp < 0xAu) goto label_0009B55F;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B55Fu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B55Fu));
    label_0009B55F:
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    if ((int32_t)cpu->ebp < (int32_t)0xAu) goto label_0009B779;
    label_0009B572:
    cpu->edi = 0u;
    cpu->ebx = cpu->esi;
    sub_pred[1] = cpu->edi < 0xAu;
    label_0009B579:
    if (sub_pred[1]) goto label_0009B587;
    cpu->edx = cpu->edi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B587u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B587u));
    label_0009B587:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->eax|=*(uint32_t*)(cpu->ebx + 4u);
    if (cpu->eax==0u) goto label_0009B59A;
    ++cpu->edi;
    cpu->ebx += 0x850u;
    sub_pred[1] = cpu->edi < 0xAu;
    if ((int32_t)(cpu->edi) < (int32_t)(0xAu)) goto label_0009B579;
    label_0009B59A:
    sub_pred[2] = cpu->ebp < 0xAu;
    if (cpu->ebp != 0xAu) goto label_0009B5C5;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B5A8u)); sfera_sub_0049B2B0(cpu, LIFT_CODE_TOKEN_VA(0x49B5A8u));
    lift_push32(cpu, 0x4AD0u);
    cpu->ecx = cpu->esi + 0x850u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49B5B5u));
    cpu->esp += 0xCu;
    cpu->ebp = 9u;
    goto label_0009B5D3;
    label_0009B5C5:
    if (sub_pred[2]) goto label_0009B5D3;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B5D3u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B5D3u));
    label_0009B5D3:
    cpu->ebx = cpu->ebp;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x850u);
    cpu->ebx += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->edi = 1u;
    cpu->eax += cpu->edi;
    cpu->edx += (cpu->eax < cpu->edi);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    if (cpu->ebp < 0xAu) goto label_0009B604;
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->edi + 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B604u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B604u));
    label_0009B604:
    *(uint32_t*)(cpu->ebx + 0x448u) = cpu->edi;
    if (cpu->ebp < 0xAu) goto label_0009B61B;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B61Bu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B61Bu));
    label_0009B61B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->ebx + 0x84Cu) = cpu->eax;
    if (cpu->ebp < 0xAu) goto label_0009B636;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B636u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B636u));
    label_0009B636:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0009B640:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B640;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0x400u) goto label_0009B68A;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x20u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h";
    *(uint32_t*)(cpu->esp + 0x24u) = 0x6Du;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B674u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49B674u));
    cpu->edi = cpu->ebx + 0x48u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),1023u); cpu->esi += 1023u; cpu->edi += 1023u; cpu->ecx = 0u;
    *(uint8_t*)(cpu->ebx + 0x447u) = 0u;
    goto label_0009B696;
    label_0009B68A:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebx + 0x48u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B691u));
    label_0009B696:
    cpu->esp += 0xCu;
    if (cpu->ebp < 0xAu) goto label_0009B6AA;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B6AAu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B6AAu));
    label_0009B6AA:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->ebx += 0x44Cu;
    *(uint8_t*)(cpu->ebx) = cpu->edx & 0xFFu;
    cpu->eax = SferaAbi::address(WorldDiagnostics::scriptContext());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_0009B739;
    if (cpu->ebp < 0xAu) goto label_0009B6D4;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B6D4u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B6D4u));
    label_0009B6D4:
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_0009B6E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B6E0;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0x400u) goto label_0009B72D;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h";
    *(uint32_t*)(cpu->esp + 0x24u) = 0x6Du;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B718u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49B718u));
    cpu->edi = cpu->ebx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),1023u); cpu->esi += 1023u; cpu->edi += 1023u; cpu->ecx = 0u;
    *(uint8_t*)(cpu->ebx + 0x3FFu) = 0u;
    goto label_0009B736;
    label_0009B72D:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B731u));
    label_0009B736:
    cpu->esp += 0xCu;
    label_0009B739:
    if (cpu->ebp < 0xAu) goto label_0009B74A;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B74Au)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B74Au));
    label_0009B74A:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esi + 8u;
    cpu->edx = 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B75Bu)); sfera_sub_0044BFE0(cpu, LIFT_CODE_TOKEN_VA(0x49B75Bu));
    if (cpu->ebp < 0xAu) goto label_0009B76C;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B76Cu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B76Cu));
    label_0009B76C:
    cpu->esi += 0x28u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x49B770u));
    cpu->esp += 4u;
    label_0009B779:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40Cu);
    cpu->eax = cpu->esp + 0x414u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x49B7C1u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B7D8u)); sfera_sub_0049B4D0(cpu, LIFT_CODE_TOKEN_VA(0x49B7D8u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40Cu);
    cpu->eax = cpu->esp + 0x414u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x49B821u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B838u)); sfera_sub_0049B4D0(cpu, LIFT_CODE_TOKEN_VA(0x49B838u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B83Fu)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x49B83Fu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x48u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x44Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x858u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x878u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x898u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0xC9Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x10A8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x10C8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x10E8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x14ECu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x18F8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x1918u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x1938u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x1D3Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2148u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2168u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2188u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x258Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2998u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x29B8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x29D8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2DDCu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x31E8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3208u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3228u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x362Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3A38u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3A58u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3A78u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3E7Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4288u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x42A8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x42C8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x46CCu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4AD8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4AF8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4B18u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4F1Cu) = cpu->ecx & 0xFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}










__declspec(noinline) void sfera_sub_0049CC90(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9;
 bool sub_pred[4]; double x87_p0, x87_p1;
    cpu->esp -= 0x74u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->ebx + 0x7E7Cu)) goto label_0009CFF6;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x7E7Cu) = cpu->eax;
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->locate(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<std::uint32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), *SferaAbi::pointer<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)));  cpu->esp += 16u;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = (uintptr_t)&g_sfera_weather_runtime.interpolation_offsets[0];
    goto label_0009CCF4;
label_0009CCF0:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
label_0009CCF4:
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    value_8 = SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->previousValue(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), static_cast<WeatherScenarios::Property>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u) / 4u - 1u), *SferaAbi::pointer<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)));  cpu->esp += 16u;
    *(float*)(cpu->esp + 0x14u) = value_8; 
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
     if (cpu->ebx != 0u) goto label_0009CD1B;
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
     value_1 = x87_p0; value_0 = value_1; goto label_0009CD58;
label_0009CD1B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    value_9 = SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->nextValue(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), static_cast<WeatherScenarios::Property>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u) / 4u - 1u), *SferaAbi::pointer<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)));  cpu->esp += 16u;
    *(float*)(cpu->esp + 0x24u) = value_9; 
    value_2 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax += cpu->ebx;
    x87_p1 = x87_p0;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    value_3 = value_2 - x87_p1; 
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    value_4 = value_3 * x87_p1; 
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    value_5 = value_4 / x87_p1; 
    value_6 = value_5 + x87_p0;  value_0 = value_6;
label_0009CD58:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x14u) = value_0; 
    value_7 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edi += 4u;
    *(float*)(cpu->esi + cpu->ecx) = value_7; 
     if ((int32_t)cpu->edi < (int32_t)((uintptr_t)&g_sfera_weather_runtime.interpolation_offsets[kWeatherInterpolationOffsetCount])) goto label_0009CCF0;
    x87_p0 = 0.0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x88u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esp + 0x34u;
    *(float*)(cpu->esi + 0x16Cu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->selectSky(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const float>(cpu->esp + 4u), SferaAbi::pointer<char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), SferaAbi::pointer<char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)));  cpu->esp += 16u;
    if (*(uint8_t*)(cpu->esp + 0x30u) != 0u) goto label_0009CDBA;
    if (*(uint8_t*)(cpu->esp + 0x44u) == 0u) goto label_0009CF99;
label_0009CDBA:
    cpu->edi = cpu->ebx + 1u;
    cpu->ebx += 0x51u;
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0009CE78;
    cpu->esi = cpu->edi;
    cpu->esi -= *(uint32_t*)(cpu->esp + 0x88u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
label_0009CDD5:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->ecx = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x5Cu;
    x87_p0 = (x87_p0) * (0.00017361111531499773);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x98u)));
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edi);
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->selectSky(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const float>(cpu->esp + 4u), SferaAbi::pointer<char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), SferaAbi::pointer<char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)));  cpu->esp += 16u;
    cpu->ecx = cpu->esp + 0x58u;
    cpu->eax = cpu->esp + 0x30u;
label_0009CE10:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CE30;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CE2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CE30;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CE10;
label_0009CE2C:
    cpu->eax = 0u;
    goto label_0009CE35;
label_0009CE30:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
label_0009CE35:
    if (cpu->eax != 0u) goto label_0009CE78;
    cpu->ecx = cpu->esp + 0x6Cu;
    cpu->eax = cpu->esp + 0x44u;
label_0009CE41:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[2] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CE61;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CE5D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[2] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CE61;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CE41;
label_0009CE5D:
    cpu->eax = 0u;
    goto label_0009CE66;
label_0009CE61:
    cpu->eax = (sub_pred[2]) ? 0xFFFFFFFFu : 1u;
label_0009CE66:
    if (cpu->eax != 0u) goto label_0009CE78;
    ++cpu->edi;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_0009CDD5;
label_0009CE78:
    cpu->edi -= *(uint32_t*)(cpu->esp + 0x88u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x88u);
    cpu->ebp = cpu->edi;
    cpu->ebx = cpu->esi + 0xFFFFFFFFu;
    cpu->edi = cpu->esi + 0xFFFFFFAFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->edi) goto label_0009CF4F;
    cpu->esi -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
label_0009CEA0:
    x87_p0 = (double)*(float*)(cpu->esp + 0x8Cu);
    cpu->eax = cpu->esp + 0x6Cu;
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->ecx);
    x87_p1 = (x87_p1) * (0.00017361111531499773);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx);
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->selectSky(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const float>(cpu->esp + 4u), SferaAbi::pointer<char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), SferaAbi::pointer<char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)));  cpu->esp += 16u;
    cpu->ecx = cpu->esp + 0x58u;
    cpu->eax = cpu->esp + 0x30u;
label_0009CEE0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[1] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CF00;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CEFC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[1] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CF00;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CEE0;
label_0009CEFC:
    cpu->eax = 0u;
    goto label_0009CF05;
label_0009CF00:
    cpu->eax = (sub_pred[1]) ? 0xFFFFFFFFu : 1u;
label_0009CF05:
    if (cpu->eax != 0u) goto label_0009CF48;
    cpu->ecx = cpu->esp + 0x6Cu;
    cpu->eax = cpu->esp + 0x44u;
label_0009CF11:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[3] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CF31;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CF2D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[3] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CF31;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CF11;
label_0009CF2D:
    cpu->eax = 0u;
    goto label_0009CF36;
label_0009CF31:
    cpu->eax = (sub_pred[3]) ? 0xFFFFFFFFu : 1u;
label_0009CF36:
    if (cpu->eax != 0u) goto label_0009CF48;
    --cpu->ebx;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->ebx > (int32_t)cpu->edi) goto label_0009CEA0;
label_0009CF48:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x88u);
label_0009CF4F:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = cpu->edi + 0x2D0u;
    lift_push32(cpu, cpu->edx);
    cpu->esi -= cpu->ebx;
    cpu->eax = cpu->edi + 0x2CCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (cpu->esi == 1u);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    WeatherScenarios::windDirection((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) & 255u) != 0u, static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)));  cpu->esp += 16u;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebp) goto label_0009CF83;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
label_0009CF83:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = cpu->edi;
    x87_p0 = (x87_p0) / (81.0);
    *(float*)(cpu->edi + 0x16Cu) = x87_p0; 
label_0009CF99:
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->copyTexture(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<SceneSkyLayer>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)));  cpu->esp += 8u;
    cpu->eax = cpu->esi + 0xC0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->copyTexture(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<SceneSkyLayer>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)));  cpu->esp += 8u;
    cpu->eax = static_cast<std::uint32_t>(SphereWorld::Vegetation::alternatePatterns());
    if (cpu->eax == 0u) goto label_0009CFF3;
    cpu->edx = cpu->esi + 0x170u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"clouds8");
    cpu->ecx = cpu->ebp;
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->copyTexture(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<SceneSkyLayer>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)));  cpu->esp += 8u;
    cpu->eax = cpu->esi + 0x21Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"clouds8a");
    cpu->ecx = cpu->ebp;
    SferaAbi::pointer<WeatherScenarios>(cpu->ecx)->copyTexture(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<SceneSkyLayer>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)));  cpu->esp += 8u;
    *(float*)(cpu->esi + 0x2C8u) = (double)(1.0);
label_0009CFF3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
label_0009CFF6:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x74u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}





__declspec(noinline) void sfera_sub_0049DC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_0009DC91;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    label_0009DC70:
    if (cpu->eax == 0u) goto label_0009DC7F;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),328u); cpu->esi += 328u; cpu->edi += 328u; cpu->ecx = 0u;
    label_0009DC7F:
    cpu->ebx += 0x148u;
    cpu->eax += 0x148u;
    if (cpu->ebx != cpu->edx) goto label_0009DC70;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009DC91:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049DCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_0009DCC9;
    lift_push32(cpu, cpu->esi);
    label_0009DCB0:
    if (cpu->eax == 0u) goto label_0009DCBE;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->ecx + 4u);
    label_0009DCBE:
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if (cpu->ecx != cpu->edx) goto label_0009DCB0;
    cpu->esi = lift_pop32(cpu);
    label_0009DCC9:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0049DEA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0009DEA0;
    label_0009DDD0:
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
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->eax <= 0x1FFFFFFFu) goto label_0009DE12;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DDD0u); throw std::length_error("std::length_error");
    label_0009DE12:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->ecx = (int32_t)(cpu->ecx) >> 3u;
    if (cpu->ecx >= cpu->eax) goto label_0009DE6F;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE29u)); sfera_sub_00402BB0(cpu, LIFT_CODE_TOKEN_VA(0x49DE29u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE47u)); sfera_sub_0049DCA0(cpu, LIFT_CODE_TOKEN_VA(0x49DE47u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi -= cpu->eax;
    cpu->edi = (int32_t)(cpu->edi) >> 3u;
    if (cpu->eax == 0u) goto label_0009DE5E;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE5Bu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49DE5Bu));
    cpu->esp += 4u;
    label_0009DE5E:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->ebx + (cpu->ecx * 8u);
    cpu->eax = cpu->ebx + (cpu->edi * 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_0009DE6F:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009DEA0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->eax -= cpu->esi;
    cpu->edi = 0x1FFFFFFFu;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_0009DEC6;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DEA0u); throw std::length_error("std::length_error");
    label_0009DEC6:
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx -= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    if (cpu->eax <= cpu->edx) goto label_0009DEFA;
    cpu->esi = cpu->edx;
    cpu->esi >>= 1u;
    cpu->edi = 0x1FFFFFFFu;
    cpu->edi -= cpu->esi;
    if (cpu->edi >= cpu->edx) goto label_0009DEE7;
    cpu->edx = 0u;
    goto label_0009DEE9;
    label_0009DEE7:
    cpu->edx += cpu->esi;
    label_0009DEE9:
    if (cpu->edx >= cpu->eax) goto label_0009DEEF;
    cpu->edx = cpu->eax;
    label_0009DEEF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    goto label_0009DDD0;
    label_0009DEFA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
