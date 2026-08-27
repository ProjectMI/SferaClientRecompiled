#include "lifted_functions.h"
#include <cmath>
#include <cstddef>
#include <cstring>
namespace lifted {

static void sfera_u32_to_sso_decimal(LiftCpu* cpu) {
    const uint32_t destination = cpu->ecx;
    uint32_t value = *(uint32_t*)(cpu->edx);
    uint8_t reversed[16]{};
    std::size_t length = 0u;
    do {
        reversed[length++] = static_cast<uint8_t>('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);
    for (std::size_t index = 0u; index != 16u; ++index) {
        const uint8_t output = index < length ? reversed[length - index - 1u] : 0u;
        *(uint8_t*)(destination + static_cast<uint32_t>(index)) = output;
    }
    *(uint32_t*)(destination + 0x10u) = static_cast<uint32_t>(length);
    *(uint32_t*)(destination + 0x14u) = 15u;
    cpu->eax = destination;
}
static uint8_t sfera_key_ascii_fold(uint8_t value) { return value >= 'a' && value <= 'z' ? (uint8_t)(value - ('a' - 'A')) : value; }
static int sfera_key_name_equals(uint32_t address, const char* literal) { if (!address || !literal) { return 0; } for (uint32_t index = 0;; ++index) { const uint8_t lhs = sfera_key_ascii_fold(*(uint8_t*)(address + index)); const uint8_t rhs = sfera_key_ascii_fold((uint8_t)literal[index]); if (lhs != rhs) { return 0; } if (!rhs) { return 1; } } }
static const char* sfera_key_name_from_code(uint32_t code) { switch (code) {
case 0x1Bu: return "ESCAPE";
case 0x70u: return "F1";
case 0x71u: return "F2";
case 0x72u: return "F3";
case 0x73u: return "F4";
case 0x74u: return "F5";
case 0x75u: return "F6";
case 0x76u: return "F7";
case 0x77u: return "F8";
case 0x78u: return "F9";
case 0x79u: return "F10";
case 0x7Au: return "F11";
case 0x7Bu: return "F12";
case 0x91u: return "SCRL_LOCK";
case 0x13u: return "PAUSE";
case 8u: return "BACKSPACE";
case 0x20u: return "SPACE";
case 0x23u: return "END";
case 0x24u: return "HOME";
case 0x25u: return "LEFT";
case 0x26u: return "UP";
case 0x27u: return "RIGHT";
case 0x28u: return "DOWN";
case 0x2Du: return "INSERT";
case 0x2Eu: return "DELETE";
case 0xDu: return "ENTER";
case 0x14u: return "CAPSLOCK";
case 0x60u: return "NUMPAD0";
case 0x61u: return "NUMPAD1";
case 0x62u: return "NUMPAD2";
case 0x63u: return "NUMPAD3";
case 0x64u: return "NUMPAD4";
case 0x65u: return "NUMPAD5";
case 0x66u: return "NUMPAD6";
case 0x67u: return "NUMPAD7";
case 0x68u: return "NUMPAD8";
case 0x69u: return "NUMPAD9";
case 0x6Au: return "NUMPADMULT";
case 0x6Bu: return "NUMPADADD";
case 0x90u: return "NUMLOCK";
case 0x6Du: return "NUMPADSUBT";
case 0x6Fu: return "NUMPADDIV";
case 0x6Eu: return "NUMPADPNT";
case 0x21u: return "PAGEUP";
case 0x22u: return "PAGEDOWN";
case 0xC0u: return "`";
case 0x31u: return "1";
case 0x32u: return "2";
case 0x33u: return "3";
case 0x34u: return "4";
case 0x35u: return "5";
case 0x36u: return "6";
case 0x37u: return "7";
case 0x38u: return "8";
case 0x39u: return "9";
case 0x30u: return "0";
case 0xBDu: return "-";
case 0xBBu: return "=";
case 0xDCu: return "\\";
case 0x51u: return "Q";
case 0x57u: return "W";
case 0x45u: return "E";
case 0x52u: return "R";
case 0x54u: return "T";
case 0x59u: return "Y";
case 0x55u: return "U";
case 0x49u: return "I";
case 0x4Fu: return "O";
case 0x50u: return "P";
case 0xDBu: return "[";
case 0xDDu: return "]";
case 0x41u: return "A";
case 0x53u: return "S";
case 0x44u: return "D";
case 0x46u: return "F";
case 0x47u: return "G";
case 0x48u: return "H";
case 0x4Au: return "J";
case 0x4Bu: return "K";
case 0x4Cu: return "L";
case 0xBAu: return ";";
case 0xDEu: return "'";
case 0x5Au: return "Z";
case 0x58u: return "X";
case 0x43u: return "C";
case 0x56u: return "V";
case 0x42u: return "B";
case 0x4Eu: return "N";
case 0x4Du: return "M";
case 0xBCu: return ",";
case 0xBEu: return ".";
case 0xBFu: return "/";
case 9u: return "TAB";
case 0x11u: return "CTRL";
case 0x10u: return "SHIFT";
default: return (const char*)0; } }
static uint32_t sfera_key_code_from_name(uint32_t address) { if (!address) { return 0u; } for (uint32_t code = 0; code <= 0xFFu; ++code) { const char* name = sfera_key_name_from_code(code); if (name && sfera_key_name_equals(address, name)) { return code; } } return 0u; }
static uint32_t sfera_key_dik_from_virtual_key(uint32_t key) {
    if (key >= 0x70u && key <= 0x79u) { return 0x3Bu + key - 0x70u; }
    if (key == 0x7Au) { return 0x57u; }
    if (key == 0x7Bu) { return 0x58u; }
    if (key >= '1' && key <= '9') { return 2u + key - '1'; }
    if (key == '0') { return 0xBu; }
    if (key >= 0x61u && key <= 0x69u) { const uint32_t digit = key - 0x60u; return 0x53u - UINT32_C(4) * ((digit + UINT32_C(2)) / UINT32_C(3)) + ((digit - UINT32_C(1)) % UINT32_C(3)); }
    if (key == 0x60u) { return 0x52u; }
    const char* position = strchr("QWERTYUIOP", (int)key); if (position) { return 0x10u + (uint32_t)(position - "QWERTYUIOP"); }
    position = strchr("ASDFGHJKL", (int)key); if (position) { return 0x1Eu + (uint32_t)(position - "ASDFGHJKL"); }
    position = strchr("ZXCVBNM", (int)key); if (position) { return 0x2Cu + (uint32_t)(position - "ZXCVBNM"); }
    switch (key) { case 0x1Bu: return 1u; case 0x91u: return 0x46u; case 0x13u: return 0xC5u; case 8u: return 0xEu; case 0x20u: return 0x39u; case 0x23u: return 0xCFu; case 0x24u: return 0xC7u; case 0x25u: return 0xCBu; case 0x26u: return 0xC8u; case 0x27u: return 0xCDu; case 0x28u: return 0xD0u; case 0x2Du: return 0xD2u; case 0x2Eu: return 0xD3u; case 0xDu: return 0x1Cu; case 0x14u: return 0x3Au; case 0x6Au: return 0x37u; case 0x6Bu: return 0x4Eu; case 0x90u: return 0x45u; case 0x6Du: return 0x4Au; case 0x6Fu: return 0xB5u; case 0x6Eu: return 0x53u; case 0x21u: return 0xC9u; case 0x22u: return 0xD1u; case 0xC0u: return 0x29u; case 0xBDu: return 0xCu; case 0xBBu: return 0xDu; case 0xDCu: return 0x2Bu; case 0xDBu: return 0x1Au; case 0xDDu: return 0x1Bu; case 0xBAu: return 0x27u; case 0xDEu: return 0x28u; case 0xBCu: return 0x33u; case 0xBEu: return 0x34u; case 0xBFu: return 0x35u; case 9u: return 0xFu; case 0x11u: return 0x1Du; case 0x10u: return 0x2Au; default: return 0u; }
}
static uint32_t sfera_key_virtual_key_from_dik(uint32_t dik) { for (uint32_t key = 0u; key <= 0xFFu; ++key) { if (sfera_key_dik_from_virtual_key(key) == dik) { return key; } } return 0u; }
__declspec(noinline) void sfera_sub_004B9A10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    *(uint32_t*)(cpu->ecx) = 0x31564955u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx + 4u;
    if (cpu->edx == cpu->eax) goto label_000B9A6B;
    lift_push32(cpu, cpu->esi);
    label_000B9A26:
    cpu->eax = cpu->edx + 8u;
    if (*(uint32_t*)(cpu->edx + 0x1Cu) < 0x10u) goto label_000B9A31;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9A31:
    cpu->esi = cpu->edi;
    cpu->esi -= cpu->eax;
    label_000B9A35:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B9A35;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->edx + 0x24u))));
    cpu->eax = *(uint32_t*)(cpu->edx + 0x18u);
    cpu->eax = cpu->eax + cpu->edi + 1u;
    cpu->edi = cpu->eax + 8u;
    x87_v0 = (x87_v0) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    *(float*)(cpu->eax) = x87_v0; 
    *(float*)(cpu->eax + 4u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->edx + 0x28u)))))) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height)))));
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10) goto label_000B9A26;
    cpu->esi = lift_pop32(cpu);
    label_000B9A6B:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9A70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if (cpu->ebx != 0u) goto label_000B9A7B;
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9A7B:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    if (cpu->esi == cpu->eax) goto label_000B9AB5;
    cpu->edi = native_function_address32(&::_stricmp);
    label_000B9A90:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000B9AA0;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9AA0:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->ebx);

    if (cpu->eax == 0u) goto label_000B9ABB;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) goto label_000B9A90;
    label_000B9AB5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9ABB:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9AD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->ecx == cpu->esi) goto label_000B9AF9;
    label_000B9AE0:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x24u);
    cpu->eax >>= 3u;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000B9AF3;
    if (*(uint8_t*)(cpu->edx + 0x48u) == 0u) goto label_000B9AFE;
    label_000B9AF3:
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx != cpu->esi) goto label_000B9AE0;
    label_000B9AF9:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9AFE:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (cpu->ecx == cpu->esi) goto label_000B9B4D;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    label_000B9B28:
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    if (cpu->edx > cpu->eax) goto label_000B9B39;
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    label_000B9B39:
    --cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000B9B49;
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    label_000B9B49:
    if (cpu->ecx != cpu->esi) goto label_000B9B28;
    label_000B9B4D:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9B77u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4B9B77u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000B9B91;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4B9B60u), "std::length_error");
    label_000B9B91:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->esi == 0u) goto label_000B9C2E;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9C08u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B9C08u));
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, 0u);
    cpu->edi += 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x24u) = 1u;
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9C2Eu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xB9C2Eu));
    label_000B9C2E:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9C50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (cpu->esi == 0u) goto label_000B9CCE;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CA8u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B9CA8u));
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, 0u);
    cpu->edi += 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x28u) = 1u;
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9CCEu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xB9CCEu));
    label_000B9CCE:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9D00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (g_sfera_interface_runtime.cross_enabled == cpu->edi) goto label_000B9F33;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_000B9D3A;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9D3Au)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xB9D3Au));
    label_000B9D3A:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx += cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->eax)) goto label_000B9F33;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    goto label_000B9D82;
    label_000B9D80:
    cpu->edi = 0u;
    label_000B9D82:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_000B9F18;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000B9F18;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xE0u));
    if ((cpu->eax & 0xFFu)==0u) goto label_000B9DB5;
    if (*(uint8_t*)(cpu->esi + 0x11Cu) != 0u) goto label_000B9F18;
    label_000B9DB5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx >>= 4u;
    if ((((cpu->ecx & 0xFFu)) & (1u)) != 0u) goto label_000B9F18;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000B9F18;
    if (*(uint8_t*)(cpu->esi + 0xE1u) != (cpu->eax & 0xFFu)) goto label_000B9F18;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_000B9DF9;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9DF9u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xB9DF9u));
    label_000B9DF9:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = cpu->edi + cpu->eax;
    cpu->ebp = cpu->esi + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebp;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_000B9F18;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x38u) < (int32_t)cpu->eax) goto label_000B9F18;
    cpu->ebx = cpu->ebp;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_000B9F14;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x3Cu) < (int32_t)cpu->ecx) goto label_000B9F14;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    sub_pred[0] = cpu->eax == cpu->ebx; sub_pred[3] = (int32_t)(cpu->eax) < (int32_t)(cpu->ebx);
    if ((int32_t)(cpu->eax) >= (int32_t)(cpu->ebx)) goto label_000B9E7C;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x38u) >= (int32_t)cpu->edx) goto label_000B9E7A;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) <= (int32_t)cpu->ecx) goto label_000B9E7A;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if ((int32_t)cpu->ebx >= (int32_t)cpu->ebp) goto label_000B9E76;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0xACu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9E71u)); sfera_sub_004B9B60(cpu, LIFT_CODE_TOKEN_VA(0x4B9E71u));
    goto label_000B9F18;
    label_000B9E76:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000B9E7A:
    sub_pred[0] = cpu->eax == cpu->ebx; sub_pred[3] = (int32_t)(cpu->eax) < (int32_t)(cpu->ebx);
    label_000B9E7C:
    if ((sub_pred[0]) || (sub_pred[3])) goto label_000B9E9C;
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->esp + 0x38u)) goto label_000B9E9C;
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_000B9E9C;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x4Cu);
    if ((int32_t)cpu->ebx >= (int32_t)*(uint32_t*)(cpu->esp + 0x3Cu)) goto label_000B9E98;
    cpu->edx = cpu->edi;
    goto label_000B9ED8;
    label_000B9E98:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000B9E9C:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
    sub_pred[1] = (int32_t)(cpu->ebx) < (int32_t)(cpu->eax);
    if ((cpu->ebx == cpu->eax) || ((int32_t)(cpu->ebx) < (int32_t)(cpu->eax))) goto label_000B9EC6;
    if ((int32_t)cpu->esi >= (int32_t)cpu->edx) goto label_000B9EC4;
    cpu->edx = cpu->esi;
    label_000B9EAA:
    cpu->edx -= cpu->ebx;
    label_000B9EAC:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x4Cu);
    sub_pred[2] = (int32_t)(cpu->edi) < (int32_t)(cpu->ecx);
    if ((cpu->edi == cpu->ecx) || ((int32_t)(cpu->edi) < (int32_t)(cpu->ecx))) goto label_000B9ED0;
    if ((int32_t)cpu->eax >= (int32_t)cpu->esi) goto label_000B9ECE;
    cpu->eax -= cpu->edi;
    goto label_000B9EDA;
    label_000B9EC4:
    sub_pred[1] = (int32_t)(cpu->ebx) < (int32_t)(cpu->eax);
    label_000B9EC6:
    if (!sub_pred[1]) goto label_000B9EAA;
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->eax;
    goto label_000B9EAC;
    label_000B9ECE:
    sub_pred[2] = (int32_t)(cpu->edi) < (int32_t)(cpu->ecx);
    label_000B9ED0:
    if (!sub_pred[2]) goto label_000B9ED6;
    cpu->eax -= cpu->ecx;
    goto label_000B9EDA;
    label_000B9ED6:
    cpu->esi -= cpu->edi;
    label_000B9ED8:
    cpu->eax = cpu->esi;
    label_000B9EDA:
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x20u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))))) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))))));
    { const double lift_left=(double)*(float*)(cpu->esp + 0x20u); const double lift_right=((double)0.30000001192092896f); if (!(lift_left>lift_right)) goto label_000B9F18; }
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0xACu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9F12u)); sfera_sub_004B9B60(cpu, LIFT_CODE_TOKEN_VA(0x4B9F12u));
    goto label_000B9F18;
    label_000B9F14:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    label_000B9F18:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_000B9D80;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000B9F33:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9F40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x25Cu;
    lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = cpu->esp + 0x15Cu;
    lift_push32(cpu, (uintptr_t)"Language\\*%s.hts"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4B9F8Cu));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x15Cu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x4B9FA2u));
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != 0xFFFFFFFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if (cpu->eax == 0u) goto label_000BA14E;
    cpu->ebp = native_strrchr_address32();
    label_000B9FC4:
    if (((*(uint8_t*)(cpu->esp + 0x18u)) & (0x10u)) != 0u) goto label_000BA136;
    cpu->eax = *(uint32_t*)((uintptr_t)"Language\\");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"Language\\") + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"Language\\") + 8u));
    *(uint32_t*)(cpu->esp + 0x158u) = cpu->eax;
    cpu->eax = cpu->esp + 0x44u;
    *(uint32_t*)(cpu->esp + 0x15Cu) = cpu->ecx;
    *(uint16_t*)(cpu->esp + 0x160u) = cpu->edx & 0xFFFFu;
    cpu->esi = cpu->eax;
    label_000BA000:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BA000;
    cpu->edi = cpu->esp + 0x158u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000BA011:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000BA011;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->edx = 0x182u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA036u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA036u));
    lift_push32(cpu, 0x68u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA03Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BA03Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x264u) = 0u;
    if (cpu->eax == 0u) goto label_000BA05E;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA05Au)); sfera_sub_004A78F0(cpu, LIFT_CODE_TOKEN_VA(0x4BA05Au));
    cpu->esi = cpu->eax;
    goto label_000BA060;
    label_000BA05E:
    cpu->esi = 0u;
    label_000BA060:
    cpu->eax = cpu->esp + 0x158u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x268u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA07Eu)); sfera_sub_004A8610(cpu, LIFT_CODE_TOKEN_VA(0x4BA07Eu));
    if (cpu->eax == 0u) goto label_000BA113;
    if (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0] == 0u) goto label_000BA0C9;
    cpu->ecx = cpu->esp + 0x158u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strrchr_address32()))(cpu->ecx, 0x5Fu);

    if (cpu->eax == 0u) goto label_000BA0C9;
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esp + 0x158u;
    --cpu->eax;
    label_000BA0B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BA0B0;
    cpu->edx = *(uint32_t*)((uintptr_t)".hts");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".hts") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    label_000BA0C9:
    cpu->edx = cpu->esp + 0x158u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA0D8u)); sfera_sub_004A5E90(cpu, LIFT_CODE_TOKEN_VA(0x4BA0D8u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA0F4u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA0F4u));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor);
    if (cpu->ecx < 1u) goto label_000BA17C;
    g_sfera_interface_core_runtime.free_list_b_cursor = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    goto label_000BA136;
    label_000BA113:
    cpu->edx = 0x197u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA122u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA122u));
    if (cpu->esi == 0u) goto label_000BA136;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA12Du)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4BA12Du));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA133u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BA133u));
    cpu->esp += 4u;
    label_000BA136:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x4BA140u));
    if (cpu->eax != 0u) goto label_000B9FC4;
    label_000BA14E:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x4BA14Fu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x258u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA17C:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BA17Cu), "std::length_error");
    lift_trap(cpu, 0x4BA187u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BA190(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = 0x1E6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA1C9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA1C9u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA1D3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BA1D3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (cpu->eax == 0u) goto label_000BA1F1;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA1EDu)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x4BA1EDu));
    cpu->edi = cpu->eax;
    goto label_000BA1F3;
    label_000BA1F1:
    cpu->edi = 0u;
    label_000BA1F3:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA203u)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x4BA203u));
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA20Cu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4BA20Cu));
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA21Du)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA21Du));
    if (cpu->eax == 0u) goto label_000BA319;
    label_000BA225:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA22Cu)); sfera_sub_004D3AC0(cpu, LIFT_CODE_TOKEN_VA(0x4BA22Cu));
    cpu->esi = cpu->eax;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    if (cpu->eax != 0u) goto label_000BA264;
    cpu->edx = 0x1F7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA254u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA254u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    goto label_000BA300;
    label_000BA264:
    cpu->eax = cpu->esi + 0x178u;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) < 0x10u) goto label_000BA275;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BA275:
    cpu->ecx = (uintptr_t)"";
    label_000BA280:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000BA2A0;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000BA29C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000BA2A0;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BA280;
    label_000BA29C:
    cpu->eax = 0u;
    goto label_000BA2A5;
    label_000BA2A0:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000BA2A5:
    if (cpu->eax != 0u) goto label_000BA2C7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"WindowUI(%s,%d %d). Window name not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA2BEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BA2BEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA2C4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA2C4u));
    cpu->esp += 0x14u;
    label_000BA2C7:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA2E3u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA2E3u));
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor);
    if (cpu->edx < 1u) goto label_000BA356;
    g_sfera_interface_core_runtime.free_list_a_cursor = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_000BA300:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA311u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA311u));
    if (cpu->eax != 0u) goto label_000BA225;
    label_000BA319:
    cpu->edx = 0x209u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA328u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA328u));
    if (cpu->edi == 0u) goto label_000BA33C;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA333u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4BA333u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA339u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BA339u));
    cpu->esp += 4u;
    label_000BA33C:
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BA356:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BA356u), "std::length_error");
    lift_trap(cpu, 0x4BA361u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BA370(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x264u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x270u;
    cpu->ecx = (uintptr_t)"Effects\\*.ui";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA3B9u)); sfera_sub_00425950(cpu, LIFT_CODE_TOKEN_VA(0x4BA3B9u));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Effects\\*.ui");
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x4BA3C7u));
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v1 = 1.0;
    cpu->esi = cpu->eax;
    x87_v0 = x87_v1 / x87_v0; 
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != 0xFFFFFFFFu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = (double)(0.0);
    if (cpu->eax == 0u) goto label_000BA647;
    label_000BA3F5:
    if (((*(uint8_t*)(cpu->esp + 0x24u)) & (0x10u)) != 0u) goto label_000BA633;
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, (uintptr_t)"loadscreen.ui"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BA40Au));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000BA633;
    cpu->eax = 0x5C737463u;
    cpu->edx = 0x65666645u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->eax;
    cpu->eax = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->esp + 0x164u) = cpu->edx;
    *(uint8_t*)(cpu->esp + 0x16Cu) = cpu->ecx & 0xFFu;
    cpu->esi = cpu->eax;
    label_000BA447:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BA447;
    cpu->edi = cpu->esp + 0x164u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000BA458:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000BA458;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->edx = 0x1E6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA47Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA47Du));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA487u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BA487u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x278u) = 0u;
    if (cpu->eax == 0u) goto label_000BA4A8;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA4A4u)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x4BA4A4u));
    cpu->edi = cpu->eax;
    goto label_000BA4AA;
    label_000BA4A8:
    cpu->edi = 0u;
    label_000BA4AA:
    cpu->edx = cpu->esp + 0x164u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x27Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA4C4u)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x4BA4C4u));
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA4CDu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4BA4CDu));
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA4DEu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA4DEu));
    if (cpu->eax == 0u) goto label_000BA5E6;
    label_000BA4E6:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA4EDu)); sfera_sub_004D3AC0(cpu, LIFT_CODE_TOKEN_VA(0x4BA4EDu));
    cpu->esi = cpu->eax;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x16Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    if (cpu->eax != 0u) goto label_000BA52C;
    cpu->edx = 0x1F7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA51Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA51Cu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    goto label_000BA5CD;
    label_000BA52C:
    cpu->eax = cpu->esi + 0x178u;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) < 0x10u) goto label_000BA53D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BA53D:
    cpu->ecx = (uintptr_t)"";
    label_000BA542:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000BA562;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000BA55E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000BA562;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BA542;
    label_000BA55E:
    cpu->eax = 0u;
    goto label_000BA567;
    label_000BA562:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000BA567:
    if (cpu->eax != 0u) goto label_000BA590;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x16Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"WindowUI(%s,%d %d). Window name not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA587u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BA587u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA58Du)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA58Du));
    cpu->esp += 0x14u;
    label_000BA590:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA5ACu)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA5ACu));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor);
    if (cpu->ecx < 1u) goto label_000BA671;
    g_sfera_interface_core_runtime.free_list_a_cursor = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_000BA5CD:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA5DEu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA5DEu));
    if (cpu->eax != 0u) goto label_000BA4E6;
    label_000BA5E6:
    cpu->edx = 0x209u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA5F5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA5F5u));
    if (cpu->edi == 0u) goto label_000BA609;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA600u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4BA600u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA606u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BA606u));
    cpu->esp += 4u;
    label_000BA609:
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esp + 0xCu))) + (((double)*(float*)(cpu->esp + 0x20u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v1 = 30.0;
    x87_v0 = (x87_v0) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA62Fu)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BA62Fu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000BA633:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x4BA639u));
    if (cpu->eax != 0u) goto label_000BA3F5;
    label_000BA647:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x4BA648u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA671:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BA671u), "std::length_error");
    lift_trap(cpu, 0x4BA67Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BA680(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) < 0x40u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (sub_pred[0]) goto label_000BA691;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBA691u)); sfera_sub_004B9B10(cpu, LIFT_CODE_TOKEN_RVA(0xBA691u));
    label_000BA691:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA69Cu)); sfera_sub_004A01D0(cpu, LIFT_CODE_TOKEN_VA(0x4BA69Cu));
    g_sfera_interface_core_runtime.state_01 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) + 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA6B0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0xCu;
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_000BA6C6;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA6C6:
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA6D5u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4BA6D5u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx == 0u) goto label_000BA6DD;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000BA6DD:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edx > cpu->eax) goto label_000BA6E9;
    cpu->eax -= cpu->edx;
    label_000BA6E9:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->edi += 28u;
    sub_pred[1] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) == 0u;
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[1]) goto label_000BA736;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    cpu->eax += cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin > cpu->eax) goto label_000BA724;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = 0u;
    label_000BA724:
    if ((g_sfera_interface_core_runtime.queue_cursor -= cpu->ecx) != 0u) goto label_000BA736;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = 0u;
    label_000BA736:
    g_sfera_interface_core_runtime.state_01 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    cpu->eax = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    if (cpu->ecx == 0u) goto label_000BA7DD;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    if (cpu->eax == cpu->edx) goto label_000BA7DD;
    label_000BA768:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BA775;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BA768;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA775:
    if (cpu->eax == cpu->edx) goto label_000BA7DD;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA78Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BA78Fu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 4u;
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA7B4u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA7B4u));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->ecx >= 1u) goto label_000BA7CF;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BA775u), "std::length_error");
    label_000BA7CF:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_000BA7DD:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA7E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    if (cpu->eax == cpu->edx) goto label_000BA865;
    label_000BA7F0:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BA7FD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BA7F0;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA7FD:
    if (cpu->eax == cpu->edx) goto label_000BA865;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA817u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BA817u));
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esp += 4u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA83Bu)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA83Bu));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->ecx >= 1u) goto label_000BA856;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BA7FDu), "std::length_error");
    label_000BA856:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_000BA865:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA892u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA892u));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->ecx >= 1u) goto label_000BA8AD;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BA870u), "std::length_error");
    label_000BA8AD:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000BA8FE;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    (void)cpu;
    label_000BA8D0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA8DCu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BA8DCu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA8ECu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BA8ECu));
    cpu->esi += 0x38u;
    cpu->edi += 0x38u;
    if (cpu->esi != cpu->ebx) goto label_000BA8D0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BA8FE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA910(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x4Cu;
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    cpu->edi = cpu->ebx + 0x10u;
    if (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0] == (cpu->ebx & 0xFFu)) goto label_000BA9C6;
    lift_push32(cpu, (uintptr_t)"_e"); lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BA96Eu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000BA9C6;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_000BA980:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BA980;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA994u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BA994u));
    cpu->eax = (uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->edx = cpu->eax + 1u;
    label_000BA9A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BA9A0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA9B8u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4BA9B8u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (*(uint32_t*)(cpu->esp + 0x40u) >= cpu->edi) goto label_000BA9C6;
    cpu->esi = cpu->esp + 0x2Cu;
    label_000BA9C6:
    lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"Effects\\");
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA9E6u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BA9E6u));
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x54u) = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000BA9F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BA9F0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA04u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4BAA04u));
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)".sfn");
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA14u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4BAA14u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->esp + 0x24u) >= cpu->edi) goto label_000BAA22;
    cpu->ecx = cpu->esp + 0x10u;
    label_000BAA22:
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA29u)); sfera_sub_004A5540(cpu, LIFT_CODE_TOKEN_VA(0x4BAA29u));
    if (cpu->eax != 0u) goto label_000BAA41;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Can't load font '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA38u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAA38u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA3Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BAA3Eu));
    cpu->esp += 0xCu;
    label_000BAA41:
    if (*(uint32_t*)(cpu->esp + 0x24u) < cpu->edi) goto label_000BAA54;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA51u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BAA51u));
    cpu->esp += 4u;
    label_000BAA54:
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x40u) < cpu->edi) goto label_000BAA77;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA74u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BAA74u));
    cpu->esp += 4u;
    label_000BAA77:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BAAA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x114u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0x3Au); lift_push32(cpu, cpu->ebx);
    cpu->edi = cpu->edx;
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4BAABEu));
    cpu->esp += 8u;
    cpu->ecx = cpu->ebx;
    if (cpu->eax == 0u) goto label_000BAAE7;
    cpu->esi = cpu->esp + 0x1Cu;
    cpu->esi -= cpu->ebx;
    label_000BAAD3:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BAAD3;
    cpu->eax -= cpu->ebx;
    *(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu) = cpu->edx & 0xFFu;
    cpu->ecx = cpu->esp + 0x1Cu;
    label_000BAAE7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAAECu)); sfera_sub_004B9850(cpu, LIFT_CODE_TOKEN_VA(0x4BAAECu));
    if (cpu->eax == 0u) goto label_000BACC5;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if (cpu->ebp != 0u) goto label_000BAB1C;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CreateWindow(%s) -> Can't create reference class");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB13u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAB13u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB19u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BAB19u));
    cpu->esp += 0xCu;
    label_000BAB1C:
    cpu->edx = cpu->ebx;
    if (cpu->ebx != 0u) goto label_000BAB27;
    cpu->edx = (uintptr_t)"";
    label_000BAB27:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000BAB30:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BAB30;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB43u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BAB43u));
    if (((*(uint8_t*)(cpu->esp + 0x12Cu)) & (1u)) == 0u) goto label_000BAB65;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    goto label_000BAC2C;
    label_000BAB65:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x17u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB76u)); sfera_sub_004B92D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAB76u));
    if (cpu->eax == 0u) goto label_000BAB9D;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    cpu->ecx += 0xFFFFFFF1u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) < (int32_t)cpu->ecx) goto label_000BAB98;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->edx += 0xFFFFFFF1u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) >= (int32_t)cpu->edx) goto label_000BAB9D;
    label_000BAB98:
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    label_000BAB9D:
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == cpu->edi) goto label_000BABF1;
    label_000BABB0:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000BABC0;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BABC0:
    cpu->ecx = cpu->ebx;
    label_000BABC2:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000BABE2;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000BABDE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000BABE2;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BABC2;
    label_000BABDE:
    cpu->eax = 0u;
    goto label_000BABE7;
    label_000BABE2:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000BABE7:
    if (cpu->eax == 0u) goto label_000BAC14;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->edi) goto label_000BABB0;
    label_000BABF1:
    if (*(uint8_t*)(cpu->esp + 0x13u) == 0u) goto label_000BAC14;
    if (*(uint8_t*)(cpu->ebp + 0x4Eu) == 0u) goto label_000BAC14;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    goto label_000BAC2C;
    label_000BAC14:
    if (((*(uint8_t*)(cpu->esp + 0x12Cu)) & (8u)) == 0u) goto label_000BAC25;
    *(uint32_t*)(cpu->ebp + 0x38u) = 0x24u;
    label_000BAC25:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBAC2Cu)); sfera_sub_004D1A10(cpu, LIFT_CODE_TOKEN_RVA(0xBAC2Cu));
    label_000BAC2C:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x12Cu));
    if ((((cpu->eax & 0xFFu)) & (2u)) != 0u) goto label_000BAC3B;
    *(uint8_t*)(cpu->ebp + 0x48u) = 0u;
    label_000BAC3B:
    if (*(uint8_t*)(cpu->ebp + 0x48u) != 0u) goto label_000BAC4E;
    if ((((cpu->eax & 0xFFu)) & (4u)) != 0u) goto label_000BAC4E;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBAC4Eu)); sfera_sub_004D1D00(cpu, LIFT_CODE_TOKEN_RVA(0xBAC4Eu));
    label_000BAC4E:
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->ebp + 0x4Au) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAC59u)); sfera_sub_004B9D00(cpu, LIFT_CODE_TOKEN_VA(0x4BAC59u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xACu);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000BAC7E;
    label_000BAC65:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x79u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->ebp + 0xACu)) goto label_000BAC65;
    label_000BAC7E:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAC9Au)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BAC9Au));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->ecx >= 1u) goto label_000BACB5;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BAC7Eu), "std::length_error");
    label_000BACB5:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    label_000BACC5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x114u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BACE0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000BAD0B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    if (cpu->edx != 0u) goto label_000BACF1;
    cpu->esi = (uintptr_t)"";
    label_000BACF1:
    cpu->eax = cpu->esi;
    cpu->edi = cpu->eax + 1u;
    label_000BACF6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BACF6;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx += 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD09u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BAD09u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BAD0B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BAD10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->edi != 0u) goto label_000BAD59;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    if (cpu->eax == 0u) goto label_000BAE50;
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->eax + 0xD8u) == cpu->ecx) goto label_000BAD43;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD3Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAD3Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD40u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BAD40u));
    cpu->esp += 0xCu;
    label_000BAD43:
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD4Cu)); sfera_sub_004D1E20(cpu, LIFT_CODE_TOKEN_VA(0x4BAD4Cu));
    cpu->edi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BAD59:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD5Eu)); sfera_sub_004B9350(cpu, LIFT_CODE_TOKEN_VA(0x4BAD5Eu));
    if (cpu->eax == 0u) goto label_000BAE50;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    if (cpu->eax != 0u) goto label_000BAD8E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"help";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD7Du)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4BAD7Du));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0xF8u) = LIFT_CALLBACK(sfera_sub_004B9540);
    goto label_000BADB1;
    label_000BAD8E:
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count == 0u) goto label_000BADA5;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->edx + 8u) == cpu->eax) goto label_000BADB1;
    label_000BADA5:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BADACu)); sfera_sub_004BA750(cpu, LIFT_CODE_TOKEN_VA(0x4BADACu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    label_000BADB1:
    if (cpu->eax == 0u) goto label_000BAE50;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BADCFu)); sfera_sub_004AEE90(cpu, LIFT_CODE_TOKEN_VA(0x4BADCFu));
    if (cpu->eax == 0u) goto label_000BADE2;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BADD5u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000BAE50;
    label_000BADE2:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BADE9u)); sfera_sub_004AF340(cpu, LIFT_CODE_TOKEN_VA(0x4BADE9u));
    lift_push32(cpu, 0u);
    if ((cpu->eax & 0xFFu) != 0u) goto label_000BAE21;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    cpu->eax = *(uint32_t*)(cpu->edx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xA8Fu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BAE21:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xA8Fu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BAE50:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BAE60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((((cpu->edx & 0xFFu)) & (2u)) != 0u) goto label_000BAF02;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x24u);
    if (*(uint32_t*)(cpu->eax) == cpu->ebx) goto label_000BAF02;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x3Cu);
    if (cpu->edx < cpu->eax) goto label_000BAEB5;
    cpu->eax = cpu->edx;
    label_000BAEB5:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edi = 0xFu;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAED8u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BAED8u));
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebx;
    label_000BAEDC:
    cpu->edx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAEF0u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4BAEF0u));
    if (*(uint32_t*)(cpu->esp + 0x28u) < 0x10u) goto label_000BAF83;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    goto label_000BAF7B;
    label_000BAF02:
    if ((((cpu->edx & 0xFFu)) & (4u)) != 0u) goto label_000BAF42;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (*(uint32_t*)(cpu->edx) == cpu->ebx) goto label_000BAF42;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax += *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edi = 0xFu;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAF38u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BAF38u));
    *(uint32_t*)(cpu->esp + 0x58u) = 1u;
    goto label_000BAEDC;
    label_000BAF42:
    cpu->edi = 0xFu;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x30u) = cpu->ebx & 0xFFu;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 2u;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAF6Fu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4BAF6Fu));
    if (*(uint32_t*)(cpu->esp + 0x44u) < 0x10u) goto label_000BAF83;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    label_000BAF7B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAF80u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BAF80u));
    cpu->esp += 4u;
    label_000BAF83:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BAFB0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[3];
    cpu->esp -= 0x60u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    if (cpu->ebx != 0x7Bu) goto label_000BAFE3;
    if (g_sfera_direct_input_runtime.keyboard_state[0x1D] == 0u) goto label_000BAFF4;
    g_sfera_interface_runtime.primary_gate = (uint8_t)(g_sfera_interface_runtime.primary_gate) == 0u;
    goto label_000BAFF4;
    label_000BAFE3:
    if (cpu->ebx != 0x70u) goto label_000BAFF4;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uintptr_t)"Language\\helpindex.hts";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBAFF4u)); sfera_sub_004BAD10(cpu, LIFT_CODE_TOKEN_RVA(0xBAFF4u));
    label_000BAFF4:
    if (g_sfera_interface_runtime.primary_gate == 0u) goto label_000BB737;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (g_sfera_client_process_runtime.ui_bridge == cpu->esi) goto label_000BB039;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state;
    if (cpu->ecx == cpu->esi) goto label_000BB039;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_07;
    if (cpu->eax == cpu->esi) goto label_000BB039;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x50u) = 0xFu;
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0xBB031u));
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state) = cpu->esi;
    label_000BB039:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB03Eu)); sfera_sub_004A1DB0(cpu, LIFT_CODE_TOKEN_VA(0x4BB03Eu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB04E;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB047u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4BB047u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB04Eu)); sfera_sub_004A1FA0(cpu, LIFT_CODE_TOKEN_RVA(0xBB04Eu));
    label_000BB04E:
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB054u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4BB054u));
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x14u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint8_t*)(cpu->esp + 0x45u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->eax&=1u; lift_test[0]=cpu->eax==0u;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)g_sfera_interface_runtime.previous_input_modifiers));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->ebx = 4u;
    if (lift_test[0]) goto label_000BB0B3;
    if ((((cpu->edx & 0xFFu)) & (1u)) != 0u) goto label_000BB0B3;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 1u;
    goto label_000BB0C0;
    label_000BB0B3:
    if (cpu->eax != cpu->esi) goto label_000BB0C0;
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000BB0C0;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    label_000BB0C0:
    cpu->esi = 2u;
    cpu->eax = cpu->ecx;
    cpu->eax&=cpu->esi; lift_test[1]=cpu->eax==0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 6u;
    if (lift_test[1]) goto label_000BB0DA;
    if ((((cpu->edx & 0xFFu)) & (2u)) != 0u) goto label_000BB0DA;
    *(uint32_t*)(cpu->esp + 0x40u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x40u)) | (uint64_t)(cpu->esi);
    goto label_000BB0E7;
    label_000BB0DA:
    if (cpu->eax != 0u) goto label_000BB0E7;
    if ((((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_000BB0E7;
    *(uint32_t*)(cpu->esp + 0x40u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x40u)) | (uint64_t)(cpu->edi);
    label_000BB0E7:
    sub_pred[1] = (uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x2A]) == 0u;
    g_sfera_interface_runtime.previous_input_modifiers = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0u;
    if (sub_pred[1]) goto label_000BB106;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 1u;
    label_000BB106:
    if (g_sfera_direct_input_runtime.keyboard_state[0x36] == 0u) goto label_000BB113;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->esi);
    label_000BB113:
    if (g_sfera_direct_input_runtime.keyboard_state[0x1D] == 0u) goto label_000BB120;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->ebx);
    label_000BB120:
    if (g_sfera_direct_input_runtime.modifier_08 == 0u) goto label_000BB12D;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->edi);
    label_000BB12D:
    if (g_sfera_direct_input_runtime.keyboard_state[0x38] == 0u) goto label_000BB13B;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(0x10u);
    label_000BB13B:
    if (g_sfera_direct_input_runtime.modifier_20 == 0u) goto label_000BB149;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(0x20u);
    label_000BB149:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ebx = *(uint32_t*)(cpu->edx);
    if (cpu->ebx == cpu->edx) goto label_000BB245;
    label_000BB160:
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ebp = *(uint32_t*)(cpu->ebx);
    if (*(uint8_t*)(cpu->edi + 0xE1u) == 0u) goto label_000BB237;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xACu);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000BB1C3;
    label_000BB180:
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax == cpu->edx) goto label_000BB1B9;
    label_000BB190:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BB19D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BB190;
    goto label_000BB1B9;
    label_000BB19D:
    if (*(uint8_t*)(cpu->ecx + 0xE0u) != 0u) goto label_000BB1B9;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x78u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB1B9:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->edi + 0xACu)) goto label_000BB180;
    label_000BB1C3:
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    if (*(uint32_t*)(cpu->edi + 0xD8u) == 0u) goto label_000BB1E9;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(0x%X) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB1DAu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB1DAu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB1E0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB1E0u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 0xCu;
    label_000BB1E9:
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->ebx = cpu->edx;
    if (cpu->esi == cpu->edx) goto label_000BB217;
    label_000BB1F1:
    if (*(uint32_t*)(cpu->esi + 8u) != cpu->edi) goto label_000BB211;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB206u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BB206u));
    cpu->esp += 4u;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    goto label_000BB213;
    label_000BB211:
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000BB213:
    if (cpu->esi != cpu->ebx) goto label_000BB1F1;
    label_000BB217:
    cpu->edx = 0x283u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB226u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB226u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB237:
    cpu->ebx = cpu->ebp;
    if (cpu->ebp != cpu->edx) goto label_000BB160;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    label_000BB245:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ebx) goto label_000BB2C5;
    label_000BB255:
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000BB2B9;
    if (*(uint8_t*)(cpu->esi + 0x10Cu) != 0u) goto label_000BB2C1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000BB28D;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB28Du)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBB28Du));
    label_000BB28D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax > (int32_t)cpu->ebp) goto label_000BB2B9;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edx) goto label_000BB2B9;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    if ((int32_t)cpu->ecx > (int32_t)cpu->eax) goto label_000BB2B9;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000BB2C1;
    label_000BB2B9:
    cpu->eax = cpu->edi;
    if (cpu->eax != cpu->ebx) goto label_000BB255;
    goto label_000BB2C5;
    label_000BB2C1:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_000BB2C5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB2CAu)); sfera_sub_004A1DB0(cpu, LIFT_CODE_TOKEN_VA(0x4BB2CAu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB30B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB2D3u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4BB2D3u));
    if (*(uint8_t*)(cpu->eax + 0x48u) != 0u) goto label_000BB30B;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->esi) goto label_000BB311;
    label_000BB2F0:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x10Cu) != 0u) goto label_000BB305;
    if (cpu->eax != cpu->esi) goto label_000BB2F0;
    goto label_000BB311;
    label_000BB305:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    goto label_000BB311;
    label_000BB30B:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB311:
    if (((*(uint8_t*)(cpu->esp + 0x40u)) & (1u)) == 0u) goto label_000BB3BC;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx == 0u) goto label_000BB3BC;
    if (*(uint8_t*)(cpu->ecx + 0x4Du) == 0u) goto label_000BB3BC;
    if (*(uint8_t*)(cpu->ecx + 0x4Fu) != 0u) goto label_000BB3BC;
    if (*(uint8_t*)(cpu->ecx + 0x48u) != 0u) goto label_000BB3BC;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax == cpu->edx) goto label_000BB37D;
    label_000BB348:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BB355;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BB348;
    goto label_000BB37D;
    label_000BB355:
    if (cpu->eax == cpu->edx) goto label_000BB37D;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB36Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BB36Eu));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 4u;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    label_000BB37D:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = cpu->edx + 4u;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB394u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BB394u));
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->edx >= 1u) goto label_000BB3AF;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BB37Du), "std::length_error");
    label_000BB3AF:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_000BB3BC:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB3C1u)); sfera_sub_004A1DB0(cpu, LIFT_CODE_TOKEN_VA(0x4BB3C1u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB3EE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB3CAu)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4BB3CAu));
    if (*(uint8_t*)(cpu->eax + 0x48u) != 0u) goto label_000BB3EE;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count == 0u) goto label_000BB3E7;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint32_t*)(cpu->ecx + 8u) == cpu->eax) goto label_000BB3EE;
    label_000BB3E7:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB3EEu)); sfera_sub_004BA750(cpu, LIFT_CODE_TOKEN_RVA(0xBB3EEu));
    label_000BB3EE:
    sub_pred[2] = (uint8_t)(*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) == 0u;
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    if (sub_pred[2]) goto label_000BB5EE;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000BB481;
    cpu->ebx = 0x6Eu;
    cpu->ebp = 0u;
    label_000BB412:
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x4Cu) == 0u) goto label_000BB477;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000BB44B;
    if (((*(uint8_t*)(cpu->esi + 0x94u)) & (2u)) != 0u) goto label_000BB477;
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB442u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4BB442u));
    *(uint32_t*)(cpu->esi + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x94u)) | (uint64_t)(2u);
    goto label_000BB477;
    label_000BB44B:
    if (((*(uint8_t*)(cpu->esi + 0x94u)) & (2u)) == 0u) goto label_000BB477;
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0x6Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB470u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4BB470u));
    *(uint32_t*)(cpu->esi + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x94u)) & (uint64_t)(0xFFFFFFFDu);
    label_000BB477:
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) goto label_000BB412;
    label_000BB481:
    if (((*(uint8_t*)(cpu->esp + 0x40u)) & (4u)) == 0u) goto label_000BB5EE;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = 0u;
    if (cpu->ecx == cpu->esi) goto label_000BB4B5;
    if (*(uint8_t*)(cpu->ecx + 0x4Cu) == 0u) goto label_000BB4B5;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->hitTest(cpu);
    if (cpu->eax != 0u) goto label_000BB599;
    label_000BB4B5:
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) < 0x40u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = 0xDu;
    if (sub_pred[0]) goto label_000BB514;
    if (cpu->ecx == cpu->esi) goto label_000BB50E;
    label_000BB4F3:
    ++cpu->eax;
    if (cpu->edx > cpu->eax) goto label_000BB4FA;
    cpu->eax = 0u;
    label_000BB4FA:
    if ((--cpu->ecx) != 0u) goto label_000BB4FF;
    cpu->eax = 0u;
    label_000BB4FF:
    if (cpu->ecx != cpu->esi) goto label_000BB4F3;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = cpu->ecx;
    label_000BB50E:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) = cpu->esi;
    label_000BB514:
    cpu->esi = cpu->ecx + 1u;
    if (cpu->edx > cpu->esi) goto label_000BB538;
    lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB527u)); sfera_sub_0049FBD0(cpu, LIFT_CODE_TOKEN_VA(0x4BB527u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    label_000BB538:
    cpu->esi = cpu->eax + cpu->ecx;
    if (cpu->edx > cpu->esi) goto label_000BB541;
    cpu->esi -= cpu->edx;
    label_000BB541:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    if (*(uint32_t*)(cpu->edx + (cpu->esi * 4u)) != 0u) goto label_000BB56E;
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB554u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB554u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000BB623;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->eax;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    label_000BB56E:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->edi == 0u) goto label_000BB58C;
    cpu->esi = cpu->esp + 0x50u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    label_000BB58C:
    ++cpu->ecx;
    g_sfera_interface_core_runtime.state_01 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) + 1u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = cpu->ecx;
    label_000BB599:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000BB5E9;
    cpu->ebp = 0xFFFFFFFDu;
    cpu->ebx = cpu->ebp + 0x72u;
    label_000BB5B0:
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (((*(uint8_t*)(cpu->esi + 0x94u)) & (2u)) == 0u) goto label_000BB5E3;
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = 0u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB5D8u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4BB5D8u));
    *(uint32_t*)(cpu->esi + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x94u)) & (uint64_t)(cpu->ebp);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB5E3:
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != cpu->eax) goto label_000BB5B0;
    label_000BB5E9:
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    label_000BB5EE:
    if (*(uint8_t*)(cpu->esp + 0x48u) != 0x1Bu) goto label_000BB677;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->edi) goto label_000BB677;
    label_000BB604:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx >>= 3u;
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000BB61B;
    if (*(uint8_t*)(cpu->esi + 0x48u) == 0u) goto label_000BB651;
    label_000BB61B:
    cpu->eax = cpu->ecx;
    if (cpu->eax != cpu->edi) goto label_000BB604;
    goto label_000BB677;
    label_000BB623:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB651u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xBB651u));
    label_000BB651:
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x54u) = 0u;
    *(uint32_t*)(cpu->esp + 0x58u) = 0x64u;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB677u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xBB677u));
    label_000BB677:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = 0u;
    g_sfera_texture_cache_runtime.render_gate = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if (cpu->edi == *(uint32_t*)(cpu->edi)) goto label_000BB70E;
    label_000BB6A0:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000BB6B4;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    label_000BB6B4:
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000BB6D2;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000BB6D2;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BB6D2:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000BB6E2;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    label_000BB6E2:
    if (*(uint8_t*)(cpu->esi + 0xE0u) == 0u) goto label_000BB6F2;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB6F2u)); sfera_sub_004D1C50(cpu, LIFT_CODE_TOKEN_RVA(0xBB6F2u));
    label_000BB6F2:
    if (*(uint32_t*)(cpu->esi + 0xF8u) == 0u) goto label_000BB702;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB702u)); sfera_sub_004D3360(cpu, LIFT_CODE_TOKEN_RVA(0xBB702u));
    label_000BB702:
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_000BB6A0;
    label_000BB70E:
    if (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready != 0u) goto label_000BB726;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB726u)); sfera_sub_004CF7C0(cpu, LIFT_CODE_TOKEN_RVA(0xBB726u));
    label_000BB726:
    if (*(uint8_t*)(cpu->esp + 0x13u) == 0u) goto label_000BB734;
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = 0u;
    label_000BB734:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BB737:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x60u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BB750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi >= 0x64u) goto label_000BB786;
    if (cpu->esi == 0xAu) goto label_000BB7E6;
    if (cpu->esi == 0xEu) goto label_000BB7D1;
    lift_push32(cpu, 0x6A5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB77Du)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB77Du));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB783u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB783u));
    cpu->esp += 0x10u;
    label_000BB786:
    if (cpu->edi != 0u) goto label_000BB7A7;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB79Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB79Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7A4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB7A4u));
    cpu->esp += 0x10u;
    label_000BB7A7:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7ADu)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB7ADu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7B4u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB7B4u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB7F5;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB7D1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7DCu)); sfera_sub_004BAD10(cpu, LIFT_CODE_TOKEN_VA(0x4BB7DCu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB7E6:
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu);
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = cpu->eax & 0xFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB7F5:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BB800(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BB852;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBE71;
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->eax + 0xD8u) == 0u) goto label_000BB837;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB82Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB82Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB834u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB834u));
    cpu->esp += 0xCu;
    label_000BB837:
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB840u)); sfera_sub_004D1E20(cpu, LIFT_CODE_TOKEN_VA(0x4BB840u));
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06) = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB852:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    cpu->esi = 0u;
    if (cpu->ecx != cpu->esi) goto label_000BB87F;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"loadscreen";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB86Du)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB86Du));
    cpu->ecx = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB879u)); sfera_sub_004BA7E0(cpu, LIFT_CODE_TOKEN_VA(0x4BB879u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    label_000BB87F:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ebx = 0x400u;
    cpu->edi = 0x300u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_000BB8CC;
    cpu->eax = cpu->ebp + 0xFFFFFC00u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_000BB8D2;
    label_000BB8CC:
    cpu->ebx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    label_000BB8D2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    if ((int32_t)cpu->eax <= (int32_t)0x300u) goto label_000BB8ED;
    cpu->eax += 0xFFFFFD00u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_000BB8F3;
    label_000BB8ED:
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000BB8F3:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == cpu->esi) goto label_000BB90D;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BB92A;
    label_000BB90D:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB921u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB921u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB927u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB927u));
    cpu->esp += 0x10u;
    label_000BB92A:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB930u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB930u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB937u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB937u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB950;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BB950:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBAB5;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BB98B;
    label_000BB96E:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB982u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB982u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB988u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB988u));
    cpu->esp += 0x10u;
    label_000BB98B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB991u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB991u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB998u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB998u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB9A9;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BB9A9:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBABC;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BB9E2;
    label_000BB9C5:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9D9u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB9D9u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9DFu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB9DFu));
    cpu->esp += 0x10u;
    label_000BB9E2:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9E8u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB9E8u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9EFu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB9EFu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBA02;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBA02:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBAC3;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBA3B;
    label_000BBA1E:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA32u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA32u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA38u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA38u));
    cpu->esp += 0x10u;
    label_000BBA3B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA41u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBA41u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA48u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA48u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBA5D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBA5D:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (*(uint8_t*)(cpu->esp + 0x34u) == 0u) goto label_000BBACE;
    if (cpu->eax == 0u) goto label_000BBACA;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBA9B;
    label_000BBA7E:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA92u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA92u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA98u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA98u));
    cpu->esp += 0x10u;
    label_000BBA9B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA1u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA8u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA8u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBB26;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"english_sphere1");
    goto label_000BBB18;
    label_000BBAB5:
    cpu->esi = 0u;
    goto label_000BB96E;
    label_000BBABC:
    cpu->esi = 0u;
    goto label_000BB9C5;
    label_000BBAC3:
    cpu->esi = 0u;
    goto label_000BBA1E;
    label_000BBACA:
    cpu->esi = 0u;
    goto label_000BBA7E;
    label_000BBACE:
    if (cpu->eax == 0u) goto label_000BBB40;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBB00;
    label_000BBAE3:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAF7u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBAF7u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAFDu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBAFDu));
    cpu->esp += 0x10u;
    label_000BBB00:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB06u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBB06u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB0Du)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBB0Du));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBB26;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"russian_sphere1");
    label_000BBB18:
    lift_push32(cpu, 0xA29u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBB26:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBB44;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    goto label_000BBB46;
    label_000BBB40:
    cpu->esi = 0u;
    goto label_000BBAE3;
    label_000BBB44:
    cpu->esi = 0u;
    label_000BBB46:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    cpu->eax = 0xE7Fu;
    *(double*)(cpu->esp + 0x24u) = x87_v0;
    x87_v0 = (x87_v0) * (0.3701171875);
    *(uint64_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->esi != 0u) goto label_000BBB9B;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB92u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBB92u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB98u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBB98u));
    cpu->esp += 0x10u;
    label_000BBB9B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA1u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA8u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA8u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBBEB;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.83203125);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBBEB:
    x87_v0 = *(double*)(cpu->esp + 0x24u);
    x87_v0 = (x87_v0) * (0.2490234375);
    cpu->eax = 0xE7Fu;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->esi != 0u) goto label_000BBC38;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC2Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC2Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC35u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC35u));
    cpu->esp += 0x10u;
    label_000BBC38:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC3Eu)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBC3Eu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC45u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC45u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBC82;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.0247395833);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBC82:
    if (cpu->esi != 0u) goto label_000BBCA3;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC9Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC9Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA0u));
    cpu->esp += 0x10u;
    label_000BBCA3:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA9u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCB0u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBCB0u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBCC6;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x64u); lift_push32(cpu, 0x7D1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBCC6:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBCE2;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    goto label_000BBCE4;
    label_000BBCE2:
    cpu->esi = 0u;
    label_000BBCE4:
    if (cpu->esi != 0u) goto label_000BBD05;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCFCu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBCFCu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD02u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD02u));
    cpu->esp += 0x10u;
    label_000BBD05:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD0Bu)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBD0Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD12u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD12u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBD51;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.83203125);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBD51:
    if (cpu->esi != 0u) goto label_000BBD72;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD69u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD69u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD6Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD6Fu));
    cpu->esp += 0x10u;
    label_000BBD72:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD78u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBD78u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD7Fu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD7Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBDBC;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.0247395833);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBDBC:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBDDA;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    goto label_000BBDDC;
    label_000BBDDA:
    cpu->esi = 0u;
    label_000BBDDC:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi += 0x177u;
    if (cpu->esi != 0u) goto label_000BBE07;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBDFEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBDFEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE04u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE04u));
    cpu->esp += 0x10u;
    label_000BBE07:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE0Du)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBE0Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE14u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE14u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBE2B;
    cpu->ebp += 0x208u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBE2B:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->esi != 0u) goto label_000BBE4E;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE45u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE45u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE4Bu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE4Bu));
    cpu->esp += 0x10u;
    label_000BBE4E:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE54u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBE54u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE5Bu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE5Bu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBE71;
    lift_push32(cpu, 0x5Au); lift_push32(cpu, 0x26Cu); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBE71:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BBE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if (cpu->eax == 0u) goto label_000BBEF3;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->ecx >= 0) goto label_000BBE94;
    cpu->edi = 0u;
    goto label_000BBE9E;
    label_000BBE94:
    if ((int32_t)cpu->ecx <= (int32_t)0x64u) goto label_000BBE9E;
    cpu->edi = 0x64u;
    label_000BBE9E:
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBECF;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBEC6u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBEC6u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBECCu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBECCu));
    cpu->esp += 0x10u;
    label_000BBECF:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBED5u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBED5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBEDCu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBEDCu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBEF1;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x7D1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBEF1:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000BBEF3:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BBF00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBF32u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBF32u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_000BBFB0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_000BBF85;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBF79u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BBF79u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ecx;
    label_000BBF85:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BBFB0:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBFD5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4BBFD5u));
    lift_trap(cpu, 0x4BBFD5u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BBF9B(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBFA4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BBFA4u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBFB0u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4BBFB0u));
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBFD5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4BBFD5u));
    lift_trap(cpu, 0x4BBFD5u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BC000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->ecx == cpu->edi) goto label_000BC058;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x30u;
    cpu->ebx = 0u;
    label_000BC010:
    if (*(uint32_t*)(cpu->esi) < 0x10u) goto label_000BC021;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC01Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC01Eu));
    cpu->esp += 4u;
    label_000BC021:
    *(uint32_t*)(cpu->esi) = 0xFu;
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xFFFFFFECu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xFFFFFFE4u) < 0x10u) goto label_000BC03F;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC03Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC03Cu));
    cpu->esp += 4u;
    label_000BC03F:
    *(uint32_t*)(cpu->esi + 0xFFFFFFE4u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0xFFFFFFE0u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xFFFFFFD0u) = cpu->ebx & 0xFFu;
    cpu->esi += 0x38u;
    cpu->edx = cpu->esi + 0xFFFFFFD0u;
    if (cpu->edx != cpu->edi) goto label_000BC010;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000BC058:
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC060(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    label_000BC0A0:
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000BC11A;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000BC0E6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC0C7u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BC0C7u));
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->edi + 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBC0E6u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xBC0E6u));
    label_000BC0E6:
    cpu->esi += 0x38u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    cpu->edi += 0x38u;
    goto label_000BC0A0;
    label_000BC11A:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC0F4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->esi == cpu->edi) goto label_000BC111;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    label_000BC101:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC10Au)); sfera_sub_0040ACE0(cpu, LIFT_CODE_TOKEN_VA(0x4BC10Au));
    cpu->esi += 0x38u;
    if (cpu->esi != cpu->edi) goto label_000BC101;
    label_000BC111:
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC11Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4BC11Au));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC130(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_000BC181;
    lift_push32(cpu, cpu->ebp);
    label_000BC150:
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_000BC164;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC161u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC161u));
    cpu->esp += 4u;
    label_000BC164:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC177u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC177u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_000BC150;
    cpu->ebp = lift_pop32(cpu);
    label_000BC181:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC190(LiftCpu* cpu, uint32_t stop_address) {
    sfera_u32_to_sso_decimal(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC290(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x160u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x174u;
    cpu->ecx = (uintptr_t)"fonts.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC2D6u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4BC2D6u));
    if (cpu->eax != 0u) goto label_000BC3F8;
    cpu->ebx = 0u;
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = (uintptr_t)"NEW_FONTS_NUMBER";
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC2F2u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4BC2F2u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0x18u) <= cpu->ebx) goto label_000BC411;
    cpu->edi = cpu->ebx + 0xFu;
    cpu->ebp = cpu->ebx + 0x10u;
    label_000BC310:
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x38u;
    sfera_u32_to_sso_decimal(cpu);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 9u); lift_push32(cpu, (uintptr_t)"NEW_FONT_");
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x184u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC342u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BC342u));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x58u;
    *(uint8_t*)(cpu->esp + 0x180u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC358u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4BC358u));
    *(uint8_t*)(cpu->esp + 0x17Cu) = 2u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000BC367;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BC367:
    cpu->edx = cpu->esp + 0x70u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC372u)); sfera_sub_00448880(cpu, LIFT_CODE_TOKEN_VA(0x4BC372u));
    if (*(uint32_t*)(cpu->esp + 0x68u) < cpu->ebp) goto label_000BC385;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC382u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC382u));
    cpu->esp += 4u;
    label_000BC385:
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x54u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x30u) < cpu->ebp) goto label_000BC3A4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC3A1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC3A1u));
    cpu->esp += 4u;
    label_000BC3A4:
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x17Cu) = 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) < cpu->ebp) goto label_000BC3CE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC3CBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC3CBu));
    cpu->esp += 4u;
    label_000BC3CE:
    cpu->ecx = cpu->esp + 0x70u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC3E3u)); sfera_sub_004BA910(cpu, LIFT_CODE_TOKEN_VA(0x4BC3E3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esp + 0x18u)) goto label_000BC310;
    goto label_000BC411;
    label_000BC3F8:
    cpu->eax = (uintptr_t)"fonts.cfg";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"File '%s' doesn't exists.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC408u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BC408u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC40Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BC40Eu));
    cpu->esp += 0xCu;
    label_000BC411:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x16Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC480(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x34u;
    if (cpu->edi != 0u) goto label_000BC4BB;
    cpu->eax = 0u;
    goto label_000BC5D1;
    label_000BC4BB:
    cpu->ebp = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->esi = *(uint32_t*)(cpu->ebp);
    if (cpu->esi == cpu->ebp) goto label_000BC519;
    label_000BC4D0:
    cpu->eax = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_000BC4DB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BC4DB:
    cpu->ecx = cpu->edi;
    label_000BC4E0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000BC500;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000BC4FC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000BC500;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BC4E0;
    label_000BC4FC:
    cpu->eax = 0u;
    goto label_000BC505;
    label_000BC500:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000BC505:
    if (cpu->eax == 0u) goto label_000BC511;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->ebp) goto label_000BC4D0;
    goto label_000BC519;
    label_000BC511:
    if (cpu->esi != cpu->ebp) goto label_000BC5BE;
    label_000BC519:
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    *(uint8_t*)(cpu->esp + 0xCu) = 0u;
    cpu->eax = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0u;
    cpu->edx = cpu->eax + 1u;
    label_000BC540:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BC540;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC554u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BC554u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC580u)); sfera_sub_004BBF00(cpu, LIFT_CODE_TOKEN_VA(0x4BC580u));
    cpu->edx = 0x71C71C6u;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11);
    if (cpu->edx >= 1u) goto label_000BC59B;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BC540u), "std::length_error");
    label_000BC59B:
    g_sfera_interface_core_runtime.state_11 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    if (*(uint32_t*)(cpu->esp + 0x20u) < 0x10u) goto label_000BC5CC;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC5B9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC5B9u));
    cpu->esp += 4u;
    goto label_000BC5CC;
    label_000BC5BE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ecx;
    label_000BC5CC:
    cpu->eax = 1u;
    label_000BC5D1:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC5F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000BC619;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBC619u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBC619u));
    label_000BC619:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u;
    cpu->edx = cpu->esi + 8u;
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000BC633;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_000BC633:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC63Du)); sfera_sub_004BC480(cpu, LIFT_CODE_TOKEN_VA(0x4BC63Du));
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC650(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1]; double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x40u;
    cpu->ebx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11) == 0u) goto label_000BC69D;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBC69Du)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_RVA(0xBC69Du));
    label_000BC69D:
    if (cpu->ebx == 0u) goto label_000BC807;
    if (cpu->esi == 0u) goto label_000BC807;
    if (*(uint32_t*)(cpu->esi) != 0x31564955u) goto label_000BC807;
    cpu->ebp = 0u;
    cpu->edi = cpu->esi + 4u;
    if (cpu->ebx == 0u) goto label_000BC807;
    label_000BC6C6:
    cpu->eax = 0u;
    cpu->ecx = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    if (*(uint8_t*)(cpu->edi) == (cpu->eax & 0xFFu)) goto label_000BC77B;
    goto label_000BC6EB;
    label_000BC6E7:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000BC6EB:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    if (cpu->edx <= 1u) goto label_000BC826;
    cpu->esi = cpu->eax + 1u;
    if (cpu->esi > 0xFFFFFFFEu) goto label_000BC826;
    if (cpu->ecx >= cpu->esi) goto label_000BC718;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC716u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x4BC716u));
    goto label_000BC730;
    label_000BC718:
    lift_test[0]=cpu->esi==0u;
    if (cpu->esi!=0u) goto label_000BC736;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if (cpu->ecx >= 0x10u) goto label_000BC72D;
    cpu->eax = cpu->esp + 0x18u;
    label_000BC72D:
    *(uint8_t*)(cpu->eax) = 0u;
    label_000BC730:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_test[0]=cpu->esi==0u;
    label_000BC736:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((!lift_test[0]) ? 1u : 0u) & 0xFFu);
    if ((cpu->ecx & 0xFFu) == 0u) goto label_000BC76D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) >= cpu->edx) goto label_000BC750;
    cpu->ecx = cpu->esp + 0x18u;
    label_000BC750:
    *(uint8_t*)(cpu->ecx + cpu->eax) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) >= cpu->edx) goto label_000BC765;
    cpu->eax = cpu->esp + 0x18u;
    label_000BC765:
    *(uint8_t*)(cpu->eax + cpu->esi) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_000BC76D:
    ++cpu->edi;
    if (*(uint8_t*)(cpu->edi) != 0u) goto label_000BC6E7;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000BC77B:
    x87_v0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 1u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 5u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_10;
    cpu->edi += 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC7BEu)); sfera_sub_004BBF00(cpu, LIFT_CODE_TOKEN_VA(0x4BC7BEu));
    cpu->ecx = 0x71C71C6u;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11);
    if (cpu->ecx < 1u) goto label_000BC831;
    g_sfera_interface_core_runtime.state_11 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11)) + 1u;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x2Cu) < 0x10u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->ebp = cpu->edx + cpu->ebp + 9u;
    *(uint32_t*)(cpu->esp + 0x48u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_000BC7FF;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC7FCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC7FCu));
    cpu->esp += 4u;
    label_000BC7FF:
    if (cpu->ebp < cpu->ebx) goto label_000BC6C6;
    label_000BC807:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BC826:
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BC826u), "std::length_error");
    label_000BC831:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BC831u), "std::length_error");
    lift_trap(cpu, 0x4BC83Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BC840(LiftCpu* cpu, uint32_t stop_address) {
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
    if (cpu->ebx <= 0x4924924u) goto label_000BC883;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BC840u), "std::length_error");
    label_000BC883:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= cpu->ebx) goto label_000BC92A;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC8AEu)); sfera_sub_004B8AA0(cpu, LIFT_CODE_TOKEN_VA(0x4BC8AEu));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC8CAu)); sfera_sub_004BC060(cpu, LIFT_CODE_TOKEN_VA(0x4BC8CAu));
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ecx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx == 0u) goto label_000BC904;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC8F9u)); sfera_sub_004BC000(cpu, LIFT_CODE_TOKEN_VA(0x4BC8F9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC901u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC901u));
    cpu->esp += 4u;
    label_000BC904:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = cpu->eax + (cpu->ecx * 8u);
    cpu->ecx = cpu->edi * 8u;
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->edx = cpu->eax + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_000BC92A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC93E(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC947u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BC947u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC953u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4BC953u));
    lift_trap(cpu, 0x4BC953u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BC960(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->esi))) >> 32u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = 0x4924924u;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->esi) goto label_000BC996;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BC960u), "std::length_error");
    label_000BC996:
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->esi <= cpu->eax) goto label_000BC9DC;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->edi = 0x4924924u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000BC9C8;
    cpu->eax = 0u;
    goto label_000BC9CA;
    label_000BC9C8:
    cpu->eax += cpu->edx;
    label_000BC9CA:
    if (cpu->eax >= cpu->esi) goto label_000BC9D0;
    cpu->eax = cpu->esi;
    label_000BC9D0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    sfera_sub_004BC840(cpu, stop_address); return;
    label_000BC9DC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC9F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->ecx == 0u) goto label_000BCA24;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x1DCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1D4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCA15u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4BCA15u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCA21u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCA21u));
    cpu->esp += 4u;
    label_000BCA24:
    *(uint32_t*)(cpu->esi + 0x1D0u) = 0u;
    *(uint32_t*)(cpu->esi + 0x1D4u) = 0u;
    *(uint32_t*)(cpu->esi + 0x1D8u) = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004D37D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004BCA50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi >= cpu->ecx) goto label_000BCAAC;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax > cpu->edi) goto label_000BCAAC;
    cpu->edi -= cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 8u)) goto label_000BCA88;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBCA88u)); sfera_sub_004BC960(cpu, LIFT_CODE_TOKEN_RVA(0xBCA88u));
    label_000BCA88:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->edi * 8u;
    cpu->eax -= cpu->edi;
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCAA3u)); sfera_sub_004B9BB0(cpu, LIFT_CODE_TOKEN_VA(0x4BCAA3u));
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0x38u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BCAAC:
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 8u)) goto label_000BCABA;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBCABAu)); sfera_sub_004BC960(cpu, LIFT_CODE_TOKEN_RVA(0xBCABAu));
    label_000BCABA:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCAC4u)); sfera_sub_004B9C50(cpu, LIFT_CODE_TOKEN_VA(0x4BCAC4u));
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0x38u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BCAD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x80u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x94u;
    cpu->ebx = 0u;
    cpu->edi = 0xFu;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"null");
    cpu->ecx = cpu->esp + 0x60u;
    *(uint32_t*)(cpu->esp + 0xA4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB44u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCB44u));
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"NULL");
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB54u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCB54u));
    lift_push32(cpu, 0x32u);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB60u)); sfera_sub_004BC840(cpu, LIFT_CODE_TOKEN_VA(0x4BCB60u));
    cpu->eax = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB6Fu)); sfera_sub_004BCA50(cpu, LIFT_CODE_TOKEN_VA(0x4BCB6Fu));
    cpu->edx = 0x1BCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB7Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCB7Eu));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB88u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BCB88u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x9Cu) = 1u;
    if (cpu->eax == cpu->ebx) goto label_000BCBA6;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCBA2u)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x4BCBA2u));
    cpu->esi = cpu->eax;
    goto label_000BCBA8;
    label_000BCBA6:
    cpu->esi = 0u;
    label_000BCBA8:
    cpu->ecx = (uintptr_t)"Language\\strings.ui";
    *(uint8_t*)(cpu->esp + 0x9Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCBB9u)); sfera_sub_004B8150(cpu, LIFT_CODE_TOKEN_VA(0x4BCBB9u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCBC1u)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x4BCBC1u));
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"stringsUI");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCBD5u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4BCBD5u));
    cpu->ebp = 0x10u;
    if (cpu->eax == 0u) goto label_000BCCF0;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCBEEu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4BCBEEu));
    lift_push32(cpu, (uintptr_t)"string");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCBFAu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCBFAu));
    if (cpu->eax == 0u) goto label_000BCCE9;
    label_000BCC02:
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0]); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC0Fu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4BCC0Fu));
    if (cpu->eax == 0u) goto label_000BCCD5;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0]); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC25u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4BCC25u));
    if (cpu->eax == 0u) goto label_000BCCD5;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    cpu->eax = (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0];
    *(uint8_t*)(cpu->esp + 0x9Cu) = 2u;
    cpu->edx = cpu->eax + 1u;
    label_000BCC55:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BCC55;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0]);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC6Du)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCC6Du));
    cpu->eax = (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0];
    cpu->edx = cpu->eax + 1u;
    label_000BCC75:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BCC75;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0]);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC8Du)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCC8Du));
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC9Cu)); sfera_sub_004BCA50(cpu, LIFT_CODE_TOKEN_VA(0x4BCC9Cu));
    *(uint8_t*)(cpu->esp + 0x9Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->ebp) goto label_000BCCB6;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCCB3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCCB3u));
    cpu->esp += 4u;
    label_000BCCB6:
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->ebp) goto label_000BCCD5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCCD2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCCD2u));
    cpu->esp += 4u;
    label_000BCCD5:
    lift_push32(cpu, (uintptr_t)"string");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCCE1u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCCE1u));
    if (cpu->eax != 0u) goto label_000BCC02;
    label_000BCCE9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBCCF0u)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_RVA(0xBCCF0u));
    label_000BCCF0:
    cpu->edx = 0x1DBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCCFFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCCFFu));
    if (cpu->esi == cpu->ebx) goto label_000BCD13;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCD0Au)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4BCD0Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCD10u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCD10u));
    cpu->esp += 4u;
    label_000BCD13:
    if (*(uint32_t*)(cpu->esp + 0x88u) < cpu->ebp) goto label_000BCD29;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCD26u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCD26u));
    cpu->esp += 4u;
    label_000BCD29:
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x6Cu) < cpu->ebp) goto label_000BCD4E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCD4Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCD4Bu));
    cpu->esp += 4u;
    label_000BCD4E:
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BCD80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->ebx = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04 == cpu->ebx) goto label_000BCDBF;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BCDBF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDC4u)); sfera_sub_004A4B10(cpu, LIFT_CODE_TOKEN_VA(0x4BCDC4u));
    cpu->ecx = (uintptr_t)"control.cfg";
    g_sfera_interface_runtime.cross_enabled = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDD8u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4BCDD8u));
    cpu->edx = (uintptr_t)&g_sfera_interface_runtime.cross_enabled;
    cpu->ecx = (uintptr_t)"EN_CROSS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDE7u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4BCDE7u));
    cpu->edx = (uintptr_t)&g_sfera_interface_runtime.sounds_enabled;
    cpu->ecx = (uintptr_t)"INTFS_SOUNDS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDF6u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4BCDF6u));
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02 != cpu->ebx) goto label_000BCE4F;
    cpu->edx = 0x364u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE0Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE0Du));
    lift_push32(cpu, 0x314u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE17u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE17u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->eax == cpu->ebx) goto label_000BCE2F;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE2Du)); sfera_sub_004A17F0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE2Du));
    goto label_000BCE31;
    label_000BCE2F:
    cpu->eax = 0u;
    label_000BCE31:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE45u)); sfera_sub_004A18E0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE45u));
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    label_000BCE4F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE54u)); sfera_sub_004BC290(cpu, LIFT_CODE_TOKEN_VA(0x4BCE54u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == cpu->ebx) goto label_000BCE92;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->ecx + 8u) = 0xFFu;
    *(uint8_t*)(cpu->ecx + 1u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE6Eu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4BCE6Eu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    if (cpu->ecx == cpu->ebx) goto label_000BCE92;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE8Cu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4BCE8Cu));
    g_sfera_ui_load_scratch_runtime.cursor_name[0] = (uint8_t)((cpu->ebx & 0xFFu));
    label_000BCE92:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE97u)); sfera_sub_004BCAD0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE97u));
    lift_push32(cpu, (uintptr_t)"Effects\\loadscreen.ui");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEA1u)); sfera_sub_004BA190(cpu, LIFT_CODE_TOKEN_VA(0x4BCEA1u));
    lift_push32(cpu, (uintptr_t)"Effects\\sprites.ui");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEABu)); sfera_sub_004B8850(cpu, LIFT_CODE_TOKEN_VA(0x4BCEABu));
    cpu->ecx = 0xFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEB5u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BCEB5u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEBAu)); sfera_sub_004B9F40(cpu, LIFT_CODE_TOKEN_VA(0x4BCEBAu));
    cpu->ecx = 0x1Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC4u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC9u)); sfera_sub_004BA370(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC9u));
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = cpu->ebx & 0xFFu;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) = 1u;
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BCEF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04 != cpu->edi) goto label_000BCF01;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BCF01:
    lift_push32(cpu, cpu->esi);
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02 == cpu->edi) goto label_000BCF39;
    cpu->edx = 0x392u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF19u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCF19u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_000BCF33;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF2Au)); sfera_sub_004A1860(cpu, LIFT_CODE_TOKEN_VA(0x4BCF2Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF30u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCF30u));
    cpu->esp += 4u;
    label_000BCF33:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02) = cpu->edi;
    label_000BCF39:
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF48u)); sfera_sub_004B94A0(cpu, LIFT_CODE_TOKEN_VA(0x4BCF48u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF4Du)); sfera_sub_004B9410(cpu, LIFT_CODE_TOKEN_VA(0x4BCF4Du));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF52u)); sfera_sub_004B9390(cpu, LIFT_CODE_TOKEN_VA(0x4BCF52u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF57u)); sfera_sub_004A5460(cpu, LIFT_CODE_TOKEN_VA(0x4BCF57u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    if (cpu->eax == cpu->ecx) goto label_000BCF92;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF73u)); sfera_sub_004BA8C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCF73u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_core_runtime.object_aux);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF8Cu)); sfera_sub_004BC000(cpu, LIFT_CODE_TOKEN_VA(0x4BCF8Cu));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count) = cpu->esi;
    label_000BCF92:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF97u)); sfera_sub_004B9B10(cpu, LIFT_CODE_TOKEN_VA(0x4BCF97u));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) = cpu->edi;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08 == cpu->edi) goto label_000BCFE3;
    cpu->edx = 0x3A4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCFB4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCFB4u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    if (cpu->eax == cpu->edi) goto label_000BCFDD;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CF160)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x98u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCFD4u)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x4BCFD4u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCFDAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BCFDAu));
    cpu->esp += 4u;
    label_000BCFDD:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = cpu->edi;
    label_000BCFE3:
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = cpu->edi;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BD000(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000BD32A;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000BD32A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->ebp) goto label_000BD066;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebp;
    if (cpu->ecx == cpu->ebp) goto label_000BD058;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBD058u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBD058u));
    label_000BD058:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000BD066:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->ebx += cpu->ecx;
    if (cpu->eax == cpu->ebp) goto label_000BD0C3;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->eax + 0xDCu) == cpu->edx) goto label_000BD0B6;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if ((int32_t)cpu->edx >= 0) goto label_000BD09F;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD09F:
    x87_v0 = (x87_v0) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000BD0B6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000BD0C3:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    if (cpu->ecx == cpu->ebp) goto label_000BD113;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000BD106;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if ((int32_t)cpu->eax >= 0) goto label_000BD0EF;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD0EF:
    x87_v0 = (x87_v0) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000BD106:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000BD113:
    if (*(uint32_t*)(cpu->esi + 0x198u) == cpu->ebp) goto label_000BD327;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_000BD135;
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->edi = 0u;
    label_000BD135:
    if ((int32_t)cpu->ebx >= 0) goto label_000BD13D;
    cpu->ebp += cpu->ebx;
    cpu->ebx = 0u;
    label_000BD13D:
    cpu->ecx = cpu->eax + cpu->edi;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    if ((int32_t)cpu->ecx <= (int32_t)cpu->eax) goto label_000BD14F;
    cpu->eax -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000BD14F:
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = cpu->ebx + cpu->ebp;
    if ((int32_t)cpu->edx <= (int32_t)cpu->eax) goto label_000BD15F;
    cpu->eax -= cpu->ebx;
    cpu->ebp = cpu->eax;
    label_000BD15F:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD1A1u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4BD1A1u));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = 1.0;
    cpu->edx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD1D1u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4BD1D1u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1E0u);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x1B4u)) goto label_000BD2C4;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x1B8u)) goto label_000BD2C4;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1DCu);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->eax + 0x34u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x28u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if (cpu->ecx==0u) goto label_000BD27B;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    cpu->ebp += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    if ((int32_t)(cpu->ebp) >= 0) goto label_000BD242;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD242:
    cpu->esp -= 0x10u;
    cpu->ebx += cpu->edx;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    if ((int32_t)(cpu->ebx) >= 0) goto label_000BD25B;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD25B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1DCu);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD279u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_VA(0x4BD279u));
    goto label_000BD2C4;
    label_000BD27B:
    cpu->ebp += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    if ((int32_t)(cpu->ebp) >= 0) goto label_000BD28D;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD28D:
    cpu->esp -= 0x10u;
    cpu->ebx += cpu->edx;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    if ((int32_t)(cpu->ebx) >= 0) goto label_000BD2A6;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD2A6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBD2C4u)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_RVA(0xBD2C4u));
    label_000BD2C4:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1B4u);
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->esi + 0x1B8u)) goto label_000BD2EB;
    label_000BD2D2:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 0x1B8u)) goto label_000BD2D2;
    label_000BD2EB:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD2FBu)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4BD2FBu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1B4u);
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->esi + 0x1B8u)) goto label_000BD327;
    label_000BD310:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD31Eu)); sfera_sub_004D2810(cpu, LIFT_CODE_TOKEN_VA(0x4BD31Eu));
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 0x1B8u)) goto label_000BD310;
    label_000BD327:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000BD32A:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BD340(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x6Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x78u);
    cpu->ebx = cpu->ecx;
    sub_pred[0] = *(uint8_t*)(cpu->ebx + 0x48u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if (!sub_pred[0]) goto label_000BD6BA;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1D0u);
    if (cpu->ecx == 0u) goto label_000BD376;
    lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BD376:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1D4u);
    if (cpu->ecx == 0u) goto label_000BD388;
    lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BD388:
    if (*(uint8_t*)(cpu->ebx + 0x1D9u) != 0u) goto label_000BD39B;
    *(uint32_t*)(cpu->ebx + 0x1E0u) = 0xFFFFFFFFu;
    label_000BD39B:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1A0u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xD8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = 0xFA1u;
    if (cpu->ecx == 0u) goto label_000BD44E;
    label_000BD3D0:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD3E5u)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4BD3E5u));
    if (cpu->eax==0u) goto label_000BD43A;
    cpu->ebp = cpu->edi & 0xFFFFu;
    label_000BD3F0:
    cpu->edx = *(uint16_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx <<= 16u;
    cpu->edx |= cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edx;
    cpu->edx = cpu->esp + 0x40u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD426u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4BD426u));
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD432u)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4BD432u));
    if (cpu->eax!=0u) goto label_000BD3F0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_000BD43A:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1A0u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx + 0x19Cu);
    ++cpu->edi;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->edi < cpu->ecx) goto label_000BD3D0;
    label_000BD44E:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    cpu->esi = 0u;
    if (cpu->edi == cpu->eax) goto label_000BD48D;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000BD47F;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBD47Fu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBD47Fu));
    label_000BD47F:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += *(uint32_t*)(cpu->esp + 0x14u);
    label_000BD48D:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    cpu->edx += cpu->esi;
    if ((int32_t)cpu->ecx < (int32_t)cpu->eax) goto label_000BD4BD;
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x28u);
    cpu->esi += cpu->eax;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_000BD4BD;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if ((int32_t)cpu->ecx < (int32_t)cpu->edx) goto label_000BD4BD;
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->esi += cpu->edx;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_000BD4BD;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    goto label_000BD4DF;
    label_000BD4BD:
    cpu->esi = cpu->ebp;
    cpu->edi = cpu->esp + 0x5Cu;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u;
    cpu->ecx = 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x5Cu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    label_000BD4DF:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x198u);
    if (cpu->ecx == 0u) goto label_000BD6B8;
    cpu->edx -= *(uint32_t*)(cpu->ebx + 0x1C4u);
    cpu->eax -= *(uint32_t*)(cpu->ebx + 0x1C0u);
    sub_pred[1] = *(uint8_t*)(cpu->ebx + 0x1E5u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (sub_pred[1]) goto label_000BD54A;
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x1B4u);
    if ((int32_t)cpu->esi >= (int32_t)*(uint32_t*)(cpu->ebx + 0x1B8u)) goto label_000BD5C3;
    label_000BD520:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD531u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4BD531u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->ebx + 0x1B8u)) goto label_000BD520;
    goto label_000BD5C3;
    label_000BD54A:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x1E4u));
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x1B4u);
    cpu->ebp = cpu->ecx & 0xFFu;
    cpu->ebp = -cpu->ebp;
    cpu->ebp = (cpu->ebp != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ebp &= cpu->edx;
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->ecx & 0xFFu)!=0u)) ? 1u : 0u) & 0xFFu);
    --cpu->edx;
    cpu->edx &= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->ebx + 0x1B8u)) goto label_000BD5BF;
    goto label_000BD584;
    label_000BD580:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_000BD584:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->ebx + 0x1B8u)) goto label_000BD580;
    label_000BD5BF:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_000BD5C3:
    if (*(uint8_t*)(cpu->ebx + 0x1D9u) == 0u) goto label_000BD6B8;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->ebp) goto label_000BD6B8;
    if (((*(uint8_t*)(cpu->ebp + 0xCu)) & (1u)) == 0u) goto label_000BD6B8;
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x1B4u);
    cpu->esi |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->ebx + 0x1B8u)) goto label_000BD680;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x19Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->ebp = cpu->eax + (cpu->edi * 4u);
    label_000BD614:
    cpu->esi = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000BD63A;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBD63Au)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBD63Au));
    label_000BD63A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->eax > (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_000BD66A;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) >= (int32_t)cpu->edx) goto label_000BD66A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->ecx > (int32_t)cpu->eax) goto label_000BD66A;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000BD678;
    label_000BD66A:
    ++cpu->edi;
    cpu->ebp += 4u;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->ebx + 0x1B8u)) goto label_000BD614;
    goto label_000BD67C;
    label_000BD678:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    label_000BD67C:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000BD680:
    if (*(uint32_t*)(cpu->ebx + 0x1E0u) == cpu->esi) goto label_000BD6B8;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xD8u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFA3u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BD6B2u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4BD6B2u));
    *(uint32_t*)(cpu->ebx + 0x1E0u) = cpu->esi;
    label_000BD6B8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BD6BA:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x6Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BD6D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ebx = 0u;
    if (cpu->ecx == cpu->ebx) goto label_000BD875;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1B0u) >= (int32_t)cpu->ebx) goto label_000BD6F5;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->ebx;
    label_000BD6F5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C8u);
    if (*(uint32_t*)(cpu->esi + 0x1B0u) <= cpu->eax) goto label_000BD709;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    label_000BD709:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1ACu) >= (int32_t)cpu->ebx) goto label_000BD717;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ebx;
    label_000BD717:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (*(uint32_t*)(cpu->esi + 0x1ACu) <= cpu->eax) goto label_000BD72B;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    label_000BD72B:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    if (*(uint8_t*)(cpu->esi + 0x1E4u) != (cpu->ebx & 0xFFu)) goto label_000BD7A0;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->ecx >= 0) goto label_000BD74B;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD74B:
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x10u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B0u)))))) / (((double)*(float*)(cpu->esp + 0x14u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(double*)(cpu->esp + 0x18u) = x87_v0;
    *(double*)(cpu->esp) = x87_v0;
    x87_v0 = std::floor(*(double*)(cpu->esp));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->esp += 8u;
    x87_v1 = x87_v0;
    x87_v1 = (*(double*)(cpu->esp + 0x10u)) - (x87_v1);
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0xCu)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ACu);
    goto label_000BD805;
    label_000BD7A0:
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    if ((int32_t)cpu->eax >= 0) goto label_000BD7B2;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BD7B2:
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x10u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1ACu)))))) / (((double)*(float*)(cpu->esp + 0x14u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    *(double*)(cpu->esp + 0x18u) = x87_v0;
    *(double*)(cpu->esp) = x87_v0;
    x87_v0 = std::floor(*(double*)(cpu->esp));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->esp += 8u;
    x87_v1 = x87_v0;
    x87_v1 = (*(double*)(cpu->esp + 0x10u)) - (x87_v1);
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0xCu)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    label_000BD805:
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->ecx = cpu->edx + cpu->eax + 1u;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->ecx <= cpu->eax) goto label_000BD83F;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    label_000BD83F:
    if (*(uint8_t*)(cpu->esi + 0x1E5u) == (cpu->ebx & 0xFFu)) goto label_000BD86E;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    label_000BD86E:
    *(uint8_t*)(cpu->esi + 0x1D8u) = 1u;
    label_000BD875:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BD880(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0xCu;
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    x87_v1 = 255.0;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    x87_v1 = (x87_v1) * (x87_v0);
    *(uint64_t*)(cpu->esp + 0xCu) = static_cast<int64_t>(std::trunc(x87_v1));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->ecx&=0xFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xDCu) = cpu->eax;
    cpu->eax <<= 24u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == 0u) goto label_000BD8E9;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    goto label_000BD8EB;
    label_000BD8E9:
    x87_v0 = x87_v0; 
    label_000BD8EB:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edi=0u;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->ecx == 0u) goto label_000BD92C;
    label_000BD900:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    ++cpu->edi;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->edi < cpu->eax) goto label_000BD900;
    label_000BD92C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BD940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1A0u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x19Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax < cpu->edx) goto label_000BD95C;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BD95C:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x19Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BD970(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (*(uint8_t*)(cpu->ebp + 0x48u) == 0u) goto label_000BD981;
    label_000BD97A:
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BD981:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1B4u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ebp + 0x1B8u)) goto label_000BD97A;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    label_000BD9A0:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x19Cu);
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    if (*(uint8_t*)(cpu->esi + 0x4Cu) == 0u) goto label_000BDA0D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000BD9D2;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBD9D2u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBD9D2u));
    label_000BD9D2:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax > (int32_t)cpu->edi) goto label_000BDA0D;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_000BDA0D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ecx > (int32_t)cpu->eax) goto label_000BDA0D;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000BDA0D;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->hitTest(cpu);
    if (cpu->eax != 0u) goto label_000BDA16;
    label_000BDA0D:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->ebp + 0x1B8u)) goto label_000BD9A0;
    label_000BDA16:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDA30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x1A0u);
    cpu->edi -= *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->esi=0u;
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    if ((int32_t)cpu->edi <= 0) goto label_000BDA7B;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    (void)cpu;
    label_000BDA50:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->edi) goto label_000BDA50;
    cpu->ebp = lift_pop32(cpu);
    label_000BDA7B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_000BDC6F;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x28u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    if (*(uint8_t*)(cpu->esi + 0x1E4u) != (cpu->ebx & 0xFFu)) goto label_000BDB11;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax = cpu->edi;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ebp); cpu->eax = n / d; cpu->edx = n % d; }
    ++cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebp);
    if (cpu->edi <= cpu->eax) goto label_000BDAF0;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ebx;
    goto label_000BDAF8;
    label_000BDAF0:
    cpu->eax -= cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000BDAF8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->eax <= cpu->ecx) goto label_000BDB07;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ebx;
    goto label_000BDB5E;
    label_000BDB07:
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ecx;
    goto label_000BDB5E;
    label_000BDB11:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax = cpu->edi;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ecx); cpu->eax = n / d; cpu->edx = n % d; }
    ++cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx);
    if (cpu->edi <= cpu->eax) goto label_000BDB3D;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ebx;
    goto label_000BDB45;
    label_000BDB3D:
    cpu->eax -= cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->eax;
    label_000BDB45:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->edi <= cpu->ebp) goto label_000BDB54;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ebx;
    goto label_000BDB5E;
    label_000BDB54:
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    label_000BDB5E:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1B0u) >= (int32_t)cpu->ebx) goto label_000BDB6C;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->ebx;
    label_000BDB6C:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    if (*(uint32_t*)(cpu->esi + 0x1B0u) <= cpu->edx) goto label_000BDB80;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->edx;
    label_000BDB80:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1ACu) >= (int32_t)cpu->ebx) goto label_000BDB8E;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ebx;
    label_000BDB8E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (*(uint32_t*)(cpu->esi + 0x1ACu) <= cpu->eax) goto label_000BDBA2;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    label_000BDBA2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->ebx = 0x17u;
    if (cpu->ecx == 0u) goto label_000BDC02;
    cpu->eax=0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)0xCCCCCCCDu * (uint32_t)(cpu->ebp)) >> 32u);
    cpu->edx >>= 3u;
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBDC02u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_RVA(0xBDC02u));
    label_000BDC02:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_000BDC68;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1CCu);
    cpu->eax=0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)0xCCCCCCCDu * (uint32_t)(cpu->edx)) >> 32u);
    cpu->edx >>= 3u;
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBDC68u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_RVA(0xBDC68u));
    label_000BDC68:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBDC6Fu)); sfera_sub_004BD6D0(cpu, LIFT_CODE_TOKEN_RVA(0xBDC6Fu));
    label_000BDC6F:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDC80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (cpu->edi != cpu->eax) goto label_000BDC9D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BDC9D:
    if (cpu->edi <= 0x3FFFFFFFu) goto label_000BDCB0;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BDC9Du), "std::length_error");
    label_000BDCB0:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BDCB9u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BDCB9u));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDCD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BDCD8u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4BDCD8u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    std::construct_at(reinterpret_cast<SphereUI::ListItemCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->eax;
    *(uint16_t*)(cpu->esi + 0x1D8u) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->eax;
    *(uint16_t*)(cpu->esi + 0x1E4u) = cpu->eax & 0xFFFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1E0u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->edi >= cpu->eax) goto label_000BDE77;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edi * 4u;
    cpu->edx = 0x1F5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BDDBEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BDDBEu));
    if (cpu->ebx == 0u) goto label_000BDDCD;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BDDCD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->edi == 0u) goto label_000BDDD9;
    cpu->ecx += cpu->ebp;
    label_000BDDD9:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax = cpu->ecx + 4u;
    cpu->edx -= cpu->eax;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4BDDEEu));
    *(uint32_t*)(cpu->esi + 0x1A0u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1A0u)) + (uint64_t)(0xFFFFFFFCu) + (uint64_t)(0u);
    cpu->esp += 0xCu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0x1E0u)) goto label_000BDE16;
    *(uint32_t*)(cpu->esi + 0x1E0u) = 0xFFFFFFFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    label_000BDE16:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (*(uint32_t*)(cpu->esi + 0x1E0u) < cpu->eax) goto label_000BDE36;
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->eax;
    goto label_000BDE3A;
    label_000BDE36:
    if ((cpu->ecx & 0xFFu) == 0u) goto label_000BDE77;
    label_000BDE3A:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    if (cpu->ecx == 0u) goto label_000BDE77;
    if (*(uint8_t*)(cpu->esi + 0x1D9u) == 0u) goto label_000BDE77;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1E0u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFA3u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBDE77u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xBDE77u));
    label_000BDE77:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDE90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->eax -= cpu->esi;
    cpu->edi = 0x3FFFFFFFu;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000BDEB6;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BDE90u), "std::length_error");
    label_000BDEB6:
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx -= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax <= cpu->edx) goto label_000BDEEA;
    cpu->esi = cpu->edx;
    cpu->esi >>= 1u;
    cpu->edi = 0x3FFFFFFFu;
    cpu->edi -= cpu->esi;
    if (cpu->edi >= cpu->edx) goto label_000BDED7;
    cpu->edx = 0u;
    goto label_000BDED9;
    label_000BDED7:
    cpu->edx += cpu->esi;
    label_000BDED9:
    if (cpu->edx >= cpu->eax) goto label_000BDEDF;
    cpu->edx = cpu->eax;
    label_000BDEDF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    sfera_sub_00429830(cpu, stop_address); return;
    label_000BDEEA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDEF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax == 0u) goto label_000BDF7F;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == 0u) goto label_000BDF4B;
    label_000BDF10:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    cpu->edx = 0x218u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BDF28u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BDF28u));
    if (cpu->edi == 0u) goto label_000BDF37;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BDF37:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x19Cu);
    ++cpu->ebx;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->ebx < cpu->ecx) goto label_000BDF10;
    label_000BDF4B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->edi == cpu->ecx) goto label_000BDF7D;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ebx = cpu->eax * 4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4BDF6Cu));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    label_000BDF7D:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000BDF7F:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BDF90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi >= cpu->eax) goto label_000BDFCF;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx > cpu->edi) goto label_000BDFCF;
    cpu->edi -= cpu->ecx;
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000BDFB8;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBDFB8u)); sfera_sub_004BDE90(cpu, LIFT_CODE_TOKEN_RVA(0xBDFB8u));
    label_000BDFB8:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000BDFE8;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BDFCF:
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000BDFDD;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBDFDDu)); sfera_sub_004BDE90(cpu, LIFT_CODE_TOKEN_RVA(0xBDFDDu));
    label_000BDFDD:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000BDFE8;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000BDFE8:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BE000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::ListItemCtrl*>(cpu->esi));
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (*(uint32_t*)(cpu->esi + 0x198u) == cpu->edi) goto label_000BE067;
    cpu->edx = cpu->edi + 0x57u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE04Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE04Eu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == cpu->edi) goto label_000BE061;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BE061:
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->edi;
    label_000BE067:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE06Eu)); sfera_sub_004BDEF0(cpu, LIFT_CODE_TOKEN_VA(0x4BE06Eu));
    if (*(uint32_t*)(cpu->esi + 0x1D0u) == cpu->edi) goto label_000BE09E;
    cpu->edx = 0x5Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE085u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE085u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->ecx == cpu->edi) goto label_000BE098;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BE098:
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->edi;
    label_000BE09E:
    if (*(uint32_t*)(cpu->esi + 0x1D4u) == cpu->edi) goto label_000BE0CE;
    cpu->edx = 0x65u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE0B5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE0B5u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    if (cpu->ecx == cpu->edi) goto label_000BE0C8;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BE0C8:
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->edi;
    label_000BE0CE:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->eax == cpu->edi) goto label_000BE0E1;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE0DEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BE0DEu));
    cpu->esp += 4u;
    label_000BE0E1:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE102u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE102u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BE120(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x198u) == 0u) goto label_000BE165;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint8_t*)(cpu->eax + 0x48u) = 0u;
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x19Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE152u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4BE152u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    --cpu->eax;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BE165:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BE170(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    sub_pred[0] = cpu->ecx == 0xFA2u;
    if (cpu->ecx > 0xFA2u) goto label_000BE28A;
    if (sub_pred[0]) goto label_000BE265;
    cpu->edx = cpu->ecx;
    if ((cpu->edx -= 0x65u) == 0u) goto label_000BE241;
    if ((--cpu->edx) == 0u) goto label_000BE21D;
    if ((cpu->edx -= 0x10u) != 0u) goto label_000BE383;
    if (cpu->eax != 0u) goto label_000BE26C;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = 0x17u;
    if (cpu->ecx == 0u) goto label_000BE1F2;
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE1F2u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_RVA(0xBE1F2u));
    label_000BE1F2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    if (cpu->ecx == 0u) goto label_000BE273;
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE206u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_VA(0x4BE206u));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE21D:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE22Au)); sfera_sub_004BD6D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE22Au));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE241:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE24Eu)); sfera_sub_004BD6D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE24Eu));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE265:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE26Cu)); sfera_sub_004BE120(cpu, LIFT_CODE_TOKEN_RVA(0xBE26Cu));
    label_000BE26C:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE273u)); sfera_sub_004BDA90(cpu, LIFT_CODE_TOKEN_RVA(0xBE273u));
    label_000BE273:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE28A:
    cpu->edx = cpu->ecx + 0xFFFFF05Cu;
    if (cpu->edx > 4u) goto label_000BE383;
    switch (cpu->edx) {
        case 0u: goto label_000BE2A0;
        case 1u: goto label_000BE2BF;
        case 2u: goto label_000BE2F9;
        case 3u: goto label_000BE321;
        case 4u: goto label_000BE35E;
        default: lift_trap(cpu, 0x4BE299u, "resolved jump-table index out of range"); return;
    }
