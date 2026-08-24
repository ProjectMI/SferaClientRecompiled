#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>
#include <cstddef>
#include <string.h>


static void sfera_u32_to_sso_decimal(LiftCpu* cpu) {
    const uint32_t destination = cpu->ecx;
    uint32_t value = lift_load32(cpu->edx);
    uint8_t reversed[16]{};
    std::size_t length = 0u;
    do {
        reversed[length++] = static_cast<uint8_t>('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);
    for (std::size_t index = 0u; index != 16u; ++index) {
        const uint8_t output = index < length ? reversed[length - index - 1u] : 0u;
        lift_store8(destination + static_cast<uint32_t>(index), output);
    }
    lift_store32(destination + 0x10u, static_cast<uint32_t>(length));
    lift_store32(destination + 0x14u, 15u);
    cpu->eax = destination;
}

static uint8_t sfera_key_ascii_fold(uint8_t value) { return value >= 'a' && value <= 'z' ? (uint8_t)(value - ('a' - 'A')) : value; }
static int sfera_key_name_equals(uint32_t address, const char* literal) { if (!address || !literal) { return 0; } for (uint32_t index = 0;; ++index) { const uint8_t lhs = sfera_key_ascii_fold(lift_load8(address + index)); const uint8_t rhs = sfera_key_ascii_fold((uint8_t)literal[index]); if (lhs != rhs) { return 0; } if (!rhs) { return 1; } } }
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A10u);
    lift_store32(cpu->ecx, 0x31564955u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000B9A6B;
    lift_push32(cpu, cpu->esi);
    label_000B9A26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A26u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edx + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B9A31;
    cpu->eax = lift_load32(cpu->eax);
    label_000B9A31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A31u);
    cpu->esi = cpu->edi;
    cpu->esi -= cpu->eax;
    label_000B9A35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A35u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000B9A35;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edx + 0x24u)))));
    cpu->eax = lift_load32(cpu->edx + 0x18u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 1u);
    cpu->edi = (uint32_t)(cpu->eax + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width)))));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edx + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height)))));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10))) goto label_000B9A26;
    cpu->esi = lift_pop32(cpu);
    label_000B9A6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A6Bu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A70u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000B9A7B;
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B9A7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A7Bu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000B9AB5;
    cpu->edi = native_function_address32(&::_stricmp);
    cpu->edi = cpu->edi;
    label_000B9A90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A90u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000B9AA0;
    cpu->eax = lift_load32(cpu->eax);
    label_000B9AA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AA0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xB9AA4u), LIFT_CODE_TOKEN_RVA(0xB9AA2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AA4u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B9ABB;
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head))) goto label_000B9A90;
    label_000B9AB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AB5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B9ABB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9ABBu);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AD0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B9AF9;
    label_000B9AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AE0u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x24u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000B9AF3;
    if ((uint8_t)(lift_load8(cpu->edx + 0x48u)) == (uint8_t)(0u)) goto label_000B9AFE;
    label_000B9AF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AF3u);
    cpu->ecx = lift_load32(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B9AE0;
    label_000B9AF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AF9u);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B9AFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9AFEu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B10u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_000B9B4D;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    label_000B9B28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B28u);
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000B9B39;
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(cpu->eax);
    label_000B9B39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B39u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = (uint32_t)(cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B9B49;
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(cpu->eax);
    label_000B9B49: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B49u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_000B9B28;
    label_000B9B4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B4Du);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B60u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9B77u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000B9B91;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB9B91u);
    label_000B9B91: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B91u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9BB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000B9C2E;
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9C08u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, 0u);
    cpu->edi += 0x1Cu;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esp + 0x24u, 1u);
    lift_store8(cpu->ecx, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB9C2Eu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000B9C2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9C2Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9C50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000B9CCE;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CA8u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, 0u);
    cpu->edi += 0x1Cu;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esp + 0x28u, 1u);
    lift_store8(cpu->ecx, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB9CCEu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000B9CCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CCEu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9D00u);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(g_sfera_interface_runtime.cross_enabled) == (uint32_t)(cpu->edi)) goto label_000B9F33;
    cpu->ecx = lift_load32(cpu->ebx + 0x9Cu);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000B9D3A;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB9D3Au); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000B9D3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9D3Au);
    cpu->eax = lift_load32(cpu->ebx + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebx + 0x28u);
    cpu->edx = lift_load32(cpu->ebx + 0x34u);
    cpu->edx += lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x2Cu);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx += cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->eax))) goto label_000B9F33;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    goto label_000B9D82;
    label_000B9D80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9D80u);
    cpu->edi = 0u;
    label_000B9D82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9D82u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000B9F18;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000B9F18;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0xE0u)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B9DB5;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x11Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B9F18;
    label_000B9DB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9DB5u);
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) != 0u) goto label_000B9F18;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000B9F18;
    if ((uint8_t)(lift_load8(cpu->esi + 0xE1u)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_000B9F18;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000B9DF9;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB9DF9u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000B9DF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9DF9u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_load32(cpu->esi + 0x28u);
    cpu->esi = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->edi + cpu->eax);
    cpu->ebp = (uint32_t)(cpu->esi + cpu->ecx);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000B9F18;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x38u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_000B9F18;
    cpu->ebx = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000B9F14;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x3Cu)) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000B9F14;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000B9E7C;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x38u)) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000B9E7A;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000B9E7A;
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_000B9E76;
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xACu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9E71u); lift_push32(cpu, r); sfera_sub_004B9B60(cpu,r); if (cpu->eip != r) return; }
    goto label_000B9F18;
    label_000B9E76: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9E76u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_000B9E7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9E7Au);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000B9E7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9E7Cu);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000B9E9C;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x38u))) goto label_000B9E9C;
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000B9E9C;
    cpu->ebx = lift_load32(cpu->esp + 0x4Cu);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x3Cu))) goto label_000B9E98;
    cpu->edx = cpu->edi;
    goto label_000B9ED8;
    label_000B9E98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9E98u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_000B9E9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9E9Cu);
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000B9EC6;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000B9EC4;
    cpu->edx = cpu->esi;
    label_000B9EAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9EAAu);
    cpu->edx -= cpu->ebx;
    label_000B9EAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9EACu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    cpu->esi = lift_load32(cpu->esp + 0x4Cu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000B9ED0;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000B9ECE;
    cpu->eax -= cpu->edi;
    goto label_000B9EDA;
    label_000B9EC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9EC4u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000B9EC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9EC6u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000B9EAA;
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->eax;
    goto label_000B9EAC;
    label_000B9ECE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9ECEu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000B9ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9ED0u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000B9ED6;
    cpu->eax -= cpu->ecx;
    goto label_000B9EDA;
    label_000B9ED6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9ED6u);
    cpu->esi -= cpu->edi;
    label_000B9ED8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9ED8u);
    cpu->eax = cpu->esi;
    label_000B9EDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9EDAu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu))))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)0.30000001192092896f));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000B9F18;
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xACu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9F12u); lift_push32(cpu, r); sfera_sub_004B9B60(cpu,r); if (cpu->eip != r) return; }
    goto label_000B9F18;
    label_000B9F14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9F14u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    label_000B9F18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9F18u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000B9D80;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000B9F33: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9F33u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9F40u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x25Cu);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = (uint32_t)(cpu->esp + 0x15Cu);
    lift_push32(cpu, (uintptr_t)"Language\\*%s.hts"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4B9F8Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9F92u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x4B9FA2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9FA8u);
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA14E;
    cpu->ebp = native_strrchr_address32();
    label_000B9FC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9FC4u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x18u)) & (0x10u)) != 0u) goto label_000BA136;
    cpu->eax = lift_load32((uintptr_t)"Language\\");
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"Language\\") + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"Language\\") + 8u)) & 0xFFFFu);
    lift_store32(cpu->esp + 0x158u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x15Cu, cpu->ecx);
    lift_store16(cpu->esp + 0x160u, cpu->edx & 0xFFFFu);
    cpu->esi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000BA000: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA000u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000BA000;
    cpu->edi = (uint32_t)(cpu->esp + 0x158u);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000BA011: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA011u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA011;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edx = 0x182u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA036u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x68u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA03Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x264u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA05E;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA05Au); lift_push32(cpu, r); sfera_sub_004A78F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000BA060;
    label_000BA05E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA05Eu);
    cpu->esi = 0u;
    label_000BA060: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA060u);
    cpu->eax = (uint32_t)(cpu->esp + 0x158u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x268u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA07Eu); lift_push32(cpu, r); sfera_sub_004A8610(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA113;
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0])) == (uint8_t)(0u)) goto label_000BA0C9;
    cpu->ecx = (uint32_t)(cpu->esp + 0x158u);
    lift_push32(cpu, 0x5Fu); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xBA09Bu), LIFT_CODE_TOKEN_RVA(0xBA099u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA09Bu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA0C9;
    lift_store8(cpu->eax, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x158u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000BA0B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA0B0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000BA0B0;
    cpu->edx = lift_load32((uintptr_t)".hts");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)".hts") + 4u)) & 0xFFu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, cpu->ecx & 0xFFu);
    label_000BA0C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA0C9u);
    cpu->edx = (uint32_t)(cpu->esp + 0x158u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA0D8u); lift_push32(cpu, r); sfera_sub_004A5E90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.free_list_b;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA0F4u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(1u)) goto label_000BA17C;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.free_list_b_cursor, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->eax);
    goto label_000BA136;
    label_000BA113: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA113u);
    cpu->edx = 0x197u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA122u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_000BA136;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA12Du); lift_push32(cpu, r); sfera_sub_004A7A00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA133u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BA136: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA136u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x4BA140u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA146u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B9FC4;
    label_000BA14E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA14Eu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x4BA14Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA155u);
    cpu->ecx = lift_load32(cpu->esp + 0x25Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x258u;
    lift_return(cpu, 0u, stop_address); return;
    label_000BA17C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA17Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    lift_trap(cpu, 0x4BA187u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA190u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = 0x1E6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA1C9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA1D3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA1F1;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA1EDu); lift_push32(cpu, r); sfera_sub_00493BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    goto label_000BA1F3;
    label_000BA1F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA1F1u);
    cpu->edi = 0u;
    label_000BA1F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA1F3u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x24u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA203u); lift_push32(cpu, r); sfera_sub_00494940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA20Cu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA21Du); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA319;
    label_000BA225: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA225u);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA22Cu); lift_push32(cpu, r); sfera_sub_004D3AC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA241u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BA264;
    cpu->edx = 0x1F7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA254u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA25Fu);
    goto label_000BA300;
    label_000BA264: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA264u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x178u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BA275;
    cpu->eax = lift_load32(cpu->eax);
    label_000BA275: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA275u);
    cpu->ecx = (uint32_t)(uintptr_t)"";
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000BA280: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA280u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA2A0;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000BA29C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA2A0;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000BA280;
    label_000BA29C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA29Cu);
    cpu->eax = 0u;
    goto label_000BA2A5;
    label_000BA2A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA2A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000BA2A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA2A5u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BA2C7;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"WindowUI(%s,%d %d). Window name not specified.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA2BEu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA2C4u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000BA2C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA2C7u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.free_list_a;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA2E3u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor);
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000BA356;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.free_list_a_cursor, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    label_000BA300: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA300u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA311u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BA225;
    label_000BA319: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA319u);
    cpu->edx = 0x209u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA328u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_000BA33C;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA333u); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA339u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BA33C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA33Cu);
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
    label_000BA356: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA356u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    lift_trap(cpu, 0x4BA361u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA370u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x264u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x270u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(uintptr_t)"Effects\\*.ui";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA3B9u); lift_push32(cpu, r); sfera_sub_00425950(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Effects\\*.ui");
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x4BA3C7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA3CDu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_push(cpu, 1.0);
    cpu->esi = cpu->eax;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA647;
    label_000BA3F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA3F5u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x24u)) & (0x10u)) != 0u) goto label_000BA633;
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, (uintptr_t)"loadscreen.ui"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BA40Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA410u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA633;
    cpu->eax = 0x5C737463u;
    cpu->edx = 0x65666645u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->esp + 0x168u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x164u, cpu->edx);
    lift_store8(cpu->esp + 0x16Cu, cpu->ecx & 0xFFu);
    cpu->esi = cpu->eax;
    label_000BA447: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA447u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000BA447;
    cpu->edi = (uint32_t)(cpu->esp + 0x164u);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000BA458: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA458u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA458;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edx = 0x1E6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA47Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA487u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x278u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA4A8;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA4A4u); lift_push32(cpu, r); sfera_sub_00493BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    goto label_000BA4AA;
    label_000BA4A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA4A8u);
    cpu->edi = 0u;
    label_000BA4AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA4AAu);
    cpu->edx = (uint32_t)(cpu->esp + 0x164u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x27Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA4C4u); lift_push32(cpu, r); sfera_sub_00494940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA4CDu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA4DEu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA5E6;
    label_000BA4E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA4E6u);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA4EDu); lift_push32(cpu, r); sfera_sub_004D3AC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x16Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA509u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BA52C;
    cpu->edx = 0x1F7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA51Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA527u);
    goto label_000BA5CD;
    label_000BA52C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA52Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x178u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BA53D;
    cpu->eax = lift_load32(cpu->eax);
    label_000BA53D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA53Du);
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000BA542: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA542u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA562;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000BA55E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA562;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000BA542;
    label_000BA55E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA55Eu);
    cpu->eax = 0u;
    goto label_000BA567;
    label_000BA562: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA562u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000BA567: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA567u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BA590;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x16Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"WindowUI(%s,%d %d). Window name not specified.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA587u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA58Du); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000BA590: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA590u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.free_list_a;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA5ACu); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(1u)) goto label_000BA671;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.free_list_a_cursor, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->eax);
    label_000BA5CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA5CDu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA5DEu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BA4E6;
    label_000BA5E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA5E6u);
    cpu->edx = 0x209u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA5F5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_000BA609;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA600u); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA606u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BA609: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA609u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 30.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA628u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA62Fu); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    label_000BA633: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA633u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x4BA639u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA63Fu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BA3F5;
    label_000BA647: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA647u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x4BA648u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA64Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x270u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000BA671: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA671u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    lift_trap(cpu, 0x4BA67Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA680u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)), r=(uint64_t)(0x40u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BA691;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBA691u); lift_push32(cpu, r); sfera_sub_004B9B10(cpu,r); if (cpu->eip != r) return; }
    label_000BA691: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA691u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA69Cu); lift_push32(cpu, r); sfera_sub_004A01D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_01, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) + 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA6B0u);
    cpu->esp -= 0xCu;
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA6C6;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_000BA6C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA6C6u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA6D5u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BA6DD;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000BA6DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA6DDu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000BA6E9;
    cpu->eax -= cpu->edx;
    label_000BA6E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA6E9u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BA736;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    cpu->eax += cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(cpu->eax);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin)) > (uint32_t)(cpu->eax)) goto label_000BA724;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(0u);
    label_000BA724: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA724u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor)), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_cursor, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BA736;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(0u);
    label_000BA736: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA736u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_01, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    cpu->eax = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA750u);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BA7DD;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->esp, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000BA7DD;
    label_000BA768: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA768u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_000BA775;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000BA768;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000BA775: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA775u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000BA7DD;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA78Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esp += 4u;
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA7B4u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(1u)) goto label_000BA7CF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBA7CFu);
    label_000BA7CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA7CFu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    label_000BA7DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA7DDu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA7E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA7E0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->esp, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000BA865;
    label_000BA7F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA7F0u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_000BA7FD;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000BA7F0;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000BA7FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA7FDu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000BA865;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA817u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA83Bu); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(1u)) goto label_000BA856;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBA856u);
    label_000BA856: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA856u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    label_000BA865: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA865u);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA870u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA892u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(1u)) goto label_000BA8AD;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBA8ADu);
    label_000BA8AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA8ADu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA8C0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000BA8FE;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    (void)cpu;
    label_000BA8D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA8D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA8DCu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA8ECu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x38u;
    cpu->edi += 0x38u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000BA8D0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000BA8FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA8FEu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BA910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA910u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x40u, 0xFu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x2Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    cpu->edi = (uint32_t)(cpu->ebx + 0x10u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0])) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BA9C6;
    lift_push32(cpu, (uintptr_t)"_e"); lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BA96Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA974u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BA9C6;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000BA980: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA980u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BA980;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA994u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BA9A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA9A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BA9A0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA9B8u); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x40u)) >= (uint32_t)(cpu->edi)) goto label_000BA9C6;
    cpu->esi = (uint32_t)(cpu->esp + 0x2Cu);
    label_000BA9C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA9C6u);
    lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"Effects\\");
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x2Cu, 0xFu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store8(cpu->esp + 0x18u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BA9E6u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    lift_store8(cpu->esp + 0x54u, 1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000BA9F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA9F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BA9F0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAA04u); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)".sfn");
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAA14u); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) >= (uint32_t)(cpu->edi)) goto label_000BAA22;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    label_000BAA22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAA22u);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAA29u); lift_push32(cpu, r); sfera_sub_004A5540(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BAA41;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Can't load font '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAA38u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAA3Eu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000BAA41: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAA41u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) < (uint32_t)(cpu->edi)) goto label_000BAA54;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAA51u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BAA54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAA54u);
    lift_store32(cpu->esp + 0x24u, 0xFu);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store8(cpu->esp + 0x10u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x40u)) < (uint32_t)(cpu->edi)) goto label_000BAA77;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAA74u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BAA77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAA77u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BAAA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAAA0u);
    cpu->esp -= 0x114u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0x3Au); lift_push32(cpu, cpu->ebx);
    cpu->edi = cpu->edx;
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4BAABEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAAC4u);
    cpu->esp += 8u;
    cpu->ecx = cpu->ebx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BAAE7;
    cpu->esi = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->esi -= cpu->ebx;
    label_000BAAD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAAD3u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000BAAD3;
    cpu->eax -= cpu->ebx;
    lift_store8(cpu->esp + cpu->eax + 0x1Cu, cpu->edx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    label_000BAAE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAAE7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAAECu); lift_push32(cpu, r); sfera_sub_004B9850(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BACC5;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAAFEu);
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000BAB1C;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CreateWindow(%s) -> Can't create reference class");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAB13u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAB19u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000BAB1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAB1Cu);
    cpu->edx = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000BAB27;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000BAB27: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAB27u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BAB30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAB30u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000BAB30;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAB43u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x12Cu)) & (1u)) == 0u) goto label_000BAB65;
    cpu->eax = lift_load32(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAB60u);
    goto label_000BAC2C;
    label_000BAB65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAB65u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->ebx;
    lift_store8(cpu->esp + 0x17u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAB76u); lift_push32(cpu, r); sfera_sub_004B92D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BAB9D;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    cpu->ecx += 0xFFFFFFF1u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000BAB98;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->edx += 0xFFFFFFF1u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000BAB9D;
    label_000BAB98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAB98u);
    lift_store8(cpu->esp + 0x13u, 1u);
    label_000BAB9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAB9Du);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000BABF1;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BABB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BABB0u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000BABC0;
    cpu->eax = lift_load32(cpu->eax);
    label_000BABC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BABC0u);
    cpu->ecx = cpu->ebx;
    label_000BABC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BABC2u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BABE2;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000BABDE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BABE2;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000BABC2;
    label_000BABDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BABDEu);
    cpu->eax = 0u;
    goto label_000BABE7;
    label_000BABE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BABE2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000BABE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BABE7u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BAC14;
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000BABB0;
    label_000BABF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BABF1u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) == (uint8_t)(0u)) goto label_000BAC14;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x4Eu)) == (uint8_t)(0u)) goto label_000BAC14;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC12u);
    goto label_000BAC2C;
    label_000BAC14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC14u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x12Cu)) & (8u)) == 0u) goto label_000BAC25;
    lift_store32(cpu->ebp + 0x38u, 0x24u);
    label_000BAC25: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC25u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBAC2Cu); lift_push32(cpu, r); sfera_sub_004D1A10(cpu,r); if (cpu->eip != r) return; }
    label_000BAC2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC2Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x12Cu)) & 0xFFu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) != 0u) goto label_000BAC3B;
    lift_store8(cpu->ebp + 0x48u, 0u);
    label_000BAC3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC3Bu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x48u)) != (uint8_t)(0u)) goto label_000BAC4E;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) != 0u) goto label_000BAC4E;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBAC4Eu); lift_push32(cpu, r); sfera_sub_004D1D00(cpu,r); if (cpu->eip != r) return; }
    label_000BAC4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC4Eu);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->ebp + 0x4Au, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAC59u); lift_push32(cpu, r); sfera_sub_004B9D00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xACu);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000BAC7E;
    label_000BAC65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC65u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x79u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC74u);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->ebp + 0xACu))) goto label_000BAC65;
    label_000BAC7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC7Eu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAC9Au); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(1u)) goto label_000BACB5;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBACB5u);
    label_000BACB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BACB5u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    label_000BACC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BACC5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x114u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BACE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BACE0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BAD0B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_000BACF1;
    cpu->esi = (uint32_t)(uintptr_t)"";
    label_000BACF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BACF1u);
    cpu->eax = cpu->esi;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000BACF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BACF6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000BACF6;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx += 0x54u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAD09u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BAD0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAD0Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BAD10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAD10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000BAD59;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BAE50;
    cpu->esi = cpu->eax;
    if ((uint32_t)(lift_load32(cpu->eax + 0xD8u)) == (uint32_t)(cpu->ecx)) goto label_000BAD43;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAD3Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAD40u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000BAD43: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAD43u);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAD4Cu); lift_push32(cpu, r); sfera_sub_004D1E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05) = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000BAD59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAD59u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAD5Eu); lift_push32(cpu, r); sfera_sub_004B9350(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BAE50;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BAD8E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"help";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAD7Du); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05) = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0xF8u, LIFT_CALLBACK(sfera_sub_004B9540));
    goto label_000BADB1;
    label_000BAD8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAD8Eu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) == (uint32_t)(0u)) goto label_000BADA5;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->edx + 8u)) == (uint32_t)(cpu->eax)) goto label_000BADB1;
    label_000BADA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BADA5u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BADACu); lift_push32(cpu, r); sfera_sub_004BA750(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    label_000BADB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BADB1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BAE50;
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BADCFu); lift_push32(cpu, r); sfera_sub_004AEE90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BADE2;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BADD5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BADDBu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BAE50;
    label_000BADE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BADE2u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BADE9u); lift_push32(cpu, r); sfera_sub_004AF340(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000BAE21;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    cpu->eax = lift_load32(cpu->edx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAE0Du);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xA8Fu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAE1Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000BAE21: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAE21u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    cpu->edx = lift_load32(cpu->ecx + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAE3Fu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xA8Fu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BAE50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAE50u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BAE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAE60u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    cpu->esi = lift_load32(cpu->esp + 0x60u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (2u)) != 0u) goto label_000BAF02;
    cpu->eax = lift_load32(cpu->ecx + 0x24u);
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->ebx)) goto label_000BAF02;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x3Cu);
    if ((uint32_t)(cpu->edx) < (uint32_t)(cpu->eax)) goto label_000BAEB5;
    cpu->eax = cpu->edx;
    label_000BAEB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAEB5u);
    cpu->ecx = lift_load32(cpu->ecx + 0x14u);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edi = 0xFu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAED8u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x58u, cpu->ebx);
    label_000BAEDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAEDCu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAEF0u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(0x10u)) goto label_000BAF83;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    goto label_000BAF7B;
    label_000BAF02: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAF02u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (4u)) != 0u) goto label_000BAF42;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(lift_load32(cpu->edx)) == (uint32_t)(cpu->ebx)) goto label_000BAF42;
    cpu->eax = lift_load32(cpu->ecx + 0x30u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax += lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edi = 0xFu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAF38u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x58u, 1u);
    goto label_000BAEDC;
    label_000BAF42: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAF42u);
    cpu->edi = 0xFu;
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store8(cpu->esp + 0x30u, cpu->ebx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x5Cu, 2u);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAF6Fu); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x44u)) < (uint32_t)(0x10u)) goto label_000BAF83;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    label_000BAF7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAF7Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BAF80u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BAF83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAF83u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BAFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAFB0u);
    cpu->esp -= 0x60u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x7Bu)) goto label_000BAFE3;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x1D]) == (uint8_t)(0u)) goto label_000BAFF4;
    { uint64_t l=(uint64_t)(g_sfera_interface_runtime.primary_gate), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_interface_runtime.primary_gate = (uint8_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u);
    goto label_000BAFF4;
    label_000BAFE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAFE3u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x70u)) goto label_000BAFF4;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Language\\helpindex.hts";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBAFF4u); lift_push32(cpu, r); sfera_sub_004BAD10(cpu,r); if (cpu->eip != r) return; }
    label_000BAFF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAFF4u);
    if ((uint8_t)(g_sfera_interface_runtime.primary_gate) == (uint8_t)(0u)) goto label_000BB737;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)(g_sfera_client_process_runtime.ui_bridge) == (uint32_t)(cpu->esi)) goto label_000BB039;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_000BB039;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_07;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000BB039;
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x50u, 0xFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xBB033u), LIFT_CODE_TOKEN_RVA(0xBB031u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB033u);
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state) = (uint32_t)(cpu->esi);
    label_000BB039: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB039u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB03Eu); lift_push32(cpu, r); sfera_sub_004A1DB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BB04E;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB047u); lift_push32(cpu, r); sfera_sub_004A21F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB04Eu); lift_push32(cpu, r); sfera_sub_004A1FA0(cpu,r); if (cpu->eip != r) return; }
    label_000BB04E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB04Eu);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB054u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB062u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x14u)) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store8(cpu->esp + 0x45u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint8_t)g_sfera_interface_runtime.previous_input_modifiers)) & 0xFFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebp);
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    cpu->ebx = 4u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BB0B3;
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (1u)) != 0u) goto label_000BB0B3;
    lift_store32(cpu->esp + 0x3Cu, 1u);
    goto label_000BB0C0;
    label_000BB0B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB0B3u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000BB0C0;
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000BB0C0;
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    label_000BB0C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB0C0u);
    cpu->esi = 2u;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 6u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BB0DA;
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (2u)) != 0u) goto label_000BB0DA;
    lift_store32(cpu->esp + 0x40u, (uint64_t)(lift_load32(cpu->esp + 0x40u)) | (uint64_t)(cpu->esi));
    goto label_000BB0E7;
    label_000BB0DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB0DAu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BB0E7;
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_000BB0E7;
    lift_store32(cpu->esp + 0x40u, (uint64_t)(lift_load32(cpu->esp + 0x40u)) | (uint64_t)(cpu->edi));
    label_000BB0E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB0E7u);
    { uint64_t l=(uint64_t)(g_sfera_direct_input_runtime.keyboard_state[0x2A]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_interface_runtime.previous_input_modifiers = (uint32_t)(cpu->ecx);
    lift_store32(cpu->esp + 0x4Cu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BB106;
    lift_store32(cpu->esp + 0x4Cu, 1u);
    label_000BB106: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB106u);
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x36]) == (uint8_t)(0u)) goto label_000BB113;
    lift_store32(cpu->esp + 0x4Cu, (uint64_t)(lift_load32(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->esi));
    label_000BB113: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB113u);
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x1D]) == (uint8_t)(0u)) goto label_000BB120;
    lift_store32(cpu->esp + 0x4Cu, (uint64_t)(lift_load32(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->ebx));
    label_000BB120: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB120u);
    if ((uint8_t)(lift_load8((uint32_t)(uintptr_t)&g_sfera_direct_input_runtime.modifier_08)) == (uint8_t)(0u)) goto label_000BB12D;
    lift_store32(cpu->esp + 0x4Cu, (uint64_t)(lift_load32(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->edi));
    label_000BB12D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB12Du);
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x38]) == (uint8_t)(0u)) goto label_000BB13B;
    lift_store32(cpu->esp + 0x4Cu, (uint64_t)(lift_load32(cpu->esp + 0x4Cu)) | (uint64_t)(0x10u));
    label_000BB13B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB13Bu);
    if ((uint8_t)(lift_load8((uint32_t)(uintptr_t)&g_sfera_direct_input_runtime.modifier_20)) == (uint8_t)(0u)) goto label_000BB149;
    lift_store32(cpu->esp + 0x4Cu, (uint64_t)(lift_load32(cpu->esp + 0x4Cu)) | (uint64_t)(0x20u));
    label_000BB149: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB149u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ebx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edx)) goto label_000BB245;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BB160: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB160u);
    cpu->edi = lift_load32(cpu->ebx + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0xE1u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = lift_load32(cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BB237;
    cpu->eax = lift_load32(cpu->edi + 0xACu);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000BB1C3;
    cpu->edi = cpu->edi;
    label_000BB180: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB180u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000BB1B9;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BB190: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB190u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_000BB19D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000BB190;
    goto label_000BB1B9;
    label_000BB19D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB19Du);
    if ((uint8_t)(lift_load8(cpu->ecx + 0xE0u)) != (uint8_t)(0u)) goto label_000BB1B9;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x78u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB1B3u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB1B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB1B9u);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->edi + 0xACu))) goto label_000BB180;
    label_000BB1C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB1C3u);
    cpu->edi = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xD8u)) == (uint32_t)(0u)) goto label_000BB1E9;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(0x%X) -> Can't destroy controls.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB1DAu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB1E0u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 0xCu;
    label_000BB1E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB1E9u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->ebx = cpu->edx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edx)) goto label_000BB217;
    label_000BB1F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB1F1u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) != (uint32_t)(cpu->edi)) goto label_000BB211;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->esi + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB206u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u);
    goto label_000BB213;
    label_000BB211: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB211u);
    cpu->esi = lift_load32(cpu->esi);
    label_000BB213: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB213u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000BB1F1;
    label_000BB217: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB217u);
    cpu->edx = 0x283u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB226u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB231u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB237: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB237u);
    cpu->ebx = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->edx)) goto label_000BB160;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    label_000BB245: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB245u);
    cpu->ebx = lift_load32(cpu->edx);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebx)) goto label_000BB2C5;
    label_000BB255: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB255u);
    cpu->edi = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000BB2B9;
    if ((uint8_t)(lift_load8(cpu->esi + 0x10Cu)) != (uint8_t)(0u)) goto label_000BB2C1;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000BB28D;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB28Du); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BB28D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB28Du);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000BB2B9;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000BB2B9;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->eax)) goto label_000BB2B9;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000BB2C1;
    label_000BB2B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB2B9u);
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000BB255;
    goto label_000BB2C5;
    label_000BB2C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB2C1u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_000BB2C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB2C5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB2CAu); lift_push32(cpu, r); sfera_sub_004A1DB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BB30B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB2D3u); lift_push32(cpu, r); sfera_sub_004A21F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->eax + 0x48u)) != (uint8_t)(0u)) goto label_000BB30B;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = lift_load32(cpu->edx);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000BB311;
    label_000BB2F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB2F0u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x10Cu)) != (uint8_t)(0u)) goto label_000BB305;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000BB2F0;
    goto label_000BB311;
    label_000BB305: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB305u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    goto label_000BB311;
    label_000BB30B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB30Bu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB311: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB311u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x40u)) & (1u)) == 0u) goto label_000BB3BC;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BB3BC;
    if ((uint8_t)(lift_load8(cpu->ecx + 0x4Du)) == (uint8_t)(0u)) goto label_000BB3BC;
    if ((uint8_t)(lift_load8(cpu->ecx + 0x4Fu)) != (uint8_t)(0u)) goto label_000BB3BC;
    if ((uint8_t)(lift_load8(cpu->ecx + 0x48u)) != (uint8_t)(0u)) goto label_000BB3BC;
    cpu->eax = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000BB37D;
    label_000BB348: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB348u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_000BB355;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000BB348;
    goto label_000BB37D;
    label_000BB355: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB355u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000BB37D;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB36Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 4u;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u);
    label_000BB37D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB37Du);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->esi = (uint32_t)(cpu->edx + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB394u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000BB3AF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBB3AFu);
    label_000BB3AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB3AFu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    label_000BB3BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB3BCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB3C1u); lift_push32(cpu, r); sfera_sub_004A1DB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BB3EE;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB3CAu); lift_push32(cpu, r); sfera_sub_004A21F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->eax + 0x48u)) != (uint8_t)(0u)) goto label_000BB3EE;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) == (uint32_t)(0u)) goto label_000BB3E7;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 8u)) == (uint32_t)(cpu->eax)) goto label_000BB3EE;
    label_000BB3E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB3E7u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB3EEu); lift_push32(cpu, r); sfera_sub_004BA750(cpu,r); if (cpu->eip != r) return; }
    label_000BB3EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB3EEu);
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store8(cpu->esp + 0x13u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BB5EE;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000BB481;
    cpu->ebx = 0x6Eu;
    cpu->ebp = 0u;
    label_000BB412: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB412u);
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Cu)) == (uint8_t)(0u)) goto label_000BB477;
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000BB44B;
    if ((uint8_t)((lift_load8(cpu->esi + 0x94u)) & (2u)) != 0u) goto label_000BB477;
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x58u, cpu->ebp);
    lift_store32(cpu->esp + 0x54u, cpu->esi);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB442u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x94u, (uint64_t)(lift_load32(cpu->esi + 0x94u)) | (uint64_t)(2u));
    goto label_000BB477;
    label_000BB44B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB44Bu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x94u)) & (2u)) == 0u) goto label_000BB477;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x58u, cpu->ebp);
    lift_store32(cpu->esp + 0x54u, cpu->esi);
    lift_store32(cpu->esp + 0x5Cu, 0x6Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB470u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x94u, (uint64_t)(lift_load32(cpu->esi + 0x94u)) & (uint64_t)(0xFFFFFFFDu));
    label_000BB477: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB477u);
    cpu->edi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head))) goto label_000BB412;
    label_000BB481: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB481u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x40u)) & (4u)) == 0u) goto label_000BB5EE;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_000BB4B5;
    if ((uint8_t)(lift_load8(cpu->ecx + 0x4Cu)) == (uint8_t)(0u)) goto label_000BB4B5;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->hitTest(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB4ADu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BB599;
    label_000BB4B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB4B5u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)), r=(uint64_t)(0x40u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    lift_store32(cpu->esp + 0x60u, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    lift_store32(cpu->esp + 0x54u, cpu->esi);
    lift_store32(cpu->esp + 0x50u, cpu->esi);
    lift_store32(cpu->esp + 0x58u, 0xDu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BB514;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_000BB50E;
    label_000BB4F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB4F3u);
    ++cpu->eax;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000BB4FA;
    cpu->eax = 0u;
    label_000BB4FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB4FAu);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BB4FF;
    cpu->eax = 0u;
    label_000BB4FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB4FFu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_000BB4F3;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = (uint32_t)(cpu->ecx);
    label_000BB50E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB50Eu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) = (uint32_t)(cpu->esi);
    label_000BB514: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB514u);
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->esi)) goto label_000BB538;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB527u); lift_push32(cpu, r); sfera_sub_0049FBD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    label_000BB538: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB538u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->esi)) goto label_000BB541;
    cpu->esi -= cpu->edx;
    label_000BB541: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB541u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_000BB56E;
    lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB554u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BB623;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    label_000BB56E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB56Eu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->edi) == 0u) goto label_000BB58C;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(cpu->esp + 0x50u);
    lift_movs32(cpu, 1u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    label_000BB58C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB58Cu);
    ++cpu->ecx;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_01, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) + 1u);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = (uint32_t)(cpu->ecx);
    label_000BB599: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB599u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000BB5E9;
    cpu->ebp = 0xFFFFFFFDu;
    cpu->ebx = (uint32_t)(cpu->ebp + 0x72u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BB5B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB5B0u);
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x94u)) & (2u)) == 0u) goto label_000BB5E3;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x58u, 0u);
    lift_store32(cpu->esp + 0x54u, cpu->esi);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB5D8u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x94u, (uint64_t)(lift_load32(cpu->esi + 0x94u)) & (uint64_t)(cpu->ebp));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB5E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB5E3u);
    cpu->edi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000BB5B0;
    label_000BB5E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB5E9u);
    lift_store8(cpu->esp + 0x13u, 1u);
    label_000BB5EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB5EEu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x48u)) != (uint8_t)(0x1Bu)) goto label_000BB677;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BB677;
    label_000BB604: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB604u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000BB61B;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) == (uint8_t)(0u)) goto label_000BB651;
    label_000BB61B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB61Bu);
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BB604;
    goto label_000BB677;
    label_000BB623: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB623u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB651u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000BB651: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB651u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x50u, cpu->ecx);
    lift_store32(cpu->esp + 0x54u, 0u);
    lift_store32(cpu->esp + 0x58u, 0x64u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB677u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000BB677: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB677u);
    cpu->ebx = lift_load32(cpu->esp + 0x34u);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = 0u;
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->edi))) goto label_000BB70E;
    label_000BB6A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB6A0u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000BB6B4;
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x38u, cpu->ebp);
    label_000BB6B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB6B4u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)(0u)) goto label_000BB6D2;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000BB6D2;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BB6D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB6D2u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000BB6E2;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    label_000BB6E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB6E2u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xE0u)) == (uint8_t)(0u)) goto label_000BB6F2;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB6F2u); lift_push32(cpu, r); sfera_sub_004D1C50(cpu,r); if (cpu->eip != r) return; }
    label_000BB6F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB6F2u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xF8u)) == (uint32_t)(0u)) goto label_000BB702;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB702u); lift_push32(cpu, r); sfera_sub_004D3360(cpu,r); if (cpu->eip != r) return; }
    label_000BB702: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB702u);
    cpu->edi = lift_load32(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000BB6A0;
    label_000BB70E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB70Eu);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready)) != (uint8_t)(0u)) goto label_000BB726;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBB726u); lift_push32(cpu, r); sfera_sub_004CF7C0(cpu,r); if (cpu->eip != r) return; }
    label_000BB726: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB726u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) == (uint8_t)(0u)) goto label_000BB734;
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = (uint8_t)(0u);
    label_000BB734: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB734u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BB737: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB737u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x60u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BB750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB750u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x64u)) goto label_000BB786;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xAu)) goto label_000BB7E6;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xEu)) goto label_000BB7D1;
    lift_push32(cpu, 0x6A5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB77Du); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB783u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BB786: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB786u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000BB7A7;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB79Eu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB7A4u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BB7A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB7A7u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB7ADu); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB7B4u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BB7F5;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB7CCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000BB7D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB7D1u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB7DCu); lift_push32(cpu, r); sfera_sub_004BAD10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000BB7E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB7E6u);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu);
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = (uint8_t)((cpu->eax & 0xFFu));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000BB7F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB7F5u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BB800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB800u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000BB852;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBE71;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xD8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BB837;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB82Eu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB834u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000BB837: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB837u);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB840u); lift_push32(cpu, r); sfera_sub_004D1E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06) = (uint32_t)(0u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
    label_000BB852: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB852u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    cpu->esi = 0u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_000BB87F;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"loadscreen";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB86Du); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB879u); lift_push32(cpu, r); sfera_sub_004BA7E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    label_000BB87F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB87Fu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB88Cu);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB89Du);
    cpu->ebx = 0x400u;
    cpu->edi = 0x300u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000BB8CC;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFC00u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    goto label_000BB8D2;
    label_000BB8CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB8CCu);
    cpu->ebx = cpu->ebp;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    label_000BB8D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB8D2u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x300u)) goto label_000BB8ED;
    cpu->eax += 0xFFFFFD00u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_000BB8F3;
    label_000BB8ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB8EDu);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000BB8F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB8F3u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000BB90D;
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BB92A;
    label_000BB90D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB90Du);
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB921u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB927u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BB92A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB92Au);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB930u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB937u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BB950;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BB950: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB950u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBAB5;
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BB98B;
    label_000BB96E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB96Eu);
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB982u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB988u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BB98B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB98Bu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB991u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB998u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BB9A9;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BB9A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB9A9u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBABC;
    cpu->ecx = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BB9E2;
    label_000BB9C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB9C5u);
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB9D9u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB9DFu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BB9E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB9E2u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB9E8u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BB9EFu); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBA02;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBA02: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBA02u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBAC3;
    cpu->ecx = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBA3B;
    label_000BBA1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBA1Eu);
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBA32u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBA38u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBA3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBA3Bu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBA41u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBA48u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBA5D;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBA5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBA5Du);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x34u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BBACE;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBACA;
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBA9B;
    label_000BBA7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBA7Eu);
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBA92u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBA98u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBA9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBA9Bu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBAA1u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBAA8u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBB26;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"english_sphere1");
    goto label_000BBB18;
    label_000BBAB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBAB5u);
    cpu->esi = 0u;
    goto label_000BB96E;
    label_000BBABC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBABCu);
    cpu->esi = 0u;
    goto label_000BB9C5;
    label_000BBAC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBAC3u);
    cpu->esi = 0u;
    goto label_000BBA1E;
    label_000BBACA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBACAu);
    cpu->esi = 0u;
    goto label_000BBA7E;
    label_000BBACE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBACEu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBB40;
    cpu->ecx = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBB00;
    label_000BBAE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBAE3u);
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBAF7u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBAFDu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBB00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBB00u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBB06u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBB0Du); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBB26;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"russian_sphere1");
    label_000BBB18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBB18u);
    lift_push32(cpu, 0xA29u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBB26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBB26u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBB44;
    cpu->ecx = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    goto label_000BBB46;
    label_000BBB40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBB40u);
    cpu->esi = 0u;
    goto label_000BBAE3;
    label_000BBB44: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBB44u);
    cpu->esi = 0u;
    label_000BBB46: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBB46u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store16(cpu->esp + 0x34u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x34u);
    lift_store_f64(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.3701171875));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi += lift_load32(cpu->esp + 0x18u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x34u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBB9B;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBB92u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBB98u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBB9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBB9Bu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBBA1u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBBA8u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBBEB;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store16(cpu->esp + 0x34u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.83203125));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x38u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBBEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBBEBu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.2490234375));
    lift_store16(cpu->esp + 0x34u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x34u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x24u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x34u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBC38;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBC2Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBC35u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBC38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBC38u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBC3Eu); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBC45u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBC82;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store16(cpu->esp + 0x34u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.0247395833));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x24u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x3Cu));
    lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBC82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBC82u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBCA3;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBC9Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBCA0u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBCA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBCA3u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBCA9u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBCB0u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBCC6;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x64u); lift_push32(cpu, 0x7D1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBCC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBCC6u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBCE2;
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    goto label_000BBCE4;
    label_000BBCE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBCE2u);
    cpu->esi = 0u;
    label_000BBCE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBCE4u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBD05;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBCFCu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBD02u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBD05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBD05u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBD0Bu); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBD12u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBD51;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store16(cpu->esp + 0x34u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.83203125));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x24u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x38u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBD51: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBD51u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBD72;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBD69u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBD6Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBD72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBD72u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBD78u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBD7Fu); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBDBC;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store16(cpu->esp + 0x34u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.0247395833));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x24u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x3Cu));
    lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBDBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBDBCu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBDDA;
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    goto label_000BBDDC;
    label_000BBDDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBDDAu);
    cpu->esi = 0u;
    label_000BBDDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBDDCu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->edi += 0x177u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBE07;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBDFEu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBE04u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBE07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBE07u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBE0Du); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBE14u); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBE2B;
    cpu->ebp += 0x208u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBE2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBE2Bu);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBE4E;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBE45u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBE4Bu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBE4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBE4Eu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBE54u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBE5Bu); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBE71;
    lift_push32(cpu, 0x5Au); lift_push32(cpu, 0x26Cu); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBE71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBE71u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BBE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBE80u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_06;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BBEF3;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000BBE94;
    cpu->edi = 0u;
    goto label_000BBE9E;
    label_000BBE94: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBE94u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(0x64u)) goto label_000BBE9E;
    cpu->edi = 0x64u;
    label_000BBE9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBE9Eu);
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000BBECF;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBEC6u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBECCu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BBECF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBECFu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBED5u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBEDCu); lift_push32(cpu, r); sfera_sub_004D2DA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000BBEF1;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x7D1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000BBEF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBEF1u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000BBEF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBEF3u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BBF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBF00u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBF32u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000BBFB0;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->esi = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->edi, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->edx);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_store32(cpu->ebp + 0xCu, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000BBF85;
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBF79u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->ecx);
    label_000BBF85: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBF85u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000BBFB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBFB0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBFD5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4BBFD5u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BBF9B(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BBF9Bu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBFA4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBFB0u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BBFD5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4BBFD5u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC000u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BC058;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x30u);
    cpu->ebx = 0u;
    cpu->edi = cpu->edi;
    label_000BC010: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC010u);
    if ((uint32_t)(lift_load32(cpu->esi)) < (uint32_t)(0x10u)) goto label_000BC021;
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC01Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC021: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC021u);
    lift_store32(cpu->esi, 0xFu);
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->ebx);
    lift_store8(cpu->esi + 0xFFFFFFECu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xFFFFFFE4u)) < (uint32_t)(0x10u)) goto label_000BC03F;
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC03Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC03F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC03Fu);
    lift_store32(cpu->esi + 0xFFFFFFE4u, 0xFu);
    lift_store32(cpu->esi + 0xFFFFFFE0u, cpu->ebx);
    lift_store8(cpu->esi + 0xFFFFFFD0u, cpu->ebx & 0xFFu);
    cpu->esi += 0x38u;
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFD0u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->edi)) goto label_000BC010;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000BC058: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC058u);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC060u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edx);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    label_000BC0A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC0A0u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFECu))) goto label_000BC11A;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000BC0E6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC0C7u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->edi + 0x1Cu);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBC0E6u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000BC0E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC0E6u);
    cpu->esi += 0x38u;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    cpu->edi += 0x38u;
    goto label_000BC0A0;
    label_000BC11A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC11Au);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC0F4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC0F4u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000BC111;
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    label_000BC101: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC101u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC10Au); lift_push32(cpu, r); sfera_sub_0040ACE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x38u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000BC101;
    label_000BC111: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC111u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC11Au); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC130u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->ebx = 0u;
    lift_store32(cpu->edi + 4u, cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_000BC181;
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000BC150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC150u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BC164;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC161u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC164: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC164u);
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC177u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->edi))) goto label_000BC150;
    cpu->ebp = lift_pop32(cpu);
    label_000BC181: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC181u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC190u);
    sfera_u32_to_sso_decimal(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC290u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x160u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x174u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(uintptr_t)"fonts.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC2D6u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BC3F8;
    cpu->ebx = 0u;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(uintptr_t)"NEW_FONTS_NUMBER";
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC2F2u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) <= (uint32_t)(cpu->ebx)) goto label_000BC411;
    cpu->edi = (uint32_t)(cpu->ebx + 0xFu);
    cpu->ebp = (uint32_t)(cpu->ebx + 0x10u);
    label_000BC310: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC310u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    sfera_u32_to_sso_decimal(cpu);
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBC31Du);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC31Du);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 9u); lift_push32(cpu, (uintptr_t)"NEW_FONT_");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x184u, cpu->ebx);
    lift_store32(cpu->esp + 0x38u, cpu->edi);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC342u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_store8(cpu->esp + 0x180u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC358u); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x17Cu, 2u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000BC367;
    cpu->eax = lift_load32(cpu->eax);
    label_000BC367: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC367u);
    cpu->edx = (uint32_t)(cpu->esp + 0x70u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC372u); lift_push32(cpu, r); sfera_sub_00448880(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x68u)) < (uint32_t)(cpu->ebp)) goto label_000BC385;
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC382u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC385: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC385u);
    lift_store32(cpu->esp + 0x68u, cpu->edi);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store8(cpu->esp + 0x54u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) < (uint32_t)(cpu->ebp)) goto label_000BC3A4;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC3A1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC3A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC3A4u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x17Cu, 0xFFFFFFFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x4Cu)) < (uint32_t)(cpu->ebp)) goto label_000BC3CE;
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC3CBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC3CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC3CEu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    lift_store8(cpu->esp + 0x38u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC3E3u); lift_push32(cpu, r); sfera_sub_004BA910(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000BC310;
    goto label_000BC411;
    label_000BC3F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC3F8u);
    cpu->eax = (uint32_t)(uintptr_t)"fonts.cfg";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"File '%s' doesn't exists.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC408u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC40Eu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000BC411: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC411u);
    cpu->ecx = lift_load32(cpu->esp + 0x174u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x16Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC480u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    if ((uint32_t)(cpu->edi) != 0u) goto label_000BC4BB;
    cpu->eax = 0u;
    goto label_000BC5D1;
    label_000BC4BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC4BBu);
    cpu->ebp = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->esi = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebp)) goto label_000BC519;
    label_000BC4D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC4D0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BC4DB;
    cpu->eax = lift_load32(cpu->eax);
    label_000BC4DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC4DBu);
    cpu->ecx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000BC4E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC4E0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BC500;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000BC4FC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BC500;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000BC4E0;
    label_000BC4FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC4FCu);
    cpu->eax = 0u;
    goto label_000BC505;
    label_000BC500: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC500u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000BC505: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC505u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BC511;
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebp)) goto label_000BC4D0;
    goto label_000BC519;
    label_000BC511: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC511u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebp)) goto label_000BC5BE;
    label_000BC519: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC519u);
    lift_store32(cpu->esp + 0x20u, 0xFu);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_store8(cpu->esp + 0xCu, 0u);
    cpu->eax = cpu->edi;
    lift_store32(cpu->esp + 0x3Cu, 0u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000BC540: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC540u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000BC540;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC554u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_10;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC580u); lift_push32(cpu, r); sfera_sub_004BBF00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x71C71C6u;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000BC59B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBC59Bu);
    label_000BC59B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC59Bu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_11, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11)) + 1u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) < (uint32_t)(0x10u)) goto label_000BC5CC;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC5B9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000BC5CC;
    label_000BC5BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC5BEu);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    lift_store32(cpu->esi + 0x28u, cpu->ecx);
    label_000BC5CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC5CCu);
    cpu->eax = 1u;
    label_000BC5D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC5D1u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC5F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC5F0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000BC619;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBC619u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BC619: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC619u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 4u);
    cpu->ecx += lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BC633;
    cpu->edx = lift_load32(cpu->edx);
    label_000BC633: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC633u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC63Du); lift_push32(cpu, r); sfera_sub_004BC480(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC650u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BC69D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_10;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBC69Du); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    label_000BC69D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC69Du);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000BC807;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000BC807;
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(0x31564955u)) goto label_000BC807;
    cpu->ebp = 0u;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000BC807;
    label_000BC6C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC6C6u);
    cpu->eax = 0u;
    cpu->ecx = 0xFu;
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store8(cpu->esp + 0x18u, cpu->eax & 0xFFu);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edi)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000BC77B;
    goto label_000BC6EB;
    label_000BC6E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC6E7u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    label_000BC6EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC6EBu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(1u)) goto label_000BC826;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFFFFEu)) goto label_000BC826;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000BC718;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC716u); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    goto label_000BC730;
    label_000BC718: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC718u);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BC736;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0x10u)) goto label_000BC72D;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    label_000BC72D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC72Du);
    lift_store8(cpu->eax, 0u);
    label_000BC730: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC730u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    label_000BC736: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC736u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000BC76D;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) >= (uint32_t)(cpu->edx)) goto label_000BC750;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    label_000BC750: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC750u);
    lift_store8(cpu->ecx + cpu->eax, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) >= (uint32_t)(cpu->edx)) goto label_000BC765;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    label_000BC765: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC765u);
    lift_store8(cpu->eax + cpu->esi, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    label_000BC76D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC76Du);
    ++cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0u)) goto label_000BC6E7;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_000BC77B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC77Bu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 1u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC789u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 5u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC79Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = (uint32_t)(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_10;
    cpu->edi += 9u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC7BEu); lift_push32(cpu, r); sfera_sub_004BBF00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x71C71C6u;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(1u)) goto label_000BC831;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_11, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11)) + 1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->ebp = (uint32_t)(cpu->edx + cpu->ebp + 9u);
    lift_store32(cpu->esp + 0x48u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BC7FF;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC7FCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC7FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC7FFu);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->ebx)) goto label_000BC6C6;
    label_000BC807: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC807u);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
    label_000BC826: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC826u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBC831u);
    label_000BC831: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC831u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    lift_trap(cpu, 0x4BC83Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC840u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0x4924924u)) goto label_000BC883;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBC883u);
    label_000BC883: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC883u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx -= lift_load32(cpu->esi);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_000BC92A;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC8AEu); lift_push32(cpu, r); sfera_sub_004B8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC8CAu); lift_push32(cpu, r); sfera_sub_004BC060(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ecx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BC904;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC8F9u); lift_push32(cpu, r); sfera_sub_004BC000(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC901u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BC904: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC904u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 8u));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->ecx -= cpu->edi;
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 8u));
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->esi, cpu->eax);
    label_000BC92A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC92Au);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC93E(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC93Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC947u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BC953u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4BC953u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC960u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    cpu->esi -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    cpu->edx = 0x4924924u;
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->esi)) goto label_000BC996;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBC996u);
    label_000BC996: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC996u);
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000BC9DC;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0x4924924u;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000BC9C8;
    cpu->eax = 0u;
    goto label_000BC9CA;
    label_000BC9C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC9C8u);
    cpu->eax += cpu->edx;
    label_000BC9CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC9CAu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_000BC9D0;
    cpu->eax = cpu->esi;
    label_000BC9D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC9D0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    sfera_sub_004BC840(cpu, stop_address); return;
    label_000BC9DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC9DCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BC9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC9F0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BCA24;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x1DCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1D4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCA15u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCA21u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCA24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCA24u);
    lift_store32(cpu->esi + 0x1D0u, 0u);
    lift_store32(cpu->esi + 0x1D4u, 0u);
    lift_store32(cpu->esi + 0x1D8u, 0u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BCA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCA50u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->ecx)) goto label_000BCAAC;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edi)) goto label_000BCAAC;
    cpu->edi -= cpu->eax;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000BCA88;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBCA88u); lift_push32(cpu, r); sfera_sub_004BC960(cpu,r); if (cpu->eip != r) return; }
    label_000BCA88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCA88u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->eax -= cpu->edi;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCAA3u); lift_push32(cpu, r); sfera_sub_004B9BB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(0x38u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000BCAAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCAACu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000BCABA;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBCABAu); lift_push32(cpu, r); sfera_sub_004BC960(cpu,r); if (cpu->eip != r) return; }
    label_000BCABA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCABAu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCAC4u); lift_push32(cpu, r); sfera_sub_004B9C50(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(0x38u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BCAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCAD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x80u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x94u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    cpu->edi = 0xFu;
    lift_store32(cpu->esp + 0x6Cu, cpu->edi);
    lift_store32(cpu->esp + 0x68u, cpu->ebx);
    lift_store8(cpu->esp + 0x58u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x88u, cpu->edi);
    lift_store32(cpu->esp + 0x84u, cpu->ebx);
    lift_store8(cpu->esp + 0x74u, cpu->ebx & 0xFFu);
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"null");
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    lift_store32(cpu->esp + 0xA4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCB44u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"NULL");
    cpu->ecx = (uint32_t)(cpu->esp + 0x7Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCB54u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.object_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCB60u); lift_push32(cpu, r); sfera_sub_004BC840(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.object_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCB6Fu); lift_push32(cpu, r); sfera_sub_004BCA50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x1BCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCB7Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCB88u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store8(cpu->esp + 0x9Cu, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000BCBA6;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCBA2u); lift_push32(cpu, r); sfera_sub_00493BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000BCBA8;
    label_000BCBA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCBA6u);
    cpu->esi = 0u;
    label_000BCBA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCBA8u);
    cpu->ecx = (uint32_t)(uintptr_t)"Language\\strings.ui";
    lift_store8(cpu->esp + 0x9Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCBB9u); lift_push32(cpu, r); sfera_sub_004B8150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCBC1u); lift_push32(cpu, r); sfera_sub_00494940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"stringsUI");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCBD5u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0x10u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BCCF0;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCBEEu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"string");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCBFAu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BCCE9;
    label_000BCC02: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCC02u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0]); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCC0Fu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BCCD5;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0]); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCC25u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BCCD5;
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x50u, cpu->edi);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0];
    lift_store8(cpu->esp + 0x9Cu, 2u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000BCC55: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCC55u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BCC55;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0]);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCC6Du); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000BCC75: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCC75u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BCC75;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0]);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCC8Du); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.object_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCC9Cu); lift_push32(cpu, r); sfera_sub_004BCA50(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x9Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->ebp)) goto label_000BCCB6;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCCB3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCCB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCCB6u);
    lift_store32(cpu->esp + 0x50u, cpu->edi);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->ebp)) goto label_000BCCD5;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCCD2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCCD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCCD5u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"string");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCCE1u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BCC02;
    label_000BCCE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCCE9u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBCCF0u); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    label_000BCCF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCCF0u);
    cpu->edx = 0x1DBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCCFFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000BCD13;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCD0Au); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCD10u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCD13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCD13u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x88u)) < (uint32_t)(cpu->ebp)) goto label_000BCD29;
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCD26u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCD29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCD29u);
    lift_store32(cpu->esp + 0x88u, cpu->edi);
    lift_store32(cpu->esp + 0x84u, cpu->ebx);
    lift_store8(cpu->esp + 0x74u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x6Cu)) < (uint32_t)(cpu->ebp)) goto label_000BCD4E;
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCD4Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCD4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCD4Eu);
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x94u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BCD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCD80u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04)) == (uint32_t)(cpu->ebx)) goto label_000BCDBF;
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000BCDBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCDBFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCDC4u); lift_push32(cpu, r); sfera_sub_004A4B10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"control.cfg";
    g_sfera_interface_runtime.cross_enabled = (uint32_t)(1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCDD8u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.cross_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"EN_CROSS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCDE7u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.sounds_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"INTFS_SOUNDS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCDF6u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02)) != (uint32_t)(cpu->ebx)) goto label_000BCE4F;
    cpu->edx = 0x364u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE0Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x314u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE17u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000BCE2F;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE2Du); lift_push32(cpu, r); sfera_sub_004A17F0(cpu,r); if (cpu->eip != r) return; }
    goto label_000BCE31;
    label_000BCE2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCE2Fu);
    cpu->eax = 0u;
    label_000BCE31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCE31u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE45u); lift_push32(cpu, r); sfera_sub_004A18E0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_interface_runtime.cursor_kind = (uint32_t)(0xFFu);
    label_000BCE4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCE4Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE54u); lift_push32(cpu, r); sfera_sub_004BC290(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000BCE92;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->ecx + 8u, 0xFFu);
    lift_store8(cpu->ecx + 1u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE6Eu); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    g_sfera_interface_runtime.cursor_kind = (uint32_t)(0xFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000BCE92;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE8Cu); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    g_sfera_ui_load_scratch_runtime.cursor_name[0] = (uint8_t)((cpu->ebx & 0xFFu));
    label_000BCE92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCE92u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCE97u); lift_push32(cpu, r); sfera_sub_004BCAD0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"Effects\\loadscreen.ui");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCEA1u); lift_push32(cpu, r); sfera_sub_004BA190(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"Effects\\sprites.ui");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCEABu); lift_push32(cpu, r); sfera_sub_004B8850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0xFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCEB5u); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCEBAu); lift_push32(cpu, r); sfera_sub_004B9F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x1Eu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCEC4u); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCEC9u); lift_push32(cpu, r); sfera_sub_004BA370(cpu,r); if (cpu->eip != r) return; }
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = (uint8_t)((cpu->ebx & 0xFFu));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) = (uint32_t)(1u);
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BCEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCEF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04)) != (uint32_t)(cpu->edi)) goto label_000BCF01;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000BCF01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCF01u);
    lift_push32(cpu, cpu->esi);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02)) == (uint32_t)(cpu->edi)) goto label_000BCF39;
    cpu->edx = 0x392u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF19u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BCF33;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF2Au); lift_push32(cpu, r); sfera_sub_004A1860(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF30u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCF33: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCF33u);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02) = (uint32_t)(cpu->edi);
    label_000BCF39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCF39u);
    g_sfera_interface_runtime.cursor_kind = (uint32_t)(0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF48u); lift_push32(cpu, r); sfera_sub_004B94A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF4Du); lift_push32(cpu, r); sfera_sub_004B9410(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF52u); lift_push32(cpu, r); sfera_sub_004B9390(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF57u); lift_push32(cpu, r); sfera_sub_004A5460(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000BCF92;
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF73u); lift_push32(cpu, r); sfera_sub_004BA8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_core_runtime.object_aux);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF8Cu); lift_push32(cpu, r); sfera_sub_004BC000(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count) = (uint32_t)(cpu->esi);
    label_000BCF92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCF92u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCF97u); lift_push32(cpu, r); sfera_sub_004B9B10(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) = (uint32_t)(cpu->edi);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08)) == (uint32_t)(cpu->edi)) goto label_000BCFE3;
    cpu->edx = 0x3A4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCFB4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000BCFDD;
    cpu->ecx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CF160)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x98u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCFD4u); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BCFDAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BCFDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCFDDu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = (uint32_t)(cpu->edi);
    label_000BCFE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BCFE3u);
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = (uint32_t)(cpu->edi);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BD000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD000u);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000BD32A;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000BD32A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_000BD066;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store32(cpu->esp + 0xCu, cpu->ebp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000BD058;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBD058u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BD058: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD058u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000BD066: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD066u);
    cpu->edi = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x34u);
    cpu->edi += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    cpu->ebx += cpu->ecx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000BD0C3;
    cpu->edx = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->eax + 0xDCu)) == (uint32_t)(cpu->edx)) goto label_000BD0B6;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000BD09F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD09F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD09Fu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000BD0B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD0B6u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000BD0C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD0C3u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000BD113;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000BD106;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000BD0EF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD0EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD0EFu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000BD106: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD106u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000BD113: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD113u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) == (uint32_t)(cpu->ebp)) goto label_000BD327;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ebp = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000BD135;
    cpu->eax += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->edi = 0u;
    label_000BD135: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD135u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000BD13D;
    cpu->ebp += cpu->ebx;
    cpu->ebx = 0u;
    label_000BD13D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD13Du);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = g_sfera_graphics_runtime.display_width;
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000BD14F;
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000BD14F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD14Fu);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = (uint32_t)(cpu->ebx + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000BD15F;
    cpu->eax -= cpu->ebx;
    cpu->ebp = cpu->eax;
    label_000BD15F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD15Fu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD1A1u); lift_push32(cpu, r); sfera_sub_004D8990(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD1D1u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1E0u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B4u))) goto label_000BD2C4;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B8u))) goto label_000BD2C4;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->esi + 0x1DCu);
    cpu->edx = lift_load32(cpu->eax + 0x30u);
    cpu->edi = lift_load32(cpu->eax + 0x34u);
    cpu->ebx = lift_load32(cpu->eax + 0x28u);
    cpu->ebp = lift_load32(cpu->eax + 0x2Cu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BD27B;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000BD242;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD242: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD242u);
    cpu->esp -= 0x10u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000BD25B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD25B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD25Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x1DCu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD279u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000BD2C4;
    label_000BD27B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD27Bu);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000BD28D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD28D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD28Du);
    cpu->esp -= 0x10u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000BD2A6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD2A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD2A6u);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBD2C4u); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    label_000BD2C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD2C4u);
    cpu->edi = lift_load32(cpu->esi + 0x1B4u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B8u))) goto label_000BD2EB;
    label_000BD2D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD2D2u);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD2E2u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B8u))) goto label_000BD2D2;
    label_000BD2EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD2EBu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD2FBu); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x1B4u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B8u))) goto label_000BD327;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BD310: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD310u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD31Eu); lift_push32(cpu, r); sfera_sub_004D2810(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B8u))) goto label_000BD310;
    label_000BD327: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD327u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000BD32A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD32Au);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x40u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BD340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD340u);
    cpu->esp -= 0x6Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x78u);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BD6BA;
    cpu->ecx = lift_load32(cpu->ebx + 0x1D0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BD376;
    lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BD376: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD376u);
    cpu->ecx = lift_load32(cpu->ebx + 0x1D4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BD388;
    lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BD388: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD388u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x1D9u)) != (uint8_t)(0u)) goto label_000BD39B;
    lift_store32(cpu->ebx + 0x1E0u, 0xFFFFFFFFu);
    label_000BD39B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD39Bu);
    cpu->ecx = lift_load32(cpu->ebx + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->ebx + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->ebx + 0xD8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x48u, 0xFA1u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BD44E;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BD3D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD3D0u);
    cpu->edx = lift_load32(cpu->ebx + 0x19Cu);
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD3E5u); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BD43A;
    cpu->ebp = cpu->edi & 0xFFFFu;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BD3F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD3F0u);
    cpu->edx = lift_load16(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x10u), 32u);
    cpu->edx |= cpu->ebp;
    lift_store32(cpu->esp + 0x4Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x50u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_store32(cpu->esp + 0x58u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD426u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD432u); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BD3F0;
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_000BD43A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD43Au);
    cpu->ecx = lift_load32(cpu->ebx + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->ebx + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ecx)) goto label_000BD3D0;
    label_000BD44E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD44Eu);
    cpu->edi = lift_load32(cpu->ebx + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    cpu->esi = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000BD48D;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000BD47F;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBD47Fu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BD47F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD47Fu);
    cpu->ecx = lift_load32(cpu->edi + 0x30u);
    cpu->esi = lift_load32(cpu->edi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    cpu->esi += lift_load32(cpu->esp + 0x14u);
    label_000BD48D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD48Du);
    cpu->eax = lift_load32(cpu->ebx + 0x30u);
    cpu->edx = lift_load32(cpu->ebx + 0x34u);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->edx += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000BD4BD;
    cpu->esi = lift_load32(cpu->ebx + 0x28u);
    cpu->esi += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000BD4BD;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->edx)) goto label_000BD4BD;
    cpu->esi = lift_load32(cpu->ebx + 0x2Cu);
    cpu->esi += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000BD4BD;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    goto label_000BD4DF;
    label_000BD4BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD4BDu);
    cpu->ecx = 7u;
    cpu->esi = cpu->ebp;
    cpu->edi = (uint32_t)(cpu->esp + 0x5Cu);
    lift_movs32(cpu, 1u);
    cpu->ecx = 0xFFFFu;
    lift_store32(cpu->esp + 0x60u, cpu->ecx);
    lift_store32(cpu->esp + 0x5Cu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    label_000BD4DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD4DFu);
    cpu->ecx = lift_load32(cpu->ebx + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BD6B8;
    cpu->edx -= lift_load32(cpu->ebx + 0x1C4u);
    cpu->eax -= lift_load32(cpu->ebx + 0x1C0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x1E5u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BD54A;
    cpu->esi = lift_load32(cpu->ebx + 0x1B4u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1B8u))) goto label_000BD5C3;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000BD520: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD520u);
    cpu->edx = lift_load32(cpu->ebx + 0x19Cu);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD531u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD53Fu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1B8u))) goto label_000BD520;
    goto label_000BD5C3;
    label_000BD54A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD54Au);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    cpu->esi = lift_load32(cpu->ecx + 0x2Cu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x1E4u)) & 0xFFu);
    cpu->edi = lift_load32(cpu->ebx + 0x1B4u);
    cpu->ebp = cpu->ecx & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->ebp), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ebp = v; }
    cpu->ebp = (uint64_t)(cpu->ebp) - (uint64_t)(cpu->ebp) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ebp &= cpu->edx;
    cpu->edx = 0u;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->edx;
    cpu->edx &= cpu->esi;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1B8u))) goto label_000BD5BF;
    goto label_000BD584;
    label_000BD580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD580u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_000BD584: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD584u);
    cpu->ecx = lift_load32(cpu->ebx + 0x19Cu);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD59Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD5AAu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1B8u))) goto label_000BD580;
    label_000BD5BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD5BFu);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_000BD5C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD5C3u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x1D9u)) == (uint8_t)(0u)) goto label_000BD6B8;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->ebp)) goto label_000BD6B8;
    if ((uint8_t)((lift_load8(cpu->ebp + 0xCu)) & (1u)) == 0u) goto label_000BD6B8;
    cpu->edi = lift_load32(cpu->ebx + 0x1B4u);
    cpu->esi |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1B8u))) goto label_000BD680;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->ebx + 0x19Cu);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    label_000BD614: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD614u);
    cpu->esi = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000BD63A;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBD63Au); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BD63A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD63Au);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_000BD66A;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000BD66A;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->eax)) goto label_000BD66A;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000BD678;
    label_000BD66A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD66Au);
    ++cpu->edi;
    cpu->ebp += 4u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1B8u))) goto label_000BD614;
    goto label_000BD67C;
    label_000BD678: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD678u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_000BD67C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD67Cu);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000BD680: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD680u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1E0u)) == (uint32_t)(cpu->esi)) goto label_000BD6B8;
    cpu->eax = lift_load32(cpu->ebx + 0xD8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x9Cu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, 0xFA3u);
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD6B2u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x1E0u, cpu->esi);
    label_000BD6B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD6B8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BD6BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD6BAu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x6Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BD6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD6D0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000BD875;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B0u)) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000BD6F5;
    lift_store32(cpu->esi + 0x1B0u, cpu->ebx);
    label_000BD6F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD6F5u);
    cpu->eax = lift_load32(cpu->esi + 0x1C8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B0u)) <= (uint32_t)(cpu->eax)) goto label_000BD709;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    label_000BD709: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD709u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1ACu)) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000BD717;
    lift_store32(cpu->esi + 0x1ACu, cpu->ebx);
    label_000BD717: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD717u);
    cpu->eax = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1ACu)) <= (uint32_t)(cpu->eax)) goto label_000BD72B;
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    label_000BD72B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD72Bu);
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    cpu->ecx = lift_load32(cpu->ecx + 0x2Cu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1E4u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BD7A0;
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000BD74B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD74B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD74Bu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1B0u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f64(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD770u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->esp += 8u;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x10u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD792u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1ACu);
    goto label_000BD805;
    label_000BD7A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD7A0u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000BD7B2;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BD7B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD7B2u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1ACu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f64(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD7D7u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->esp += 8u;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x10u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD7F9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    label_000BD805: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD805u);
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BD810u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x1BCu);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 1u);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->esi + 0x1B8u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_000BD83F;
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    label_000BD83F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD83Fu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1E5u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BD86E;
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1B4u, cpu->ebx);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    label_000BD86E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD86Eu);
    lift_store8(cpu->esi + 0x1D8u, 1u);
    label_000BD875: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD875u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BD880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD880u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, 255.0);
    cpu->esi = cpu->ecx;
    lift_store16(cpu->esp + 6u, cpu->fpu_control);
    lift_push32(cpu, cpu->edi);
    cpu->eax = lift_load16(cpu->esp + 0xAu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xCu));
    lift_store64(cpu->esp + 0xCu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xAu));
    lift_store32(cpu->esi + 0xDCu, cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BD8E9;
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD8E7u);
    goto label_000BD8EB;
    label_000BD8E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD8E9u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000BD8EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD8EBu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx -= lift_load32(cpu->esi + 0x19Cu);
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BD92C;
    label_000BD900: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD900u);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD918u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_000BD900;
    label_000BD92C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD92Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BD940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD940u);
    cpu->edx = lift_load32(cpu->ecx + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_000BD95C;
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_000BD95C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD95Cu);
    cpu->ecx = lift_load32(cpu->ecx + 0x19Cu);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BD970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD970u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x48u)) == (uint8_t)(0u)) goto label_000BD981;
    label_000BD97A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD97Au);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000BD981: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD981u);
    cpu->eax = lift_load32(cpu->ebp + 0x1B4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x1B8u))) goto label_000BD97A;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    label_000BD9A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD9A0u);
    cpu->eax = lift_load32(cpu->ebp + 0x19Cu);
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u));
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Cu)) == (uint8_t)(0u)) goto label_000BDA0D;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000BD9D2;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBD9D2u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BD9D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BD9D2u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->edi)) goto label_000BDA0D;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000BDA0D;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->eax)) goto label_000BDA0D;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000BDA0D;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->hitTest(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA09u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BDA16;
    label_000BDA0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA0Du);
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x1B8u))) goto label_000BD9A0;
    label_000BDA16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA16u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA30u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebx + 0x1A0u);
    cpu->edi -= lift_load32(cpu->ebx + 0x19Cu);
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000BDA7B;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    (void)cpu;
    label_000BDA50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA50u);
    cpu->eax = lift_load32(cpu->ebx + 0x19Cu);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA75u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edi)) goto label_000BDA50;
    cpu->ebp = lift_pop32(cpu);
    label_000BDA7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA7Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDA90u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000BDC6F;
    cpu->ecx = lift_load32(cpu->eax + 0x28u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->eax + 0x2Cu);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1E4u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000BDB11;
    cpu->edi = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax = cpu->edi;
    lift_divide_accumulator(cpu, cpu->ebp, 32u, 0u);
    ++cpu->eax;
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebp);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->eax)) goto label_000BDAF0;
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    goto label_000BDAF8;
    label_000BDAF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDAF0u);
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000BDAF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDAF8u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000BDB07;
    lift_store32(cpu->esi + 0x1CCu, cpu->ebx);
    goto label_000BDB5E;
    label_000BDB07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB07u);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esi + 0x1CCu, cpu->ecx);
    goto label_000BDB5E;
    label_000BDB11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB11u);
    cpu->edi = lift_load32(cpu->esi + 0x28u);
    cpu->eax = cpu->edi;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    ++cpu->eax;
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->eax)) goto label_000BDB3D;
    lift_store32(cpu->esi + 0x1CCu, cpu->ebx);
    goto label_000BDB45;
    label_000BDB3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB3Du);
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esi + 0x1CCu, cpu->eax);
    label_000BDB45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB45u);
    cpu->edi = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebp)) goto label_000BDB54;
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    goto label_000BDB5E;
    label_000BDB54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB54u);
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    label_000BDB5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB5Eu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1B0u)) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000BDB6C;
    lift_store32(cpu->esi + 0x1B0u, cpu->ebx);
    label_000BDB6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB6Cu);
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B0u)) <= (uint32_t)(cpu->edx)) goto label_000BDB80;
    lift_store32(cpu->esi + 0x1B0u, cpu->edx);
    label_000BDB80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB80u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1ACu)) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000BDB8E;
    lift_store32(cpu->esi + 0x1ACu, cpu->ebx);
    label_000BDB8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDB8Eu);
    cpu->eax = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1ACu)) <= (uint32_t)(cpu->eax)) goto label_000BDBA2;
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    label_000BDBA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDBA2u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    cpu->ebx = 0x17u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BDC02;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1B0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBDC02u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    label_000BDC02: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDC02u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BDC68;
    cpu->edx = lift_load32(cpu->esi + 0x1CCu);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBDC68u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    label_000BDC68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDC68u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBDC6Fu); lift_push32(cpu, r); sfera_sub_004BD6D0(cpu,r); if (cpu->eip != r) return; }
    label_000BDC6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDC6Fu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDC80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDC80u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000BDC9D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000BDC9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDC9Du);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0x3FFFFFFFu)) goto label_000BDCB0;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBDCB0u);
    label_000BDCB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDCB0u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BDCB9u); lift_push32(cpu, r); sfera_sub_0049F1D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDCD0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BDCD8u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    std::construct_at(reinterpret_cast<SphereUI::ListItemCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    lift_store32(cpu->esi + 0x1CCu, cpu->eax);
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    lift_store32(cpu->esi + 0x1D4u, cpu->eax);
    lift_store16(cpu->esi + 0x1D8u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esi + 0x1DCu, cpu->eax);
    lift_store16(cpu->esi + 0x1E4u, cpu->eax & 0xFFFFu);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    lift_store32(cpu->esi + 0x1E0u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x50u, 0xCu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDD70u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000BDE77;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    cpu->edx = 0x1F5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BDDBEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000BDDCD;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BDDCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDDCDu);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000BDDD9;
    cpu->ecx += cpu->ebp;
    label_000BDDD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDDD9u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->eax = (uint32_t)(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4BDDEEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDDF4u);
    lift_store32(cpu->esi + 0x1A0u, (uint64_t)(lift_load32(cpu->esi + 0x1A0u)) + (uint64_t)(0xFFFFFFFCu) + (uint64_t)(0u));
    cpu->esp += 0xCu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0x1E0u))) goto label_000BDE16;
    lift_store32(cpu->esi + 0x1E0u, 0xFFFFFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_000BDE16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDE16u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1E0u)) < (uint32_t)(cpu->eax)) goto label_000BDE36;
    --cpu->eax;
    lift_store32(cpu->esi + 0x1E0u, cpu->eax);
    goto label_000BDE3A;
    label_000BDE36: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDE36u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000BDE77;
    label_000BDE3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDE3Au);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BDE77;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1D9u)) == (uint8_t)(0u)) goto label_000BDE77;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = lift_load32(cpu->esi + 0x1E0u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0xFA3u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBDE77u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000BDE77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDE77u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDE90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDE90u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = 0x3FFFFFFFu;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000BDEB6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBDEB6u);
    label_000BDEB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDEB6u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000BDEEA;
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->edi = 0x3FFFFFFFu;
    cpu->edi -= cpu->esi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_000BDED7;
    cpu->edx = 0u;
    goto label_000BDED9;
    label_000BDED7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDED7u);
    cpu->edx += cpu->esi;
    label_000BDED9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDED9u);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000BDEDF;
    cpu->edx = cpu->eax;
    label_000BDEDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDEDFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    sfera_sub_00429830(cpu, stop_address); return;
    label_000BDEEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDEEAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDEF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BDF7F;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BDF4B;
    cpu->edi = cpu->edi;
    label_000BDF10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDF10u);
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u));
    cpu->edx = 0x218u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BDF28u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_000BDF37;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BDF37: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDF37u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->ebx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->ecx)) goto label_000BDF10;
    label_000BDF4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDF4Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    cpu->edi = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000BDF7D;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4BDF6Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDF72u);
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    label_000BDF7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDF7Du);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000BDF7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDF7Fu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BDF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDF90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000BDFCF;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_000BDFCF;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000BDFB8;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBDFB8u); lift_push32(cpu, r); sfera_sub_004BDE90(cpu,r); if (cpu->eip != r) return; }
    label_000BDFB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDFB8u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BDFE8;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000BDFCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDFCFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000BDFDD;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBDFDDu); lift_push32(cpu, r); sfera_sub_004BDE90(cpu,r); if (cpu->eip != r) return; }
    label_000BDFDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDFDDu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BDFE8;
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->ecx);
    label_000BDFE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BDFE8u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BE000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE000u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::ListItemCtrl*>(cpu->esi));
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) == (uint32_t)(cpu->edi)) goto label_000BE067;
    cpu->edx = (uint32_t)(cpu->edi + 0x57u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE04Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BE061;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BE061: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE061u);
    lift_store32(cpu->esi + 0x198u, cpu->edi);
    label_000BE067: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE067u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE06Eu); lift_push32(cpu, r); sfera_sub_004BDEF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D0u)) == (uint32_t)(cpu->edi)) goto label_000BE09E;
    cpu->edx = 0x5Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE085u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BE098;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BE098: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE098u);
    lift_store32(cpu->esi + 0x1D0u, cpu->edi);
    label_000BE09E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE09Eu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D4u)) == (uint32_t)(cpu->edi)) goto label_000BE0CE;
    cpu->edx = 0x65u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE0B5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BE0C8;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BE0C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE0C8u);
    lift_store32(cpu->esi + 0x1D4u, cpu->edi);
    label_000BE0CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE0CEu);
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000BE0E1;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE0DEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BE0E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE0E1u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x19Cu, cpu->edi);
    lift_store32(cpu->esi + 0x1A0u, cpu->edi);
    lift_store32(cpu->esi + 0x1A4u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE102u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BE120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE120u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) == (uint32_t)(0u)) goto label_000BE165;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE13Au);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store8(cpu->eax + 0x48u, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x19Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE152u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    --cpu->eax;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000BE165: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE165u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BE170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE170u);
    cpu->esp -= 0x20u;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFA2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000BE28A;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BE265;
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x65u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BE241;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BE21D;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x10u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BE383;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BE26C;
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 8u, 0x17u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BE1F2;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE1F2u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    label_000BE1F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE1F2u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BE273;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE206u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE21D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE21Du);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE22Au); lift_push32(cpu, r); sfera_sub_004BD6D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE241: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE241u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE24Eu); lift_push32(cpu, r); sfera_sub_004BD6D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE265: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE265u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE26Cu); lift_push32(cpu, r); sfera_sub_004BE120(cpu,r); if (cpu->eip != r) return; }
    label_000BE26C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE26Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE273u); lift_push32(cpu, r); sfera_sub_004BDA90(cpu,r); if (cpu->eip != r) return; }
    label_000BE273: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE273u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE28A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE28Au);
    cpu->edx = (uint32_t)(cpu->ecx + 0xFFFFF05Cu);
    if ((uint32_t)(cpu->edx) > (uint32_t)(4u)) goto label_000BE383;
    switch ((uint32_t)(cpu->edx)) {
        case 0u: goto label_000BE2A0;
        case 1u: goto label_000BE2BF;
        case 2u: goto label_000BE2F9;
        case 3u: goto label_000BE321;
        case 4u: goto label_000BE35E;
        default: lift_trap(cpu, 0x4BE299u, "resolved jump-table index out of range"); return;
    }
