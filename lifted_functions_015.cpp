#include "lifted_functions.h"
#include <cmath>
namespace lifted {

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


} // namespace lifted
