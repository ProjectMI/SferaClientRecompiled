#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static void sfera_filebuf_write_bytes(LiftCpu* cpu, uint32_t filebuf, uint32_t data, uint32_t count) {
    uint32_t written = 0u;
    while (written < count) {
        lift_push32(cpu, *(uint8_t*)(data + written));
        cpu->ecx = filebuf;
        lift_push32(cpu, LIFT_CALLBACK_SENTINEL); sfera_sub_004B2680(cpu, LIFT_CALLBACK_SENTINEL);
        if (cpu->eip != LIFT_CALLBACK_SENTINEL || cpu->eax == UINT32_MAX) { break; }
        ++written;
    }
    cpu->eax = written;
    cpu->edx = 0u;
}
static const char* sfera_filebuf_open_mode(uint32_t open_mode) {
    const bool input = (open_mode & 1u) != 0u;
    const bool output = (open_mode & 2u) != 0u;
    const bool append = (open_mode & 8u) != 0u;
    const bool truncate = (open_mode & 16u) != 0u;
    const bool binary = (open_mode & 32u) != 0u;
    if (append) { return input ? (binary ? "a+b" : "a+") : (binary ? "ab" : "a"); }
    if (input && output) { return truncate ? (binary ? "w+b" : "w+") : (binary ? "r+b" : "r+"); }
    if (output) { return binary ? "wb" : "w"; }
    return binary ? "rb" : "r";
}
static FILE* sfera_filebuf_file(uint32_t filebuf) { return reinterpret_cast<FILE*>(static_cast<uintptr_t>(*(uint32_t*)(filebuf + 0x54u))); }
static bool sfera_filebuf_close_native(uint32_t filebuf) {
    FILE* file = sfera_filebuf_file(filebuf);
    if (file == nullptr) { return false; }
    const bool success = std::fclose(file) == 0;
    *(uint8_t*)(filebuf + 0x50u) = 0u;
    *(uint8_t*)(filebuf + 0x49u) = 0u;
    *(uint32_t*)(filebuf + 0x54u) = 0u;
    *(uint32_t*)(filebuf + 0x4Cu) = g_sfera_recovered_static_runtime.ui_counter_a;
    *(uint32_t*)(filebuf + 0x44u) = 0u;
    return success;
}
static uint8_t sfera_string_obfuscation_primary_shift(uint32_t index) { switch (index % 13u) { case 0u: return 1u; case 1u: return 2u; case 2u: return 3u; case 3u: return UINT8_C(0xFE); case 4u: return 1u; case 5u: return UINT8_C(0xFF); case 6u: return UINT8_C(0xFE); case 7u: return UINT8_C(0xFD); case 8u: return 2u; case 9u: return UINT8_C(0xFF); case 10u: return 0u; case 11u: return UINT8_C(0xFE); default: return 2u; } }
static uint8_t sfera_string_obfuscation_secondary_shift(uint32_t index) { switch (index % 7u) { case 0u: return 0u; case 1u: return UINT8_C(0xFF); case 2u: return UINT8_C(0xFE); case 3u: return 2u; case 4u: return UINT8_C(0xFF); case 5u: return 0u; default: return 1u; } }
__declspec(noinline) void sfera_sub_004AFD50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::HyperTextCtrl*>(cpu->esi));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x198u) == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (sub_pred[0]) goto label_000AFDB9;
    cpu->edx = 0x6Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFD9Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AFD9Fu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->edi == 0u) goto label_000AFDB9;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFDB0u)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4AFDB0u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFDB6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AFDB6u));
    cpu->esp += 4u;
    label_000AFDB9:
    if (*(uint32_t*)(cpu->esi + 0x2C4u) == 0u) goto label_000AFDEB;
    cpu->edx = 0x70u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFDD1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AFDD1u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x2C4u);
    if (cpu->edi == 0u) goto label_000AFDEB;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFDE2u)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4AFDE2u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFDE8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AFDE8u));
    cpu->esp += 4u;
    label_000AFDEB:
    if (*(uint32_t*)(cpu->esi + 0x2D8u) == 0u) goto label_000AFE16;
    cpu->edx = 0x71u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFE03u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4AFE03u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2D8u);
    if (cpu->ecx == 0u) goto label_000AFE16;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000AFE16:
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFE21u)); sfera_sub_004AF470(cpu, LIFT_CODE_TOKEN_VA(0x4AFE21u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2DCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFE2Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AFE2Du));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x2DCu) = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFE49u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4AFE49u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004AFE60(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->ebx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_000AFE8B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000AFE8B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000AFE8B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFE9Eu)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x4AFE9Eu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_000AFEBE;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000AFEBE;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000AFEBE:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFED1u)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x4AFED1u));
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFEDDu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AFEDDu));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if (cpu->eax > cpu->edi) goto label_000AFEFE;
    cpu->ebp = cpu->edi;
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    goto label_000AFF08;
    label_000AFEFE:
    cpu->ecx = cpu->edi;
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ebp = cpu->ecx;
    label_000AFF08:
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFF14u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4AFF14u));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax -= cpu->edi;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp + 0x14u) < cpu->eax);
    cpu->esp -= 0xCu;
    sub_pred[0] = (uint8_t)(cpu->eax) == (uint8_t)(cpu->ebx);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    if (sub_pred[0]) goto label_000AFFE8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ecx == cpu->ebx) goto label_000AFF48;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000AFF48;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000AFF48:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_000AFF6F;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000AFF6F;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000AFF6F:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFF87u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4AFF87u));
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFF90u)); sfera_sub_004AFA50(cpu, LIFT_CODE_TOKEN_VA(0x4AFF90u));
    if (cpu->ebp <= cpu->ebx) goto label_000B0094;
    cpu->ebp = 0xFu;
    label_000AFFA0:
    if (*(uint32_t*)(cpu->esi + 0x10u) == cpu->ebx) goto label_000AFFDD;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000AFFBF;
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4AFFBCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4AFFBCu));
    cpu->esp += 4u;
    label_000AFFBF:
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    *(uint8_t*)(cpu->edi) = cpu->ebx & 0xFFu;
    ++*(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (*(uint32_t*)(cpu->esi + 8u) > cpu->eax) goto label_000AFFD5;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_000AFFD5:
    if ((--*(uint32_t*)(cpu->esi + 0x10u)) != 0u) goto label_000AFFDD;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_000AFFDD:
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_000AFFA0;
    goto label_000B0094;
    label_000AFFE8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->ecx == cpu->ebx) goto label_000AFFFA;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000AFFFA;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000AFFFA:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0012u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B0012u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_000B0032;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000B0032;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000B0032:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->ecx = cpu->esp + 0x58u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0042u)); sfera_sub_004AFAE0(cpu, LIFT_CODE_TOKEN_VA(0x4B0042u));
    if (cpu->ebp <= cpu->ebx) goto label_000B0094;
    cpu->ebp = 0xFu;
    label_000B0050:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax == cpu->ebx) goto label_000B008E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = cpu->eax + cpu->ecx + 0xFFFFFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->ecx > cpu->eax) goto label_000B0067;
    cpu->eax -= cpu->ecx;
    label_000B0067:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_000B007E;
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B007Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B007Bu));
    cpu->esp += 4u;
    label_000B007E:
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    *(uint8_t*)(cpu->edi) = cpu->ebx & 0xFFu;
    if ((--*(uint32_t*)(cpu->esi + 0x10u)) != 0u) goto label_000B008E;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_000B008E:
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_000B0050;
    label_000B0094:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B00AAu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B00AAu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B00B1u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B00B1u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B00C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax == cpu->ecx) goto label_000B00FB;
    label_000B00D0:
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->eax == cpu->ecx) goto label_000B00FB;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B00EAu)); sfera_sub_004AFB70(cpu, LIFT_CODE_TOKEN_VA(0x4B00EAu));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_000B00D0;
    label_000B00FB:
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0100(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0131u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4B0131u));
    x87_v0 = 1.0;
    cpu->ebx = 0u;
    *(float*)(cpu->esi + 0x2C8u) = x87_v0; 
    std::construct_at(reinterpret_cast<SphereUI::HyperTextCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x2A0u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2ACu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2B0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2B4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2C4u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x2CCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x2D0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2D4u) = cpu->ebx;
    cpu->edi = cpu->esi + 0x2DCu;
    *(uint32_t*)(cpu->esi + 0x2D8u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x34u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B01A5u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B01A5u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B0222;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2F4u) = 0xFFFF0000u;
    *(uint32_t*)(cpu->esi + 0x2F8u) = 0xFFFFFF00u;
    *(uint32_t*)(cpu->esi + 0x2FCu) = 0xFFFFFFFFu;
    *(uint8_t*)(cpu->esi + 0x308u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 6u;
    *(uint8_t*)(cpu->esi + 0x1A0u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x300u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x304u) = cpu->ebx;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B0222:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B024Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B024Cu));
    lift_trap(cpu, 0x4B024Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004B0250(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0258u)); sfera_sub_004AFD50(cpu, LIFT_CODE_TOKEN_VA(0x4B0258u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000B0268;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0265u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B0265u));
    cpu->esp += 4u;
    label_000B0268:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x58u;
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->esi + 0x1A0u;
    if (*(uint8_t*)(cpu->esi + 0x1A0u) == 0u) goto label_000B056B;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x300u) != cpu->ebx) goto label_000B02CA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B02C6u)); sfera_sub_004B9350(cpu, LIFT_CODE_TOKEN_VA(0x4B02C6u));
    cpu->ebp = cpu->eax;
    goto label_000B0335;
    label_000B02CA:
    cpu->edx = 0x14Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B02D9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B02D9u));
    lift_push32(cpu, 0x68u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B02E0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B02E0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ebx;
    if (cpu->eax == cpu->ebx) goto label_000B02FA;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B02F6u)); sfera_sub_004A78F0(cpu, LIFT_CODE_TOKEN_VA(0x4B02F6u));
    cpu->ecx = cpu->eax;
    goto label_000B02FC;
    label_000B02FA:
    cpu->ecx = 0u;
    label_000B02FC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x8Cu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->esp + 0x60u) = 0xFFFFFFFFu;
    cpu->ebp = cpu->ecx;
    if ((cpu->eax & 0xFFu) >= 2u) goto label_000B0316;
    cpu->edx -= 2u;
    label_000B0316:
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x300u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x304u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB0335u)); sfera_sub_004A8720(cpu, LIFT_CODE_TOKEN_RVA(0xB0335u));
    label_000B0335:
    if (cpu->ebp == cpu->ebx) goto label_000B0558;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint8_t*)(cpu->esp + 0x17u) = 0u;
    if (cpu->eax == cpu->ebx) goto label_000B044B;
    if (*(uint8_t*)(cpu->esi + 0x308u) == 0u) goto label_000B038D;
    cpu->edx = 0x15Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0368u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B0368u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->edi == cpu->ebx) goto label_000B0382;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0379u)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4B0379u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B037Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B037Fu));
    cpu->esp += 4u;
    label_000B0382:
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ebx;
    goto label_000B0410;
    label_000B038D:
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x2A0u) == 0u;
    x87_v0 = 0.0;
    cpu->ebx = 1u;
    *(float*)(cpu->esi + 0x2C8u) = x87_v0; 
    *(uint8_t*)(cpu->esi + 0x2CCu) = cpu->ebx & 0xFFu;
    if (sub_pred[0]) goto label_000B03DA;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B03B5u)); sfera_sub_004090F0(cpu, LIFT_CODE_TOKEN_VA(0x4B03B5u));
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x2DCu;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B03C9u)); sfera_sub_004AF8A0(cpu, LIFT_CODE_TOKEN_VA(0x4B03C9u));
    cpu->ecx = cpu->esp + 0x38u;
    *(uint32_t*)(cpu->esp + 0x60u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB03DAu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0xB03DAu));
    label_000B03DA:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2ACu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2B0u);
    *(uint32_t*)(cpu->esi + 0x2C4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2B4u);
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x2B8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2BCu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2C0u) = cpu->edx;
    cpu->ebx = 0u;
    label_000B0410:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    if (cpu->ecx == cpu->ebx) goto label_000B043A;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x44u) = 0xA90u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB043Au)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xB043Au));
    label_000B043A:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    if (*(uint8_t*)(cpu->ecx + 0x48u) != 0u) goto label_000B044B;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB044Bu)); sfera_sub_004CF750(cpu, LIFT_CODE_TOKEN_RVA(0xB044Bu));
    label_000B044B:
    *(uint32_t*)(cpu->esi + 0x2FCu) = 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esi + 0x300u) != cpu->ebx) goto label_000B0489;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x8Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if ((cpu->ecx & 0xFFu) >= 2u) goto label_000B046E;
    cpu->eax -= 2u;
    label_000B046E:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0481u)); sfera_sub_004A88A0(cpu, LIFT_CODE_TOKEN_VA(0x4B0481u));
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    goto label_000B048F;
    label_000B0489:
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ebp;
    label_000B048F:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2F8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2F4u);
    *(uint32_t*)(cpu->eax + 0x50u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B04B2u)); sfera_sub_004A6220(cpu, LIFT_CODE_TOKEN_VA(0x4B04B2u));
    if (*(uint8_t*)(cpu->esp + 0x68u) == 0u) goto label_000B04C0;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_000B04C0;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    label_000B04C0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->ecx <= cpu->eax) goto label_000B04CF;
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->ebx;
    goto label_000B04D7;
    label_000B04CF:
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->eax;
    label_000B04D7:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B04E4u)); sfera_sub_004AEC80(cpu, LIFT_CODE_TOKEN_VA(0x4B04E4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2D8u);
    if (cpu->ecx == cpu->ebx) goto label_000B0540;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2A4u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x28u);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = 0x17u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB0540u)); sfera_sub_004C79A0(cpu, LIFT_CODE_TOKEN_RVA(0xB0540u));
    label_000B0540:
    if (*(uint8_t*)(cpu->esp + 0x17u) == 0u) goto label_000B0558;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B054Cu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4B054Cu));
    *(uint32_t*)(cpu->esi + 0x2D0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2D4u) = cpu->edx;
    label_000B0558:
    *(uint8_t*)(cpu->esi + 0x1A0u) = 0u;
    *(uint32_t*)(cpu->esi + 0x300u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x304u) = cpu->ebx;
    label_000B056B:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0590(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    sub_pred[1] = *(uint8_t*)(cpu->ebp + 0x1A0u) == 0u;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if (sub_pred[1]) goto label_000B05AC;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB05ACu)); sfera_sub_004B0270(cpu, LIFT_CODE_TOKEN_RVA(0xB05ACu));
    label_000B05AC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x2D8u);
    cpu->ebx = 0u;
    if (cpu->ecx == cpu->ebx) goto label_000B05C4;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000B05C4:
    if (*(uint8_t*)(cpu->ebp + 0x2CCu) == (cpu->ebx & 0xFFu)) goto label_000B0678;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B05D5u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4B05D5u));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->ebp + 0x2D0u); cpu->eax -= *(uint32_t*)(cpu->ebp + 0x2D0u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0x2D4u) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x20u)))))) / (10000.0));
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = (x87_v0) + (x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->ebp + 0x2C8u) = x87_v0;
    x87_v1 = 0.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>lift_right)) goto label_000B0620; }
    *(float*)(cpu->ebp + 0x2C8u) = x87_v0; 
    goto label_000B0622;
    label_000B0620:
    x87_v0 = x87_v0; 
    label_000B0622:
    x87_v0 = 1.0;
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->ebp + 0x2C8u)); if (!(lift_left<lift_right)) goto label_000B0676; }
    *(float*)(cpu->ebp + 0x2C8u) = x87_v0; 
    *(uint8_t*)(cpu->ebp + 0x2CCu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->ebp + 0x2C4u) == cpu->ebx) goto label_000B0678;
    cpu->edx = 0x1C6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0654u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B0654u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x2C4u);
    if (cpu->esi == cpu->ebx) goto label_000B066E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0665u)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4B0665u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B066Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B066Bu));
    cpu->esp += 4u;
    label_000B066E:
    *(uint32_t*)(cpu->ebp + 0x2C4u) = cpu->ebx;
    goto label_000B0678;
    label_000B0676:
    x87_v0 = x87_v0; 
    label_000B0678:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x198u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_000B08A5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x44u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x40u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)cpu->edi <= (int32_t)cpu->ebx) goto label_000B076C;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    label_000B06C0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    if (*(uint8_t*)(cpu->ecx + 0x124u) == 0u) goto label_000B0745;
    cpu->esi = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x120u) <= (int32_t)cpu->esi) goto label_000B0716;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ebp = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx + 0x88u;
    label_000B06E8:
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->eax + 0xFFFFFFF8u)) goto label_000B0702;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->eax)) goto label_000B0702;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->eax + 0xFFFFFFFCu)) goto label_000B0702;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->eax + 4u)) goto label_000B0710;
    label_000B0702:
    ++cpu->esi;
    cpu->eax += 0x10u;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->ecx + 0x120u)) goto label_000B06E8;
    goto label_000B0712;
    label_000B0710:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    label_000B0712:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    label_000B0716:
    *(uint8_t*)(cpu->ecx + 0x125u) = cpu->ebx & 0xFFu;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000B0760;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != *(uint32_t*)(cpu->ebp + 0x2FCu)) goto label_000B0741;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xECu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0737u)); sfera_sub_004CF750(cpu, LIFT_CODE_TOKEN_VA(0x4B0737u));
    *(uint32_t*)(cpu->ebp + 0x2FCu) = 0xFFFFFFFFu;
    label_000B0741:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000B0745:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x128u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_000B06C0;
    goto label_000B076C;
    label_000B0760:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    label_000B076C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0x2FCu)) goto label_000B07C3;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xECu);
    if (*(uint8_t*)(cpu->ecx + 0x48u) != 0u) goto label_000B0789;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB0789u)); sfera_sub_004CF750(cpu, LIFT_CODE_TOKEN_RVA(0xB0789u));
    label_000B0789:
    if (cpu->edi == 0xFFFFFFFFu) goto label_000B07C3;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xECu);
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x128u);
    cpu->edx += *(uint32_t*)(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B07A7u)); sfera_sub_004D0060(cpu, LIFT_CODE_TOKEN_VA(0x4B07A7u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B07BDu)); sfera_sub_004CF770(cpu, LIFT_CODE_TOKEN_VA(0x4B07BDu));
    *(uint32_t*)(cpu->ebp + 0x2FCu) = cpu->edi;
    label_000B07C3:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x198u);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx -= cpu->esi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ebx = 0u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000B08A4;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    label_000B07F0:
    cpu->esi += *(uint32_t*)(cpu->esp + 0x1Cu);
    if (*(uint8_t*)(cpu->esi + 0x124u) == 0u) goto label_000B0878;
    cpu->edx = 0u;
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x120u) <= (int32_t)cpu->edx) goto label_000B086E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ebp = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->esi + 0x88u;
    label_000B0818:
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->eax + 0xFFFFFFF8u)) goto label_000B0832;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->eax)) goto label_000B0832;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->eax + 0xFFFFFFFCu)) goto label_000B0832;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->eax + 4u)) goto label_000B0840;
    label_000B0832:
    ++cpu->edx;
    cpu->eax += 0x10u;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esi + 0x120u)) goto label_000B0818;
    goto label_000B086E;
    label_000B0840:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    if (((*(uint8_t*)(cpu->edx + 0xCu)) & (1u)) == 0u) goto label_000B0869;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0854u)); sfera_sub_004AED90(cpu, LIFT_CODE_TOKEN_VA(0x4B0854u));
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000B0869;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_link.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB0869u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xB0869u));
    label_000B0869:
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    label_000B086E:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x13u));
    *(uint8_t*)(cpu->esi + 0x125u) = cpu->eax & 0xFFu;
    label_000B0878:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x128u) + (uint64_t)(0u);
    cpu->ecx -= cpu->esi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0xDD67C8A7u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    ++cpu->ebx;
    cpu->ecx += cpu->edx;
    if (cpu->ebx < cpu->ecx) goto label_000B07F0;
    label_000B08A4:
    cpu->edi = lift_pop32(cpu);
    label_000B08A5:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B08B0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    sub_pred[0] = cpu->eax == 0xA8Du;
    if (cpu->eax > 0xA8Du) goto label_000B0998;
    if (sub_pred[0]) goto label_000B090E;
    if (cpu->eax != 0x66u) goto label_000B0ADE;
    if (*(uint32_t*)(cpu->esi + 0x198u) == 0u) goto label_000B08F6;
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB08F6u)); sfera_sub_004AEC80(cpu, LIFT_CODE_TOKEN_RVA(0xB08F6u));
    label_000B08F6:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B090E:
    if (*(uint32_t*)(cpu->esi + 0x2ECu) == 0u) goto label_000B0980;
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0922u)); sfera_sub_004AF350(cpu, LIFT_CODE_TOKEN_VA(0x4B0922u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    *(uint8_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0945u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B0945u));
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0950u)); sfera_sub_004AF410(cpu, LIFT_CODE_TOKEN_VA(0x4B0950u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) >= cpu->edi) goto label_000B0963;
    cpu->eax = cpu->esp + 8u;
    label_000B0963:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B096Du)); sfera_sub_004AED40(cpu, LIFT_CODE_TOKEN_VA(0x4B096Du));
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < cpu->edi) goto label_000B0980;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B097Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B097Du));
    cpu->esp += 4u;
    label_000B0980:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B0998:
    cpu->edx = cpu->eax + 0xFFFFF572u;
    if (cpu->edx > 5u) goto label_000B0ADE;
    switch (cpu->edx) {
        case 0u: goto label_000B09AE;
        case 1u: goto label_000B0A6C;
        case 2u: goto label_000B0ADE;
        case 3u: goto label_000B0A2E;
        case 4u: goto label_000B0A98;
        case 5u: goto label_000B0ABD;
        default: lift_trap(cpu, 0x4B09A7u, "resolved jump-table index out of range"); return;
    }