label_000BE2A0: ;
    cpu->ecx = lift_load32(cpu->esi + 0x1E0u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE2BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE2BFu);
    lift_store32(cpu->esi + 0x1E0u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_000BE2E2;
    lift_store32(cpu->esi + 0x1E0u, 0xFFFFFFFFu);
    label_000BE2E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE2E2u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE2F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE2F9u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = 1u;
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE321: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE321u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_000BE273;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE340u); lift_push32(cpu, r); sfera_sub_004BDD70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE347u); lift_push32(cpu, r); sfera_sub_004BDA90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE35E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE35Eu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE365u); lift_push32(cpu, r); sfera_sub_004BDEF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE36Cu); lift_push32(cpu, r); sfera_sub_004BDA90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000BE383: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE383u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE391u); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BE3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE3C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE3C8u); lift_push32(cpu, r); sfera_sub_004BE000(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000BE3D8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE3D5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BE3D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE3D8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BE3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE3E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esp + 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE419u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) != (uint32_t)(0u)) goto label_000BE43C;
    lift_push32(cpu, 0x77u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE433u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE439u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000BE43C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE43Cu);
    cpu->edi = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"vscrollbar");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE454u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE47C;
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE46Eu); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE47Cu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000BE47C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE47Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"hscrollbar");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE490u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE4D2;
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE4AAu); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1D4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE4B8u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE4C3u); lift_push32(cpu, r); sfera_sub_004C7DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    cpu->eax |= 1u;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE4D2u); lift_push32(cpu, r); sfera_sub_004C7DA0(cpu,r); if (cpu->eip != r) return; }
    label_000BE4D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE4D2u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"itemTemplate");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE4E6u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE5A6;
    cpu->edx = 0x8Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE4FDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE507u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE523;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE521u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    goto label_000BE525;
    label_000BE523: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE523u);
    cpu->eax = 0u;
    label_000BE525: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE525u);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x3Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE541u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE554u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BE573;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListItemCtrl::LoadUI(%s,%d,%d) -> Can't load item template.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE56Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE570u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000BE573: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE573u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE580u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    lift_store8(cpu->edx + 0x48u, 0u);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->eax + 0xF4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    lift_store8(cpu->edx + 0x4Au, 1u);
    label_000BE5A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE5A6u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"createItems");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE5B3u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE678;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE5C4u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000BE678;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000BE5D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE5D0u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BE66A;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE5E5u);
    cpu->ebp = cpu->eax;
    lift_store8(cpu->ebp + 0x48u, 0u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x44u, cpu->ebp);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000BE63E;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edx)) goto label_000BE63E;
    cpu->ebp = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_arithmetic(cpu, cpu->ebp, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 0x1A4u))) goto label_000BE627;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x19Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE627u); lift_push32(cpu, r); sfera_sub_004BDE90(cpu,r); if (cpu->eip != r) return; }
    label_000BE627: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE627u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE65F;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    lift_store32(cpu->eax, cpu->edx);
    goto label_000BE65F;
    label_000BE63E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE63Eu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 0x1A4u))) goto label_000BE653;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x19Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE653u); lift_push32(cpu, r); sfera_sub_004BDE90(cpu,r); if (cpu->eip != r) return; }
    label_000BE653: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE653u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE65F;
    lift_store32(cpu->eax, cpu->ebp);
    label_000BE65F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE65Fu);
    cpu->edi = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->esi + 0x1A0u, (uint64_t)(lift_load32(cpu->esi + 0x1A0u)) + (uint64_t)(4u) + (uint64_t)(0u));
    label_000BE66A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE66Au);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BE5D0;
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    label_000BE678: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE678u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"selectSprite");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE685u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE6D5;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.list_item_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE697u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE6D5;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.list_item_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE6ABu); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1DCu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000BE6D5;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.list_item_value[0]); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListItemCtrl::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE6CCu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE6D2u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    label_000BE6D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE6D5u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"selectedItem");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE6E2u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE712;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE6EFu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1E0u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_000BE712;
    lift_store32(cpu->esi + 0x1E0u, 0xFFFFFFFFu);
    label_000BE712: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE712u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"canSelectItems");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE71Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE737;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE72Cu); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x1D9u, cpu->eax & 0xFFu);
    label_000BE737: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE737u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"horizontal");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE744u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE75C;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE751u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x1E4u, cpu->ecx & 0xFFu);
    label_000BE75C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE75Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"userMove");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE769u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE781;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE776u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x1E5u, cpu->edx & 0xFFu);
    label_000BE781: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE781u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE788u); lift_push32(cpu, r); sfera_sub_004BDA90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE794u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BE7B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE7B0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE7BEu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x19Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x19Cu);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE7DCu); lift_push32(cpu, r); sfera_sub_004A9980(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1B0u);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    lift_store32(cpu->esi + 0x1B4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1B8u);
    lift_store32(cpu->esi + 0x1B8u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1BCu);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1C0u);
    lift_store32(cpu->esi + 0x1C0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1C4u);
    lift_store32(cpu->esi + 0x1C4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1CCu);
    lift_store32(cpu->esi + 0x1CCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1D0u);
    lift_store32(cpu->esi + 0x1D0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1D4u);
    lift_store32(cpu->esi + 0x1D4u, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1D8u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1D8u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->edi + 0x1D9u);
    lift_store8(cpu->esi + 0x1D9u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->edi + 0x1DCu);
    lift_store32(cpu->esi + 0x1DCu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1E0u);
    lift_store32(cpu->esi + 0x1E0u, cpu->ecx);
    cpu->edx = lift_load8(cpu->edi + 0x1E4u);
    lift_store8(cpu->esi + 0x1E4u, cpu->edx & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1E5u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1E5u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BE8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE8C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    cpu->edx = 0x130u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE8FCu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1E8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE906u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BE924;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE920u); lift_push32(cpu, r); sfera_sub_004BDCD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    goto label_000BE926;
    label_000BE924: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE924u);
    cpu->ebx = 0u;
    label_000BE926: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE926u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BE936u); lift_push32(cpu, r); sfera_sub_004BE7B0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->ebx + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xECu)) == (uint32_t)(0u)) goto label_000BE95E;
    cpu->ecx = lift_load32(cpu->ebp + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE950u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebx + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBE95Eu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000BE95E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE95Eu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x198u)) == (uint32_t)(0u)) goto label_000BE97A;
    cpu->ecx = lift_load32(cpu->ebp + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE974u);
    lift_store32(cpu->ebx + 0x198u, cpu->eax);
    label_000BE97A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE97Au);
    cpu->eax = lift_load32(cpu->ebp + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebp + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BEB14;
    cpu->ecx = lift_load32(cpu->ebx + 0x1A0u);
    cpu->edi = lift_load32(cpu->ebx + 0x19Cu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000BE9C7;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4BE9B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE9B8u);
    cpu->esp += 0xCu;
    cpu->ebp += cpu->edi;
    lift_store32(cpu->ebx + 0x1A0u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_000BE9C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE9C7u);
    cpu->ecx = lift_load32(cpu->ebp + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->ebp + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BEB14;
    label_000BE9F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE9F0u);
    cpu->ecx = lift_load32(cpu->ebx + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BE9FDu);
    cpu->edi = cpu->eax;
    lift_store8(cpu->edi + 0x48u, 0u);
    cpu->eax = lift_load32(cpu->ebx + 0x1A0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000BEA8C;
    cpu->edx = lift_load32(cpu->ebx + 0x19Cu);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_000BEA8C;
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000BEA75;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3FFFFFFEu)) goto label_000BEB72;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000BEA75;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->ebp = 0x3FFFFFFFu;
    cpu->ebp -= cpu->edx;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ecx)) goto label_000BEA5D;
    cpu->ecx = 0u;
    goto label_000BEA5F;
    label_000BEA5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEA5Du);
    cpu->ecx += cpu->edx;
    label_000BEA5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEA5Fu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000BEA65;
    cpu->ecx = cpu->eax;
    label_000BEA65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEA65u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x19Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BEA71u); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_000BEA75: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEA75u);
    cpu->eax = lift_load32(cpu->ebx + 0x1A0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BEAED;
    cpu->edx = lift_load32(cpu->ebx + 0x19Cu);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->eax, cpu->ecx);
    goto label_000BEAED;
    label_000BEA8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEA8Cu);
    cpu->ecx = lift_load32(cpu->ebx + 0x1A4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000BEAE1;
    cpu->edx = lift_load32(cpu->ebx + 0x19Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3FFFFFFEu)) goto label_000BEB72;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000BEAE1;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->ebp = 0x3FFFFFFFu;
    cpu->ebp -= cpu->edx;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ecx)) goto label_000BEAC9;
    cpu->ecx = 0u;
    goto label_000BEACB;
    label_000BEAC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEAC9u);
    cpu->ecx += cpu->edx;
    label_000BEACB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEACBu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000BEAD1;
    cpu->ecx = cpu->eax;
    label_000BEAD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEAD1u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x19Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BEADDu); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_000BEAE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEAE1u);
    cpu->eax = lift_load32(cpu->ebx + 0x1A0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BEAED;
    lift_store32(cpu->eax, cpu->edi);
    label_000BEAED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEAEDu);
    lift_store32(cpu->ebx + 0x1A0u, (uint64_t)(lift_load32(cpu->ebx + 0x1A0u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ebp + 0x19Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_000BE9F0;
    label_000BEB14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEB14u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x1D0u)) == (uint32_t)(0u)) goto label_000BEB38;
    cpu->ecx = lift_load32(cpu->ebp + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEB2Au);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebx + 0x1D0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBEB38u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000BEB38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEB38u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x1D4u)) == (uint32_t)(0u)) goto label_000BEB5C;
    cpu->ecx = lift_load32(cpu->ebp + 0x1D4u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEB4Eu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->ebx + 0x1D4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBEB5Cu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000BEB5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEB5Cu);
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_000BEB72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEB72u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    lift_trap(cpu, 0x4BEB7Du, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BEB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEB80u);
    cpu->eax = sfera_key_dik_from_virtual_key(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BEBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEBA0u);
    cpu->eax = sfera_key_virtual_key_from_dik(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BEBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEBC0u);
    cpu->eax = sfera_key_code_from_name(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BEC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEC00u);
    const char* name = sfera_key_name_from_code(cpu->ecx);
    cpu->eax = (uintptr_t)(name ? name : "???");
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BEC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEC20u);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1DCu);
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->ebx = lift_load32(cpu->esi + 0x2Cu);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 2u));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000BEC5F;
    cpu->edi += cpu->ebp;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    label_000BEC5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEC5Fu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000BEC71;
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->ebx += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_000BEC71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEC71u);
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx = (uint32_t)(cpu->edi + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000BEC81;
    cpu->eax -= cpu->ebp;
    cpu->edi = cpu->eax;
    label_000BEC81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEC81u);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = (uint32_t)(cpu->ebx + cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000BEC91;
    cpu->eax -= cpu->ecx;
    cpu->ebx = cpu->eax;
    label_000BEC91: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEC91u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esp + 0x78u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000BECDD;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BECD9u); lift_push32(cpu, r); sfera_sub_004D8990(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_000BECDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BECDDu);
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x38u, cpu->ebp);
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BED09u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1E4u);
    cpu->ebx = lift_load32(cpu->esi + 0x1BCu);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x1E0u);
    cpu->esi = lift_load32(cpu->esi + 0xDCu);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0x18u), 32u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi);
    cpu->ebx += lift_load32(cpu->esp + 0x74u);
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(0x18u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ecx = cpu->edi;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x10u));
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x74u)))));
    { uint64_t l=cpu->esp, r=(uint64_t)(0x10u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(7u), 32u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->edi &= 0xFFFFFFu;
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx |= cpu->edi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BEDBAu); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->esp -= 0x10u;
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BEDECu); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BEE1Au); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BEE48u); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    --cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BEE7Au); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x78u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BEE95;
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBEE95u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    label_000BEE95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEE95u);
    cpu->esp += 0x58u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BEEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEEB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000BEEE0;
    cpu->edx = lift_load32(cpu->ecx + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->eax)) goto label_000BEEE0;
    lift_store32(cpu->ecx + 0x1D8u, cpu->esi);
    label_000BEEE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEEE0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BEEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEEF0u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x3Cu);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 8u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BF113;
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BEF26;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000BEF26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEF26u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1D4u)) != (uint8_t)(0u)) goto label_000BEF4C;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1D8u, 0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 4u, stop_address); return;
    label_000BEF4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEF4Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ebx = cpu->edx;
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BF112;
    if ((uint8_t)((lift_load8(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000BF112;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = 0u;
    cpu->eax = 0u;
    cpu->edx = 0u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ecx)) goto label_000BEFBA;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x9Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BEFAC;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBEFACu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BEFAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEFACu);
    cpu->eax = lift_load32(cpu->ebp + 0x30u);
    cpu->edx = lift_load32(cpu->ebp + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->edx += lift_load32(cpu->esp + 0x18u);
    label_000BEFBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BEFBAu);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    cpu->ecx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000BF111;
    cpu->edi = lift_load32(cpu->esi + 0x28u);
    cpu->edi += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->edi)) goto label_000BF111;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000BF111;
    cpu->edi = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->edi + cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000BF111;
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    cpu->ecx -= cpu->eax;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1CCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BF022;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(lift_load32(cpu->esi + 0x1C0u))) goto label_000BF022;
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edi -= cpu->ecx;
    cpu->edx += cpu->edi;
    label_000BF022: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF022u);
    cpu->eax -= cpu->edx;
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x1BCu), 32u, 0u);
    cpu->eax += lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ebx)) goto label_000BF039;
    cpu->eax |= 0xFFFFFFFFu;
    label_000BF039: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF039u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1D8u))) goto label_000BF06D;
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, 0xE16u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBF06Du); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000BF06D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF06Du);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1F0u)) != (uint8_t)(0u)) goto label_000BF0A3;
    lift_store8(cpu->esi + 0x1F0u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF082u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1E8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ECu, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 4u, stop_address); return;
    label_000BF0A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF0A3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF0A8u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1E8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1ECu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.6);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000BF10A;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1D8u)) < (int32_t)(uint32_t)(0u)) goto label_000BF10A;
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, 0xE1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBF10Au); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000BF10A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF10Au);
    lift_store8(cpu->esi + 0x1F0u, 0u);
    label_000BF111: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF111u);
    cpu->ebp = lift_pop32(cpu);
    label_000BF112: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF112u);
    cpu->ebx = lift_pop32(cpu);
    label_000BF113: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF113u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BF130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF130u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1C4u)) >= (int32_t)(uint32_t)(0u)) goto label_000BF149;
    lift_store32(cpu->esi + 0x1C4u, 0u);
    label_000BF149: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF149u);
    cpu->eax = lift_load32(cpu->esi + 0x1B8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1C4u)) <= (uint32_t)(cpu->eax)) goto label_000BF15D;
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    label_000BF15D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF15Du);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1BCu)))));
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000BF174;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BF174: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF174u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1C4u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f64(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF199u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->esp += 8u;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x10u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 8u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF1BBu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF1C6u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1C0u);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x19Cu, cpu->edi);
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000BF204;
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    label_000BF204: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF204u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BF210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF210u);
    cpu->esp -= 0x78u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000BF9A9;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000BF9A9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000BF275;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000BF267;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBF267u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000BF267: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF267u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x24u);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    label_000BF275: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF275u);
    cpu->ebp = lift_load32(cpu->esi + 0x34u);
    cpu->ebx = lift_load32(cpu->esi + 0x30u);
    cpu->ebp += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BF956;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, cpu->eax);
    lift_store32(cpu->esp + 0x64u, cpu->eax);
    lift_store32(cpu->esp + 0x68u, cpu->eax);
    lift_store32(cpu->esp + 0x6Cu, cpu->eax);
    lift_store32(cpu->esp + 0x70u, cpu->eax);
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    lift_store32(cpu->esp + 0x78u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF2E8u); lift_push32(cpu, r); sfera_sub_004D8990(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->edi = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi + 0x1C8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1CCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000BF33B;
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esi + 0x1C0u))) goto label_000BF33B;
    cpu->edx = lift_load32(cpu->esi + 0x1BCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax -= cpu->edx;
    cpu->edi += cpu->eax;
    label_000BF33B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF33Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    cpu->edx = cpu->ebx;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000BF363;
    cpu->ecx += cpu->ebx;
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    label_000BF363: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF363u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000BF371;
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    label_000BF371: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF371u);
    cpu->edx += cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000BF385;
    cpu->ecx -= lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    label_000BF385: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF385u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000BF39C;
    cpu->ecx -= lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    label_000BF39C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF39Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x4Cu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x50u, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF3D4u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->ebx);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ebp);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx += cpu->ebx;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ebp;
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(0xFFu)) goto label_000BF417;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000BF417;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF411u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_screen_clip_runtime.right;
    label_000BF417: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF417u);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1CEu)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_000BF46A;
    cpu->ecx = 0x2E2E2020u;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"  ...") + 4u)) & 0xFFFFu);
    lift_store32(cpu->esp + 0x78u, cpu->ecx);
    lift_store16(cpu->esp + 0x7Cu, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF460u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_screen_clip_runtime.right;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    label_000BF46A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF46Au);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B0u)) != (uint32_t)(0u)) goto label_000BF663;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1CEu)) == (uint8_t)(0u)) goto label_000BF5D8;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x19Cu))) goto label_000BF8F6;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_000BF4C4;
    label_000BF4C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF4C0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_000BF4C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF4C4u);
    cpu->eax += lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->eax + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BF4DB;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    goto label_000BF4DF;
    label_000BF4DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF4DBu);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    label_000BF4DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF4DFu);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF501u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, 0.0);
    cpu->ebp &= 0xFFFFFFu;
    cpu->ebp |= lift_load32(cpu->esp + 0x28u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x28u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000BF582;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF54Du); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + cpu->edx + 0x20u);
    cpu->ecx += lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"  ...");
    goto label_000BF5AA;
    label_000BF582: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF582u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    label_000BF5AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF5AAu);
    cpu->edx = cpu->edi;
    cpu->ecx += cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF5B3u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi += lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x19Cu))) goto label_000BF4C0;
    goto label_000BF8F2;
    label_000BF5D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF5D8u);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x19Cu))) goto label_000BF8F6;
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    label_000BF600: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF600u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    cpu->eax = lift_load32(cpu->ecx + cpu->ebp + 0x1Cu);
    cpu->ecx += cpu->ebp;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_000BF614;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000BF614: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF614u);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->eax &= 0xFFFFFFu;
    cpu->eax |= lift_load32(cpu->esp + 0x30u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + cpu->ebp + 0x20u);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF644u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi += lift_load32(cpu->esi + 0x1BCu);
    ++cpu->eax;
    cpu->ebp += 0x24u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x19Cu))) goto label_000BF600;
    goto label_000BF8F2;
    label_000BF663: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF663u);
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    cpu->eax -= lift_load32(cpu->esi + 0x198u);
    cpu->ebp = lift_load32(cpu->esi + 0x1A0u);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0x1Fu), 32u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x198u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000BF6AE;
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000BF6AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF6AEu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_000BF6BA;
    cpu->edx -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->eax = cpu->edx;
    label_000BF6BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF6BAu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1CEu)) == (uint8_t)(0u)) goto label_000BF84A;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000BF8F2;
    lift_store32(cpu->esp + 0x18u, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    goto label_000BF704;
    label_000BF700: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF700u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_000BF704: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF704u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->eax += lift_load32(cpu->esi + 0x1A0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->eax + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BF726;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    goto label_000BF72A;
    label_000BF726: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF726u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    label_000BF72A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF72Au);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF74Cu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_x87_push(cpu, 0.0);
    cpu->ebp &= 0xFFFFFFu;
    cpu->ebp |= lift_load32(cpu->esp + 0x28u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x28u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000BF7CD;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    cpu->ecx = lift_load32(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF798u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + cpu->edx + 0x20u);
    cpu->ecx += lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"  ...");
    goto label_000BF7F5;
    label_000BF7CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF7CDu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->edx + cpu->ecx + 0x20u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    label_000BF7F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF7F5u);
    cpu->edx = cpu->edi;
    cpu->ecx += cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF7FEu); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1A0u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi + 0x1BCu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    ++cpu->ebp;
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->eax)) goto label_000BF836;
    lift_store32(cpu->esp + 0x10u, 0u);
    label_000BF836: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF836u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BF700;
    goto label_000BF8F2;
    label_000BF84A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF84Au);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000BF8F2;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    goto label_000BF864;
    label_000BF860: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF860u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_000BF864: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF864u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->eax = lift_load32(cpu->edx + cpu->ecx + 0x1Cu);
    cpu->edx += cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edx + 0x14u)) < (uint32_t)(0x10u)) goto label_000BF87F;
    cpu->edx = lift_load32(cpu->edx);
    label_000BF87F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF87Fu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ecx + cpu->ebp + 0x20u);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax &= 0xFFFFFFu;
    cpu->eax |= lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->ebx;
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF8B1u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->edi += lift_load32(cpu->esi + 0x1BCu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) < (uint32_t)(cpu->ecx)) goto label_000BF8E8;
    lift_store32(cpu->esp + 0x10u, 0u);
    label_000BF8E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF8E8u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000BF860;
    label_000BF8F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF8F2u);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    label_000BF8F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF8F6u);
    cpu->eax = lift_load32(cpu->esi + 0x1D8u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000BF927;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x19Cu))) goto label_000BF927;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x1BCu));
    cpu->eax += lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBF927u); lift_push32(cpu, r); sfera_sub_004BEC20(cpu,r); if (cpu->eip != r) return; }
    label_000BF927: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF927u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BF937u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(0xFFu)) goto label_000BF956;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000BF956;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBF956u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000BF956: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF956u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BF9A9;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000BF99C;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000BF985;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000BF985: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF985u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000BF99C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF99Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000BF9A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF9A9u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x78u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BF9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BF9C0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000BFA65;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000BFA01;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u) + 0x20u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000BFA01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFA01u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000BFA15;
    cpu->eax = lift_load32(cpu->eax);
    label_000BFA15: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFA15u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFA35u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (4u)) == 0u) goto label_000BFA4D;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_store32(cpu->edi + cpu->eax + 0x20u, cpu->edx);
    label_000BFA4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFA4Du);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_000BFA63;
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx -= lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    lift_store32(cpu->edi + cpu->edx + 0x20u, cpu->ecx);
    label_000BFA63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFA63u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000BFA65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFA65u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BFA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFA70u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi + 0x1BCu);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax = cpu->edi;
    lift_divide_accumulator(cpu, cpu->ebx, 32u, 0u);
    ++cpu->eax;
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->eax)) goto label_000BFAC7;
    lift_store32(cpu->esi + 0x1B8u, cpu->edx);
    goto label_000BFAD0;
    label_000BFAC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFAC7u);
    cpu->eax -= cpu->edi;
    ++cpu->eax;
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    label_000BFAD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFAD0u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000BFB2A;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, 0x17u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBFB2Au); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    label_000BFB2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFB2Au);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFB31u); lift_push32(cpu, r); sfera_sub_004BF130(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BFB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFB90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFB98u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::ListCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    lift_store16(cpu->esi + 0x1CCu, cpu->eax & 0xFFFFu);
    lift_store8(cpu->esi + 0x1CEu, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    lift_store8(cpu->esi + 0x1D4u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1BCu, 1u);
    lift_store32(cpu->esi + 0x1D8u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x1DCu, 3u);
    lift_store32(cpu->esi + 0x1E8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    lift_store8(cpu->esi + 0x1F0u, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    lift_store32(cpu->esi + 0x50u, 0xAu);
    lift_store32(cpu->esi + 0x1E0u, 0x32000000u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BFC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFC50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::ListCtrl*>(cpu->esi));
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D0u)) == (uint32_t)(cpu->edi)) goto label_000BFCB7;
    cpu->edx = (uint32_t)(cpu->edi + 0x66u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFC9Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BFCB1;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000BFCB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFCB1u);
    lift_store32(cpu->esi + 0x1D0u, cpu->edi);
    label_000BFCB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFCB7u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BFCE7;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x1ACu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFCD8u); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFCE4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BFCE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFCE7u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x1A0u, cpu->edi);
    lift_store32(cpu->esi + 0x1A4u, cpu->edi);
    lift_store32(cpu->esi + 0x1A8u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFD08u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BFD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFD20u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->edi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000BFE6E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi + 0x1B0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000BFD82;
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000BFD73;
    cpu->ecx += cpu->eax;
    label_000BFD73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFD73u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_000BFD7B;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->eax;
    label_000BFD7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFD7Bu);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->esi, 32u, 0u);
    label_000BFD82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFD82u);
    cpu->ebp = lift_load32(cpu->edi + 0x1A0u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000BFD93;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 8u));
    cpu->ebp = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 4u));
    label_000BFD93: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFD93u);
    cpu->ebx = lift_load32(cpu->edi + 0x1A4u);
    cpu->ebp += 0x24u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_000BFDC5;
    cpu->esi = (uint32_t)(cpu->ebp + 0xFFFFFFFCu);
    label_000BFDA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFDA3u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFE0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFDB0u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    lift_store32(cpu->esi, cpu->edx);
    cpu->ebp += 0x24u;
    cpu->esi += 0x24u;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_000BFDA3;
    label_000BFDC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFDC5u);
    cpu->ebx = lift_load32(cpu->edi + 0x1A4u);
    cpu->esi = (uint32_t)(cpu->ebx + 0xFFFFFFDCu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000BFDFC;
    cpu->ebp = 0xFu;
    label_000BFDD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFDD7u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000BFDE8;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFDE5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BFDE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFDE8u);
    lift_store32(cpu->esi + 0x14u, cpu->ebp);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi += 0x24u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000BFDD7;
    label_000BFDFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFDFCu);
    lift_store32(cpu->edi + 0x1A4u, (uint64_t)(lift_load32(cpu->edi + 0x1A4u)) + (uint64_t)(0xFFFFFFDCu) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->edi + 0x1B0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000BFE2B;
    lift_store32(cpu->edi + 0x1B4u, (uint64_t)(lift_load32(cpu->edi + 0x1B4u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B4u)) < (uint32_t)(cpu->eax)) goto label_000BFE2B;
    lift_store32(cpu->edi + 0x1B4u, 0u);
    label_000BFE2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFE2Bu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000BFE67;
    if ((uint32_t)(lift_load32(cpu->edi + 0x1D8u)) == (uint32_t)(cpu->edx)) goto label_000BFE67;
    cpu->eax = lift_load32(cpu->edi + 0xD8u);
    lift_store32(cpu->edi + 0x1D8u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 8u, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0xE16u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBFE67u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000BFE67: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFE67u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBFE6Eu); lift_push32(cpu, r); sfera_sub_004BFA70(cpu,r); if (cpu->eip != r) return; }
    label_000BFE6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFE6Eu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BFE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFE80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFE88u); lift_push32(cpu, r); sfera_sub_004BFC50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000BFE98;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFE95u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000BFE98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFE98u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004BFEA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFEA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x70u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->edi = 0u;
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000BFF1B;
    cpu->eax |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D8u)) == (uint32_t)(cpu->eax)) goto label_000BFF1B;
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    lift_store32(cpu->esp + 0x4Cu, 0xE16u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBFF1Bu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000BFF1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFF1Bu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x118u)) == (uint32_t)(cpu->edi)) goto label_000BFF6F;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edi)) goto label_000BFF6F;
    cpu->eax = lift_load8(cpu->esi + 0x8Du);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFF47u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x118u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000BFF5A;
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    cpu->ebp -= cpu->ecx;
    label_000BFF5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFF5Au);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000BFF6F;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->eax -= cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebp = cpu->eax;
    cpu->ebp = lift_shift_arithmetic(cpu, cpu->ebp, (uint32_t)(1u), 32u);
    label_000BFF6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFF6Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B0u)) != (uint32_t)(cpu->edi)) goto label_000BFFF5;
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store8(cpu->esp + 0x1Cu, 0u);
    lift_store32(cpu->esp + 0x68u, cpu->edi);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edi)) goto label_000BFF95;
    cpu->ebx = (uint32_t)(uintptr_t)" ";
    label_000BFF95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFF95u);
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000BFFA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFFA0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000BFFA0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFFB4u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x74u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x40u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFFD0u); lift_push32(cpu, r); sfera_sub_004A43D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x68u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C013A;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4BFFEDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000C013A;
    label_000BFFF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4BFFF5u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(lift_load32(cpu->esi + 0x1B0u))) goto label_000C00C6;
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store8(cpu->esp + 0x1Cu, 0u);
    lift_store32(cpu->esp + 0x68u, 1u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C0040;
    cpu->ebx = (uint32_t)(uintptr_t)" ";
    label_000C0040: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0040u);
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000C0045: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0045u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C0045;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0059u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1A0u);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_store32(cpu->esp + 0x40u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0075u); lift_push32(cpu, r); sfera_sub_004A43D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B4u, (uint64_t)(lift_load32(cpu->esi + 0x1B4u)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x1B0u))) goto label_000C0093;
    lift_store32(cpu->esi + 0x1B4u, 0u);
    label_000C0093: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0093u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x68u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C00AF;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C00ACu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C00AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C00AFu);
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    lift_store8(cpu->esp + 0x1Cu, 0u);
    goto label_000C013A;
    label_000C00C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C00C6u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C00CF;
    cpu->ebx = (uint32_t)(uintptr_t)" ";
    label_000C00CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C00CFu);
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000C00D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C00D4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C00D4;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C00F6u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0x1Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0x20u, cpu->ebp);
    lift_store32(cpu->esi + 0x1B4u, (uint64_t)(lift_load32(cpu->esi + 0x1B4u)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x1B0u))) goto label_000C013A;
    lift_store32(cpu->esi + 0x1B4u, cpu->edi);
    label_000C013A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C013Au);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0141u); lift_push32(cpu, r); sfera_sub_004BFA70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C0170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0170u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C01B4;
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0192u); lift_push32(cpu, r); sfera_sub_004A3DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1ACu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C01ADu); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    label_000C01B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C01B4u);
    lift_store32(cpu->esi + 0x1D8u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x1B4u, 0u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004BFA70(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C01E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C01E0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x1CDu)) == (uint8_t)(0u)) goto label_000C04A3;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C04A3;
    lift_push32(cpu, 0x3FFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4C020Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0210u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000C0220: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0220u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C0220;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax -= cpu->edx;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0]), cpu->ecx & 0xFFu);
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    goto label_000C0254;
    label_000C0243: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0243u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000C0250: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0250u);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    label_000C0254: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0254u);
    cpu->edx = lift_load8(cpu->ebp + 0x8Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C026Eu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->ebp + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C027C;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000C027C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C027Cu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx += cpu->ebx;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000C048C;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x20u, 0u);
    label_000C0297: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0297u);
    lift_push32(cpu, 0x3FFCu);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    g_sfera_ui_parse_scratch_runtime.token_buffer[0] = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4C02AFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C02B4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->esp += 0xCu;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C039F;
    label_000C02C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C02C1u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000C02CD;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Au)) goto label_000C02CD;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Bu)) goto label_000C02EC;
    label_000C02CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C02CDu);
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), cpu->eax & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x4000u)) goto label_000C0499;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000C02C1;
    goto label_000C039F;
    label_000C02EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C02ECu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C039F;
    label_000C02F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C02F6u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000C039F;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Au)) goto label_000C039F;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Bu)) goto label_000C039F;
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), cpu->eax & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x4000u)) goto label_000C0499;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), 0u);
    cpu->edx = lift_load8(cpu->ebp + 0x8Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0346u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->ebp + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C0354;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000C0354: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0354u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000C036B;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->eax)) goto label_000C036B;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000C0373;
    label_000C036B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C036Bu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000C02F6;
    goto label_000C039F;
    label_000C0373: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0373u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    ++cpu->esi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C038Bu); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, 1u);
    label_000C039F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C039Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C0250;
    cpu->edx = lift_load8(cpu->ebp + 0x8Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C03CEu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x8Cu)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)((cpu->eax & 0xFFu)) >= (uint8_t)(2u)) goto label_000C03E3;
    cpu->ecx -= 2u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_000C03E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C03E3u);
    cpu->edx = lift_load32(cpu->ebp + 0x28u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_000C03FC;
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->edi)) goto label_000C03FC;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000C0448;
    label_000C03FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C03FCu);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->ebx);
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->edx)) goto label_000C0462;
    if ((uint8_t)((cpu->eax & 0xFFu)) >= (uint8_t)(2u)) goto label_000C0413;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->eax = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    goto label_000C0415;
    label_000C0413: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0413u);
    cpu->eax = 0u;
    label_000C0415: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0415u);
    cpu->eax += cpu->ecx;
    cpu->ebx += cpu->eax;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C0297;
    lift_push32(cpu, 0x341u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C043Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0440u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    goto label_000C0297;
    label_000C0448: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0448u);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C045Cu); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    goto label_000C0243;
    label_000C0462: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0462u);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C047Eu); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store8(cpu->ecx, 0u);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    goto label_000C0243;
    label_000C048C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C048Cu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC0499u); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    label_000C0499: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0499u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
    label_000C04A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C04A3u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C04B0u); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C04C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C04C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x21Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C04F4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C04FEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C051C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0518u); lift_push32(cpu, r); sfera_sub_004BFB90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000C051E;
    label_000C051C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C051Cu);
    cpu->esi = 0u;
    label_000C051E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C051Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C052Eu); lift_push32(cpu, r); sfera_sub_004A44F0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000C0556;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0548u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC0556u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C0556: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0556u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1D0u)) == (uint32_t)(0u)) goto label_000C057A;
    cpu->ecx = lift_load32(cpu->edi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C056Cu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC057Au); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C057A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C057Au);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C0590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0590u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C08B6;
    lift_push32(cpu, 0x3FFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.auxiliary_text[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4C05ADu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C05B3u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.auxiliary_text[0];
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(g_sfera_ui_parse_scratch_runtime.auxiliary_text[0]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->eax = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C08A9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000C05D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C05D1u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0xAu)) goto label_000C0898;
    lift_store8(cpu->ecx, 0u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x1CDu)) == (uint8_t)(0u)) goto label_000C0884;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0884;
    lift_push32(cpu, 0x3FFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4C05FDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0603u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000C0610: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0610u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000C0610;
    cpu->eax -= cpu->edx;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0];
    cpu->ebx = 0u;
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.input_text[0]), cpu->ecx & 0xFFu);
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    goto label_000C0644;
    label_000C0630: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0630u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000C0640: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0640u);
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    label_000C0644: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0644u);
    cpu->edx = lift_load8(cpu->ebp + 0x8Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C065Eu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->ebp + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C066C;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000C066C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C066Cu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx += cpu->ebx;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000C087C;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x20u, 0u);
    label_000C0687: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0687u);
    lift_push32(cpu, 0x3FFCu);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    g_sfera_ui_parse_scratch_runtime.token_buffer[0] = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4C069Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C06A4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->esp += 0xCu;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C078F;
    label_000C06B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C06B1u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000C06BD;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Au)) goto label_000C06BD;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Bu)) goto label_000C06DC;
    label_000C06BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C06BDu);
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), cpu->eax & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x4000u)) goto label_000C0891;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000C06B1;
    goto label_000C078F;
    label_000C06DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C06DCu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C078F;
    label_000C06E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C06E6u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000C078F;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Au)) goto label_000C078F;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Bu)) goto label_000C078F;
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), cpu->eax & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x4000u)) goto label_000C0891;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), 0u);
    cpu->edx = lift_load8(cpu->ebp + 0x8Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0736u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->ebp + 0x8Cu)) >= (uint8_t)(2u)) goto label_000C0744;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) - (uint64_t)(2u) - (uint64_t)(0u));
    label_000C0744: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0744u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000C075B;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->eax)) goto label_000C075B;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000C0763;
    label_000C075B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C075Bu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000C06E6;
    goto label_000C078F;
    label_000C0763: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0763u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    ++cpu->esi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C077Bu); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, 1u);
    label_000C078F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C078Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]), 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C0640;
    cpu->edx = lift_load8(cpu->ebp + 0x8Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C07BEu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x8Cu)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)((cpu->eax & 0xFFu)) >= (uint8_t)(2u)) goto label_000C07D3;
    cpu->ecx -= 2u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_000C07D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C07D3u);
    cpu->edx = lift_load32(cpu->ebp + 0x28u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_000C07EC;
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->edi)) goto label_000C07EC;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000C0838;
    label_000C07EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C07ECu);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->ebx);
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->edx)) goto label_000C0852;
    if ((uint8_t)((cpu->eax & 0xFFu)) >= (uint8_t)(2u)) goto label_000C0803;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->eax = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    goto label_000C0805;
    label_000C0803: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0803u);
    cpu->eax = 0u;
    label_000C0805: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0805u);
    cpu->eax += cpu->ecx;
    cpu->ebx += cpu->eax;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C0687;
    lift_push32(cpu, 0x341u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C082Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0830u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    goto label_000C0687;
    label_000C0838: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0838u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C084Cu); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    goto label_000C0630;
    label_000C0852: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0852u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C086Eu); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store8(cpu->ecx, 0u);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    goto label_000C0630;
    label_000C087C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C087Cu);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    goto label_000C088A;
    label_000C0884: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0884u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    label_000C088A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C088Au);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC0891u); lift_push32(cpu, r); sfera_sub_004BFEA0(cpu,r); if (cpu->eip != r) return; }
    label_000C0891: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0891u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = (uint32_t)(cpu->ecx + 1u);
    label_000C0898: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0898u);
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C05D1;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C08A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C08A9u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC08B6u); lift_push32(cpu, r); sfera_sub_004C01E0(cpu,r); if (cpu->eip != r) return; }
    label_000C08B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C08B6u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C08C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C08C0u);
    cpu->esp -= 0x20u;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x38u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xE11u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000C0A13;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C099F;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x66u)) goto label_000C0979;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x76u)) goto label_000C0D1C;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000C0959;
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x17u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C0960;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0940u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0959: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0959u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC0960u); lift_push32(cpu, r); sfera_sub_004BFA70(cpu,r); if (cpu->eip != r) return; }
    label_000C0960: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0960u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0979: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0979u);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0986u); lift_push32(cpu, r); sfera_sub_004BF130(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C099F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C099Fu);
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx += 5u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1B8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C09BAu); lift_push32(cpu, r); sfera_sub_004C0590(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esi + 0x1CCu)) == (uint8_t)(0u)) goto label_000C09FA;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000C09FA;
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    cpu->eax = lift_load32(cpu->esi + 0x1B8u);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C09F3;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC09F3u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    label_000C09F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C09F3u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC09FAu); lift_push32(cpu, r); sfera_sub_004BF130(cpu,r); if (cpu->eip != r) return; }
    label_000C09FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C09FAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0A13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0A13u);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFF1EEu);
    if ((uint32_t)(cpu->edx) > (uint32_t)(0xEu)) goto label_000C0D1C;
    switch ((uint32_t)(cpu->edx)) {
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
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0A4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0A4Au);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000C0A9F;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000C0A74;
    cpu->edi = (uint32_t)(uintptr_t)" ";
    label_000C0A74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0A74u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0A86u); lift_push32(cpu, r); sfera_sub_0049D560(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0A9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0A9Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0AB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0AB5u);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000C0A9F;
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0x1Cu, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0AFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0AFCu);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x1CDu, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0B20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0B20u);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000C0B63;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0B4Au); lift_push32(cpu, r); sfera_sub_004BF9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0B63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0B63u);
    cpu->edx = lift_load32(cpu->esi + 0x1D8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0B84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0B84u);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += cpu->edx;
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0BBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0BBCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0BC4u); lift_push32(cpu, r); sfera_sub_004BEEB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0BDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0BDDu);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C0A9F;
    cpu->ebx = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C0C10;
    cpu->edx = cpu->edi;
    goto label_000C0C2B;
    label_000C0C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C10u);
    cpu->edx = lift_load32(cpu->esi + 0x1B4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C0C1C;
    cpu->edx += cpu->eax;
    label_000C0C1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C1Cu);
    if ((uint32_t)(cpu->edx) < (uint32_t)(cpu->eax)) goto label_000C0C24;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    label_000C0C24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C24u);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ebx, 32u, 0u);
    label_000C0C2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C2Bu);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 8u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C0C40;
    cpu->eax = lift_load32(cpu->eax);
    label_000C0C40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C40u);
    cpu->ecx -= cpu->eax;
    label_000C0C42: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C42u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C0C42;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0C65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C65u);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C0A9F;
    cpu->ebx = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C0C98;
    cpu->edx = cpu->edi;
    goto label_000C0CB3;
    label_000C0C98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0C98u);
    cpu->edx = lift_load32(cpu->esi + 0x1B4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000C0CA4;
    cpu->edx += cpu->eax;
    label_000C0CA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0CA4u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(cpu->eax)) goto label_000C0CAC;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    label_000C0CAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0CACu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ebx, 32u, 0u);
    label_000C0CB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0CB3u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 8u));
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x1Cu);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0CDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0CDBu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0CE2u); lift_push32(cpu, r); sfera_sub_004C0170(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0CFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0CFBu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0D03u); lift_push32(cpu, r); sfera_sub_004BFD20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000C0D1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0D1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0D26u); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C0D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0D80u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0D99u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + 0x1BCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->edi + 0x8Cu);
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)" ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0DB8u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x9Cu)) != (uint32_t)(0u)) goto label_000C0DDB;
    lift_push32(cpu, 0x79u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0DD2u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0DD8u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C0DDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0DDBu);
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"scrollbar");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0DF3u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0E1B;
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E0Du); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->edi + 0x1D0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC0E1Bu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C0E1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0E1Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"formatStrings");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E28u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0E40;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E35u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->edi + 0x1CDu, cpu->edx & 0xFFu);
    label_000C0E40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0E40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"useContinueMark");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E4Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0E65;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E5Au); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->edi + 0x1CEu, cpu->eax & 0xFFu);
    label_000C0E65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0E65u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canSelect");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E72u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0E8A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E7Fu); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->edi + 0x1D4u, cpu->ecx & 0xFFu);
    label_000C0E8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0E8Au);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"selectionBorder");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0E97u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0EAA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0EA4u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1DCu, cpu->eax);
    label_000C0EAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0EAAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"selectionColor");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0EB7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0F29;
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C0ED8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0EDEu);
    cpu->esp += 0x18u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C0F01;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'selectionColor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0EF8u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0EFEu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000C0F01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0F01u);
    cpu->eax = lift_load8(cpu->esp + 0x34u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = lift_load8(cpu->esp + 0x10u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load8(cpu->esp + 0x14u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store32(cpu->edi + 0x1E0u, cpu->eax);
    label_000C0F29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0F29u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"selectionLineColor");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0F36u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0FA8;
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C0F57u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0F5Du);
    cpu->esp += 0x18u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C0F80;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'selectionLineColor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0F77u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0F7Du); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000C0F80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0F80u);
    cpu->eax = lift_load8(cpu->esp + 0x34u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = lift_load8(cpu->esp + 0x14u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store32(cpu->edi + 0x1E4u, cpu->eax);
    label_000C0FA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0FA8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"chatlike");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0FB5u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0FD7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0FC2u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->edi + 0x1CCu, cpu->edx & 0xFFu);
    lift_store32(cpu->edi + 0x1B0u, 0x40u);
    label_000C0FD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0FD7u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"maxItems");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0FE4u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C0FF7;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0FF1u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1B0u, cpu->eax);
    label_000C0FF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C0FF7u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C0FFFu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"addstring");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C100Bu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1088;
    cpu->ebp = (uint32_t)(cpu->esi + 0x10u);
    label_000C1012: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1012u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0]); lift_push32(cpu, (uintptr_t)"%s %x"); lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x44u, 0u);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C102Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1030u);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_000C1059;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_parse_scratch_runtime.token_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1042u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000C104A;
    cpu->eax = lift_load32(cpu->eax);
    label_000C104A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C104Au);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1057u); lift_push32(cpu, r); sfera_sub_004C0590(cpu,r); if (cpu->eip != r) return; }
    goto label_000C1078;
    label_000C1059: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1059u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'addstring'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C106Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1075u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000C1078: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1078u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"addstring");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1084u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C1012;
    label_000C1088: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1088u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C108Fu); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1096u); lift_push32(cpu, r); sfera_sub_004BFA70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C10A2u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C10C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C10C0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000C10F0;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC10F0u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C10F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C10F0u);
    cpu->eax = lift_load32(cpu->edi + 0x34u);
    cpu->ecx = lift_load32(cpu->edi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 8u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x200u, cpu->ecx);
    lift_store32(cpu->esi + 0x204u, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1110u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C111Bu); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    cpu->edx = lift_load32(cpu->esi + 0x200u);
    cpu->ebx = lift_load32(cpu->ecx + 0x2Cu);
    cpu->ebp = (uint32_t)(cpu->eax + cpu->edx);
    lift_store32(cpu->esi + 0x208u, cpu->eax);
    lift_store32(cpu->esi + 0x20Cu, cpu->ebx);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_width)) goto label_000C1148;
    cpu->edi -= cpu->eax;
    label_000C1148: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1148u);
    if ((int32_t)(uint32_t)(cpu->edx) < 0) goto label_000C1150;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000C1152;
    label_000C1150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1150u);
    cpu->edi = 0u;
    label_000C1152: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1152u);
    cpu->esi = lift_load32(cpu->esi + 0x204u);
    cpu->ebp = (uint32_t)(cpu->esi + cpu->ebx);
    cpu->eax = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_height)) goto label_000C1167;
    cpu->eax -= cpu->ebx;
    label_000C1167: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1167u);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000C116F;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000C1171;
    label_000C116F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C116Fu);
    cpu->eax = 0u;
    label_000C1171: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1171u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->edx)) goto label_000C1179;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000C1184;
    label_000C1179: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1179u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000C1184: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1184u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1190u);
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C11C5u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C11E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C11E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000C11EB;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C11EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C11EBu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"RIGHT_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC11FAu), LIFT_CODE_TOKEN_RVA(0xC11F8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C11FAu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C1209;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C1209: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1209u);
    lift_push32(cpu, (uintptr_t)"RIGHT_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC1211u), LIFT_CODE_TOKEN_RVA(0xC120Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1211u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C1220;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 2u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C1220: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1220u);
    lift_push32(cpu, (uintptr_t)"CENTER_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC1228u), LIFT_CODE_TOKEN_RVA(0xC1226u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1228u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C1237;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C1237: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1237u);
    lift_push32(cpu, (uintptr_t)"CENTER_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC123Fu), LIFT_CODE_TOKEN_RVA(0xC123Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C123Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C124E;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 8u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C124E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C124Eu);
    lift_push32(cpu, (uintptr_t)"CENTER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC1256u), LIFT_CODE_TOKEN_RVA(0xC1254u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1256u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C1265;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0xCu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000C1265: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1265u);
    lift_push32(cpu, (uintptr_t)"RIGHT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xC126Du), LIFT_CODE_TOKEN_RVA(0xC126Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C126Du);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFDu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 3u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1280u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1288u); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x200u);
    cpu->eax += lift_load32(cpu->esi + 0x30u);
    cpu->edx = lift_load32(cpu->esi + 0x1C0u);
    cpu->ecx = lift_load32(cpu->esi + 0x204u);
    cpu->ecx += lift_load32(cpu->esi + 0x34u);
    cpu->edx += cpu->eax;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx += cpu->ecx;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx -= lift_load32(cpu->esi + 0x1C8u);
    cpu->edx += cpu->eax;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax -= lift_load32(cpu->esi + 0x1CCu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax += cpu->ecx;
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C12E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C12E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C12E8u); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1F4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 8u));
    cpu->eax += lift_load32(cpu->esi + 0x204u);
    cpu->ecx = lift_load32(cpu->esi + 0x200u);
    cpu->ecx += lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esi + 0x1ECu);
    cpu->edx = lift_load32(cpu->esi + 0x1D4u);
    cpu->eax += lift_load32(cpu->esi + 0x34u);
    cpu->edx += cpu->ecx;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx += cpu->eax;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx -= lift_load32(cpu->esi + 0x1DCu);
    cpu->edx += cpu->ecx;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x1F4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1CCu);
    cpu->esi = lift_pop32(cpu);
    cpu->ecx += cpu->eax;
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1350u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C135Bu); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x214u);
    cpu->ecx -= lift_load32(cpu->esi + 0x210u);
    cpu->eax = lift_load32(cpu->esi + 0x200u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x30u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x1F4u));
    cpu->ecx += lift_load32(cpu->esi + 0x204u);
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->ecx += lift_load32(cpu->esi + 0x1ECu);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx += lift_load32(cpu->esi + 0x34u);
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C13CEu); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C13E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C13E0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x210u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x214u))) goto label_000C1457;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C13F9u); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x214u);
    cpu->edi -= lift_load32(cpu->esi + 0x210u);
    cpu->ebp = lift_load32(cpu->esi + 0x1F4u);
    cpu->ecx = lift_load32(cpu->esi + 0x204u);
    cpu->ecx += lift_load32(cpu->esi + 0x1ECu);
    cpu->eax = lift_load32(cpu->esi + 0x200u);
    cpu->eax += lift_load32(cpu->esi + 0x30u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x34u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebx = lift_load32(cpu->esi + 0x28u);
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(5u), 32u);
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebx += cpu->eax;
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_000C1457;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000C1457;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000C1457;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C1457;
    cpu->eax -= cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ebp, 32u, 1u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000C1457;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_000C145D;
    label_000C1457: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1457u);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    label_000C145D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C145Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1470u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esi + 0x224u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1493u); lift_push32(cpu, r); sfera_sub_004D8990(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C149Au); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->esi + 0x200u);
    cpu->ecx += lift_load32(cpu->esi + 0x30u);
    cpu->edx = lift_load32(cpu->esi + 0x204u);
    cpu->edx += lift_load32(cpu->esi + 0x34u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->esp + 8u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C14F8u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1510u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    cpu->esi -= lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->edx + 4u);
    cpu->edi -= lift_load32(cpu->eax + 0xCu);
    cpu->esi -= lift_load32(cpu->eax);
    cpu->edi -= lift_load32(cpu->eax + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 0x8Cu)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(2u) - (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax & 0xFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1549u); lift_push32(cpu, r); sfera_sub_004A5270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_000C1571;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->esi)) goto label_000C1571;
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->ebx;
    lift_store32(cpu->eax, cpu->edx);
    label_000C1571: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1571u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_000C1587;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->edi)) goto label_000C1587;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edi;
    cpu->ebp -= cpu->edx;
    lift_store32(cpu->eax + 4u, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    label_000C1587: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1587u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (4u)) == 0u) goto label_000C1596;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->esi)) goto label_000C1596;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    lift_store32(cpu->eax, cpu->esi);
    label_000C1596: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1596u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (8u)) == 0u) goto label_000C15A6;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->edi)) goto label_000C15A6;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(1u), 32u);
    lift_store32(cpu->eax + 4u, cpu->edi);
    label_000C15A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C15A6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C15B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C15B0u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C1603;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x7FFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000C15D5;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C15CEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C1603;
    label_000C15D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C15D5u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC1603u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000C1603: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1603u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1610u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C161Cu); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000C1654;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000C1654;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1649u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C164Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->eax = cpu->esi;
    label_000C1654: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1654u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1660u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1676u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1684u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C1790;
    cpu->eax = lift_load32(cpu->esi + 0x214u);
    cpu->eax -= lift_load32(cpu->esi + 0x210u);
    if ((uint32_t)((cpu->eax) & (0xFFFFFFE0u)) == 0u) goto label_000C1790;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C16B9u); lift_push32(cpu, r); sfera_sub_004C13E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x220u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x214u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C172B;
    cpu->edi = lift_load32(cpu->esi + 0x210u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    if ((uint8_t)(lift_load8(cpu->edx + cpu->edi + 0x1Cu)) == (uint8_t)(0u)) goto label_000C172B;
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    if ((uint8_t)((lift_load8(cpu->edx + 0xCu)) & (1u)) == 0u) goto label_000C172B;
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, 0x1BBCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C171Cu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1723u); lift_push32(cpu, r); sfera_sub_004C1190(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    label_000C172B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C172Bu);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000C1754;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC1754u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000C1754: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1754u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->ebx)) goto label_000C177C;
    cpu->edx = lift_load32(cpu->edi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000C177C;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000C177C;
    cpu->eax = lift_load32(cpu->edi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->eax)) goto label_000C178D;
    label_000C177C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C177Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    if ((uint8_t)((lift_load8(cpu->ecx + 0xCu)) & (3u)) == 0u) goto label_000C178D;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC178Du); lift_push32(cpu, r); sfera_sub_004C1190(cpu,r); if (cpu->eip != r) return; }
    label_000C178D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C178Du);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000C1790: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1790u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C17B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C17B0u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C17BDu); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esi + 0x204u);
    cpu->ebp += lift_load32(cpu->esi + 0x34u);
    cpu->ebx = lift_load32(cpu->esi + 0x200u);
    cpu->ebx += lift_load32(cpu->esi + 0x30u);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1814u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esi + 0x1BCu)) == (uint8_t)(0u)) goto label_000C18CD;
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) == (uint32_t)(0u)) goto label_000C18CD;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C1839;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000C183B;
    label_000C1839: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1839u);
    cpu->eax = cpu->edi;
    label_000C183B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C183Bu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C0u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1861u); lift_push32(cpu, r); sfera_sub_004C1510(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1868u); lift_push32(cpu, r); sfera_sub_004C1280(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C1870;
    cpu->edi = lift_load32(cpu->edi);
    label_000C1870: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1870u);
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x8Cu)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->ecx;
    cpu->ecx = cpu->eax & 0xFFu;
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->eax += lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 0u);
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax += lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 8u;
    cpu->eax += cpu->ebx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C18CCu); lift_push32(cpu, r); sfera_sub_004A4E10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_000C18CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C18CDu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C18E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C18E0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x214u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->eax)) goto label_000C1A2F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1909u); lift_push32(cpu, r); sfera_sub_004C10C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x1F4u);
    cpu->ebp = lift_load32(cpu->esi + 0x200u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edi += lift_load32(cpu->esi + 0x204u);
    cpu->ebp += lift_load32(cpu->esi + 0x30u);
    cpu->edi += lift_load32(cpu->esi + 0x1ECu);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->edi += lift_load32(cpu->esi + 0x34u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1967u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x210u);
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + cpu->ecx + 0x10u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ebx + cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C1A2D;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000C1986;
    cpu->eax = lift_load32(cpu->eax);
    label_000C1986: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1986u);
    cpu->edx = lift_load32(cpu->esi + 0x1E4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1D4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1F0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C19ACu); lift_push32(cpu, r); sfera_sub_004C1510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C19B8u); lift_push32(cpu, r); sfera_sub_004C12E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx += lift_load32(cpu->esi + 0x210u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x1Cu)) != (uint8_t)(0u)) goto label_000C19CE;
    cpu->edx = lift_load32(cpu->esi + 0x1B8u);
    label_000C19CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C19CEu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000C19D6;
    cpu->ebx = lift_load32(cpu->ebx);
    label_000C19D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C19D6u);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x8Cu)) & 0xFFu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x1D8u);
    cpu->eax += lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_push32(cpu, 0u);
    cpu->eax += cpu->ebp;
    cpu->eax += lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)(2u) - (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC1A2Du); lift_push32(cpu, r); sfera_sub_004A4E10(cpu,r); if (cpu->eip != r) return; }
    label_000C1A2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1A2Du);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000C1A2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1A2Fu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1A40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C1ADC;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000C1ADC;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1A5Du); lift_push32(cpu, r); sfera_sub_004C1110(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1A64u); lift_push32(cpu, r); sfera_sub_004C1470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1A6Bu); lift_push32(cpu, r); sfera_sub_004C17B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x214u);
    cpu->eax -= lift_load32(cpu->esi + 0x210u);
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1AC2;
    label_000C1A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1A80u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0x220u))) goto label_000C1A98;
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    goto label_000C1AA6;
    label_000C1A98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1A98u);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    label_000C1AA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1AA6u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1AAEu); lift_push32(cpu, r); sfera_sub_004C18E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x214u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->edx)) goto label_000C1A80;
    label_000C1AC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1AC2u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1AC9u); lift_push32(cpu, r); sfera_sub_004C1350(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi += 0x224u;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1ADBu); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_000C1ADC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1ADCu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1AE0u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000C1AFD;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C1AFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1AFDu);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0x7FFFFFFu)) goto label_000C1B10;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xC1B10u);
    label_000C1B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1B10u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1B19u); lift_push32(cpu, r); sfera_sub_004C15B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    cpu->edi += cpu->eax;
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C1B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1B30u);
    cpu->esp -= 0x120u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x9Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x13Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C1B86;
    lift_push32(cpu, 0x16u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\MenuListControl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1B7Du); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1B83u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C1B86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1B86u);
    cpu->eax = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0xF4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1B9Eu); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"topSprite");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1BABu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1C0B;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1BBDu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1C0B;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1BCDu); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C1BFF;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1BF6u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1BFCu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C1BFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1BFFu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    goto label_000C1C3F;
    label_000C1C0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1C0Bu);
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"topSprite"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1C36u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1C3Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C1C3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1C3Fu);
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esi + 0x1E8u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"middleSprite");
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1C64u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1CC4;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1C76u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1CC4;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1C86u); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C1CB8;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1CAFu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1CB5u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C1CB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1CB8u);
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    goto label_000C1CF8;
    label_000C1CC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1CC4u);
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"middleSprite"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1CEFu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1CF5u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C1CF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1CF8u);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esi + 0x1F0u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"middleHoveredSprite");
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1F4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1D1Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1D4E;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1D2Fu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1D4E;
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1D46u); lift_push32(cpu, r); sfera_sub_004C1610(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    goto label_000C1D5A;
    label_000C1D4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1D4Eu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_store32(cpu->esi + 0x1A4u, cpu->ecx);
    label_000C1D5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1D5Au);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"bottomSprite");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1D67u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1DC7;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1D79u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1DC7;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1D89u); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C1DBB;
    cpu->eax = (uintptr_t)g_sfera_menu_sprite_not_found_message;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::GetSprite"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1DB2u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1DB8u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000C1DBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1DBBu);
    lift_store32(cpu->esi + 0x1A8u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    goto label_000C1DFB;
    label_000C1DC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1DC7u);
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"bottomSprite"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1DF2u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1DF8u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C1DFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1DFBu);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1ECu);
    lift_store32(cpu->esi + 0x1F8u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    lift_push32(cpu, (uint32_t)(uintptr_t)"normalColor");
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1FCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1E2Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1EAE;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C1E47u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1E4Du);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000C1E89;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"normalColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1E80u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1E86u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C1E89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1E89u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    cpu->edx = lift_load8(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->edx;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    goto label_000C1EE2;
    label_000C1EAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1EAEu);
    cpu->eax = (uintptr_t)g_sfera_menu_list_missing_parameter_message;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"normalColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1ED9u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1EDFu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C1EE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1EE2u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"disabledColor");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1EEFu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C1F6C;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C1F0Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1F11u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000C1F4D;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"disabledColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1F44u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1F4Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C1F4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1F4Du);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    cpu->edx = lift_load8(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->edx;
    goto label_000C1F72;
    label_000C1F6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1F6Cu);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    label_000C1F72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1F72u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"hoveredColor");
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1F85u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C2003;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C1FA1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1FA7u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000C1FE3;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"hoveredColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1FDAu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C1FE0u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C1FE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C1FE3u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load8(cpu->esp + 0x10u);
    cpu->ecx = lift_load8(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    goto label_000C2009;
    label_000C2003: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2003u);
    cpu->edx = lift_load32(cpu->esi + 0x1B0u);
    label_000C2009: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2009u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"listItemTextMargin");
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1B4u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C201Cu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C20F1;
    cpu->eax = (uint32_t)(cpu->esi + 0x1E0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1DCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1D8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1D4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C2049u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C204Fu);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(4u)) goto label_000C208B;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"listItemTextMargin"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2082u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2088u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C208B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C208Bu);
    cpu->ebx = 0u;
    label_000C208D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C208Du);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"listItemTextFormat");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C209Au); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C210D;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C20ABu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C210D;
    cpu->ebx = 0u;
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1E4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C20BEu); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C2113;
    label_000C20C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C20C6u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C20D3u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C20E6;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C20E0u); lift_push32(cpu, r); sfera_sub_004C11E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1E4u, (uint64_t)(lift_load32(cpu->esi + 0x1E4u)) | (uint64_t)(cpu->eax));
    label_000C20E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C20E6u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_000C20C6;
    goto label_000C2113;
    label_000C20F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C20F1u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x1D4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1D8u, cpu->ebx);
    lift_store32(cpu->esi + 0x1DCu, cpu->ebx);
    lift_store32(cpu->esi + 0x1E0u, cpu->ebx);
    goto label_000C208D;
    label_000C210D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C210Du);
    lift_store32(cpu->esi + 0x1E4u, cpu->ebx);
    label_000C2113: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2113u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"needShowTitle");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2120u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_store8(cpu->esi + 0x1BCu, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C22E0;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"titleColor");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2141u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C21C2;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C215Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2163u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000C21A3;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"titleColor"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C219Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C21A0u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C21A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C21A3u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    cpu->edx = lift_load8(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->edx;
    goto label_000C21C8;
    label_000C21C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C21C2u);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    label_000C21C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C21C8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"titleTextMargin");
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C21DBu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C22BB;
    cpu->ecx = (uint32_t)(cpu->esi + 0x1CCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1C4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C2208u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C220Eu);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(4u)) goto label_000C224E;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"titleTextMargin"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2245u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C224Bu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000C224E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C224Eu);
    cpu->ebx = 0u;
    label_000C2250: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2250u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"titleTextFormat");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C225Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C22DA;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C226Eu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C22DA;
    cpu->ebx = 0u;
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x1D0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2281u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000C22E0;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000C2290: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2290u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C229Du); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C22B0;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C22AAu); lift_push32(cpu, r); sfera_sub_004C11E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1D0u, (uint64_t)(lift_load32(cpu->esi + 0x1D0u)) | (uint64_t)(cpu->eax));
    label_000C22B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C22B0u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_000C2290;
    goto label_000C22E0;
    label_000C22BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C22BBu);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    lift_store32(cpu->esi + 0x1CCu, cpu->ebx);
    goto label_000C2250;
    label_000C22DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C22DAu);
    lift_store32(cpu->esi + 0x1D0u, cpu->ebx);
    label_000C22E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C22E0u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"maxItems");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C22EDu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C2351;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4C22FFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2305u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x198u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000C235B;
    cpu->eax = (uintptr_t)g_sfera_menu_not_enough_arguments_message;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"maxItems"); lift_push32(cpu, (uintptr_t)"SphereUI::CMenuListControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2346u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C234Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    goto label_000C235B;
    label_000C2351: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2351u);
    lift_store32(cpu->esi + 0x198u, 1u);
    label_000C235B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C235Bu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x8Cu)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esi + 0x220u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C2377;
    lift_store8(cpu->esi + 0x8Cu, 2u);
    label_000C2377: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2377u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2383u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x120u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C23B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C23B0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000C23E4;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    (void)cpu;
    label_000C23C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C23C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C23CCu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->edi + 0x1Cu, cpu->eax & 0xFFu);
    cpu->esi += 0x20u;
    cpu->edi += 0x20u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000C23C0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000C23E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C23E4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C23F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C23F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edx);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    label_000C2430: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2430u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFECu))) goto label_000C2499;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000C245D;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2457u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->esi + 0x1Cu, cpu->eax & 0xFFu);
    label_000C245D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C245Du);
    cpu->esi += 0x20u;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    cpu->edi += 0x20u;
    goto label_000C2430;
    label_000C2499: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2499u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C246B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C246Bu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000C2490;
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    label_000C2480: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2480u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2489u); lift_push32(cpu, r); sfera_sub_004A3E00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x20u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000C2480;
    label_000C2490: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2490u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2499u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C24B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C24B0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000C24E9;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000C24C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C24C0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000C24D1;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C24CEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C24D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C24D1u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi += 0x20u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000C24C0;
    label_000C24E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C24E9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C24F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C24F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edx);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    label_000C2530: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2530u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFECu))) goto label_000C2599;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000C255D;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2557u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->esi + 0x1Cu, cpu->eax & 0xFFu);
    label_000C255D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C255Du);
    cpu->esi += 0x20u;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    cpu->edi += 0x20u;
    goto label_000C2530;
    label_000C2599: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2599u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C256B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C256Bu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000C2590;
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    label_000C2580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2580u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2589u); lift_push32(cpu, r); sfera_sub_004A3E00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x20u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000C2580;
    label_000C2590: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2590u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2599u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C25B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C25B0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C25C6u); lift_push32(cpu, r); sfera_sub_004C24B0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2695(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2695u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C269Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C26AAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4C26AAu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C26B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C26B0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C26CBu); lift_push32(cpu, r); sfera_sub_004C24F0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2710(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000C2710;
    label_000C25D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C25D0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x7FFFFFFu)) goto label_000C2612;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xC2612u);
    label_000C2612: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2612u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000C2681;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2629u); lift_push32(cpu, r); sfera_sub_004C15B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2647u); lift_push32(cpu, r); sfera_sub_004C23F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = cpu->edx;
    cpu->edi -= cpu->ecx;
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C266C;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2661u); lift_push32(cpu, r); sfera_sub_004C24B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2669u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(4u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000C266C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C266Cu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += cpu->ebx;
    cpu->edi &= 0xFFFFFFE0u;
    cpu->edi += cpu->ebx;
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_store32(cpu->esi, cpu->ebx);
    label_000C2681: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2681u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C2710: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2710u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = 0x7FFFFFFu;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C2736;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xC2736u);
    label_000C2736: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2736u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000C276A;
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->edi = 0x7FFFFFFu;
    cpu->edi -= cpu->esi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_000C2757;
    cpu->edx = 0u;
    goto label_000C2759;
    label_000C2757: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2757u);
    cpu->edx += cpu->esi;
    label_000C2759: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2759u);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000C275F;
    cpu->edx = cpu->eax;
    label_000C275F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C275Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    goto label_000C25D0;
    label_000C276A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C276Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2770u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2778u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store8(cpu->esi + 0x1BCu, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::CMenuListControl*>(cpu->esi));
    cpu->ecx = 1u;
    lift_store32(cpu->esi + 0x198u, cpu->ecx);
    lift_store32(cpu->esi + 0x210u, cpu->eax);
    lift_store32(cpu->esi + 0x214u, cpu->eax);
    lift_store32(cpu->esi + 0x218u, cpu->eax);
    lift_store32(cpu->esi + 0x220u, cpu->ecx);
    lift_store32(cpu->esi + 0x50u, 0x15u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C27C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C27C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::CMenuListControl*>(cpu->esi));
    cpu->ecx = lift_load32(cpu->esi + 0x210u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000C27FA;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x21Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x214u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C27EBu); lift_push32(cpu, r); sfera_sub_004C24B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x210u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C27F7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C27FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C27FAu);
    lift_store32(cpu->esi + 0x210u, 0u);
    lift_store32(cpu->esi + 0x214u, 0u);
    lift_store32(cpu->esi + 0x218u, 0u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004D37D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2830u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C28B2;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_000C28B2;
    cpu->edi -= cpu->ecx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000C2877;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC2877u); lift_push32(cpu, r); sfera_sub_004C2710(cpu,r); if (cpu->eip != r) return; }
    label_000C2877: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2877u);
    cpu->edi &= 0xFFFFFFE0u;
    cpu->edi += lift_load32(cpu->esi);
    cpu->ebx = cpu->edi;
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000C28F6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->edi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C28AAu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->edi + 0x1Cu, cpu->eax & 0xFFu);
    goto label_000C28F6;
    label_000C28B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C28B2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000C28C0;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC28C0u); lift_push32(cpu, r); sfera_sub_004C2710(cpu,r); if (cpu->eip != r) return; }
    label_000C28C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C28C0u);
    cpu->ebx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_000C28F6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + 0x14u, 0xFu);
    lift_store32(cpu->ebx + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    lift_store8(cpu->ebx, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C28F0u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->ebx + 0x1Cu, cpu->ecx & 0xFFu);
    label_000C28F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C28F6u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(0x20u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2910u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = lift_load32(cpu->esp + 0x48u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 0x214u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = (uint32_t)(cpu->eax + 0x210u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(lift_load32(cpu->eax + 0x198u))) goto label_000C29FB;
    cpu->ecx = lift_load32(cpu->eax + 0x9Cu);
    cpu->esi = lift_load32(cpu->ecx + 0x2Cu);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    cpu->edi = lift_load32(cpu->eax + 0x1F4u);
    lift_store32(cpu->eax + 0x2Cu, (uint64_t)(lift_load32(cpu->eax + 0x2Cu)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    lift_store32(cpu->eax + 0x208u, cpu->edx);
    lift_store32(cpu->eax + 0x20Cu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->edi + cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C299Bu);
    cpu->eax = cpu->ebp;
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, 0u);
    lift_store8(cpu->esp + 0x14u, 0u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    label_000C29B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C29B5u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C29B5;
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C29C9u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x4Cu)) & 0xFFu);
    lift_store8(cpu->esp + 0x30u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x44u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C29E7u); lift_push32(cpu, r); sfera_sub_004C2830(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(0x10u)) goto label_000C29FB;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C29F8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C29FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C29FBu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2A20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2A28u); lift_push32(cpu, r); sfera_sub_004C27C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C2A38;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2A35u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C2A38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2A38u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2A40u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    cpu->edi = lift_load32(cpu->esp + 0x64u);
    cpu->eax = (uint32_t)(cpu->edx + 0xFFFFE443u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_000C2C4D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000C2A95;
        case 1u: goto label_000C2B2D;
        case 2u: goto label_000C2B48;
        case 3u: goto label_000C2BA5;
        case 4u: goto label_000C2BD4;
        default: lift_trap(cpu, 0x4C2A8Eu, "resolved jump-table index out of range"); return;
    }
label_000C2A95: ;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    cpu->eax = lift_load32(cpu->ecx + 0x2Cu);
    lift_store32(cpu->esi + 0x208u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1FCu);
    cpu->edx += lift_load32(cpu->esi + 0x1ECu);
    lift_store32(cpu->esi + 0x20Cu, cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 0x214u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(5u), 32u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x1F4u));
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x208u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x7Au);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2AE5u);
    cpu->ecx = lift_load32(cpu->esi + 0x214u);
    cpu->eax = lift_load32(cpu->esi + 0x210u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C2B23;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2B02u); lift_push32(cpu, r); sfera_sub_004C23B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x214u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x21Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2B1Du); lift_push32(cpu, r); sfera_sub_004C24B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x214u, cpu->edi);
    label_000C2B23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2B23u);
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2B2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2B2Du);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2B3Eu); lift_push32(cpu, r); sfera_sub_004C2910(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2B48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2B48u);
    cpu->eax = lift_load32(cpu->esi + 0x214u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000C2B9B;
    cpu->edx = lift_load32(cpu->esi + 0x210u);
    cpu->ecx = cpu->edi;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->edx + 0x1Cu)) == (uint8_t)(0u)) goto label_000C2B9B;
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    lift_store32(cpu->esp + 0x3Cu, 0x1BBCu);
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC2B9Bu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000C2B9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2B9Bu);
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2BA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2BA5u);
    cpu->eax = lift_load32(cpu->esi + 0x214u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C2BCA;
    cpu->edx = lift_load32(cpu->esi + 0x210u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    lift_store8(cpu->edi + cpu->edx + 0x1Cu, cpu->ecx & 0xFFu);
    label_000C2BCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2BCAu);
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2BD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2BD4u);
    cpu->eax = lift_load32(cpu->esi + 0x214u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x210u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000C2C46;
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, 0u);
    lift_store8(cpu->esp + 0x14u, 0u);
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    label_000C2C01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2C01u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000C2C01;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2C15u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->ecx += lift_load32(cpu->esi + 0x210u);
    lift_store32(cpu->esp + 0x5Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2C32u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(0x10u)) goto label_000C2C46;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2C43u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C2C46: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2C46u);
    cpu->eax = 1u;
    goto label_000C2C57;
    label_000C2C4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2C4Du);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC2C57u); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    label_000C2C57: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2C57u);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2C90u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000C2DB5;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000C2CEB;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C2DB4;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2CCBu); lift_push32(cpu, r); sfera_sub_004C23B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2CE0u); lift_push32(cpu, r); sfera_sub_004C24B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C2CEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2CEBu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->eax)) goto label_000C2D2E;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2D05u); lift_push32(cpu, r); sfera_sub_004C23B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2D18u); lift_push32(cpu, r); sfera_sub_004C24B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->eax -= lift_load32(cpu->edi);
    cpu->ebp = lift_pop32(cpu);
    cpu->eax &= 0xFFFFFFE0u;
    cpu->eax += lift_load32(cpu->esi);
    cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C2D2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2D2Eu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000C2D70;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2D4Du); lift_push32(cpu, r); sfera_sub_004C23B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2D64u); lift_push32(cpu, r); sfera_sub_004C24F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C2D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2D70u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000C2D8B;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2D80u); lift_push32(cpu, r); sfera_sub_004C25B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2D88u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C2D8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2D8Bu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->esi;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2D9Bu); lift_push32(cpu, r); sfera_sub_004C1AE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C2DB3;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2DB0u); lift_push32(cpu, r); sfera_sub_004C26B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000C2DB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2DB3u);
    cpu->ebp = lift_pop32(cpu);
    label_000C2DB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2DB4u);
    cpu->ebx = lift_pop32(cpu);
    label_000C2DB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2DB5u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2DC0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2DCEu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1A0u);
    lift_store32(cpu->esi + 0x1A0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1A4u);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1A8u);
    lift_store32(cpu->esi + 0x1A8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1B0u);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    lift_store32(cpu->esi + 0x1B4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1B8u);
    lift_store32(cpu->esi + 0x1B8u, cpu->edx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1BCu)) & 0xFFu);
    lift_store8(cpu->esi + 0x1BCu, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->edi + 0x1C0u);
    lift_store32(cpu->esi + 0x1C0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1C4u);
    lift_store32(cpu->esi + 0x1C4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1CCu);
    lift_store32(cpu->esi + 0x1CCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1D0u);
    lift_store32(cpu->esi + 0x1D0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1D4u);
    lift_store32(cpu->esi + 0x1D4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1D8u);
    lift_store32(cpu->esi + 0x1D8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1DCu);
    lift_store32(cpu->esi + 0x1DCu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1E0u);
    lift_store32(cpu->esi + 0x1E0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1E4u);
    lift_store32(cpu->esi + 0x1E4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1E8u);
    lift_store32(cpu->esi + 0x1E8u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1ECu);
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1F0u);
    lift_store32(cpu->esi + 0x1F0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1F4u);
    lift_store32(cpu->esi + 0x1F4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1F8u);
    lift_store32(cpu->esi + 0x1F8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1FCu);
    lift_store32(cpu->esi + 0x1FCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x200u);
    lift_store32(cpu->esi + 0x200u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x204u);
    lift_store32(cpu->esi + 0x204u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x208u);
    lift_store32(cpu->esi + 0x208u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x20Cu);
    cpu->eax = (uint32_t)(cpu->edi + 0x210u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x210u);
    lift_store32(cpu->esi + 0x20Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2F48u); lift_push32(cpu, r); sfera_sub_004C2C90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x220u);
    lift_store32(cpu->esi + 0x220u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x224u);
    lift_store32(cpu->esi + 0x224u, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 0x228u);
    lift_store32(cpu->esi + 0x228u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x22Cu);
    lift_store32(cpu->esi + 0x22Cu, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 0x230u);
    lift_store32(cpu->esi + 0x230u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x234u);
    lift_store32(cpu->esi + 0x234u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x238u);
    lift_store32(cpu->esi + 0x238u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C2FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C2FB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xE3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\MenuListControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2FE5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x240u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C2FEFu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000C3047;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3009u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::CMenuListControl*>(cpu->esi));
    lift_store32(cpu->esi + 0x210u, cpu->ebx);
    lift_store32(cpu->esi + 0x214u, cpu->ebx);
    lift_store32(cpu->esi + 0x218u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x20u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C302Eu); lift_push32(cpu, r); sfera_sub_004C2DC0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000C3047: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3047u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3060u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000C30D8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1B0u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000C30D8;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3082u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1B8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1BCu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 4u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (4.0));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000C30D6;
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000C30D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C30D6u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000C30D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C30D8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C30E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C30E0u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000C30FD;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C30FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C30FDu);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0x9249249u)) goto label_000C3110;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xC3110u);
    label_000C3110: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3110u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3119u); lift_push32(cpu, r); sfera_sub_00402B40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3140u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000C3166;
    (void)cpu;
    label_000C3150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3150u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C315Cu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x1Cu;
    cpu->edi += 0x1Cu;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000C3150;
    label_000C3166: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3166u);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3170u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edx);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    label_000C31B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C31B0u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFECu))) goto label_000C320B;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000C31D7;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC31D7u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000C31D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C31D7u);
    cpu->esi += 0x1Cu;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    cpu->edi += 0x1Cu;
    goto label_000C31B0;
    label_000C320B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C320Bu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C31E5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C31E5u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000C3202;
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    label_000C31F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C31F2u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C31FBu); lift_push32(cpu, r); sfera_sub_004A3E00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x1Cu;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000C31F2;
    label_000C3202: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3202u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C320Bu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3230u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C324Bu); lift_push32(cpu, r); sfera_sub_004C3170(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3250u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3258u); lift_push32(cpu, r); sfera_sub_004CFE70(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::MiniHelpCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 0xFu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3270u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3278u); lift_push32(cpu, r); sfera_sub_004BC9F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C3288;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3285u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C3288: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3288u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3290u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000C3416;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000C32F5;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000C3415;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C32D5u); lift_push32(cpu, r); sfera_sub_0040A270(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C32EAu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C32F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C32F5u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi);
    cpu->edi -= cpu->ebp;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_000C3364;
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C331Fu); lift_push32(cpu, r); sfera_sub_004C3140(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3332u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C3364: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3364u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->edx -= cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000C33C1;
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->edx -= cpu->edi;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C339Cu); lift_push32(cpu, r); sfera_sub_004C3140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C33B5u); lift_push32(cpu, r); sfera_sub_004C3170(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000C33C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C33C1u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000C33DC;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C33D1u); lift_push32(cpu, r); sfera_sub_0040A780(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C33D9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C33DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C33DCu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->ecx -= lift_load32(cpu->ebx);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C33FCu); lift_push32(cpu, r); sfera_sub_004C30E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000C3414;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3411u); lift_push32(cpu, r); sfera_sub_004C3230(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000C3414: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3414u);
    cpu->ebp = lift_pop32(cpu);
    label_000C3415: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3415u);
    cpu->edi = lift_pop32(cpu);
    label_000C3416: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3416u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3420u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C342Eu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1A0u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1A0u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->edi + 0x1A8u);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1B0u));
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 0x1B8u);
    lift_store32(cpu->esi + 0x1B8u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1BCu);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1C0u);
    lift_store32(cpu->esi + 0x1C0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1C4u);
    lift_store32(cpu->esi + 0x1C4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1C8u);
    lift_store32(cpu->esi + 0x1C8u, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1CCu)) & 0xFFu);
    cpu->edx = (uint32_t)(cpu->edi + 0x1D0u);
    lift_store8(cpu->esi + 0x1CCu, cpu->ecx & 0xFFu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C34D0u); lift_push32(cpu, r); sfera_sub_004C3290(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x1E0u);
    lift_store32(cpu->esi + 0x1E0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1E4u);
    lift_store32(cpu->esi + 0x1E4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1E8u);
    lift_store32(cpu->esi + 0x1E8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 0x1ECu);
    lift_store32(cpu->esi + 0x1ECu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1F0u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1F0u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3520u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x45u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\MiniHelpCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3554u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C355Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000C3589;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C357Au); lift_push32(cpu, r); sfera_sub_004CFE70(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::MiniHelpCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 0xFu);
    goto label_000C358B;
    label_000C3589: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3589u);
    cpu->esi = 0u;
    label_000C358B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C358Bu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C359Bu); lift_push32(cpu, r); sfera_sub_004C3420(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C35C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C35C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C35F3u); lift_push32(cpu, r); sfera_sub_004D51A0(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::CMinimapControl*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0xECu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000C3625;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3617u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC3625u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000C3625: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3625u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3640u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C3648u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x194u, cpu->eax);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::CMinimapControl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 0x14u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3670u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"arup");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C36A4u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x2Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\MinimapControl.cpp";
    lift_store32(cpu->esi + 0x194u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C36B9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C36C3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000C36EF;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C36DEu); lift_push32(cpu, r); sfera_sub_004C35C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000C36EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C36EFu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3710u);
    sfera_sub_004D2DD0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004C3720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4C3720u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::CMinimapControl*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C372Eu); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000C373E;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4C373Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000C373E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4C373Eu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}