label_000BE2A0: ;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1E0u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE2BF:
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax < cpu->edx) goto label_000BE2E2;
    *(uint32_t*)(cpu->esi + 0x1E0u) = 0xFFFFFFFFu;
    label_000BE2E2:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE2F9:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = 1u;
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE321:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax >= cpu->edx) goto label_000BE273;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE340u)); sfera_sub_004BDD70(cpu, LIFT_CODE_TOKEN_VA(0x4BE340u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE347u)); sfera_sub_004BDA90(cpu, LIFT_CODE_TOKEN_VA(0x4BE347u));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE35E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE365u)); sfera_sub_004BDEF0(cpu, LIFT_CODE_TOKEN_VA(0x4BE365u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE36Cu)); sfera_sub_004BDA90(cpu, LIFT_CODE_TOKEN_VA(0x4BE36Cu));
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BE383:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE391u)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4BE391u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BE3C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE3C8u)); sfera_sub_004BE000(cpu, LIFT_CODE_TOKEN_VA(0x4BE3C8u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000BE3D8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE3D5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BE3D5u));
    cpu->esp += 4u;
    label_000BE3D8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BE3E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x30u;
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE419u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4BE419u));
    if (*(uint32_t*)(cpu->esi + 0x9Cu) != 0u) goto label_000BE43C;
    lift_push32(cpu, 0x77u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE433u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE433u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE439u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE439u));
    cpu->esp += 0x10u;
    label_000BE43C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"vscrollbar");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE454u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4BE454u));
    if (cpu->eax == 0u) goto label_000BE47C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE46Eu)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4BE46Eu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE47Cu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xBE47Cu));
    label_000BE47C:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"hscrollbar");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE490u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4BE490u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->eax == 0u) goto label_000BE4D2;
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE4AAu)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4BE4AAu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE4B8u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE4B8u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE4C3u)); sfera_sub_004C7DB0(cpu, LIFT_CODE_TOKEN_VA(0x4BE4C3u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->eax |= 1u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE4D2u)); sfera_sub_004C7DA0(cpu, LIFT_CODE_TOKEN_RVA(0xBE4D2u));
    label_000BE4D2:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"itemTemplate");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE4E6u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4BE4E6u));
    if (cpu->eax == 0u) goto label_000BE5A6;
    cpu->edx = 0x8Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE4FDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE4FDu));
    lift_push32(cpu, 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE507u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BE507u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = 0u;
    if (cpu->eax == 0u) goto label_000BE523;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE521u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4BE521u));
    goto label_000BE525;
    label_000BE523:
    cpu->eax = 0u;
    label_000BE525:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE541u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE541u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    if (cpu->eax != 0u) goto label_000BE573;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListItemCtrl::LoadUI(%s,%d,%d) -> Can't load item template.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE56Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE56Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE570u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE570u));
    cpu->esp += 0x14u;
    label_000BE573:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE580u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE580u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint8_t*)(cpu->edx + 0x48u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->eax + 0xF4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint8_t*)(cpu->edx + 0x4Au) = 1u;
    label_000BE5A6:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"createItems");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE5B3u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4BE5B3u));
    if (cpu->eax == 0u) goto label_000BE678;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE5C4u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4BE5C4u));
    if ((int32_t)cpu->eax <= 0) goto label_000BE678;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000BE5D0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == 0u) goto label_000BE66A;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->ebp = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0x48u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = cpu->esp + 0x44u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebp;
    if (cpu->ecx >= cpu->eax) goto label_000BE63E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edx = cpu->esp + 0x44u;
    if (cpu->ecx > cpu->edx) goto label_000BE63E;
    cpu->ebp = cpu->edx;
    cpu->ebp -= cpu->ecx;
    cpu->ebp = (int32_t)(cpu->ebp) >> 2u;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 0x1A4u)) goto label_000BE627;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi + 0x19Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE627u)); sfera_sub_004BDE90(cpu, LIFT_CODE_TOKEN_RVA(0xBE627u));
    label_000BE627:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    if (cpu->eax == 0u) goto label_000BE65F;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    goto label_000BE65F;
    label_000BE63E:
    if (cpu->eax != *(uint32_t*)(cpu->esi + 0x1A4u)) goto label_000BE653;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi + 0x19Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE653u)); sfera_sub_004BDE90(cpu, LIFT_CODE_TOKEN_RVA(0xBE653u));
    label_000BE653:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    if (cpu->eax == 0u) goto label_000BE65F;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    label_000BE65F:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1A0u)) + (uint64_t)(4u) + (uint64_t)(0u);
    label_000BE66A:
    if ((--*(uint32_t*)(cpu->esp + 0x14u)) != 0u) goto label_000BE5D0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    label_000BE678:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"selectSprite");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE685u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4BE685u));
    if (cpu->eax == 0u) goto label_000BE6D5;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.list_item_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE697u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4BE697u));
    if (cpu->eax == 0u) goto label_000BE6D5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.list_item_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE6ABu)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4BE6ABu));
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->eax;
    if (cpu->eax != 0u) goto label_000BE6D5;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.list_item_value[0]); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListItemCtrl::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE6CCu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BE6CCu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE6D2u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE6D2u));
    cpu->esp += 0x18u;
    label_000BE6D5:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"selectedItem");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE6E2u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4BE6E2u));
    if (cpu->eax == 0u) goto label_000BE712;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE6EFu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4BE6EFu));
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->eax < cpu->edx) goto label_000BE712;
    *(uint32_t*)(cpu->esi + 0x1E0u) = 0xFFFFFFFFu;
    label_000BE712:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"canSelectItems");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE71Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4BE71Fu));
    if (cpu->eax == 0u) goto label_000BE737;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE72Cu)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4BE72Cu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->eax!=0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x1D9u) = cpu->eax & 0xFFu;
    label_000BE737:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"horizontal");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE744u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4BE744u));
    if (cpu->eax == 0u) goto label_000BE75C;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE751u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4BE751u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((cpu->eax!=0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x1E4u) = cpu->ecx & 0xFFu;
    label_000BE75C:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"userMove");
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE769u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4BE769u));
    if (cpu->eax == 0u) goto label_000BE781;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE776u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4BE776u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((cpu->eax!=0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x1E5u) = cpu->edx & 0xFFu;
    label_000BE781:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE788u)); sfera_sub_004BDA90(cpu, LIFT_CODE_TOKEN_VA(0x4BE788u));
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE794u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4BE794u));
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BE7B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE7BEu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4BE7BEu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    cpu->ecx = cpu->edi + 0x19Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x19Cu;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE7DCu)); sfera_sub_004A9980(cpu, LIFT_CODE_TOKEN_VA(0x4BE7DCu));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1ACu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1B0u);
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B8u);
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1BCu);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1C0u);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C4u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1D0u);
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1D4u);
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1D8u));
    *(uint8_t*)(cpu->esi + 0x1D8u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->edi + 0x1D9u);
    *(uint8_t*)(cpu->esi + 0x1D9u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1DCu);
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1E0u);
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->ecx;
    cpu->edx = *(uint8_t*)(cpu->edi + 0x1E4u);
    *(uint8_t*)(cpu->esi + 0x1E4u) = cpu->edx & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1E5u));
    *(uint8_t*)(cpu->esi + 0x1E5u) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BE8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    cpu->edx = 0x130u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE8FCu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BE8FCu));
    lift_push32(cpu, 0x1E8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE906u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4BE906u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    if (cpu->eax == 0u) goto label_000BE924;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE920u)); sfera_sub_004BDCD0(cpu, LIFT_CODE_TOKEN_VA(0x4BE920u));
    cpu->ebx = cpu->eax;
    goto label_000BE926;
    label_000BE924:
    cpu->ebx = 0u;
    label_000BE926:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BE936u)); sfera_sub_004BE7B0(cpu, LIFT_CODE_TOKEN_VA(0x4BE936u));
    *(uint8_t*)(cpu->ebx + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->ebp + 0xECu) == 0u) goto label_000BE95E;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBE95Eu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xBE95Eu));
    label_000BE95E:
    if (*(uint32_t*)(cpu->ebp + 0x198u) == 0u) goto label_000BE97A;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    *(uint32_t*)(cpu->ebx + 0x198u) = cpu->eax;
    label_000BE97A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1A0u);
    cpu->eax -= *(uint32_t*)(cpu->ebp + 0x19Cu);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax == 0u) goto label_000BEB14;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1A0u);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x19Cu);
    if (cpu->edi == cpu->ecx) goto label_000BE9C7;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ebp = cpu->eax * 4u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4BE9B2u));
    cpu->esp += 0xCu;
    cpu->ebp += cpu->edi;
    *(uint32_t*)(cpu->ebx + 0x1A0u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_000BE9C7:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1A0u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0x19Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->ecx == 0u) goto label_000BEB14;
    label_000BE9F0:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->edi = cpu->eax;
    *(uint8_t*)(cpu->edi + 0x48u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1A0u);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->ecx >= cpu->eax) goto label_000BEA8C;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x19Cu);
    if (cpu->edx > cpu->ecx) goto label_000BEA8C;
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1A4u);
    cpu->edi -= cpu->edx;
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    if (cpu->eax != cpu->ecx) goto label_000BEA75;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax > 0x3FFFFFFEu) goto label_000BEB72;
    cpu->ecx -= cpu->edx;
    ++cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->eax <= cpu->ecx) goto label_000BEA75;
    cpu->edx = cpu->ecx;
    cpu->edx >>= 1u;
    cpu->ebp = 0x3FFFFFFFu;
    cpu->ebp -= cpu->edx;
    if (cpu->ebp >= cpu->ecx) goto label_000BEA5D;
    cpu->ecx = 0u;
    goto label_000BEA5F;
    label_000BEA5D:
    cpu->ecx += cpu->edx;
    label_000BEA5F:
    if (cpu->ecx >= cpu->eax) goto label_000BEA65;
    cpu->ecx = cpu->eax;
    label_000BEA65:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0x19Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BEA71u)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4BEA71u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_000BEA75:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1A0u);
    if (cpu->eax == 0u) goto label_000BEAED;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_000BEAED;
    label_000BEA8C:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1A4u);
    if (cpu->eax != cpu->ecx) goto label_000BEAE1;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x19Cu);
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax > 0x3FFFFFFEu) goto label_000BEB72;
    cpu->ecx -= cpu->edx;
    ++cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->eax <= cpu->ecx) goto label_000BEAE1;
    cpu->edx = cpu->ecx;
    cpu->edx >>= 1u;
    cpu->ebp = 0x3FFFFFFFu;
    cpu->ebp -= cpu->edx;
    if (cpu->ebp >= cpu->ecx) goto label_000BEAC9;
    cpu->ecx = 0u;
    goto label_000BEACB;
    label_000BEAC9:
    cpu->ecx += cpu->edx;
    label_000BEACB:
    if (cpu->ecx >= cpu->eax) goto label_000BEAD1;
    cpu->ecx = cpu->eax;
    label_000BEAD1:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0x19Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BEADDu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4BEADDu));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_000BEAE1:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1A0u);
    if (cpu->eax == 0u) goto label_000BEAED;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_000BEAED:
    *(uint32_t*)(cpu->ebx + 0x1A0u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 0x1A0u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1A0u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0x19Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->eax;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if (cpu->eax < cpu->edx) goto label_000BE9F0;
    label_000BEB14:
    if (*(uint32_t*)(cpu->ebp + 0x1D0u) == 0u) goto label_000BEB38;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x1D0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBEB38u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xBEB38u));
    label_000BEB38:
    if (*(uint32_t*)(cpu->ebp + 0x1D4u) == 0u) goto label_000BEB5C;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1D4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x1D4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBEB5Cu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xBEB5Cu));
    label_000BEB5C:
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BEB72:
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4BEB72u), "std::length_error");
    lift_trap(cpu, 0x4BEB7Du, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004BEB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_key_dik_from_virtual_key(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BEBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_key_virtual_key_from_dik(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BEBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_key_code_from_name(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BEC00(LiftCpu* cpu, uint32_t stop_address) {
    const char* name = sfera_key_name_from_code(cpu->ecx);
    cpu->eax = (uintptr_t)(name ? name : "???");
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BEC20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1DCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x6Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->edi = cpu->edx + (cpu->eax * 2u);
    if ((int32_t)(cpu->ebp) >= 0) goto label_000BEC5F;
    cpu->edi += cpu->ebp;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    label_000BEC5F:
    if ((int32_t)cpu->ecx >= 0) goto label_000BEC71;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->ebx += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000BEC71:
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx = cpu->edi + cpu->ebp;
    if ((int32_t)cpu->edx <= (int32_t)cpu->eax) goto label_000BEC81;
    cpu->eax -= cpu->ebp;
    cpu->edi = cpu->eax;
    label_000BEC81:
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = cpu->ebx + cpu->ecx;
    if ((int32_t)cpu->edx <= (int32_t)cpu->eax) goto label_000BEC91;
    cpu->eax -= cpu->ecx;
    cpu->ebx = cpu->eax;
    label_000BEC91:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->eax;
    if (*(uint8_t*)(cpu->esp + 0x78u) == (cpu->eax & 0xFFu)) goto label_000BECDD;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BECD9u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4BECD9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000BECDD:
    x87_v0 = 0.0;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(float*)(cpu->esp + 0x44u) = x87_v0; 
    cpu->ecx = cpu->esp + 0x34u;
    x87_v0 = 1.0;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x4Cu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BED09u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4BED09u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1E4u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->edx = cpu->ecx;
    cpu->edi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1E0u);
    cpu->esi = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->edx >>= 24u;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x74u);
    cpu->edx = (uint32_t)(((uint64_t)0x80808081u * (uint32_t)(cpu->edx)) >> 32u);
    cpu->ecx&=0xFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->edx >>= 7u;
    cpu->esi = cpu->edx;
    cpu->esi <<= 24u;
    cpu->esi|=cpu->ecx;
    cpu->ecx = cpu->edi;
    cpu->ecx >>= 24u;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x10u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)0x80808081u * (uint32_t)(cpu->ecx)) >> 32u);
    *(float*)(cpu->esp + 0x1Cu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    *(float*)(cpu->esp + 0x20u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x74u))));
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    cpu->ecx = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    cpu->ecx >>= 7u;
    cpu->ecx <<= 24u;
    cpu->edi &= 0xFFFFFFu;
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    cpu->ecx |= cpu->edi;
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BEDBAu)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4BEDBAu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->esp -= 0x10u;
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BEDECu)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4BEDECu));
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BEE1Au)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4BEE1Au));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BEE48u)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4BEE48u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    --cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BEE7Au)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4BEE7Au));
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0x78u) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000BEE95;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBEE95u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_RVA(0xBEE95u));
    label_000BEE95:
    cpu->esp += 0x58u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BEEB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    if ((int32_t)cpu->esi < 0) goto label_000BEEE0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1A4u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->esi >= cpu->eax) goto label_000BEEE0;
    *(uint32_t*)(cpu->ecx + 0x1D8u) = cpu->esi;
    label_000BEEE0:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BEEF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esi = cpu->ecx;
    sub_pred[1] = *(uint8_t*)(cpu->esi + 0x48u) == 0u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edi;
    if (!sub_pred[1]) goto label_000BF113;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->ecx == 0u) goto label_000BEF26;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BEF26:
    if (*(uint8_t*)(cpu->esi + 0x1D4u) != 0u) goto label_000BEF4C;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1D8u) = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BEF4C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->ebx = cpu->edx;
    cpu->ebx >>= 31u;
    if ((cpu->ebx += cpu->edx) == 0u) goto label_000BF112;
    if (((*(uint8_t*)(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000BF112;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = 0u;
    cpu->eax = 0u;
    cpu->edx = 0u;
    if (cpu->ebp == cpu->ecx) goto label_000BEFBA;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x9Cu);
    if (cpu->ecx == 0u) goto label_000BEFAC;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBEFACu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBEFACu));
    label_000BEFAC:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x18u);
    label_000BEFBA:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->edx < (int32_t)cpu->ecx) goto label_000BF111;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edi += cpu->ecx;
    if ((int32_t)cpu->edx >= (int32_t)cpu->edi) goto label_000BF111;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    if ((int32_t)cpu->ecx < (int32_t)cpu->eax) goto label_000BF111;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = cpu->edi + cpu->eax;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edx) goto label_000BF111;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->ecx -= cpu->eax;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    cpu->eax = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x1CCu) == 0u) goto label_000BF022;
    if (cpu->ebx >= *(uint32_t*)(cpu->esi + 0x1C0u)) goto label_000BF022;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edi -= cpu->ecx;
    cpu->edx += cpu->edi;
    label_000BF022:
    cpu->eax -= cpu->edx;
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->esi + 0x1BCu)); cpu->eax = n / d; cpu->edx = n % d; }
    cpu->eax += *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->eax < cpu->ebx) goto label_000BF039;
    cpu->eax |= 0xFFFFFFFFu;
    label_000BF039:
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x1D8u)) goto label_000BF06D;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xE16u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBF06Du)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xBF06Du));
    label_000BF06D:
    if (*(uint8_t*)(cpu->esi + 0x1F0u) != 0u) goto label_000BF0A3;
    *(uint8_t*)(cpu->esi + 0x1F0u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF082u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4BF082u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BF0A3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF0A8u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4BF0A8u));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x1E8u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x1E8u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1ECu) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(float*)(cpu->esp + 0x10u) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x10u)))))) / (10000.0));
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=0.6; if (!(lift_left<lift_right)) goto label_000BF10A; }
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1D8u) < (int32_t)0u) goto label_000BF10A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xE1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBF10Au)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xBF10Au));
    label_000BF10A:
    *(uint8_t*)(cpu->esi + 0x1F0u) = 0u;
    label_000BF111:
    cpu->ebp = lift_pop32(cpu);
    label_000BF112:
    cpu->ebx = lift_pop32(cpu);
    label_000BF113:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BF130(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1C4u) >= (int32_t)0u) goto label_000BF149;
    *(uint32_t*)(cpu->esi + 0x1C4u) = 0u;
    label_000BF149:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B8u);
    if (*(uint32_t*)(cpu->esi + 0x1C4u) <= cpu->eax) goto label_000BF15D;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    label_000BF15D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1BCu))));
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->eax >= 0) goto label_000BF174;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BF174:
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1C4u)))))) / (((double)*(float*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(double*)(cpu->esp + 0x18u) = x87_v0;
    *(double*)(cpu->esp) = x87_v0;
    x87_v0 = std::floor(*(double*)(cpu->esp));
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->esp += 8u;
    x87_v1 = x87_v0;
    x87_v1 = (*(double*)(cpu->esp + 0x10u)) - (x87_v1);
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 8u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->edi = cpu->ecx + cpu->eax + 1u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    sub_pred[0] = cpu->edi <= cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000BF204;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    label_000BF204:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BF210(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0;
    cpu->esp -= 0x78u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000BF9A9;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000BF9A9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->eax) goto label_000BF275;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000BF267;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBF267u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xBF267u));
    label_000BF267:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    label_000BF275:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebp += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ebx += cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    if (cpu->eax == 0u) goto label_000BF956;
    cpu->eax = 0u;
    cpu->ecx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF2E8u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4BF2E8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->edi = cpu->ebp;
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->eax <<= 24u;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x1CCu) == 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (sub_pred[0]) goto label_000BF33B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= *(uint32_t*)(cpu->esi + 0x1C0u)) goto label_000BF33B;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax -= cpu->edx;
    cpu->edi += cpu->eax;
    label_000BF33B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    cpu->edx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if ((int32_t)cpu->ebx >= 0) goto label_000BF363;
    cpu->ecx += cpu->ebx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    label_000BF363:
    if ((int32_t)cpu->ebp >= 0) goto label_000BF371;
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_000BF371:
    cpu->edx += cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ecx) goto label_000BF385;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    label_000BF385:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ecx) goto label_000BF39C;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    label_000BF39C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = 0.0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x58u) = x87_v0; 
    x87_v0 = 1.0;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x5Cu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edx;
    cpu->edx = cpu->esp + 0x48u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF3D4u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4BF3D4u));
    g_sfera_screen_clip_runtime.left = cpu->ebx;
    g_sfera_screen_clip_runtime.top = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx += cpu->ebx;
    g_sfera_screen_clip_runtime.right = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ebp;
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != 0xFFu) goto label_000BF417;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000BF417;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF411u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4BF411u));
    cpu->ecx = g_sfera_screen_clip_runtime.right;
    label_000BF417:
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    if (*(uint8_t*)(cpu->esi + 0x1CEu) == (cpu->edx & 0xFFu)) goto label_000BF46A;
    cpu->ecx = 0x2E2E2020u;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"  ...") + 4u));
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    *(uint16_t*)(cpu->esp + 0x7Cu) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->ecx = cpu->esp + 0x84u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF460u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4BF460u));
    cpu->ecx = g_sfera_screen_clip_runtime.right;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    label_000BF46A:
    if (*(uint32_t*)(cpu->esi + 0x1B0u) != 0u) goto label_000BF663;
    if (*(uint8_t*)(cpu->esi + 0x1CEu) == 0u) goto label_000BF5D8;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x19Cu)) goto label_000BF8F6;
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_000BF4C4;
    label_000BF4C0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_000BF4C4:
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0x1Cu);
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000BF4DB;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    goto label_000BF4DF;
    label_000BF4DB:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    label_000BF4DF:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF501u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4BF501u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = 0.0;
    cpu->ebp &= 0xFFFFFFu;
    cpu->ebp |= *(uint32_t*)(cpu->esp + 0x28u);
    sub_pred[1] = cpu->eax <= *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0u);
    if (sub_pred[1]) goto label_000BF582;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = cpu->ecx;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF54Du)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4BF54Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = 0.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->edx + 0x20u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"  ...");
    goto label_000BF5AA;
    label_000BF582:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = cpu->ecx;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    label_000BF5AA:
    cpu->edx = cpu->edi;
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF5B3u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4BF5B3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x19Cu)) goto label_000BF4C0;
    goto label_000BF8F2;
    label_000BF5D8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x19Cu)) goto label_000BF8F6;
    cpu->ebp = cpu->eax + (cpu->eax * 8u);
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    label_000BF600:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x1Cu);
    cpu->ecx += cpu->ebp;
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_000BF614;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000BF614:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    x87_v0 = 0.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->eax &= 0xFFFFFFu;
    cpu->eax |= *(uint32_t*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x20u);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF644u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4BF644u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1BCu);
    ++cpu->eax;
    cpu->ebp += 0x24u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x19Cu)) goto label_000BF600;
    goto label_000BF8F2;
    label_000BF663:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->edx -= cpu->ebp;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->eax = cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax;
    cpu->edx >>= 31u;
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->eax -= cpu->edx;
    cpu->eax += *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)(cpu->eax) >= 0) goto label_000BF6AE;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000BF6AE:
    if (cpu->eax < cpu->edx) goto label_000BF6BA;
    cpu->edx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->eax = cpu->edx;
    label_000BF6BA:
    if (*(uint8_t*)(cpu->esi + 0x1CEu) == 0u) goto label_000BF84A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->ecx <= 0) goto label_000BF8F2;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    goto label_000BF704;
    label_000BF700:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_000BF704:
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0x1Cu);
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000BF726;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    goto label_000BF72A;
    label_000BF726:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    label_000BF72A:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF74Cu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4BF74Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    x87_v0 = 0.0;
    cpu->ebp &= 0xFFFFFFu;
    cpu->ebp |= *(uint32_t*)(cpu->esp + 0x28u);
    sub_pred[2] = cpu->eax <= *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0u);
    if (sub_pred[2]) goto label_000BF7CD;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = cpu->ecx;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF798u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4BF798u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = 0.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->edx + 0x20u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"  ...");
    goto label_000BF7F5;
    label_000BF7CD:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = cpu->ecx;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    label_000BF7F5:
    cpu->edx = cpu->edi;
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF7FEu)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4BF7FEu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    ++cpu->ebp;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if (cpu->ebp < cpu->eax) goto label_000BF836;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_000BF836:
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    if ((--*(uint32_t*)(cpu->esp + 0x20u)) != 0u) goto label_000BF700;
    goto label_000BF8F2;
    label_000BF84A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->ecx <= 0) goto label_000BF8F2;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    goto label_000BF864;
    label_000BF860:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_000BF864:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ecx + 0x1Cu);
    cpu->edx += cpu->ecx;
    if (*(uint32_t*)(cpu->edx + 0x14u) < 0x10u) goto label_000BF87F;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_000BF87F:
    x87_v0 = 0.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax &= 0xFFFFFFu;
    cpu->eax |= *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF8B1u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4BF8B1u));
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->ecx -= cpu->ebp;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    if (*(uint32_t*)(cpu->esp + 0x10u) < cpu->ecx) goto label_000BF8E8;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_000BF8E8:
    if ((--*(uint32_t*)(cpu->esp + 0x14u)) != 0u) goto label_000BF860;
    label_000BF8F2:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000BF8F6:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000BF927;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0x19Cu)) goto label_000BF927;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x1BCu));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBF927u)); sfera_sub_004BEC20(cpu, LIFT_CODE_TOKEN_RVA(0xBF927u));
    label_000BF927:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BF937u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4BF937u));
    if (*(uint32_t*)(cpu->esi + 0xDCu) != 0xFFu) goto label_000BF956;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000BF956;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBF956u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xBF956u));
    label_000BF956:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_000BF9A9;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000BF99C;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    if ((int32_t)cpu->eax >= 0) goto label_000BF985;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000BF985:
    x87_v0 = (x87_v0) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x2Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000BF99C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000BF9A9:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x78u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BF9C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= cpu->ebp;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    if (cpu->eax >= cpu->ecx) goto label_000BFA65;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ebx != 0u) goto label_000BFA01;
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u) + 0x20u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BFA01:
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + (cpu->eax * 8u);
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->eax = cpu->edi + cpu->ebp;
    if (*(uint32_t*)(cpu->edi + cpu->ebp + 0x14u) < 0x10u) goto label_000BFA15;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BFA15:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFA35u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4BFA35u));
    if ((((cpu->ebx & 0xFFu)) & (4u)) == 0u) goto label_000BFA4D;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx -= *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx >>= 1u;
    *(uint32_t*)(cpu->edi + cpu->eax + 0x20u) = cpu->edx;
    label_000BFA4D:
    if ((((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_000BFA63;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    *(uint32_t*)(cpu->edi + cpu->edx + 0x20u) = cpu->ecx;
    label_000BFA63:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000BFA65:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BFA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1BCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax = cpu->edi;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ebx); cpu->eax = n / d; cpu->edx = n % d; }
    ++cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edx = 0u;
    if (cpu->edi <= cpu->eax) goto label_000BFAC7;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->edx;
    goto label_000BFAD0;
    label_000BFAC7:
    cpu->eax -= cpu->edi;
    ++cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    label_000BFAD0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->ecx == cpu->edx) goto label_000BFB2A;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = 0x17u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBFB2Au)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_RVA(0xBFB2Au));
    label_000BFB2A:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFB31u)); sfera_sub_004BF130(cpu, LIFT_CODE_TOKEN_VA(0x4BFB31u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BFB90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFB98u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4BFB98u));
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::ListCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    *(uint16_t*)(cpu->esi + 0x1CCu) = cpu->eax & 0xFFFFu;
    *(uint8_t*)(cpu->esi + 0x1CEu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1D4u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1BCu) = 1u;
    *(uint32_t*)(cpu->esi + 0x1D8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1DCu) = 3u;
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1F0u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x50u) = 0xAu;
    *(uint32_t*)(cpu->esi + 0x1E0u) = 0x32000000u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BFC50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::ListCtrl*>(cpu->esi));
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (*(uint32_t*)(cpu->esi + 0x1D0u) == cpu->edi) goto label_000BFCB7;
    cpu->edx = cpu->edi + 0x66u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFC9Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BFC9Eu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->ecx == cpu->edi) goto label_000BFCB1;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BFCB1:
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->edi;
    label_000BFCB7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    if (cpu->ecx == cpu->edi) goto label_000BFCE7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esi + 0x1ACu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFCD8u)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4BFCD8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFCE4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BFCE4u));
    cpu->esp += 4u;
    label_000BFCE7:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFD08u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4BFD08u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BFD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->edi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->edx >= cpu->eax) goto label_000BFE6E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x1B0u);
    if (cpu->esi == 0u) goto label_000BFD82;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    if ((int32_t)(cpu->ecx -= cpu->eax) >= 0) goto label_000BFD73;
    cpu->ecx += cpu->eax;
    label_000BFD73:
    if (cpu->ecx < cpu->eax) goto label_000BFD7B;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->eax;
    label_000BFD7B:
    cpu->eax = cpu->ecx + cpu->edx;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->esi); cpu->eax = n / d; cpu->edx = n % d; }
    label_000BFD82:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x1A0u);
    if (cpu->edx == 0u) goto label_000BFD93;
    cpu->eax = cpu->edx + (cpu->edx * 8u);
    cpu->ebp = cpu->ebp + (cpu->eax * 4u);
    label_000BFD93:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x1A4u);
    cpu->ebp += 0x24u;
    if (cpu->ebp == cpu->ebx) goto label_000BFDC5;
    cpu->esi = cpu->ebp + 0xFFFFFFFCu;
    label_000BFDA3:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 0xFFFFFFE0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFDB0u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BFDB0u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->ebp += 0x24u;
    cpu->esi += 0x24u;
    if (cpu->ebp != cpu->ebx) goto label_000BFDA3;
    label_000BFDC5:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x1A4u);
    cpu->esi = cpu->ebx + 0xFFFFFFDCu;
    if (cpu->esi == cpu->ebx) goto label_000BFDFC;
    cpu->ebp = 0xFu;
    label_000BFDD7:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000BFDE8;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFDE5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BFDE5u));
    cpu->esp += 4u;
    label_000BFDE8:
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi += 0x24u;
    if (cpu->esi != cpu->ebx) goto label_000BFDD7;
    label_000BFDFC:
    *(uint32_t*)(cpu->edi + 0x1A4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x1A4u)) + (uint64_t)(0xFFFFFFDCu) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1B0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000BFE2B;
    *(uint32_t*)(cpu->edi + 0x1B4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x1B4u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    if (*(uint32_t*)(cpu->edi + 0x1B4u) < cpu->eax) goto label_000BFE2B;
    *(uint32_t*)(cpu->edi + 0x1B4u) = 0u;
    label_000BFE2B:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    if (cpu->ecx == 0u) goto label_000BFE67;
    if (*(uint32_t*)(cpu->edi + 0x1D8u) == cpu->edx) goto label_000BFE67;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xD8u);
    *(uint32_t*)(cpu->edi + 0x1D8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xE16u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBFE67u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xBFE67u));
    label_000BFE67:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBFE6Eu)); sfera_sub_004BFA70(cpu, LIFT_CODE_TOKEN_RVA(0xBFE6Eu));
    label_000BFE6E:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BFE80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFE88u)); sfera_sub_004BFC50(cpu, LIFT_CODE_TOKEN_VA(0x4BFE88u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000BFE98;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFE95u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BFE95u));
    cpu->esp += 4u;
    label_000BFE98:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BFEA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x60u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->edi = 0u;
    cpu->ebp = 0u;
    if (cpu->ecx == cpu->edi) goto label_000BFF1B;
    cpu->eax |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esi + 0x1D8u) == cpu->eax) goto label_000BFF1B;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0xE16u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBFF1Bu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xBFF1Bu));
    label_000BFF1B:
    if (*(uint32_t*)(cpu->esi + 0x118u) == cpu->edi) goto label_000BFF6F;
    if (cpu->ebx == cpu->edi) goto label_000BFF6F;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFF47u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4BFF47u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x118u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000BFF5A;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebp -= cpu->ecx;
    label_000BFF5A:
    if ((((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000BFF6F;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax -= cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->ebp = cpu->eax;
    cpu->ebp = (int32_t)(cpu->ebp) >> 1u;
    label_000BFF6F:
    if (*(uint32_t*)(cpu->esi + 0x1B0u) != cpu->edi) goto label_000BFFF5;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 0u;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edi;
    if (cpu->ebx != cpu->edi) goto label_000BFF95;
    cpu->ebx = (uintptr_t)" ";
    label_000BFF95:
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_000BFFA0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BFFA0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFFB4u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BFFB4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->edx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    cpu->ecx = cpu->esi + 0x1A0u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFFD0u)); sfera_sub_004A43D0(cpu, LIFT_CODE_TOKEN_VA(0x4BFFD0u));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x30u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x68u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_000C013A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BFFEDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4BFFEDu));
    cpu->esp += 4u;
    goto label_000C013A;
    label_000BFFF5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    if (cpu->ecx >= *(uint32_t*)(cpu->esi + 0x1B0u)) goto label_000C00C6;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 0u;
    *(uint32_t*)(cpu->esp + 0x68u) = 1u;
    if (cpu->ebx != 0u) goto label_000C0040;
    cpu->ebx = (uintptr_t)" ";
    label_000C0040:
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_000C0045:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C0045;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0059u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C0059u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1A0u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0075u)); sfera_sub_004A43D0(cpu, LIFT_CODE_TOKEN_VA(0x4C0075u));
    ++*(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x1B0u)) goto label_000C0093;
    *(uint32_t*)(cpu->esi + 0x1B4u) = 0u;
    label_000C0093:
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x30u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x68u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_000C00AF;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C00ACu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C00ACu));
    cpu->esp += 4u;
    label_000C00AF:
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 0u;
    goto label_000C013A;
    label_000C00C6:
    if (cpu->ebx != 0u) goto label_000C00CF;
    cpu->ebx = (uintptr_t)" ";
    label_000C00CF:
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_000C00D4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C00D4;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C00F6u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C00F6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0x1Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0x20u) = cpu->ebp;
    ++*(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x1B0u)) goto label_000C013A;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edi;
    label_000C013A:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0141u)); sfera_sub_004BFA70(cpu, LIFT_CODE_TOKEN_VA(0x4C0141u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C0170(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    if (cpu->eax == cpu->ecx) goto label_000C01B4;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0192u)); sfera_sub_004A3DB0(cpu, LIFT_CODE_TOKEN_VA(0x4C0192u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1ACu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C01ADu)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4C01ADu));
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    label_000C01B4:
    *(uint32_t*)(cpu->esi + 0x1D8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1B4u) = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004BFA70(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C01E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (*(uint8_t*)(cpu->ebp + 0x1CDu) == 0u) goto label_000C04A3;
    if (cpu->eax == 0u) goto label_000C04A3;
    lift_push32(cpu, 0x3FFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4C020Au));
    cpu->eax = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->esp += 0xCu;
    cpu->edx = cpu->eax + 1u;
    label_000C0220:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C0220;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax -= cpu->edx;
    cpu->esi = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0])) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    goto label_000C0254;
    label_000C0243:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    label_000C0250:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    label_000C0254:
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x8Cu);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C026Eu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C026Eu));
    if (*(uint8_t*)(cpu->ebp + 0x8Cu) >= 2u) goto label_000C027C;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) - (uint64_t)(2u) - (uint64_t)(0u);
    label_000C027C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx += cpu->ebx;
    if (cpu->edx <= *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000C048C;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    label_000C0297:
    lift_push32(cpu, 0x3FFCu);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    g_sfera_ui_parse_scratch_runtime.token_buffer[0] = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4C02AFu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    cpu->esp += 0xCu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C039F;
    label_000C02C1:
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_000C02CD;
    if ((cpu->eax & 0xFFu) == 0x3Au) goto label_000C02CD;
    if ((cpu->eax & 0xFFu) != 0x3Bu) goto label_000C02EC;
    label_000C02CD:
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = cpu->eax & 0xFFu;
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi >= (int32_t)0x4000u) goto label_000C0499;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000C02C1;
    goto label_000C039F;
    label_000C02EC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C039F;
    label_000C02F6:
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_000C039F;
    if ((cpu->eax & 0xFFu) == 0x3Au) goto label_000C039F;
    if ((cpu->eax & 0xFFu) == 0x3Bu) goto label_000C039F;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = cpu->eax & 0xFFu;
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi >= (int32_t)0x4000u) goto label_000C0499;
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = 0u;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x8Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0346u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C0346u));
    if (*(uint8_t*)(cpu->ebp + 0x8Cu) >= 2u) goto label_000C0354;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) - (uint64_t)(2u) - (uint64_t)(0u);
    label_000C0354:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->edx < *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000C036B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->eax) goto label_000C036B;
    if (cpu->ebx == 0u) goto label_000C0373;
    label_000C036B:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000C02F6;
    goto label_000C039F;
    label_000C0373:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    lift_push32(cpu, cpu->ecx);
    ++cpu->esi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C038Bu)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C038Bu));
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    label_000C039F:
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x20u) == 1u;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = 0u;
    if (sub_pred[0]) goto label_000C0250;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x8Cu);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C03CEu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C03CEu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x8Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((cpu->eax & 0xFFu) >= 2u) goto label_000C03E3;
    cpu->ecx -= 2u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_000C03E3:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    if (cpu->ecx < cpu->edx) goto label_000C03FC;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->edi) goto label_000C03FC;
    if (cpu->ebx == 0u) goto label_000C0448;
    label_000C03FC:
    cpu->edi = cpu->ecx + cpu->ebx;
    if (cpu->edi > cpu->edx) goto label_000C0462;
    if ((cpu->eax & 0xFFu) >= 2u) goto label_000C0413;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    goto label_000C0415;
    label_000C0413:
    cpu->eax = 0u;
    label_000C0415:
    cpu->eax += cpu->ecx;
    cpu->ebx += cpu->eax;
    sub_pred[1] = *(uint8_t*)(cpu->esi) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (!sub_pred[1]) goto label_000C0297;
    lift_push32(cpu, 0x341u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C043Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C043Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0440u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C0440u));
    cpu->esp += 0x10u;
    goto label_000C0297;
    label_000C0448:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C045Cu)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C045Cu));
    ++cpu->esi;
    goto label_000C0243;
    label_000C0462:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C047Eu)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C047Eu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint8_t*)(cpu->ecx) = 0u;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    goto label_000C0243;
    label_000C048C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC0499u)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_RVA(0xC0499u));
    label_000C0499:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000C04A3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C04B0u)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C04B0u));
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C04C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x21Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C04F4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C04F4u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C04FEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C04FEu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000C051C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0518u)); sfera_sub_004BFB90(cpu, LIFT_CODE_TOKEN_VA(0x4C0518u));
    cpu->esi = cpu->eax;
    goto label_000C051E;
    label_000C051C:
    cpu->esi = 0u;
    label_000C051E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C052Eu)); sfera_sub_004A44F0(cpu, LIFT_CODE_TOKEN_VA(0x4C052Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000C0556;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC0556u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC0556u));
    label_000C0556:
    if (*(uint32_t*)(cpu->edi + 0x1D0u) == 0u) goto label_000C057A;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC057Au)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC057Au));
    label_000C057A:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C0590(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (cpu->eax == 0u) goto label_000C08B6;
    lift_push32(cpu, 0x3FFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.auxiliary_text[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4C05ADu));
    cpu->ecx = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.auxiliary_text[0];
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->eax = cpu->ecx;
    if ((uint8_t)((uint64_t)(g_sfera_ui_parse_scratch_runtime.auxiliary_text[0])) == 0u) goto label_000C08A9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000C05D1:
    if (*(uint8_t*)(cpu->ecx) != 0xAu) goto label_000C0898;
    *(uint8_t*)(cpu->ecx) = 0u;
    if (*(uint8_t*)(cpu->ebp + 0x1CDu) == 0u) goto label_000C0884;
    if (cpu->eax == 0u) goto label_000C0884;
    lift_push32(cpu, 0x3FFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4C05FDu));
    cpu->eax = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->esp += 0xCu;
    cpu->edx = cpu->eax + 1u;
    label_000C0610:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000C0610;
    cpu->eax -= cpu->edx;
    cpu->esi = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->ebx = 0u;
    *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0])) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    goto label_000C0644;
    label_000C0630:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    label_000C0640:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
    label_000C0644:
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x8Cu);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C065Eu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C065Eu));
    if (*(uint8_t*)(cpu->ebp + 0x8Cu) >= 2u) goto label_000C066C;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) - (uint64_t)(2u) - (uint64_t)(0u);
    label_000C066C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx += cpu->ebx;
    if (cpu->edx <= *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000C087C;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    label_000C0687:
    lift_push32(cpu, 0x3FFCu);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    g_sfera_ui_parse_scratch_runtime.token_buffer[0] = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4C069Fu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    cpu->esp += 0xCu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C078F;
    label_000C06B1:
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_000C06BD;
    if ((cpu->eax & 0xFFu) == 0x3Au) goto label_000C06BD;
    if ((cpu->eax & 0xFFu) != 0x3Bu) goto label_000C06DC;
    label_000C06BD:
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = cpu->eax & 0xFFu;
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi >= (int32_t)0x4000u) goto label_000C0891;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000C06B1;
    goto label_000C078F;
    label_000C06DC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C078F;
    label_000C06E6:
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_000C078F;
    if ((cpu->eax & 0xFFu) == 0x3Au) goto label_000C078F;
    if ((cpu->eax & 0xFFu) == 0x3Bu) goto label_000C078F;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = cpu->eax & 0xFFu;
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi >= (int32_t)0x4000u) goto label_000C0891;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = 0u;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x8Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0736u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C0736u));
    if (*(uint8_t*)(cpu->ebp + 0x8Cu) >= 2u) goto label_000C0744;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) - (uint64_t)(2u) - (uint64_t)(0u);
    label_000C0744:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->edx < *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000C075B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->eax) goto label_000C075B;
    if (cpu->ebx == 0u) goto label_000C0763;
    label_000C075B:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000C06E6;
    goto label_000C078F;
    label_000C0763:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    lift_push32(cpu, cpu->ecx);
    ++cpu->esi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C077Bu)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C077Bu));
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    label_000C078F:
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x20u) == 1u;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0])) = 0u;
    if (sub_pred[0]) goto label_000C0640;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x8Cu);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C07BEu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C07BEu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x8Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((cpu->eax & 0xFFu) >= 2u) goto label_000C07D3;
    cpu->ecx -= 2u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_000C07D3:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    if (cpu->ecx < cpu->edx) goto label_000C07EC;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->edi) goto label_000C07EC;
    if (cpu->ebx == 0u) goto label_000C0838;
    label_000C07EC:
    cpu->edi = cpu->ecx + cpu->ebx;
    if (cpu->edi > cpu->edx) goto label_000C0852;
    if ((cpu->eax & 0xFFu) >= 2u) goto label_000C0803;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    goto label_000C0805;
    label_000C0803:
    cpu->eax = 0u;
    label_000C0805:
    cpu->eax += cpu->ecx;
    cpu->ebx += cpu->eax;
    sub_pred[1] = *(uint8_t*)(cpu->esi) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (!sub_pred[1]) goto label_000C0687;
    lift_push32(cpu, 0x341u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C082Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C082Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0830u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C0830u));
    cpu->esp += 0x10u;
    goto label_000C0687;
    label_000C0838:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C084Cu)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C084Cu));
    ++cpu->esi;
    goto label_000C0630;
    label_000C0852:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C086Eu)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C086Eu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint8_t*)(cpu->ecx) = 0u;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    goto label_000C0630;
    label_000C087C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    goto label_000C088A;
    label_000C0884:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    label_000C088A:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC0891u)); sfera_sub_004BFEA0(cpu, LIFT_CODE_TOKEN_RVA(0xC0891u));
    label_000C0891:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = cpu->ecx + 1u;
    label_000C0898:
    ++cpu->ecx;
    sub_pred[2] = *(uint8_t*)(cpu->ecx) == 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    if (!sub_pred[2]) goto label_000C05D1;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C08A9:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC08B6u)); sfera_sub_004C01E0(cpu, LIFT_CODE_TOKEN_RVA(0xC08B6u));
    label_000C08B6:
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C08C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    sub_pred[2] = cpu->eax == 0xE11u;
    if (cpu->eax > 0xE11u) goto label_000C0A13;
    if (sub_pred[2]) goto label_000C099F;
    if (cpu->eax == 0x66u) goto label_000C0979;
    if (cpu->eax != 0x76u) goto label_000C0D1C;
    if (cpu->ecx != 0u) goto label_000C0959;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x17u;
    if (cpu->ecx == 0u) goto label_000C0960;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0940u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_VA(0x4C0940u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0959:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC0960u)); sfera_sub_004BFA70(cpu, LIFT_CODE_TOKEN_RVA(0xC0960u));
    label_000C0960:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0979:
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0986u)); sfera_sub_004BF130(cpu, LIFT_CODE_TOKEN_VA(0x4C0986u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C099F:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx += 5u;
    sub_pred[0] = cpu->edx < *(uint32_t*)(cpu->esi + 0x1B8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (!sub_pred[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C09BAu)); sfera_sub_004C0590(cpu, LIFT_CODE_TOKEN_VA(0x4C09BAu));
    if (*(uint8_t*)(cpu->esi + 0x1CCu) == 0u) goto label_000C09FA;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000C09FA;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B8u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000C09F3;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x14u) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC09F3u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_RVA(0xC09F3u));
    label_000C09F3:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC09FAu)); sfera_sub_004BF130(cpu, LIFT_CODE_TOKEN_RVA(0xC09FAu));
    label_000C09FA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0A13:
    cpu->edx = cpu->eax + 0xFFFFF1EEu;
    if (cpu->edx > 0xEu) goto label_000C0D1C;
    switch (cpu->edx) {
        case 0u: goto label_000C0A4A;
        case 1u: goto label_000C0AB5;
        case 2u: goto label_000C0AFC;
        case 3u: goto label_000C0B20;
        case 4u: case 10u: goto label_000C0D1C;
        case 5u: goto label_000C0BBC;
        case 6u: goto label_000C0B63;
        case 7u: goto label_000C0BDD;
        case 8u: goto label_000C0B84;
        case 9u: goto label_000C0C65;
        case 11u: goto label_000C0CDB;
        case 12u: goto label_000C0CFB;
        case 13u: goto label_000C0A29;
        case 14u: goto label_000C0979;
        default: lift_trap(cpu, 0x4C0A22u, "resolved jump-table index out of range"); return;
    }