label_000B09AE: ;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2ECu);
    if (cpu->eax == 0u) goto label_000B0A16;
    if (cpu->eax == 1u) goto label_000B09D4;
    label_000B09C0:
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B09CBu)); sfera_sub_004AF410(cpu, LIFT_CODE_TOKEN_VA(0x4B09CBu));
    if (*(uint32_t*)(cpu->esi + 0x2ECu) != 1u) goto label_000B09C0;
    label_000B09D4:
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B09DFu)); sfera_sub_004AF350(cpu, LIFT_CODE_TOKEN_VA(0x4B09DFu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B09E9u)); sfera_sub_00431460(cpu, LIFT_CODE_TOKEN_VA(0x4B09E9u));
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B09F4u)); sfera_sub_004AF410(cpu, LIFT_CODE_TOKEN_VA(0x4B09F4u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) >= 0x10u) goto label_000B0A03;
    cpu->eax = cpu->esp + 8u;
    label_000B0A03:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0A0Du)); sfera_sub_004AED40(cpu, LIFT_CODE_TOKEN_VA(0x4B0A0Du));
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB0A16u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0xB0A16u));
    label_000B0A16:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B0A2E:
    if (*(uint32_t*)(cpu->esi + 0x2ECu) == 0u) goto label_000B0A54;
    label_000B0A40:
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0A4Bu)); sfera_sub_004AF410(cpu, LIFT_CODE_TOKEN_VA(0x4B0A4Bu));
    if (*(uint32_t*)(cpu->esi + 0x2ECu) != 0u) goto label_000B0A40;
    label_000B0A54:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B0A6C:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp + 0x34u) != 0u);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0A80u)); sfera_sub_004AED40(cpu, LIFT_CODE_TOKEN_VA(0x4B0A80u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B0A98:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0AA5u)); sfera_sub_004AECE0(cpu, LIFT_CODE_TOKEN_VA(0x4B0AA5u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B0ABD:
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0AC6u)); sfera_sub_004B0270(cpu, LIFT_CODE_TOKEN_VA(0x4B0AC6u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B0ADE:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0AECu)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4B0AECu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0B20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000B0BAB;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ebx == cpu->ebp) goto label_000B0BAB;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_000B0B4E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0B4E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B0B52;
    label_000B0B4E:
    cpu->edx = 0u;
    goto label_000B0B54;
    label_000B0B52:
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_000B0B54:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_000B0B68;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0B68;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B0B6C;
    label_000B0B68:
    cpu->ecx = 0u;
    goto label_000B0B6E;
    label_000B0B6C:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B0B6E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_000B0B82;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0B82;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B0B86;
    label_000B0B82:
    cpu->eax = 0u;
    goto label_000B0B88;
    label_000B0B86:
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B0B88:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0B97u)); sfera_sub_004AFC40(cpu, LIFT_CODE_TOKEN_VA(0x4B0B97u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_000B0BAB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    if (cpu->eax == 0u) goto label_000B0BCD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0BCD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    label_000B0BCD:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0BE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x70u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edi;
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0C19u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0C19u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    if (cpu->ecx > cpu->eax) goto label_000B0C2C;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    goto label_000B0C33;
    label_000B0C2C:
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->esi = cpu->eax;
    label_000B0C33:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000B0E2C;
    cpu->ecx >>= 1u;
    if (cpu->esi > cpu->ecx) goto label_000B0D7C;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    label_000B0C58:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000B0CAA;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx != 0u) goto label_000B0C68;
    cpu->edx = 0u;
    goto label_000B0C6A;
    label_000B0C68:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    label_000B0C6A:
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (cpu->ecx > cpu->eax) goto label_000B0C73;
    cpu->eax -= cpu->ecx;
    label_000B0C73:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0C81u)); sfera_sub_004AF790(cpu, LIFT_CODE_TOKEN_VA(0x4B0C81u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->eax;
    goto label_000B0C58;
    label_000B0CAA:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0CC6u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0CC6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0CCDu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0CCDu));
    cpu->edx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0CD8u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0CD8u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    if (cpu->eax == 0u) goto label_000B0CEF;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0CEF;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B0CF3;
    label_000B0CEF:
    cpu->ecx = 0u;
    goto label_000B0CF5;
    label_000B0CF3:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B0CF5:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_000B0D0D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0D0D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B0D11;
    label_000B0D0D:
    cpu->ecx = 0u;
    goto label_000B0D13;
    label_000B0D11:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B0D13:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D1Du)); sfera_sub_004B00C0(cpu, LIFT_CODE_TOKEN_VA(0x4B0D1Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D3Au)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0D3Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D41u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0D41u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D48u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0D48u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D5Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0D5Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D64u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0D64u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D74u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0D74u));
    cpu->ecx = cpu->ebp + 0xFFFFFFA8u;
    goto label_000B0E27;
    label_000B0D7C:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    label_000B0D83:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000B0DD5;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx != 0u) goto label_000B0D93;
    cpu->edx = 0u;
    goto label_000B0D95;
    label_000B0D93:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    label_000B0D95:
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (cpu->ecx > cpu->eax) goto label_000B0D9E;
    cpu->eax -= cpu->ecx;
    label_000B0D9E:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0DACu)); sfera_sub_004AF8A0(cpu, LIFT_CODE_TOKEN_VA(0x4B0DACu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->eax;
    goto label_000B0D83;
    label_000B0DD5:
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0DECu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B0DECu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFF9Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E01u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0E01u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E08u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0E08u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFF90u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E1Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0E1Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E24u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0E24u));
    cpu->ecx = cpu->ebp + 0xFFFFFF84u;
    label_000B0E27:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB0E2Cu)); sfera_sub_004B0B20(cpu, LIFT_CODE_TOKEN_RVA(0xB0E2Cu));
    label_000B0E2C:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0C8A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_000B0CA1;
    label_000B0C95:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0C9Cu)); sfera_sub_004AF510(cpu, LIFT_CODE_TOKEN_VA(0x4B0C9Cu));
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_000B0C95;
    label_000B0CA1:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0CAAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B0CAAu));
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0CC6u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0CC6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0CCDu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0CCDu));
    cpu->edx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0CD8u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0CD8u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    if (cpu->eax == 0u) goto label_000B0CEF;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0CEF;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B0CF3;
    label_000B0CEF:
    cpu->ecx = 0u;
    goto label_000B0CF5;
    label_000B0CF3:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B0CF5:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_000B0D0D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B0D0D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B0D11;
    label_000B0D0D:
    cpu->ecx = 0u;
    goto label_000B0D13;
    label_000B0D11:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B0D13:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D1Du)); sfera_sub_004B00C0(cpu, LIFT_CODE_TOKEN_VA(0x4B0D1Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D3Au)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0D3Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D41u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0D41u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D48u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0D48u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D5Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0D5Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D64u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0D64u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0D74u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0D74u));
    cpu->ecx = cpu->ebp + 0xFFFFFFA8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E2Cu)); sfera_sub_004B0B20(cpu, LIFT_CODE_TOKEN_VA(0x4B0E2Cu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0DB5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_000B0DCC;
    label_000B0DC0:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0DC7u)); sfera_sub_004AF410(cpu, LIFT_CODE_TOKEN_VA(0x4B0DC7u));
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_000B0DC0;
    label_000B0DCC:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0DD5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B0DD5u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0DECu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B0DECu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFF9Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E01u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0E01u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E08u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0E08u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFF90u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E1Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0E1Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E24u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0E24u));
    cpu->ecx = cpu->ebp + 0xFFFFFF84u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0E2Cu)); sfera_sub_004B0B20(cpu, LIFT_CODE_TOKEN_VA(0x4B0E2Cu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0E40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esp;
    if (cpu->edx == 0u) goto label_000B0E6E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000B0E6E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000B0E6E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->edx == 0u) goto label_000B0E9D;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000B0E9D;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000B0E9D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->edx == 0u) goto label_000B0ECC;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000B0ECC;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000B0ECC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0ED8u)); sfera_sub_004B0BE0(cpu, LIFT_CODE_TOKEN_VA(0x4B0ED8u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B0EE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->edi == cpu->esi) goto label_000B109B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebp = 0u;
    if (cpu->ecx != cpu->ebp) goto label_000B0F11;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0F05u)); sfera_sub_004AF470(cpu, LIFT_CODE_TOKEN_VA(0x4B0F05u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B0F11:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    if (cpu->ecx > cpu->eax) goto label_000B0FC7;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0F2Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0F2Du));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0F3Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B0F3Eu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0F4Fu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0F4Fu));
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0F58u)); sfera_sub_004AF990(cpu, LIFT_CODE_TOKEN_VA(0x4B0F58u));
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0F64u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B0F64u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->ebp;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    if (cpu->edx == cpu->ebp) goto label_000B0F82;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->ebp) goto label_000B0F82;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000B0F82:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    if (cpu->ecx == cpu->ebp) goto label_000B0FA8;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebp) goto label_000B0FA8;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000B0FA8:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0FBBu)); sfera_sub_004AFE60(cpu, LIFT_CODE_TOKEN_VA(0x4B0FBBu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B0FC7:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0FD9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0FD9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0FE0u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B0FE0u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B0FF1u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B0FF1u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    if (cpu->ebx == cpu->ebp) goto label_000B1011;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (cpu->ecx == cpu->ebp) goto label_000B1011;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000B1011:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1029u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B1029u));
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1032u)); sfera_sub_004AF990(cpu, LIFT_CODE_TOKEN_VA(0x4B1032u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1043u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B1043u));
    cpu->esp -= 0xCu;
    cpu->esi = 0u;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    if (cpu->ebx == cpu->esi) goto label_000B1061;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    if (cpu->ebx == cpu->esi) goto label_000B1061;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000B1061:
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1070u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B1070u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->esp;
    if (cpu->edx == cpu->esi) goto label_000B108E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->esi) goto label_000B108E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000B108E:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB109Bu)); sfera_sub_004B0E40(cpu, LIFT_CODE_TOKEN_RVA(0xB109Bu));
    label_000B109B:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B10B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B10BFu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4B10BFu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    cpu->ecx = cpu->edi;
    cpu->eax = cpu->esi + 0x1A0u;
    cpu->ecx -= cpu->esi;
    cpu->ebp = 0x100u;
    label_000B10E6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->eax));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if ((--cpu->ebp) != 0u) goto label_000B10E6;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x2A0u));
    *(uint8_t*)(cpu->esi + 0x2A0u) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2A4u);
    *(uint32_t*)(cpu->esi + 0x2A4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2A8u);
    *(uint32_t*)(cpu->esi + 0x2A8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2ACu);
    *(uint32_t*)(cpu->esi + 0x2ACu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2B0u);
    *(uint32_t*)(cpu->esi + 0x2B0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2B4u);
    *(uint32_t*)(cpu->esi + 0x2B4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2B8u);
    *(uint32_t*)(cpu->esi + 0x2B8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2BCu);
    *(uint32_t*)(cpu->esi + 0x2BCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2C0u);
    *(uint32_t*)(cpu->esi + 0x2C0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2C4u);
    *(uint32_t*)(cpu->esi + 0x2C4u) = cpu->eax;
    *(float*)(cpu->esi + 0x2C8u) = (double)*(float*)(cpu->edi + 0x2C8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x2CCu));
    *(uint8_t*)(cpu->esi + 0x2CCu) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2D0u);
    *(uint32_t*)(cpu->esi + 0x2D0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2D4u);
    *(uint32_t*)(cpu->esi + 0x2D4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2D8u);
    cpu->edx = cpu->edi + 0x2DCu;
    *(uint32_t*)(cpu->esi + 0x2D8u) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x2DCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B11B5u)); sfera_sub_004B0EE0(cpu, LIFT_CODE_TOKEN_VA(0x4B11B5u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2F4u);
    *(uint32_t*)(cpu->esi + 0x2F4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2F8u);
    *(uint32_t*)(cpu->esi + 0x2F8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2FCu);
    *(uint32_t*)(cpu->esi + 0x2FCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x300u);
    *(uint32_t*)(cpu->esi + 0x300u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x304u);
    *(uint32_t*)(cpu->esi + 0x304u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x308u));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x308u) = cpu->edx & 0xFFu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1210(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x12Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1244u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B1244u));
    lift_push32(cpu, 0x310u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B124Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B124Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000B126C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1268u)); sfera_sub_004B0100(cpu, LIFT_CODE_TOKEN_VA(0x4B1268u));
    cpu->esi = cpu->eax;
    goto label_000B126E;
    label_000B126C:
    cpu->esi = 0u;
    label_000B126E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B127Eu)); sfera_sub_004B10B0(cpu, LIFT_CODE_TOKEN_VA(0x4B127Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0x2D8u) == 0u) goto label_000B12A6;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2D8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2D8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB12A6u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xB12A6u));
    label_000B12A6:
    cpu->edx = 0x13Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B12B5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B12B5u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B12BFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B12BFu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (cpu->eax == 0u) goto label_000B12DB;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B12D9u)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4B12D9u));
    goto label_000B12DD;
    label_000B12DB:
    cpu->eax = 0u;
    label_000B12DD:
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = cpu->ecx + 0x48u;
    if (*(uint32_t*)(cpu->edx) != cpu->eax) goto label_000B1360;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x3Cu);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x30u);
    cpu->eax -= cpu->eax;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_000B1360:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000B13BA;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x11u) != 0u) goto label_000B139D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000B139A;
    label_000B1390:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000B1390;
    label_000B139A:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B139D:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000B13B8;
    label_000B13A6:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_000B13B8;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000B13A6;
    label_000B13B8:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000B13BA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B14F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esi + 0x25Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1514u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4B1514u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000B1537;
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1532u)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4B1532u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    label_000B1537:
    cpu->eax += *(uint32_t*)(cpu->edi + 0x34u);
    x87_v0 = 0.0;
    cpu->edx += *(uint32_t*)(cpu->edi + 0x30u);
    *(uint32_t*)(cpu->esi + 0x278u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x278u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = 1.0;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x274u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B15A3u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4B15A3u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1830(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t filebuf = cpu->ecx;
    const auto* path = reinterpret_cast<const char*>(static_cast<uintptr_t>(*(uint32_t*)(cpu->esp + 4u)));
    const uint32_t open_mode = *(uint32_t*)(cpu->esp + 8u);
    if (sfera_filebuf_file(filebuf) != nullptr) { cpu->eax = 0u; cpu->esp += 0x10u; cpu->eip = stop_address; return; }
    FILE* file = std::fopen(path, sfera_filebuf_open_mode(open_mode));
    if (file != nullptr && (open_mode & 4u) != 0u && std::fseek(file, 0, SEEK_END) != 0) { std::fclose(file); file = nullptr; }
    if (file == nullptr) { cpu->eax = 0u; cpu->esp += 0x10u; cpu->eip = stop_address; return; }
    *(uint8_t*)(filebuf + 0x50u) = 1u;
    *(uint8_t*)(filebuf + 0x49u) = 0u;
    *(uint32_t*)(filebuf + 0x54u) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(file));
    *(uint32_t*)(filebuf + 0x4Cu) = g_sfera_recovered_static_runtime.ui_counter_a;
    *(uint32_t*)(filebuf + 0x44u) = 0u;
    *(uint32_t*)(filebuf + 0x10u) = 0u;
    *(uint32_t*)(filebuf + 0x14u) = 0u;
    *(uint32_t*)(filebuf + 0x20u) = 0u;
    *(uint32_t*)(filebuf + 0x24u) = 0u;
    *(uint32_t*)(filebuf + 0x30u) = 0u;
    *(uint32_t*)(filebuf + 0x34u) = 0u;
    cpu->eax = filebuf;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B19D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x11u) != 0u) goto label_000B19E8;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_000B19E8:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_000B1A02;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A02:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_000B1A13;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A13:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x11u) != 0u) goto label_000B1A38;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_000B1A38:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_000B1A53;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A53:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_000B1A67;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A67:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1A80(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream = cpu->ecx;
    const uint32_t string = cpu->edx;
    const uint32_t size = *(uint32_t*)(string + 0x10u);
    const uint32_t data = *(uint32_t*)(string + 0x14u) >= 0x10u ? *(uint32_t*)(string) : string;
    sfera_filebuf_write_bytes(cpu, stream + 4u, data, size);
    if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
    if (cpu->eax != size) { *(uint32_t*)(stream + 0x6Cu) = *(uint32_t*)(stream + 0x6Cu) | 4u; }
    cpu->eax = stream;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1CB0(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream = cpu->ecx;
    const uint32_t data = cpu->edx;
    uint32_t size = 0u;
    while (*(uint8_t*)(data + size) != 0u) { ++size; }
    sfera_filebuf_write_bytes(cpu, stream + 4u, data, size);
    if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
    if (cpu->eax != size) { *(uint32_t*)(stream + 0x6Cu) = *(uint32_t*)(stream + 0x6Cu) | 4u; }
    cpu->eax = stream;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1F00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax == 0u) goto label_000B1FEB;
    if (*(uint32_t*)(cpu->esp + 0x14u) <= 0u) goto label_000B1FEB;
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0x18u) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_000B1F77;
    cpu->edi = 0u;
    cpu->ebx = 0u;
    if (cpu->eax == 0u) goto label_000B1F62;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000B1F32:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000B1F3C;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000B1F3E;
    label_000B1F3C:
    cpu->eax = cpu->esi;
    label_000B1F3E:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->ebx));
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1F52u)); sfera_sub_004A53E0(cpu, LIFT_CODE_TOKEN_VA(0x4B1F52u));
    cpu->edi += *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->edi > *(uint32_t*)(cpu->esp + 0x20u)) goto label_000B1F6D;
    ++cpu->ebx;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x10u)) goto label_000B1F32;
    label_000B1F62:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000B1F6D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000B1F77:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000B1F81;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_000B1F83;
    label_000B1F81:
    cpu->ecx = cpu->esi;
    label_000B1F83:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1F98u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4B1F98u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x24u) <= cpu->eax) goto label_000B1FE1;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebx = 0u;
    label_000B1FA7:
    --cpu->edi;
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_000B1FE1;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000B1FB7;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000B1FB9;
    label_000B1FB7:
    cpu->eax = cpu->esi;
    label_000B1FB9:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edi));
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B1FCDu)); sfera_sub_004A53E0(cpu, LIFT_CODE_TOKEN_VA(0x4B1FCDu));
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ebx <= *(uint32_t*)(cpu->esp + 0x20u)) goto label_000B1FA7;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000B1FE1:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000B1FEB:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2000(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x11u) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (sub_pred[0]) goto label_000B2019;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4B2000u), "std::out_of_range");
    label_000B2019:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B202Bu)); sfera_sub_004B1370(cpu, LIFT_CODE_TOKEN_VA(0x4B202Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (*(uint8_t*)(cpu->ecx + 0x11u) == 0u) goto label_000B2038;
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    goto label_000B2050;
    label_000B2038:
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2045;
    cpu->edi = cpu->ecx;
    goto label_000B2050;
    label_000B2045:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebx) goto label_000B20B7;
    label_000B2050:
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint8_t*)(cpu->edi + 0x11u) != 0u) goto label_000B205C;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_000B205C:
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebx) goto label_000B2069;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_000B2074;
    label_000B2069:
    if (*(uint32_t*)(cpu->esi) != cpu->ebx) goto label_000B2071;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_000B2074;
    label_000B2071:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_000B2074:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x10u)) goto label_000B2092;
    if (*(uint8_t*)(cpu->edi + 0x11u) == 0u) goto label_000B2089;
    cpu->eax = cpu->esi;
    goto label_000B2090;
    label_000B2089:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB2090u)); sfera_sub_004D1C30(cpu, LIFT_CODE_TOKEN_RVA(0xB2090u));
    label_000B2090:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_000B2092:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->edx) goto label_000B210E;
    if (*(uint8_t*)(cpu->edi + 0x11u) == 0u) goto label_000B20AB;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_000B210E;
    label_000B20AB:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B20B2u)); sfera_sub_00402100(cpu, LIFT_CODE_TOKEN_VA(0x4B20B2u));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_000B210E;
    label_000B20B7:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebx + 8u)) goto label_000B20C7;
    cpu->esi = cpu->eax;
    goto label_000B20E1;
    label_000B20C7:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edi + 0x11u) != 0u) goto label_000B20D3;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_000B20D3:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_000B20E1:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebx) goto label_000B20EE;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_000B20FC;
    label_000B20EE:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebx) goto label_000B20F9;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_000B20FC;
    label_000B20F9:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_000B20FC:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x10u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x10u));
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebx + 0x10u) = cpu->ecx & 0xFFu;
    label_000B210E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->eax + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B2216;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->ecx + 4u)) goto label_000B2213;
    label_000B2130:
    if (*(uint8_t*)(cpu->edi + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B2213;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_000B21A2;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x10u) != 0u) goto label_000B215A;
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2157u)); sfera_sub_004B19D0(cpu, LIFT_CODE_TOKEN_VA(0x4B2157u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    label_000B215A:
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B21D2;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B216F;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x10u) == (cpu->ebx & 0xFFu)) goto label_000B21CE;
    label_000B216F:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B2189;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->eax + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2186u)); sfera_sub_004B1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B2186u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    label_000B2189:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x10u));
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B21A0u)); sfera_sub_004B19D0(cpu, LIFT_CODE_TOKEN_VA(0x4B21A0u));
    goto label_000B2213;
    label_000B21A2:
    if (*(uint8_t*)(cpu->eax + 0x10u) != 0u) goto label_000B21B9;
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B21B7u)); sfera_sub_004B1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B21B7u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    label_000B21B9:
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B21D2;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B21E5;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B21E5;
    label_000B21CE:
    *(uint8_t*)(cpu->eax + 0x10u) = 0u;
    label_000B21D2:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->edx + 4u)) goto label_000B2130;
    goto label_000B2213;
    label_000B21E5:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B21FD;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->eax + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B21FBu)); sfera_sub_004B19D0(cpu, LIFT_CODE_TOKEN_VA(0x4B21FBu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    label_000B21FD:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x10u));
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB2213u)); sfera_sub_004B1A20(cpu, LIFT_CODE_TOKEN_RVA(0xB2213u));
    label_000B2213:
    *(uint8_t*)(cpu->edi + 0x10u) = cpu->ebx & 0xFFu;
    label_000B2216:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2220u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B2220u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000B2231;
    --cpu->eax;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    label_000B2231:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->ecx;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x11u) != 0u) goto label_000B226F;
    label_000B2251:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B225Cu)); sfera_sub_004B2240(cpu, LIFT_CODE_TOKEN_VA(0x4B225Cu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2264u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B2264u));
    cpu->esp += 4u;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x11u) == 0u) goto label_000B2251;
    label_000B226F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->edi == *(uint32_t*)(cpu->esp + 0x24u)) goto label_000B2314;
    cpu->eax = *(uint32_t*)(cpu->edx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->edx + 0x10u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_000B22B4;
    label_000B22B0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000B22B4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = cpu->edi;
    if (cpu->ecx > cpu->edi) goto label_000B22BF;
    cpu->eax -= cpu->ecx;
    label_000B22BF:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    if (*(uint32_t*)(cpu->esp + 0x14u) < 0x10u) goto label_000B22CE;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_000B22CE:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_000B22D7;
    label_000B22D7:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_000B22DF;
    cpu->ecx = cpu->ebx;
    label_000B22DF:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000B22E7;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B22E7:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B22EFu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4B22EFu));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_000B2303;
    if (cpu->esi < cpu->ebx) goto label_000B2303;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebx);
    if (cpu->eax == 0u) goto label_000B230E;
    label_000B2303:
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esp + 0x2Cu)) goto label_000B22B0;
    label_000B230E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B2314:
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2330(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000B2348;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4B2330u), "std::length_error");
    label_000B2348:
    if (cpu->edi <= 0xFFFFFFFEu) goto label_000B2358;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4B2348u), "std::length_error");
    label_000B2358:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->edi) goto label_000B2382;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2369u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x4B2369u));
    if (cpu->edi == 0u) goto label_000B23E6;
    label_000B236D:
    if (cpu->edi != 1u) goto label_000B23AE;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000B23A4;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x10u));
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    goto label_000B23CA;
    label_000B2382:
    if (cpu->edi != 0u) goto label_000B236D;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->eax < 0x10u) goto label_000B239A;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000B239A:
    cpu->eax = cpu->esi;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000B23A4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x10u));
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    goto label_000B23CA;
    label_000B23AE:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000B23B8;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000B23BA;
    label_000B23B8:
    cpu->eax = cpu->esi;
    label_000B23BA:
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4B23C2u));
    cpu->esp += 0xCu;
    label_000B23CA:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_000B23E0;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000B23E0:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_000B23E6:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B23F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2407u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B2407u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B240Eu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B240Eu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx == 0u) goto label_000B2416;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000B2416:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edx > cpu->eax) goto label_000B242E;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax -= cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B242E:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2440(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x11u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (!sub_pred[0]) goto label_000B246A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    label_000B2455:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->esi) goto label_000B245F;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_000B2463;
    label_000B245F:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B2463:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2455;
    cpu->esi = lift_pop32(cpu);
    label_000B246A:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->edx == cpu->eax) goto label_000B248D;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->edx + 0xCu)) goto label_000B248D;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000B248D:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B24B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->ebx;
    if (*(uint8_t*)(cpu->ebx + 0x11u) != 0u) goto label_000B24E1;
    label_000B24C3:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B24CEu)); sfera_sub_004B2240(cpu, LIFT_CODE_TOKEN_VA(0x4B24CEu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B24D6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B24D6u));
    cpu->esp += 4u;
    cpu->ebx = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x11u) == 0u) goto label_000B24C3;
    label_000B24E1:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2500(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ebx;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x11u) == 0u;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    if (!sub_pred[0]) goto label_000B2587;
    cpu->ecx = cpu->edi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B254Au)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B254Au));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x10u));
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->eax & 0xFFu;
    if (*(uint8_t*)(cpu->ecx + 0x11u) == 0u) goto label_000B2564;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    label_000B2564:
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2576u)); sfera_sub_004B2500(cpu, LIFT_CODE_TOKEN_VA(0x4B2576u));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2584u)); sfera_sub_004B2500(cpu, LIFT_CODE_TOKEN_VA(0x4B2584u));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_000B2587:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B259E(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B25AAu)); sfera_sub_004B2240(cpu, LIFT_CODE_TOKEN_VA(0x4B25AAu));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B25B3u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B25B3u));
    lift_trap(cpu, 0x4B25B3u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004B25C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->eax == 0u) goto label_000B25DA;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B25DA;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B25DE;
    label_000B25DA:
    cpu->ecx = 0u;
    goto label_000B25E0;
    label_000B25DE:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B25E0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_000B25FA;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000B25FA;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000B25FE;
    label_000B25FA:
    cpu->ecx = 0u;
    goto label_000B2600;
    label_000B25FE:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B2600:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B260Fu)); sfera_sub_004B2280(cpu, LIFT_CODE_TOKEN_VA(0x4B260Fu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    cpu->eax = cpu->esi;
    if (cpu->ecx == 0u) goto label_000B2640;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_000B2640;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_000B2640:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2675u)); sfera_sub_004B2330(cpu, LIFT_CODE_TOKEN_VA(0x4B2675u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2680(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t ch = *(uint32_t*)(cpu->esp + 4u);
    if (ch == UINT32_MAX) { cpu->eax = 0u; cpu->esp += 8u; cpu->eip = stop_address; return; }
    FILE* file = sfera_filebuf_file(cpu->ecx);
    cpu->eax = file != nullptr && std::fputc(static_cast<unsigned char>(ch), file) != EOF ? ch : UINT32_MAX;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2C40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_000B2C6E;
    if (cpu->edx != cpu->eax) goto label_000B2C6E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2C5Eu)); sfera_sub_004B24B0(cpu, LIFT_CODE_TOKEN_VA(0x4B2C5Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B2C6E:
    if (cpu->ecx == cpu->edx) goto label_000B2CDF;
    label_000B2C72:
    cpu->edx = cpu->ecx;
    if (*(uint8_t*)(cpu->ecx + 0x11u) != 0u) goto label_000B2CC8;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2CA0;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2C9A;
    label_000B2C90:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2C90;
    label_000B2C9A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_000B2CC8;
    label_000B2CA0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2CC4;
    label_000B2CB0:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_000B2CC4;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2CB0;
    label_000B2CC4:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000B2CC8:
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2CD5u)); sfera_sub_004B2000(cpu, LIFT_CODE_TOKEN_VA(0x4B2CD5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000B2C72;
    label_000B2CDF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2D09u)); sfera_sub_004B2500(cpu, LIFT_CODE_TOKEN_VA(0x4B2D09u));
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2D55;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x11u) != 0u) goto label_000B2D30;
    label_000B2D26:
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x11u) == 0u) goto label_000B2D26;
    label_000B2D30:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2D4C;
    label_000B2D41:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2D41;
    label_000B2D4C:
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B2D55:
    *(uint32_t*)(cpu->edx) = cpu->edx;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2D70(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream = cpu->ecx;
    const uint32_t destination = cpu->edx;
    const uint32_t delimiter = *(uint32_t*)(cpu->esp + 4u) & 0xFFu;
    const uint32_t filebuf = stream + 0x10u;
    uint32_t state = 0u;
    bool extracted = false;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = destination;
    lift_push32(cpu, LIFT_CALLBACK_SENTINEL); sfera_sub_00402810(cpu, LIFT_CALLBACK_SENTINEL);
    if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
    FILE* file = sfera_filebuf_file(filebuf);
    if (file == nullptr || (*(uint32_t*)(stream + 0x74u) & 6u) != 0u) {
        state |= 2u;
    } else {
        for (;;) {
            const int value = std::fgetc(file);
            if (value == EOF) { state |= 1u; break; }
            const uint32_t character = static_cast<uint32_t>(static_cast<unsigned char>(value));
            if (character == delimiter) { extracted = true; break; }
            if (*(uint32_t*)(destination + 0x10u) >= 0xFFFFFFFEu) { state |= 2u; break; }
            lift_push32(cpu, character); lift_push32(cpu, 1u);
            cpu->ecx = destination;
            lift_push32(cpu, LIFT_CALLBACK_SENTINEL); sfera_sub_0048EDB0(cpu, LIFT_CALLBACK_SENTINEL);
            if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
            extracted = true;
        }
    }
    if (!extracted) { state |= 2u; }
    if (state != 0u) { *(uint32_t*)(stream + 0x74u) = *(uint32_t*)(stream + 0x74u) | state; }
    cpu->eax = stream;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B30C0(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t filebuf = cpu->ecx;
    cpu->eax = sfera_filebuf_close_native(filebuf) ? filebuf : 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3110(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0x210u) == 0u;
    lift_push32(cpu, cpu->esi);
    if (sub_pred[0]) goto label_000B31AA;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3135u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B3135u));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3145u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B3145u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->esi == *(uint32_t*)(cpu->eax + 8u)) goto label_000B31A9;
    lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_000B3150:
    cpu->edx = 0x273u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B315Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B315Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax!=0u) goto label_000B316B;
    cpu->edx=0u;
    goto label_000B316D;
    label_000B316B:
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_000B316D:
    cpu->edi = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax = cpu->esi;
    cpu->ecx = cpu->esi;
    cpu->eax >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edi > cpu->eax) goto label_000B3180;
    cpu->eax -= cpu->edi;
    label_000B3180:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B318Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B318Fu));
    cpu->esp += 4u;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0x200u;
    ++cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B31A3u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B31A3u));
    if (cpu->esi != *(uint32_t*)(cpu->eax + 8u)) goto label_000B3150;
    cpu->edi = lift_pop32(cpu);
    label_000B31A9:
    cpu->ebx = lift_pop32(cpu);
    label_000B31AA:
    cpu->ecx = cpu->ebp + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B31B5u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B31B5u));
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->ebp + 0x1C8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B31C8u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B31C8u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->ebp + 0x1E4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B31D9u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B31D9u));
    *(uint32_t*)(cpu->ebp + 0x254u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0x258u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0x21Cu) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3200(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->ecx;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000B3253;
    cpu->eax -= *(uint32_t*)(cpu->esi);
    cpu->ebx = cpu->eax + 1u;
    goto label_000B3256;
    label_000B3253:
    cpu->ebx |= 0xFFFFFFFFu;
    label_000B3256:
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3262u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4B3262u));
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x70u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B327Au)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4B327Au));
    cpu->ebx = 0x10u;
    *(uint8_t*)(cpu->esp + 0x64u) = 2u;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->ebx) goto label_000B3297;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3294u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B3294u));
    cpu->esp += 4u;
    label_000B3297:
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x50u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0u;
    *(uint8_t*)(cpu->esp + 0x3Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B32B3u)); sfera_sub_00431210(cpu, LIFT_CODE_TOKEN_VA(0x4B32B3u));
    if (cpu->eax != 1u) goto label_000B32C0;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x244u);
    goto label_000B32D3;
    label_000B32C0:
    if (cpu->eax != 2u) goto label_000B32CD;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x240u);
    goto label_000B32D3;
    label_000B32CD:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x248u);
    label_000B32D3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x34u) >= cpu->ebx) goto label_000B32E1;
    cpu->ecx = cpu->esp + 0x20u;
    label_000B32E1:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x8Cu);
    cpu->edx -= 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B32FAu)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4B32FAu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B330Bu)); sfera_sub_00431220(cpu, LIFT_CODE_TOKEN_VA(0x4B330Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x34u) >= cpu->ebx) goto label_000B3319;
    cpu->eax = cpu->esp + 0x20u;
    label_000B3319:
    cpu->edx = *(uint32_t*)(cpu->edi + 0xDCu);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x8Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    cpu->edx <<= 24u;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u))));
    cpu->esi &= 0xFFFFFFu;
    cpu->edx |= cpu->esi;
    cpu->ecx -= 2u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->eax))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B334Fu)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_VA(0x4B334Fu));
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->ebx) goto label_000B3362;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B335Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B335Fu));
    cpu->esp += 4u;
    label_000B3362:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x80u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = cpu->ecx;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000B33E6;
    cpu->eax -= *(uint32_t*)(cpu->edi);
    cpu->ebx = cpu->eax + 1u;
    goto label_000B33E9;
    label_000B33E6:
    cpu->ebx |= 0xFFFFFFFFu;
    label_000B33E9:
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B33F5u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4B33F5u));
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x78u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B340Du)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4B340Du));
    cpu->edi = 0x10u;
    cpu->ebx = 2u;
    *(uint8_t*)(cpu->esp + 0x6Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x58u) < cpu->edi) goto label_000B342E;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B342Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B342Bu));
    cpu->esp += 4u;
    label_000B342E:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x60u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0u;
    *(uint8_t*)(cpu->esp + 0x4Cu) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B345Cu)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B345Cu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (cpu->edx == *(uint32_t*)(cpu->esi + 0x1BCu)) goto label_000B3476;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, 0x2Au); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB3476u)); sfera_sub_004B2330(cpu, LIFT_CODE_TOKEN_RVA(0xB3476u));
    label_000B3476:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x3Cu) >= cpu->edi) goto label_000B3484;
    cpu->ecx = cpu->esp + 0x28u;
    label_000B3484:
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->edx -= cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B349Cu)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4B349Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B34ADu)); sfera_sub_00431220(cpu, LIFT_CODE_TOKEN_VA(0x4B34ADu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x3Cu) >= cpu->edi) goto label_000B34BB;
    cpu->eax = cpu->esp + 0x28u;
    label_000B34BB:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x84u);
    cpu->eax&=0xFFFFFFu;
    cpu->edx <<= 24u;
    cpu->edx |= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    cpu->ecx -= cpu->ebx;
    *(float*)(cpu->esp + 4u) = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u))));
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->eax))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B34F6u)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_VA(0x4B34F6u));
    if (*(uint32_t*)(cpu->esp + 0x3Cu) < cpu->edi) goto label_000B3509;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3506u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B3506u));
    cpu->esp += 4u;
    label_000B3509:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3530(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x44u;
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x218u) == 0u) goto label_000B3737;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x254u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x21Cu);
    if (cpu->ecx == cpu->eax) goto label_000B35E4;
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1C8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3594u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4B3594u));
    cpu->edi = 0x10u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->edi) goto label_000B35A8;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B35A8:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->edx -= 2u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B35C3u)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x4B35C3u));
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x38u) < cpu->edi) goto label_000B35DE;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B35DBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B35DBu));
    cpu->esp += 4u;
    label_000B35DE:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    goto label_000B35E6;
    label_000B35E4:
    cpu->ebx = 0u;
    label_000B35E6:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000B3609;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3604u)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4B3604u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    label_000B3609:
    cpu->eax += *(uint32_t*)(cpu->edi + 0x34u);
    cpu->edx += *(uint32_t*)(cpu->edi + 0x30u);
    *(uint32_t*)(cpu->esi + 0x278u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += cpu->edx;
    cpu->ebx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x218u);
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x274u) = cpu->edx;
    if (cpu->eax == 0u) goto label_000B369C;
    if ((--cpu->eax) != 0u) goto label_000B3737;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x238u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x278u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x22Cu);
    cpu->ecx <<= 24u;
    cpu->eax += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x228u);
    lift_push32(cpu, (uintptr_t)"_");
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    cpu->esp -= 8u;
    cpu->ecx -= 2u;
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    if ((int32_t)(cpu->eax) >= 0) goto label_000B368F;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000B368F:
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3697u)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_VA(0x4B3697u));
    goto label_000B3737;
    label_000B369C:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x228u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x238u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x278u);
    cpu->edi += cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ebx <<= 24u;
    cpu->ecx &= 0xFFFFFFu;
    cpu->ecx |= cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ebx -= *(uint32_t*)(cpu->esi + 0x234u);
    cpu->ebx += cpu->edx;
    cpu->ebx = cpu->ebx + cpu->eax + 0xFFFFFFFEu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if ((int32_t)cpu->ebx >= 0) goto label_000B36E5;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000B36E5:
    cpu->ebx = cpu->edi + 1u;
    cpu->esp -= 0x10u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    if ((int32_t)cpu->ebx >= 0) goto label_000B3701;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000B3701:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x22Cu);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->esi += cpu->edx;
    cpu->edx = cpu->esi + cpu->eax + 2u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    if ((int32_t)cpu->edi >= 0) goto label_000B372F;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000B372F:
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB3737u)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_RVA(0xB3737u));
    label_000B3737:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3760(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x258u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1C8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B37ABu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4B37ABu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x230u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x228u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->eax -= 2u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B37DCu)); sfera_sub_004B1F00(cpu, LIFT_CODE_TOKEN_VA(0x4B37DCu));
    if (cpu->eax == 0u) goto label_000B37E1;
    ++cpu->eax;
    label_000B37E1:
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->eax;
    if (sub_pred[0]) goto label_000B37FB;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B37F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B37F8u));
    cpu->esp += 4u;
    label_000B37FB:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3820(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x254u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1C8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B386Au)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4B386Au));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x230u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x228u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->eax -= 2u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B389Bu)); sfera_sub_004B1F00(cpu, LIFT_CODE_TOKEN_VA(0x4B389Bu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x254u);
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->ecx;
    if (cpu->eax != cpu->edx) goto label_000B38BB;
    cpu->edx = cpu->ecx + cpu->edx + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->edx;
    goto label_000B38C3;
    label_000B38BB:
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->ecx;
    label_000B38C3:
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < 0x10u) goto label_000B38D7;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B38D4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B38D4u));
    cpu->esp += 4u;
    label_000B38D7:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3900(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream = cpu->ecx;
    const uint32_t filebuf = stream + 0x10u;
    const bool success = sfera_filebuf_close_native(filebuf);
    if (!success) { *(uint32_t*)(stream + 0x74u) = *(uint32_t*)(stream + 0x74u) | 2u; }
    cpu->eax = success ? filebuf : 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3970(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0x28u) == cpu->ebx) goto label_000B39CB;
    *(uint32_t*)(cpu->edi + 0x6Cu) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    label_000B39CB:
    cpu->esi = cpu->edi + 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x20u) = 2u;
    *(uint8_t*)(cpu->esi + 0x50u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x49u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->ebx;
    cpu->ecx = g_sfera_recovered_static_runtime.ui_counter_a;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->ebx;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3A40(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t filebuf = cpu->ecx + 4u;
    if (sfera_filebuf_file(filebuf) != nullptr) { (void)sfera_filebuf_close_native(filebuf); }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3B00(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t stream = cpu->ecx;
    const uint32_t filebuf = stream + 4u;
    const bool success = sfera_filebuf_close_native(filebuf);
    if (!success) { *(uint32_t*)(stream + 0x6Cu) = *(uint32_t*)(stream + 0x6Cu) | 2u; }
    cpu->eax = success ? filebuf : 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3C10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->edi > cpu->eax) goto label_000B3C96;
    if (*(uint32_t*)(cpu->esi + 0x14u) == cpu->eax) goto label_000B3C96;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3C7Fu)); sfera_sub_00403CA0(cpu, LIFT_CODE_TOKEN_VA(0x4B3C7Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B3C96;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_000B3C90;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000B3C92;
    label_000B3C90:
    cpu->eax = cpu->esi;
    label_000B3C92:
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_000B3C96:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3CA2u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x4B3CA2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3CB0u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x4B3CB0u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3D40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x5Cu));
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = 0u;
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1BCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3DA1u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B3DA1u));
    if (*(uint32_t*)(cpu->eax) == cpu->edi) goto label_000B3F31;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D8u);
    if (cpu->eax >= *(uint32_t*)(cpu->esi + 0x24Cu)) goto label_000B3F31;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3DD8u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B3DD8u));
    if (*(uint32_t*)(cpu->eax) == cpu->edi) goto label_000B3DF3;
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::isdigit), LIFT_CODE_TOKEN_VA(0x4B3DE2u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000B3F31;
    label_000B3DF3:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3E0Eu)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B3E0Eu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B3E7A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x18u));
    *(uint32_t*)(cpu->esp + 0x40u) = 0xFu;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->edx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 1u;
    *(uint8_t*)(cpu->esp + 0x2Du) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x200u;
    cpu->ecx = cpu->esp + 0x34u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3E4Fu)); sfera_sub_00492010(cpu, LIFT_CODE_TOKEN_VA(0x4B3E4Fu));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x40u) < 0x10u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x54u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_000B3E6D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3E6Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B3E6Au));
    cpu->esp += 4u;
    label_000B3E6D:
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000B3F31;
    goto label_000B3F07;
    label_000B3E7A:
    cpu->edx = 0x16Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3E89u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B3E89u));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3E90u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B3E90u));
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x54u) = 1u;
    if (cpu->edi == 0u) goto label_000B3ED3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3EB5u)); sfera_sub_004B2650(cpu, LIFT_CODE_TOKEN_VA(0x4B3EB5u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x64u) = 2u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3ED1u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4B3ED1u));
    goto label_000B3ED5;
    label_000B3ED3:
    cpu->eax = 0u;
    label_000B3ED5:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x200u;
    *(uint32_t*)(cpu->esp + 0x58u) = 3u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3EF1u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x4B3EF1u));
    *(uint32_t*)(cpu->esp + 0x54u) = 0xFFFFFFFFu;
    if ((((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_000B3F07;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB3F07u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0xB3F07u));
    label_000B3F07:
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3F12u)); sfera_sub_00491D00(cpu, LIFT_CODE_TOKEN_VA(0x4B3F12u));
    cpu->edx = cpu->esi + 0x1C8u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + 0x1E4u;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3F2Au)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x4B3F2Au));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB3F31u)); sfera_sub_004B4100(cpu, LIFT_CODE_TOKEN_RVA(0xB3F31u));
    label_000B3F31:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B3F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x1D8u) == 0u) goto label_000B4057;
    if (*(uint32_t*)(cpu->esi + 0x210u) == 0u) goto label_000B4057;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3F9Cu)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B3F9Cu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B4056;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->edx == 0xFFFFFFFFu) goto label_000B3FBD;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edx == 0u) goto label_000B3FB9;
    if (cpu->eax == 0u) goto label_000B3FBD;
    label_000B3FB9:
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    goto label_000B3FE6;
    label_000B3FBD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    --cpu->ecx;
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3FD9u)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B3FD9u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B4056;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    label_000B3FE6:
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B3FF1u)); sfera_sub_0048F420(cpu, LIFT_CODE_TOKEN_VA(0x4B3FF1u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B4056;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4000u)); sfera_sub_00491D00(cpu, LIFT_CODE_TOKEN_VA(0x4B4000u));
    cpu->edx = cpu->esi + 0x1C8u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + 0x1E4u;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4018u)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x4B4018u));
    --*(uint32_t*)(cpu->esi + 0x258u);
    if (*(uint32_t*)(cpu->esi + 0x254u) <= 0u) goto label_000B402E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB402Eu)); sfera_sub_004B3760(cpu, LIFT_CODE_TOKEN_RVA(0xB402Eu));
    label_000B402E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x21Cu);
    if (cpu->eax == 0u) goto label_000B4056;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x254u);
    if (cpu->eax != cpu->ecx) goto label_000B4050;
    --cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB4050u)); sfera_sub_004B3820(cpu, LIFT_CODE_TOKEN_RVA(0xB4050u));
    label_000B4050:
    --*(uint32_t*)(cpu->esi + 0x21Cu);
    label_000B4056:
    cpu->edi = lift_pop32(cpu);
    label_000B4057:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4082u)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B4082u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B40C8;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B409Au)); sfera_sub_0048F420(cpu, LIFT_CODE_TOKEN_VA(0x4B409Au));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B40C8;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B40A9u)); sfera_sub_00491D00(cpu, LIFT_CODE_TOKEN_VA(0x4B40A9u));
    cpu->eax = cpu->esi + 0x1C8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x1E4u;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B40C1u)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x4B40C1u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB40C8u)); sfera_sub_004B3820(cpu, LIFT_CODE_TOKEN_RVA(0xB40C8u));
    label_000B40C8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B40D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    if (cpu->ecx == 0u) goto label_000B40FB;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x254u);
    if (cpu->ecx != cpu->eax) goto label_000B40F5;
    --cpu->eax;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB40F5u)); sfera_sub_004B3820(cpu, LIFT_CODE_TOKEN_RVA(0xB40F5u));
    label_000B40F5:
    --*(uint32_t*)(cpu->esi + 0x21Cu);
    label_000B40FB:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4100(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    if (cpu->ecx >= *(uint32_t*)(cpu->esi + 0x1D8u)) goto label_000B413C;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x258u);
    ++cpu->eax;
    sub_pred[0] = cpu->ecx == cpu->eax;
    cpu->ecx = cpu->esi;
    if (!sub_pred[0]) goto label_000B4131;
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4129u)); sfera_sub_004B3760(cpu, LIFT_CODE_TOKEN_VA(0x4B4129u));
    ++*(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B4131:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4136u)); sfera_sub_004B3820(cpu, LIFT_CODE_TOKEN_VA(0x4B4136u));
    ++*(uint32_t*)(cpu->esi + 0x21Cu);
    label_000B413C:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x1D8u) == cpu->edi) goto label_000B4162;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4159u)); sfera_sub_004B3820(cpu, LIFT_CODE_TOKEN_VA(0x4B4159u));
    *(uint32_t*)(cpu->esi + 0x21Cu) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B4162:
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x21Cu) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1D8u);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->ecx + 0x21Cu) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_000B419E;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x258u) = cpu->eax;
    sfera_sub_004B3760(cpu, stop_address); return;
    label_000B419E:
    *(uint32_t*)(cpu->ecx + 0x254u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x258u) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B41B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->edi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x10u) = 0u;
    *(uint8_t*)(cpu->edi) = 0u;
    lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
    lift_native_call(cpu, native_function_address32(&::IsClipboardFormatAvailable), LIFT_CODE_TOKEN_VA(0x4B4203u));
    if (cpu->eax != 1u) goto label_000B4257;
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::OpenClipboard), LIFT_CODE_TOKEN_VA(0x4B4210u));
    if (cpu->eax != 1u) goto label_000B4257;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetClipboardData), LIFT_CODE_TOKEN_VA(0x4B421Cu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_000B4251;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::GlobalLock), LIFT_CODE_TOKEN_VA(0x4B4229u));
    if (cpu->eax == 0u) goto label_000B4251;
    cpu->ecx = cpu->eax;
    cpu->ebp = cpu->ecx + 1u;
    label_000B4238:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B4238;
    cpu->ecx -= cpu->ebp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B424Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B424Au));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::GlobalUnlock), LIFT_CODE_TOKEN_RVA(0xB424Bu));
    label_000B4251:
    lift_native_call(cpu, native_function_address32(&::CloseClipboard), LIFT_CODE_TOKEN_RVA(0xB4251u));
    label_000B4257:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x7Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xA4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xA0u);
    cpu->ebx = 0u;
    cpu->eax -= cpu->ebx;
    cpu->esi = cpu->ecx;
    if (cpu->eax == 0u) goto label_000B44F6;
    if ((--cpu->eax) != 0u) goto label_000B4590;
    if (*(uint32_t*)(cpu->edi + 0x10u) == cpu->ebx) goto label_000B4590;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint32_t*)(cpu->esp + 0x9Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B42E1u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B42E1u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B44CC;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->esp + 0x98u) = 1u;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x70u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x54u) = cpu->ebx & 0xFFu;
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x9Cu) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4357u)); sfera_sub_00490C50(cpu, LIFT_CODE_TOKEN_VA(0x4B4357u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x1D8u);
    if (cpu->ecx > *(uint32_t*)(cpu->esi + 0x24Cu)) goto label_000B43FD;
    cpu->edi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1F4u);
    if (cpu->edi > *(uint32_t*)(cpu->esi + 0x250u)) goto label_000B43FD;
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4391u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B4391u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B43A4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B43A4u));
    cpu->ecx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B43B4u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B43B4u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B43C3u)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x4B43C3u));
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B43CEu)); sfera_sub_0048F7E0(cpu, LIFT_CODE_TOKEN_VA(0x4B43CEu));
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B43D9u)); sfera_sub_00491D00(cpu, LIFT_CODE_TOKEN_VA(0x4B43D9u));
    cpu->eax = cpu->esi + 0x1C8u;
    cpu->edx = cpu->esi + 0x1E4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B43F1u)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x4B43F1u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B43F8u)); sfera_sub_004B4180(cpu, LIFT_CODE_TOKEN_VA(0x4B43F8u));
    goto label_000B4491;
    label_000B43FD:
    if (*(uint32_t*)(cpu->esp + 0x28u) == cpu->ebx) goto label_000B4488;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4415u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B4415u));
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4423u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B4423u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->esi == *(uint32_t*)(cpu->eax + 8u)) goto label_000B4488;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    label_000B4430:
    cpu->edx = 0x266u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B443Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B443Fu));
    if (cpu->ebp != cpu->ebx) goto label_000B4447;
    cpu->edx=0u;
    goto label_000B444A;
    label_000B4447:
    cpu->edx = *(uint32_t*)(cpu->ebp);
    label_000B444A:
    cpu->edi = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax = cpu->esi;
    cpu->ecx = cpu->esi;
    cpu->eax >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edi > cpu->eax) goto label_000B445D;
    cpu->eax -= cpu->edi;
    label_000B445D:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B446Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B446Cu));
    cpu->esp += 4u;
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x1Cu;
    ++cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B447Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B447Eu));
    if (cpu->esi != *(uint32_t*)(cpu->eax + 8u)) goto label_000B4430;
    cpu->ebp = 0xFu;
    label_000B4488:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB4491u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_RVA(0xB4491u));
    label_000B4491:
    if (*(uint32_t*)(cpu->esp + 0x68u) < 0x10u) goto label_000B44A5;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B44A2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B44A2u));
    cpu->esp += 4u;
    label_000B44A5:
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x54u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B44BAu)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B44BAu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B44C4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B44C4u));
    cpu->esp += 4u;
    goto label_000B4590;
    label_000B44CC:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x34u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB44F6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xB44F6u));
    label_000B44F6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1F4u);
    if (*(uint32_t*)(cpu->esi + 0x1F8u) < 0x10u) goto label_000B450D;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1E4u);
    goto label_000B4513;
    label_000B450D:
    cpu->eax = cpu->esi + 0x1E4u;
    label_000B4513:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4521u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x4B4521u));
    if (cpu->eax == 0u) goto label_000B4590;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    if (cpu->edx > *(uint32_t*)(cpu->esi + 0x250u)) goto label_000B4590;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4537u)); sfera_sub_004B3110(cpu, LIFT_CODE_TOKEN_VA(0x4B4537u));
    if (*(uint32_t*)(cpu->edi + 0x10u) == cpu->ebx) goto label_000B4590;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0x1E4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B454Bu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B454Bu));
    cpu->ebx = cpu->esi + 0x1C8u;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esi + 0x200u;
    cpu->ecx = cpu->esi + 0x1E4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4563u)); sfera_sub_00490C50(cpu, LIFT_CODE_TOKEN_VA(0x4B4563u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4577u)); sfera_sub_004923E0(cpu, LIFT_CODE_TOKEN_VA(0x4B4577u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esi + 0x1E4u;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4589u)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x4B4589u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB4590u)); sfera_sub_004B4180(cpu, LIFT_CODE_TOKEN_RVA(0xB4590u));
    label_000B4590:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x88u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B45C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    sub_pred[0] = cpu->eax == 0x1DB0u;
    if (cpu->eax > 0x1DB0u) goto label_000B46E1;
    if (sub_pred[0]) goto label_000B4674;
    if (cpu->eax != 0x69u) goto label_000B4780;
    if (cpu->ecx == 0u) goto label_000B4666;
    if (*(uint8_t*)(cpu->esi + 0x4Au) != 0u) goto label_000B4666;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->eax;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4630u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4B4630u));
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4644u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4B4644u));
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4658u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4B4658u));
    *(uint8_t*)(cpu->esi + 0x4Au) = 1u;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4666:
    *(uint8_t*)(cpu->esi + 0x4Au) = 0u;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4674:
    if (cpu->ecx == 0u) goto label_000B4779;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    *(uint8_t*)(cpu->esp + 0x10u) = 0u;
    cpu->ebx = cpu->eax + 1u;
    label_000B4696:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B4696;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B46AAu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B46AAu));
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B46BFu)); sfera_sub_004B4270(cpu, LIFT_CODE_TOKEN_VA(0x4B46BFu));
    if (*(uint32_t*)(cpu->esp + 0x24u) < 0x10u) goto label_000B4779;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B46D4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B46D4u));
    cpu->esp += 4u;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B46E1:
    cpu->edx = cpu->eax + 0xFFFFE24Fu;
    if (cpu->edx > 5u) goto label_000B4780;
    switch (cpu->edx) {
        case 0u: goto label_000B4707;
        case 1u: goto label_000B4731;
        case 2u: case 4u: goto label_000B4780;
        case 3u: goto label_000B4761;
        case 5u: goto label_000B46F7;
        default: lift_trap(cpu, 0x4B46F0u, "resolved jump-table index out of range"); return;
    }
