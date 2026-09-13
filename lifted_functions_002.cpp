#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_00418750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x414u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x418u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\%d%s");
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, 0x400u); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x418787u));
    cpu->ebp = native_function_address32(&::fopen);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->edx);
    cpu->edi = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 0x1Cu;
    if (cpu->esi == 0u) goto label_00018875;
    cpu->edi = native_function_address32(&::fclose);
    label_000187B4:
    if ((cpu->ebx & 0xFFu) != 1u) goto label_00018815;
    lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x4187BEu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4187C5u));
    cpu->esp += 0x10u;
    if ((int32_t)cpu->eax <= (int32_t)0x989680u) goto label_00018815;
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi == 0u) goto label_00018815;
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4187F3u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 0x14u;
    if (cpu->esi != 0u) goto label_000187B4;
    goto label_00018877;
    label_00018815:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x41881Au));
    cpu->eax = *(uint16_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x1Au);
    cpu->edx = *(uint16_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x1Au);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint16_t*)(cpu->esp + 0x22u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%02u.%02u.%04u %02u:%02u:%02u "); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x41884Au));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44Cu);
    cpu->ebx = cpu->eax;
    cpu->eax = cpu->esp + 0x450u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::vfprintf), LIFT_CODE_TOKEN_VA(0x418863u));
    lift_push32(cpu, cpu->esi);
    cpu->ebx += cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x30u;
    cpu->eax = cpu->ebx;
    goto label_00018877;
    label_00018875:
    cpu->eax = cpu->edi;
    label_00018877:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004188A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4188CEu)); sfera_sub_00419810(cpu, LIFT_CODE_TOKEN_VA(0x4188CEu));
    cpu->ebx = 0u;
    lift_push32(cpu, 0x23u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    cpu->ecx = 0x13880u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA68u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA6Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA70u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA74u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA78u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA7Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA80u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA84u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xEA88u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xEA8Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA90u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA94u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA98u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x13880u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0xEA9Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x418940u));
    cpu->eax = 0u;
    lift_push32(cpu, (uintptr_t)"============================================================================\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    *(uint32_t*)(cpu->esi + 0xEAA0u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xEAA4u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0xEAA6u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xEAA8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEAACu) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xEAB0u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xEAB2u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xEAB8u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418986u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418986u));
    lift_push32(cpu, (uintptr_t)"Create connect manager\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418995u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418995u));
    cpu->esp += 0x1Cu;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00418A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->esi + 0xEAA4u) != (cpu->ebx & 0xFFu)) goto label_00018B10;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(1)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418A43u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418A43u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA70u);
    cpu->edi = native_function_address32(&::WaitForSingleObject);
    cpu->esp += 8u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esi + 0xEA88u) = cpu->ebx & 0xFFu;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u)); cpu->esp += 0x8u;
    cpu->ebx = native_function_address32(&::TerminateThread);
    if (cpu->eax == 0u) goto label_00018A72;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA70u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::TerminateThread)))(cpu->ecx, 0u);
    label_00018A72:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA70u);
    cpu->ebp = native_function_address32(&::CloseHandle);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA78u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(cpu->eax, 0x64u);
    if (cpu->eax == 0u) goto label_00018A9B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA78u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::TerminateThread)))(cpu->ecx, 0u);
    label_00018A9B:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA78u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA80u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(cpu->eax, 0x64u);
    if (cpu->eax == 0u) goto label_00018ABE;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA80u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::TerminateThread)))(cpu->ecx, 0u);
    label_00018ABE:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA80u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(cpu->edx);
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(2)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418AD6u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418AD6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_00018AF0;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00018AF0;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418AEBu));
    label_00018AF0:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418AF0u));
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(3)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    *(uint16_t*)(cpu->esi + 0xEAA4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418B0Du)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418B0Du));
    cpu->esp += 8u;
    label_00018B10:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00418BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)&g_sfera_network_send_runtime.critical_section);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)&g_sfera_network_send_runtime.critical_section;
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418BE4u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = cpu->ebx + 8u;
    cpu->ebp = cpu->eax & 0xFFFFu;
    cpu->ecx = 0x13880u;
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edi = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edi) goto label_00018C4F;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: send buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418C1Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418C1Cu));
    g_sfera_network_runtime.initialization_result = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00018C3E;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00018C3E;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418C39u));
    label_00018C3E:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418C3Eu));
    *(uint8_t*)(cpu->esi + 0xEAA5u) = 0u;
    goto label_00018D2B;
    label_00018C4F:
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x418C4Fu));
    cpu->eax&=0x80000003u;
    if (((cpu->eax)&0x80000000u)==0u) goto label_00018C61;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFCu;
    ++cpu->eax;
    label_00018C61:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    ++cpu->eax;
    *(uint16_t*)(cpu->esi + 0xEAB2u) = (uint64_t)(*(uint16_t*)(cpu->esi + 0xEAB2u)) + (uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    *(uint16_t*)(cpu->edx + cpu->eax) = cpu->ebp & 0xFFFFu;
    cpu->eax = *(uint16_t*)(cpu->esi + 0xEAB2u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    *(uint16_t*)(cpu->ecx + cpu->edx + 4u) = cpu->eax & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x2Cu));
    *(uint16_t*)(cpu->ecx + cpu->edx + 6u) = cpu->eax & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx + cpu->eax + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x418CBEu));
    cpu->eax = 4u;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    if ((int32_t)cpu->edi <= (int32_t)cpu->eax) goto label_00018CFF;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x28u));
    label_00018CF0:
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(((int8_t)(*(uint8_t*)(cpu->edx + cpu->eax)))) & 0xFFFFu);
    ++cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00018CF0;
    goto label_00018D04;
    label_00018CFF:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x28u));
    label_00018D04:
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0xEAB4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) ^ (uint64_t)((cpu->ecx & 0xFFFFu)))) & 0xFFFFu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    *(uint16_t*)(cpu->eax + cpu->ecx + 2u) = cpu->edx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0xEAA0u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0xEAA0u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    ++*(uint32_t*)(cpu->esi + 0xEAB8u);
    label_00018D2B:
    lift_push32(cpu, (uintptr_t)&g_sfera_network_send_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418D30u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00418D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418D85u)); sfera_sub_00418A20(cpu, LIFT_CODE_TOKEN_VA(0x418D85u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, 0x3Au);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418DA6u)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x418DA6u));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004193E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x1A8u;
    sub_pred[0] = (uint8_t)(*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_00019410;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019716;
    label_00019410:
    if (*(uint8_t*)(cpu->edi + 0xEAA4u) != 1u) goto label_0001943B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------ERROR: ALREADY Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419431u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419431u));
    cpu->esp += 0x10u;
    cpu->eax = 0u;
    goto label_00019716;
    label_0001943B:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1B8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419454u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419454u));
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x102u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x419461u));
    if (cpu->eax == 0u) goto label_00019479;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41946Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(1)--init connect manager (%d '%s'), error=%d\n");
    goto label_000194A3;
    label_00019479:
    lift_push32(cpu, 6u); lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x41947Fu));
    *(uint32_t*)(cpu->edi + 0xEA68u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000194B8;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41948Fu));
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x419496u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2)--init connect manager (%d '%s'), error=%d\n");
    label_000194A3:
    lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4194ADu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4194ADu));
    cpu->esp += 0x14u;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019715;
    label_000194B8:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s'), skt=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4194CCu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4194CCu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0xEA68u);
    cpu->esp += 0x14u;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, 6u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    lift_native_call(cpu, native_function_address32(&::setsockopt), LIFT_CODE_TOKEN_VA(0x4194E9u));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_0001950D;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4194F4u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2_1)--init connect manager (%d), error=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41950Au)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41950Au));
    cpu->esp += 0x10u;
    label_0001950D:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') - no delay res = %d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41951Fu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41951Fu));
    cpu->esp += 0x14u;
    cpu->ecx = 2u;
    lift_push32(cpu, cpu->ebp);
    *(uint16_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x41952Du));
    lift_push32(cpu, cpu->esi);
    *(uint16_t*)(cpu->esp + 0x1Au) = cpu->eax & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419538u));
    lift_push32(cpu, cpu->esi);
    if (cpu->eax == 0xFFFFFFFFu) goto label_0001955E;
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419543u));
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x41954Du));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(1) (%d '%s'), skt=%d, adr='%s'\n");
    goto label_00019586;
    label_0001955E:
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x41955Eu));
    if (cpu->eax == 0u) goto label_000196E4;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x419577u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(2) (%d '%s'), skt=%d, adr='%s'\n");
    label_00019586:
    lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419590u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419590u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0xEA68u);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x10u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::connect), LIFT_CODE_TOKEN_VA(0x4195A1u));
    if (cpu->eax == 0u) goto label_000195FB;
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x4195AAu));
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4195B2u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_1)--init connect manager (%d '%s') \n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195CAu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195CAu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_2)--init connect manager (%d '%s'), errno=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195DCu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195DCu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_3)--init connect manager (%d '%s'), lastError=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195EEu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195EEu));
    cpu->esp += 0x38u;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4195F1u));
    goto label_00019711;
    label_000195FB:
    cpu->eax = cpu->edi + 0xEA74u;
    *(uint8_t*)(cpu->edi + 0xEA88u) = 0u;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_tcp_socket_receive_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->edi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->eax)))));
    *(uint32_t*)(cpu->edi + 0xEA70u) = cpu->eax;
    if (cpu->eax != 0u) goto label_00019638;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419625u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(5)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019638:
    cpu->ebx = native_function_address32(&::SetThreadPriority);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::SetThreadPriority)))(cpu->eax, 0u);
    cpu->ecx = cpu->edi + 0xEA7Cu;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_tcp_send_maintenance_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->edi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->ecx)))));
    *(uint32_t*)(cpu->edi + 0xEA78u) = cpu->eax;
    if (cpu->eax != 0u) goto label_00019679;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419666u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(6)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019679:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::SetThreadPriority)))(cpu->eax, 0u);
    cpu->edx = cpu->edi + 0xEA84u;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_tcp_receive_dispatch_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->edi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->edx)))));
    *(uint32_t*)(cpu->edi + 0xEA80u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000196B1;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4196A1u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(7)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_000196B1:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::SetThreadPriority)))(cpu->eax, 0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x4196BBu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(3) (%d '%s'), skt=%d, adr='%s'\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4196D4u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4196D4u));
    cpu->esp += 0x18u;
    *(uint16_t*)(cpu->edi + 0xEAA4u) = 0x101u;
    cpu->eax = 0u;
    goto label_00019714;
    label_000196E4:
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4196E4u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xEA68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x4196F2u));
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4196F7u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(3)--init connect manager (%d '%s'), error=%d\n");
    label_00019704:
    lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41970Eu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41970Eu));
    cpu->esp += 0x14u;
    label_00019711:
    cpu->eax |= 0xFFFFFFFFu;
    label_00019714:
    cpu->ebx = lift_pop32(cpu);
    label_00019715:
    cpu->ebp = lift_pop32(cpu);
    label_00019716:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1A8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00419810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xEA60u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41981Bu));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0xEA60u) = 0u;
    *(uint32_t*)(cpu->esi + 0xEA64u) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00419840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    cpu->eax = *(uint32_t*)((uintptr_t)"0123456789ABCDEF");
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->eax = *(uint32_t*)(((uintptr_t)"0123456789ABCDEF") + 4u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(((uintptr_t)"0123456789ABCDEF") + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(((uintptr_t)"0123456789ABCDEF") + 0xCu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"0123456789ABCDEF") + 0x10u));
    cpu->esi += cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->eax & 0xFFu;
    if (cpu->ecx >= cpu->esi) goto label_000198E6;
    label_00019885:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x61u) goto label_0001988F;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x7Au) goto label_000198DE;
    label_0001988F:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x41u) goto label_00019897;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x5Au) goto label_000198DE;
    label_00019897:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_0001989F;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_000198DE;
    label_0001989F:
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0x5Fu) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0x7Eu) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000198FC;
    cpu->eax = cpu->esi + 0xFFFFFFFEu;
    if (cpu->ecx >= cpu->eax) goto label_00019901;
    *(uint8_t*)(cpu->ecx) = 0x25u;
    cpu->eax = *(uint8_t*)(cpu->edx);
    cpu->eax >>= 4u;
    cpu->eax = *(uint8_t*)(cpu->esp + cpu->eax + 4u);
    *(uint8_t*)(cpu->ecx + 1u) = cpu->eax & 0xFFu;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->eax &= 0xFu;
    cpu->eax = *(uint8_t*)(cpu->esp + cpu->eax + 4u);
    *(uint8_t*)(cpu->ecx + 2u) = cpu->eax & 0xFFu;
    cpu->ecx += 3u;
    goto label_000198E1;
    label_000198DE:
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    label_000198E1:
    ++cpu->edx;
    if (cpu->ecx < cpu->esi) goto label_00019885;
    label_000198E6:
    *(uint8_t*)(cpu->esi + 0xFFFFFFFFu) = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000198FC:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    label_00019901:
    if (cpu->ecx >= cpu->esi) goto label_000198E6;
    *(uint8_t*)(cpu->ecx) = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}


} // namespace lifted