label_000C0A29: ;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0A4A:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->ecx >= cpu->eax) goto label_000C0A9F;
    if (cpu->edi != 0u) goto label_000C0A74;
    cpu->edi = (uintptr_t)" ";
    label_000C0A74:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 8u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->edx + (cpu->ecx * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0A86u)); sfera_sub_0049D560(cpu, LIFT_CODE_TOKEN_VA(0x4C0A86u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0A9F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0AB5:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->ecx >= cpu->eax) goto label_000C0A9F;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0x1Cu) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0AFC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->ecx!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x1CDu) = cpu->eax & 0xFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0B20:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->ecx >= cpu->eax) goto label_000C0B63;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0B4Au)); sfera_sub_004BF9C0(cpu, LIFT_CODE_TOKEN_VA(0x4C0B4Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0B63:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1D8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0B84:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += cpu->edx;
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0BBC:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0BC4u)); sfera_sub_004BEEB0(cpu, LIFT_CODE_TOKEN_VA(0x4C0BC4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0BDD:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000C0A9F;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1B0u);
    if (cpu->ebx != 0u) goto label_000C0C10;
    cpu->edx = cpu->edi;
    goto label_000C0C2B;
    label_000C0C10:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B4u);
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_000C0C1C;
    cpu->edx += cpu->eax;
    label_000C0C1C:
    if (cpu->edx < cpu->eax) goto label_000C0C24;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    label_000C0C24:
    cpu->eax = cpu->edi + cpu->edx;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ebx); cpu->eax = n / d; cpu->edx = n % d; }
    label_000C0C2B:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = cpu->edx + (cpu->edx * 8u);
    sub_pred[1] = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x14u) < 0x10u;
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    if (sub_pred[1]) goto label_000C0C40;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C0C40:
    cpu->ecx -= cpu->eax;
    label_000C0C42:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->eax + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C0C42;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0C65:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000C0A9F;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1B0u);
    if (cpu->ebx != 0u) goto label_000C0C98;
    cpu->edx = cpu->edi;
    goto label_000C0CB3;
    label_000C0C98:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B4u);
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_000C0CA4;
    cpu->edx += cpu->eax;
    label_000C0CA4:
    if (cpu->edx < cpu->eax) goto label_000C0CAC;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    label_000C0CAC:
    cpu->eax = cpu->edi + cpu->edx;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ebx); cpu->eax = n / d; cpu->edx = n % d; }
    label_000C0CB3:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->edx + (cpu->edx * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x1Cu);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0CDB:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0CE2u)); sfera_sub_004C0170(cpu, LIFT_CODE_TOKEN_VA(0x4C0CE2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0CFB:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0D03u)); sfera_sub_004BFD20(cpu, LIFT_CODE_TOKEN_VA(0x4C0D03u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000C0D1C:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0D26u)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4C0D26u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C0D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x24u;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0D99u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4C0D99u));
    cpu->ecx = cpu->edi + 0x1BCu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x8Cu);
    lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)" ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0DB8u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4C0DB8u));
    if (*(uint32_t*)(cpu->edi + 0x9Cu) != 0u) goto label_000C0DDB;
    lift_push32(cpu, 0x79u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0DD2u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C0DD2u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0DD8u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C0DD8u));
    cpu->esp += 0x10u;
    label_000C0DDB:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"scrollbar");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0DF3u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4C0DF3u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->eax == 0u) goto label_000C0E1B;
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E0Du)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4C0E0Du));
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x1D0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC0E1Bu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC0E1Bu));
    label_000C0E1B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"formatStrings");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E28u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0E28u));
    if (cpu->eax == 0u) goto label_000C0E40;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E35u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4C0E35u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->edi + 0x1CDu) = cpu->edx & 0xFFu;
    label_000C0E40:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"useContinueMark");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E4Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0E4Du));
    if (cpu->eax == 0u) goto label_000C0E65;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E5Au)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4C0E5Au));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->edi + 0x1CEu) = cpu->eax & 0xFFu;
    label_000C0E65:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canSelect");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E72u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0E72u));
    if (cpu->eax == 0u) goto label_000C0E8A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E7Fu)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4C0E7Fu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->edi + 0x1D4u) = cpu->ecx & 0xFFu;
    label_000C0E8A:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"selectionBorder");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0E97u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0E97u));
    if (cpu->eax == 0u) goto label_000C0EAA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0EA4u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C0EA4u));
    *(uint32_t*)(cpu->edi + 0x1DCu) = cpu->eax;
    label_000C0EAA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"selectionColor");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0EB7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0EB7u));
    if (cpu->eax == 0u) goto label_000C0F29;
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C0ED8u));
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000C0F01;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'selectionColor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0EF8u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C0EF8u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0EFEu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C0EFEu));
    cpu->esp += 0x14u;
    label_000C0F01:
    cpu->eax = *(uint8_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->ecx <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x14u);
    cpu->eax <<= 8u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x1E0u) = cpu->eax;
    label_000C0F29:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"selectionLineColor");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0F36u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0F36u));
    if (cpu->eax == 0u) goto label_000C0FA8;
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C0F57u));
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000C0F80;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'selectionLineColor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0F77u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C0F77u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0F7Du)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C0F7Du));
    cpu->esp += 0x14u;
    label_000C0F80:
    cpu->eax = *(uint8_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x14u);
    cpu->ecx <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->eax <<= 8u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x1E4u) = cpu->eax;
    label_000C0FA8:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"chatlike");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0FB5u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0FB5u));
    if (cpu->eax == 0u) goto label_000C0FD7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0FC2u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4C0FC2u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->edi + 0x1CCu) = cpu->edx & 0xFFu;
    *(uint32_t*)(cpu->edi + 0x1B0u) = 0x40u;
    label_000C0FD7:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"maxItems");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0FE4u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C0FE4u));
    if (cpu->eax == 0u) goto label_000C0FF7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0FF1u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4C0FF1u));
    *(uint32_t*)(cpu->edi + 0x1B0u) = cpu->eax;
    label_000C0FF7:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C0FFFu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4C0FFFu));
    lift_push32(cpu, (uintptr_t)"addstring");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C100Bu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4C100Bu));
    if (cpu->eax == 0u) goto label_000C1088;
    cpu->ebp = cpu->esi + 0x10u;
    label_000C1012:
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]); lift_push32(cpu, (uintptr_t)"%s %x"); lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x44u) = 0u;
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C102Au));
    cpu->esp += 0x10u;
    if (cpu->eax != 2u) goto label_000C1059;
    cpu->ecx = (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1042u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4C1042u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000C104A;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C104A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1057u)); sfera_sub_004C0590(cpu, LIFT_CODE_TOKEN_VA(0x4C1057u));
    goto label_000C1078;
    label_000C1059:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'addstring'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C106Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C106Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1075u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1075u));
    cpu->esp += 0x14u;
    label_000C1078:
    lift_push32(cpu, (uintptr_t)"addstring");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1084u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1084u));
    if (cpu->eax != 0u) goto label_000C1012;
    label_000C1088:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C108Fu)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x4C108Fu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1096u)); sfera_sub_004BFA70(cpu, LIFT_CODE_TOKEN_VA(0x4C1096u));
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C10A2u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4C10A2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C10C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000C10F0;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC10F0u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC10F0u));
    label_000C10F0:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x200u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x204u) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1110(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C111Bu)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C111Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->ebp = cpu->eax + cpu->edx;
    *(uint32_t*)(cpu->esi + 0x208u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x20Cu) = cpu->ebx;
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_graphics_runtime.display_width) goto label_000C1148;
    cpu->edi -= cpu->eax;
    label_000C1148:
    if ((int32_t)cpu->edx < 0) goto label_000C1150;
    if ((int32_t)cpu->edi >= 0) goto label_000C1152;
    label_000C1150:
    cpu->edi = 0u;
    label_000C1152:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x204u);
    cpu->ebp = cpu->esi + cpu->ebx;
    cpu->eax = cpu->esi;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_graphics_runtime.display_height) goto label_000C1167;
    cpu->eax -= cpu->ebx;
    label_000C1167:
    if ((int32_t)cpu->esi < 0) goto label_000C116F;
    if ((int32_t)cpu->eax >= 0) goto label_000C1171;
    label_000C116F:
    cpu->eax = 0u;
    label_000C1171:
    if (cpu->edi != cpu->edx) goto label_000C1179;
    if (cpu->eax == cpu->esi) goto label_000C1184;
    label_000C1179:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C1184:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xD8u);
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C11C5u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4C11C5u));
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C11E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi != 0u) goto label_000C11EB;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C11EB:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"RIGHT_X");

    if (cpu->eax != 0u) goto label_000C1209;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C1209:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"RIGHT_Y");

    if (cpu->eax != 0u) goto label_000C1220;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 2u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C1220:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"CENTER_X");

    if (cpu->eax != 0u) goto label_000C1237;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C1237:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"CENTER_Y");

    if (cpu->eax != 0u) goto label_000C124E;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 8u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C124E:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"CENTER");

    if (cpu->eax != 0u) goto label_000C1265;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C1265:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"RIGHT");

    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xFFFFFFFDu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 3u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1280(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1288u)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1288u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x204u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edx += cpu->eax;
    g_sfera_screen_clip_runtime.left = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx += cpu->ecx;
    g_sfera_screen_clip_runtime.top = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edx += cpu->eax;
    g_sfera_screen_clip_runtime.right = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1CCu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax += cpu->ecx;
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C12E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C12E8u)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C12E8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 8u));
    cpu->eax += *(uint32_t*)(cpu->esi + 0x204u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edx += cpu->ecx;
    g_sfera_screen_clip_runtime.left = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx += cpu->eax;
    g_sfera_screen_clip_runtime.top = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1DCu);
    cpu->edx += cpu->ecx;
    g_sfera_screen_clip_runtime.right = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1F4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1CCu);
    cpu->esi = lift_pop32(cpu);
    cpu->ecx += cpu->eax;
    g_sfera_screen_clip_runtime.bottom = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1350(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C135Bu)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C135Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = (int32_t)(cpu->ecx) >> 5u;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x1F4u));
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x204u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->esp -= 8u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->eax <<= 24u;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C13CEu)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4C13CEu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C13E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x210u);
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x214u)) goto label_000C1457;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C13F9u)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C13F9u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x1F4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x204u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edi = (int32_t)(cpu->edi) >> 5u;
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebx += cpu->eax;
    cpu->edx += cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) < (int32_t)cpu->eax) goto label_000C1457;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) >= (int32_t)cpu->ebx) goto label_000C1457;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000C1457;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000C1457;
    cpu->eax -= cpu->ecx;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ebp); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    if ((int32_t)cpu->eax < 0) goto label_000C1457;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_000C145D;
    label_000C1457:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    label_000C145D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1470(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = cpu->esi + 0x224u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1493u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4C1493u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C149Au)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C149Au));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x204u);
    cpu->edx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = 1.0;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    cpu->edx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C14F8u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4C14F8u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->esi -= *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    cpu->edi -= *(uint32_t*)(cpu->eax + 0xCu);
    cpu->esi -= *(uint32_t*)(cpu->eax);
    cpu->edi -= *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 0x8Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(2u) - (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1549u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4C1549u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Cu));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_000C1571;
    if (cpu->ebx >= cpu->esi) goto label_000C1571;
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->ebx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000C1571:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    if ((((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_000C1587;
    if (cpu->edx >= cpu->edi) goto label_000C1587;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edi;
    cpu->ebp -= cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    label_000C1587:
    if ((((cpu->ecx & 0xFFu)) & (4u)) == 0u) goto label_000C1596;
    if (cpu->ebx >= cpu->esi) goto label_000C1596;
    cpu->esi -= cpu->ebx;
    cpu->esi >>= 1u;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    label_000C1596:
    if ((((cpu->ecx & 0xFFu)) & (8u)) == 0u) goto label_000C15A6;
    if (cpu->edx >= cpu->edi) goto label_000C15A6;
    cpu->edi -= cpu->edx;
    cpu->edi >>= 1u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    label_000C15A6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C15B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000C1603;
    if (cpu->ecx > 0x7FFFFFFu) goto label_000C15D5;
    cpu->ecx <<= 5u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C15CEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C15CEu));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000C1603;
    label_000C15D5:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC1603u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xC1603u));
    label_000C1603:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1610(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C161Cu)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4C161Cu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_000C1654;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax != 0u) goto label_000C1654;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1649u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1649u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C164Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C164Fu));
    cpu->esp += 0x10u;
    cpu->eax = cpu->esi;
    label_000C1654:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1676u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4C1676u));
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C1790;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x210u);
    if (((cpu->eax) & (0xFFFFFFE0u)) == 0u) goto label_000C1790;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C16B9u)); sfera_sub_004C13E0(cpu, LIFT_CODE_TOKEN_VA(0x4C16B9u));
    *(uint32_t*)(cpu->esi + 0x220u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->ecx = (int32_t)(cpu->ecx) >> 5u;
    if (cpu->eax >= cpu->ecx) goto label_000C172B;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x210u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 5u;
    if (*(uint8_t*)(cpu->edx + cpu->edi + 0x1Cu) == 0u) goto label_000C172B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    if (((*(uint8_t*)(cpu->edx + 0xCu)) & (1u)) == 0u) goto label_000C172B;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->eax = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x1BBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C171Cu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4C171Cu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1723u)); sfera_sub_004C1190(cpu, LIFT_CODE_TOKEN_VA(0x4C1723u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    label_000C172B:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000C1754;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC1754u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xC1754u));
    label_000C1754:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax > (int32_t)cpu->ebx) goto label_000C177C;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_000C177C;
    if ((int32_t)cpu->ecx > (int32_t)cpu->ebp) goto label_000C177C;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)cpu->ebp < (int32_t)cpu->eax) goto label_000C178D;
    label_000C177C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    if (((*(uint8_t*)(cpu->ecx + 0xCu)) & (3u)) == 0u) goto label_000C178D;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC178Du)); sfera_sub_004C1190(cpu, LIFT_CODE_TOKEN_RVA(0xC178Du));
    label_000C178D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C1790:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C17B0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C17BDu)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C17BDu));
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x204u);
    cpu->ebp += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->ebx += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->esp -= 8u;
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1814u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4C1814u));
    if (*(uint8_t*)(cpu->esi + 0x1BCu) == 0u) goto label_000C18CD;
    if (*(uint32_t*)(cpu->esi + 0x64u) == 0u) goto label_000C18CD;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x68u) < 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x54u;
    if (sub_pred[0]) goto label_000C1839;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000C183B;
    label_000C1839:
    cpu->eax = cpu->edi;
    label_000C183B:
    cpu->ecx = cpu->esi + 0x1C0u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x1E8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1861u)); sfera_sub_004C1510(cpu, LIFT_CODE_TOKEN_VA(0x4C1861u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1868u)); sfera_sub_004C1280(cpu, LIFT_CODE_TOKEN_VA(0x4C1868u));
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000C1870;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_000C1870:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x8Cu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax - 2u) & 0xFFu);
    cpu->ecx <<= 24u;
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->ecx;
    cpu->ecx = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 8u;
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C18CCu)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_VA(0x4C18CCu));
    cpu->edi = lift_pop32(cpu);
    label_000C18CD:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C18E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    if (cpu->ebx >= cpu->eax) goto label_000C1A2F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1909u)); sfera_sub_004C10C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1909u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1F4u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x204u);
    cpu->ebp += *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->esp -= 8u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1967u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4C1967u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x210u);
    cpu->ebx <<= 5u;
    cpu->eax = cpu->ebx + cpu->ecx;
    if (*(uint32_t*)(cpu->ebx + cpu->ecx + 0x10u) == 0u) goto label_000C1A2D;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000C1986;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000C1986:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1E4u);
    cpu->ecx = cpu->esi + 0x1D4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->ecx = cpu->esi + 0x1F0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C19ACu)); sfera_sub_004C1510(cpu, LIFT_CODE_TOKEN_VA(0x4C19ACu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C19B8u)); sfera_sub_004C12E0(cpu, LIFT_CODE_TOKEN_VA(0x4C19B8u));
    cpu->ebx += *(uint32_t*)(cpu->esi + 0x210u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint8_t*)(cpu->ebx + 0x1Cu) != 0u) goto label_000C19CE;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B8u);
    label_000C19CE:
    if (*(uint32_t*)(cpu->ebx + 0x14u) < 0x10u) goto label_000C19D6;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    label_000C19D6:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x8Cu));
    cpu->eax <<= 24u;
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D8u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    lift_push32(cpu, 0u);
    cpu->eax += cpu->ebp;
    cpu->eax += *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)(2u) - (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = cpu->ecx & 0xFFu;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC1A2Du)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_RVA(0xC1A2Du));
    label_000C1A2D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000C1A2F:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C1ADC;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C1ADC;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1A5Du)); sfera_sub_004C1110(cpu, LIFT_CODE_TOKEN_VA(0x4C1A5Du));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1A64u)); sfera_sub_004C1470(cpu, LIFT_CODE_TOKEN_VA(0x4C1A64u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1A6Bu)); sfera_sub_004C17B0(cpu, LIFT_CODE_TOKEN_VA(0x4C1A6Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->edi=0u;
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    if (cpu->eax == 0u) goto label_000C1AC2;
    label_000C1A80:
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0x220u)) goto label_000C1A98;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    goto label_000C1AA6;
    label_000C1A98:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    label_000C1AA6:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1AAEu)); sfera_sub_004C18E0(cpu, LIFT_CODE_TOKEN_VA(0x4C1AAEu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x210u);
    ++cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    if (cpu->edi < cpu->edx) goto label_000C1A80;
    label_000C1AC2:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1AC9u)); sfera_sub_004C1350(cpu, LIFT_CODE_TOKEN_VA(0x4C1AC9u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi += 0x224u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1ADBu)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4C1ADBu));
    cpu->edi = lift_pop32(cpu);
    label_000C1ADC:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1AE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (cpu->edi != cpu->eax) goto label_000C1AFD;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C1AFD:
    if (cpu->edi <= 0x7FFFFFFu) goto label_000C1B10;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4C1AFDu), "std::length_error");
    label_000C1B10:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1B19u)); sfera_sub_004C15B0(cpu, LIFT_CODE_TOKEN_VA(0x4C1B19u));
    cpu->edi <<= 5u;
    cpu->edi += cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C1B30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0x120u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x9Cu) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x13Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    if (!sub_pred[1]) goto label_000C1B86;
    lift_push32(cpu, 0x16u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MenuListControl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1B7Du)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1B7Du));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1B83u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1B83u));
    cpu->esp += 0x10u;
    label_000C1B86:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xF4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1B9Eu)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4C1B9Eu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"topSprite");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1BABu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C1BABu));
    if (cpu->eax == 0u) goto label_000C1C0B;
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1BBDu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C1BBDu));
    if (cpu->eax == 0u) goto label_000C1C0B;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1BCDu)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4C1BCDu));
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_000C1BFF;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1BF6u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1BF6u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1BFCu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1BFCu));
    cpu->esp += 0x10u;
    label_000C1BFF:
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    goto label_000C1C3F;
    label_000C1C0B:
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"topSprite"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1C36u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1C36u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1C3Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1C3Cu));
    cpu->esp += 0x1Cu;
    label_000C1C3F:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"middleSprite");
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1C64u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C1C64u));
    if (cpu->eax == 0u) goto label_000C1CC4;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1C76u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C1C76u));
    if (cpu->eax == 0u) goto label_000C1CC4;
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1C86u)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4C1C86u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_000C1CB8;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1CAFu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1CAFu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1CB5u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1CB5u));
    cpu->esp += 0x10u;
    label_000C1CB8:
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    goto label_000C1CF8;
    label_000C1CC4:
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"middleSprite"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1CEFu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1CEFu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1CF5u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1CF5u));
    cpu->esp += 0x1Cu;
    label_000C1CF8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"middleHoveredSprite");
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1F4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1D1Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C1D1Du));
    if (cpu->eax == 0u) goto label_000C1D4E;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1D2Fu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C1D2Fu));
    if (cpu->eax == 0u) goto label_000C1D4E;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1D46u)); sfera_sub_004C1610(cpu, LIFT_CODE_TOKEN_VA(0x4C1D46u));
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    goto label_000C1D5A;
    label_000C1D4E:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->ecx;
    label_000C1D5A:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"bottomSprite");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1D67u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C1D67u));
    if (cpu->eax == 0u) goto label_000C1DC7;
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1D79u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4C1D79u));
    if (cpu->eax == 0u) goto label_000C1DC7;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1D89u)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4C1D89u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_000C1DBB;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1DB2u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1DB2u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1DB8u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1DB8u));
    cpu->esp += 0x10u;
    label_000C1DBB:
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    goto label_000C1DFB;
    label_000C1DC7:
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"bottomSprite"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1DF2u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1DF2u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1DF8u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1DF8u));
    cpu->esp += 0x1Cu;
    label_000C1DFB:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1F8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"normalColor");
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1FCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1E2Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C1E2Bu));
    if (cpu->eax == 0u) goto label_000C1EAE;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C1E47u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000C1E89;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"normalColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1E80u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1E80u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1E86u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1E86u));
    cpu->esp += 0x1Cu;
    label_000C1E89:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x18u);
    cpu->eax|=0xFFFFFF00u;
    cpu->eax <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    goto label_000C1EE2;
    label_000C1EAE:
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"normalColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1ED9u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1ED9u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1EDFu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1EDFu));
    cpu->esp += 0x1Cu;
    label_000C1EE2:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"disabledColor");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1EEFu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C1EEFu));
    if (cpu->eax == 0u) goto label_000C1F6C;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C1F0Bu));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000C1F4D;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"disabledColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1F44u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1F44u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1F4Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1F4Au));
    cpu->esp += 0x1Cu;
    label_000C1F4D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x18u);
    cpu->eax|=0xFFFFFF00u;
    cpu->eax <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->edx;
    goto label_000C1F72;
    label_000C1F6C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    label_000C1F72:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"hoveredColor");
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1F85u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C1F85u));
    if (cpu->eax == 0u) goto label_000C2003;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C1FA1u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000C1FE3;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"hoveredColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1FDAu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C1FDAu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C1FE0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C1FE0u));
    cpu->esp += 0x1Cu;
    label_000C1FE3:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x18u);
    cpu->edx|=0xFFFFFF00u;
    cpu->edx <<= 8u;
    cpu->edx|=cpu->eax;
    cpu->edx <<= 8u;
    cpu->edx |= cpu->ecx;
    goto label_000C2009;
    label_000C2003:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B0u);
    label_000C2009:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"listItemTextMargin");
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C201Cu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C201Cu));
    if (cpu->eax == 0u) goto label_000C20F1;
    cpu->eax = cpu->esi + 0x1E0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1DCu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x1D8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x1D4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C2049u));
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000C208B;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"listItemTextMargin"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2082u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C2082u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2088u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C2088u));
    cpu->esp += 0x1Cu;
    label_000C208B:
    cpu->ebx = 0u;
    label_000C208D:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"listItemTextFormat");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C209Au)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C209Au));
    if (cpu->eax == 0u) goto label_000C210D;
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C20ABu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C20ABu));
    if (cpu->eax == 0u) goto label_000C210D;
    cpu->ebx = 0u;
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C20BEu)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4C20BEu));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_000C2113;
    label_000C20C6:
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C20D3u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C20D3u));
    if (cpu->eax == 0u) goto label_000C20E6;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C20E0u)); sfera_sub_004C11E0(cpu, LIFT_CODE_TOKEN_VA(0x4C20E0u));
    *(uint32_t*)(cpu->esi + 0x1E4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1E4u)) | (uint64_t)(cpu->eax);
    label_000C20E6:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_000C20C6;
    goto label_000C2113;
    label_000C20F1:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->ebx;
    goto label_000C208D;
    label_000C210D:
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->ebx;
    label_000C2113:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"needShowTitle");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2120u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C2120u));
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C22E0;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"titleColor");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2141u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C2141u));
    if (cpu->eax == 0u) goto label_000C21C2;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C215Du));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000C21A3;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"titleColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C219Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C219Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C21A0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C21A0u));
    cpu->esp += 0x1Cu;
    label_000C21A3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x18u);
    cpu->eax|=0xFFFFFF00u;
    cpu->eax <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->edx;
    goto label_000C21C8;
    label_000C21C2:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    label_000C21C8:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"titleTextMargin");
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C21DBu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C21DBu));
    if (cpu->eax == 0u) goto label_000C22BB;
    cpu->ecx = cpu->esi + 0x1CCu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x1C8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x1C4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1C0u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C2208u));
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000C224E;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"titleTextMargin"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2245u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C2245u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C224Bu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C224Bu));
    cpu->esp += 0x1Cu;
    label_000C224E:
    cpu->ebx = 0u;
    label_000C2250:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"titleTextFormat");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C225Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C225Du));
    if (cpu->eax == 0u) goto label_000C22DA;
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C226Eu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C226Eu));
    if (cpu->eax == 0u) goto label_000C22DA;
    cpu->ebx = 0u;
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2281u)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4C2281u));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_000C22E0;
    label_000C2290:
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C229Du)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4C229Du));
    if (cpu->eax == 0u) goto label_000C22B0;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C22AAu)); sfera_sub_004C11E0(cpu, LIFT_CODE_TOKEN_VA(0x4C22AAu));
    *(uint32_t*)(cpu->esi + 0x1D0u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1D0u)) | (uint64_t)(cpu->eax);
    label_000C22B0:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_000C2290;
    goto label_000C22E0;
    label_000C22BB:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ebx;
    goto label_000C2250;
    label_000C22DA:
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->ebx;
    label_000C22E0:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"maxItems");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C22EDu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4C22EDu));
    if (cpu->eax == 0u) goto label_000C2351;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C22FFu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ecx;
    if (cpu->eax == 1u) goto label_000C235B;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"maxItems"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2346u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4C2346u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C234Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4C234Cu));
    cpu->esp += 0x1Cu;
    goto label_000C235B;
    label_000C2351:
    *(uint32_t*)(cpu->esi + 0x198u) = 1u;
    label_000C235B:
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x8Cu) < 2u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x220u) = cpu->eax;
    if (!sub_pred[0]) goto label_000C2377;
    *(uint8_t*)(cpu->esi + 0x8Cu) = 2u;
    label_000C2377:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2383u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4C2383u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x120u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C23B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000C23E4;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    (void)cpu;
    label_000C23C0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C23CCu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4C23CCu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x1Cu));
    *(uint8_t*)(cpu->edi + 0x1Cu) = cpu->eax & 0xFFu;
    cpu->esi += 0x20u;
    cpu->edi += 0x20u;
    if (cpu->esi != cpu->ebx) goto label_000C23C0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000C23E4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C23F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    label_000C2430:
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000C2499;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000C245D;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2457u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4C2457u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1Cu));
    *(uint8_t*)(cpu->esi + 0x1Cu) = cpu->eax & 0xFFu;
    label_000C245D:
    cpu->esi += 0x20u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    cpu->edi += 0x20u;
    goto label_000C2430;
    label_000C2499:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C246B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->esi == cpu->edi) goto label_000C2490;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    label_000C2480:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2489u)); sfera_sub_004A3E00(cpu, LIFT_CODE_TOKEN_VA(0x4C2489u));
    cpu->esi += 0x20u;
    if (cpu->esi != cpu->edi) goto label_000C2480;
    label_000C2490:
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2499u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4C2499u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C24B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->edi) goto label_000C24E9;
    label_000C24C0:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000C24D1;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C24CEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C24CEu));
    cpu->esp += 4u;
    label_000C24D1:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi += 0x20u;
    if (cpu->esi != cpu->edi) goto label_000C24C0;
    label_000C24E9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C24F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    label_000C2530:
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000C2599;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000C255D;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2557u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4C2557u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1Cu));
    *(uint8_t*)(cpu->esi + 0x1Cu) = cpu->eax & 0xFFu;
    label_000C255D:
    cpu->esi += 0x20u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    cpu->edi += 0x20u;
    goto label_000C2530;
    label_000C2599:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C256B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->esi == cpu->edi) goto label_000C2590;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    label_000C2580:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2589u)); sfera_sub_004A3E00(cpu, LIFT_CODE_TOKEN_VA(0x4C2589u));
    cpu->esi += 0x20u;
    if (cpu->esi != cpu->edi) goto label_000C2580;
    label_000C2590:
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2599u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4C2599u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C25B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C25C6u)); sfera_sub_004C24B0(cpu, LIFT_CODE_TOKEN_VA(0x4C25C6u));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2695(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C269Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C269Eu));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C26AAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4C26AAu));
    lift_trap(cpu, 0x4C26AAu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004C26B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C26CBu)); sfera_sub_004C24F0(cpu, LIFT_CODE_TOKEN_VA(0x4C26CBu));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2710(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000C2710;
    label_000C25D0:
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
    if (cpu->eax <= 0x7FFFFFFu) goto label_000C2612;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4C25D0u), "std::length_error");
    label_000C2612:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->ecx = (int32_t)(cpu->ecx) >> 5u;
    if (cpu->ecx >= cpu->eax) goto label_000C2681;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2629u)); sfera_sub_004C15B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2629u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2647u)); sfera_sub_004C23F0(cpu, LIFT_CODE_TOKEN_VA(0x4C2647u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->edx;
    cpu->edi -= cpu->ecx;
    if (cpu->ecx==0u) goto label_000C266C;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2661u)); sfera_sub_004C24B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2661u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2669u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C2669u));
    cpu->esp += 4u;
    label_000C266C:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax <<= 5u;
    cpu->eax += cpu->ebx;
    cpu->edi &= 0xFFFFFFE0u;
    cpu->edi += cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_000C2681:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C2710:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->eax -= cpu->esi;
    cpu->edi = 0x7FFFFFFu;
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000C2736;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4C2710u), "std::length_error");
    label_000C2736:
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx -= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    if (cpu->eax <= cpu->edx) goto label_000C276A;
    cpu->esi = cpu->edx;
    cpu->esi >>= 1u;
    cpu->edi = 0x7FFFFFFu;
    cpu->edi -= cpu->esi;
    if (cpu->edi >= cpu->edx) goto label_000C2757;
    cpu->edx = 0u;
    goto label_000C2759;
    label_000C2757:
    cpu->edx += cpu->esi;
    label_000C2759:
    if (cpu->edx >= cpu->eax) goto label_000C275F;
    cpu->edx = cpu->eax;
    label_000C275F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    goto label_000C25D0;
    label_000C276A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2778u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4C2778u));
    cpu->eax = 0u;
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::CMenuListControl*>(cpu->esi));
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x210u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x214u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x218u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x220u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x50u) = 0x15u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C27C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::CMenuListControl*>(cpu->esi));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x210u);
    if (cpu->ecx == 0u) goto label_000C27FA;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x21Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x214u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C27EBu)); sfera_sub_004C24B0(cpu, LIFT_CODE_TOKEN_VA(0x4C27EBu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x210u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C27F7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C27F7u));
    cpu->esp += 4u;
    label_000C27FA:
    *(uint32_t*)(cpu->esi + 0x210u) = 0u;
    *(uint32_t*)(cpu->esi + 0x214u) = 0u;
    *(uint32_t*)(cpu->esi + 0x218u) = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004D37D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C2830(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->edi >= cpu->eax) goto label_000C28B2;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx > cpu->edi) goto label_000C28B2;
    cpu->edi -= cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000C2877;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC2877u)); sfera_sub_004C2710(cpu, LIFT_CODE_TOKEN_RVA(0xC2877u));
    label_000C2877:
    cpu->edi &= 0xFFFFFFE0u;
    cpu->edi += *(uint32_t*)(cpu->esi);
    cpu->ebx = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if (cpu->edi == cpu->eax) goto label_000C28F6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->edi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->edi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C28AAu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4C28AAu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x1Cu));
    *(uint8_t*)(cpu->edi + 0x1Cu) = cpu->eax & 0xFFu;
    goto label_000C28F6;
    label_000C28B2:
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000C28C0;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC28C0u)); sfera_sub_004C2710(cpu, LIFT_CODE_TOKEN_RVA(0xC28C0u));
    label_000C28C0:
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    if (cpu->ebx == cpu->eax) goto label_000C28F6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ebx + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    *(uint8_t*)(cpu->ebx) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C28F0u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4C28F0u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1Cu));
    *(uint8_t*)(cpu->ebx + 0x1Cu) = cpu->ecx & 0xFFu;
    label_000C28F6:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0x20u) + (uint64_t)(0u);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2910(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x38u;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x214u);
    cpu->edx -= *(uint32_t*)(cpu->eax + 0x210u);
    cpu->ecx = cpu->eax + 0x210u;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->edx >= *(uint32_t*)(cpu->eax + 0x198u)) goto label_000C29FB;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x9Cu);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->edi = *(uint32_t*)(cpu->eax + 0x1F4u);
    *(uint32_t*)(cpu->eax + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x2Cu)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    *(uint32_t*)(cpu->eax + 0x208u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x20Cu) = cpu->esi;
    cpu->eax = cpu->edi + cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    *(uint8_t*)(cpu->esp + 0x14u) = 0u;
    cpu->ecx = cpu->eax + 1u;
    label_000C29B5:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C29B5;
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C29C9u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C29C9u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x4Cu));
    *(uint8_t*)(cpu->esp + 0x30u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x44u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C29E7u)); sfera_sub_004C2830(cpu, LIFT_CODE_TOKEN_VA(0x4C29E7u));
    if (*(uint32_t*)(cpu->esp + 0x28u) < 0x10u) goto label_000C29FB;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C29F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C29F8u));
    cpu->esp += 4u;
    label_000C29FB:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2A28u)); sfera_sub_004C27C0(cpu, LIFT_CODE_TOKEN_VA(0x4C2A28u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C2A38;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2A35u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C2A35u));
    cpu->esp += 4u;
    label_000C2A38:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->eax = cpu->edx + 0xFFFFE443u;
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    if (cpu->eax > 4u) goto label_000C2C4D;
    switch (cpu->eax) {
        case 0u: goto label_000C2A95;
        case 1u: goto label_000C2B2D;
        case 2u: goto label_000C2B48;
        case 3u: goto label_000C2BA5;
        case 4u: goto label_000C2BD4;
        default: lift_trap(cpu, 0x4C2A8Eu, "resolved jump-table index out of range"); return;
    }