label_000B46F7: ;
    *(uint32_t*)(cpu->esi + 0x23Cu) = cpu->ecx;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4707:
    if (cpu->ecx == 0u) goto label_000B4779;
    cpu->eax = cpu->esi + 0x1C8u;
    if (*(uint32_t*)(cpu->esi + 0x1DCu) < 0x10u) goto label_000B471C;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B471C:
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    label_000B4720:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B4720;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4731:
    if (cpu->ecx == 0u) goto label_000B4779;
    cpu->eax = cpu->esi + 0x1E4u;
    if (*(uint32_t*)(cpu->esi + 0x1F8u) < 0x10u) goto label_000B4746;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B4746:
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    label_000B4750:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B4750;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4761:
    if (cpu->ecx == 0u) goto label_000B476D;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1D8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000B476D:
    if (cpu->edi == 0u) goto label_000B4779;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F4u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    label_000B4779:
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4780:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB478Au)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_RVA(0xB478Au));
    label_000B478A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B47D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x48u) == 0u;
    lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_000B4A68;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000B4A68;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000B4820;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B481Bu)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4B481Bu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    label_000B4820:
    cpu->eax += *(uint32_t*)(cpu->edi + 0x34u);
    cpu->edx += *(uint32_t*)(cpu->edi + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx = cpu->eax;
    cpu->ebx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edi += cpu->edx;
    *(uint32_t*)(cpu->esi + 0x274u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x278u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = cpu->ecx + cpu->edi + 0xFFFFFFFFu;
    cpu->ecx = cpu->eax + cpu->ebx + 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x22Cu);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x228u);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    cpu->edx += cpu->edi;
    cpu->eax += cpu->ebx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4871u)); sfera_sub_004B14F0(cpu, LIFT_CODE_TOKEN_VA(0x4B4871u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    g_sfera_screen_clip_runtime.left = cpu->edi;
    g_sfera_screen_clip_runtime.top = cpu->ebx;
    g_sfera_screen_clip_runtime.right = cpu->ecx;
    g_sfera_screen_clip_runtime.bottom = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x4B4891u));
    cpu->ecx = cpu->eax;
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x220u);
    if (cpu->ecx <= 0x1F4u) goto label_000B48BD;
    sub_pred[1] = *(uint8_t*)(cpu->esi + 0x224u) == 0u;
    *(uint32_t*)(cpu->esi + 0x220u) = cpu->eax;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (sub_pred[1]);
    *(uint8_t*)(cpu->esi + 0x224u) = cpu->edx & 0xFFu;
    label_000B48BD:
    if (*(uint8_t*)(cpu->esi + 0x224u) == 0u) goto label_000B48D3;
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000B48D3;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB48D3u)); sfera_sub_004B3530(cpu, LIFT_CODE_TOKEN_RVA(0xB48D3u));
    label_000B48D3:
    if (*(uint32_t*)(cpu->esi + 0x1D8u) == 0u) goto label_000B4A56;
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x254u);
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B48FBu)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B48FBu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B4A56;
    cpu->ebx |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x18u) == cpu->ebx) goto label_000B4A56;
    if (*(uint32_t*)(cpu->esp + 0x24u) == cpu->ebx) goto label_000B4A56;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x258u);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4935u)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B4935u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B4A56;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->eax != cpu->ebx) goto label_000B4950;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x210u);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    label_000B4950:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ebx > cpu->eax) goto label_000B4A56;
    label_000B4960:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B496Cu)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4B496Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B497Fu)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x4B497Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B4A47;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4993u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4B4993u));
    cpu->ebx = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B49A9u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4B49A9u));
    cpu->edi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esp + 0x50u;
    --cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B49B6u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4B49B6u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != *(uint32_t*)(cpu->esp + 0x18u)) goto label_000B49C8;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    label_000B49C8:
    if (cpu->eax != *(uint32_t*)(cpu->esp + 0xCu)) goto label_000B49D2;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    label_000B49D2:
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B49DEu)); sfera_sub_00431240(cpu, LIFT_CODE_TOKEN_VA(0x4B49DEu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->eax != 4u) goto label_000B4A0E;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x23Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4A0Cu)); sfera_sub_004B3390(cpu, LIFT_CODE_TOKEN_VA(0x4B4A0Cu));
    goto label_000B4A31;
    label_000B4A0E:
    if (cpu->eax != 5u) goto label_000B4A31;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB4A31u)); sfera_sub_004B3200(cpu, LIFT_CODE_TOKEN_RVA(0xB4A31u));
    label_000B4A31:
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4A3Du)); sfera_sub_00431260(cpu, LIFT_CODE_TOKEN_VA(0x4B4A3Du));
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000B4A47:
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ebx <= *(uint32_t*)(cpu->esp + 0xCu)) goto label_000B4960;
    label_000B4A56:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi += 0x25Cu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB4A68u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_RVA(0xB4A68u));
    label_000B4A68:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4AB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4AD8u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B4AD8u));
    cpu->ecx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x10u) <= cpu->ebx) goto label_000B4B50;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    label_000B4AE1:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax < 0x10u) goto label_000B4AED;
    cpu->ebx = *(uint32_t*)(cpu->esi);
    goto label_000B4AEF;
    label_000B4AED:
    cpu->ebx = cpu->esi;
    label_000B4AEF:
    if (cpu->eax < 0x10u) goto label_000B4AF8;
    cpu->edi = *(uint32_t*)(cpu->esi);
    goto label_000B4AFA;
    label_000B4AF8:
    cpu->edi = cpu->esi;
    label_000B4AFA:
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x4EC4EC4Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xDu);
    cpu->ebp = cpu->ecx;
    cpu->ebp -= cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(sfera_string_obfuscation_primary_shift(cpu->ebp)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + (uint64_t)(sfera_string_obfuscation_secondary_shift(cpu->eax))) & 0xFFu);
    ++cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(*(uint8_t*)(cpu->ebx + cpu->ecx + 0xFFFFFFFFu)) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->edi + cpu->ecx + 0xFFFFFFFFu) = cpu->edx & 0xFFu;
    if (cpu->ecx < *(uint32_t*)(cpu->esi + 0x10u)) goto label_000B4AE1;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000B4B50:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4B60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->edi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    *(uint8_t*)(cpu->edi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4B90u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B4B90u));
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->edi + 0x10u) <= cpu->esi) goto label_000B4C05;
    lift_push32(cpu, cpu->ebp);
    label_000B4B98:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->eax < 0x10u) goto label_000B4BA4;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    goto label_000B4BA6;
    label_000B4BA4:
    cpu->ecx = cpu->edi;
    label_000B4BA6:
    if (cpu->eax < 0x10u) goto label_000B4BAF;
    cpu->ebp = *(uint32_t*)(cpu->edi);
    goto label_000B4BB1;
    label_000B4BAF:
    cpu->ebp = cpu->edi;
    label_000B4BB1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->esi));
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x4EC4EC4Fu * (int32_t)(cpu->esi))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xDu);
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx - (uint64_t)(sfera_string_obfuscation_primary_shift(cpu->edx))) & 0xFFu);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->esi))) >> 32u);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->edx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx - (uint64_t)(sfera_string_obfuscation_secondary_shift(cpu->eax))) & 0xFFu);
    ++cpu->esi;
    *(uint8_t*)(cpu->esi + cpu->ebp + 0xFFFFFFFFu) = cpu->ecx & 0xFFu;
    if (cpu->esi < *(uint32_t*)(cpu->edi + 0x10u)) goto label_000B4B98;
    cpu->ebp = lift_pop32(cpu);
    label_000B4C05:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4C10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0x28u) == cpu->ebx) goto label_000B4C6B;
    *(uint32_t*)(cpu->edi + 0x74u) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    label_000B4C6B:
    cpu->esi = cpu->edi + 0x10u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x20u) = 2u;
    *(uint8_t*)(cpu->esi + 0x50u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x49u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->ebx;
    cpu->ecx = g_sfera_recovered_static_runtime.ui_counter_a;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->ebx;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4CE0(LiftCpu* cpu, uint32_t stop_address) {
    const uint32_t filebuf = cpu->ecx + 0x10u;
    if (sfera_filebuf_file(filebuf) != nullptr) { (void)sfera_filebuf_close_native(filebuf); }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B4DD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x34u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4E01u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4B4E01u));
    cpu->ebx = 0u;
    cpu->edi = cpu->esi + 0x198u;
    std::construct_at(reinterpret_cast<SphereUI::HyperTextEditControl*>(cpu->esi));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x40u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4E25u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B4E25u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B4F82;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    lift_push32(cpu, 0x14u);
    *(uint8_t*)(cpu->esp + 0x40u) = 2u;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4E5Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B4E5Du));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B4F58;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint8_t*)(cpu->ecx + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint8_t*)(cpu->edx + 0x11u) = 1u;
    cpu->eax = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1C8u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1F8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1F4u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1E4u) = cpu->ebx & 0xFFu;
    cpu->edi = cpu->esi + 0x200u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x40u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4ED7u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B4ED7u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B4F2E;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x21Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x224u) = 1u;
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x50u) = 0x17u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B4F2E:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB4F58u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xB4F58u));
    label_000B4F58:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB4F82u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xB4F82u));
    label_000B4F82:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4FACu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B4FACu));
    lift_trap(cpu, 0x4B4FACu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004B4FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0xCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B4FD3u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B4FD3u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (cpu->edx != *(uint32_t*)(cpu->esi + 0x1BCu)) goto label_000B5013;
    if (*(uint32_t*)(cpu->esi + 0x1A8u) == 0u) goto label_000B5013;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    if (cpu->eax == 0u) goto label_000B4FF7;
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    label_000B4FF7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B500Bu)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4B500Bu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB5013u)); sfera_sub_004B4270(cpu, LIFT_CODE_TOKEN_RVA(0xB5013u));
    label_000B5013:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B5020(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0xCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5043u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B5043u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (cpu->edx != *(uint32_t*)(cpu->esi + 0x1BCu)) goto label_000B5089;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    if (cpu->ecx == 0u) goto label_000B5089;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    if (cpu->eax >= cpu->ecx) goto label_000B5068;
    ++cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    label_000B5068:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    sub_pred[0] = cpu->eax == cpu->ecx;
    cpu->ecx = cpu->esi + 0x198u;
    if (!sub_pred[0]) goto label_000B5079;
    --cpu->eax;
    label_000B5079:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B507Fu)); sfera_sub_004B23F0(cpu, LIFT_CODE_TOKEN_VA(0x4B507Fu));
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB5089u)); sfera_sub_004B4270(cpu, LIFT_CODE_TOKEN_RVA(0xB5089u));
    label_000B5089:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B5090(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x80u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x94u;
    lift_push32(cpu, 2u);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    cpu->edi = 0xFu;
    lift_push32(cpu, (uintptr_t)"  ");
    cpu->ecx = cpu->esp + 0x60u;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B50EDu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B50EDu));
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\n\r");
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0xA4u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5110u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B5110u));
    cpu->eax = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0xA0u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5124u)); sfera_sub_004B41B0(cpu, LIFT_CODE_TOKEN_VA(0x4B5124u));
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x44u;
    *(uint8_t*)(cpu->esp + 0xA4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5141u)); sfera_sub_00490530(cpu, LIFT_CODE_TOKEN_VA(0x4B5141u));
    cpu->ebp = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x88u) < cpu->ebp) goto label_000B515C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5159u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5159u));
    cpu->esp += 4u;
    label_000B515C:
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->ebp) goto label_000B5181;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B517Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B517Eu));
    cpu->esp += 4u;
    label_000B5181:
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x9Cu) = 6u;
    if (*(uint32_t*)(cpu->esp + 0x6Cu) < cpu->ebp) goto label_000B51A8;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B51A5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B51A5u));
    cpu->esp += 4u;
    label_000B51A8:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24Cu);
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->ebx & 0xFFu;
    if (cpu->edx <= cpu->eax) goto label_000B51D8;
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB51D8u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_RVA(0xB51D8u));
    label_000B51D8:
    if (*(uint32_t*)(cpu->esp + 0x4Cu) == cpu->ebx) goto label_000B52DE;
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B51FDu)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B51FDu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B5220;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x200u;
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B521Au)); sfera_sub_00492010(cpu, LIFT_CODE_TOKEN_VA(0x4B521Au));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B529B;
    goto label_000B5278;
    label_000B5220:
    cpu->edx = 0x208u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B522Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B522Fu));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5236u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B5236u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x9Cu) = 7u;
    if (cpu->eax == cpu->ebx) goto label_000B525A;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5258u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4B5258u));
    goto label_000B525C;
    label_000B525A:
    cpu->eax = 0u;
    label_000B525C:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x200u;
    *(uint8_t*)(cpu->esp + 0xA0u) = 6u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB5278u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0xB5278u));
    label_000B5278:
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5283u)); sfera_sub_00491D00(cpu, LIFT_CODE_TOKEN_VA(0x4B5283u));
    cpu->eax = cpu->esi + 0x1C8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x1E4u;
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB529Bu)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_RVA(0xB529Bu));
    label_000B529B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = cpu->ecx + cpu->edx + 0xFFFFFFFFu;
    if (cpu->eax >= *(uint32_t*)(cpu->esi + 0x1D8u)) goto label_000B52DE;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x258u);
    cpu->edi = cpu->eax + 1u;
    sub_pred[0] = cpu->ecx == cpu->edi;
    cpu->ecx = cpu->esi;
    if (!sub_pred[0]) goto label_000B52CF;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B52CDu)); sfera_sub_004B3760(cpu, LIFT_CODE_TOKEN_VA(0x4B52CDu));
    goto label_000B52D4;
    label_000B52CF:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB52D4u)); sfera_sub_004B3820(cpu, LIFT_CODE_TOKEN_RVA(0xB52D4u));
    label_000B52D4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esi + 0x21Cu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x21Cu)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    label_000B52DE:
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->ebp) goto label_000B52F1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B52EEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B52EEu));
    cpu->esp += 4u;
    label_000B52F1:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B5350(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x110u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x124u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x134u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x134u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint8_t*)(cpu->edi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B53BDu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B53BDu));
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 1u;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0xD4u;
    *(uint32_t*)(cpu->esp + 0x134u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xE8u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xE4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xD4u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B53F4u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B53F4u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x130u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5405u)); sfera_sub_004B4C10(cpu, LIFT_CODE_TOKEN_VA(0x4B5405u));
    lift_push32(cpu, 0xCu); lift_push32(cpu, (uintptr_t)"connectn.cfg");
    cpu->ecx = cpu->esp + 0xF0u;
    *(uint8_t*)(cpu->esp + 0x134u) = 2u;
    *(uint32_t*)(cpu->esp + 0x104u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x100u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xF0u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5435u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B5435u));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0xFCu) < 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xE8u);
    *(uint8_t*)(cpu->esp + 0x12Cu) = 3u;
    if (!sub_pred[0]) goto label_000B5455;
    cpu->eax = cpu->esp + 0xE8u;
    label_000B5455:
    lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5462u)); sfera_sub_004B1830(cpu, LIFT_CODE_TOKEN_VA(0x4B5462u));
    if (cpu->eax != 0u) goto label_000B547C;
    *(uint32_t*)(cpu->esp + 0x90u) = 2u;
    goto label_000B548E;
    label_000B547C:
    *(uint32_t*)(cpu->esp + 0x90u) = 0u;
    label_000B548E:
    if (((*(uint32_t*)(cpu->esp + 0x90u)) & (6u)) != 0u) goto label_000B56DA;
    lift_push32(cpu, 0xAu);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B54BEu)); sfera_sub_004B2D70(cpu, LIFT_CODE_TOKEN_VA(0x4B54BEu));
    if (((*(uint32_t*)(cpu->eax + 0x74u)) & (6u)) != 0u) goto label_000B5658;
    label_000B54E0:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    if (cpu->esi < 2u) goto label_000B562C;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B54F4u)); sfera_sub_0048DBE0(cpu, LIFT_CODE_TOKEN_VA(0x4B54F4u));
    if (*(uint8_t*)(cpu->eax) != 0x4Du) goto label_000B562C;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5506u)); sfera_sub_0048DBE0(cpu, LIFT_CODE_TOKEN_VA(0x4B5506u));
    if (*(uint8_t*)(cpu->eax) != 0x41u) goto label_000B562C;
    cpu->ecx = cpu->esi + 0xFFFFFFFFu;
    if ((int32_t)cpu->ecx < (int32_t)cpu->ebx) goto label_000B562C;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x14u);
    label_000B5520:
    if (cpu->edx < 0x10u) goto label_000B5529;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000B552B;
    label_000B5529:
    cpu->eax = cpu->edi;
    label_000B552B:
    if (*(uint8_t*)(cpu->eax + cpu->ecx) == 0x2Eu) goto label_000B5539;
    if ((int32_t)(--cpu->ecx) >= 0) goto label_000B5520;
    goto label_000B562C;
    label_000B5539:
    cpu->ebp = cpu->ecx + 1u;
    label_000B5540:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_000B554C;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000B554E;
    label_000B554C:
    cpu->eax = cpu->edi;
    label_000B554E:
    if (*(uint8_t*)(cpu->eax + cpu->ebp) == 0x22u) goto label_000B5627;
    if (cpu->ecx < 0x10u) goto label_000B5561;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000B5563;
    label_000B5561:
    cpu->eax = cpu->edi;
    label_000B5563:
    cpu->ecx = *(uint8_t*)(cpu->eax + cpu->ebp);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xD0u;
    cpu->ecx = cpu->esp + 0x108u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B557Bu)); sfera_sub_004B3C10(cpu, LIFT_CODE_TOKEN_VA(0x4B557Bu));
    cpu->esi = cpu->eax;
    cpu->edx = cpu->esp + 0xCCu;
    if (cpu->edx == cpu->esi) goto label_000B55FF;
    if (*(uint32_t*)(cpu->esp + 0xE0u) < 0x10u) goto label_000B55A2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B559Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B559Fu));
    cpu->esp += 4u;
    label_000B55A2:
    *(uint32_t*)(cpu->esp + 0xE0u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xCCu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x14u) >= 0x10u) goto label_000B55DA;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xD0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4B55CFu));
    cpu->esp += 0xCu;
    goto label_000B55E5;
    label_000B55DA:
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0xCCu) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_000B55E5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    label_000B55FF:
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x118u) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x12Cu) = 3u;
    if (sub_pred[1]) goto label_000B5621;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x104u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B561Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B561Eu));
    cpu->esp += 4u;
    label_000B5621:
    ++cpu->ebp;
    goto label_000B5540;
    label_000B5627:
    cpu->ebp = 0xFu;
    label_000B562C:
    lift_push32(cpu, 0xAu);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5639u)); sfera_sub_004B2D70(cpu, LIFT_CODE_TOKEN_VA(0x4B5639u));
    if (((*(uint32_t*)(cpu->eax + 0x74u)) & (6u)) == 0u) goto label_000B54E0;
    label_000B5658:
    cpu->esi = cpu->esp + 0x2Cu;
    if (*(uint32_t*)(cpu->esp + 0x80u) == cpu->ebx) goto label_000B5687;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B566Cu)); sfera_sub_004B2AD0(cpu, LIFT_CODE_TOKEN_VA(0x4B566Cu));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000B5672;
    cpu->esi = 0u;
    label_000B5672:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4B567Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000B5689;
    label_000B5687:
    cpu->esi = 0u;
    label_000B5689:
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint8_t*)(cpu->esp + 0x7Cu) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x75u) = cpu->ebx & 0xFFu;
    cpu->edx = g_sfera_recovered_static_runtime.ui_counter_a;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    if (cpu->esi != cpu->ebx) goto label_000B56C8;
    *(uint32_t*)(cpu->esp + 0x90u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x90u)) | (uint64_t)(2u);
    label_000B56C8:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0xD4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB56DAu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xB56DAu));
    label_000B56DA:
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0xFCu) < cpu->esi) goto label_000B56F8;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B56F5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B56F5u));
    cpu->esp += 4u;
    label_000B56F8:
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0xFCu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xF8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xE8u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x12Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5721u)); sfera_sub_004B4CE0(cpu, LIFT_CODE_TOKEN_VA(0x4B5721u));
    if (*(uint32_t*)(cpu->esp + 0xE0u) < cpu->esi) goto label_000B5747;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5744u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5744u));
    cpu->esp += 4u;
    label_000B5747:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x11Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B57C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x19Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1B0u;
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x1BCu);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5820u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B5820u));
    if (*(uint32_t*)(cpu->eax) != cpu->esi) goto label_000B5CE8;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5833u)); sfera_sub_004B4C10(cpu, LIFT_CODE_TOKEN_VA(0x4B5833u));
    cpu->ebx = 0u;
    lift_push32(cpu, 0x12u);
    cpu->edi = 0xFu;
    lift_push32(cpu, (uintptr_t)"_hyperTextEdit.log");
    cpu->ecx = cpu->esp + 0x128u;
    *(uint32_t*)(cpu->esp + 0x1C0u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x13Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x138u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x128u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5869u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B5869u));
    cpu->edx = cpu->esp + 0xE8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esp + 0x1BCu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5880u)); sfera_sub_004B5350(cpu, LIFT_CODE_TOKEN_VA(0x4B5880u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x9Cu);
    sub_pred[0] = *(uint32_t*)(cpu->eax + 0x18Cu) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x1B8u) = 2u;
    if (sub_pred[0]) goto label_000B58A3;
    cpu->esi = *(uint32_t*)(cpu->eax + 0x178u);
    goto label_000B58A9;
    label_000B58A3:
    cpu->esi = cpu->eax + 0x178u;
    label_000B58A9:
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x114u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x104u) = cpu->ebx & 0xFFu;
    cpu->edi = cpu->eax + 1u;
    label_000B58C3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000B58C3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x10Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B58DAu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B58DAu));
    lift_push32(cpu, 8u);
    cpu->esi = 0xFu;
    lift_push32(cpu, (uintptr_t)"players\\");
    cpu->ecx = cpu->esp + 0xD4u;
    *(uint8_t*)(cpu->esp + 0x1C0u) = 3u;
    *(uint32_t*)(cpu->esp + 0xE8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xE4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xD4u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B590Fu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B590Fu));
    cpu->eax = cpu->esp + 0x104u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xD0u;
    cpu->ecx = cpu->esp + 0x178u;
    *(uint8_t*)(cpu->esp + 0x1BCu) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5932u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4B5932u));
    lift_push32(cpu, (uintptr_t)"_");
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x194u;
    *(uint8_t*)(cpu->esp + 0x1BCu) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B594Du)); sfera_sub_004903C0(cpu, LIFT_CODE_TOKEN_VA(0x4B594Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x15Cu;
    *(uint8_t*)(cpu->esp + 0x1BCu) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5968u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4B5968u));
    cpu->edx = cpu->esp + 0x120u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x140u;
    *(uint8_t*)(cpu->esp + 0x1BCu) = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5986u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4B5986u));
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x16Cu) < cpu->edi) goto label_000B59A4;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x158u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B59A1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B59A1u));
    cpu->esp += 4u;
    label_000B59A4:
    *(uint32_t*)(cpu->esp + 0x16Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x158u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1A4u) < cpu->edi) goto label_000B59D2;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x190u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B59CFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B59CFu));
    cpu->esp += 4u;
    label_000B59D2:
    *(uint32_t*)(cpu->esp + 0x1A4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1A0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x190u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x188u) < cpu->edi) goto label_000B5A00;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x174u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B59FDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B59FDu));
    cpu->esp += 4u;
    label_000B5A00:
    *(uint32_t*)(cpu->esp + 0x188u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x184u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x174u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0xE0u) < cpu->edi) goto label_000B5A2E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5A2Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5A2Bu));
    cpu->esp += 4u;
    label_000B5A2E:
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xCCu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x118u) < cpu->edi) goto label_000B5A5C;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x104u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5A59u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5A59u));
    cpu->esp += 4u;
    label_000B5A5C:
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x114u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x104u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0xFCu) < cpu->edi) goto label_000B5A8A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5A87u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5A87u));
    cpu->esp += 4u;
    label_000B5A8A:
    *(uint32_t*)(cpu->esp + 0xFCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xF8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xE8u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x1B8u) = 0xFu;
    if (*(uint32_t*)(cpu->esp + 0x134u) < cpu->edi) goto label_000B5AC0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x120u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5ABDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5ABDu));
    cpu->esp += 4u;
    label_000B5AC0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x13Cu);
    *(uint32_t*)(cpu->esp + 0x134u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x130u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x120u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x150u) >= cpu->edi) goto label_000B5AEC;
    cpu->eax = cpu->esp + 0x13Cu;
    label_000B5AEC:
    lift_push32(cpu, 0x40u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5AFAu)); sfera_sub_004B1830(cpu, LIFT_CODE_TOKEN_VA(0x4B5AFAu));
    if (cpu->eax != 0u) goto label_000B5B14;
    *(uint32_t*)(cpu->esp + 0x90u) = 2u;
    goto label_000B5B26;
    label_000B5B14:
    *(uint32_t*)(cpu->esp + 0x90u) = 0u;
    label_000B5B26:
    if (((*(uint32_t*)(cpu->esp + 0x90u)) & (6u)) != 0u) goto label_000B5C96;
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xCCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, 0xAu);
    cpu->edx = cpu->esp + 0xD0u;
    cpu->ecx = cpu->esp + 0x20u;
    *(uint8_t*)(cpu->esp + 0x1BCu) = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5B78u)); sfera_sub_004B2D70(cpu, LIFT_CODE_TOKEN_VA(0x4B5B78u));
    if (((*(uint32_t*)(cpu->eax + 0x74u)) & (6u)) != 0u) goto label_000B5C5F;
    label_000B5BA0:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1A8u);
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x1B4u)) goto label_000B5C5F;
    if (*(uint32_t*)(cpu->esp + 0xDCu) == cpu->ebx) goto label_000B5C30;
    cpu->ecx = cpu->esp + 0xCCu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xECu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5BD2u)); sfera_sub_004B4AB0(cpu, LIFT_CODE_TOKEN_VA(0x4B5BD2u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xD0u;
    *(uint8_t*)(cpu->esp + 0x1BCu) = 0x11u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5BE7u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4B5BE7u));
    *(uint8_t*)(cpu->esp + 0x1B8u) = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0xFCu) < cpu->edi) goto label_000B5C08;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5C05u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5C05u));
    cpu->esp += 4u;
    label_000B5C08:
    cpu->ecx = cpu->esp + 0xCCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x198u;
    *(uint32_t*)(cpu->esp + 0x100u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xFCu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xECu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB5C30u)); sfera_sub_004AF8A0(cpu, LIFT_CODE_TOKEN_RVA(0xB5C30u));
    label_000B5C30:
    lift_push32(cpu, 0xAu);
    cpu->edx = cpu->esp + 0xD0u;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5C42u)); sfera_sub_004B2D70(cpu, LIFT_CODE_TOKEN_VA(0x4B5C42u));
    if (((*(uint32_t*)(cpu->eax + 0x74u)) & (6u)) == 0u) goto label_000B5BA0;
    label_000B5C5F:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5C68u)); sfera_sub_004B3900(cpu, LIFT_CODE_TOKEN_VA(0x4B5C68u));
    if (*(uint32_t*)(cpu->esp + 0xE0u) < cpu->edi) goto label_000B5C81;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5C7Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5C7Eu));
    cpu->esp += 4u;
    label_000B5C81:
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xCCu) = cpu->ebx & 0xFFu;
    label_000B5C96:
    if (*(uint32_t*)(cpu->esp + 0x150u) < cpu->edi) goto label_000B5CAF;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x13Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5CACu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5CACu));
    cpu->esp += 4u;
    label_000B5CAF:
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x150u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x13Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x1B8u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5CDBu)); sfera_sub_004B4CE0(cpu, LIFT_CODE_TOKEN_VA(0x4B5CDBu));
    label_000B5CE8:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1A8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B5D10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1E8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1FCu;
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5D74u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B5D74u));
    if (*(uint32_t*)(cpu->eax) != cpu->edi) goto label_000B623D;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x1A8u) == cpu->ebx) goto label_000B623D;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5D95u)); sfera_sub_004B3970(cpu, LIFT_CODE_TOKEN_VA(0x4B5D95u));
    lift_push32(cpu, 0x12u);
    cpu->edi = 0xFu;
    lift_push32(cpu, (uintptr_t)"_hyperTextEdit.log");
    cpu->ecx = cpu->esp + 0xE8u;
    *(uint32_t*)(cpu->esp + 0x20Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xFCu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xF8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xE8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5DC9u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B5DC9u));
    cpu->edx = cpu->esp + 0x188u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x208u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5DE0u)); sfera_sub_004B5350(cpu, LIFT_CODE_TOKEN_VA(0x4B5DE0u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x9Cu);
    sub_pred[0] = *(uint32_t*)(cpu->eax + 0x18Cu) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x204u) = 2u;
    if (sub_pred[0]) goto label_000B5E03;
    cpu->esi = *(uint32_t*)(cpu->eax + 0x178u);
    goto label_000B5E09;
    label_000B5E03:
    cpu->esi = cpu->eax + 0x178u;
    label_000B5E09:
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x148u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x144u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x134u) = cpu->ebx & 0xFFu;
    cpu->ebp = cpu->eax + 1u;
    label_000B5E23:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000B5E23;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x13Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5E3Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B5E3Au));
    lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"players\\");
    cpu->ecx = cpu->esp + 0x120u;
    *(uint8_t*)(cpu->esp + 0x20Cu) = 3u;
    *(uint32_t*)(cpu->esp + 0x134u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x130u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x120u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5E6Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B5E6Au));
    cpu->eax = cpu->esp + 0x134u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x11Cu;
    cpu->ecx = cpu->esp + 0x1C4u;
    *(uint8_t*)(cpu->esp + 0x208u) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5E8Du)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4B5E8Du));
    lift_push32(cpu, (uintptr_t)"_");
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x170u;
    *(uint8_t*)(cpu->esp + 0x208u) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5EA8u)); sfera_sub_004903C0(cpu, LIFT_CODE_TOKEN_VA(0x4B5EA8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x1E0u;
    *(uint8_t*)(cpu->esp + 0x208u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5EC3u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4B5EC3u));
    cpu->edx = cpu->esp + 0xE0u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x154u;
    *(uint8_t*)(cpu->esp + 0x208u) = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5EE1u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4B5EE1u));
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x1F0u) < cpu->esi) goto label_000B5EFF;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1DCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5EFCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5EFCu));
    cpu->esp += 4u;
    label_000B5EFF:
    *(uint32_t*)(cpu->esp + 0x1F0u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1ECu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1DCu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x180u) < cpu->esi) goto label_000B5F2D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x16Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5F2Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5F2Au));
    cpu->esp += 4u;
    label_000B5F2D:
    *(uint32_t*)(cpu->esp + 0x180u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x17Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x16Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1D4u) < cpu->esi) goto label_000B5F5B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1C0u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5F58u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5F58u));
    cpu->esp += 4u;
    label_000B5F5B:
    *(uint32_t*)(cpu->esp + 0x1D4u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1D0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1C0u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x12Cu) < cpu->esi) goto label_000B5F89;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x118u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5F86u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5F86u));
    cpu->esp += 4u;
    label_000B5F89:
    *(uint32_t*)(cpu->esp + 0x12Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x128u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x118u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x148u) < cpu->esi) goto label_000B5FB7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x134u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5FB4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5FB4u));
    cpu->esp += 4u;
    label_000B5FB7:
    *(uint32_t*)(cpu->esp + 0x148u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x144u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x134u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x19Cu) < cpu->esi) goto label_000B5FE5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x188u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B5FE2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B5FE2u));
    cpu->esp += 4u;
    label_000B5FE5:
    *(uint32_t*)(cpu->esp + 0x19Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x198u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x188u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x204u) = 0xFu;
    if (*(uint32_t*)(cpu->esp + 0xF4u) < cpu->esi) goto label_000B601B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xE0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6018u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6018u));
    cpu->esp += 4u;
    label_000B601B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x150u);
    *(uint32_t*)(cpu->esp + 0xF4u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xF0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xE0u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x164u) >= cpu->esi) goto label_000B6047;
    cpu->eax = cpu->esp + 0x150u;
    label_000B6047:
    lift_push32(cpu, 0x40u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6055u)); sfera_sub_004B1830(cpu, LIFT_CODE_TOKEN_VA(0x4B6055u));
    if (cpu->eax != 0u) goto label_000B606F;
    *(uint32_t*)(cpu->esp + 0xA4u) = 2u;
    goto label_000B6081;
    label_000B606F:
    *(uint32_t*)(cpu->esp + 0xA4u) = 0u;
    label_000B6081:
    if (((*(uint32_t*)(cpu->esp + 0xA4u)) & (6u)) != 0u) goto label_000B61EB;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->esp + 0x20u;
    cpu->ebp += 0x198u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B60BAu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B60BAu));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B60C6u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B60C6u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != *(uint32_t*)(cpu->eax + 8u));
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000B61DD;
    label_000B60D8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax != cpu->ebx) goto label_000B60E4;
    cpu->ecx = 0u;
    goto label_000B60E6;
    label_000B60E4:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000B60E6:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->esi) goto label_000B60F1;
    cpu->eax -= cpu->edx;
    label_000B60F1:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x108u;
    *(uint32_t*)(cpu->esp + 0x11Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x108u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B611Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B611Cu));
    cpu->eax = cpu->esp + 0xFCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1A8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint8_t*)(cpu->esp + 0x20Cu) = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B613Du)); sfera_sub_004B4B60(cpu, LIFT_CODE_TOKEN_VA(0x4B613Du));
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x38u;
    *(uint8_t*)(cpu->esp + 0x204u) = 0x11u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6150u)); sfera_sub_004B1A80(cpu, LIFT_CODE_TOKEN_VA(0x4B6150u));
    cpu->edx = (uintptr_t)"\n";
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B615Cu)); sfera_sub_004B1CB0(cpu, LIFT_CODE_TOKEN_VA(0x4B615Cu));
    if (*(uint32_t*)(cpu->esp + 0x1B8u) < 0x10u) goto label_000B6176;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1A4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6173u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6173u));
    cpu->esp += 4u;
    label_000B6176:
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x110u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x1B8u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1B4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1A4u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x204u) = 0xFu;
    if (sub_pred[1]) goto label_000B61AD;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xFCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B61AAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B61AAu));
    cpu->esp += 4u;
    label_000B61AD:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x114u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x100u) = cpu->ebx & 0xFFu;
    ++cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B61CFu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B61CFu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != *(uint32_t*)(cpu->eax + 8u));
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000B60D8;
    label_000B61DD:
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B61E6u)); sfera_sub_004B3B00(cpu, LIFT_CODE_TOKEN_VA(0x4B61E6u));
    cpu->esi = 0x10u;
    label_000B61EB:
    if (*(uint32_t*)(cpu->esp + 0x164u) < cpu->esi) goto label_000B6204;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x150u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6201u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6201u));
    cpu->esp += 4u;
    label_000B6204:
    cpu->ecx = cpu->esp + 0x38u;
    *(uint32_t*)(cpu->esp + 0x164u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x160u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x150u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x204u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6230u)); sfera_sub_004B3A40(cpu, LIFT_CODE_TOKEN_VA(0x4B6230u));
    label_000B623D:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1F4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B6270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    lift_push32(cpu, 1u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B628Au)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4B628Au));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == 0u) goto label_000B62B2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_000B62B2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000B62B2:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B62C5u)); sfera_sub_004AFE60(cpu, LIFT_CODE_TOKEN_VA(0x4B62C5u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B62D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1Cu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::HyperTextEditControl*>(cpu->esi));
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x4Bu) == 1u;
    *(uint32_t*)(cpu->esp + 0x24u) = 5u;
    if (!sub_pred[0]) goto label_000B6315;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB6315u)); sfera_sub_004B5D10(cpu, LIFT_CODE_TOKEN_RVA(0xB6315u));
    label_000B6315:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B631Cu)); sfera_sub_004B3110(cpu, LIFT_CODE_TOKEN_VA(0x4B631Cu));
    cpu->ebx = 0u;
    cpu->ecx = cpu->esi + 0x200u;
    g_sfera_texture_cache_runtime.render_gate = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B632Fu)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B632Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x200u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B633Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B633Bu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x200u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esi + 0x1F8u) < 0x10u) goto label_000B635C;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1E4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6359u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6359u));
    cpu->esp += 4u;
    label_000B635C:
    cpu->edi = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1F8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1F4u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1E4u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x1DCu) < 0x10u) goto label_000B638B;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6388u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6388u));
    cpu->esp += 4u;
    label_000B638B:
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->edi;
    cpu->edi = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1C8u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x30u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B63BFu)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4B63BFu));
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B63C8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B63C8u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B63D6u)); sfera_sub_004AF470(cpu, LIFT_CODE_TOKEN_VA(0x4B63D6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B63E2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B63E2u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B63FAu)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4B63FAu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B6410(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[5];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x190u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1B4u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1BCu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1B8u);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    if (*(uint32_t*)(cpu->esi + 0x9Cu) != cpu->ebx) goto label_000B6492;
    lift_push32(cpu, 0x2Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6489u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6489u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B648Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B648Fu));
    cpu->esp += 0x10u;
    label_000B6492:
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B649Eu)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4B649Eu));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B64ABu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B64ABu));
    if (cpu->eax == 0u) goto label_000B652C;
    cpu->esi = native_function_address32(&::sscanf);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xB64CDu));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000B6502;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"textColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B64F9u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B64F9u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B64FFu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B64FFu));
    cpu->esp += 0x1Cu;
    label_000B6502:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x20u);
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->edx + 0x23Cu) = cpu->ecx;
    goto label_000B653C;
    label_000B652C:
    *(uint32_t*)(cpu->esi + 0x23Cu) = 0xFFFFFFFFu;
    cpu->esi = native_function_address32(&::sscanf);
    label_000B653C:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"cursorColor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6549u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B6549u));
    if (cpu->eax == 0u) goto label_000B65C5;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xB6565u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000B659B;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"cursorColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6592u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6592u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6598u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B6598u));
    cpu->esp += 0x1Cu;
    label_000B659B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x20u);
    cpu->edx|=0xFFFFFF00u;
    cpu->edx <<= 8u;
    cpu->edx|=cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx <<= 8u;
    cpu->edx |= cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x238u) = cpu->edx;
    goto label_000B65D3;
    label_000B65C5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ecx + 0x238u) = 0xFFFFFFFFu;
    label_000B65D3:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"linkColor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B65E0u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B65E0u));
    if (cpu->eax == 0u) goto label_000B665B;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xB65FCu));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000B6631;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"linkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6628u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6628u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B662Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B662Eu));
    cpu->esp += 0x1Cu;
    label_000B6631:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x20u);
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->edx + 0x248u) = cpu->ecx;
    goto label_000B6686;
    label_000B665B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"%s(): HyperTextEdit control must have '%s' parameter in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"linkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B667Du)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B667Du));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6683u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B6683u));
    cpu->esp += 0x1Cu;
    label_000B6686:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"playerLinkColor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6693u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B6693u));
    if (cpu->eax == 0u) goto label_000B670E;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xB66AFu));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000B66E5;
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"playerLinkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B66DCu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B66DCu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B66E2u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B66E2u));
    cpu->esp += 0x1Cu;
    label_000B66E5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x20u);
    cpu->eax|=0xFFFFFF00u;
    cpu->eax <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax <<= 8u;
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x240u) = cpu->eax;
    goto label_000B671E;
    label_000B670E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x248u);
    *(uint32_t*)(cpu->eax + 0x240u) = cpu->edx;
    label_000B671E:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"itemLinkColor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B672Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B672Bu));
    if (cpu->eax == 0u) goto label_000B67A7;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xB6747u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000B677D;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"itemLinkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6774u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6774u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B677Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B677Au));
    cpu->esp += 0x1Cu;
    label_000B677D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x20u);
    cpu->edx|=0xFFFFFF00u;
    cpu->edx <<= 8u;
    cpu->edx|=cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx <<= 8u;
    cpu->edx |= cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x244u) = cpu->edx;
    goto label_000B67B7;
    label_000B67A7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x248u);
    *(uint32_t*)(cpu->eax + 0x244u) = cpu->ecx;
    label_000B67B7:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"maxVisibleTextLength");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B67C4u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B67C4u));
    cpu->esi = 0x100u;
    if (cpu->eax == 0u) goto label_000B67E1;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B67D5u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4B67D5u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edx + 0x24Cu) = cpu->eax;
    goto label_000B67EB;
    label_000B67E1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax + 0x24Cu) = cpu->esi;
    label_000B67EB:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"maxHyperTextLength");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B67F8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B67F8u));
    if (cpu->eax == 0u) goto label_000B6810;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6804u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4B6804u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ecx + 0x250u) = cpu->eax;
    goto label_000B681E;
    label_000B6810:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edx + 0x250u) = 0xC00u;
    label_000B681E:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"maxHistoryLength");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B682Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B682Bu));
    if (cpu->eax == 0u) goto label_000B6843;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6837u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4B6837u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ecx + 0x1B4u) = cpu->eax;
    goto label_000B684D;
    label_000B6843:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edx + 0x1B4u) = cpu->esi;
    label_000B684D:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"cursorType");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B685Au)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B685Au));
    cpu->ebp = 0xFu;
    if (cpu->eax == 0u) goto label_000B6A17;
    cpu->eax = cpu->esp + 0xA0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6877u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4B6877u));
    if (cpu->eax == 0u) goto label_000B6A17;
    cpu->eax = cpu->esp + 0xA0u;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x84u) = cpu->ebx & 0xFFu;
    cpu->edx = cpu->eax + 1u;
    label_000B68A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000B68A0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xA4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x8Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B68BEu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B68BEu));
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"none");
    cpu->ecx = cpu->esp + 0x70u;
    *(uint32_t*)(cpu->esp + 0x1B4u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x70u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B68E7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B68E7u));
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x84u;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B68FFu)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x4B68FFu));
    cpu->esi = 0x10u;
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x1ACu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x7Cu) < cpu->esi) goto label_000B6922;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B691Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B691Fu));
    cpu->esp += 4u;
    label_000B6922:
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_000B6937;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0x218u) = cpu->ebx;
    goto label_000B69F0;
    label_000B6937:
    lift_push32(cpu, 5u); lift_push32(cpu, (uintptr_t)"vline");
    cpu->ecx = cpu->esp + 0x70u;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x70u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6959u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B6959u));
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x84u;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6971u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x4B6971u));
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x1ACu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x7Cu) < cpu->esi) goto label_000B698F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B698Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B698Cu));
    cpu->esp += 4u;
    label_000B698F:
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_000B69A7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ecx + 0x218u) = 1u;
    cpu->esi = cpu->ecx;
    goto label_000B69F0;
    label_000B69A7:
    lift_push32(cpu, (uintptr_t)"uline");
    cpu->ecx = cpu->esp + 0x6Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B69B5u)); sfera_sub_004090F0(cpu, LIFT_CODE_TOKEN_VA(0x4B69B5u));
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x84u;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B69CDu)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x4B69CDu));
    cpu->ecx = cpu->esp + 0x68u;
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B69DAu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4B69DAu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = 0u;
    cpu->esi = cpu->eax;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x17u) != (uint8_t)(cpu->ebx));
    ++cpu->edx;
    *(uint32_t*)(cpu->eax + 0x218u) = cpu->edx;
    label_000B69F0:
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x98u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x1ACu) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_000B6A27;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6A12u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6A12u));
    cpu->esp += 4u;
    goto label_000B6A27;
    label_000B6A17:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edx + 0x218u) = 1u;
    cpu->esi = cpu->edx;
    label_000B6A27:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"editMode");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6A38u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B6A38u));
    if (cpu->eax == 0u) goto label_000B6CC3;
    cpu->ecx = cpu->esp + 0xA0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6A54u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4B6A54u));
    if (cpu->eax == 0u) goto label_000B6CC3;
    label_000B6A60:
    cpu->eax = cpu->esp + 0xA0u;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x84u) = cpu->ebx & 0xFFu;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_000B6A80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000B6A80;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xA4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x8Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6A9Eu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B6A9Eu));
    lift_push32(cpu, 0xEu); lift_push32(cpu, (uintptr_t)"enterPlainText");
    cpu->ecx = cpu->esp + 0x70u;
    *(uint32_t*)(cpu->esp + 0x1B4u) = 4u;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x70u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6ACBu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B6ACBu));
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x84u;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6AE3u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x4B6AE3u));
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x7Cu) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 4u;
    if (sub_pred[1]) goto label_000B6B03;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6B00u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6B00u));
    cpu->esp += 4u;
    label_000B6B03:
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_000B6B2F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6B1Eu)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B6B1Eu));
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x1B8u;
    goto label_000B6C74;
    label_000B6B2F:
    lift_push32(cpu, 0xBu); lift_push32(cpu, (uintptr_t)"numbersOnly");
    cpu->ecx = cpu->esp + 0x70u;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x70u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6B51u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B6B51u));
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x84u;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6B69u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x4B6B69u));
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x7Cu) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 4u;
    if (sub_pred[2]) goto label_000B6B89;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6B86u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6B86u));
    cpu->esp += 4u;
    label_000B6B89:
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_000B6BD3;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x20u;
    cpu->esi += 0x1B8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6BA6u)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B6BA6u));
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6BB3u)); sfera_sub_004043F0(cpu, LIFT_CODE_TOKEN_VA(0x4B6BB3u));
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6BC8u)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B6BC8u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->ecx);
    goto label_000B6C72;
    label_000B6BD3:
    lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"password");
    cpu->ecx = cpu->esp + 0x70u;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x70u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6BF5u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4B6BF5u));
    cpu->edx = cpu->esp + 0x68u;
    cpu->ecx = cpu->esp + 0x84u;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6C0Du)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x4B6C0Du));
    sub_pred[3] = *(uint32_t*)(cpu->esp + 0x7Cu) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x1ACu) = 4u;
    if (sub_pred[3]) goto label_000B6C2D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6C2Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6C2Au));
    cpu->esp += 4u;
    label_000B6C2D:
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_000B6C7D;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x20u;
    cpu->esi += 0x1B8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6C4Au)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B6C4Au));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6C57u)); sfera_sub_004043F0(cpu, LIFT_CODE_TOKEN_VA(0x4B6C57u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6C6Cu)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B6C6Cu));
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    label_000B6C72:
    cpu->ecx = cpu->esi;
    label_000B6C74:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6C79u)); sfera_sub_004043F0(cpu, LIFT_CODE_TOKEN_VA(0x4B6C79u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000B6C7D:
    sub_pred[4] = *(uint32_t*)(cpu->esp + 0x98u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x1ACu) = 0xFFFFFFFFu;
    if (sub_pred[4]) goto label_000B6CA2;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6C9Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6C9Fu));
    cpu->esp += 4u;
    label_000B6CA2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = cpu->esp + 0xA0u;
    ++cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6CBBu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4B6CBBu));
    if (cpu->eax != 0u) goto label_000B6A60;
    label_000B6CC3:
    if (*(uint32_t*)(cpu->esi + 0x1C0u) != cpu->ebx) goto label_000B6CF5;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6CE0u)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B6CE0u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6CF1u)); sfera_sub_004043F0(cpu, LIFT_CODE_TOKEN_VA(0x4B6CF1u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000B6CF5:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"titleTextMargin");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6D06u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B6D06u));
    if (cpu->eax == 0u) goto label_000B6D6B;
    cpu->edx = cpu->esi + 0x234u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x230u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x22Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x228u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4B6D2Fu));
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000B6D83;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"visibleTextMargin"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6D60u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6D60u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6D66u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B6D66u));
    cpu->esp += 0x1Cu;
    goto label_000B6D83;
    label_000B6D6B:
    *(uint32_t*)(cpu->esi + 0x228u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x22Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x230u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x234u) = cpu->ebx;
    label_000B6D83:
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6D8Fu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4B6D8Fu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6D96u)); sfera_sub_004B57C0(cpu, LIFT_CODE_TOKEN_VA(0x4B6D96u));
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x19Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B6DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = 0x1DB3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6E09u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4B6E09u));
    if (*(uint32_t*)(cpu->esi + 0x1F4u) == 0u) goto label_000B6EFC;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esp + 0x18u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6E39u)); sfera_sub_004B2440(cpu, LIFT_CODE_TOKEN_VA(0x4B6E39u));
    if (*(uint32_t*)(cpu->eax) != cpu->edi) goto label_000B6EFC;
    if (*(uint32_t*)(cpu->esi + 0x1A8u) == 0u) goto label_000B6EDE;
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6E63u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6E63u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6E78u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4B6E78u));
    cpu->edx = cpu->esi + 0x1E4u;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6E87u)); sfera_sub_004B25C0(cpu, LIFT_CODE_TOKEN_VA(0x4B6E87u));
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6E97u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6E97u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_000B6EBB;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A8u);
    if (cpu->edx != *(uint32_t*)(cpu->esi + 0x1B4u)) goto label_000B6EDE;
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6EB9u)); sfera_sub_004AF510(cpu, LIFT_CODE_TOKEN_VA(0x4B6EB9u));
    goto label_000B6EDE;
    label_000B6EBB:
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6ECEu)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x4B6ECEu));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB6EDEu)); sfera_sub_004B6270(cpu, LIFT_CODE_TOKEN_RVA(0xB6EDEu));
    label_000B6EDE:
    cpu->edx = cpu->esi + 0x1E4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6EF0u)); sfera_sub_004AF8A0(cpu, LIFT_CODE_TOKEN_VA(0x4B6EF0u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    label_000B6EFC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B6F10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6F18u)); sfera_sub_004B62D0(cpu, LIFT_CODE_TOKEN_VA(0x4B6F18u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000B6F28;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6F25u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B6F25u));
    cpu->esp += 4u;
    label_000B6F28:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B6F30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x48u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000B7254;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6F7Cu)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4B6F7Cu));
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->edx = 0u;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000B6FB6;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B6FB1u)); sfera_sub_004A8A30(cpu, LIFT_CODE_TOKEN_VA(0x4B6FB1u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    label_000B6FB6:
    cpu->eax += *(uint32_t*)(cpu->edi + 0x34u);
    cpu->edx += *(uint32_t*)(cpu->edi + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebp = cpu->eax;
    cpu->ebp += *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esi + 0x278u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edi += cpu->edx;
    *(uint32_t*)(cpu->esi + 0x274u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    cpu->eax = cpu->edx + cpu->ebp + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x4Au));
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B70B3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 0x14u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B708F;
    if (*(uint8_t*)(cpu->ecx + 0x15u) != 0u) goto label_000B708F;
    cpu->eax = cpu->eax & 0xFFu;
    cpu->eax += 0xFFFFFFF8u;
    if (cpu->eax > 0xB3u) goto label_000B709F;
    switch (cpu->eax) {
        case 0u: goto label_000B702F;
        case 5u: goto label_000B7077;
        case 27u: goto label_000B706E;
        case 28u: goto label_000B7065;
        case 29u: goto label_000B7041;
        case 30u: goto label_000B7053;
        case 31u: goto label_000B704A;
        case 32u: goto label_000B705C;
        case 37u: goto label_000B7080;
        case 38u: goto label_000B7038;
        case 179u: goto label_000B702B;
        default: goto label_000B709F;
    }
label_000B702B: ;
    lift_push32(cpu, 0x3Du);
    goto label_000B7098;
    label_000B702F:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7036u)); sfera_sub_004B3F60(cpu, LIFT_CODE_TOKEN_VA(0x4B7036u));
    goto label_000B709F;
    label_000B7038:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B703Fu)); sfera_sub_004B4060(cpu, LIFT_CODE_TOKEN_VA(0x4B703Fu));
    goto label_000B709F;
    label_000B7041:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7048u)); sfera_sub_004B40D0(cpu, LIFT_CODE_TOKEN_VA(0x4B7048u));
    goto label_000B709F;
    label_000B704A:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7051u)); sfera_sub_004B4100(cpu, LIFT_CODE_TOKEN_VA(0x4B7051u));
    goto label_000B709F;
    label_000B7053:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B705Au)); sfera_sub_004B4FB0(cpu, LIFT_CODE_TOKEN_VA(0x4B705Au));
    goto label_000B709F;
    label_000B705C:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7063u)); sfera_sub_004B5020(cpu, LIFT_CODE_TOKEN_VA(0x4B7063u));
    goto label_000B709F;
    label_000B7065:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B706Cu)); sfera_sub_004B4140(cpu, LIFT_CODE_TOKEN_VA(0x4B706Cu));
    goto label_000B709F;
    label_000B706E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7075u)); sfera_sub_004B4180(cpu, LIFT_CODE_TOKEN_VA(0x4B7075u));
    goto label_000B709F;
    label_000B7077:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B707Eu)); sfera_sub_004B6DD0(cpu, LIFT_CODE_TOKEN_VA(0x4B707Eu));
    goto label_000B709F;
    label_000B7080:
    if (((*(uint8_t*)(cpu->ecx + 0x18u)) & (3u)) == 0u) goto label_000B709F;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B708Du)); sfera_sub_004B5090(cpu, LIFT_CODE_TOKEN_VA(0x4B708Du));
    goto label_000B709F;
    label_000B708F:
    cpu->eax = *(uint8_t*)(cpu->ecx + 0x15u);
    if ((cpu->eax & 0xFFu) < 0x20u) goto label_000B709F;
    lift_push32(cpu, cpu->eax);
    label_000B7098:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB709Fu)); sfera_sub_004B3D40(cpu, LIFT_CODE_TOKEN_RVA(0xB709Fu));
    label_000B709F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint16_t*)(cpu->eax + 0x14u) = 0u;
    g_sfera_texture_cache_runtime.render_gate = 1u;
    label_000B70B3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (((*(uint8_t*)(cpu->eax + 0xCu)) & (1u)) == 0u) goto label_000B7254;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_000B724A;
    if ((int32_t)cpu->ebx > (int32_t)*(uint32_t*)(cpu->esp + 0x28u)) goto label_000B724A;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) < (int32_t)cpu->ebp) goto label_000B724A;
    if ((int32_t)cpu->ebx > (int32_t)*(uint32_t*)(cpu->esp + 0x2Cu)) goto label_000B724A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x4Au));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000B712E;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7102u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4B7102u));
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7116u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4B7116u));
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B712Au)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4B712Au));
    *(uint8_t*)(cpu->esi + 0x4Au) = 1u;
    label_000B712E:
    if (*(uint32_t*)(cpu->esi + 0x1D8u) == 0u) goto label_000B7254;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x254u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x258u);
    cpu->ecx -= cpu->eax;
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x1C8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B715Cu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4B715Cu));
    cpu->ebx -= *(uint32_t*)(cpu->esi + 0x228u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, 0u);
    cpu->ebx -= cpu->edi;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx -= 2u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x74u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7182u)); sfera_sub_004B1F00(cpu, LIFT_CODE_TOKEN_VA(0x4B7182u));
    cpu->eax += *(uint32_t*)(cpu->esi + 0x254u);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esi + 0x21Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x64u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B719Fu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4B719Fu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (((*(uint8_t*)(cpu->edx + 0x18u)) & (1u)) == 0u) goto label_000B7254;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x21Cu);
    cpu->edx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B71C8u)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4B71C8u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B7254;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != 0xFFFFFFFFu) goto label_000B71E4;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x210u);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000B71E4:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B71F0u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4B71F0u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if (cpu->eax != 5u) goto label_000B7254;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B720Du)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4B720Du));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7219u)); sfera_sub_00431680(cpu, LIFT_CODE_TOKEN_VA(0x4B7219u));
    sub_pred[0] = *(uint32_t*)(cpu->eax + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x64u) = 1u;
    if (sub_pred[0]) goto label_000B7229;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B7229:
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7238u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x4B7238u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B723Fu)); sfera_sub_004A2670(cpu, LIFT_CODE_TOKEN_VA(0x4B723Fu));
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7248u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4B7248u));
    goto label_000B7254;
    label_000B724A:
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000B7254;
    *(uint8_t*)(cpu->esi + 0x4Au) = 0u;
    label_000B7254:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7360(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7370u)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4B7370u));
    cpu->eax = cpu->edi + 0x198u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7382u)); sfera_sub_004B0EE0(cpu, LIFT_CODE_TOKEN_VA(0x4B7382u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B0u);
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B4u);
    cpu->ebp = cpu->edi + 0x1B8u;
    cpu->ebx = cpu->esi + 0x1B8u;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edx;
    if (cpu->ebx == cpu->ebp) goto label_000B73C5;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B73BDu)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4B73BDu));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB73C5u)); sfera_sub_004B2CF0(cpu, LIFT_CODE_TOKEN_RVA(0xB73C5u));
    label_000B73C5:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi + 0x1C8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1C8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B73DBu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B73DBu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->edx = cpu->edi + 0x1E4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x1E4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B73F1u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B73F1u));
    cpu->eax = cpu->edi + 0x200u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7403u)); sfera_sub_004AADE0(cpu, LIFT_CODE_TOKEN_VA(0x4B7403u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x218u);
    *(uint32_t*)(cpu->esi + 0x218u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x21Cu);
    *(uint32_t*)(cpu->esi + 0x21Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x220u);
    *(uint32_t*)(cpu->esi + 0x220u) = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x224u));
    *(uint8_t*)(cpu->esi + 0x224u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x228u);
    *(uint32_t*)(cpu->esi + 0x228u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x22Cu);
    *(uint32_t*)(cpu->esi + 0x22Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x230u);
    *(uint32_t*)(cpu->esi + 0x230u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x234u);
    *(uint32_t*)(cpu->esi + 0x234u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x238u);
    *(uint32_t*)(cpu->esi + 0x238u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x23Cu);
    *(uint32_t*)(cpu->esi + 0x23Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x240u);
    *(uint32_t*)(cpu->esi + 0x240u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x244u);
    *(uint32_t*)(cpu->esi + 0x244u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x248u);
    *(uint32_t*)(cpu->esi + 0x248u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x24Cu);
    *(uint32_t*)(cpu->esi + 0x24Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x250u);
    *(uint32_t*)(cpu->esi + 0x250u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x254u);
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x258u);
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x25Cu);
    *(uint32_t*)(cpu->esi + 0x25Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x260u);
    *(uint32_t*)(cpu->esi + 0x260u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x264u);
    *(uint32_t*)(cpu->esi + 0x264u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x268u);
    *(uint32_t*)(cpu->esi + 0x268u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x26Cu);
    *(uint32_t*)(cpu->esi + 0x26Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x270u);
    *(uint32_t*)(cpu->esi + 0x270u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x274u);
    *(uint32_t*)(cpu->esi + 0x274u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x278u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x278u) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x34u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7571u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4B7571u));
    cpu->ebx = 0u;
    cpu->edi = cpu->esi + 0x198u;
    std::construct_at(reinterpret_cast<SphereUI::HyperTextEditControl*>(cpu->esi));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x40u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7595u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B7595u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B76F5;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    lift_push32(cpu, 0x14u);
    *(uint8_t*)(cpu->esp + 0x40u) = 2u;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B75CDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B75CDu));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B76CB;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint8_t*)(cpu->ecx + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1BCu);
    *(uint8_t*)(cpu->edx + 0x11u) = 1u;
    cpu->eax = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1C8u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1F8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1F4u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1E4u) = cpu->ebx & 0xFFu;
    cpu->edi = cpu->esi + 0x200u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x40u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7647u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B7647u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000B76A1;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x40u) = 7u;
    *(uint32_t*)(cpu->esi + 0x254u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x258u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7686u)); sfera_sub_004B7360(cpu, LIFT_CODE_TOKEN_VA(0x4B7686u));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B76A1:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB76CBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xB76CBu));
    label_000B76CB:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB76F5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xB76F5u));
    label_000B76F5:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B771Fu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B771Fu));
    lift_trap(cpu, 0x4B771Fu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004B7720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    cpu->edx = 0x24u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7753u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B7753u));
    lift_push32(cpu, 0x280u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B775Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B775Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_000B7789;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7778u)); sfera_sub_004B7540(cpu, LIFT_CODE_TOKEN_VA(0x4B7778u));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B7789:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B77A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B77A8u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4B77A8u));
    x87_v0 = 0.0;
    cpu->eax = 0u;
    *(float*)(cpu->esi + 0x1A8u) = x87_v0; 
    x87_v0 = 1.0;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x19Cu) = cpu->eax & 0xFFu;
    *(float*)(cpu->esi + 0x1B0u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1A4u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::ImageCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0xFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 3u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B77F0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7809u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4B7809u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebp = 0u;
    lift_push32(cpu, (uintptr_t)"image");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x194u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7822u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B7822u));
    if (cpu->eax == 0u) goto label_000B7875;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7833u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4B7833u));
    if (cpu->eax == 0u) goto label_000B7875;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7847u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4B7847u));
    *(uint32_t*)(cpu->edi + 0x194u) = cpu->eax;
    if (cpu->eax != cpu->ebp) goto label_000B7875;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ImageCtrl::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B786Cu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B786Cu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7872u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B7872u));
    cpu->esp += 0x18u;
