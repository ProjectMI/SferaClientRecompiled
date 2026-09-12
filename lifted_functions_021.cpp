#include "lifted_functions.h"
#include <cmath>
namespace lifted {



















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














} // namespace lifted