label_000C2A95: ;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0x208u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1FCu);
    cpu->edx += *(uint32_t*)(cpu->esi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x20Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->edi -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->edi = (int32_t)(cpu->edi) >> 5u;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x1F4u));
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x208u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x210u);
    if (cpu->eax == cpu->ecx) goto label_000C2B23;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2B02u)); sfera_sub_004C23B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2B02u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x21Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2B1Du)); sfera_sub_004C24B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2B1Du));
    *(uint32_t*)(cpu->esi + 0x214u) = cpu->edi;
    label_000C2B23:
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2B2D:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((cpu->ecx!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2B3Eu)); sfera_sub_004C2910(cpu, LIFT_CODE_TOKEN_VA(0x4C2B3Eu));
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2B48:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    if (cpu->edi >= cpu->eax) goto label_000C2B9B;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x210u);
    cpu->ecx = cpu->edi;
    cpu->ecx <<= 5u;
    if (*(uint8_t*)(cpu->ecx + cpu->edx + 0x1Cu) == 0u) goto label_000C2B9B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = cpu->esp + 0x30u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0x1BBCu;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC2B9Bu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xC2B9Bu));
    label_000C2B9B:
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2BA5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    if (cpu->edi >= cpu->eax) goto label_000C2BCA;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x210u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((cpu->ecx!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->edi <<= 5u;
    *(uint8_t*)(cpu->edi + cpu->edx + 0x1Cu) = cpu->ecx & 0xFFu;
    label_000C2BCA:
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2BD4:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x214u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x210u);
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    if (cpu->edi >= cpu->eax) goto label_000C2C46;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    *(uint8_t*)(cpu->esp + 0x14u) = 0u;
    cpu->ebp = cpu->eax + 1u;
    label_000C2C01:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000C2C01;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2C15u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4C2C15u));
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    cpu->ecx <<= 5u;
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x210u);
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2C32u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4C2C32u));
    if (*(uint32_t*)(cpu->esp + 0x28u) < 0x10u) goto label_000C2C46;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2C43u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C2C43u));
    cpu->esp += 4u;
    label_000C2C46:
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2C4D:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC2C57u)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_RVA(0xC2C57u));
    label_000C2C57:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2C90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->edi) goto label_000C2DB5;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    cpu->ebx -= cpu->ecx;
    cpu->ebx = (int32_t)(cpu->ebx) >> 5u;
    if (cpu->ebx != 0u) goto label_000C2CEB;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == cpu->ecx) goto label_000C2DB4;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2CCBu)); sfera_sub_004C23B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2CCBu));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2CE0u)); sfera_sub_004C24B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2CE0u));
    cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C2CEB:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi);
    cpu->eax -= cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    if (cpu->ebx > cpu->eax) goto label_000C2D2E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2D05u)); sfera_sub_004C23B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2D05u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2D18u)); sfera_sub_004C24B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2D18u));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax -= *(uint32_t*)(cpu->edi);
    cpu->ebp = lift_pop32(cpu);
    cpu->eax &= 0xFFFFFFE0u;
    cpu->eax += *(uint32_t*)(cpu->esi);
    cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C2D2E:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx -= cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    if (cpu->ebx > cpu->edx) goto label_000C2D70;
    cpu->eax <<= 5u;
    cpu->ebx = cpu->ecx + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2D4Du)); sfera_sub_004C23B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2D4Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2D64u)); sfera_sub_004C24F0(cpu, LIFT_CODE_TOKEN_VA(0x4C2D64u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C2D70:
    if (cpu->ebp == 0u) goto label_000C2D8B;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2D80u)); sfera_sub_004C25B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2D80u));
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2D88u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C2D88u));
    cpu->esp += 4u;
    label_000C2D8B:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax -= *(uint32_t*)(cpu->edi);
    cpu->ecx = cpu->esi;
    cpu->eax = (int32_t)(cpu->eax) >> 5u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2D9Bu)); sfera_sub_004C1AE0(cpu, LIFT_CODE_TOKEN_VA(0x4C2D9Bu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C2DB3;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2DB0u)); sfera_sub_004C26B0(cpu, LIFT_CODE_TOKEN_VA(0x4C2DB0u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000C2DB3:
    cpu->ebp = lift_pop32(cpu);
    label_000C2DB4:
    cpu->ebx = lift_pop32(cpu);
    label_000C2DB5:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2DC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2DCEu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4C2DCEu));
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
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B8u);
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1BCu));
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1C0u);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C4u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1CCu);
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1D0u);
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1D4u);
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->eax;
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
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1F0u);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1F4u);
    *(uint32_t*)(cpu->esi + 0x1F4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1F8u);
    *(uint32_t*)(cpu->esi + 0x1F8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1FCu);
    *(uint32_t*)(cpu->esi + 0x1FCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x200u);
    *(uint32_t*)(cpu->esi + 0x200u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x204u);
    *(uint32_t*)(cpu->esi + 0x204u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x208u);
    *(uint32_t*)(cpu->esi + 0x208u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x20Cu);
    cpu->eax = cpu->edi + 0x210u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x210u;
    *(uint32_t*)(cpu->esi + 0x20Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2F48u)); sfera_sub_004C2C90(cpu, LIFT_CODE_TOKEN_VA(0x4C2F48u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x220u);
    *(uint32_t*)(cpu->esi + 0x220u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x224u);
    *(uint32_t*)(cpu->esi + 0x224u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x228u);
    *(uint32_t*)(cpu->esi + 0x228u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x22Cu);
    *(uint32_t*)(cpu->esi + 0x22Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x230u);
    *(uint32_t*)(cpu->esi + 0x230u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x234u);
    *(uint32_t*)(cpu->esi + 0x234u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x238u);
    *(uint32_t*)(cpu->esi + 0x238u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C2FB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0xE3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MenuListControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2FE5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C2FE5u));
    lift_push32(cpu, 0x240u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C2FEFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C2FEFu));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    if (cpu->esi == cpu->ebx) goto label_000C3047;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3009u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4C3009u));
    std::construct_at(reinterpret_cast<SphereUI::CMenuListControl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x210u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x214u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x218u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x20u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C302Eu)); sfera_sub_004C2DC0(cpu, LIFT_CODE_TOKEN_VA(0x4C302Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C3047:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3060(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000C30D8;
    { const double lift_right=(double)*(float*)(cpu->esi + 0x1B0u); const double lift_left=1.0; if (lift_left==lift_right) goto label_000C30D8; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3082u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4C3082u));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x1B8u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x1B8u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1BCu) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(float*)(cpu->esp + 4u) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 4u)))))) / (10000.0));
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->esp + 4u))) * (4.0));
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    *(float*)(cpu->esi + 0x1B0u) = x87_v0;
    x87_v1 = 1.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_000C30D6; }
    *(float*)(cpu->esi + 0x1B0u) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C30D6:
    x87_v0 = x87_v0; 
    label_000C30D8:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C30E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (cpu->edi != cpu->eax) goto label_000C30FD;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C30FD:
    if (cpu->edi <= 0x9249249u) goto label_000C3110;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4C30FDu), "std::length_error");
    label_000C3110:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3119u)); sfera_sub_00402B40(cpu, LIFT_CODE_TOKEN_VA(0x4C3119u));
    cpu->ecx = cpu->edi * 8u;
    cpu->ecx -= cpu->edi;
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->ebx) goto label_000C3166;
    (void)cpu;
    label_000C3150:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C315Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4C315Cu));
    cpu->esi += 0x1Cu;
    cpu->edi += 0x1Cu;
    if (cpu->esi != cpu->ebx) goto label_000C3150;
    label_000C3166:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3170(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    label_000C31B0:
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000C320B;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000C31D7;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC31D7u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xC31D7u));
    label_000C31D7:
    cpu->esi += 0x1Cu;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    cpu->edi += 0x1Cu;
    goto label_000C31B0;
    label_000C320B:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C31E5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->esi == cpu->edi) goto label_000C3202;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    label_000C31F2:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C31FBu)); sfera_sub_004A3E00(cpu, LIFT_CODE_TOKEN_VA(0x4C31FBu));
    cpu->esi += 0x1Cu;
    if (cpu->esi != cpu->edi) goto label_000C31F2;
    label_000C3202:
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C320Bu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4C320Bu));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C324Bu)); sfera_sub_004C3170(cpu, LIFT_CODE_TOKEN_VA(0x4C324Bu));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3250(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3258u)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4C3258u));
    std::construct_at(reinterpret_cast<SphereUI::MiniHelpCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 0xFu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3278u)); sfera_sub_004BC9F0(cpu, LIFT_CODE_TOKEN_VA(0x4C3278u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C3288;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3285u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C3285u));
    cpu->esp += 4u;
    label_000C3288:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3290(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000C3416;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != 0u) goto label_000C32F5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == cpu->ecx) goto label_000C3415;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C32D5u)); sfera_sub_0040A270(cpu, LIFT_CODE_TOKEN_VA(0x4C32D5u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C32EAu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4C32EAu));
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C32F5:
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi);
    cpu->edi -= cpu->ebp;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx > cpu->edi) goto label_000C3364;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C331Fu)); sfera_sub_004C3140(cpu, LIFT_CODE_TOKEN_VA(0x4C331Fu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3332u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4C3332u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C3364:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx -= cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->ecx > cpu->eax) goto label_000C33C1;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edx = cpu->edi * 8u;
    cpu->edx -= cpu->edi;
    cpu->edi = cpu->ecx + (cpu->edx * 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C339Cu)); sfera_sub_004C3140(cpu, LIFT_CODE_TOKEN_VA(0x4C339Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C33B5u)); sfera_sub_004C3170(cpu, LIFT_CODE_TOKEN_VA(0x4C33B5u));
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000C33C1:
    if (cpu->ebp == 0u) goto label_000C33DC;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C33D1u)); sfera_sub_0040A780(cpu, LIFT_CODE_TOKEN_VA(0x4C33D1u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C33D9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C33D9u));
    cpu->esp += 4u;
    label_000C33DC:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C33FCu)); sfera_sub_004C30E0(cpu, LIFT_CODE_TOKEN_VA(0x4C33FCu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000C3414;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3411u)); sfera_sub_004C3230(cpu, LIFT_CODE_TOKEN_VA(0x4C3411u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000C3414:
    cpu->ebp = lift_pop32(cpu);
    label_000C3415:
    cpu->edi = lift_pop32(cpu);
    label_000C3416:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3420(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C342Eu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4C342Eu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1A0u));
    *(uint8_t*)(cpu->esi + 0x1A0u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1A8u);
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1ACu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ecx;
    *(float*)(cpu->esi + 0x1B0u) = (double)*(float*)(cpu->edi + 0x1B0u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B8u);
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1BCu);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1C0u);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C4u);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C8u);
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1CCu));
    cpu->edx = cpu->edi + 0x1D0u;
    *(uint8_t*)(cpu->esi + 0x1CCu) = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x1D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C34D0u)); sfera_sub_004C3290(cpu, LIFT_CODE_TOKEN_VA(0x4C34D0u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1E0u);
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1E4u);
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1E8u);
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1F0u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3520(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x45u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MiniHelpCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3554u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C3554u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C355Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C355Eu));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->esi == 0u) goto label_000C3589;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C357Au)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4C357Au));
    std::construct_at(reinterpret_cast<SphereUI::MiniHelpCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 0xFu;
    goto label_000C358B;
    label_000C3589:
    cpu->esi = 0u;
    label_000C358B:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C359Bu)); sfera_sub_004C3420(cpu, LIFT_CODE_TOKEN_VA(0x4C359Bu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C35C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C35F3u)); sfera_sub_004D51A0(cpu, LIFT_CODE_TOKEN_VA(0x4C35F3u));
    std::construct_at(reinterpret_cast<SphereUI::CMinimapControl*>(cpu->esi));
    sub_pred[0] = *(uint32_t*)(cpu->edi + 0xECu) == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (sub_pred[0]) goto label_000C3625;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC3625u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xC3625u));
    label_000C3625:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3640(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C3648u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4C3648u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::CMinimapControl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 0x14u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3670(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)"arup");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C36A4u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4C36A4u));
    cpu->edx = 0x2Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapControl.cpp";
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C36B9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4C36B9u));
    lift_push32(cpu, 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C36C3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4C36C3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_000C36EF;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C36DEu)); sfera_sub_004C35C0(cpu, LIFT_CODE_TOKEN_VA(0x4C36DEu));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000C36EF:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004C3710(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_004D2DD0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004C3720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::CMinimapControl*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C372Eu)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4C372Eu));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C373E;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4C373Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4C373Bu));
    cpu->esp += 4u;
    label_000C373E:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