label_000B7875:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"alpha");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7882u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B7882u));
    if (cpu->eax == 0u) goto label_000B7894;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B788Eu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4B788Eu));
    *(uint32_t*)(cpu->edi + 0x1ACu) = cpu->eax;
label_000B7894:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"imageStyle");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B78A1u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B78A1u));
    if (cpu->eax == 0u) goto label_000B7917;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x198u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B78B2u)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4B78B2u));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebp) goto label_000B7917;
    cpu->ebx = native_function_address32(&::_stricmp);
label_000B78C0:
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B78CDu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4B78CDu));
    if (cpu->eax == 0u) goto label_000B790A;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))((uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0], (uintptr_t)"NOTIFY_LB");

    if (cpu->eax != 0u) goto label_000B78EB;
    cpu->eax = 1u;
    goto label_000B7904;
label_000B78EB:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))((uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0], (uintptr_t)"NOTIFY_FOCUS");

    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xFFFFFFFEu;
    cpu->eax += 2u;
label_000B7904:
    *(uint32_t*)(cpu->edi + 0x198u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x198u)) | (uint64_t)(cpu->eax);
label_000B790A:
    cpu->ebp += 2u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_000B78C0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
label_000B7917:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"rotate");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7924u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4B7924u));
    if (cpu->eax == 0u) goto label_000B794A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7931u)); value_0 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4B7931u));
    *(float*)(cpu->esp + 0x24u) = value_0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xA2Au);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::ImageCtrl*>(cpu->edi)->handleMessage(cpu);
label_000B794A:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7956u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4B7956u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7970(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000B7AE7;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == 0u) goto label_000B79BE;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000B79B0;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB79B0u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xB79B0u));
    label_000B79B0:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000B79BE:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    if (cpu->ecx==0u) goto label_000B7AE7;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    if (*(uint8_t*)(cpu->esi + 0x1A4u) != 0u) goto label_000B7A7A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu))));
    if ((int32_t)cpu->ecx >= 0) goto label_000B7A22;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000B7A22:
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    x87_v2 = x87_v1;
    cpu->esp -= 0x10u;
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x18u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u))));
    if ((int32_t)cpu->edx >= 0) goto label_000B7A4B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000B7A4B:
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    x87_v3 = x87_v2;
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v2; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x18u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v1; 
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7A75u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_VA(0x4B7A75u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B7A7A:
    x87_v0 = (double)*(float*)(cpu->esi + 0x1A8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp -= 0x14u;
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu))));
    if ((int32_t)cpu->eax >= 0) goto label_000B7A97;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000B7A97:
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    x87_v2 = x87_v1;
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u))));
    if ((int32_t)cpu->ecx >= 0) goto label_000B7ABD;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000B7ABD:
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    x87_v3 = x87_v2;
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v2; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x1Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v1; 
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB7AE7u)); sfera_sub_004CEE60(cpu, LIFT_CODE_TOKEN_RVA(0xB7AE7u));
    label_000B7AE7:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2Cu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x198u) == cpu->edi) goto label_000B7C88;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->ebx == cpu->edi) goto label_000B7B5A;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_000B7B4C;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7B48u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_VA(0x4B7B48u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000B7B4C:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000B7B5A:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ebp += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_000B7C4B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx += cpu->edi;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000B7C4B;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ebp) goto label_000B7C4B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx += cpu->ebp;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000B7C4B;
    if (*(uint8_t*)(cpu->esi + 0x19Cu) != 0u) goto label_000B7BD3;
    if (((*(uint8_t*)(cpu->esi + 0x198u)) & (2u)) == 0u) goto label_000B7BD3;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x67u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7BC8u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4B7BC8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->esi + 0x19Cu) = 1u;
    label_000B7BD3:
    if (((*(uint8_t*)(cpu->edx + 0xCu)) & (1u)) == 0u) goto label_000B7C86;
    if (((*(uint8_t*)(cpu->esi + 0x198u)) & (1u)) == 0u) goto label_000B7C86;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx -= cpu->ebp;
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->eax -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x3E9u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7C21u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4B7C21u));
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000B7C86;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_click.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7C36u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_VA(0x4B7C36u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B7C4B:
    if (*(uint8_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000B7C86;
    if (((*(uint8_t*)(cpu->esi + 0x198u)) & (2u)) == 0u) goto label_000B7C86;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x68u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7C7Fu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4B7C7Fu));
    *(uint8_t*)(cpu->esi + 0x19Cu) = 0u;
    label_000B7C86:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B7C88:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7CA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->edi != 0u) goto label_000B7CE6;
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B7CE6:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x194u);
    if (cpu->eax == 0u) goto label_000B7D05;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4B7CF4u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000B7DA4;
    label_000B7D05:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esi + 0x194u) = 0u;
    if (cpu->ecx == 0u) goto label_000B7D25;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7D1Fu)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4B7D1Fu));
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->eax;
    label_000B7D25:
    if (*(uint32_t*)(cpu->esi + 0x194u) != 0u) goto label_000B7DA4;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7D35u)); sfera_sub_004B8360(cpu, LIFT_CODE_TOKEN_VA(0x4B7D35u));
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000B7DA4;
    if (*(uint32_t*)(cpu->esi + 0x1A0u) != cpu->eax) goto label_000B7D8C;
    cpu->edx = 0x123u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ImageCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7D56u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B7D56u));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7D60u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B7D60u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_000B7D7C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7D7Au)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4B7D7Au));
    goto label_000B7D7E;
    label_000B7D7C:
    cpu->eax = 0u;
    label_000B7D7E:
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    label_000B7D8C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7D98u)); sfera_sub_004CF1F0(cpu, LIFT_CODE_TOKEN_VA(0x4B7D98u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->eax;
    label_000B7DA4:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7DC0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xA4u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xB4u);
    cpu->eax = cpu->ecx + 0xFFFFF5D7u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edi;
    if (cpu->eax > 3u) goto label_000B7ECE;
    switch (cpu->eax) {
        case 0u: goto label_000B7E12;
        case 1u: goto label_000B7E5C;
        case 2u: goto label_000B7E00;
        case 3u: goto label_000B7E9C;
        default: lift_trap(cpu, 0x4B7DF9u, "resolved jump-table index out of range"); return;
    }
label_000B7E00: ;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7E08u)); sfera_sub_004B7CA0(cpu, LIFT_CODE_TOKEN_VA(0x4B7E08u));
    cpu->eax = 1u;
    goto label_000B7EDF;
    label_000B7E12:
    if (cpu->edi != 0u) goto label_000B7E24;
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->edi;
    cpu->eax = cpu->edi + 1u;
    goto label_000B7EDF;
    label_000B7E24:
    lift_push32(cpu, 0x9Cu);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4B7E30u));
    lift_push32(cpu, 0x40u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4B7E3Du));
    cpu->esp += 0x18u;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7E52u)); sfera_sub_004B7CA0(cpu, LIFT_CODE_TOKEN_VA(0x4B7E52u));
    cpu->eax = 1u;
    goto label_000B7EDF;
    label_000B7E5C:
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esi + 0x1A8u) = x87_v0;
    { const double lift_right=x87_v0; const double lift_left=0.0; if (lift_left!=lift_right) goto label_000B7E7C; }
    *(uint8_t*)(cpu->esi + 0x1A4u) = 0u;
    goto label_000B7E83;
    label_000B7E7C:
    *(uint8_t*)(cpu->esi + 0x1A4u) = 1u;
    label_000B7E83:
    x87_v0 = (x87_v0) / (180.0);
    cpu->eax = 1u;
    x87_v0 = (x87_v0) * (3.1415929794311523);
    *(float*)(cpu->esi + 0x1A8u) = x87_v0; 
    goto label_000B7EDF;
    label_000B7E9C:
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edi;
    if (cpu->edi <= 0xFFu) goto label_000B7EB4;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0xFFu;
    label_000B7EB4:
    x87_v0 = (double)*(float*)(cpu->esi + 0x1B0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    reinterpret_cast<SphereUI::ImageCtrl*>(cpu->esi)->setOpacity(cpu);
    cpu->eax = 1u;
    goto label_000B7EDF;
    label_000B7ECE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB7EDFu)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_RVA(0xB7EDFu));
    label_000B7EDF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xA4u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7F10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1ACu);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->ecx + 0x1ACu))));
    cpu->esp -= 8u;
    if ((int32_t)cpu->eax >= 0) goto label_000B7F29;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000B7F29:
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint64_t*)(cpu->esp) = static_cast<int64_t>(std::trunc(x87_v1));
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx&=0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0xDCu) = cpu->eax;
    cpu->eax <<= 24u;
    cpu->edx |= cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x90u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->eax;
    *(float*)(cpu->ecx + 0x1B0u) = x87_v0; 
    *(uint32_t*)(cpu->ecx + 0x98u) = cpu->edx;
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B7F90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::ImageCtrl*>(cpu->esi));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x1A0u) == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (sub_pred[0]) goto label_000B7FF9;
    cpu->edx = 0x5Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ImageCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7FDFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B7FDFu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1A0u);
    if (cpu->edi == 0u) goto label_000B7FF9;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7FF0u)); sfera_sub_004CF160(cpu, LIFT_CODE_TOKEN_VA(0x4B7FF0u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B7FF6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B7FF6u));
    cpu->esp += 4u;
    label_000B7FF9:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8008u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4B8008u));
    if (((*(uint8_t*)(cpu->esp + 0x20u)) & (1u)) == 0u) goto label_000B8018;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8015u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B8015u));
    cpu->esp += 4u;
    label_000B8018:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8030(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B803Eu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4B803Eu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x19Cu));
    *(uint8_t*)(cpu->esi + 0x19Cu) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1A0u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1A4u));
    *(uint8_t*)(cpu->esi + 0x1A4u) = cpu->eax & 0xFFu;
    *(float*)(cpu->esi + 0x1A8u) = (double)*(float*)(cpu->edi + 0x1A8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1ACu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->edi + 0x1B0u);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi + 0x1B0u) = x87_v0; 
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B80A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0xB5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ImageCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B80D4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B80D4u));
    lift_push32(cpu, 0x1B8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B80DEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B80DEu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000B80FC;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B80F8u)); sfera_sub_004B77A0(cpu, LIFT_CODE_TOKEN_VA(0x4B80F8u));
    cpu->esi = cpu->eax;
    goto label_000B80FE;
    label_000B80FC:
    cpu->esi = 0u;
    label_000B80FE:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B810Eu)); sfera_sub_004B8030(cpu, LIFT_CODE_TOKEN_VA(0x4B810Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000B8136;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8136u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xB8136u));
    label_000B8136:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8150(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint8_t)(*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_000B8160;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B8160:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2Eu); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4B8165u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebx != 0u) goto label_000B81AC;
    cpu->edx = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax = cpu->edi;
    cpu->edx -= cpu->edi;
    label_000B8180:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B8180;
    cpu->eax = (uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->edx = cpu->eax;
    label_000B8191:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B8191;
    cpu->edi = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_000B81A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000B81A0;
    cpu->esi = cpu->edx;
    goto label_000B8219;
    label_000B81AC:
    cpu->esi = cpu->ebx;
    cpu->esi -= cpu->edi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4B81B7u));
    cpu->eax = (uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + ((uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0])) = 0u;
    cpu->ecx = cpu->eax;
    label_000B81D0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B81D0;
    cpu->edi = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000B81E1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000B81E1;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->ebx;
    cpu->ecx = cpu->eax;
    label_000B8200:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B8200;
    cpu->edi = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000B8211:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000B8211;
    label_000B8219:
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8230(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_client_process_runtime.ui_bridge = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_07) = cpu->edx;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8250(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = cpu->ecx;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08 == 0u) goto label_000B82B4;
    cpu->esi = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09 <= cpu->esi) goto label_000B82B4;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->edi = 0u;
    label_000B8292:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->eax);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->ebx);

    if (cpu->eax == 0u) goto label_000B831D;
    ++cpu->esi;
    cpu->edi += 0x98u;
    if (cpu->esi < *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) goto label_000B8292;
    label_000B82B4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82BBu)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4B82BBu));
    if (cpu->eax == 0xFFFFFFFFu) goto label_000B8347;
    cpu->edx = 0x2E9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82D3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B82D3u));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82DDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B82DDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_000B82F7;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82F5u)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4B82F5u));
    cpu->esi = cpu->eax;
    label_000B82F7:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8307u)); sfera_sub_004CF1A0(cpu, LIFT_CODE_TOKEN_VA(0x4B8307u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B831D:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x98u);
    ++*(uint32_t*)(cpu->esi + cpu->ecx + 0x8Cu);
    cpu->eax = cpu->esi + cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B8347:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8360(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    if (sub_pred[0]) goto label_000B83A3;
    cpu->edi = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09 <= cpu->edi) goto label_000B83A3;
    cpu->ebx = native_function_address32(&::_stricmp);
    cpu->esi = 0u;
    label_000B8381:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = *(uint32_t*)(cpu->esi + cpu->eax);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->ebp);

    if (cpu->eax == 0u) goto label_000B83AA;
    ++cpu->edi;
    cpu->esi += 0x98u;
    if (cpu->edi < *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) goto label_000B8381;
    label_000B83A3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B83AA:
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x98u);
    cpu->eax += (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B83C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) != cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B83D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->edx = 0u;
    if (cpu->eax == cpu->edx) goto label_000B8407;
    if (cpu->ecx > 3u) goto label_000B83F9;
    if (cpu->ecx >= 2u) goto label_000B83F1;
    if (cpu->ecx > 1u) goto label_000B8407;
    *(uint8_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 1u) = cpu->edx & 0xFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B83F1:
    *(uint8_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 1u) = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B83F9:
    if (cpu->ecx != 0xFFu) goto label_000B8407;
    *(uint8_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 1u) = cpu->edx & 0xFFu;
    label_000B8407:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    cpu->eax = cpu->ecx;
    if (cpu->eax >= 4u) goto label_000B8450;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if (cpu->ecx != 0u) goto label_000B8463;
    label_000B8450:
    cpu->eax = 0u;
    cpu->edx = 0u;
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B8463:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8468u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4B8468u));
    cpu->edx = cpu->esp;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8472u)); sfera_sub_0044FC60(cpu, LIFT_CODE_TOKEN_VA(0x4B8472u));
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->eax == 0u) goto label_000B849B;
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    label_000B849B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B84B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B8550;
    cpu->eax += 0xFFFFFFC0u;
    if (cpu->eax > 0xBFu) goto label_000B8550;
    switch (cpu->eax) {
        case 0u: case 1u: goto label_000B84F6;
        case 2u: goto label_000B8515;
        case 3u: goto label_000B8534;
        case 191u: goto label_000B84DC;
        default: goto label_000B8550;
    }
label_000B84DC: ;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B84E9u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B84E9u));
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B84F6:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"curseye"); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8508u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8508u));
    g_sfera_interface_runtime.cursor_kind = 0x40u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B8515:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"cursman"); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8527u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8527u));
    g_sfera_interface_runtime.cursor_kind = 0x42u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B8534:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"cursman"); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8546u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8546u));
    g_sfera_interface_runtime.cursor_kind = 0x43u;
    label_000B8550:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8630(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B867A;
    if (cpu->esi != 0u) goto label_000B8656;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B864Bu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B864Bu));
    g_sfera_ui_load_scratch_runtime.cursor_name[0] = (uint8_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B8656:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8664u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8664u));
    cpu->edx = (uintptr_t)g_sfera_ui_load_scratch_runtime.cursor_name;
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_000B8670:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B8670;
    label_000B867A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B869F;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B869Eu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B869Eu));
    cpu->esi = lift_pop32(cpu);
    label_000B869F:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B86B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B86CA;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B86C9u)); sfera_sub_004A1AD0(cpu, LIFT_CODE_TOKEN_VA(0x4B86C9u));
    cpu->esi = lift_pop32(cpu);
    label_000B86CA:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B86D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B86F3;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B86F2u)); sfera_sub_004A1B00(cpu, LIFT_CODE_TOKEN_VA(0x4B86F2u));
    cpu->esi = lift_pop32(cpu);
    label_000B86F3:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->esi == 0u) goto label_000B8737;
    if (*(uint32_t*)(cpu->esi + 0xD8u) == 0u) goto label_000B8727;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B871Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B871Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8724u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8724u));
    cpu->esp += 0xCu;
    label_000B8727:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->edi!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8737u)); sfera_sub_004D1E20(cpu, LIFT_CODE_TOKEN_RVA(0xB8737u));
    label_000B8737:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8740(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx != 0u) goto label_000B8747;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B8747:
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B874Du)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4B874Du));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->esi != 0u) goto label_000B875F;
    label_000B875A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B875F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8764u)); sfera_sub_004D1A00(cpu, LIFT_CODE_TOKEN_VA(0x4B8764u));
    if (cpu->eax != 0xCu) goto label_000B875A;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8771u)); sfera_sub_004BD940(cpu, LIFT_CODE_TOKEN_VA(0x4B8771u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8780(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000B8792;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    label_000B8792:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B87A0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000B87B2;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x30u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    label_000B87B2:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B87C0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_interface_runtime.cross_enabled = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B87D0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_interface_runtime.sounds_enabled = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B87E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_interface_runtime.sounds_enabled;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B87F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (((*(uint8_t*)(cpu->esi + 0x40u)) & (1u)) == 0u) goto label_000B8807;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8804u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B8804u));
    cpu->esp += 4u;
    label_000B8807:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->edx) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    *(uint32_t*)(cpu->ecx) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->edx) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->ecx) = 0u;
    *(uint32_t*)(cpu->esi + 0x40u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x40u)) & (uint64_t)(0xFFFFFFFEu);
    *(uint32_t*)(cpu->esi + 0x3Cu) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8850(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->edi = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08 == cpu->edi) goto label_000B88C4;
    cpu->edx = 0x216u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8895u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8895u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    if (cpu->eax == cpu->edi) goto label_000B88BE;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CF160)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x98u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88B5u)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x4B88B5u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88BBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B88BBu));
    cpu->esp += 4u;
    label_000B88BE:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = cpu->edi;
    label_000B88C4:
    cpu->edx = 0x21Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88D9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B88D9u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88E3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B88E3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_000B88FD;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88F9u)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x4B88F9u));
    cpu->esi = cpu->eax;
    goto label_000B88FF;
    label_000B88FD:
    cpu->esi = 0u;
    label_000B88FF:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8912u)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x4B8912u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B891Fu)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x4B891Fu));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi <= 0) goto label_000B8A07;
    cpu->edx = 0x226u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8938u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8938u));
    cpu->eax = cpu->edi;
    cpu->edx = 0x98u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    cpu->eax = 0u;
    cpu->ecx += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->ecx < 4u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B895Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B895Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    if (cpu->eax == 0u) goto label_000B8991;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CF160)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CDF00)); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax + 4u;
    lift_push32(cpu, 0x98u); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B898Au)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x4B898Au));
    cpu->eax = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    goto label_000B8993;
    label_000B8991:
    cpu->eax = 0u;
    label_000B8993:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B89AFu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4B89AFu));
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B89C0u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4B89C0u));
    if (cpu->eax == 0u) goto label_000B8A00;
    cpu->edi = 0u;
    label_000B89D0:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi + cpu->edx;
    lift_push32(cpu, cpu->ebx);
    cpu->edi += 0x98u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B89EBu)); sfera_sub_004CE8A0(cpu, LIFT_CODE_TOKEN_VA(0x4B89EBu));
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B89FCu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4B89FCu));
    if (cpu->eax != 0u) goto label_000B89D0;
    label_000B8A00:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8A07u)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0xB8A07u));
    label_000B8A07:
    cpu->edx = 0x234u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A16u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8A16u));
    if (cpu->esi == 0u) goto label_000B8A2A;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A21u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4B8A21u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A27u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B8A27u));
    cpu->esp += 4u;
    label_000B8A2A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    if (cpu->ecx != 0u) goto label_000B8A5C;
    if (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready != (cpu->ecx & 0xFFu)) goto label_000B8A93;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    cpu->esp += 8u;
    sfera_sub_004CF750(cpu, stop_address); return;
    label_000B8A5C:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0xBB9u);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A6Eu)); sfera_sub_004D0130(cpu, LIFT_CODE_TOKEN_VA(0x4B8A6Eu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A73u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4B8A73u));
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8A93u)); sfera_sub_004CF770(cpu, LIFT_CODE_TOKEN_RVA(0xB8A93u));
    label_000B8A93:
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000B8AFF;
    if (cpu->ecx > 0x4924924u) goto label_000B8AD1;
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8ACAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B8ACAu));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000B8AFF;
    label_000B8AD1:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8AFFu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xB8AFFu));
    label_000B8AFF:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B90A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->esi = 0u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000B9114;
    cpu->ebx = 0u;
    label_000B90D0:
    cpu->eax = cpu->ebx + cpu->edi;
    if (*(uint32_t*)(cpu->ebx + cpu->edi + 0x14u) < 0x10u) goto label_000B90DC;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B90DC:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4B90DEu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000B911C;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    ++cpu->esi;
    cpu->ecx += cpu->edx;
    cpu->ebx += 0x38u;
    if (cpu->esi < cpu->ecx) goto label_000B90D0;
    label_000B9114:
    cpu->eax = cpu->edi + 0x1Cu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B911C:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->edx = cpu->esi * 8u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx -= cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->eax + (cpu->edx * 8u) + 0x1Cu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9145u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4B9145u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000B914D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B914D:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->ecx == 0u) goto label_000B9185;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax == 0u) goto label_000B9185;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x64u);
    if (cpu->esi <= cpu->eax) goto label_000B9169;
    cpu->esi = cpu->eax;
    label_000B9169:
    cpu->eax = cpu->ecx + 0x54u;
    if (*(uint32_t*)(cpu->ecx + 0x68u) < 0x10u) goto label_000B9174;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9174:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4B9177u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + cpu->edi) = 0u;
    cpu->esi = lift_pop32(cpu);
    label_000B9185:
    cpu->edi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B919Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4B919Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000B91C3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_000B91BD;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000B91BD:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B91C3:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B91F1u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B91F1u));
    lift_trap(cpu, 0x4B91F1u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004B92D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    if (cpu->edi != 0u) goto label_000B92D9;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B92D9:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx);
    if (cpu->esi == cpu->ebx) goto label_000B932E;
    label_000B92E7:
    cpu->eax = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_000B92F2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B92F2:
    cpu->ecx = cpu->edi;
    label_000B92F4:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000B9314;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000B9310;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000B9314;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B92F4;
    label_000B9310:
    cpu->eax = 0u;
    goto label_000B9319;
    label_000B9314:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000B9319:
    if (cpu->eax == 0u) goto label_000B932A;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->ebx) goto label_000B92E7;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B932A:
    if (cpu->esi != cpu->ebx) goto label_000B9335;
    label_000B932E:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B9335:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->eax) goto label_000B9380;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_000B9366:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->edi);

    if (cpu->eax == 0u) goto label_000B9386;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) goto label_000B9366;
    label_000B9380:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9386:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000B93D2;
    lift_push32(cpu, cpu->edi);
    label_000B93A0:
    cpu->edx = 0x1A8u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93AFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B93AFu));
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->edi == 0u) goto label_000B93C6;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93BDu)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4B93BDu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93C3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B93C3u));
    cpu->esp += 4u;
    label_000B93C6:
    cpu->esi = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    if (cpu->esi != cpu->eax) goto label_000B93A0;
    cpu->edi = lift_pop32(cpu);
    label_000B93D2:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor) = 0u;
    if (cpu->ecx == *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) goto label_000B9405;
    label_000B93F0:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B93F8u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) goto label_000B93F0;
    label_000B9405:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9410(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor <= 0u) goto label_000B9496;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->ecx) goto label_000B945B;
    label_000B9430:
    cpu->edx = 0x273u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B943Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B943Fu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->ecx == 0u) goto label_000B944F;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000B944F:
    cpu->esi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    if (cpu->esi != cpu->ecx) goto label_000B9430;
    label_000B945B:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor) = 0u;
    if (cpu->eax == *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) goto label_000B9495;
    label_000B9480:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9488u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9488u));
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) goto label_000B9480;
    label_000B9495:
    cpu->esi = lift_pop32(cpu);
    label_000B9496:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B94A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->eax == cpu->ecx) goto label_000B9534;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000B94B4:
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    if (*(uint32_t*)(cpu->edi + 0xD8u) == 0u) goto label_000B94DC;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(0x%X) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B94CDu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B94CDu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B94D3u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B94D3u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 0xCu;
    label_000B94DC:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->ebp = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_000B950A;
    label_000B94E4:
    if (*(uint32_t*)(cpu->esi + 8u) != cpu->edi) goto label_000B9504;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B94F9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B94F9u));
    cpu->esp += 4u;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    goto label_000B9506;
    label_000B9504:
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000B9506:
    if (cpu->esi != cpu->ebp) goto label_000B94E4;
    label_000B950A:
    cpu->edx = 0x283u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9519u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B9519u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = cpu->ebx;
    if (cpu->ebx != cpu->ecx) goto label_000B94B4;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B9534:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->eax == 0x64u) goto label_000B9614;
    if (cpu->eax == 0x3E9u) goto label_000B95DD;
    if (cpu->eax != 0xA90u) goto label_000B95C1;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B956Bu)); sfera_sub_004AEE90(cpu, LIFT_CODE_TOKEN_VA(0x4B956Bu));
    if (cpu->eax == 0u) goto label_000B959B;
    lift_push32(cpu, (uintptr_t)"Language\\helpindex.hts");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B957Bu)); sfera_sub_004AEE90(cpu, LIFT_CODE_TOKEN_VA(0x4B957Bu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4B957Cu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000B959B;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xA91u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000B959B:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B95A2u)); sfera_sub_004AF340(cpu, LIFT_CODE_TOKEN_VA(0x4B95A2u));
    cpu->esi = lift_pop32(cpu);
    lift_push32(cpu, 0u);
    if ((cpu->eax & 0xFFu) != 0u) goto label_000B95C3;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000B95C1:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B95C3:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B95DD:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if ((--cpu->edx) == 0u) goto label_000B9607;
    if ((--cpu->edx) != 0u) goto label_000B95C1;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xA8Du);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9607:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uintptr_t)"Language\\helpindex.hts";
    cpu->edi = lift_pop32(cpu);
    sfera_sub_004BAD10(cpu, stop_address); return;
    label_000B9614:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    sfera_sub_004BAD10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004B9620(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9650u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4B9650u));
    cpu->eax = g_sfera_screen_clip_runtime.top;
    cpu->ecx = g_sfera_screen_clip_runtime.bottom;
    cpu->edi = g_sfera_screen_clip_runtime.left;
    cpu->ebp = g_sfera_screen_clip_runtime.right;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((uint8_t)(g_sfera_interface_runtime.primary_gate) == 0u) goto label_000B96B2;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000B9698;
    label_000B9683:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->esi = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    if (cpu->esi != cpu->eax) goto label_000B9683;
    label_000B9698:
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000B96B2;
    label_000B96A0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B96A8u)); sfera_sub_004D2810(cpu, LIFT_CODE_TOKEN_VA(0x4B96A8u));
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) goto label_000B96A0;
    label_000B96B2:
    if (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready != 0u) goto label_000B96C5;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB96C5u)); sfera_sub_004CFA00(cpu, LIFT_CODE_TOKEN_RVA(0xB96C5u));
    label_000B96C5:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->eax == 0u) goto label_000B97D8;
    if (*(uint8_t*)(cpu->eax) == 0u) goto label_000B97D8;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->esi |= 0xFFFFFFFFu;
    lift_test[0]=((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)&1u)==0u;
    g_sfera_screen_clip_runtime.left = 0u;
    g_sfera_screen_clip_runtime.top = 0u;
    g_sfera_screen_clip_runtime.bottom = cpu->ecx;
    g_sfera_screen_clip_runtime.right = cpu->edx;
    if (!lift_test[0]) goto label_000B973D;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B972Cu)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x4B972Cu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9736u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4B9736u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    label_000B973D:
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if (cpu->ecx != 0u) goto label_000B9757;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9751u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4B9751u));
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    label_000B9757:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    if ((((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_000B9796;
    cpu->eax = 1u;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9785u)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x4B9785u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B978Fu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4B978Fu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    label_000B9796:
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if (cpu->ecx != 0u) goto label_000B97B0;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B97AAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4B97AAu));
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    label_000B97B0:
    reinterpret_cast<CCursor*>(cpu->ecx)->isInsideViewport(cpu);
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B97D8;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB97D8u)); sfera_sub_004A1B70(cpu, LIFT_CODE_TOKEN_RVA(0xB97D8u));
    label_000B97D8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    g_sfera_screen_clip_runtime.top = cpu->ecx;
    cpu->ecx = 0u;
    g_sfera_screen_clip_runtime.left = cpu->edi;
    g_sfera_screen_clip_runtime.right = cpu->ebp;
    g_sfera_screen_clip_runtime.bottom = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B97FFu)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4B97FFu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9820(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000B9849;
    if (cpu->edx != 0u) goto label_000B982B;
    cpu->eax = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B982B:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx <= 1u) goto label_000B9845;
    cpu->ecx = cpu->edx + 0xFFFFFFFFu;
    label_000B9840:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000B9840;
    label_000B9845:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9849:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->eax) goto label_000B9895;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_000B9870:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000B9880;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9880:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->edi);

    if (cpu->eax == 0u) goto label_000B989B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) goto label_000B9870;
    label_000B9895:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B989B:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B98B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B98BCu)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4B98BCu));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ebp = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->ebp) goto label_000B995B;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_000B98E0:
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000B9941;
    if (*(uint8_t*)(cpu->esi + 0x4Fu) != 0u) goto label_000B9941;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000B9915;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9915u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xB9915u));
    label_000B9915:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->eax > (int32_t)cpu->ebx) goto label_000B9941;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_000B9941;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ecx > (int32_t)cpu->eax) goto label_000B9941;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000B9951;
    label_000B9941:
    cpu->eax = cpu->edi;
    if (cpu->eax != cpu->ebp) goto label_000B98E0;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9951:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B995B:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9970(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->ecx != 0u) goto label_000B99B8;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000B99B3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000B9990:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) goto label_000B9990;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B99B3:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000B99B8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B99E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->eax = 0u;
    if (cpu->ecx == cpu->edx) goto label_000B9A05;
    lift_push32(cpu, cpu->esi);
    (void)cpu;
    label_000B99F0:
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->eax + cpu->esi + 9u;
    if (cpu->ecx != cpu->edx) goto label_000B99F0;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000B9A05;
    cpu->eax += 4u;
    label_000B9A05:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
